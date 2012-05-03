#ifndef Aether_Camera_h
#define Aether_Camera_h

#include "Math.h"
#include "Film.h"

class Camera {
public:
	// Constructor
	Camera(Film& film);
	
	// Public methods
	virtual Ray3D generateRay();
	
private:
	// Private data
	Film _film;
};

#endif
