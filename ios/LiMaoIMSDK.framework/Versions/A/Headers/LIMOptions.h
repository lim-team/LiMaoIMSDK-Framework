//
//  LIMOptions.h
//  CocoaAsyncSocket
//
//  Created by tt on 2019/11/23.
//

#import <Foundation/Foundation.h>
#import "LIMConnectInfo.h"
#import "LIMConst.h"
NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    LIMModeWrite, // 写扩散模式
    LIMModeRead, // 读扩散模式
} LIMMode;


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


/// IM模式
@property(nonatomic,assign) LIMMode mode;
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


/// db前缀
@property(nonatomic,copy) NSString *dbPrefix;

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


/// 发送图片的时候图片最大大小，大于这个大小将自动压缩
@property(nonatomic,assign) long imageMaxBytes;


/// SDK使用消息协议版本（默认使用最新的协议，如果使用旧协议需要手动设置值）
@property(nonatomic,assign) uint8_t protoVersion;



/// 同步频道消息每次大小
@property(nonatomic,assign) NSInteger syncChannelMessageLimit;

/// 协议类型
@property(nonatomic,assign) LIMProto proto;

@property(nonatomic,assign) BOOL mosConvertOn; // 是否开启mos的content转换（临时参数）

@end

NS_ASSUME_NONNULL_END
