#ifndef Aether_OrthographicCamera_h
#define Aether_OrthographicCamera_h

#include "ProjectionCamera.h"

class OrthographicCamera : public ProjectionCamera {
public:
	// Constructor
	OrthographicCamera(std::shared_ptr<Film> film,
		float nearPlaneDistance, float farPlaneDistance,
		Vector3D lookDirection, Vector3D upDirection,
		Point3D position, float width);
	
protected:
	virtual Matrix3D getProjectionMatrix() const override;
	
private:
	float _width;
};

#endif
