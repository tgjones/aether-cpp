#ifndef Aether_Camera_h
#define Aether_Camera_h

#include <memory>
#include "../Math/Math.h"
#include "../Film.h"
#include "../Sampling/Sample.h"

class Camera {
public:
	// Constructor
	Camera(std::shared_ptr<Film> film);
	
	// Accessors
	std::shared_ptr<Film> getFilm() const;
	
	// Public methods
	virtual Ray3D generateRay(const Sample& sample) const = 0;
	
protected:
	// Protected methods
	float getAspectRatio() const;
	
	// Protected data
	std::shared_ptr<Film> _film;
};

#endif
