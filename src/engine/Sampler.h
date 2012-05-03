#ifndef Aether_Sampler_h
#define Aether_Sampler_h

#include "Sample.h"

class Sampler {
public:
	virtual bool getNextSample(Sample& sample) = 0;
};

#endif
