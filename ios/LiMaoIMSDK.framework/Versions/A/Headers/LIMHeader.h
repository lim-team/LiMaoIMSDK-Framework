//
//  LIMHeader.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LIMHeader : NSObject

// 剩余长度
@property(nonatomic,assign) uint32_t remainLength;
// 包类型
@property(nonatomic,assign) uint8_t packetType;

// 是否显示未读
@property(nonatomic,assign) BOOL showUnread; // RedDot

// 是否不存储
@property(nonatomic,assign) BOOL noPersist;

@end

NS_ASSUME_NONNULL_END
