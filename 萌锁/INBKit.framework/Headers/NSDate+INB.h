//
//  NSDate+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  日期格式化
 */
@interface NSDate (INBDateFormat)
/**
 *  将使用某种日期格式[dateFormat]的字符串[dateString]转化为日期
 *
 *  @param dateString 日期字符串
 *  @param dateFormat 日期字符串所使用的日期格式
 *
 *  @return 日期
 */
+ (NSDate *)dateFromDateString:(NSString *)dateString
				withDateFormat:(NSString *)dateFormat;
@end
