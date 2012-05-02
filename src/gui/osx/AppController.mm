//
//  AppController.m
//  Aether
//
//  Created by Tim Jones on 01/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "AppController.h"
#import "Geometry.h"
#import "Shape.h"
#import "Plane.h"
#import "ShadeRec.h"

#define SAMPLE_SIZE 8
#define SAMPLE_NUMBER 3
#define PIXEL_BYTES 3

@implementation AppController

- (IBAction)render:(id)sender {
	CGSize size = [imageView bounds].size;
	int pixelWidth = size.width, pixelHeight = size.height;
	unsigned char* bitmapData = (unsigned char*) calloc(pixelWidth * pixelHeight * PIXEL_BYTES,
														sizeof(unsigned char));
	
	for (uint row = 0; row < pixelHeight; row++)
	{
		for (uint col = 0; col < pixelWidth; col++)
		{
			double color[3] = { 128, 0, 0 };
			int intColor[3];
			uint byteOffset = PIXEL_BYTES * ((row * pixelWidth) + col);
			for (uint i = 0; i < 3; i++)
			{
				intColor[i] = round(color[i]);
				bitmapData[byteOffset + i] = intColor[i];
			}
		}
	}
	
	NSBitmapImageRep* imageRep = [[NSBitmapImageRep alloc] initWithBitmapDataPlanes:&bitmapData
																		 pixelsWide:pixelWidth
																		 pixelsHigh:pixelHeight
																	  bitsPerSample:SAMPLE_SIZE
																	samplesPerPixel:SAMPLE_NUMBER
																		   hasAlpha:NO
																		   isPlanar:NO
																	 colorSpaceName:NSCalibratedRGBColorSpace
																		bytesPerRow:(pixelWidth * PIXEL_BYTES)
																	   bitsPerPixel:0];
	
	NSImage* image = [[NSImage alloc] initWithSize:size];
	[image addRepresentation:imageRep];
	[imageView setImage:image];
}

@end
