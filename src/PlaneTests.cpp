#include "Tests.h"
#include "Plane.h"

TEST(PlaneTests, Constructor) {
	auto point = Point3D(1, 2, 3);
	auto normal = Normal3D(0, 1, 0);
	auto plane = Plane(point, normal);
	EXPECT_EQ(Point3D(1, 2, 3), plane.getPoint());
	EXPECT_EQ(Normal3D(0, 1, 0), plane.getNormal());
}

TEST(PlaneTests, HitSuccess) {
	auto plane = Plane(Point3D(0, 0, 0), Normal3D(0, 1, 0));
	auto ray = Ray3D(Point3D(0, 4, 0), Vector3D::Down);
	double tmin;
	ShadeRec sr;
	EXPECT_TRUE(plane.hit(ray, tmin, sr));
	EXPECT_EQ(4.0, tmin);
}

TEST(PlaneTests, HitMiss) {
	auto plane = Plane(Point3D(0, 0, 0), Normal3D(0, 1, 0));
	auto ray = Ray3D(Point3D(0, 1, 0), Vector3D::Forward);
	double tmin;
	ShadeRec sr;
	EXPECT_FALSE(plane.hit(ray, tmin, sr));
}