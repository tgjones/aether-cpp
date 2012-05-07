#ifndef Aether_PinholeCamera_h
#define Aether_PinholeCamera_h

#include "Camera.h"

class PinholeCamera : public Camera
{
public:
	// Constructor
	PinholeCamera(std::shared_ptr<Film> film, Point3D eyePosition,
				  Point3D screenTopLeft, Point3D screenTopRight);
	
	// Public methods
	virtual Ray3D generateRay(const Sample& sample) const override;
	
private:
	// Private data
	Point3D _eyePosition;
	Point3D _screenTopLeft, _screenBottomRight;
};

#endif
