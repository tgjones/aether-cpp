//
//  Plane.cpp
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include "Plane.h"

const double Plane::kEpsilon = 0.001;

bool
Plane::hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const {
	double t = dot((_point - ray.origin), _normal) / dot(ray.direction, _normal);

	if (t > kEpsilon) {
		tmin = t;
		sr.normal = _normal;
		sr.localHitPoint = ray.origin + (t * ray.direction);
		return true;
	}
	return false;
}