//
//  LIMUUIDUtil.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/5/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LIMUUIDUtil : NSObject

+ (NSString*)getUUID;

+(NSString*) getClientMsgNo:(NSString*)custId toCustId:(NSString*)toCustId chatId:(NSString*)chatId;
@end

NS_ASSUME_NONNULL_END
