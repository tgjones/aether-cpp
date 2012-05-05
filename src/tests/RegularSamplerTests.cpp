#include "Tests.h"
#include "RegularSampler.h"

TEST(RegularSamplerTest, GetNextSample) {
	auto s = RegularSampler(0, 2, 0, 2);
	
	Sample sample;
	
	EXPECT_TRUE(s.getNextSample(sample));
	EXPECT_EQ(0, sample.getImageX());
	EXPECT_EQ(0, sample.getImageY());
	
	EXPECT_TRUE(s.getNextSample(sample));
	EXPECT_EQ(1, sample.getImageX());
	EXPECT_EQ(0, sample.getImageY());
	
	EXPECT_TRUE(s.getNextSample(sample));
	EXPECT_EQ(0, sample.getImageX());
	EXPECT_EQ(1, sample.getImageY());
	
	EXPECT_TRUE(s.getNextSample(sample));
	EXPECT_EQ(1, sample.getImageX());
	EXPECT_EQ(1, sample.getImageY());
	
	EXPECT_FALSE(s.getNextSample(sample));
}