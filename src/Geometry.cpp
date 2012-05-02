//
//  Geometry.cpp
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Geometry.h"

float dot(const Vector3D &v1, const Vector3D &v2) {
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

float dot(const Normal3D &n1, const Vector3D &v2) {
	return n1.x * v2.x + n1.y * v2.y + n1.z * v2.z;
}

float dot(const Vector3D &v1, const Normal3D &n2) {
	return v1.x * n2.x + v1.y * n2.y + v1.z * n2.z;
}

Vector3D
Vector3D::operator*(const double a) const {
	return Vector3D(x * a, y * a, z * a);
}

Vector3D operator*(float f, const Vector3D &v) {
	return Vector3D(f * v.x, f * v.y, f * v.z);
}

Vector3D
Point3D::operator-(const Point3D& p) const {
	return Vector3D(x - p.x, y - p.y, z - p.z);
}

Point3D
Point3D::operator+(const Vector3D& v) const {
	return Point3D(x + v.x, y + v.y, z + v.z);
}