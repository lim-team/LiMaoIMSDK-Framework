//
//  LIMPacketBodyCoder.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//
#import "LIMPacket.h"

@protocol LIMPacketBodyCoder <NSObject>

-(LIMPacket*) decode:(NSData*) body header:(LIMHeader*)header;

-(NSData*) encode:(LIMPacket*)packet;

@end
