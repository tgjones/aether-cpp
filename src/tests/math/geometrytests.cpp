#include "tests.h"
#include "geometry.h"

TEST(Vector3DTest, Constructor) {
	Vector3D v = Vector3D(1, 2, 3);
	EXPECT_EQ(1, v.x);
	EXPECT_EQ(2, v.y);
	EXPECT_EQ(3, v.z);
}