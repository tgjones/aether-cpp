#include "Vector3d.h"
#include <cmath>
#include "Point3D.h"

const Vector3D
Vector3D::Forward(FORWARD_X, FORWARD_Y, FORWARD_Z);

const Vector3D
Vector3D::Backward(BACKWARD_X, BACKWARD_Y, BACKWARD_Z);

const Vector3D
Vector3D::Up(UP_X, UP_Y, UP_Z);

const Vector3D
Vector3D::Down(DOWN_X, DOWN_Y, DOWN_Z);

Vector3D
Vector3D::normalize(const Vector3D& v) {
	return v / v.length();
}

Vector3D
Vector3D::cross(const Vector3D& v1, const Vector3D& v2) {
	return Vector3D((v1.y * v2.z) - (v1.z * v2.y),
					(v1.z * v2.x) - (v1.x * v2.z),
					(v1.x * v2.y) - (v1.y * v2.x));
}

Vector3D::Vector3D(const Point3D& p) : x(p.x), y(p.y), z(p.z) { }

float
Vector3D::lengthSquared() const {
	return (x * x) + (y * y) + (z * z);
}

float
Vector3D::length() const {
	return sqrtf(lengthSquared());
}

void
Vector3D::normalize() {
	float length = this->length();
	x /= length;
	y /= length;
	z /= length;
}

Vector3D
Vector3D::operator-() const {
	return Vector3D(-x, -y, -z);
}

Vector3D
Vector3D::operator+(const Vector3D& v) const {
	return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D
Vector3D::operator*(const float a) const {
	return Vector3D(x * a, y * a, z * a);
}

Vector3D
Vector3D::operator/(const float a) const {
	return Vector3D(x / a, y / a, z / a);
}

Vector3D operator*(float f, const Vector3D &v) {
	return Vector3D(f * v.x, f * v.y, f * v.z);
}

float dot(const Vector3D &v1, const Vector3D &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}