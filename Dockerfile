# SPDX-FileCopyrightText: 2026 Ishaan Sharma
#
# SPDX-License-Identifier: MIT

# Reproducible build environment. Build:  docker build -t fdyn-dev .
# Run:  docker run --rm -it -v "$PWD":/workspace fdyn-dev
FROM ubuntu:22.04
ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential cmake ninja-build git ca-certificates clang clang-format clang-tidy \
    && rm -rf /var/lib/apt/lists/*
WORKDIR /workspace
CMD ["bash"]
