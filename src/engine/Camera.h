#ifndef Aether_Camera_h
#define Aether_Camera_h

#include "Math.h"

class Camera {
public:
	virtual Ray3D generateRay();
};

#endif
