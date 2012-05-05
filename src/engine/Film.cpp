#include "Film.h"

float
Film::getAspectRatio() const
{
	return _xRes / (float) _yRes;
}

int
Film::getXRes() const
{
	return _xRes;
}

int
Film::getYRes() const
{
	return _yRes;
}