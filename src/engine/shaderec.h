//
//  ShadeRec.h
//  Aether
//
//  Created by Tim Jones on 02/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Aether_ShadeRec_h
#define Aether_ShadeRec_h

#include "math.h"
#include "color.h"
class World;

class ShadeRec {
public:
	// Constructor
	//ShadeRec(World& wr) : w(wr) { }
	ShadeRec() { }
	
	// Public data
	bool hitAnObject = false;
	Point3D localHitPoint;
	Normal3D normal;
	Color color;
	//World w;
};

#endif
