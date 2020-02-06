//
//  LIMCoder.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
NS_ASSUME_NONNULL_BEGIN


@interface LIMCoder : NSObject


/**
 编码包

 @param packet 包对象
 @return 返回包的二进制数据
 */
-(NSData*) encode:(LIMPacket*)packet;


/**
 解码包

 @param data <#data description#>
 @return <#return value description#>
 */
-(LIMPacket*) decode:(NSData*)data;

@end

NS_ASSUME_NONNULL_END
