//
//  Geometry.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Geometry_h
#define Aether_Geometry_h

class Vector3D {
public :
	// Constructors
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) { }
	
	// Operators
	Vector3D operator*(const double a) const;
	
	// Public data
	float x, y, z;
};

float dot(const Vector3D &v1, const Vector3D &v2);
Vector3D operator*(float f, const Vector3D &v);

class Point3D {
public :	
	// Constructors
	Point3D(float x, float y, float z) : x(x), y(y), z(z) { }
	
	// Operators
	Vector3D operator-(const Point3D& p) const;
	Point3D operator+(const Vector3D& v) const;
	Point3D operator*(const double a) const;
	
	// Public data
	float x, y, z;
};

class Normal3D {
	public :	
	// Constructors
	Normal3D(float x, float y, float z) : x(x), y(y), z(z) { }
	
	// Public data
	float x, y, z;
};

float dot(const Normal3D &n1, const Vector3D &v2);
float dot(const Vector3D &v1, const Normal3D &n2);

class Ray3D {
public:
	// Constructors
	Ray3D(const Point3D& origin, const Vector3D& direction);
	
	// Public data
	Point3D origin;
	Vector3D direction;
};

class Color {
public:
	// Constructors
	Color(float r, float g, float b) : r(r), g(g), b(b) { }
	
	// Public data
	float r, g, b;
};

#endif
