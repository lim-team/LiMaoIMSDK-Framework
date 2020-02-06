//
//  LIMMessageDB.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMMessage.h"
#import "LIMSendackPacket.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMMessageDB : NSObject

+ (LIMMessageDB *)shared;
/**
 保存消息

 @param messages 消息集合
 */
-(void) saveMessages:(NSArray<LIMMessage*>*)messages;


/**
 获取频道中，从指定消息之前、指定数量的最新消息实体

 @param channel 频道
 @param oldestClientSeq 截止的客户端编号
 @param limit 消息数量限制
 @return 消息实体集合
 
 例如：  oldestClientSeq为20，count为2，会返回clientSeq为19和18的LIMMessage对象列表。
 */
-(NSArray<LIMMessage*>*) getMessages:(LIMChannel*)channel oldestClientSeq:(uint32_t)oldestClientSeq limit:(int) limit;


/**
 通过序列号获取消息
 
 @param clientSeqs <#clientSeqs description#>
 @return <#return value description#>
 */
-(NSArray<LIMMessage*>*) getMessagesWithClientSeqs:(NSArray<NSNumber*>*)clientSeqs;
/**
 获取指定clientSeq的消息

 @param clientSeq 客户端序号
 @return <#return value description#>
 */
-(LIMMessage*) getMessage:(uint32_t)clientSeq;


/**
 通过消息ID获取消息

 @param messageId <#messageId description#>
 @return <#return value description#>
 */
-(LIMMessage*) getMessageWithMessageId:(uint64_t)messageId;

/**
 更新消息通过发送回执消息
 
 @param sendackPackets <#sendackPackets description#>
 */
-(void) updateMessageWithSendackPackets:(NSArray<LIMSendackPacket*> *)sendackPackets;


/**
 更新消息

 @param content 消息content内容
 @param status 消息状态
 @param extra 消息扩展数据
 @param clientSeq 消息客户端唯一编号
 */
-(void) updateMessageContent:(NSData*)content status:(LIMMessageStatus)status extra:(NSDictionary*)extra clientSeq:(uint32_t)clientSeq;


/**
 更新语音消息已读状态

 @param voiceReaded 语音是否已读
 @param clientSeq 客户端唯一ID
 */
-(void) updateMessageVoiceReaded:(BOOL)voiceReaded clientSeq:(uint32_t)clientSeq;


/**
 更新消息已读状态

 @param readed 是否已读
 @param clientSeq 客户端唯一ID
 */
-(void) updateMessageReaded:(BOOL) readed clientSeq:(uint32_t)clientSeq;


/**
 更新消息扩展字段

 @param extra <#extra description#>
 @param clientSeq <#clientSeq description#>
 */
-(void) updateMessageExtra:(NSDictionary*) extra clientSeq:(uint32_t)clientSeq;
/**
 将等待发送的消息状态更改为发送失败的状态
 */
-(void) updateMessageWaitSendToFailStatus;


/**
 更新消息状态

 @param status 消息状态
 @param clientSeq 消息clientSeq
 */
-(void) updateMessageStatus:(LIMMessageStatus)status withClientSeq:(uint32_t)clientSeq;


/**
 获取消息表中最大的message_seq

 @return <#return value description#>
 */
-(uint32_t) getMaxMessageSeq;

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
 获取最后一条消息

 @param channel <#channel description#>
 @return <#return value description#>
 */
-(LIMMessage*) getLastMessage:(LIMChannel*)channel;


@end

NS_ASSUME_NONNULL_END
