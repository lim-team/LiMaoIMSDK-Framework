//
//  LIMChatManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "LIMMessage.h"
#import "LIMMessageContent.h"
#import "LIMSendackPacket.h"
#import "LIMRecvPacket.h"
#import "LIMConversation.h"
#import "LIMMessageStatusModel.h"
NS_ASSUME_NONNULL_BEGIN

/**
 聊天管理委托
 */
@protocol LIMChatManagerDelegate <NSObject>



@optional


/**
 收到消息回调
 
 @param message 收到的消息
 @param left 消息剩余数量 ，可当left为0时再刷新UI
 */
- (void)onRecvMessages:(LIMMessage*)message left:(NSInteger)left;

/**
 消息更新
 
 @param message <#message description#>
 */
-(void) onMessageUpdate:(LIMMessage*) message;


/**
 消息被删除

 @param message 被删除的消息
 */
-(void) onMessageDeleted:(LIMMessage*) message;


/**
 指定频道的消息已清除

 @param channel <#channel description#>
 */
-(void) onMessageCleared:(LIMChannel*)channel;

/**
 消息状态发送改变

 @param messageStatusModel 消息状态model
 @param left 剩余数量 可当left为0时再刷新UI
 */
-(void) onMessageStatusChange:(LIMMessageStatusModel *)messageStatusModel left:(NSInteger)left;





@end

@interface LIMChatManager : NSObject


/**
 保存消息 (都为自己所发消息)

 @param content 消息正文
 @param channel 频道
 */
-(LIMMessage*) saveMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel;


/**
 保存消息（可自定发送者）

 @param content 消息正文
 @param channel 频道
 @param fromUid 发送者uid
 @return <#return value description#>
 */
-(LIMMessage*) saveMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel fromUid:( NSString* __nullable)fromUid;


/**
 发送消息 (发送并保存消息)

 @param content 消息正文
 @param channel 投递到那个频道
 */
-(LIMMessage*) sendMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel;


/**
 发送消息（仅仅发送，不保存）

 @param message 消息
 @return <#return value description#>
 */
-(LIMMessage*) sendMessage:(LIMMessage*)message;


/// 发送消息
/// @param message 消息对象
/// @param addRetryQueue 是否添加到重试队列，如果是true，消息发送失败将会进行指定次数的重试
-(LIMMessage*) sendMessage:(LIMMessage*)message addRetryQueue:(BOOL)addRetryQueue;


/**
 转发消息

 @param content 消息正文
 @param channel 频道
 @return <#return value description#>
 */
-(LIMMessage*) forwardMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel;

/**
 删除消息

 @param message 消息对象
 */
-(void) deleteMessage:(LIMMessage*)message;


/**
 清除指定频道的消息

 @param channel 频道
 */
-(void) clearMessages:(LIMChannel*)channel;
/**
 处理发送消息回执

 @param sendackArray <#sendackArray description#>
 */
-(void) handleSendack:(NSArray<LIMSendackPacket*> *)sendackArray;


/**
 处理收到消息

 @param packets <#packets description#>
 */
-(void) handleRecv:(NSArray<LIMRecvPacket*>*) packets;


/**
 处理消息 （流程： 保存消息-> 触发收到消息委托 -> 保存或更新最近会话 -> 触发最近会话委托）

 @param messages <#messages description#>
 */
-(void) handleMessages:(NSArray<LIMMessage*>*) messages;

/**
获取频道中，指定数量的消息

 @param channel 频道
@param oldestClientSeq 截止的客户端编号
 @param limit 数量限制
 @return 消息实体结构
 */
- (NSArray<LIMMessage*> *)getHistoryMessages:(LIMChannel*) channel oldestClientSeq:(uint32_t)oldestClientSeq  limit:(int)limit;


/**
 更新语音消息已读状态
 
 @param message 消息
 */
-(void) updateMessageVoiceReaded:(LIMMessage*)message;


/**
 更新消息已读状态
 
@param message 消息
 */
-(void) updateMessageReaded:(LIMMessage*)message;


/**
 更新扩展数据

 @param message 消息对象
 */
-(void) updateMessageExtra:(LIMMessage*)message;

/**
 添加连接委托
 
 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMChatManagerDelegate>) delegate;


/**
 移除连接委托
 
 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMChatManagerDelegate>) delegate;


// 调用消息状态改变委托
//- (void)callMessageStatusChangeDelegate:(NSArray<LIMMessageStatusModel*>*)statusModels;

// 调用消息更新委托
- (void)callMessageUpdateDelegate:(LIMMessage*)message;

@end




NS_ASSUME_NONNULL_END
