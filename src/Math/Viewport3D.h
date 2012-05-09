#ifndef Aether_Viewport3D_h
#define Aether_Viewport3D_h

#include "Matrix3D.h"
#include "Point3D.h"
#include "Point4D.h"
#include "Ray3D.h"

class Viewport3D
{
public:
  // Constructor
  Viewport3D(int x, int y, int width, int height);

  // Accessors
  int getX() const;
  int getY() const;
  int getWidth() const;
  int getHeight() const;
  float getMinDepth() const;
  void setMinDepth(float value);
  float getMaxDepth() const;
  void setMaxDepth(float value);

  // Methods
  Point3D unproject(const Point3D& screenPoint, const Matrix3D& projection,
    const Matrix3D& view, const Matrix3D& world) const;
  Ray3D createPickRay(const int screenX, const int screenY,
    const Matrix3D& projection, const Matrix3D& view,
    const Matrix3D& world) const;

private:
  // Private data
  int _x, _y, _width, _height;
  float _minDepth = 0.0f;
  float _maxDepth = 1.0f;
};

#endif
