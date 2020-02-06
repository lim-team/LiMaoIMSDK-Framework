//
//  LIMMessageFileDownloadTask.h
//  LiMaoBase
//
//  Created by tt on 2020/1/16.
//

#import <Foundation/Foundation.h>
#import "LIMBaseTask.h"
#import "LIMMessage.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMMessageFileDownloadTask : LIMBaseTask
-(instancetype) initWithMessage:(LIMMessage*)message;


// 消息
@property(nonatomic,strong) LIMMessage *message;

/**
 错误 如果任务下载失败，则有值
 */
@property(nullable,nonatomic,strong) NSError *error;

/**
 下载进度
 */
@property(nonatomic,assign) CGFloat progress;


@end

NS_ASSUME_NONNULL_END
