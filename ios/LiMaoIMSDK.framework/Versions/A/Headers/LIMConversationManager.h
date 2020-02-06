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
NS_ASSUME_NONNULL_BEGIN

@protocol LIMConversationManagerDelegate <NSObject>

@optional


/**
 最近会话被添加

 @param conversation 最近会话对象
 */
- (void)onConversationAdd:(LIMConversation*)conversation;


/**
 最近会话被更新

 @param conversation 最近会话对象
 */
- (void)onConversationUpdate:(LIMConversation*)conversation;

/**
 最近会话未读数更新
 
 @param channel 频道
 @param unreadCount 未读数量
 */
- (void)onConversationUnreadCountUpdate:(LIMChannel*)channel unreadCount:(NSInteger)unreadCount;

@end

@interface LIMConversationManager : NSObject

/**
 添加或更新最近会话

 @param conversation conversation
 @param incUnreadCount 未读数递增数量
 */
-(LIMConversationAddOrUpdateResult*) addOrUpdateConversation:(LIMConversation*)conversation incUnreadCount:(NSInteger)incUnreadCount;

/**
 追加提醒
 
 @param reminder 提醒项
 @param channel 频道
 @return 追加后的最近会话
 */
-(LIMConversation*)  appendReminder:(LIMReminder*) reminder channel:(LIMChannel*)channel;


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

/**
 获取最近会话列表
 
 @return 最好会话对象集合
 */
-(NSArray<LIMConversation*>*) getConversationList;


/**
 调用最近会话添加委托

 @param conversation <#conversation description#>
 */
- (void)callOnConversationAddDelegate:(LIMConversation*)conversation;


/**
 调用最近会话更新委托

 @param conversation <#conversation description#>
 */
- (void)callOnConversationUpdateDelegate:(LIMConversation*)conversation;

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


@end



NS_ASSUME_NONNULL_END
