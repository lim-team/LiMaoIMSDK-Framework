//
//  LIMConnectionManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/23.
//

#import <Foundation/Foundation.h>
#import "LIMPacket.h"
#import "LIMConnectInfo.h"
NS_ASSUME_NONNULL_BEGIN


typedef enum : NSUInteger {
    LIMNoConnect,    // 未连接
    LIMConnecting,  // 连接中
    LIMPullingOffline, // 拉取离线中
    LIMConnetced, // 已建立连接
    LIMDisconnected, // 断开连接
} LIMConnectStatus;






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


///  获取连接地址
@property(nonatomic,copy) void(^getConnectAddr)(void(^complete)(NSString * __nullable addr));
/**
 *  连接狸猫服务器
 */
-(void) connect;



/**
 断开连接
 @param force 是否强制断开 如果force设置为true 将不再自动重连
 */
-(void) disconnect:(BOOL) force;


/// 登出，将强制断开，并清除登录信息
-(void) logout;


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


@end

NS_ASSUME_NONNULL_END
