//
//  LIMVoiceContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/16.
//

#import <Foundation/Foundation.h>
#import "LIMMediaMessageContent.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMVoiceContent : LIMMediaMessageContent


/**
 初始化

 @param voiceData 音频数据
 @param second 音频秒长
 @return <#return value description#>
 */
+ (instancetype)initWithData:(NSData *)voiceData second:(int)second;


// 音频数据
@property(nonatomic,strong) NSData *voiceData;

// 音频长度（单位秒）
@property(nonatomic,assign) NSInteger second;

@end

NS_ASSUME_NONNULL_END
