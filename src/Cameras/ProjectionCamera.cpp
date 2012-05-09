#include "ProjectionCamera.h"

#include "../Math/Viewport3D.h"

ProjectionCamera::ProjectionCamera(std::shared_ptr<Film> film,
								   float nearPlaneDistance, float farPlaneDistance,
								   Vector3D lookDirection, Vector3D upDirection,
								   Point3D position)
	: Camera(film),
	  _nearPlaneDistance(nearPlaneDistance), _farPlaneDistance(farPlaneDistance),
	  _lookDirection(lookDirection), _upDirection(upDirection),
	  _position(position)
{
	
}

Ray3D
ProjectionCamera::generateRay(const Sample &sample) const
{
	auto viewport = Viewport3D(0, 0, _film->getXRes(), _film->getYRes());
	return viewport.createPickRay(sample.getImageX(), sample.getImageY(),
		getViewMatrix(), getProjectionMatrix(), Matrix3D::Identity);
}

Matrix3D
ProjectionCamera::getViewMatrix() const
{
	return Matrix3D::createLookAt(_position, _lookDirection, _upDirection);
}