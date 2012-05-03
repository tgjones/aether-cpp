#ifndef Aether_Tracer_h
#define Aether_Tracer_h

class Tracer {
public:
	// Constructor
	Tracer(const int width, const int height)
		: _width(width), _height(height)
	{ }
	
	// Public methods
	void trace();
	
private:
	// Private data
	int _width;
	int _height;
};

#endif
