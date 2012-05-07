#include "Camera.h"

Camera::Camera(std::shared_ptr<Film> film) : _film(film) { }

std::shared_ptr<Film>
Camera::getFilm() const {
	return _film;
}

float
Camera::getAspectRatio() const
{
	return _film->getAspectRatio();
}