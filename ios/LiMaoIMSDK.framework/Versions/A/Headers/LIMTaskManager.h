//
//  LIMTaskManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/15.
//

#import <Foundation/Foundation.h>
#import "LIMTaskProto.h"
NS_ASSUME_NONNULL_BEGIN

@protocol LIMTaskManagerDelegate <NSObject>

@optional


/**
 任务完成

 @param task <#task description#>
 */
-(void) taskComplete:(id<LIMTaskProto>)task;


/**
 任务进度

 @param task <#task description#>
 */
-(void) taskProgress:(id<LIMTaskProto>)task;

@end

@interface LIMTaskManager : NSObject

@property(nonatomic,weak) id<LIMTaskManagerDelegate> delegate;

/**
 添加任务

 @param task <#task description#>
 */
-(void) add:(id<LIMTaskProto>)task;


/**
 获取任务

 @param taskId <#taskId description#>
 */
-(id<LIMTaskProto>) get:(NSString *)taskId;
/**
 移除任务

 @param task <#task description#>
 */
-(void) remove:(id<LIMTaskProto>)task;

@end

NS_ASSUME_NONNULL_END
