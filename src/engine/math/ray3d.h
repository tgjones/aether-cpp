#ifndef aether_ray3d_h
#define aether_ray3d_h

#include "point3d.h"
#include "vector3d.h"

class Ray3D {
public:
	// Constructors
	Ray3D(const Point3D& origin, const Vector3D& direction)
		: origin(origin), direction(direction)
	{ }
	
	// Public data
	Point3D origin;
	Vector3D direction;
};

#endif
