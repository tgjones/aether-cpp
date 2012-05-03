#ifndef Aether_Plane_h
#define Aether_Plane_h

#include "Shape.h"
#include "Math.h"

class Plane : public Shape {
public:
	// Constructor
	Plane(const Point3D point, const Normal3D& normal)
		: _point(point), _normal(normal)
	{}
	
	// Public accessors
	Point3D getPoint();
	Normal3D getNormal();
	
	// Public methods
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const override;
	
private:
	// Private data
	Point3D _point;
	Normal3D _normal;
	static const double kEpsilon;
};

#endif
