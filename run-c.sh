#!/bin/sh

set -eu

if [ "$#" -ne 1 ]; then
  printf 'Usage: %s path/to/file.c\n' "$0" >&2
  exit 1
fi

script_dir=$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)
source_file=$1

if [ ! -f "$source_file" ]; then
  printf 'Error: file not found: %s\n' "$source_file" >&2
  exit 1
fi

build_dir=$(mktemp -d)
trap 'rm -rf "$build_dir"' EXIT INT TERM HUP

output_file="$build_dir/program"
source_dir=$(dirname -- "$source_file")

cc -Wall -Wextra -Wpedantic \
  -I"$script_dir/include" \
  -I"$source_dir" \
  "$source_file" \
  -lm \
  -o "$output_file"

"$output_file"
