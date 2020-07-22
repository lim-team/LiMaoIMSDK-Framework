//
//  LIMChannelManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
#import "LIMChannelInfo.h"
#import "LIMChannelMemberDB.h"
NS_ASSUME_NONNULL_BEGIN


@protocol LIMChannelManagerDelegate <NSObject>

@optional


/**
 频道信息更新

 @param channelInfo <#channelInfo description#>
 */
-(void) channelInfoUpdate:(LIMChannelInfo*)channelInfo;


/// 频道数据移除
/// @param channel <#channel description#>
-(void) channelInfoDelete:(LIMChannel*)channel;

@end


typedef void  (^LIMChannelInfoBlock)(LIMChannelInfo*);

@interface LIMChannelManager : NSObject

+ (LIMChannelManager *)shared;

/**
 获取频道信息

 @param channel 频道
 @param channelInfoBlock 获取到频道信息回调
 */
-(void) fetchChannelInfo:(LIMChannel*) channel  completion:(_Nullable LIMChannelInfoBlock)channelInfoBlock;

-(void) fetchChannelInfo:(LIMChannel*) channel;


/**
 获取频道信息

 @param channel 频道
 @return <#return value description#>
 */
-(LIMChannelInfo*) getChannelInfo:(LIMChannel*)channel;


/**
删除频道信息
 */
-(void) deleteChannelInfo:(LIMChannel*) channelInfo;


/**
 添加或更新频道，如果需要更新的话（只与version大于当前库里的version才更新）

 @param channelInfo <#channelInfo description#>
 */
-(void) addOrUpdateChannelInfoIfNeed:(LIMChannelInfo*) channelInfo;


/**
 添加或更新（不比较版本）

 @param channelInfo <#channelInfo description#>
 */
-(void) addOrUpdateChannelInfo:(LIMChannelInfo*) channelInfo;


/// 更新频道信息
/// @param channelInfo <#channelInfo description#>
-(void) updateChannelInfo:(LIMChannelInfo*) channelInfo;


/// 添加频道信息
/// @param channelInfo <#channelInfo description#>
-(void) addChannelInfo:(LIMChannelInfo*) channelInfo;
/**
 更新频道设置

 @param channel 频道
 @param setting 频道设置字典 比例设置免打扰 则传 @{@"mute":@(true)} 设置多个 @{@"mute":@(true),@"stick":@(true)}
 */
-(void) updateChannelSetting:(LIMChannel*)channel setting:(NSDictionary*)setting;


/**
 批量添加或更新频道信息 (不通知上层)

 @param channelInfos <#channelInfos description#>
 */
-(void) addOrUpdateChannelInfos:(NSArray<LIMChannelInfo*>*) channelInfos;


/**
 添加或更新频道成员

 @param members 频道成员集合
 */
-(void) addOrUpdateMembers:(NSArray<LIMChannelMember*>*)members;


/**
 获取频道成员集合

 @param channel 频道对象
 @return <#return value description#>
 */
-(NSArray<LIMChannelMember*>*) getMembersWithChannel:(LIMChannel*)channel;


/**
 获取频道指定成员

 @param channel 频道
 @param uid 成员UID
 */
-(LIMChannelMember*) getMember:(LIMChannel*)channel uid:(NSString*)uid;


/**
 获取频道的成员最新同步key
 
 @param channel 频道信息
 @return <#return value description#>
 */
-(NSString*) getMemberLastSyncKey:(LIMChannel*)channel;

/**
 设置频道缓存

 @param channelInfo <#channelInfo description#>
 */
-(void) setCache:(LIMChannelInfo*) channelInfo;


/**
 获取缓存内的频道信息

 @return <#return value description#>
 */
-(LIMChannelInfo*) getCache:(LIMChannel*)channel;

/**
 添加连接委托
 
 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMChannelManagerDelegate>) delegate;


/**
 移除连接委托
 
 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMChannelManagerDelegate>) delegate;

@end

NS_ASSUME_NONNULL_END
