#include "Viewport3D.h"

Viewport3D::Viewport3D(int x, int y, int width, int height)
  : _x(x), _y(y), _width(width), _height(height)
{

}

int
Viewport3D::getX() const
{
  return _x;
}

int
Viewport3D::getY() const
{
  return _y;
}

int
Viewport3D::getWidth() const
{
  return _width;
}

int
Viewport3D::getHeight() const
{
  return _height;
}

float
Viewport3D::getMinDepth() const
{
  return _minDepth;
}

void
Viewport3D::setMinDepth(float value)
{
  _minDepth = value;
}

float
Viewport3D::getMaxDepth() const
{
  return _maxDepth;
}

void
Viewport3D::setMaxDepth(float value)
{
  _maxDepth = value;
}

Point3D
Viewport3D::unproject(const Point3D& screenPoint, const Matrix3D& projection,
  const Matrix3D& view, const Matrix3D& world) const
{
  Matrix3D screenToWorld = Matrix3D::invert(world * view * projection);

  // Calculate normalized device coordinates:
  // x, y in [-1, 1] 
  // z    in [ 0, 1]
  Point4D ndc;
  ndc.x = (((screenPoint.x - _x) / (float) _width)  * 2.f) - 1.f;
  ndc.y = (((screenPoint.y - _y) / (float) _height) * 2.f) - 1.f;
  ndc.z = (screenPoint.z - _minDepth) / (_maxDepth - _minDepth);
  ndc.w = 1.f;

  // Transform to world space, and cast to Point3D, which will
  // divide x, y & z by w
  return Point3D(screenToWorld.transform(ndc));
}

Ray3D
Viewport3D::createPickRay(const int screenX, const int screenY,
  const Matrix3D& projection, const Matrix3D& view,
  const Matrix3D& world) const
{
  Point3D nearPoint = unproject(Point3D(screenX, screenY, _minDepth),
    projection, view, world);
  Point3D farPoint = unproject(Point3D(screenX, screenY, _maxDepth),
    projection, view, world);

  return Ray3D(nearPoint, Vector3D::normalize(farPoint - nearPoint));
}
