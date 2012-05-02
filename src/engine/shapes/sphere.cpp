//
//  Sphere.cpp
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <math.h>
#include "Sphere.h"

const double Sphere::kEpsilon = 0.001;

bool
Sphere::hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const {
	auto temp = ray.origin - center;
	auto a = dot(ray.direction, ray.direction);
	auto b = 2.0 * dot(temp, ray.direction);
	auto c = dot(temp, temp) - (radius * radius);
	auto disc = (b * b) - (4.0 * a * c);
	
	if (disc < 0)
		return false;
	
	double e = sqrt(disc);
	double denom = 2.0 * a;
	double t = (-b - e) / denom; // smaller root
	
	// TODO
	
	return false;
}