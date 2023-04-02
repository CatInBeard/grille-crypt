#!/bin/bash

docker build -t build .
docker run -v "$PWD/../../../:/grille-crypt" --user build -w "/grille-crypt/build/archlinux/" build ./build.sh

