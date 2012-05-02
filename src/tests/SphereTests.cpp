#include "tests.h"
#include "math.h"
#include "sphere.h"

TEST(SphereTests, Constructor) {
	auto sphere = Sphere(Point3D(1, 2, 3), 10.0);
	EXPECT_EQ(10.0, sphere.getRadius());
}

TEST(SphereTests, HitSuccess) {
	auto sphere = Sphere(Point3D(0, 0, 3), 10.0);
	auto ray = Ray3D(Point3D(0, 0, 20), Vector3D::Forward);
	double tmin;
	ShadeRec sr;
	EXPECT_TRUE(sphere.hit(ray, tmin, sr));
	EXPECT_EQ(7.0, tmin);
}

TEST(SphereTests, HitMiss) {
	auto sphere = Sphere(Point3D(0, 0, 3), 10.0);
	auto ray = Ray3D(Point3D(20, 0, 20), Vector3D::Forward);
	double tmin;
	ShadeRec sr;
	EXPECT_FALSE(sphere.hit(ray, tmin, sr));
}