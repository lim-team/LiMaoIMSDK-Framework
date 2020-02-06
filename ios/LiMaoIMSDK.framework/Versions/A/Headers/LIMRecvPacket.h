//
//  LIMRecvPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMRecvPacket : LIMPacket<LIMPacketBodyCoder>
// 消息唯一ID
@property(nonatomic,assign) uint64_t messageId;
// 消息序列号 （用户唯一，有序递增）
@property(nonatomic,assign) uint32_t messageSeq;
// 服务器时间
@property(nonatomic,assign) uint32_t timestamp;
// 发送者UID
@property(nonatomic,copy) NSString *fromUid;
//频道ID（如果是个人频道ChannelId为个人的UID）
@property(nonatomic,copy) NSString *channelId;
//频道类型（1.个人 2.群组）
@property(nonatomic,assign) uint8_t channelType;
// 负荷数据
@property(nonatomic,strong) NSData *payload;
@end

NS_ASSUME_NONNULL_END
