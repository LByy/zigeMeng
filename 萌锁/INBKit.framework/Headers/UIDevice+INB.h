//
//  UIDevice+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  UIDevice 便利方法
 */
@interface UIDevice (INBConvenient)
/**
 *  摄像头是否可用
 *
 *  @return 可用：YES; 不可用：NO
 */
+ (BOOL)isCameraAvailable;
/**
 *  前置摄像头是否可用
 *
 *  @return 可用：YES; 不可用：NO
 */
+ (BOOL)isFrontCameraDeviceAvailable;
/**
 *  后置摄像头是否可用
 *
 *  @return 可用：YES; 不可用：NO
 */
+ (BOOL)isRearCameraDeviceAvailable;
/**
 *  摄像头是否支持拍摄视频
 *
 *  @return 是：YES; 否：NO
 */
+ (BOOL)doesCameraSupportShootingVideos;
/**
 *  摄像头是否支持拍照
 *
 *  @return 是：YES; 否：NO
 */
+ (BOOL)doesCameraSupportTakingPhotos;
@end
