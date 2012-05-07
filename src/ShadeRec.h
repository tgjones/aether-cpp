#ifndef Aether_ShadeRec_h
#define Aether_ShadeRec_h

#include "Math/Math.h"
#include "Math/Color.h"

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
