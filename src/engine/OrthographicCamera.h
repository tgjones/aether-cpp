#ifndef Aether_OrthographicCamera_h
#define Aether_OrthographicCamera_h

#include "ProjectionCamera.h"

class OrthographicCamera : public ProjectionCamera {
public:
	virtual Ray3D generateRay(const Sample& sample) const override;
};

#endif
