#ifndef Aether_Sampler_h
#define Aether_Sampler_h

#include "Sample.h"

class Sampler {
public:
	// Constructor
	Sampler(int xStart, int xEnd, int yStart, int yEnd);
	
	// Public methods
	virtual bool getNextSample(Sample& sample) = 0;
	
protected:
	// Protected data
	int _xStart, _xEnd, _yStart, _yEnd;
};

#endif
