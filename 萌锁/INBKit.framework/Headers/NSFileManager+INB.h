//
//  NSFileManager+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  路径
 */
@interface NSFileManager (INBPath)
+ (BOOL)fileExistsAtPath:(NSString *)path;
+ (BOOL)createDirectoryAtPath:(NSString *)path
						error:(NSError **)error;
@end
