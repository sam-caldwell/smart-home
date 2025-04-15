#!/bin/sh

cmake -S . -B build && \
cmake --build build --target build_and_test
