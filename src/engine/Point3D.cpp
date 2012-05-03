#include "Math.h"

Vector3D
Point3D::operator-(const Point3D& p) const {
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D
Point3D::operator+(const Vector3D& v) const {
	return Point3D(x + v.x, y + v.y, z + v.z);
}

bool
Point3D::operator==(const Point3D& p) const {
	return x == p.x && y == p.y && z == p.z;
}

bool
Point3D::operator!=(const Point3D& p) const {
	return x != p.x || y != p.y || z != p.z;
}

std::ostream& operator<<(std::ostream& stream, const Point3D& p) {
	stream << p.x << p.y << p.z;
	return stream;
}