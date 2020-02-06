//
//  LIMChannel.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/27.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LIMChannel : NSObject<NSCopying>
// 频道ID
@property(nonatomic,copy) NSString *channelId;
// 频道类型
@property(nonatomic,assign) uint8_t channelType;

-(instancetype) initWith:(NSString*)channelId channelType:(uint8_t)channelType;



@end

NS_ASSUME_NONNULL_END
