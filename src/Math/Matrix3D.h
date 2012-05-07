#ifndef Aether_Matrix3D_h
#define Aether_Matrix3D_h

#include "Point3D.h"
#include "Vector3D.h"

class Matrix3D {
public:
	// Static methods
	static Matrix3D createLookAt(const Point3D& cameraPosition,
								 const Vector3D& lookDirection,
								 const Vector3D& cameraUpVector);
	static Matrix3D createOrthographic(float width, float height,
									   float zNearPlane, float zFarPlane);
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
	
	// Operators
	Matrix3D operator*(const Matrix3D& rhs) const;
	
private:
	// Private data
	float m[4][4];
};

#endif
