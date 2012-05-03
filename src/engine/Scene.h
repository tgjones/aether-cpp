#ifndef Aether_Scene_h
#define Aether_Scene_h

#include "Camera.h"

class Scene {
public:
	// Constructor
	Scene(Camera camera, Shape shape);
	
	// Public methods
	void render();
};

#endif
