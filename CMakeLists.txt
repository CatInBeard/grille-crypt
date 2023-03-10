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

if(UNIX)
	set(SystemDepended src/LinuxRandomStream.cpp src/LinuxFactory.h src/LinuxFactory.cpp src/LinuxFactoryBuilder.cpp)
	message(STATUS "build for unix")
else()
         message(STATUS "build not for unix")                                      
endif()

add_executable(${PROJECT_NAME} src/main.cpp src/GrilleKey.h src/GrilleKey.cpp src/AbstractCryptStream.h src/AbstractCryptStream.cpp src/EncryptStream.h src/EncryptStream.cpp src/AbstractRandomStream.h src/LinuxRandomStream.h src/AbstractSystemDependedFactory.h src/AbstractSystemDependedFactory.cpp ${SystemDepended})
	
target_link_libraries(${PROJECT_NAME})
