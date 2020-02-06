//
//  LIMCMDContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/31.
//

#import "LIMMediaMessageContent.h"

NS_ASSUME_NONNULL_BEGIN

@interface LIMCMDContent : LIMMessageContent


/**
 cmd
 */
@property(nonatomic,copy) NSString *cmd;

/**
 cmd参数
 */
@property(nonatomic,copy) id param;
@end

NS_ASSUME_NONNULL_END
