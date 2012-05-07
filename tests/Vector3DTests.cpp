#include <igloo/igloo_alt.h>
using namespace igloo;

#include "Math/Vector3D.h"

Describe(Vector3DClass)
{
	It(Has_a_constructor)
	{
		auto v = Vector3D(1, 2, 3);
		Assert::That(1, Equals(v.x));
		Assert::That(2, Equals(v.y));
		Assert::That(3, Equals(v.z));
	}
};
