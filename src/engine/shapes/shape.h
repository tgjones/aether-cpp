//
//  Shape.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_Shape_h
#define Aether_Shape_h

#include "math.h"
#include "shaderec.h"

class Shape {
public:
	virtual bool hit(const Ray3D& ray, double& tmin, ShadeRec& sr) const = 0;
	
protected:
	Color color;
};

#endif
