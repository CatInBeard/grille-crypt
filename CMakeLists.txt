cmake_minimum_required(VERSION 3.1)

project(grille-crypt VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

add_compile_options(
    -Werror

    -Wall
    -Wextra
    -Wpedantic

    -Wcast-align
    -Wcast-qual
    -Wconversion
    -Wctor-dtor-privacy
    -Wenum-compare
    -Wfloat-equal
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Woverloaded-virtual
    -Wredundant-decls
    -Wsign-conversion
    -Wsign-promo
)

add_executable(grille-crypt src/main.cpp src/GrilleKey.h src/GrilleKey.cpp src/AbstractCryptStream.h src/AbstractCryptStream.cpp)

target_link_libraries(grille-crypt)
