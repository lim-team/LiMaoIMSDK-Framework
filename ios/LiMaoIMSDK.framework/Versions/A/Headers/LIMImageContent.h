//
//  LIMImageMessageContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/13.
// 图片消息content

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "LIMMediaMessageContent.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMImageContent : LIMMediaMessageContent


@property(nonatomic,assign) CGFloat width;

@property(nonatomic,assign) CGFloat height;

/*!
 初始化图片消息
 
 @param image   原始图片
 @return        图片消息对象
 */
+ (instancetype)initWithImage:(UIImage *)image;


/*!
 是否发送原图
 
 @discussion 在发送图片的时候，是否发送原图，默认值为NO。
 */
@property (nonatomic, getter=isFull) BOOL full;

/*!
 图片消息的缩略图
 */
@property (nonatomic, strong) UIImage *thumbnailImage;

/*!
 图片消息的原始图片信息
 */
@property (nonatomic, strong,readonly) UIImage *originalImage;

/*!
 图片消息的原始图片信息
 */
@property (nonatomic, strong, readonly) NSData *originalImageData;

@end

NS_ASSUME_NONNULL_END
