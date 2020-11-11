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
#import "LIMSyncChannelMessageModel.h"
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


/// 清除所有消息
-(void) onMessageAllCleared;



@end

// 同步频道消息
typedef void(^LIMSyncChannelMessageCallback)(LIMSyncChannelMessageModel* __nullable syncChannelMessageModel,NSError * __nullable error);
typedef void (^LIMSyncChannelMessageProvider)(LIMChannel *channel,uint32_t minMessageSeq,uint32_t maxMessageSeq,NSInteger limit,bool reverse,LIMSyncChannelMessageCallback callback);

@interface LIMChatManager : NSObject


/// 同步频道消息提供者（由第三方设置）
@property(nonatomic,copy) LIMSyncChannelMessageProvider syncChannelMessageProvider;
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

-(LIMMessage*) saveMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel fromUid:(NSString* __nullable)fromUid  status:(LIMMessageStatus)status;


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


/// 清除所有消息
-(void) clearAllMessages;
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

// @param channel 频道
//@param oldestMessageSeq 截止的消息序列号
// @param limit 数量限制
// @return 消息实体结构
// */
//- (NSArray<LIMMessage*> *)getHistoryMessages:(LIMChannel*) channel oldestMessageSeq:(uint32_t)oldestMessageSeq  limit:(int)limit;
//
//- (NSArray<LIMMessage*> *)getHistoryMessages:(LIMChannel*) channel oldestMessageSeq:(uint32_t)oldestMessageSeq contain:(BOOL)contain  limit:(int)limit reverse:(BOOL)reverse;



/// 获取历史消息或同步历史消息（如果本地没有则同步）
-(void) getOrSyncHistoryMessages:(LIMChannel*) channel oldestOrderSeq:(uint32_t)oldestOrderSeq contain:(BOOL)contain  limit:(int)limit reverse:(BOOL)reverse  complete:(void(^)(NSArray<LIMMessage*> *messages,NSError *error))complete;
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


/// 撤回消息
/// @param message <#message description#>
-(void) revokeMessage:(LIMMessage*)message;



/// 获取orderSeq
/// @param messageSeq <#messageSeq description#>
-(uint32_t) getOrderSeq:(uint32_t)messageSeq;


/// 正文包装为消息
/// @param content 消息正文
/// @param channel 频道
/// @param fromUid 发送者UID
-(LIMMessage*) contentToMessage:(LIMMessageContent*)content channel:(LIMChannel*)channel fromUid:(NSString*)fromUid;



/// 通过正文类型获取content
/// @param contentType 正文类型
-(LIMMessageContent*) getMessageContent:(NSInteger)contentType;

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


/// 调用收到消息的委托
/// @param messages <#messages description#>
- (void)callRecvMessagesDelegate:(NSArray<LIMMessage*>*)messages;

@end




NS_ASSUME_NONNULL_END
