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
 @return 返回去重了的消息集合
 */
-(NSArray<LIMMessage*>*) saveMessages:(NSArray<LIMMessage*>*)messages;


/// 保存或更新消息
/// @param messages <#messages description#>
-(NSArray<LIMMessage*>*) replaceMessages:(NSArray<LIMMessage*>*)messages;


/**
 获取频道中，从指定消息之前、指定数量的最新消息实体

 @param channel 频道
 @param oldestOrderSeq 截止的客户端排序号
 @param limit 消息数量限制
 @return 消息实体集合
 
 例如：  oldestOrderSeq为20，count为2，会返回oldestOrderSeq为19和18的LIMMessage对象列表。
 */
-(NSArray<LIMMessage*>*) getMessages:(LIMChannel*)channel oldestOrderSeq:(uint32_t)oldestOrderSeq limit:(int) limit;


/// 获取频道中，从指定消息之前、指定数量的最新消息实体
/// @param channel 查询指定频道
/// @param oldestOrderSeq 客户端排序号
/// @param contain 查询结果是否包含当前oldestClientSeq的数据
/// @param limit 限制
/// @param reverse 倒序查询
-(NSArray<LIMMessage*>*) getMessages:(LIMChannel*)channel oldestOrderSeq:(uint32_t)oldestOrderSeq contain:(BOOL) contain limit:(int) limit reverse:(BOOL)reverse;


/// 获取消息列表
/// @param channel 频道对象
/// @param keyword 关键字
-(NSArray<LIMMessage*>*) getMessages:(LIMChannel*)channel keyword:(NSString*)keyword limit:(int) limit;


/// 获取消息序号区间内已经被删除的消息
/// @param channel 频道
/// @param minMessageSeq 最小消息序号
/// @param maxMessageSeq 最大消息序号
-(NSArray<LIMMessage*>*) getDeletedMessagesWithChannel:(LIMChannel*)channel minMessageSeq:(uint32_t)minMessageSeq maxMessageSeq:(uint32_t)maxMessageSeq;

/**
 通过序列号获取消息
 
 @param clientSeqs <#clientSeqs description#>
 @return <#return value description#>
 */
-(NSArray<LIMMessage*>*) getMessagesWithClientSeqs:(NSArray<NSNumber*>*)clientSeqs;


/// 通过客户端消息编号获取消息列表
/// @param clientMsgNos <#clientMsgNos description#>
-(NSArray<LIMMessage*>*) getMessagesWithClientMsgNos:(NSArray*)clientMsgNos;

/**
 通过客户端消息编号获取消息

 @param clientMsgNo 客户端消息编号
 @return <#return value description#>
 */
-(LIMMessage*) getMessageWithClientMsgNo:(NSString*)clientMsgNo;
/**
 获取指定clientSeq的消息

 @param clientSeq 客户端序号
 @return <#return value description#>
 */
-(LIMMessage*) getMessage:(uint32_t)clientSeq;


/// 通过消息序号查询消息
/// @param channel <#channel description#>
/// @param messageSeq <#messageSeq description#>
-(LIMMessage*) getMessage:(LIMChannel*)channel messageSeq:(uint32_t)messageSeq;



/// 通过排序号获取频道内指定消息
/// @param orderSeq <#orderSeq description#>
/// @param channel <#channel description#>
-(LIMMessage*) getMessage:(LIMChannel*)channel orderSeq:(uint32_t)orderSeq;


/// 获取小于指定orderSeq 有messageSeq的第一条消息
/// @param channel <#channel description#>
/// @param orderSeq <#orderSeq description#>
-(LIMMessage*) getMessage:(LIMChannel*)channel lessThanAndFirstMessageSeq:(uint32_t)orderSeq;

// 获取大于指定orderSeq 有messageSeq的第一条消息
-(LIMMessage*) getMessage:(LIMChannel*)channel moreThanAndFirstMessageSeq:(uint32_t)orderSeq;
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
 将上传中的消息状态更改为发送失败的状态
 */
-(void) updateMessageUploadingToFailStatus;


/// 获取所有等待发送的消息
-(NSArray<LIMMessage*>*) getMessagesWaitSend;
/**
 更新消息状态

 @param status 消息状态
 @param clientSeq 消息clientSeq
 */
-(void) updateMessageStatus:(LIMMessageStatus)status withClientSeq:(uint32_t)clientSeq;


/// 更新消息撤回状态
/// @param revoke <#revoke description#>
/// @param clientMsgNo <#clientMsgNo description#>
-(void) updateMessageRevoke:(BOOL)revoke clientMsgNo:(NSString*)clientMsgNo;

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


/// 清除所有消息
-(void) clearAllMessages;
/**
 获取最后一条消息

 @param channel <#channel description#>
 @return <#return value description#>
 */
-(LIMMessage*) getLastMessage:(LIMChannel*)channel;


/// 获取指定偏移量的最新消息
/// @param channel <#channel description#>
/// @param offset <#offset description#>
-(LIMMessage*) getLastMessage:(LIMChannel*)channel offset:(NSInteger)offset;


/// 查询排序在指定message之前的消息数量
/// @param message <#message description#>
-(NSInteger) getOrderCountMoreThanMessage:(LIMMessage*)message;
@end

NS_ASSUME_NONNULL_END
