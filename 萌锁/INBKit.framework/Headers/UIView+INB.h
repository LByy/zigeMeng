//
//  UIView+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  坐标转换
 */
@interface UIView (INBConvertGeometry)
- (CGRect)convertBoundsToMainWindow;
- (CGRect)convertBoundsToView:(UIView *)view;
- (CGPoint)convertBoundsOriginToMainWindow;
- (CGPoint)convertBoundsOriginToView:(UIView *)view;
- (CGRect)convertFrameToMainWindow;
- (CGRect)convertFrameToView:(UIView *)view;
- (CGPoint)convertFrameOriginToMainWindow;
- (CGPoint)convertFrameOriginToView:(UIView *)view;
@end

@interface UIView (INBGeometry)
@property (nonatomic, assign) CGFloat geometryX;// frame's origin x
@property (nonatomic, assign) CGFloat geometryY;// frame's origin y
@property (nonatomic, assign) CGFloat geometryWidth;// bounds' width. use bounds/center and not frame if non-identity transform.
@property (nonatomic, assign) CGFloat geometryHeight;// bounds' height. use bounds/center and not frame if non-identity transform
@property (nonatomic, assign) CGFloat geometryCenterX;// center x
@property (nonatomic, assign) CGFloat geometryCenterY;// center y
@property (nonatomic, assign) CGFloat geometryTop;// frame's min y
@property (nonatomic, assign) CGFloat geometryLeft;// frame's min x
@property (nonatomic, assign) CGFloat geometryBottom;// frame's max y
@property (nonatomic, assign) CGFloat geometryRight;// frame's max x
@property (nonatomic, assign) CGSize geometrySize;// bounds' size
@end
