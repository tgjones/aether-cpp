#ifndef Aether_Sphere_h
#define Aether_Sphere_h

#include "Shape.h"
#include "../Math/Math.h"

class Sphere : public Shape {
public:
	// Constructor
	Sphere(const Point3D center, const float radius)
		: _center(center), _radius(radius)
	{ }
	
	// Accessors
	Point3D getCenter();
	float getRadius();
	
	// Methods
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const override;
	
private:
	// Private data
	Point3D _center;
	float _radius;
	static const double kEpsilon; // for shadows and secondary rays
};


#endif
