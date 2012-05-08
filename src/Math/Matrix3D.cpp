#include "Matrix3D.h"

#include <iomanip>

Matrix3D
Matrix3D::createLookAt(const Point3D& cameraPosition,
					   const Vector3D& lookDirection,
					   const Vector3D& cameraUpVector) {
	Vector3D position = Vector3D(cameraPosition);
	
	Vector3D dir = Vector3D::normalize(-lookDirection);
	Vector3D right = Vector3D::normalize(Vector3D::cross(cameraUpVector, dir));
	Vector3D newUp = Vector3D::cross(dir, right);
	
	return Matrix3D(right.x, newUp.x, dir.x, 0,
					right.y, newUp.y, dir.y, 0,
					right.z, newUp.z, dir.z, 0,
					-dot(right, position),
					-dot(newUp, position),
					-dot(dir, position),
					1);
}

Matrix3D
Matrix3D::createOrthographic(float width, float height, float nearZ, float farZ)
{
	return createScale(2.0f / width, 2.0f / height, 1.0f / (nearZ - farZ))
		* createTranslation(0, 0, nearZ / (nearZ - farZ));
}

Matrix3D
Matrix3D::createScale(float xScale, float yScale, float zScale)
{
	return Matrix3D(
	  xScale, 0, 0, 0,
		0, yScale, 0, 0,
		0, 0, zScale, 0,
		0, 0, 0, 1);
}

Matrix3D
Matrix3D::createTranslation(float xPosition, float yPosition, float zPosition)
{
	return Matrix3D(
	  1, 0, 0, 0,
		0, 1, 0, 0,
  	0, 0, 1, 0,
  	xPosition, yPosition, zPosition, 1);
}

Matrix3D::Matrix3D(float m00, float m01, float m02, float m03,
		 float m10, float m11, float m12, float m13,
		 float m20, float m21, float m22, float m23,
		 float m30, float m31, float m32, float m33) 
{
	m[0][0] = m00; m[0][1] = m01; m[0][2] = m02; m[0][3] = m03;
	m[1][0] = m10; m[1][1] = m11; m[1][2] = m12; m[1][3] = m13;
	m[2][0] = m20; m[2][1] = m21; m[2][2] = m22; m[2][3] = m23;
	m[3][0] = m30; m[3][1] = m31; m[3][2] = m32; m[3][3] = m33;
}

Matrix3D::Matrix3D()
{
	m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
	m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = 0;
	m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = 0;
	m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
}

Vector3D
Matrix3D::transform(const Vector3D &v) const
{
	float x = v.x;
	float y = v.y;
	float z = v.z;
	Vector3D result;
	result.x = ((x * m[0][0]) + (y * m[1][0])) + (z * m[2][0]);
	result.y = ((x * m[0][1]) + (y * m[1][1])) + (z * m[2][1]);
	result.z = ((x * m[0][2]) + (y * m[1][2])) + (z * m[2][2]);
	return result;
}

Point3D
Matrix3D::transform(const Point3D &p) const
{
	float x = p.x;
	float y = p.y;
	float z = p.z;
	Point3D result;
	result.x = ((x * m[0][0]) + (y * m[1][0])) + (z * m[2][0]) + m[3][0];
	result.y = ((x * m[0][1]) + (y * m[1][1])) + (z * m[2][1]) + m[3][1];
	result.z = ((x * m[0][2]) + (y * m[1][2])) + (z * m[2][2]) + m[3][2];
	
	float w = (((x * m[0][3]) + (y * m[1][3])) + (z * m[2][3])) + m[3][3];
	result.x /= w;
	result.y /= w;
	result.z /= w;
	
	return result;
}

Matrix3D
Matrix3D::operator*(const Matrix3D& rhs) const
{
	Matrix3D r;
	for (int i = 0; i < 4; ++i)
		for (int j = 0; j < 4; ++j)
			r.m[i][j] = m[i][0] * rhs.m[0][j] +
				m[i][1] * rhs.m[1][j] +
				m[i][2] * rhs.m[2][j] +
				m[i][3] * rhs.m[3][j];
	return r;
}

float
Matrix3D::operator()(const int i, const int j) const
{
  return m[i][j];
}	

std::ostream&
operator<<(std::ostream& stm, const Matrix3D& m)
{
  stm << std::endl;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 4; j++)
    {
      stm << std::setw(8) << std::setprecision(3);
      stm << m.m[i][j];
    }
    stm << std::endl;
  }
  return stm;
}