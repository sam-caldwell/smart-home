#!/bin/bash

set -e  # Exit on any error

# Configure CMake project
cmake -S . -B build

# Build and run the custom build_and_test target
cmake --build build --target build_and_test
