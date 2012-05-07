#include "InMemoryFilm.h"

InMemoryFilm::InMemoryFilm(int xRes, int yRes)
	: Film(xRes, yRes), _data(xRes * yRes)
{
}

void
InMemoryFilm::addSample(const Sample& sample, Color c) {
	_data[(sample.getImageY() * _xRes) + sample.getImageX()] = c;
}

std::vector<Color>
InMemoryFilm::getData() const {
	return _data;
}