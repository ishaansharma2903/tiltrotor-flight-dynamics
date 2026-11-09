# SPDX-FileCopyrightText: 2026 Ishaan Sharma
#
# SPDX-License-Identifier: MIT

cmake_minimum_required(VERSION 3.21)
project(fdyn VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(FDYN_BUILD_TESTS "Build unit tests" ON)
option(FDYN_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)
option(FDYN_SANITIZE "Enable AddressSanitizer and UndefinedBehaviorSanitizer" OFF)

# One place that applies the project's compiler settings to a target.
function(fdyn_configure_target target)
  target_compile_options(${target} PRIVATE -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
  if(FDYN_WARNINGS_AS_ERRORS)
    target_compile_options(${target} PRIVATE -Werror)
  endif()
  if(FDYN_SANITIZE)
    target_compile_options(${target} PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer)
    target_link_options(${target} PRIVATE -fsanitize=address,undefined)
  endif()
endfunction()

# The library: everything reusable lives here.
add_library(fdyn src/vec3.cpp)
add_library(fdyn::fdyn ALIAS fdyn)
target_include_directories(fdyn PUBLIC include)
fdyn_configure_target(fdyn)

# Executables are thin; they only call the library.
add_subdirectory(apps/demo)

if(FDYN_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()
