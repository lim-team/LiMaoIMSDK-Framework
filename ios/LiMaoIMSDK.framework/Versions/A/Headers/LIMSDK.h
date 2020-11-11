//
//  LIMSDK.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/23.
//

#import <Foundation/Foundation.h>
#import "LIMOptions.h"
#import "LIMConnectionManager.h"
#import "LIMCoder.h"
#import "LIMPakcetBodyCoderManager.h"
#import "LIMChatManager.h"
#import "LIMMessageContent.h"
#import "LIMConversationManager.h"
#import "LIMChannelManager.h"
#import "LIMMediaManager.h"
#import "LIMMessageFileUploadTask.h"
#import "LIMMessageFileDownloadTask.h"
#import "LIMTaskManager.h"
#import "LIMCMDManager.h"
NS_ASSUME_NONNULL_BEGIN


/**
 频道资料回调

 @param error 错误
 */
typedef void (^LIMChannelInfoCallback)(NSError * _Nullable error);


/**
 离线消息回调

 @param messages 获取的离线消息
 @param more 是否还有更多消息
 @param error 错误信息
 */
typedef void(^LIMOfflineMessageCallback)(NSArray<LIMMessage*>* __nullable messages,bool more,NSError * __nullable error);
/**
 离线消息ack回调
 @param messageSeq 最后收到的消息序列号
 */

typedef void(^LIMOfflineMessageAck)(uint32_t messageSeq,void(^complete)(NSError *error));


/**
 用户信息提供者 （第三方需要设置）

 */
typedef void (^LIMChannelInfoUpdate)(LIMChannel *channel,LIMChannelInfoCallback callback);


/**
 离线消息拉取

 @param limit <#limit description#>
 @param messageSeq <#messageSeq description#>
 @param callback <#callback description#>
 */
typedef void (^LIMOfflineMessagePull)(int limit,uint32_t messageSeq,LIMOfflineMessageCallback callback);


// 狸猫SDK
@interface LIMSDK : NSObject



+ (LIMSDK *)shared;

@property(nonatomic,strong) LIMOptions* options;

/**
 连接信息串
 */
@property(nonatomic,copy) NSString *connectURL;

/**
 连接管理者
 */
@property(nonatomic,strong) LIMConnectionManager *connectionManager;


/**
 聊天管理者
 */
@property(nonatomic,strong) LIMChatManager *chatManager;


/**
 频道管理者
 */
@property(nonatomic,strong) LIMChannelManager *channelManager;

/**
 频道信息提供者
 */
@property(nonatomic,strong) LIMChannelInfoUpdate channelInfoUpdate;


/**
 媒体文件管理者
 */
@property(nonatomic,strong) LIMMediaManager *mediaManager;


/**
 编码者
 */
@property(nonatomic,strong) LIMCoder *coder;


/**
 包body的编码解码者管理
 */
@property(nonatomic,strong) LIMPakcetBodyCoderManager *bodyCoderManager;


/**
 最近会话管理
 */
@property(nonatomic,strong) LIMConversationManager *conversationManager;



/// cmd管理者
@property(nonatomic,strong) LIMCMDManager *cmdManager;


/**
 是否是debug模式

 @return <#return value description#>
 */
-(BOOL) isDebug;



/// 注册消息正文
/// @param cls 正文的class （需要继承LIMMessageContent）
-(void) registerMessageContent:(Class)cls;


/// 注册消息正文（指定正文类型）
/// @param cls 正文的class （需要继承LIMMessageContent）
/// @param contentType 正文类型
-(void) registerMessageContent:(Class)cls contentType:(NSInteger)contentType;


/**
 获取正文类型对应的正文对象

 @param contentType <#contentType description#>
 @return <#return value description#>
 */
-(Class) getMessageContent:(NSInteger)contentType;


/**
 是否是系统消息 （目前规定的系统消息的contentType类型为 [1000,2000]之间）

 @param contentType 正文类型
 @return <#return value description#>
 */
-(BOOL) isSystemMessage:(NSInteger)contentType;


// 离线消息拉取（普通模式）
@property(nonatomic,copy,readonly) LIMOfflineMessagePull offlineMessagePull;
@property(nonatomic,copy,readonly) LIMOfflineMessageAck offlineMessageAck;

// 离线会话拉取（万人群模式）
//@property(nonatomic,copy,readonly) LIMOfflineMessagePull offlineMessagePull;

/**
 离线消息提供者

 @param offlineMessageCallback 消息回调
 @param offlineMessageAckCallback ack回调
 */
-(void) setOfflineMessageProvider:(LIMOfflineMessagePull) offlineMessageCallback offlineMessagesAck:(LIMOfflineMessageAck) offlineMessageAckCallback;


/**
 获取消息文件上传任务

 @param message <#message description#>
 @return <#return value description#>
 */
-(LIMMessageFileUploadTask*) getMessageFileUploadTask:(LIMMessage*)message;


/// 获取消息下载任务
/// @param message <#message description#>
-(LIMMessageFileDownloadTask*) getMessageDownloadTask:(LIMMessage*)message;

@end

NS_ASSUME_NONNULL_END
