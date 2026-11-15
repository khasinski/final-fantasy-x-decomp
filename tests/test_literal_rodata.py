"""Run inside the ffx-decomp image with the period compiler installed."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]
CC = ROOT / "tools/cc/ee-gcc2.9-991111-01/bin/ee-gcc"


@unittest.skipUnless(sys.platform == "linux" and CC.exists(), "requires the Linux EE compiler")
class LiteralRodataTest(unittest.TestCase):
    def compile_literal(self, mapped=True, altered=False):
        with tempfile.TemporaryDirectory() as directory:
            work = Path(directory)
            (work / "src").mkdir()
            (work / "config").mkdir()
            (work / "baserom").symlink_to(ROOT / "baserom", target_is_directory=True)
            layout = {"probe": {"piece": "piece_00572370", "address": 0x572370, "size": 16}}
            (work / "config/c_rodata.json").write_text(json.dumps(layout if mapped else {}))
            first = "scene5" if altered else "scene4"
            (work / "src/probe.c").write_text(
                'extern void sink(const char *);\n'
                'void probe(void) { sink("' + first + '"); sink("scene17"); }\n')
            result = subprocess.run(
                [sys.executable, str(ROOT / "tools/ccwrap.py"), str(CC),
                 "src/probe.c", "probe.o", "-O2", "-G0", "-g0"],
                cwd=work, capture_output=True, text=True)
            return result, (work / "probe.o").exists()

    def test_original_block_is_accepted(self):
        result, exists = self.compile_literal()
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertTrue(exists)

    def test_changed_literal_is_rejected(self):
        result, exists = self.compile_literal(altered=True)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("literal block differs", result.stderr)
        self.assertFalse(exists)

    def test_unmapped_literal_is_rejected(self):
        result, exists = self.compile_literal(mapped=False)
        self.assertNotEqual(result.returncode, 0)
        self.assertIn("non-jump-table .rodata", result.stderr)
        self.assertFalse(exists)


if __name__ == "__main__":
    unittest.main()
