#ifndef Aether_Camera_h
#define Aether_Camera_h

#include <memory>
#include "Math.h"
#include "Film.h"
#include "Sample.h"

class Camera {
public:
	// Constructor
	Camera(std::shared_ptr<Film> film);
	
	// Accessors
	std::shared_ptr<Film> getFilm() const;
	
	// Public methods
	virtual Ray3D generateRay(const Sample& sample) const;
	
private:
	// Private data
	std::shared_ptr<Film> _film;
};

#endif
