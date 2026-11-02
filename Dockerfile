# x86-64 Linux image: the period ee-gcc binaries are 32-bit i386 ELFs,
# so on Apple Silicon this runs under emulation (--platform linux/amd64).
FROM --platform=linux/amd64 ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN dpkg --add-architecture i386 && apt-get update && apt-get install -y --no-install-recommends \
    build-essential gcc-multilib binutils-mipsel-linux-gnu binutils-mips-linux-gnu \
    libc6:i386 libstdc++6:i386 zlib1g:i386 \
    python3 python3-pip python3-venv ninja-build git curl xz-utils ca-certificates \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /work
COPY requirements.txt /tmp/requirements.txt
RUN pip3 install --no-cache-dir -r /tmp/requirements.txt
