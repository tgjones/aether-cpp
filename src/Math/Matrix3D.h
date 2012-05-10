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
	
	// Constructors
	template<class ...T>
	Matrix<4>(float first, T... next)
		: MatrixBase<Matrix, 4>(first, next...)
	{ }
	
	Matrix<4>() : MatrixBase<Matrix, 4>() {}
	
	// Public methods
	Vector3D transform(const Vector3D& v) const;
	Point3D transform(const Point3D& p) const;
  Point4D transform(const Point4D& p) const;

	// Friends
	friend std::ostream& operator<<(std::ostream& stm, const Matrix<4>& m);
};

typedef Matrix<4> Matrix3D;

#endif
