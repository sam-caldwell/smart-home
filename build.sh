#!/bin/bash

set -e  # Exit on any error

rm -rf build &>/dev/null || true

# Configure CMake project
cmake -S . -B build

# Build and run the custom build_and_test target
cmake --build build --target build_and_test
)
