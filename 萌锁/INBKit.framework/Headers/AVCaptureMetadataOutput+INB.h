//
//  AVCaptureMetadataOutput+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <AVFoundation/AVFoundation.h>
#ifdef __IPHONE_7_0
/**
 *  条码
 */
@interface AVCaptureMetadataOutput (INBBarcode)
/**
 *  所有的条形码类型
 */
@property (nonatomic, readonly) NSArray *barcodeMetadataObjectTypes NS_AVAILABLE_IOS(7_0);
/**
 *  一维条形码
 */
@property (nonatomic, readonly) NSArray *oneDimensionalBarcodeMetadataObjectTypes NS_AVAILABLE_IOS(7_0);
/**
 *  二维条形码
 */
@property (nonatomic, readonly) NSArray *twoDimensionalBarcodeMetadataObjectTypes NS_AVAILABLE_IOS(7_0);
@end
#endif
