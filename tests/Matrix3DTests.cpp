#include <igloo/igloo_alt.h>
using namespace igloo;

#include "TestHelper.h"
#include "Math/Matrix3D.h"

Describe(Matrix3DClass)
{
  It(Can_be_constructed_with_all_values_specified)
  {

  }

  It(Can_create_an_orthographic_projection_matrix)
  {
    const float width = 600, height = 400;
    const float nearZ = 10, farZ = 1000;
    auto matrix = Matrix3D::createOrthographic(
      width, height, nearZ, farZ);
	
	  cml::matrix44f_r expected;
	  matrix_orthographic_RH(expected,
      width, height, nearZ, farZ,
		  cml::z_clip_zero);

    Assert::That(matrix, Is().Fulfilling(IsCorrectMatrix(expected)));
  }
  
  It(Can_multiply_matrices)
  {
    auto actualMatrix1 = Matrix3D(
      0, 1, 2, 3,
      4, 5, 6, 7,
      8, 9, 10, 11,
      12, 13, 14, 15);
    auto actualMatrix2 = Matrix3D(
      16, 17, 18, 19,
      20, 21, 22, 23,
      24, 25, 26, 27,
      28, 29, 30, 31);
    auto actual = actualMatrix1 * actualMatrix2;
    
    auto expectedMatrix1 = cml::matrix44f_r(
      0, 1, 2, 3,
      4, 5, 6, 7,
      8, 9, 10, 11,
      12, 13, 14, 15);
    auto expectedMatrix2 = cml::matrix44f_r(
      16, 17, 18, 19,
      20, 21, 22, 23,
      24, 25, 26, 27,
      28, 29, 30, 31);
    auto expected = expectedMatrix1 * expectedMatrix2;
    
    Assert::That(actual, Is().Fulfilling(IsCorrectMatrix(expected)));
  }
};
