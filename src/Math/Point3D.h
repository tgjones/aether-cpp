#ifndef aether_point3d_h
#define aether_point3d_h

#include <ostream>
#include "Point4D.h"
#include "Vector3D.h"

class Point3D {
public :	
	// Constructors
	Point3D(float x, float y, float z) : x(x), y(y), z(z) { }
  Point3D(const Point4D& p); 
	Point3D() : x(0), y(0), z(0) { }
	
	// Operators
	Vector3D operator-(const Point3D& p) const;
	Point3D operator+(const Vector3D& v) const;
	Point3D operator*(const double a) const;
	bool operator==(const Point3D& p) const;
	bool operator!=(const Point3D& p) const;
	
	// Public data
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Point3D& p);

#endif
