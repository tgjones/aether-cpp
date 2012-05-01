//
//  AppController.h
//  Aether
//
//  Created by Tim Jones on 01/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppController : NSObject {
@private
	IBOutlet NSImageView* imageView;
}

- (IBAction)render:(id)sender;

@end
