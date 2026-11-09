# SPDX-FileCopyrightText: 2026 Ishaan Sharma
#
# SPDX-License-Identifier: MIT

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
  URL_HASH SHA256=1f357c27ca988c3f7c6b4bf68a9395005ac6761f034046e9dde0896e3aba00e4
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(fdyn_tests unit/vec3_test.cpp)
target_link_libraries(fdyn_tests PRIVATE fdyn::fdyn GTest::gtest_main)
fdyn_configure_target(fdyn_tests)
gtest_discover_tests(fdyn_tests)
