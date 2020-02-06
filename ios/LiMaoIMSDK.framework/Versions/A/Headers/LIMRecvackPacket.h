//
//  LIMRecvackPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/30.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMPacketBodyCoder.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMRecvackPacket : LIMPacket<LIMPacketBodyCoder>

@property(nonatomic,assign) uint64_t messageId;
@property(nonatomic,assign) uint32_t messageSeq;

@end

NS_ASSUME_NONNULL_END
