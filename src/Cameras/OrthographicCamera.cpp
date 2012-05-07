#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(std::shared_ptr<Film> film,
									   float nearPlaneDistance, float farPlaneDistance,
									   Vector3D& lookDirection, Vector3D& upDirection,
									   Point3D& position, float width)
	: ProjectionCamera(film, nearPlaneDistance, farPlaneDistance,
					   lookDirection, upDirection, position),
	  _width(width)
{
	
}

Matrix3D
OrthographicCamera::getProjectionMatrix() const
{
	return Matrix3D::createOrthographic(_width, _width / getAspectRatio(),
										_nearPlaneDistance, _farPlaneDistance);
}