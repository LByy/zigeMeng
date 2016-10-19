//
//  UIScreen+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  视网膜屏幕
 */
@interface UIScreen (INBRetinaScreen)
/**
 *  判断屏幕是否为视网膜屏幕
 *
 *  @return 如果屏幕是视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)isRetinaScreen;
/**
 *  判断屏幕是否为3.5英寸视网膜屏幕
 *
 *  @return 如果屏幕是3.5英寸视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)is3Dot5InchesRetinaScreen;
/**
 *  判断屏幕是否为4英寸视网膜屏幕，同`+ (BOOL)is4InchesRetinaScreen`
 *
 *  @return 如果屏幕是4英寸视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)is4Dot0InchesRetinaScreen;
/**
 *  判断屏幕是否为4英寸视网膜屏幕
 *
 *  @return 如果屏幕是4英寸视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)is4InchesRetinaScreen;
/**
 *  判断屏幕是否为4.7英寸视网膜屏幕
 *
 *  @return 如果屏幕是4.7英寸视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)is4Dot7InchesRetinaScreen;
/**
 *  判断屏幕是否为5.5英寸视网膜屏幕
 *
 *  @return 如果屏幕是5.5英寸视网膜屏幕,则返回YES;否则,返回NO.
 */
+ (BOOL)is5Dot5InchesRetinaScreen;
@end
