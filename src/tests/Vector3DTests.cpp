#include "tests.h"
#include "vector3d.h"

TEST(Vector3DTest, Constructor) {
	auto v = Vector3D(1, 2, 3);
	EXPECT_EQ(1, v.x);
	EXPECT_EQ(2, v.y);
	EXPECT_EQ(3, v.z);
}