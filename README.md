# grille-crypt

[![cppcheck static analysis](https://github.com/CatInBeard/grille-crypt/actions/workflows/cppcheck.yaml/badge.svg)](https://github.com/CatInBeard/grille-crypt/actions/workflows/cppcheck.yaml)
[![archlinux package builder](https://github.com/CatInBeard/grille-crypt/actions/workflows/arch_build.yaml/badge.svg)](https://github.com/CatInBeard/grille-crypt/actions/workflows/arch_build.yaml)

## About
Grille-crypt is a free grille algorithm C++ implementation.
For more information about grille: https://en.m.wikipedia.org/wiki/Grille_(cryptography)  
Grille-crypt provides you to encrypt and decrypt files with your key. Its disadvantage is that the encrypted file is much larger than the original one.  But due to the presence of random data in the encrypted file, bruteforce becomes much more complicated.

[![asciicast](https://asciinema.org/a/FnpoCVqyopwB5zg4q6ePMwj6N.svg)](https://asciinema.org/a/FnpoCVqyopwB5zg4q6ePMwj6N)

## Build
To build grille-crypt:  
```
git clone https://github.com/CatInBeard/grille-crypt.git
cd grille-crypt  
cmake CMakeLists.txt
cmake --build .
```

### Arch
You can build package for archlinux, [read this](build/archlinux/README.md)

## License
This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.  

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.  

You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
