// SPDX-FileCopyrightText: 2026 Ishaan Sharma
//
// SPDX-License-Identifier: MIT

#include "fdyn/vec3.hpp"

#include <cmath>
#include <stdexcept>

namespace fdyn {

double norm(const Vec3& v) { return std::hypot(v.x, v.y, v.z); }

Vec3 normalized(const Vec3& v, double min_norm) {
  const double n = norm(v);
  if (n < min_norm) {
    throw std::invalid_argument("normalized: vector length is below the minimum");
  }
  return Vec3{v.x / n, v.y / n, v.z / n};
}

}  // namespace fdyn
