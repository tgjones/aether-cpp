#include "Aether.h"
#include "InMemoryFilm.h"
#include "OrthographicCamera.h"
#include "RegularSampler.h"
#include "Sphere.h"
#include "Scene.h"

std::vector<Color> aetherRenderScene(int width, int height) {
	auto film = std::make_shared<InMemoryFilm>(width, height);
	auto camera = std::make_shared<OrthographicCamera>(film);
	
	auto sampler = std::make_shared<RegularSampler>(0, width, 0, height);
	
	auto shape = std::make_shared<Sphere>(Point3D(0, 0, 0), 5);
	
	auto scene = std::make_shared<Scene>(camera, sampler, shape);
	scene->render();
	
	return film->getData();
}