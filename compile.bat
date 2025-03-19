@echo off
cmake -B build %* && cd build && cmake --build . --config Release --parallel 4
cd ..
