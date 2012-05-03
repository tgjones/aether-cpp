#ifndef aether_vector3d_h
#define aether_vector3d_h

#define UP_X (0.0f)
#define UP_Y (1.0f)
#define UP_Z (0.0f)

#define DOWN_X (-UP_X)
#define DOWN_Y (-UP_Y)
#define DOWN_Z (-UP_Z)

#define FORWARD_X (0.0f)
#define FORWARD_Y (0.0f)
#define FORWARD_Z (-1.0f)

#define BACKWARD_X (-FORWARD_X)
#define BACKWARD_Y (-FORWARD_Y)
#define BACKWARD_Z (-FORWARD_Z)

class Vector3D {
	public :
	// Statics
	static const Vector3D Forward;
	static const Vector3D Backward;
	static const Vector3D Up;
	static const Vector3D Down;
	
	// Constructors
	Vector3D(float x, float y, float z) : x(x), y(y), z(z) { }
	Vector3D() : x(0), y(0), z(0) { }
	
	// Operators
	Vector3D operator+(const Vector3D& v) const;
	Vector3D operator*(const double a) const;
	Vector3D operator/(const double a) const;
	
	// Public data
	float x, y, z;
};

float dot(const Vector3D &v1, const Vector3D &v2);
Vector3D operator*(float f, const Vector3D &v);

#endif
