//
//  LIMCMDManager.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/10/7.
//

#import <Foundation/Foundation.h>
#import "LIMSyncConversationModel.h"
@class LIMCMDManager;
NS_ASSUME_NONNULL_BEGIN

@protocol LIMCMDManagerDelegate <NSObject>

@optional


/// 收到命令
/// @param manager <#manager description#>
/// @param model <#model description#>
-(void) cmdManager:(LIMCMDManager*)manager onCMD:(LIMCMDModel*)model;

@end

@interface LIMCMDManager : NSObject

/**
 添加媒体委托
 
 @param delegate <#delegate description#>
 */
-(void) addDelegate:(id<LIMCMDManagerDelegate>) delegate;


/**
 移除媒体委托
 
 @param delegate <#delegate description#>
 */
-(void)removeDelegate:(id<LIMCMDManagerDelegate>) delegate;


/// 调用接受命令委托
/// @param model <#model description#>
-(void) callOnCMDDelegate:(LIMCMDModel*)model;

@end

NS_ASSUME_NONNULL_END
