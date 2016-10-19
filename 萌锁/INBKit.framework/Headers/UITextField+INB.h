//
//  UITextField+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextField (INBDisablePaste)
/**
 *  是否禁用text field的复制、粘贴、剪切功能。默认为NO（不禁用）
 */
@property (nonatomic, assign, getter=isDisableCopyPasteCut) BOOL disableCopyPasteCut;
@end
