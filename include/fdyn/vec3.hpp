// SPDX-FileCopyrightText: 2026 Ishaan Sharma
//
// SPDX-License-Identifier: MIT

#pragma once

namespace fdyn {

struct Vec3 {
  double x{0.0};
  double y{0.0};
  double z{0.0};
};

// Euclidean length of v.
double norm(const Vec3& v);

// Returns v scaled to unit length.
// Throws std::invalid_argument if the length of v is below min_norm.
Vec3 normalized(const Vec3& v, double min_norm = 1e-12);

}  // namespace fdyn
