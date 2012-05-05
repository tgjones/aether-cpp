#include "RegularSampler.h"

RegularSampler::RegularSampler(int xStart, int xEnd, int yStart, int yEnd)
	: Sampler(xStart, xEnd, yStart, yEnd), _xPos(xStart), _yPos(yStart) {

}

bool
RegularSampler::getNextSample(Sample& sample) {
	if (_yPos == _yEnd)
		return false;
	
	sample.setImageX(_xPos);
	sample.setImageY(_yPos);
	
	if (++_xPos == _xEnd) {
		_xPos = _xStart;
		++_yPos;
	}
	
	return true;
}