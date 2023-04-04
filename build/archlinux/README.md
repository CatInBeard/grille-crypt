# Build for archlinux

[![archlinux package builder](https://github.com/CatInBeard/grille-crypt/actions/workflows/arch_build.yaml/badge.svg)](https://github.com/CatInBeard/grille-crypt/actions/workflows/arch_build.yaml)

## Manual build
You need to install make,cmake, gcc,git, basedevel. To install:

```
sudo pacman -Syu make cmake gcc git base-devel
```  
To make arch package:  

```
git clone https://github.com/CatInBeard/grille-crypt.git
cd grille-crypt/build/archlinux
./build.sh
```

To install package:  
```
sudo pacman -U grille-crypt-0.1.0-1-x86_64.pkg.tar.zst
```
## Build with docker:
```
git clone https://github.com/CatInBeard/grille-crypt.git  
cd grille-crypt/build/archlinux/CI
./ci_build.sh  
```