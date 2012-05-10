#ifndef Aether_Matrix3D_h
#define Aether_Matrix3D_h

#include "Matrix.h"
#include "Point3D.h"
#include "Point4D.h"
#include "Vector3D.h"

// Specialize Matrix<4> template to provide useful 3D methods
template<>
class Matrix<4> : public MatrixBase<Matrix<4>, 4>
{
public:
  // Static methods
	static Matrix<4> createLookAt(
	  const Point3D& cameraPosition,
		const Vector3D& lookDirection,
	  const Vector3D& cameraUpVector);
	  
	static Matrix<4> createOrthographic(
	  float width, float height,
	  float nearZ, float farZ);
	  
	static Matrix<4> createScale(float xScale, float yScale, float zScale);
	static Matrix<4> createTranslation(float xPosition, float yPosition, float zPosition);
};

typedef Matrix<4> Matrix3D;

/*
#include <iostream>

class Matrix3D : public Matrix<Matrix3D, 4>
{
public:
	// Static constants
	static const Matrix3D Identity;
	
	// Static methods
	static Matrix3D createLookAt(
	  const Point3D& cameraPosition,
		const Vector3D& lookDirection,
	  const Vector3D& cameraUpVector);
	  
	static Matrix3D createOrthographic(
	  float width, float height,
	  float nearZ, float farZ);
	  
	static Matrix3D createScale(float xScale, float yScale, float zScale);
	static Matrix3D createTranslation(float xPosition, float yPosition, float zPosition);
	
	// Constructors
	Matrix3D(float m00, float m01, float m02, float m03,
			 float m10, float m11, float m12, float m13,
			 float m20, float m21, float m22, float m23,
       float m30, float m31, float m32, float m33);
	Matrix3D();
	
	// Public methods
	Vector3D transform(const Vector3D& v) const;
	Point3D transform(const Point3D& p) const;
  Point4D transform(const Point4D& p) const;
	
	// Operators
	Matrix3D operator*(const Matrix3D& rhs) const;
  float operator()(const int i, const int j) const;
  
  // Friends
  friend std::ostream& operator<<(std::ostream& stm, const Matrix3D& m);
};
*/
#endif
