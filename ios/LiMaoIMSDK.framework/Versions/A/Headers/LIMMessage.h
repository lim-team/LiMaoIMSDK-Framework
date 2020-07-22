//
//  LIMMessage.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
#import "LIMMessageContent.h"
#import "LIMChannelInfo.h"
#import "LIMConst.h"
#import "LIMChannelMemberDB.h"
#import "LIMTaskProto.h"
NS_ASSUME_NONNULL_BEGIN
@interface LIMMessageHeader : NSObject
// 是否红点
// 是否显示未读
@property(nonatomic,assign) BOOL showUnread; // RedDot

// 是否不存储
@property(nonatomic,assign) BOOL noPersist;

@end

@interface LIMMessage : NSObject
// 消息头
@property(nonatomic,strong) LIMMessageHeader *header;

// 客户端序列号 (客户端提供，服务端原样返回)
@property(nonatomic,assign) uint32_t clientSeq;
/// 客户端消息唯一编号(相同clientMsgNo被认为是重复消息)
@property(nonatomic,copy) NSString *clientMsgNo;
// 消息ID（全局唯一）
@property(nonatomic,assign) uint64_t messageId;
// 消息序列号（用户唯一，有序）
@property(nonatomic,assign)  uint32_t messageSeq;
// 消息时间（服务器时间,单位秒）
@property(nonatomic,assign) NSInteger timestamp;
// 本地消息创建时间
@property(nonatomic,assign) NSInteger localTimestamp;

// 发送者
@property(nonatomic,strong) LIMChannelInfo *from;
// 发送者uid
@property(nonatomic,copy) NSString *fromUid;

// 发送者在频道里的成员信息
@property(nonatomic,strong,readonly) LIMChannelMember *memberOfFrom;

// 接收者uid
@property(nonatomic,copy) NSString *toUid;
// 频道
@property(nonatomic,strong) LIMChannel *channel;
/**
 *  频道资料，可能为空，如果为空可以调用LIMChannelManager fetchChannelInfo:completion 触发频道信息变更委托
 */
@property(nullable,nonatomic,strong,readonly) LIMChannelInfo *channelInfo;
// 正文类型
@property(nonatomic,assign) NSInteger contentType;
// 消息正文
@property(nonatomic,strong) LIMMessageContent *content;
// 消息正文data数据
@property(nonatomic,strong) NSData *contentData;

// 消息是否已读
@property(nonatomic,assign) BOOL readed;
// 语音是否已读 （对语音消息有效）
@property(nonatomic,assign) BOOL voiceReaded;

// 消息状态
@property(nonatomic,assign) LIMMessageStatus status;


/// 消息关联的任务（例如：下载图片任务，上传图片任务等等）
@property(nonatomic,weak,readonly) id<LIMTaskProto> task;
/**
 是否是发送消息

 @return <#return value description#>
 */
- (BOOL)isSend;

// 本地扩展数据
@property(nonatomic,copy) NSMutableDictionary *extra;

@end


NS_ASSUME_NONNULL_END
