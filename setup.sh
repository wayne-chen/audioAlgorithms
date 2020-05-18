#!/usr/bin/sh

cd FRUT
mkdir build && cd build/
cmake .. -DCMAKE_INSTALL_PREFIX=../prefix -DJUCE_ROOT=../../JUCE
cmake --build . --target install

# build project
cd ../../audioAlgorithms
../FRUT/prefix/FRUT/bin/Jucer2Reprojucer audioAlgorithms.jucer ../FRUT/prefix/FRUT/cmake/Reprojucer.cmake
mkdir build && cd build/
cmake .. -GXcode
cmake --build .
