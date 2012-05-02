#include "tests.h"
#include "sphere.h"

TEST(SphereTests, Constructor) {
	auto sphere = Sphere(Point3D(1, 2, 3), 10.0);
	EXPECT_EQ(10.0, sphere.getRadius());
}