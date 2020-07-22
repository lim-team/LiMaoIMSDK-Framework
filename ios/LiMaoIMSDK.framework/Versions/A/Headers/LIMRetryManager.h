//
//  LIMRetryManager.h
//  LiMaoBase
//
//  Created by tt on 2019/12/29.
//

#import <Foundation/Foundation.h>
#import "LIMMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMRetryItem : NSObject
// 消息
@property(nonatomic,strong) LIMMessage *message;
// 重试次数
@property(nonatomic,assign) long retryCount;
// 下次重试时间
@property(nonatomic,assign) long nextRetryTime;

@property(nonatomic,assign) long nextRetryTime2;


@end

@interface LIMRetryManager : NSObject

+ (LIMRetryManager *)shared;


/**
 开启重试
 */
-(void) start;


/**
 停止重试
 */
-(void) stop;
/**
 添加重试项

 @param message 消息
 */
-(void) add:(LIMMessage*)message;


/**
 移除重试项

 @param key key
 */
-(void) removeRetryItem:(NSString*) key;

@end

NS_ASSUME_NONNULL_END
