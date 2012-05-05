#ifndef Aether_Scene_h
#define Aether_Scene_h

#include "Camera.h"
#include "Sampler.h"
#include "Shape.h"

class Scene {
public:
	// Constructor
	Scene(std::shared_ptr<Camera> camera,
		  std::shared_ptr<Sampler> sampler,
		  std::shared_ptr<Shape> shape);
	
	// Public methods
	void render();
	
private:
	// Private data
	std::shared_ptr<Camera> _camera;
	std::shared_ptr<Sampler> _sampler;
	std::shared_ptr<Shape> _shape;
	
	// Private methods
	Color li(Ray3D& ray, Sample& sample);
};

#endif
