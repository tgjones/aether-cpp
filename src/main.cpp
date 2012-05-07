#include "Aether.h"

int main(int argc, char* argv[])
{
  int pixelWidth = 600;
  int pixelHeight = 400;
  std::vector<Color> renderedSceneData = aetherRenderScene(pixelWidth, pixelHeight);
}
