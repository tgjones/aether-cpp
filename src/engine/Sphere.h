//
//  Sphere.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Sphere_h
#define Aether_Sphere_h

#include "shape.h"
#include "math.h"

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
