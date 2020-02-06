//
//  LIMConversationUtil.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/24.
//

#import <Foundation/Foundation.h>
#import "LIMConversation.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMConversationUtil : NSObject
// 合并提醒数据
+(NSArray<LIMReminder*>*) mergeReminders:(NSArray<LIMReminder*>*)source dest:(NSArray<LIMReminder*>*)dest;
@end

NS_ASSUME_NONNULL_END
