#ifndef Aether_RegularSampler_h
#define Aether_RegularSampler_h

#include "Sampler.h"

class RegularSampler : public Sampler {
public:
	// Constructor
	RegularSampler(int xStart, int xEnd, int yStart, int yEnd);
	
	// Public methods
	virtual bool getNextSample(Sample& sample) override;
	
private:
	// Private data
	int _xPos, _yPos;
};

#endif
