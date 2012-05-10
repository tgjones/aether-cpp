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
	
	return Matrix3D(right.x, newUp.x, dir.x, 0.0f,
					right.y, newUp.y, dir.y, 0.0f,
					right.z, newUp.z, dir.z, 0.0f,
					-dot(right, position),
					-dot(newUp, position),
					-dot(dir, position),
					1.0f);
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
	  xScale, 0.0f, 0.0f, 0.0f,
		0.0f, yScale, 0.0f, 0.0f,
		0.0f, 0.0f, zScale, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
}

Matrix3D
Matrix3D::createTranslation(float xPosition, float yPosition, float zPosition)
{
	return Matrix3D(
	  1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
  	0.0f, 0.0f, 1.0f, 0.0f,
  	xPosition, yPosition, zPosition, 1.0f);
}

Vector3D
Matrix3D::transform(const Vector3D &v) const
{
	float x = v.x;
	float y = v.y;
	float z = v.z;
	Vector3D result;
	result.x = ((x * at(0, 0)) + (y * at(1, 0))) + (z * at(2, 0));
	result.y = ((x * at(0, 1)) + (y * at(1, 1))) + (z * at(2, 1));
	result.z = ((x * at(0, 2)) + (y * at(1, 2))) + (z * at(2, 2));
	return result;
}

Point3D
Matrix3D::transform(const Point3D& p) const
{
	float x = p.x;
	float y = p.y;
	float z = p.z;
	Point3D result;
	result.x = ((x * at(0, 0)) + (y * at(1, 0))) + (z * at(2, 0)) + at(3, 0);
	result.y = ((x * at(0, 1)) + (y * at(1, 1))) + (z * at(2, 1)) + at(3, 1);
	result.z = ((x * at(0, 2)) + (y * at(1, 2))) + (z * at(2, 2)) + at(3, 2);
	
	float w = (((x * at(0, 3)) + (y * at(1, 3))) + (z * at(2, 3))) + at(3, 3);
	result.x /= w;
	result.y /= w;
	result.z /= w;
	
	return result;
}

Point4D
Matrix3D::transform(const Point4D& p) const
{
  float x = p.x;
  float y = p.y;
  float z = p.z;
  float w = p.w;
	
  Point4D result;
	result.x = ((x * at(0, 0)) + (y * at(1, 0))) + (z * at(2, 0)) + (w * at(3, 0));
	result.y = ((x * at(0, 1)) + (y * at(1, 1))) + (z * at(2, 1)) + (w * at(3, 1));
	result.z = ((x * at(0, 2)) + (y * at(1, 2))) + (z * at(2, 2)) + (w * at(3, 2));
	result.w = ((x * at(0, 3)) + (y * at(1, 3))) + (z * at(2, 3)) + (w * at(3, 3));
  return result;
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
      stm << m.at(i, j);
    }
    stm << std::endl;
  }
  return stm;
}
