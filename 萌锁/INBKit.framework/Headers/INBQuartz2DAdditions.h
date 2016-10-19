//
//  INBQuartz2DAdditions.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//


#ifndef INBKit_INBQuartz2DAdditions_h
#define INBKit_INBQuartz2DAdditions_h

#import <UIKit/UIKit.h>
#import <CoreGraphics/CoreGraphics.h>

/**
 *  绘制描画线段
 *
 *  @param context     上下文
 *  @param startPoint  起始点
 *  @param endPoint    终止点
 *  @param lineWidth   线宽
 *  @param strokeColor 描画颜色
 *
 */
void drawStrokeLine(CGContextRef context,
                    CGPoint startPoint,
                    CGPoint endPoint,
                    CGFloat lineWidth,
                    CGColorRef strokeColor);
/**
 *  绘制描画直角矩形
 *
 *  @param context     上下文
 *  @param rect        矩形框
 *  @param lineWidth   线宽
 *  @param strokeColor 描画颜色
 *  @param lineJoin    线衔接
 *
 */
void drawStrokeRightAngleRectangle(CGContextRef context,
                                   CGRect rect,
                                   CGFloat lineWidth,
                                   CGColorRef strokeColor,
                                   CGLineJoin lineJoin);
/**
 *  绘制描画圆角矩形
 *
 *  @param context      上下文
 *  @param rect         矩形框
 *  @param cornerRadius 圆角半径
 *  @param lineWidth    线宽
 *  @param strokeColor  描画颜色
 *
 */
void drawStrokeRoundedRectangle(CGContextRef context,
                                CGRect rect,
                                CGFloat cornerRadius,
                                CGFloat lineWidth,
                                CGColorRef strokeColor);
/**
 *  绘制描画三角形
 *
 *  @param context     上下文
 *  @param p1          点1
 *  @param p2          点2
 *  @param p3          点3
 *  @param lineWidth   线宽
 *  @param strokeColor 描画颜色
 *  @param lineJoin    线衔接
 *
 */
void drawStrokeTriangle(CGContextRef context,
                        CGPoint p1,
                        CGPoint p2,
                        CGPoint p3,
                        CGFloat lineWidth,
                        CGColorRef strokeColor,
                        CGLineJoin lineJoin);
#endif
