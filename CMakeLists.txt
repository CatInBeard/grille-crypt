cmake_minimum_required(VERSION 3.1)

project(grille-crypt VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED on)

if(ALL_ERRORS)
	message(STATUS "Add error flags")
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

endif()

if(UNIX)
	set(SystemDepended src/LinuxRandomStream.cpp src/LinuxFactory.h src/LinuxFactory.cpp src/LinuxFactoryBuilder.cpp)
	message(STATUS "Build for unix")
else()
         message(STATUS "Build not for unix")                                      
endif()

add_executable(${PROJECT_NAME} src/main.cpp src/GrilleKey.h src/GrilleKey.cpp src/AbstractCryptStream.h src/AbstractCryptStream.cpp src/EncryptStream.h src/EncryptStream.cpp src/AbstractRandomStream.h src/LinuxRandomStream.h src/AbstractSystemDependedFactory.h src/AbstractSystemDependedFactory.cpp src/DecryptStream.h src/DecryptStream.cpp src/KeyGenerator.h src/KeyGenerator.cpp src/XorCrypt.h src/XorCrypt.cpp src/converter.h src/converter.cpp src/FileFormatter.h src/FileFormatter.cpp ${SystemDepended})
	
target_link_libraries(${PROJECT_NAME})
