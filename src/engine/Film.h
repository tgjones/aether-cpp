#ifndef Aether_Film_h
#define Aether_Film_h

#include "Color.h"

class Film {
public:
	// Constructor
	Film(int xRes, int yRes)
		: _xRes(xRes), _yRes(yRes)
	{ }
	
	// Public methods
	virtual void addSample(int x, int y, Color c) = 0;
	
private:
	// Private data
	const int _xRes, _yRes;
};

#endif
