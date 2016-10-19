//
//  INBInputAccessoryView.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  view controller/text field/text view的inputAccessoryView
 *
 *  使用时，需要将相关对象(UIResponder子类)的inputAccessoryView属性设置为该类的实例
 */
@interface INBInputAccessoryView : UIToolbar
/**
 *  是否循环遍历所有的text field或text view，默认为NO
 */
@property (nonatomic) BOOL loopSearchTextInputs;
/**
 *  当前的输入域：UITextField或UITextView。该类会通过通知设置该属性（UITextFieldTextDidBeginEditingNotification、UITextViewTextDidBeginEditingNotification、UITextFieldTextDidEndEditingNotification、UITextViewTextDidEndEditingNotification）
 */
@property (nonatomic, assign, readonly) UIView<UITextInput> *textInput;
/**
 *  输入域。如果没有手动设置，该类的实现会自动进行设置
 */
@property (nonatomic, copy) NSArray *textInputs;
@property (nonatomic, weak) UIViewController *hostVC;
@end
