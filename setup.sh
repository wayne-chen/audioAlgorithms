#!/usr/bin/sh

cd FRUT
if [ ! -d "build" ]; then
    mkdir build
fi
cd build/
cmake .. -DCMAKE_INSTALL_PREFIX=../prefix -DJUCE_ROOT=../../JUCE
cmake --build . --target install

# build project
cd ../../audioAlgorithms
../FRUT/prefix/FRUT/bin/Jucer2Reprojucer audioAlgorithms.jucer ../FRUT/prefix/FRUT/cmake/Reprojucer.cmake
if [ ! -d "build" ]; then
    mkdir build
fi
cd build/
cmake .. -GXcode
cmake --build .
