//
//  UIImage+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <UIKit/UIKit.h>
/**
 *  创建单色图片
 */
@interface UIImage (INBPureColorImage)
/**
 *  使用指定的颜色、尺寸、圆角，创建纯色图片（单色图片）
 *
 *  @param color  颜色
 *  @param size   尺寸
 *  @param radius 圆角
 *
 *  @return 纯色图片（单色图片）
 */
+ (UIImage *)imageWithColor:(UIColor *)color
					   size:(CGSize)size
			   cornerRadius:(CGFloat)radius;
/**
 *  使用指定的颜色、尺寸，创建无圆角的纯色图片（单色图片）
 *
 *  @param color  颜色
 *  @param size   尺寸
 *
 *  @return 纯色图片（单色图片）
 */
+ (UIImage *)imageWithColor:(UIColor *)color
					   size:(CGSize)size;
/**
 *  使用指定的颜色，创建尺寸为{1 point, 1 point}、无圆角的纯色图片（单色图片）
 *
 *  @param color  颜色
 *
 *  @return 纯色图片（单色图片）
 */
+ (UIImage *)imageWithColor:(UIColor *)color;
@end
/**
 *  颜色渐变方向
 */
typedef NS_ENUM(NSUInteger, INBLinearGradientColorDirection){
	/**
	 *  top to bottom
	 */
	INBLinearGradientColorDirectionTop2Bottom,
	/**
	 *  bottom to top
	 */
	INBLinearGradientColorDirectionBottom2Top,
	/**
	 *  left to right
	 */
	INBLinearGradientColorDirectionLeft2Right,
	/**
	 *  right to left
	 */
	INBLinearGradientColorDirectionRight2Left,
    INBLinearGradientColorDirectionTopLeft2BottomRight,
    INBLinearGradientColorDirectionTopRight2BottomLeft,
    INBLinearGradientColorDirectionBottomLeft2TopRight,
    INBLinearGradientColorDirectionBottomRight2TopLeft,
};
/**
 *  创建颜色渐变图片
 */
@interface UIImage (INBLinearGradientColorImage)
/**
 *  使用指定的颜色，创建线性渐变图片
 *
 *  @param colors    UIColor(s)
 *  @param direction 渐变方向
 *  @param size      图片尺寸
 *  @param radius    圆角
 *
 *  @return 线性渐变图片
 */
+ (UIImage *)imageWithColors:(NSArray *)colors
				   direction:(INBLinearGradientColorDirection)direction
						size:(CGSize)size
				cornerRadius:(CGFloat)radius;
/**
 *  使用指定的颜色，创建线性渐变图片
 *
 *  @param colors    UIColor(s)
 *  @param direction 渐变方向
 *  @param size      图片尺寸
 *
 *  @return 线性渐变图片
 */
+ (UIImage *)imageWithColors:(NSArray *)colors
				   direction:(INBLinearGradientColorDirection)direction
						size:(CGSize)size;
@end
/**
 *  创建尺寸可调整图片
 */
@interface UIImage (INBResizableImage)
/**
 *  使用图片中心位置的像素点，对图片进行平铺调整（使用UIImageResizingModeTile）
 *
 *  @return 调整后的图片
 */
- (UIImage *)resizableImage;
/**
 *  使用图片中心位置的像素点，对图片进行平铺/拉伸调整
 *
 *  @param resizingMode 调整模式
 *
 *  @return 调整后的图片
 */
- (UIImage *)resizableImageWithResizingMode:(UIImageResizingMode)resizingMode;
@end
/**
 *  所使用的模式，不要修改对应的值
 */
typedef NS_ENUM(NSInteger, INBImageCompressionMode){
	/**
	 *  填充（不保持原有的宽高比）
	 */
	INBImageCompressionModeFill = UIViewContentModeScaleToFill,
	/**
	 *  合身（保持原有的宽高比）
	 */
	INBImageCompressionModeAspectFit = UIViewContentModeScaleAspectFit,
	/**
	 *  填充（保持原有的宽高比）
	 */
	INBImageCompressionModeAspectFill = UIViewContentModeScaleAspectFill,
};

/**
 *  通过缩小图片尺寸，实现图片质量压缩
 */
@interface UIImage (INBQualityCompression)
/**
 *  将图片压缩到指定的分辨率，使用的INBImageCompressionMode为INBImageCompressionModeAspectFit。如果图片的原始宽高均不大于指定的宽高，则不进行处理。
 *
 *  @param destImgSize 图片最终的分辨率：size.width像素 * size.height像素
 *
 *  @return 压缩后的图片
 */
- (UIImage *)compressImageToSpecifiedCGSize:(CGSize)destImgSize;
/**
 *  使用指定的INBImageCompressionMode，将图片压缩到指定的分辨率。如果图片的原始宽高均不大于指定的宽高，则不进行处理。
 *
 *  @param destImgSize  图片最终的分辨率：size.width像素 * size.height像素
 *  @param compressMode [fill]/[aspect fit]/[aspect fill]
 *
 *  @return 压缩后的图片
 */
- (UIImage *)compressImageToSpecifiedCGSize:(CGSize)destImgSize
								   withMode:(INBImageCompressionMode)compressMode;
/**
 *  将图片压缩至指定的内存占用值，以千字节计算，
 *  使用的INBImageCompressionMode为INBImageCompressionModeAspectFit
 *  如果图片的原始大小不大于指定的值，则不进行处理。
 *
 *  @param specifiedKB 指定的内存占用值，以千字节计算
 *
 *  @return 压缩后的图片
 */
- (UIImage *)compressImageToSpecifiedKB:(CGFloat)specifiedKB;
/**
 *  将图片压缩至指定的内存占用值，以千字节计算
 *  如果图片的原始大小不大于指定的值，则不进行处理。
 *
 *  @param specifiedKB  指定的内存占用值，以千字节计算
 *  @param compressMode [fill]/[aspect fit]/[aspect fill]
 *
 *  @return 压缩后的图片
 */
- (UIImage *)compressImageToSpecifiedKB:(CGFloat)specifiedKB
							   withMode:(INBImageCompressionMode)compressMode;
@end

/**
 *  图片格式format只能是: kUTTypePNG / kUTTypeJPEG / kUTTypeJPEG2000
 *  如果没有指定图片格式，则使用kUTTypePNG
 */
@interface UIImage (INBReadWrite)
- (BOOL)writeToFileUnderDirectory:(NSString *)directory
			   withPathComponents:(NSString *)pathComponents
						imgFormat:(CFStringRef)format;
- (BOOL)writeToFileUnderDirectory:(NSString *)directory
			   withPathComponents:(NSString *)pathComponents
		 allowWhitespaceComponent:(BOOL)allow
					trimComponent:(BOOL)trim
						imgFormat:(CFStringRef)format;

- (BOOL)writeToFileUnderDocuments:(NSString *)pathComponents
						imgFormat:(CFStringRef)format;
- (BOOL)writeToFileUnderDocuments:(NSString *)pathComponents
		 allowWhitespaceComponent:(BOOL)allow
					trimComponent:(BOOL)trim
						imgFormat:(CFStringRef)format;

- (BOOL)writeToFileUnderLibrary:(NSString *)pathComponents
					  imgFormat:(CFStringRef)format;;
- (BOOL)writeToFileUnderLibrary:(NSString *)pathComponents
	   allowWhitespaceComponent:(BOOL)allow
				  trimComponent:(BOOL)trim
					  imgFormat:(CFStringRef)format;

+ (UIImage *)imageWithContentsOfFileUnderDirectory:(NSString *)directory
								withPathComponents:(NSString *)pathComponents;
+ (UIImage *)imageWithContentsOfFileUnderDirectory:(NSString *)directory
								withPathComponents:(NSString *)pathComponents
						  allowWhitespaceComponent:(BOOL)allow
									 trimComponent:(BOOL)trim;

+ (UIImage *)imageWithContentsOfFileUnderDocuments:(NSString *)pathComponents;
+ (UIImage *)imageWithContentsOfFileUnderDocuments:(NSString *)pathComponents
						  allowWhitespaceComponent:(BOOL)allow
									 trimComponent:(BOOL)trim;

+ (UIImage *)imageWithContentsOfFileUnderLibrary:(NSString *)pathComponents;
+ (UIImage *)imageWithContentsOfFileUnderLibrary:(NSString *)pathComponents
						allowWhitespaceComponent:(BOOL)allow
								   trimComponent:(BOOL)trim;
@end