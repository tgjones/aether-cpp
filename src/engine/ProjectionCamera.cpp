#include "ProjectionCamera.h"

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
	Matrix3D matrix = getViewMatrix() * getProjectionMatrix();
	
	Point3D position;
	position.x = ((sample.getImageX() / _film->getXRes()) * 2.0f) - 1.0f;
	position.y = -(((sample.getImageY() / _film->getYRes()) * 2.0f) - 1.0f);
	position.z = 0;
	
	Point3D transformedPosition = matrix.transform(position);
	Vector3D direction = Vector3D::normalize(transformedPosition - position);
	
	return Ray3D(position, direction);
}

Matrix3D
ProjectionCamera::getViewMatrix() const
{
	return Matrix3D::createLookAt(_position, _lookDirection, _upDirection);
}