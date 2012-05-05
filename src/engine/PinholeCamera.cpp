#include "PinholeCamera.h"

PinholeCamera::PinholeCamera(std::shared_ptr<Film> film, Point3D eyePosition,
							 Point3D screenTopLeft, Point3D screenBottomRight)
	: Camera(film), _eyePosition(eyePosition),
	  _screenTopLeft(screenTopLeft),
	  _screenBottomRight(screenBottomRight)
{
	
}

Ray3D
PinholeCamera::generateRay(const Sample &sample) const
{
	// calculate width and height of a pixel in world space coords
	float pixelWidth = (_screenBottomRight.x - _screenTopLeft.x) / _film->getXRes();
	float pixelHeight = (_screenTopLeft.y - _screenBottomRight.y) / _film->getYRes();
	
	// First, calculate direction of the current pixel from eye position
	float sx = _screenTopLeft.x + (sample.getImageX() * pixelWidth);
	float sy = _screenTopLeft.y - (sample.getImageY() * pixelHeight);
	Vector3D eyeToPixelDir = Point3D(sx, sy, 0) - _eyePosition;
	eyeToPixelDir.normalize();
	
	// Set up primary (eye) ray
	return Ray3D(_eyePosition, eyeToPixelDir);
}