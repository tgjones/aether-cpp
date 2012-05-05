#ifndef Aether_OrthographicCamera_h
#define Aether_OrthographicCamera_h

#include "ProjectionCamera.h"

class OrthographicCamera : public ProjectionCamera {
public:
	// Constructor
	OrthographicCamera(std::shared_ptr<Film> film);
	
	// Public methods
	virtual Ray3D generateRay(const Sample& sample) const override;
};

#endif
