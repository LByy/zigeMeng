//
//  UIApplication+OpenNativeApplication.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  状态栏样式
 */
@interface UIApplication (INBStatusBarStyle)
/**
 *  使用白字黑背景状态栏（不透明）
 */
+ (void)useLightContentDarkBackgroundStatusBar;
@end
/**
 *  跳转到iOS原生应用程序中
 */
@interface UIApplication (INBOpenNativeApplication)
/**
 * 打开iOS原生应用程序
 *
 * 地图:
 *	    http:maps.apple.com/maps?ll=39.9,116.4&z=12
 *	    http:maps.apple.com/maps?saddr=上海火车站&daddr=上海虹桥火车站
 *	    http:maps.apple.com/maps?q=上海虹桥火车站
 *
 * 邮箱:
 *	    mailto:a@gmail.com,b@gmail.com?cc=c@gmail.com,d@gmail.com&bcc=e@gmail.com,f@gmail.com&subject=此处填写主题&body=此处填写内容
 *
 * 消息:
 *	    sms:a@gmail.com
 *      sms:1311111111
 *
 * 电话:
 *	    tel:1311111111
 *
 * App Store:
 *		     https:itunes.apple.com/cn/app/wang-yi-xin-wen/id425349261?mt=8&uo=4
 *
 *  @param url URL(NSString * or NSURL *)
 *  @param vc  如果不能打开指定的url，将使用vc呈现UIAlertController进行提示
 */
+ (void)openNativeAppWithURL:(id)url withVC:(UIViewController *)vc;
@end
