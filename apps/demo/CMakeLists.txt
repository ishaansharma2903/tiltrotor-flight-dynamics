# SPDX-FileCopyrightText: 2026 Ishaan Sharma
#
# SPDX-License-Identifier: MIT

add_executable(fdyn_demo main.cpp)
target_link_libraries(fdyn_demo PRIVATE fdyn::fdyn)
fdyn_configure_target(fdyn_demo)
