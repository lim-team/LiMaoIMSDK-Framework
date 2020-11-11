//
//  LIMConversationManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMMessage.h"
#import "LIMConversation.h"
#import "LIMConversationDB.h"
#import "LIMSyncConversationModel.h"
NS_ASSUME_NONNULL_BEGIN

typedef void(^LIMSyncConversationCallback)(LIMSyncConversationWrapModel* __nullable model,NSError * __nullable error);

typedef void(^LIMSyncConversationAck)(uint64_t cmdVersion,void(^ _Nullable complete)(NSError * _Nullable error));

// 同步会话返回 timestamp：最新会话的时间戳 lastMsgSeqs：客户端所有会话的最后一条消息序列号 格式： channelID:channelType:last_msg_seq|channelID:channelType:last_msg_seq
typedef void (^LIMSyncConversationProvider)(long long version,NSString *lastMsgSeqs,LIMSyncConversationCallback callback);



@protocol LIMConversationManagerDelegate <NSObject>

@optional

/**
  最近会话被添加

 @param conversation <#conversation description#>
 @param left 会话剩余数量 UI层可以判断left == 0 的时候才刷新 避免频繁刷新UI导致卡顿
 */
- (void)onConversationAdd:(LIMConversation*)conversation left:(NSInteger)left;


/**
 最近会话被更新

 @param conversation 最近会话对象
 @param left 会话剩余数量 UI层可以判断left == 0 的时候才刷新 避免频繁刷新UI导致卡顿
 */
- (void)onConversationUpdate:(LIMConversation*)conversation left:(NSInteger)left;

/**
 最近会话未读数更新
 
 @param channel 频道
 @param unreadCount 未读数量
 */
- (void)onConversationUnreadCountUpdate:(LIMChannel*)channel unreadCount:(NSInteger)unreadCount;


/// 最近会话被删除
/// @param channel <#channel description#>
-(void) onConversationDelete:(LIMChannel*)channel;


/// 所有最近会话删除
-(void) onConversationAllDelete;

@end

@interface LIMConversationManager : NSObject


/// 同步最近会话
@property(nonatomic,copy,readonly) LIMSyncConversationProvider syncConversationProvider;
@property(nonatomic,copy,readonly) LIMSyncConversationAck syncConversationAck;


/// 设置同步会话提供者
/// @param syncConversationProvider <#syncConversationProvider description#>
/// @param syncConversationAck <#syncConversationAck description#>
-(void) setSyncConversationProviderAndAck:(LIMSyncConversationProvider) syncConversationProvider ack:(LIMSyncConversationAck)syncConversationAck;

/**
 添加或更新最近会话

 @param conversation conversation
 @param incUnreadCount 未读数递增数量
 */
-(LIMConversationAddOrUpdateResult*) addOrUpdateConversation:(LIMConversation*)conversation incUnreadCount:(NSInteger)incUnreadCount;

-(LIMConversationAddOrUpdateResult*) addOrUpdateConversation:(LIMConversation*)cs;


/// 添加最近会话信息
/// @param conversation <#conversation description#>
-(void) addConversation:(LIMConversation*)conversation;


/// 恢复指定频道的会话
/// @param channel <#channel description#>
-(void) recoveryConversation:(LIMChannel*)channel;

/**
 追加提醒
 
 @param reminder 提醒项
 @param channel 频道
 @return 追加后的最近会话
 */
-(LIMConversation*)  appendReminder:(LIMReminder*) reminder channel:(LIMChannel*)channel;


/**
 移除某个类型的提醒

 @param type 提醒类型
 @param channel 所在频道
 */
-(void)  removeReminder:(LIMReminderType) type channel:(LIMChannel*)channel;

/**
 获取频道里指定类型的提醒

 @param type 提醒类型
 @param channel 频道
 @return <#return value description#>
 */
-(LIMReminder*) getReminder:(LIMReminderType)type channel:(LIMChannel*)channel;


/**
 清除指定频道的所有提醒

 @param channel 频道
 */
-(void) clearAllReminder:(LIMChannel*)channel;

/**
 清除指定频道的未读消息
 
 @param channel <#channel description#>
 */
-(void) clearConversationUnreadCount:(LIMChannel*)channel;


/// 设置未读数
/// @param channel 频道
/// @param unread 未读数量
-(void) setConversationUnreadCount:(LIMChannel*)channel unread:(NSInteger)unread;


/// 删除最近会话
/// @param channel 频道
-(void) deleteConversation:(LIMChannel*)channel;

/**
 获取最近会话列表
 
 @return 最好会话对象集合
 */
-(NSArray<LIMConversation*>*) getConversationList;


/// 获取指定频道的最近会话信息
/// @param channel <#channel description#>
-(LIMConversation*) getConversation:(LIMChannel*)channel;

/**
 调用最近会话添加委托

 @param conversation <#conversation description#>
 */
- (void)callOnConversationAddDelegate:(LIMConversation*)conversation;


/**
  调用最近会话添加委托

 @param conversation <#conversation description#>
 @param left 剩余数量 （方便UI层left==0的时候刷新）
 */
- (void)callOnConversationAddDelegate:(LIMConversation*)conversation left:(NSInteger)left;


/**
 调用最近会话更新委托

 @param conversation <#conversation description#>
 */
- (void)callOnConversationUpdateDelegate:(LIMConversation*)conversation;


/**
  调用最近会话更新委托

 @param conversation <#conversation description#>
 @param left left 剩余数量 （方便UI层left==0的时候刷新）
 */
- (void)callOnConversationUpdateDelegate:(LIMConversation*)conversation left:(NSInteger)left;


/// 调用删除所有最近会话委托
- (void)callOnConversationAllDeleteDelegate;

/**
 添加最近会话委托
 
 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMConversationManagerDelegate>) delegate;


/**
 移除最近会话委托
 
 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMConversationManagerDelegate>) delegate;

/**
 获取所有会话未读数量
 */
-(NSInteger) getAllConversationUnreadCount;


/// 处理同步下来的最近会话
/// @param model 会话同步对象
-(void) handleSyncConversation:(LIMSyncConversationWrapModel*)model;

@end



NS_ASSUME_NONNULL_END
