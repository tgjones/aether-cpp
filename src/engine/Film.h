#ifndef Aether_Film_h
#define Aether_Film_h

#include "Color.h"
#include "Sample.h"

class Film {
public:
	// Constructor
	Film(int xRes, int yRes)
		: _xRes(xRes), _yRes(yRes)
	{ }
	
	// Public methods
	virtual void addSample(const Sample& sample, Color c) = 0;
	float getAspectRatio() const;
	int getXRes() const;
	int getYRes() const;
	
protected:
	// Protected data
	const int _xRes, _yRes;
};

#endif
