//
//  LIMTask.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/15.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMTaskStatusWait, // 任务等待执行
     LIMTaskStatusSuccess, // 任务执行成功
    LIMTaskStatusProgressing, // 任务处理中
    LIMTaskStatusSuspend, // 任务挂起
    LIMTaskStatusError, // 任务执行错误
     LIMTaskStatusCancel, // 任务执行错误
} LIMTaskStatus;

typedef void(^LIMTaskListener)(void);


@protocol LIMTaskProto <NSObject>


/**
 设置任务监听者
 */
@property(nonatomic,copy,readonly) NSArray<LIMTaskListener> *listeners;

/**
 任务唯一ID
 */
@property(nonatomic,copy) NSString *taskId;


/**
 任务状态
 */
@property(nonatomic,assign) LIMTaskStatus status;


/**
 添加监听者

 @param listener 监听者
 @param target 目标
 */
- (void)addListener:(nonnull LIMTaskListener)listener target:(id) target;


/**
 移除监听者

 @param target <#target description#>
 */
-(void) removeListener:(id) target;

/**
 恢复任务
 */
-(void) resume;
/**
 暂停任务
 */
-(void) suspend;


/**
取消任务
 */
-(void) cancel;


/**
 任务更新
 */
-(void) update;


@end

NS_ASSUME_NONNULL_END
