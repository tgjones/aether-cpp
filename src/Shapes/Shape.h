#ifndef Aether_Shape_h
#define Aether_Shape_h

#include "../Math/Math.h"
#include "../ShadeRec.h"

class Shape {
public:
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const = 0;
	
protected:
	Color color;
};

#endif
