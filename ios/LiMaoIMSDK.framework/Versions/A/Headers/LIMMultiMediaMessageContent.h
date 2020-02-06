//
//  LIMMultiMediaMessageContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/13.
//

#import <Foundation/Foundation.h>
#import "LIMMessageContent.h"
#import "LIMMediaProto.h"

NS_ASSUME_NONNULL_BEGIN

/**
 如果一个消息有多个多媒体文件 使用此MessageContent
 */
@interface LIMMultiMediaMessageContent : LIMMessageContent


/**
 多个多媒体文件
 */
@property NSArray<id<LIMMediaProto>> *medias;

@end

NS_ASSUME_NONNULL_END
