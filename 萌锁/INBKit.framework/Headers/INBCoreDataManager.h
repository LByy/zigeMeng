//
//  INBCoreDataManager.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <CoreData/CoreData.h>
// 使用CoreData时，请将相应的文件以下列名字进行命名
// 项目中以xcdatamodeld为后缀的文件的文件名
#define INBCoreDataManagerCoreDataFileName @"INBCoreDataManagerCoreData"
// sqlite文件的文件名（项目中以xcdatamodeld为后缀的文件会自动转换为sqlite文件）
#define INBCoreDataManagerSQLiteFileName   @"INBCoreDataManagerSQLite"

@interface INBCoreDataManager : NSObject
@property (nonatomic, retain, readonly) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain, readonly) NSManagedObjectModel *managedObjectModel;
@property (nonatomic, retain, readonly) NSPersistentStoreCoordinator *persistentStoreCoordinator;
+ (INBCoreDataManager *)sharedINBCoreDataManager;
- (BOOL)save;
/**
 *  获取CoreData默认为NSManagedObject生成的id
 *
 *  @param managedObject NSManagedObject
 *
 *  @return `记录`的id
 */
- (NSNumber *)managedObjectID:(NSManagedObject *)managedObject;
/**
 *  为NSManagedObject设置自定义id
 *
 *  @param managedObject NSManagedObject
 */
//- (void)setCustomIDForManagedObject:(NSManagedObject *)managedObject;
@end
