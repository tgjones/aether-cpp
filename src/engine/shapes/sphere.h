//
//  Sphere.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Sphere_h
#define Aether_Sphere_h

#include "Shape.h"
#include "Geometry.h"

class Sphere : Shape {
public:
	// Constructor
	Sphere(const Point3D center, const float radius);
	
	// Methods
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const;
	
private:
	// Private data
	Point3D center;
	float radius;
	static const double kEpsilon; // for shadows and secondary rays
};


#endif
