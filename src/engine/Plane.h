//
//  Plane.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Plane_h
#define Aether_Plane_h

#include "shape.h"
#include "math.h"

class Plane : Shape {
public:
	// Constructor
	Plane(const Point3D point, const Normal3D& normal)
		: _point(point), _normal(normal)
	{}
	
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const override;
	
private:
	// Private data
	Point3D _point;
	Normal3D _normal;
	static const double kEpsilon;
};

#endif
