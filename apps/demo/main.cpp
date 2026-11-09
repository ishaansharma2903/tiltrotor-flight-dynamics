// SPDX-FileCopyrightText: 2026 Ishaan Sharma
//
// SPDX-License-Identifier: MIT

#include <iostream>

#include "fdyn/vec3.hpp"

int main() {
  const fdyn::Vec3 v = fdyn::normalized({3.0, 4.0, 0.0});
  std::cout << v.x << " " << v.y << " " << v.z << "\n";
  return 0;
}
