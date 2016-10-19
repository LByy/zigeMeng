//
//  UIWindow+INB.h
//  INBKit
//
//  Created by Daniate on 15/10/28.
//  Copyright © 2015年 上海胤贝. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIWindow (INB)
/**
 *  最适合的window(满足4个条件：bounds与屏幕的bounds相同、可见、关联的screen与mainScreen相同、normal window level)，如果不满足上述4个条件，则返回key window
 *
 *  @return window
 */
+ (UIWindow *)suitableWindow;
@end
