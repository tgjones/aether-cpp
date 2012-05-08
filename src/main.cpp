#include <ostream>
#include <png.hpp>
#include "Aether.h"

int main(int argc, char* argv[])
{
  int pixelWidth = 600;
  int pixelHeight = 400;
  std::vector<Color> renderedSceneData = aetherRenderScene(pixelWidth, pixelHeight);
  
  png::image<png::rgb_pixel> image(128, 128);
	for (size_t y = 0; y < image.get_height(); ++y)
	{
		for (size_t x = 0; x < image.get_width(); ++x)
		{
			image[y][x] = png::rgb_pixel(x, y, x + y);
			// non-checking equivalent of image.set_pixel(x, y, ...);
		}
	}
  image.write("output.png");
}
