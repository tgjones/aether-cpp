#ifndef Aether_Point4D_h
#define Aether_Point4D_h

#include <ostream>

class Point4D
{
public :	
	// Constructors
	Point4D(float x, float y, float z, float w)
    : x(x), y(y), z(z), w(w)
  { }
	Point4D() : x(0), y(0), z(0), w(1) { }
	
	// Public data
	float x, y, z, w;
};

std::ostream& operator<<(std::ostream& stream, const Point4D& p);

#endif
