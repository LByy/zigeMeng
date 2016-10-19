//
//  NSData+INB.h
//  INBKit
//
//  Created by Daniate on 15/3/12.
//  Copyright (c) 2015年 Daniate. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>
/**
 *  Base-64
 */
@interface NSData (INBBase64)
/**
 *  对自身进行Base-64编码
 *
 *  @return Base-64编码字符串（每隔64个字符，就加入回车符'\r'与换行符'\n'，但结尾处不会加入，URL Unsafe）
 */
- (NSString *)base64EncodedString;
/**
 *  对自身进行Base-64编码
 *
 *  @return Base-64编码数据（每隔64个字符，就加入回车符'\r'与换行符'\n'，但结尾处不会加入，URL Unsafe）
 */
- (NSData *)base64EncodedData;
/**
 *  对Base-64字符串进行解码
 *
 *  @param base64String Base-64字符串
 *
 *  @return 解码后的数据
 */
+ (NSData *)base64DecodedDataWithString:(NSString *)base64String;
/**
 *  对Base-64数据进行解码
 *
 *  @param base64Data Base-64数据
 *
 *  @return 解码后的数据
 */
+ (NSData *)base64DecodedDataWithData:(NSData *)base64Data;
/**
 *  对自身（Base-64数据）进行Base-64解码
 *
 *  @return 解码后的数据
 */
- (NSData *)base64DecodedData;
@end

/**
 *  消息摘要与安全哈希。返回的数据未经任何处理（如，Base-64、hex）。
 */
@interface NSData (INBMessageDigest)
/**
 *  Message Digest 2
 *
 *  @return md2
 */
- (NSData *)MD2;
/**
 *  Message Digest 4
 *
 *  @return md4
 */
- (NSData *)MD4;
/**
 *  Message Digest 5
 *
 *  @return md5
 */
- (NSData *)MD5;
/**
 *  Secure Hash Algorithm 1
 *
 *  @return sha1
 */
- (NSData *)SHA1;
/**
 *  Secure Hash Algorithm 224
 *
 *  @return sha224
 */
- (NSData *)SHA224;
/**
 *  Secure Hash Algorithm 256
 *
 *  @return sha256
 */
- (NSData *)SHA256;
/**
 *  Secure Hash Algorithm 384
 *
 *  @return sha384
 */
- (NSData *)SHA384;
/**
 *  Secure Hash Algorithm 512
 *
 *  @return sha512
 */
- (NSData *)SHA512;
@end
/**
 *  对数据进行十六进制编解码，使用小写字母
 */
@interface NSData (INBHex)
/**
 *  判断自身是否为十六进制编码数据
 *
 *  @return 是：YES/否：NO
 */
- (BOOL)isHexData;
/**
 *  将原始数据中的每个字节，转换为两个十六进制字符，并将它们放入到指定的缓冲区中，最后通过缓冲区构建NSData。
 *
 *  @return NSData（bytes中的每个字符都是十六进制字符）
 */
- (NSData *)encodeToHexData;
/**
 *  对调用`- (NSData *)encodeToHexData`得到的数据进行还原
 *
 *  @return 还原后的NSData
 */
- (NSData *)decodeFromHexData;
/**
 *  获取NSData对应的十六进制字符串。例如：[[data MD5] encodeHexString]
 *
 *  @return 十六进制字符串
 */
- (NSString *)encodeToHexString;
/**
 *  将字符串转换为十六进制编码数据
 *
 *  @param string 字符串
 *
 *  @return 转换后的NSData
 */
+ (NSData *)encodeToHexData:(NSString *)string;
/**
 *  对调用`- (NSString *)encodeToHexString`得到的结果进行还原
 *
 *  @param hexString 十六进制字符串
 *
 *  @return 还原后的NSData
 */
+ (NSData *)decodeFromHexString:(NSString *)hexString;
@end
/**
 *  密码学安全伪随机数生成器
 */
@interface NSData (INBCryptoPRNG)
/**
 *  生成安全随机数据，可用于生成密钥、初始化向量等等。
 *
 *  @param length 长度
 *
 *  @return 安全随机数据
 */
+ (NSData *)generateSecureRandomData:(size_t)length;
@end
/**
 *  哈希消息验证码
 */
@interface NSData (INBHmac)
/**
 *  为指定的Hmac算法生成密钥
 *
 *  @param algorithm Hmac算法
 *
 *  @return 密钥
 */
+ (NSData *)generateHmacKeyForAlgorithm:(CCHmacAlgorithm)algorithm;
/**
 *  哈希消息验证码
 *
 *  @param algorithm Hmac算法
 *  @param key       密钥（NSData / NSString）
 *
 *  @return 哈希消息验证码。返回的数据未经任何处理（如，base64、hex）。
 */
- (NSData *)HmacWithAlgorithm:(CCHmacAlgorithm)algorithm key:(id)key;
@end
/**
 *  对称密钥生成器
 */
@interface NSData (INBSymmetricKeyGenerator)
/**
 *  为指定的加密算法生成对称密钥。使用的密钥长度如下：<br/>
 *  kCCAlgorithmAES      -> kCCKeySizeAES256<br/>
 *  kCCAlgorithmDES      -> kCCKeySizeDES<br/>
 *  kCCAlgorithm3DES     -> kCCKeySize3DES<br/>
 *  kCCAlgorithmCAST     -> kCCKeySizeMaxCAST<br/>
 *  kCCAlgorithmRC4      -> kCCKeySizeMaxRC4<br/>
 *  kCCAlgorithmRC2      -> kCCKeySizeMaxRC2<br/>
 *  kCCAlgorithmBlowfish -> kCCKeySizeMaxBlowfish<br/>
 *
 *  @param algorithm 加密算法
 *
 *  @return 密钥
 */
+ (NSData *)generateSymmetricKeyForAlgorithm:(CCAlgorithm)algorithm;
/**
 *  为指定的加密算法生成对称密钥。<br/>
 *  如果指定的密钥大小不正确，会自动进行处理：<br/>
 *  kCCAlgorithmAES      -> keySize <= kCCKeySizeAES128, use kCCKeySizeAES128<br/>
 *                       -> keySize > kCCKeySizeAES128 and keySize <= kCCKeySizeAES192, use kCCKeySizeAES192<br/>
 *                       -> keySize > kCCKeySizeAES192, use kCCKeySizeAES256<br/>
 *  kCCAlgorithmDES      -> kCCKeySizeDES<br/>
 *  kCCAlgorithm3DES     -> kCCKeySize3DES<br/>
 *  kCCAlgorithmCAST     -> [kCCKeySizeMinCAST, kCCKeySizeMaxCAST]<br/>
 *  kCCAlgorithmRC4      -> [kCCKeySizeMinRC4, kCCKeySizeMaxRC4]<br/>
 *  kCCAlgorithmRC2      -> [kCCKeySizeMinRC2, kCCKeySizeMaxRC2]<br/>
 *  kCCAlgorithmBlowfish -> [kCCKeySizeMinBlowfish, kCCKeySizeMaxBlowfish]<br/>
 *
 *  @param algorithm 加密算法
 *  @param keySize   密钥长度（单位：字节）
 *
 *  @return 密钥
 */
+ (NSData *)generateSymmetricKeyForAlgorithm:(CCAlgorithm)algorithm
									 keySize:(unsigned int)keySize;
@end
/**
 *  初始化向量生成器
 */
@interface NSData (INBIVGenerator)
/**
 *  为指定的加密算法生成初始化向量，初始化向量的大小与算法分组的大小相同。
 *
 *  @param algorithm 加密算法，不能是流加密算法
 *
 *  @return 初始化向量
 */
+ (NSData *)generateIVForAlgorithm:(CCAlgorithm)algorithm;
@end
/**
 *  分组对称加解密（不是流加解密）
 */
@interface NSData (INBSymmetricEncryptionDecryption)
/**
 *  使用分组对称加密算法对数据进行加解密，使用CBC。
 *
 *  @param algorithm      算法，不能是流加密算法
 *  @param key            密钥
 *  @param iv             初始化向量，可以为空。
 *  @param operation      加密/解密操作
 *  @param isPKCS7Padding 是否使用PKCS7Padding填充模式
 *
 *  @return 加密/解密后的数据
 */
- (NSData *)doBlockCipherWithAlgorithm:(CCAlgorithm)algorithm
								   key:(NSData *)key
									iv:(NSData *)iv
							 operation:(CCOperation)operation
						isPKCS7Padding:(BOOL)isPKCS7Padding;
/**
 *  使用分组对称加密算法对数据进行加解密。
 *
 *  @param algorithm      算法，不能是流加密算法
 *  @param key            密钥
 *  @param iv             初始化向量，可以为空。
 *  @param operation      加密/解密操作
 *  @param isPKCS7Padding 是否使用PKCS7Padding填充模式
 *  @param isECB          是否使用ECB模式，如不使用，则是使用CBC模式
 *
 *  @return 加密/解密后的数据
 */
- (NSData *)doBlockCipherWithAlgorithm:(CCAlgorithm)algorithm
								   key:(NSData *)key
									iv:(NSData *)iv
							 operation:(CCOperation)operation
						isPKCS7Padding:(BOOL)isPKCS7Padding
								 isECB:(BOOL)isECB;
@end
/**
 *  读写文件
 */
@interface NSData (INBReadWrite)
- (BOOL)writeToFileUnderDirectory:(NSString *)directory
			   withPathComponents:(NSString *)pathComponents;
- (BOOL)writeToFileUnderDirectory:(NSString *)directory
			   withPathComponents:(NSString *)pathComponents
		 allowWhitespaceComponent:(BOOL)allow trimComponent:(BOOL)trim;

- (BOOL)writeToFileUnderDocuments:(NSString *)pathComponents;
- (BOOL)writeToFileUnderDocuments:(NSString *)pathComponents
		 allowWhitespaceComponent:(BOOL)allow
					trimComponent:(BOOL)trim;

- (BOOL)writeToFileUnderLibrary:(NSString *)pathComponents;
- (BOOL)writeToFileUnderLibrary:(NSString *)pathComponents
	   allowWhitespaceComponent:(BOOL)allow
				  trimComponent:(BOOL)trim;

+ (NSData *)dataWithContentsOfFileUnderDirectory:(NSString *)directory
							  withPathComponents:(NSString *)pathComponents;
+ (NSData *)dataWithContentsOfFileUnderDirectory:(NSString *)directory
							  withPathComponents:(NSString *)pathComponents
						allowWhitespaceComponent:(BOOL)allow trimComponent:(BOOL)trim;

+ (NSData *)dataWithContentsOfFileUnderDocuments:(NSString *)pathComponents;
+ (NSData *)dataWithContentsOfFileUnderDocuments:(NSString *)pathComponents
						allowWhitespaceComponent:(BOOL)allow
								   trimComponent:(BOOL)trim;

+ (NSData *)dataWithContentsOfFileUnderLibrary:(NSString *)pathComponents;
+ (NSData *)dataWithContentsOfFileUnderLibrary:(NSString *)pathComponents
					  allowWhitespaceComponent:(BOOL)allow
								 trimComponent:(BOOL)trim;
@end
