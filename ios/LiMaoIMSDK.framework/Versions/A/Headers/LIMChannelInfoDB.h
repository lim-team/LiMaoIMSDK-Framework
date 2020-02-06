//
//  LIMChannelInfoDB.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import "LIMChannelInfo.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMChannelInfoDB : NSObject
+ (LIMChannelInfoDB *)shared;

/**
 保存频道信息

 @param channelInfo 频道信息
 @return <#return value description#>
 */
-(BOOL) saveChannelInfo:(LIMChannelInfo*)channelInfo;


/**
 批量修改或添加频道信息

 @param channelInfos <#channelInfos description#>
 */
-(void) addOrUpdateChannelInfos:(NSArray<LIMChannelInfo*>*)channelInfos;

/**
 更新频道信息

 @param channelInfo <#channelInfo description#>
 */
-(void) updateChannelInfo:(LIMChannelInfo*)channelInfo;
/**
 获取频道信息

 @param channel 频道
 @return <#return value description#>
 */
-(LIMChannelInfo*) queryChannelInfo:(LIMChannel*)channel;
@end

NS_ASSUME_NONNULL_END
