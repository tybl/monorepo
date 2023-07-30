#!/bin/sh
rm -rf build
cmake -S . -B build -DCMAKE_CXX_CLANG_TIDY=clang-tidy -DCMAKE_EXPORT_COMPILE_COMMANDS=true
