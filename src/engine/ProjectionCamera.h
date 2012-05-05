#ifndef Aether_ProjectionCamera_h
#define Aether_ProjectionCamera_h

#include "Camera.h"
#include "Math.h"

class ProjectionCamera : public Camera {
public:
	// Constructor
	ProjectionCamera(std::shared_ptr<Film> film,
					 float nearPlaneDistance, float farPlaneDistance,
					 Vector3D lookDirection, Vector3D upDirection,
					 Point3D position);
	
	// Public methods
	virtual Ray3D generateRay(const Sample& sample) const override;
	
protected:
	// Protected methods
	Matrix3D getViewMatrix() const;
	virtual Matrix3D getProjectionMatrix() const = 0;
	
	// Protected data
	float _nearPlaneDistance, _farPlaneDistance;
	
private:
	// Private data
	Vector3D _lookDirection, _upDirection;
	Point3D _position;
};

#endif
