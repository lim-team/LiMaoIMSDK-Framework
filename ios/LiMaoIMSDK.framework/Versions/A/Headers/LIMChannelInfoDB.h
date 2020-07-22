//
//  LIMChannelInfoDB.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import "LIMChannelInfo.h"
#import "LIMChannelInfoSearchResult.h"
#import "LIMChannelMessageSearchResult.h"
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


/// 删除频道信息
/// @param channel <#channel description#>
-(void) deleteChannelInfo:(LIMChannel*)channel;

/**
 获取频道信息

 @param channel 频道
 @return <#return value description#>
 */
-(LIMChannelInfo*) queryChannelInfo:(LIMChannel*)channel;


/// 通过状态查询频道信息
/// @param status 0.正常 2.黑明单
-(NSArray<LIMChannelInfo*>*) queryChannelInfosWithStatus:(NSInteger)status;


/// 获取跟我好友关系的频道数据
/// @param keyword 关键字
/// @param limit 数量限制
-(NSArray<LIMChannelInfo*>*) queryChannelInfoWithFriend:(NSString*)keyword limit:(NSInteger)limit;


/// 搜索频道信息
/// @param keyword 频道关键字
/// @param channelType 频道类型
/// @param limit 数量限制
-(NSArray<LIMChannelInfoSearchResult*>*) searchChannelInfoWithKeyword:(NSString*)keyword channelType:(uint8_t)channelType limit:(NSInteger)limit;


/// 搜索频道内的消息
/// @param keyword 搜索关键字
/// @param limit 数量限制
-(NSArray<LIMChannelMessageSearchResult*>*) searchChannelMessageWithKeyword:(NSString*)keyword  limit:(NSInteger)limit;

/// 查询频道
/// @param keyword 关键字
/// @param channelType 频道类型
/// @param limit 数量限制
-(NSArray<LIMChannelInfo*>*) queryChannelInfoWithType:(NSString*)keyword channelType:(uint8_t)channelType limit:(NSInteger)limit;
@end

NS_ASSUME_NONNULL_END
