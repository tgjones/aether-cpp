#ifndef aether_normal3d_h
#define aether_normal3d_h

#include <ostream>
#include "Vector3D.h"

class Normal3D {
public :	
	// Constructors
	Normal3D(float x, float y, float z) : x(x), y(y), z(z) { }
	Normal3D() : x(0), y(0), z(0) { }
	
	// Operators
	Normal3D& operator=(const Vector3D& rhs);
	bool operator==(const Normal3D& n) const;
	
	// Public data
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Normal3D& p);

float dot(const Normal3D &n1, const Vector3D &v2);
float dot(const Vector3D &v1, const Normal3D &n2);

#endif