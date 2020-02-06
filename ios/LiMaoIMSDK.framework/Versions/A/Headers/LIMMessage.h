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
// 消息ID（全局唯一）
@property(nonatomic,assign) uint64_t messageId;
// 消息序列号（用户唯一，有序）
@property(nonatomic,assign)  uint32_t messageSeq;
// 消息时间（服务器时间）
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


// 本地扩展数据
@property(nonatomic,copy) NSMutableDictionary *extra;

@end


NS_ASSUME_NONNULL_END
