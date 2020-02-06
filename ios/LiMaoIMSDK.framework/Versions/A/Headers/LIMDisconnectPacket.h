//
//  LIMDisconnectPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/30.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMDisconnectPacket :  LIMPacket<LIMPacketBodyCoder>

// 原因代码
@property(nonatomic,assign) uint8_t reasonCode;
// 原因字符串
@property(nonatomic,copy) NSString *reason;

@end

NS_ASSUME_NONNULL_END
