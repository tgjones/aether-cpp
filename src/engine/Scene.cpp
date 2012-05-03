#include "Scene.h"

void
Scene::render() {
	Sample sample;
	
	while (_sampler->getNextSample(sample)) {
		auto ray = _camera->generateRay(sample);
		auto color = evaluateIncomingLight(ray, sample);
		_camera->getFilm()->addSample(sample, Color::Blue);
	}
}