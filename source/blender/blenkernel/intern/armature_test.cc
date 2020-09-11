#include "BKE_armature.h"

#include "BLI_math.h"

#include "testing/testing.h"

namespace blender::bke::tests {

static const float FLOAT_EPSILON = 1.2e-7;

TEST(mat3_vec_to_roll, UnitMatrix)
{
  float unit_matrix[3][3];
  float roll;

  unit_m3(unit_matrix);

  // Any vector with a unit matrix should return zero roll.
  mat3_vec_to_roll(unit_matrix, unit_matrix[0], &roll);
  EXPECT_FLOAT_EQ(0.0f, roll);

  mat3_vec_to_roll(unit_matrix, unit_matrix[1], &roll);
  EXPECT_FLOAT_EQ(0.0f, roll);

  mat3_vec_to_roll(unit_matrix, unit_matrix[2], &roll);
  EXPECT_FLOAT_EQ(0.0f, roll);

  {
    // Non-unit vector.
    float vector[3] = {1.0f, 1.0f, 1.0f};
    mat3_vec_to_roll(unit_matrix, vector, &roll);
    EXPECT_NEAR(0.0f, roll, FLOAT_EPSILON);

    // Normalized version of the above vector.
    normalize_v3(vector);
    mat3_vec_to_roll(unit_matrix, vector, &roll);
    EXPECT_NEAR(0.0f, roll, FLOAT_EPSILON);
  }
}

TEST(mat3_vec_to_roll, Rotationmatrix)
{
  float rotation_matrix[3][3];
  float roll;

  const float rot_around_x[3] = {1.234f, 0.0f, 0.0f};
  eul_to_mat3(rotation_matrix, rot_around_x);

  {
    const float unit_axis_x[3] = {1.0f, 0.0f, 0.0f};
    mat3_vec_to_roll(rotation_matrix, unit_axis_x, &roll);
    EXPECT_NEAR(1.234f, roll, FLOAT_EPSILON);
  }

  {
    const float unit_axis_y[3] = {0.0f, 1.0f, 0.0f};
    mat3_vec_to_roll(rotation_matrix, unit_axis_y, &roll);
    EXPECT_NEAR(0, roll, FLOAT_EPSILON);
  }

  {
    const float unit_axis_z[3] = {0.0f, 0.0f, 1.0f};
    mat3_vec_to_roll(rotation_matrix, unit_axis_z, &roll);
    EXPECT_NEAR(0, roll, FLOAT_EPSILON);
  }

  {
    const float between_x_and_y[3] = {1.0f, 1.0f, 0.0f};
    mat3_vec_to_roll(rotation_matrix, between_x_and_y, &roll);
    EXPECT_NEAR(0.57158958f, roll, FLOAT_EPSILON);
  }
}

}  // namespace blender::bke::tests
