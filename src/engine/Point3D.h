#ifndef aether_point3d_h
#define aether_point3d_h

#include "vector3d.h"

class Point3D {
public :	
	// Constructors
	Point3D(float x, float y, float z) : x(x), y(y), z(z) { }
	Point3D() : x(0), y(0), z(0) { }
	
	// Operators
	Vector3D operator-(const Point3D& p) const;
	Point3D operator+(const Vector3D& v) const;
	Point3D operator*(const double a) const;
	
	// Public data
	float x, y, z;
};


#endif
