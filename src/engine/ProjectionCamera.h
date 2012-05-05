#ifndef Aether_ProjectionCamera_h
#define Aether_ProjectionCamera_h

#include "Camera.h"

class ProjectionCamera : public Camera {
public:
	// Constructor
	ProjectionCamera(std::shared_ptr<Film> film);
};

#endif
