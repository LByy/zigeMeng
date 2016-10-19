//
//  NSString+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  日期字符串格式转换
 */
@interface NSString (INBDateFormat)
+ (NSDateFormatter *)dateFmt;
/**
 *  将某个日期格式[fromDateFormat]的字符串[dateString]转化为另外一种日期格式[toDateFormat]的字符串
 *
 *  @param dateString     当前日期字符串
 *  @param fromDateFormat 当前日期字符串所使用的日期格式
 *  @param toDateFormat   目标日期格式
 *
 *  @return 使用目标日期格式[toDateFormat]的字符串
 */
+ (NSString *)stringFromDateString:(NSString *)dateString
					fromDateFormat:(NSString *)fromDateFormat
					  toDateFormat:(NSString *)toDateFormat;
/**
 *  将日期[date]转化出使用某种日期格式[dateFormat]的字符串
 *
 *  @param date       日期
 *  @param dateFormat 日期格式
 *
 *  @return 使用日期格式[dateFormat]的字符串
 */
+ (NSString *)stringFromDate:(NSDate *)date
			  withDateFormat:(NSString *)dateFormat;
@end
/**
 *  HTML实体
 */
@interface NSString (INBHtmlEntity)
/**
 *  将包含易读字符的字符串转换为由HTML实体构成的字符串。警告：支持的实体并不全面。
 *
 *  @param readableString 字符串(可能包含易读字符)
 *
 *  @return 由HTML实体构成的字符串
 */
+ (NSString *)readableString2HtmlEntityString:(NSString *)readableString;
/**
 *  将包含HTML实体的字符串转换为易读形式的字符串。警告：支持的实体并不全面。
 *
 *  @param htmlEntityString 字符串(可能包含包含HTML实体)
 *
 *  @return 易读形式的字符串
 */
+ (NSString *)htmlEntityString2ReadableString:(NSString *)htmlEntityString;
@end
/**
 *  字符串绘制
 */
@interface NSString (INBDrawing)
/**
 *  绘制字符串（整合 iOS 7.0 earlier API 及 iOS 7.0 and later API）
 *
 *  @param point 字符串左上角所在位置
 *  @param font  渲染字符串时，所使用的字体
 *  @param color 渲染字符串时，所使用的前景色
 *
 *  @return 渲染字符串所用的尺寸
 */
- (CGSize)drawAtPoint:(CGPoint)point
		 withTextFont:(UIFont *)font
		withTextColor:(UIColor *)color;
/**
 *  获取字符串使用指定字体时所占用的尺寸（整合 iOS 7.0 earlier API 及 iOS 7.0 and later API）
 *
 *  @param font 字体
 *
 *  @return 字符串使用指定字体时所占用的尺寸
 */
- (CGSize)sizeWithTextFont:(UIFont *)font;
@end

/**
 *  对字符串进行十六进制编解码，使用小写字母
 */
@interface NSString (INBHex)
/**
 *  获取NSString对应的十六进制编码字符串
 *
 *  @return 十六进制编码字符串
 */
- (NSString *)encodeToHexString;
/**
 *  对调用`- (NSString *)encodeToHexString`得到的字符串进行还原
 *
 *  @return 还原后的NSString
 */
- (NSString *)decodeFromHexString;
/**
 *  将NSData编码为十六进制编码字符串
 *
 *  @param data data
 *
 *  @return 十六进制编码字符串
 */
+ (NSString *)encodeToHexString:(NSData *)data;
/**
 *  将十六进制编码数据还原为字符串
 *
 *  @param hexData 十六进制编码数据
 *
 *  @return 字符串
 */
+ (NSString *)decodeFromHexData:(NSData *)hexData;
@end
