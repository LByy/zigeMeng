//
//  INBLog.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <Foundation/Foundation.h>

// By default, Xcode defined `DEBUG=1` for debug mode, this macro doesn't exist in release mode. (see: TARGETS -> Build Settings -> Preprocessing -> Preprocessor Macros)
@interface INBLog : NSObject
+(void)file:(const char *)sourceFile function:(const char *)funcName lineNum:(int)lineNum logFormat:(NSString *)format, ...;
@end

#if (DEBUG == 1)
#define INBLog(fmt, ...) [INBLog file:__FILE__ function:__PRETTY_FUNCTION__ lineNum:__LINE__ logFormat:(fmt), ##__VA_ARGS__]
#else
#define INBLog(fmt, ...) do {} while (0)
#endif
