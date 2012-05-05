#include "OrthographicCamera.h"

OrthographicCamera::OrthographicCamera(std::shared_ptr<Film> film)
	: ProjectionCamera(film) {
	
}

Ray3D
OrthographicCamera::generateRay(const Sample &sample) const {
	return Ray3D(Point3D(0, 0, 20), Vector3D::Forward);
}