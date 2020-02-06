//
//  LIMConnackPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/26.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMConnackPacket : LIMPacket<LIMPacketBodyCoder>

// 客户端与服务器的时间差值
@property(nonatomic,assign) int64_t timeDiff;

// 连接返回原因代号
@property(nonatomic,assign) uint8_t reasonCode;

@end

NS_ASSUME_NONNULL_END
