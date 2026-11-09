// SPDX-FileCopyrightText: 2026 Ishaan Sharma
//
// SPDX-License-Identifier: MIT

#include "fdyn/vec3.hpp"

#include <gtest/gtest.h>

#include <stdexcept>

using fdyn::Vec3;

// Known-answer test: a 3-4-5 triangle has an exactly known length.
TEST(Vec3Norm, KnownValue) { EXPECT_DOUBLE_EQ(fdyn::norm({3.0, 4.0, 0.0}), 5.0); }

// Property test: the result always has unit length, whatever the input scale.
TEST(Vec3Normalized, ReturnsUnitLength) {
  for (const Vec3 v : {Vec3{1.0, 2.0, 3.0}, Vec3{-1e6, 2e6, 0.5}, Vec3{1e-6, 0.0, 0.0}}) {
    EXPECT_NEAR(fdyn::norm(fdyn::normalized(v)), 1.0, 1e-14);
  }
}

// Property test: direction is preserved, so the components keep their ratios.
TEST(Vec3Normalized, PreservesDirection) {
  const Vec3 u = fdyn::normalized({2.0, 0.0, 0.0});
  EXPECT_DOUBLE_EQ(u.x, 1.0);
  EXPECT_DOUBLE_EQ(u.y, 0.0);
  EXPECT_DOUBLE_EQ(u.z, 0.0);
}

// Error handling: the zero vector has no direction.
TEST(Vec3Normalized, ThrowsOnZeroVector) {
  EXPECT_THROW(fdyn::normalized({0.0, 0.0, 0.0}), std::invalid_argument);
}
