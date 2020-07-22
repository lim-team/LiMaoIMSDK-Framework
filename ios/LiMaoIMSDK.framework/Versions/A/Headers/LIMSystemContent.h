//
//  LIMSystemContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/4.
//

#import <Foundation/Foundation.h>
#import "LIMMessageContent.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMSystemContent : LIMMessageContent

@property(nonatomic,strong) NSDictionary *content;


/// 真实的正文类型
-(NSInteger) realContentType;
@end

NS_ASSUME_NONNULL_END
