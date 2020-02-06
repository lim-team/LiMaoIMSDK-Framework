//
//  LIMPacket.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//

#import <Foundation/Foundation.h>
#import "LIMHeader.h"
typedef NSString* (^Encode)(void);

@interface LIMPacket : NSObject

@property(nonatomic,strong) LIMHeader *header;


@end
