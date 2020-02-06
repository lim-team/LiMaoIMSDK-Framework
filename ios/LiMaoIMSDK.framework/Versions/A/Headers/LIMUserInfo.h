//
//  LIMUser.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LIMUserInfo : NSObject<NSCoding>

-(instancetype) initWithUid:(NSString*)uid name:(NSString*)name avatar:(NSString*)avatar;

/*!
 用户ID
 */
@property (nonatomic, copy) NSString *uid;

/*!
 用户名称
 */
@property (nonatomic, copy) NSString *name;

/*!
 用户头像的URL
 */
@property (nonatomic, copy) NSString *avatar;

/**
 用户信息附加字段
 */
@property (nonatomic, copy) NSString *extra;

@end

NS_ASSUME_NONNULL_END
