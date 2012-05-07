#include "Scene.h"

Scene::Scene(std::shared_ptr<Camera> camera,
			 std::shared_ptr<Sampler> sampler,
			 std::shared_ptr<Shape> shape)
	: _camera(camera), _sampler(sampler), _shape(shape) {
	
}

void
Scene::render() {
	Sample sample;
	
	while (_sampler->getNextSample(sample)) {
		auto ray = _camera->generateRay(sample);
		auto color = li(ray, sample);
		_camera->getFilm()->addSample(sample, color);
	}
}

Color
Scene::li(Ray3D &ray, Sample &sample) {
	// TODO: Use Integrator to actually trace ray.
	double tmin;
	ShadeRec sr;
	if (_shape->hit(ray, tmin, sr))
	{
		return Color(1, 0, 0);
	}
	return Color::Blue;
}