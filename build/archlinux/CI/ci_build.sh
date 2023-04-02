#!/bin/bash

docker build -t build .
chmod 777 ../
docker run -v "$PWD/../../../:/grille-crypt" --user build -w "/grille-crypt/build/archlinux/" build ./build.sh

