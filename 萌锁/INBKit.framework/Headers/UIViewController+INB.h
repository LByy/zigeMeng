//
//  UIViewController+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "INBInputAccessoryView.h"

@interface UIViewController (INBInputAccessoryView)
@property (nonatomic, strong) INBInputAccessoryView *inputAccessoryView;
@end

/**
 *  呈现与消除
 */
@interface UIViewController (INBPresentDismiss)
/**
 *  呈现指定的视图控制器（具有动画效果）
 *
 *  @param viewControllerToPresent 需要呈现的视图控制器
 *  @param completion              呈现结束后调用的block
 */
- (void)presentViewController:(UIViewController *)viewControllerToPresent
				   completion:(void (^)(void))completion;
/**
 *  呈现指定的视图控制器（具有动画效果）
 *
 *  @param viewControllerToPresent 需要呈现的视图控制器
 */
- (void)presentViewController:(UIViewController *)viewControllerToPresent;
/**
 *  消除调用了该方法的视图控制器（具有动画效果）
 *
 *  @param completion 消除结束后调用的block
 */
- (void)dismissViewControllerCompletion:(void (^)(void))completion;
/**
 *  消除调用了该方法的视图控制器（具有动画效果）
 */
- (void)dismissViewController;
@end
