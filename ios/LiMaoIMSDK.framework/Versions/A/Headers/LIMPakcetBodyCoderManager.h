//
//  LIMPakcetBodyManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//

#import <Foundation/Foundation.h>
#import "LIMPacketBodyCoder.h"
#import "LIMConst.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMPakcetBodyCoderManager : NSObject


/**
 注册body解码者

 @param packetType 包类型
 @param bodyCoder 包编码者
 */
-(void) registerBodyCoder:(LIMPacketType)packetType bodyCoder:(id<LIMPacketBodyCoder>)bodyCoder;

/**
 获取body编码者

 @param packetType 包类型
 @return 返回包body编码者
 */
-(id<LIMPacketBodyCoder>) getBodyCoder:(LIMPacketType)packetType;
@end

NS_ASSUME_NONNULL_END
