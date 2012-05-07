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

Point3D
Sphere::getCenter() {
	return _center;
}

float
Sphere::getRadius() {
	return _radius;
}

bool
Sphere::hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const {
	Vector3D temp = ray.origin - _center;
	float a = dot(ray.direction, ray.direction);
	float b = 2.0 * dot(temp, ray.direction);
	float c = dot(temp, temp) - (_radius * _radius);
	float disc = (b * b) - (4.0 * a * c);
	
	if (disc < 0)
		return false;
	
	double e = sqrt(disc);
	double denom = 2.0 * a;
	double t = (-b - e) / denom; // smaller root
	
	if (t > kEpsilon) {
		tmin = t;
		sr.normal = (temp + t * ray.direction) / _radius;
		sr.localHitPoint = ray.origin + t * ray.direction;
		return true;
	} 
	
	t = (-b + e) / denom; // larger root
	
	if (t > kEpsilon) {
		tmin = t;
		sr.normal = (temp + t * ray.direction) / _radius;
		sr.localHitPoint = ray.origin + t * ray.direction;
		return true;
	} 
	
	return false;
}