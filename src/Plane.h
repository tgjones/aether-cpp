//
//  Plane.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Plane_h
#define Aether_Plane_h

#include "Shape.h"
#include "Geometry.h"

class Plane : Shape {
public:
	// Constructor
	Plane(const Point3D p, const Normal3D& n);
	
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const;
	
private:
	// Private data
	Point3D point;
	Normal3D normal;
	static const double kEpsilon;
};

#endif
