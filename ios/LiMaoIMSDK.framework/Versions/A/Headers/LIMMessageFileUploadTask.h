//
//  LIMMessageFileUploadTask.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/15.
//

#import <Foundation/Foundation.h>
#import "LIMTaskProto.h"
#import "LIMMessage.h"
#import "LIMBaseTask.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMMessageFileUploadTask : LIMBaseTask

-(instancetype) initWithMessage:(LIMMessage*)message;

// 消息
@property(nonatomic,strong) LIMMessage *message;

/**
 错误 如果任务上传失败，则有值
 */
@property(nullable,nonatomic,strong) NSError *error;
@property(nonatomic,assign) CGFloat progress;

/**
 上传后返回的路径
 */
@property(nullable,nonatomic,strong) NSString *remoteUrl;




@end

NS_ASSUME_NONNULL_END
