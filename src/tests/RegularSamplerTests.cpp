#include <igloo/igloo_alt.h>
using namespace igloo;

#include "RegularSampler.h"

Describe(RegularSamplerClass)
{
	Describe(GetNextSample)
	{
		It(Returns_the_correct_samples)
		{
			auto s = RegularSampler(0, 2, 0, 2);
			
			Sample sample;
			
			Assert::That(s.getNextSample(sample), IsTrue());
			Assert::That(0, Equals(sample.getImageX()));
			Assert::That(0, Equals(sample.getImageY()));
			
			Assert::That(s.getNextSample(sample), IsTrue());
			Assert::That(1, Equals(sample.getImageX()));
			Assert::That(0, Equals(sample.getImageY()));
			
			Assert::That(s.getNextSample(sample), IsTrue());
			Assert::That(0, Equals(sample.getImageX()));
			Assert::That(1, Equals(sample.getImageY()));
			
			Assert::That(s.getNextSample(sample), IsTrue());
			Assert::That(1, Equals(sample.getImageX()));
			Assert::That(1, Equals(sample.getImageY()));
			
			Assert::That(s.getNextSample(sample), IsFalse());
		}
	};
};