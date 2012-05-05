#include <igloo/igloo_alt.h>
using namespace igloo;

#include "Plane.h"

Describe(PlaneClass)
{
	It(Has_a_constructor_that_takes_point_and_normal)
	{
		auto point = Point3D(1, 2, 3);
		auto normal = Normal3D(0, 1, 0);
		auto plane = Plane(point, normal);
		Assert::That(Point3D(1, 2, 3), Equals(plane.getPoint()));
		Assert::That(Normal3D(0, 1, 0), Equals(plane.getNormal()));
	}
	
	Describe(HitMethod)
	{
		It(Returns_true_when_ray_hits)
		{
			auto plane = Plane(Point3D(0, 0, 0), Normal3D(0, 1, 0));
			auto ray = Ray3D(Point3D(0, 4, 0), Vector3D::Down);
			double tmin;
			ShadeRec sr;
			Assert::That(plane.hit(ray, tmin, sr), IsTrue());
			Assert::That(4.0, Equals(tmin));
		}
		
		It(Returns_false_when_ray_misses)
		{
			auto plane = Plane(Point3D(0, 0, 0), Normal3D(0, 1, 0));
			auto ray = Ray3D(Point3D(0, 1, 0), Vector3D::Forward);
			double tmin;
			ShadeRec sr;
			Assert::That(plane.hit(ray, tmin, sr), IsFalse());
		}
	};
};