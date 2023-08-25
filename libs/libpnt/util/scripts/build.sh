#!/bin/sh
cmake -S util/dependencies -B build_deps
cmake --build build_deps
cmake -B build_libpnt -DCMAKE_PREFIX_PATH=build_deps
cmake --build build_libpnt
ctest --test-dir build_libpnt
