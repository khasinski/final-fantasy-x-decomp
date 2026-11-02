# Host-side helpers. The period compilers are 32-bit x86 Linux binaries, so
# anything that compiles runs inside the ffx-decomp Docker image.
DOCKER = docker run --rm -it -v "$(CURDIR)":/work ffx-decomp

.PHONY: image split shell
image:
	docker build -t ffx-decomp .
split:
	.venv/bin/python -m splat split config/SCES_504.90.yaml
	python3 -P tools/split_rodata.py
	python3 -P tools/eeasm.py asm/nonmatchings build/ee_asm
shell:
	$(DOCKER) bash

# Full pipeline in the container: split -> ninja -> compare with the original.
.PHONY: build
build: split
	docker run --rm -v "$(CURDIR)":/work ffx-decomp sh -c "python3 configure.py && ninja"
