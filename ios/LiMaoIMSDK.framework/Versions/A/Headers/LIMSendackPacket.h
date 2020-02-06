//
//  LIMSendackPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMSendackPacket :  LIMPacket<LIMPacketBodyCoder>
// 客户端序列号 (客户端提供，服务端原样返回)
@property(nonatomic,assign) uint32_t clientSeq;
// 消息ID（全局唯一）
@property(nonatomic,assign) uint64_t messageId;
// 消息序列号（用户唯一，有序）
@property(nonatomic,assign) uint32_t messageSeq;
// 原因代码
@property(nonatomic,assign) uint8_t reasonCode;

@end

NS_ASSUME_NONNULL_END
