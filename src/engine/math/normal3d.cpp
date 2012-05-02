#include "normal3d.h"

Normal3D&
Normal3D::operator=(const Vector3D& rhs) {
	x = rhs.x; y = rhs.y; z = rhs.z;
	return *this;
}

float dot(const Normal3D &n1, const Vector3D &v2) {
	return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
}

float dot(const Vector3D &v1, const Normal3D &n2) {
	return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}