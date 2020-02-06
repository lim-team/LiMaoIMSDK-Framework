//
//  LIMMessageStatusModel.h
//  LiMaoBase
//
//  Created by tt on 2019/12/29.
//

#import <Foundation/Foundation.h>
#import "LIMConst.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMMessageStatusModel : NSObject
// 消息唯一ID
@property(nonatomic,assign) uint32_t clientSeq;
// 消息状态
@property(nonatomic) LIMMessageStatus status;

-(instancetype) initWithClientSeq:(uint32_t)clientSeq status:(LIMMessageStatus)status;
@end

NS_ASSUME_NONNULL_END
