# Basics start
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set (CMAKE_CXX_EXTENSIONS OFF)

# Set up standard flag warnings if compiler is appropriate
if(CMAKE_CXX_COMPILER_ID MATCHES "GNUClan|AppleClang")
  set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")
endif()

# Declares the main build
add_executable(mpags-cipher mpags-cipher.cpp)

# Defines what compiler features are needed
target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)