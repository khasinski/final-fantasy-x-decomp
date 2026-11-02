import importlib.util
import json
from pathlib import Path
import struct
import subprocess
import sys
import tempfile
import unittest

REPO = Path(__file__).resolve().parents[1]


class ProgressScopeTests(unittest.TestCase):
    def fixture(self, root, overlays=True, matched=0):
        for name in ('config', 'src', 'docs'):
            (root/name).mkdir()
        (root/'config/funcs.txt').write_text('func_00101000 0x101000 0x64\nfunc_00102000 0x102000 0x12c\n')
        (root/'src/sample.c').write_text('void func_00101000(void) {}\nINCLUDE_ASM("sample", func_00102000);\n')
        if overlays:
            (root/'docs/ee-overlay-code-size.json').write_text(json.dumps({'measurements': {
                'detected_instruction_bytes': 600, 'code_region_span_bytes': 1000,
                'exact_byte_distinct_inferred_routine_piece_bytes': 1}}))
            (root/'docs/ee-overlay-audit.json').write_text(json.dumps({
                'conclusions': {'battle_containers': 2, 'unique_battle_payload_sha256': 2},
                'build_status': {'matched_code_bytes': matched, 'matched_containers': int(matched>0)}}))

    def run_status(self, root, *extra):
        result = subprocess.run([sys.executable, '-P', str(REPO/'tools/status.py'),
                                 '--root', str(root), '--json', *extra],
                                capture_output=True, text=True, check=True)
        return json.loads(result.stdout)

    def test_weighted_bytes_and_repeated_overlay_bytes(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);self.fixture(root)
            r=self.run_status(root)
            self.assertEqual(r['resident_elf']['coverage_percent'], 25)
            self.assertEqual(r['known_ee_estimate']['coverage_percent'], 10)
            self.assertAlmostEqual(r['known_ee_estimate']['span_scenario_percent'], 100/14)
            self.assertFalse(r['known_ee_estimate']['span_scenario_is_confidence_interval'])
            self.assertIsNone(r['whole_game_coverage_percent'])
            self.assertIsNone(r['other_scopes']['IOP']['coverage_percent'])
            self.assertFalse(r['rom_verified'])

    def test_missing_overlay_inventory_is_unknown(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);self.fixture(root, overlays=False)
            r=self.run_status(root)
            self.assertIsNone(r['known_ee_estimate'])
            self.assertIsNone(r['whole_game_coverage_percent'])

    def test_partial_overlay_progress_and_saved_json(self):
        with tempfile.TemporaryDirectory() as d:
            root=Path(d);self.fixture(root, matched=120)
            destination=root/'report.json'
            r=self.run_status(root, '--debt', '--write-report', str(destination))
            self.assertEqual(r['known_ee_estimate']['coverage_percent'], 22)
            self.assertEqual(json.loads(destination.read_text()), r)


class DecoderTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        spec=importlib.util.spec_from_file_location('overlay_audit', REPO/'tools/audit_overlays.py')
        cls.module=importlib.util.module_from_spec(spec);spec.loader.exec_module(cls.module)

    def test_both_backreference_formats_and_prefix(self):
        for kind, command in [(1, 0x88), (2, 0x90)]:
            packet=bytes([kind])+struct.pack('<I', 7)+b'\x03abc'+bytes([command,2,0])
            self.assertEqual(self.module.decode(packet), b'abcabca')
            self.assertEqual(self.module.decode(packet, 4), b'abca')

    def test_zero_history_and_rle(self):
        for kind in [1, 2]:
            packet=bytes([kind])+struct.pack('<I', 9)+b'\x80\x00\x7e\x00A\x7f\x02\x00B\x00'
            self.assertEqual(self.module.decode(packet), b'\0\0\0AAAABB')


if __name__=='__main__':
    unittest.main()
