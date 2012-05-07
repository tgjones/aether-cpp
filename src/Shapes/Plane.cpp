#include "Plane.h"

const double Plane::kEpsilon = 0.001;

Point3D
Plane::getPoint() {
	return _point;
}

Normal3D
Plane::getNormal() {
	return _normal;
}

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