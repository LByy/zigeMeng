//
//  INBKeyboardManager.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface INBKeyboardManager : NSObject
+ (INBKeyboardManager *)sharedINBKeyboardManager;
/**
 *  当前的基础视图（通常使用UIScrollView）
 */
@property (nonatomic, weak) UIView *currentBaseView;
/**
 *  注册通知：Keyboard、TextField、TextView
 */
- (void)registerNotifications;
/**
 *  移除通知：Keyboard、TextField、TextView
 */
- (void)removeNotifications;
/**
 *  注册键盘通知
 */
- (void)registerKeyboardNotifications;
/**
 *  移除键盘通知
 */
- (void)removeKeyboardNotifications;
/**
 *  注册输入框通知
 */
- (void)registerTextFieldNotifications;
/**
 *  移除输入框通知
 */
- (void)removeTextFieldNotifications;
/**
 *  移除文本视图通知
 */
- (void)registerTextViewNotifications;
/**
 *  移除文本视图通知
 */
- (void)removeTextViewNotifications;

@end
