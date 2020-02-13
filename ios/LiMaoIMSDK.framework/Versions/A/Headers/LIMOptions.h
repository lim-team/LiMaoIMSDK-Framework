//
//  LIMOptions.h
//  CocoaAsyncSocket
//
//  Created by tt on 2019/11/23.
//

#import <Foundation/Foundation.h>
#import "LIMConnectInfo.h"
NS_ASSUME_NONNULL_BEGIN

typedef LIMConnectInfo*_Nonnull(^LIMConnectInfoCallback)(void);


@interface LIMOptions : NSObject


/**
 IM的host
 */
@property(nonatomic,copy) NSString *host;

/**
 IM的端口
 */
@property(nonatomic,assign) uint16_t port;


/**
 连接信息回调
 */
@property(nonatomic,copy) LIMConnectInfoCallback connectInfoCallback;


/**
连接信息
 */
@property(nullable,nonatomic,strong) LIMConnectInfo *connectInfo;
/**
 是否是debug模式
 */
@property(nonatomic,assign) bool isDebug;


/**
 是否有登录信息

 @return <#return value description#>
 */
-(BOOL) hasLogin;

/**
 心跳间隔 （ 单位秒）
 */
@property(nonatomic,assign) NSTimeInterval heartbeatInterval;

/**
 数据库的存储目录
 */
@property(nonatomic,copy) NSString *dbDir;

// 消息文件根目录
@property(nonatomic,copy) NSString *messageFileRootDir;


/**
 在每次发送消息中是否携带发送者的用户信息。
 */
@property(nonatomic,assign) bool enableMessageAttachUserInfo;

/**
 消息重试间隔 (单位秒)
 */
@property(nonatomic,assign) NSTimeInterval messageRetryInterval;

/**
 消息重试次数
 */
@property(nonatomic,assign) NSInteger messageRetryCount;


/**
 离线消息每次拉取数量
 */
@property(nonatomic,assign) NSInteger offlineMessageLimit;

@end

NS_ASSUME_NONNULL_END
