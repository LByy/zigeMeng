//
//  INBMacroAdditions.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#ifndef INBKit_INBMacroAdditions_h
#define INBKit_INBMacroAdditions_h

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <GLKit/GLKit.h>
#import <Availability.h>
#import <AvailabilityInternal.h>
#import <objc/runtime.h>

#import "UIScreen+INB.h"
#import "UIImage+INB.h"

#pragma mark - ARC(自动引用计数)
#define INBARCStrong           __strong
#define INBARCWeak             __weak
#define INBARCUnsafeUnretained __unsafe_unretained
#define INBARCAutoreleasing    __autoreleasing
#define INBARCBridge           __bridge
#define INBARCBridgeRetained   __bridge_retained
#define INBARCBridgeTransfer   __bridge_transfer

#pragma mark - block
#define INBWeakSelf typeof(self) __weak zelf = self

#pragma mark - ARC环境下的严格单例
#define INBStrictSingletonForClass(__CLASS_NAME__) \
static __CLASS_NAME__ *shared##__CLASS_NAME__ = nil;\
+ (__CLASS_NAME__ *)shared##__CLASS_NAME__ {\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
shared##__CLASS_NAME__ = [[super allocWithZone:NULL] init];\
});\
return shared##__CLASS_NAME__;\
}\
+ (id)allocWithZone:(struct _NSZone *)zone {\
return [__CLASS_NAME__ shared##__CLASS_NAME__];\
}

#pragma mark - iOS内置的Singletons
#define INBUIApplication        [UIApplication sharedApplication]
#define INBUIDevice             [UIDevice currentDevice]
#define INBUIScreen             [UIScreen mainScreen]
#define INBNSNotificationCenter [NSNotificationCenter defaultCenter]
#define INBNSFileManager        [NSFileManager defaultManager]
#define INBNSUserDefaults       [NSUserDefaults standardUserDefaults]
#define INBAVAudioSession       [AVAudioSession sharedInstance]
#ifdef __IPHONE_9_0
#define INBGKRandomSource       [GKRandomSource sharedRandom]
#endif

#pragma mark - CALayer animatable key paths
#define INBCAAnimationKeyPathBounds                 @"bounds"
#define INBCAAnimationKeyPathPosition               @"position"
#define INBCAAnimationKeyPathZPosition              @"zPosition"
#define INBCAAnimationKeyPathAnchorPoint            @"anchorPoint"
#define INBCAAnimationKeyPathAnchorPointZ           @"anchorPointZ"
#define INBCAAnimationKeyPathTransform              @"transform"
#define INBCAAnimationKeyPathTransformRotation      @"transform.rotation"
#define INBCAAnimationKeyPathHidden                 @"hidden"
#define INBCAAnimationKeyPathDoubleSided            @"doubleSided"
#define INBCAAnimationKeyPathSublayerTransform      @"sublayerTransform"
#define INBCAAnimationKeyPathMasksToBounds          @"masksToBounds"
#define INBCAAnimationKeyPathContents               @"contents"
#define INBCAAnimationKeyPathContentsRect           @"contentsRect"
#define INBCAAnimationKeyPathContentsScale          @"contentsScale"
#define INBCAAnimationKeyPathContentsCenter         @"contentsCenter"
#define INBCAAnimationKeyPathMinificationFilterBias @"minificationFilterBias"
#define INBCAAnimationKeyPathBackgroundColor        @"backgroundColor"
#define INBCAAnimationKeyPathCornerRadius           @"cornerRadius"
#define INBCAAnimationKeyPathBorderWidth            @"borderWidth"
#define INBCAAnimationKeyPathBorderColor            @"borderColor"
#define INBCAAnimationKeyPathOpacity                @"opacity"
#define INBCAAnimationKeyPathCompositingFilter      @"compositingFilter"
#define INBCAAnimationKeyPathFilters                @"filters"
#define INBCAAnimationKeyPathBackgroundFilters      @"backgroundFilters"
#define INBCAAnimationKeyPathShouldRasterize        @"shouldRasterize"
#define INBCAAnimationKeyPathRasterizationScale     @"rasterizationScale"
#define INBCAAnimationKeyPathShadowColor            @"shadowColor"
#define INBCAAnimationKeyPathShadowOpacity          @"shadowOpacity"
#define INBCAAnimationKeyPathShadowOffset           @"shadowOffset"
#define INBCAAnimationKeyPathShadowRadius           @"shadowRadius"
#define INBCAAnimationKeyPathShadowPath             @"shadowPath"
#define INBCAAnimationKeyPathBoundsSize                    @"bounds.size"
#define INBCAAnimationKeyPathBoundsSizeWidth               @"bounds.size.width"
#define INBCAAnimationKeyPathBoundsSizeHeight              @"bounds.size.height"
#define INBCAAnimationKeyPathPositionX                     @"position.x"
#define INBCAAnimationKeyPathPositionY                     @"position.y"
#define INBCAAnimationKeyPathAnchorPointX                  @"anchorPoint.x"
#define INBCAAnimationKeyPathAnchorPointY                  @"anchorPoint.y"
#define INBCAAnimationKeyPathTransformTranslation          @"transform.translation"
#define INBCAAnimationKeyPathTransformTranslationX         @"transform.translation.x"
#define INBCAAnimationKeyPathTransformTranslationY         @"transform.translation.y"
#define INBCAAnimationKeyPathTransformTranslationZ         @"transform.translation.z"
#define INBCAAnimationKeyPathTransformScale                @"transform.scale"
#define INBCAAnimationKeyPathTransformScaleX               @"transform.scale.x";
#define INBCAAnimationKeyPathTransformScaleY               @"transform.scale.y";
#define INBCAAnimationKeyPathTransformRotationX            @"transform.rotation.x"
#define INBCAAnimationKeyPathTransformRotationY            @"transform.rotation.y"
#define INBCAAnimationKeyPathTransformRotationZ            @"transform.rotation.z"
#define INBCAAnimationKeyPathSublayerTransformTranslation  @"sublayerTransform.translation"
#define INBCAAnimationKeyPathSublayerTransformTranslationX @"sublayerTransform.translation.x"
#define INBCAAnimationKeyPathSublayerTransformTranslationY @"sublayerTransform.translation.y"
#define INBCAAnimationKeyPathSublayerTransformTranslationZ @"sublayerTransform.translation.z"
#define INBCAAnimationKeyPathSublayerTransformScale        @"sublayerTransform.scale"
#define INBCAAnimationKeyPathSublayerTransformScaleX       @"sublayerTransform.scale.x"
#define INBCAAnimationKeyPathSublayerTransformScaleY       @"sublayerTransform.scale.y"
#define INBCAAnimationKeyPathSublayerTransformRotation     @"sublayerTransform.rotation"
#define INBCAAnimationKeyPathSublayerTransformRotationX    @"sublayerTransform.rotation.x"
#define INBCAAnimationKeyPathSublayerTransformRotationY    @"sublayerTransform.rotation.y"
#define INBCAAnimationKeyPathSublayerTransformRotationZ    @"sublayerTransform.rotation.z"
#define INBCAAnimationKeyPathContentsRectOrigin            @"contentsRect.origin"
#define INBCAAnimationKeyPathContentsRectOriginX           @"contentsRect.origin.x"
#define INBCAAnimationKeyPathContentsRectOriginY           @"contentsRect.origin.y"
#define INBCAAnimationKeyPathContentsRectSize              @"contentsRect.size"
#define INBCAAnimationKeyPathContentsRectSizeWidth         @"contentsRect.size.width"
#define INBCAAnimationKeyPathContentsRectSizeHeight        @"contentsRect.size.height"
#define INBCAAnimationKeyPathContentsCenterOrigin          @"contentsCenter.origin"
#define INBCAAnimationKeyPathContentsCenterOriginX         @"contentsCenter.origin.x"
#define INBCAAnimationKeyPathContentsCenterOriginY         @"contentsCenter.origin.y"
#define INBCAAnimationKeyPathContentsCenterSize            @"contentsCenter.size"
#define INBCAAnimationKeyPathContentsCenterSizeWidth       @"contentsCenter.size.width"
#define INBCAAnimationKeyPathContentsCenterSizeHeight      @"contentsCenter.size.height"
#define INBCAAnimationKeyPathShadowOffsetWidth             @"shadowOffset.width"
#define INBCAAnimationKeyPathShadowOffsetHeight            @"shadowOffset.height"

#pragma mark - Data
#define INBDataFromString(__STR__) [__STR__ dataUsingEncoding:NSUTF8StringEncoding]

#pragma mark - 字符串
#define INBStringFromClass(__CLASS_NAME__) NSStringFromClass([__CLASS_NAME__ class])
#define INBStringFromData(__DATA__) [[NSString alloc] initWithData:__DATA__ encoding:NSUTF8StringEncoding]
#pragma mark - 字符串处理 - 去除两侧空白符(White Space, WS)
#define INBTrimmedStringWS(__STRING__)   ([(__STRING__) isKindOfClass:[NSString class]] ? (((NSString *)(__STRING__)).length == 0 ? @"" : [((NSString *)(__STRING__)) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]]) : @"")
#pragma mark - 字符串处理 - 去除两侧空白符(White Space, WS)及换行符(New Line, NL)
#define INBTrimmedStringWSNL(__STRING__) ([(__STRING__) isKindOfClass:[NSString class]] ? (((NSString *)(__STRING__)).length == 0 ? @"" : [((NSString *)(__STRING__)) stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]]) : @"")
#pragma mark - 字符串处理 - 判断字符串是否为空白字符串或NULL
#define INBIsBlankOrNullString(__STRING__) (INBTrimmedStringWSNL(__STRING__).length == 0 ? YES : NO)
#pragma mark - 字符串处理 - 将指定的UITextField文本去除两侧空白符(White Space, WS)
#define INBTrimmedTextFieldText(__TEXT_FIELD__) ([(__TEXT_FIELD__) isKindOfClass:[UITextField class]] ? INBTrimmedStringWS(((UITextField *)(__TEXT_FIELD__)).text) : @"")
#pragma mark - 字符串处理 - 将指定的UITextView文本去除两侧空白符(White Space, WS)
#define INBTrimmedTextViewText(__TEXT_VIEW__)   ([(__TEXT_VIEW__) isKindOfClass:[UITextView class]] ? INBTrimmedStringWS(((UITextView *)(__TEXT_VIEW__)).text) : @"")
#pragma mark - 字符串处理 - 判断UITextField中的文本是否为空白字符串或NULL
#define INBTextFieldTextIsBlankOrNullString(__TEXT_FIELD__) (INBTrimmedTextFieldText(__TEXT_FIELD__).length == 0 ? YES : NO)
#pragma mark - 字符串处理 - 判断UITextView中的文本是否为空白字符串或NULL
#define INBTextViewTextIsBlankOrNullString(__TEXT_VIEW__) (INBTrimmedTextViewText(__TEXT_VIEW__).length == 0 ? YES : NO)

#pragma mark - 数字转字符串
#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
#define INBNSIntegerString(__NSIntegerValue__)   [NSString stringWithFormat:@"%ld", (long)(__NSIntegerValue__)]
#define INBNSUIntegerString(__NSUIntegerValue__) [NSString stringWithFormat:@"%lu", (unsigned long)(__NSUIntegerValue__)]
#else
#define INBNSIntegerString(__NSIntegerValue__)   [NSString stringWithFormat:@"%d", (int)(__NSIntegerValue__)]
#define INBNSUIntegerString(__NSUIntegerValue__) [NSString stringWithFormat:@"%u", (unsigned int)(__NSUIntegerValue__)]
#endif
#define INBIntString(__INT__)                    [NSString stringWithFormat:@"%d", __INT__]
#define INBLongString(__LONG__)                  [NSString stringWithFormat:@"%ld", __LONG__]
#define INBLongLongString(__LONG_LONG____)       [NSString stringWithFormat:@"%lld", __LONG_LONG____]
#define INBUnsignedIntString(__UNSIGNED_INT__)   [NSString stringWithFormat:@"%u", __UNSIGNED_INT__]
#define INBUnsignedLongString(__UNSIGNED_LONG__) [NSString stringWithFormat:@"%lu", __UNSIGNED_LONG__]
#define INBUnsignedLongLongString(__UNSIGNED_LONG_LONG__) [NSString stringWithFormat:@"%llu", __UNSIGNED_LONG_LONG__]

#pragma mark - 应用程序窗口
#define INBWindows     (INBUIApplication.windows)
#define INBFirstWindow ((UIWindow *)(INBWindows.firstObject))
#define INBLastWindow  ((UIWindow *)(INBWindows.lastObject))
#define INBKeyWindow   (INBUIApplication.keyWindow)

#pragma mark - 随机浮点数，区间为[0.0f, 1.0f]
#define INBRndFloat (arc4random() % UINT32_MAX * 1.0f / (UINT32_MAX - 1))
// [0, N]区间内的随机数
#define INBRndUnsignedIntFrom0ToN(__N__) arc4random_uniform((__N__) + 1)

#pragma mark - 颜色
#define INBBlackColor     [UIColor blackColor]
#define INBDarkGrayColor  [UIColor darkGrayColor]
#define INBLightGrayColor [UIColor lightGrayColor]
#define INBWhiteColor     [UIColor whiteColor]
#define INBGrayColor      [UIColor grayColor]
#define INBRedColor       [UIColor redColor]
#define INBGreenColor     [UIColor greenColor]
#define INBBlueColor      [UIColor blueColor]
#define INBCyanColor      [UIColor cyanColor]
#define INBYellowColor    [UIColor yellowColor]
#define INBMagentaColor   [UIColor magentaColor]
#define INBOrangeColor    [UIColor orangeColor]
#define INBPurpleColor    [UIColor purpleColor]
#define INBBrownColor     [UIColor brownColor]
#define INBClearColor     [UIColor clearColor]
#pragma mark - 颜色 - RGB
#define INBRGBAColor(__RED_0_255__, __GREEN_0_255__, __BLUE_0_255__, __ALPHA_0_255__) [UIColor colorWithRed:(__RED_0_255__)/255.0f green:(__GREEN_0_255__)/255.0f blue:(__BLUE_0_255__)/255.0f alpha:(__ALPHA_0_255__)/255.0f]
#define INBRGBColor(__RED_0_255__, __GREEN_0_255__, __BLUE_0_255__) INBRGBAColor(__RED_0_255__, __GREEN_0_255__, __BLUE_0_255__, 255.0f)
#pragma mark - 颜色 - HEX
#define INBHexColor(__HEX__) INBRGBColor(((__HEX__) & 0xFF0000) >> 16, ((__HEX__) & 0xFF00) >> 8, (__HEX__) & 0xFF)
#define INBHexAColor(__HEX__, __ALPHA_0_255__) INBRGBAColor(((__HEX__) & 0xFF0000) >> 16, ((__HEX__) & 0xFF00) >> 8, (__HEX__) & 0xFF, __ALPHA_0_255__)
#pragma mark - 颜色 - 系统弹框弹出时所使用的半透明暗淡颜色
#define INBDimColor [UIColor colorWithWhite:0 alpha:0.4f]
#pragma mark - 颜色 - 可在调试模式下时使用随机颜色
#if (DEBUG == 1)
#define INBRndColor             [UIColor colorWithRed:INBRndFloat green:INBRndFloat blue:INBRndFloat alpha:1.0f]
#define INBRndColorWithRndAlpha [UIColor colorWithRed:INBRndFloat green:INBRndFloat blue:INBRndFloat alpha:INBRndFloat]
#else
#define INBRndColor             nil
#define INBRndColorWithRndAlpha nil
#endif

#pragma mark - 系统版本比对(>)
#define INBSystemVersionGreaterThan(__VERSION_STRING__)          ([[INBUIDevice systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] == NSOrderedDescending)
#pragma mark - 系统版本比对(>=)
#define INBSystemVersionGreaterThanOrEqualTo(__VERSION_STRING__) ([[INBUIDevice systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] != NSOrderedAscending)
#pragma mark - 系统版本比对(<)
#define INBSystemVersionLessThan(__VERSION_STRING__)             ([[INBUIDevice systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] == NSOrderedAscending)
#pragma mark - 系统版本比对(<=)
#define INBSystemVersionLessThanOrEqualTo(__VERSION_STRING__)    ([[INBUIDevice systemVersion] compare:(__VERSION_STRING__) options:NSNumericSearch] != NSOrderedDescending)
#pragma mark - 便利的系统版本比对
#define INBIOS5_0_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"5.0")
#define INBIOS5_1_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"5.1")
#define INBIOS6_0_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"6.0")
#define INBIOS6_1_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"6.1")
#define INBIOS7_0_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"7.0")
#define INBIOS7_1_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"7.1")
#define INBIOS8_0_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.0")
#define INBIOS8_1_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.1")
#define INBIOS8_1_1OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.1.1")
#define INBIOS8_2_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.2")
#define INBIOS8_3_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.3")
#define INBIOS8_4_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"8.4")
#define INBIOS9_0_0OrLater INBSystemVersionGreaterThanOrEqualTo(@"9.0")

#pragma mark - Version
#define INBVersionString ((NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleShortVersionString"])
#pragma mark - Build
#define INBBuildString   ((NSString *)[[NSBundle mainBundle] objectForInfoDictionaryKey:@"CFBundleVersion"])

#pragma mark - 沙盒中的`Documents`目录
#define INBDocumentsDirectory    ((NSString *)(NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject))
#define INBDocumentsDirectoryURL ((NSURL *)([INBNSFileManager URLsForDirectory:NSDocumentDirectory inDomains:NSUserDomainMask].firstObject))
#pragma mark - 沙盒中的`Library`目录
#define INBLibraryDirectory    ((NSString *)(NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject))
#define INBLibraryDirectoryURL ((NSURL *)([INBNSFileManager URLsForDirectory:NSLibraryDirectory inDomains:NSUserDomainMask].firstObject))

#pragma mark - 几何，构建点、尺寸、向量、矩形框，获取矩形框的中心点
#define INBPoint(__X__, __Y__)              CGPointMake(__X__, __Y__)
#define INBSize(__W__, __H__)               CGSizeMake(__W__, __H__)
#define INBVector(__DX__, __DY__)           CGVectorMake(__DX__, __DY__)
#define INBRect(__X__, __Y__, __W__, __H__) CGRectMake(__X__, __Y__, __W__, __H__)
#define INBCenterPointOfRect(__RECT__)      CGPointMake(CGRectGetMidX(__RECT__), CGRectGetMidY(__RECT__))

#pragma mark - 屏幕尺寸，iOS 8及之后的与iOS 8之前的不一样(屏幕旋转)
#define INBScreenBounds (INBUIScreen.bounds)
#define INBScreenSize   (INBScreenBounds.size)
#define INBScreenWidth  (INBScreenSize.width)
#define INBScreenHeight (INBScreenSize.height)

#pragma mark - UUID
#define INBUUIDString   (INBUIDevice.identifierForVendor.UUIDString)

#pragma mark - 状态栏的矩形框，iOS 8及之后的与iOS 8之前的不一样(屏幕旋转)
#define INBStatusBarFrame  (INBUIApplication.statusBarFrame)
#define INBStatusBarSize   (INBStatusBarFrame.size)
#define INBStatusBarWidth  (INBStatusBarSize.width)
#define INBStatusBarHeight (INBStatusBarSize.height)

#pragma mark - 判断屏幕是否为视网膜屏幕， 参见`UIScreen+INB.h`
#define INBIsRetinaScreen            [UIScreen isRetinaScreen]
#define INBIs3Dot5InchesRetinaScreen [UIScreen is3Dot5InchesRetinaScreen]
#define INBIs4InchesRetinaScreen     [UIScreen is4InchesRetinaScreen]
#define INBIs4Dot7InchesRetinaScreen [UIScreen is4Dot7InchesRetinaScreen]
#define INBIs5Dot5InchesRetinaScreen [UIScreen is5Dot5InchesRetinaScreen]

#pragma mark - UIImage
#define INBImage(__IMAGE_NAME__)     [UIImage imageNamed:(__IMAGE_NAME__)]
// 尺寸可变图片， 参见`UIImage+INB.h`
#define INBResizableImage(__IMAGE__) ([(__IMAGE__) respondsToSelector:@selector(resizableImage)] ? [(UIImage *)(__IMAGE__) resizableImage] : nil)
#define INBTransparentImage INBResizableImage([UIImage imageWithColor:[UIColor colorWithWhite:0 alpha:0.3]])

#pragma mark - Navigation Controller
#define INBNavigationController(__ROOT_VC__) [[UINavigationController alloc] initWithRootViewController:__ROOT_VC__]

#pragma mark - Storyboard
#define INBStoryboard(__NAME__)                            ([(__NAME__) isKindOfClass:[NSString class]] ? [UIStoryboard storyboardWithName:(__NAME__) bundle:nil] : nil)
#define INBStoryboardVC(__STORYBOARD__, __VC_CLASS_NAME__) ((__VC_CLASS_NAME__ *)[__STORYBOARD__ instantiateViewControllerWithIdentifier:INBStringFromClass(__VC_CLASS_NAME__)])

#pragma mark - Nib
#define INBNib(__CLASS_NAME__)              [UINib nibWithNibName:INBStringFromClass(__CLASS_NAME__) bundle:nil]
#define INBViewFromNib(__VIEW_CLASS_NAME__) ((__VIEW_CLASS_NAME__ *)[[NSBundle mainBundle] loadNibNamed:INBStringFromClass(__VIEW_CLASS_NAME__) owner:nil options:nil].firstObject)
#define INBVCFromNib(__VC_CLASS_NAME__)     ((__VC_CLASS_NAME__ *)[[__VC_CLASS_NAME__ alloc] initWithNibName:INBStringFromClass(__VC_CLASS_NAME__) bundle:nil])

#pragma mark - Font
#define INBSystemFont(__FONT_SIZE__)       [UIFont systemFontOfSize:(__FONT_SIZE__)]
#define INBBoldSystemFont(__FONT_SIZE__)   [UIFont boldSystemFontOfSize:(__FONT_SIZE__)]
#define INBItalicSystemFont(__FONT_SIZE__) [UIFont italicSystemFontOfSize:(__FONT_SIZE__)]

#pragma mark - 隐藏键盘
#define INBDismissKeyboard [INBUIApplication sendAction:@selector(resignFirstResponder) to:nil from:nil forEvent:nil]

#pragma mark - Index Path
#define INBIndexPathForSectionRow(__SECTION__, __ROW__) [NSIndexPath indexPathForRow:__ROW__ inSection:__SECTION__]
#define INBIndexPathForSectionItem(__SECTION__, __ITEM__) [NSIndexPath indexPathForItem:__ITEM__ inSection:__SECTION__]

#pragma mark - table view register [ReuseIdentifier对应类名]
#define INBTableViewRegisterCellClass(__TABLE__, __CELL_CLASS_NAME__) [__TABLE__ registerClass:[__CELL_CLASS_NAME__ class] forCellReuseIdentifier:INBStringFromClass(__CELL_CLASS_NAME__)]
#define INBTableViewRegisterCellNib(__TABLE__, __CELL_CLASS_NAME__)   [__TABLE__ registerNib:INBNib(__CELL_CLASS_NAME__) forCellReuseIdentifier:INBStringFromClass(__CELL_CLASS_NAME__)]
#define INBTableViewRegisterHeaderFooterClass(__TABLE__, __VIEW_CLASS_NAME__) [__TABLE__ registerClass:[__VIEW_CLASS_NAME__ class] forHeaderFooterViewReuseIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__)]
#define INBTableViewRegisterHeaderFooterNib(__TABLE__, __VIEW_CLASS_NAME__) [__TABLE__ registerNib:INBNib(__VIEW_CLASS_NAME__) forHeaderFooterViewReuseIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__)]

#pragma mark - table view dequeue [ReuseIdentifier对应类名]
#define INBTableViewDequeueCellClass(__TABLE__, __CELL_CLASS_NAME__, __INDEX_PATH__) ((__CELL_CLASS_NAME__ *)[__TABLE__ dequeueReusableCellWithIdentifier:INBStringFromClass(__CELL_CLASS_NAME__) forIndexPath:__INDEX_PATH__])
#define INBTableViewDequeueHeaderFooterClass(__TABLE__, __VIEW_CLASS_NAME__) ((__VIEW_CLASS_NAME__ *)[__TABLE__ dequeueReusableHeaderFooterViewWithIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__)])

#pragma mark - collection view register [ReuseIdentifier对应类名]
#define INBCollectionViewRegisterCellClass(__COLLECTION_VIEW_, __CELL_CLASS_NAME__) [__COLLECTION_VIEW_ registerClass:[__CELL_CLASS_NAME__ class] forCellWithReuseIdentifier:INBStringFromClass(__CELL_CLASS_NAME__)]
#define INBCollectionViewRegisterCellNib(__COLLECTION_VIEW_, __CELL_CLASS_NAME__) [__COLLECTION_VIEW_ registerNib:INBNib(__CELL_CLASS_NAME__) forCellWithReuseIdentifier:INBStringFromClass(__CELL_CLASS_NAME__)]
#define INBCollectionViewRegisterSupplementaryClass(__COLLECTION_VIEW_, __VIEW_CLASS_NAME__, __KIND_NAME__) [__COLLECTION_VIEW_ registerClass:[__VIEW_CLASS_NAME__ class] forSupplementaryViewOfKind:__KIND_NAME__ withReuseIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__)]
#define INBCollectionViewRegisterSupplementaryNib(__COLLECTION_VIEW_, __VIEW_CLASS_NAME__, __KIND_NAME__) [__COLLECTION_VIEW_ registerNib:INBNib(__VIEW_CLASS_NAME__) forSupplementaryViewOfKind:__KIND_NAME__ withReuseIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__)]

#pragma mark - collection view dequeue [ReuseIdentifier对应类名]
#define INBCollectionViewDequeueCellClass(__COLLECTION_VIEW_, __CELL_CLASS_NAME__, __INDEX_PATH__) ((__CELL_CLASS_NAME__ *)[__COLLECTION_VIEW_ dequeueReusableCellWithReuseIdentifier:INBStringFromClass(__CELL_CLASS_NAME__) forIndexPath:__INDEX_PATH__])
#define INBCollectionViewDequeueSupplementaryClass(__COLLECTION_VIEW_, __VIEW_CLASS_NAME__, __KIND_NAME__, __INDEX_PATH__) ((__VIEW_CLASS_NAME__ *)[__COLLECTION_VIEW_ dequeueReusableSupplementaryViewOfKind:__KIND_NAME__ withReuseIdentifier:INBStringFromClass(__VIEW_CLASS_NAME__) forIndexPath:__INDEX_PATH__])

#endif
