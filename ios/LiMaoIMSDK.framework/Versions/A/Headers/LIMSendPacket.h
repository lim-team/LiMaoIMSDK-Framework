//
//  LIMSendPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMSendPacket : LIMPacket<LIMPacketBodyCoder>

// 客户端提供的序列号，在客户端内唯一
@property(nonatomic,assign) uint32_t clientSeq;

/// 客户端消息唯一编号
@property(nonatomic,copy) NSString *clientMsgNo;

//频道ID（如果是个人频道ChannelId为个人的UID）
@property(nonatomic,copy) NSString *channelId;
//频道类型（1.个人 2.群组）
@property(nonatomic,assign) uint8_t channelType;
// 负荷数据
@property(nonatomic,strong) NSData *payload;

@end

NS_ASSUME_NONNULL_END
