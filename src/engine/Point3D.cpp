#include "point3d.h"

Vector3D
Point3D::operator-(const Point3D& p) const {
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D
Point3D::operator+(const Vector3D& v) const {
	return Point3D(x + v.x, y + v.y, z + v.z);
}