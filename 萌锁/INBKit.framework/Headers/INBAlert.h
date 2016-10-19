//
//  INBAlert.h
//  INBKit
//
//  Created by Daniate on 14/12/30.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^INBAlertCancelHandler)();
typedef void (^INBAlertDefaultHandler)();
/**
 *  弹出框，整合UIAlertView与UIAlertController。
 *
 *  注意：如果在很短的一段时间内调用了多次showXXX方法，
 *  那么只有第一个提示框会弹出，其它的都会被忽略
 */
@interface INBAlert : NSObject
+ (instancetype)sharedINBAlert;
- (void)showInViewController:(UIViewController *)viewController
				   withTitle:(NSString *)title
					messsage:(NSString *)msg
		   cancelButtonTitle:(NSString *)cancelTitle
		  defaultButtonTitle:(NSString *)defaultTitle
			   cancelHandler:(INBAlertCancelHandler)cancelHandler
			  defaultHandler:(INBAlertDefaultHandler)defaultHandler;
- (void)dismiss;
@end
