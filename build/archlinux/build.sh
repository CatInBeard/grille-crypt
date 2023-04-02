#!/bin/bash

cmake  ../../CMakeLists.txt
cmake --build .
rm CMa* -r
rm cmake_install.cmake

makepkg

rm grille-crypt
rm pkg -r
rm src -r
rm Makefile
