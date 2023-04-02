#!/bin/bash

cmake  ../../CMakeLists.txt
cmake --build .
makepkg

rm grille-crypt
rm pkg -r
rm src -r
rm Makefile
rm CMa* -r
rm cmake_install.cmake