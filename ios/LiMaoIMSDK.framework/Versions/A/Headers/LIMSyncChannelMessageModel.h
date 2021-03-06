//
//  LIMSyncChannelMessageModel.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/10/5.
//

#import <Foundation/Foundation.h>
#import "LIMMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMSyncChannelMessageModel : NSObject

@property(nonatomic,assign) uint32_t minMessageSeq; // 最小消息序列号
@property(nonatomic,assign) uint32_t maxMessageSeq; // 最大消息序列号
@property(nonatomic,assign) BOOL more; // 是否还有更多数据
@property(nonatomic,strong) NSArray<LIMMessage*> *messages; // 消息集合

@end

NS_ASSUME_NONNULL_END
