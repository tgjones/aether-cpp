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
      0.0f, 1.0f, 2.0f, 3.0f,
      4.0f, 5.0f, 6.0f, 7.0f,
      8.0f, 9.0f, 10.0f, 11.0f,
      12.0f, 13.0f, 14.0f, 15.0f);
    auto actualMatrix2 = Matrix3D(
      16.0f, 17.0f, 18.0f, 19.0f,
      20.0f, 21.0f, 22.0f, 23.0f,
      24.0f, 25.0f, 26.0f, 27.0f,
      28.0f, 29.0f, 30.0f, 31.0f);
    auto actual = actualMatrix1 * actualMatrix2;
    
    auto expectedMatrix1 = cml::matrix44f_r(
      0.0f, 1.0f, 2.0f, 3.0f,
      4.0f, 5.0f, 6.0f, 7.0f,
      8.0f, 9.0f, 10.0f, 11.0f,
      12.0f, 13.0f, 14.0f, 15.0f);
    auto expectedMatrix2 = cml::matrix44f_r(
      16.0f, 17.0f, 18.0f, 19.0f,
      20.0f, 21.0f, 22.0f, 23.0f,
      24.0f, 25.0f, 26.0f, 27.0f,
      28.0f, 29.0f, 30.0f, 31.0f);
    auto expected = expectedMatrix1 * expectedMatrix2;
    
    Assert::That(actual, Is().Fulfilling(IsCorrectMatrix(expected)));
  }

  It(Can_invert_matrices)
  {
    auto original = Matrix3D(
      3.0f, 0.0f, 2.0f, -1.0f,
      1.0f, 2.0f, 0.0f, -2.0f,
      4.0f, 0.0f, 6.0f, -3.0f,
      5.0f, 0.0f, 2.0f, 0.0f);
    auto actual = Matrix3D::invert(original);
    
    auto expected = inverse(cml::matrix44f_r(
      3.0f, 0.0f, 2.0f, -1.0f,
      1.0f, 2.0f, 0.0f, -2.0f,
      4.0f, 0.0f, 6.0f, -3.0f,
      5.0f, 0.0f, 2.0f, 0.0f));
    
    Assert::That((original * actual).approximatelyEquals(Matrix3D::identity()), Is().True());
    Assert::That(actual, Is().Fulfilling(IsCorrectMatrix(expected)));
  }
};
