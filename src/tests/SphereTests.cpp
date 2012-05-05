#include <igloo/igloo_alt.h>
using namespace igloo;

#include "Math.h"
#include "Sphere.h"

Describe(SphereClass)
{
	It(Has_a_constructor_that_takes_point_and_normal)
	{
		auto point = Point3D(1, 2, 3);
		auto sphere = Sphere(point, 10.0);
		Assert::That(point, Equals(sphere.getCenter()));
		Assert::That(10.0, Equals(sphere.getRadius()));
	}
	
	Describe(HitMethod)
	{
		It(Returns_true_when_ray_hits)
		{
			auto sphere = Sphere(Point3D(0, 0, 3), 10.0);
			auto ray = Ray3D(Point3D(0, 0, 20), Vector3D::Forward);
			double tmin;
			ShadeRec sr;
			Assert::That(sphere.hit(ray, tmin, sr), IsTrue());
			Assert::That(7.0, Equals(tmin));
		}
		
		It(Returns_false_when_ray_misses)
		{
			auto sphere = Sphere(Point3D(0, 0, 3), 10.0);
			auto ray = Ray3D(Point3D(20, 0, 20), Vector3D::Forward);
			double tmin;
			ShadeRec sr;
			Assert::That(sphere.hit(ray, tmin, sr), IsFalse());
		}
	};
};