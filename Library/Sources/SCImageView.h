//
//  SCCIImageView.h
//  SCRecorder
//
//  Created by Simon CORSIN on 14/05/14.
//  Copyright (c) 2014 rFlex. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreImage/CoreImage.h>
#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>

typedef enum : NSUInteger {
    SCImageViewModeFillStretched = 0,
    SCImageViewModeFillAspectRatio = 1,
    SCImageViewModeFitAspectRatio = 2
} SCImageViewMode;

@interface SCImageView : GLKView

@property (strong, nonatomic) CIImage *image;
@property (assign, nonatomic) CGRect imageSize;
@property (readonly, nonatomic) CIContext* ciContext;
@property (readonly, nonatomic) BOOL dirty;
@property (assign, nonatomic) SCImageViewMode viewMode;

// Make the view dirty, this asks the SCPlayer to render the SCImageView when it can
- (void)makeDirty;

// Process the rect with imageSize using the specified viewMode
- (CGRect)processRect:(CGRect)rect withImageSize:(CGSize)imageSize;

@end
