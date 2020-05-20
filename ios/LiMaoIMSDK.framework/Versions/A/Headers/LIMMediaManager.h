//
//  LIMMediaManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/13.
//

#import <Foundation/Foundation.h>
#import "LIMMediaProto.h"
#import "LIMMessage.h"
#import "LIMTaskProto.h"
#import "LIMTaskManager.h"
#import <CoreGraphics/CGBase.h>
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMMediaUploadStateProcessing = 0,
    LIMMediaUploadStateSuccess = 1,
    LIMMediaUploadStateFail = 2,
} LIMMediaUploadState;

typedef enum : NSUInteger {
    LIMMediaDownloadStateProcessing = 0,
    LIMMediaDownloadStateSuccess = 1,
    LIMMediaDownloadStateFail = 2,
} LIMMediaDownloadState;

@interface LIMFileInfo : NSObject

@property(nonatomic,copy) NSString *fid; // 文件唯一id
@property(nonatomic,copy) NSString *name; // 文件名
@property(nonatomic,assign) long size;  // 文件大小（单位byte）
@property(nonatomic,copy) NSString *url; // 文件路径

@end

/**
 多媒体委托
 */
@protocol LIMMediaManagerDelegate <NSObject>


/**
 媒体文件数据更新

 @param media 媒体文件
 */
-(void) mediaManageUpdate:(id<LIMMediaProto>)media;


@end


/**
 多媒体上传任务提供者
 */
typedef id<LIMTaskProto>_Nonnull(^LIMMediaUploadTaskProvider)(LIMMessage* message);

/**
 多媒体下载任务提供者
 */
typedef id<LIMTaskProto>_Nonnull(^LIMMediaDownloadTaskProvider)(LIMMessage* message);

// 音频播放完成block
typedef void(^LIMAudioPayerDidFinishBlock)(BOOL successFlag);


@interface LIMMediaManager : NSObject

+ (LIMMediaManager *)shared;

@property(nonatomic,strong) LIMTaskManager *taskManager;
/**
 添加媒体委托
 
 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMMediaManagerDelegate>) delegate;


/**
 移除媒体委托
 
 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMMediaManagerDelegate>) delegate;



/**
 下载任务提供者
 */
@property(nonatomic,copy) LIMMediaDownloadTaskProvider downloadTaskProvider;
/**
上传任务提供者
 */
@property(nonatomic,copy) LIMMediaUploadTaskProvider uploadTaskProvider;

/**
 上传消息里的多媒体

 @param message 消息
 */
-(void) upload:(LIMMessage*) message;


/**
 下载消息的多媒体文件

 @param message <#message description#>
 */
-(void) download:(LIMMessage*)message;


/**
 下载消息的多媒体文件

 @param message 消息对象
 @param callback 下载回调
 */
-(void) download:(LIMMessage*)message callback:(void(^ __nullable)(LIMMediaDownloadState state,CGFloat progress,NSError * __nullable error))callback;

/**
 获取上传进度

 @param message 消息
 @return <#return value description#>
 */
-(CGFloat) getUploadProgress:(LIMMessage*)message;


/**
 获取下载进度

 @param message 消息
 @return <#return value description#>
 */
-(CGFloat) getDowloadProgress:(LIMMessage*)message;



/**
 将音频消息的副本转换为源文件

 @param message <#message description#>
 */
-(void) voiceMessageThumbToSource:(LIMMessage*)message;

/**
 *  是否正在播放音频
 *
 */
- (BOOL)isAudioPlaying;

/**
 *  播放音频文件
 *
 *  @param filePath 文件路径
 */
-(void) playAudio:(NSString *)filePath payerDidFinish:(LIMAudioPayerDidFinishBlock)finishBlock;

/**
 *  停止播放音频
 */
- (void)stopAudioPlay;


@end

NS_ASSUME_NONNULL_END
