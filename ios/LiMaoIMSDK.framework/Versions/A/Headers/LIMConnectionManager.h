//
//  LIMConnectionManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/23.
//

#import <Foundation/Foundation.h>
#import "ILIMConnectionManager.h"
#import "LIMPacket.h"
NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    LIMNoConnect,    // 未连接
    LIMConnecting,  // 连接中
    LIMPullingOffline, // 拉取离线中
    LIMConnetced, // 已建立连接
    LIMDisconnected, // 断开连接
} LIMConnectStatus;


@interface LIMConnectInfo : NSObject

@property(nonatomic,copy) NSString *uid;
@property(nonatomic,copy) NSString *token;
@property(nonatomic,copy) NSString *name;
@property(nonatomic,copy) NSString *avatar;

@end

typedef LIMConnectInfo*_Nonnull(^LIMConnectInfoCallback)(void);

@protocol LIMConnectionManagerDelegate <NSObject>

@optional
/**
 连接状态监听
 */
-(void) onConnectStatus:(LIMConnectStatus)status;


/**
  连接被踢出

 @param reasonCode 踢出原因代号
 @param reason 踢出原因字符串
 */
-(void) onKick:(uint8_t)reasonCode reason:(NSString*)reason;
@end

@interface LIMConnectionManager : NSObject

+ (LIMConnectionManager*)sharedManager;

@property(nonatomic,assign,readonly) LIMConnectStatus connectStatus;

/**
 *  连接狸猫服务器
 */
-(void) connect;



/**
 设置连接信息回调block

 @param callback 连接信息回调
 */
-(void) setConnectInfoCallback:(LIMConnectInfoCallback)callback;

/**
 断开连接
 @param force 是否强制断开 如果force设置为true 将不再自动重连
 */
-(void) disconnect:(BOOL) force;


/**
 添加连接委托

 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMConnectionManagerDelegate>) delegate;


/**
 移除连接委托

 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMConnectionManagerDelegate>) delegate;


/**
 发送包

 @param packet <#packet description#>
 */
-(void) sendPacket:(LIMPacket*)packet;


/**
 发送ping包
 */
-(void) sendPing;


/**
 当前连接信息

 @return <#return value description#>
 */
-(LIMConnectInfo*) currentConnectInfo;
@end

NS_ASSUME_NONNULL_END
