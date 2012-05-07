#ifndef Aether_InMemoryFilm_h
#define Aether_InMemoryFilm_h

#include <vector>
#include "Film.h"
#include "Math/Color.h"

class InMemoryFilm : public Film {
public:
	// Constructor
	InMemoryFilm(int xRes, int yRes);
	
	// Public methods
	virtual void addSample(const Sample& sample, Color c) override;
	std::vector<Color> getData() const;

private:
	// Private data
	std::vector<Color> _data;
};

#endif
