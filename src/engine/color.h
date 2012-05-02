#ifndef aether_color_h
#define aether_color_h

class Color {
public:
	// Constructors
	Color(float r, float g, float b) : r(r), g(g), b(b) { }
	Color() : r(0), g(0), b(0) { }
	
	// Public data
	float r, g, b;
};

#endif
