#!/bin/sh

set -eu

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
cd "$script_dir"

if ! command -v clang-format >/dev/null 2>&1; then
  printf 'Error: clang-format not found in PATH\n' >&2
  exit 1
fi

find . \
  -path './build' -prune -o \
  -path './.git' -prune -o \
  -type f \( -name '*.c' -o -name '*.h' \) -exec clang-format -i {} +
