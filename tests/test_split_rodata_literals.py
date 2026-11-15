"""Literal ownership survives regeneration of the assembly data pieces."""
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest

ROOT = Path(__file__).resolve().parents[1]

class LiteralSplitTest(unittest.TestCase):
    def test_literal_is_separate_from_neighboring_data(self):
        with tempfile.TemporaryDirectory() as tmp:
            root = Path(tmp)
            (root / "config").mkdir()
            (root / "asm/data").mkdir(parents=True)
            (root / "config/funcs.txt").write_text("")
            (root / "config/c_rodata.json").write_text(json.dumps({
                "unit": {"address": 0x1008, "size": 8}
            }))
            blob = '.section .rodata, "a"\n'
            for address in (0x1000, 0x1008, 0x1010):
                name = f"D_{address:08X}"
                blob += f"nonmatching {name}\ndlabel {name}\n.word 1, 2\nenddlabel {name}\n"
            (root / "asm/data/rodata.rodata.s").write_text(blob)
            subprocess.run([sys.executable, str(ROOT / "tools/split_rodata.py")], cwd=root, check=True, capture_output=True)
            self.assertEqual((root / "config/rodata_layout.txt").read_text().splitlines(), [
                "piece piece_00001000 0x1000", "piece piece_00001008 0x1008", "piece piece_00001010 0x1010"
            ])
            literal = (root / "asm/data/rodata/piece_00001008.s").read_text()
            self.assertIn("dlabel D_00001008", literal)
            self.assertNotIn("D_00001000", literal)
            self.assertNotIn("D_00001010", literal)

if __name__ == "__main__":
    unittest.main()
