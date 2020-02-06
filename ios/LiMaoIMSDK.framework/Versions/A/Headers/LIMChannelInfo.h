//
//  LIMChannelInfo.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMChannelInfoFollowStrange,
    LIMChannelInfoFollowFriend,
} LIMChannelInfoFollow;

@interface LIMChannelInfo : NSObject

// 频道
@property(nonatomic,strong) LIMChannel *channel;


/**
 是否已关注 0.未关注（陌生人） 1.已关注（好友）
 */
@property(nonatomic,assign) LIMChannelInfoFollow follow;

/**
 频道名字
 */
@property(nonatomic,copy) NSString *name;


/**
频道公告
 */
@property(nonatomic,copy) NSString *notice;


/**
 频道logo
 */
@property(nonatomic,copy) NSString *logo;


/**
 频道备注
 */
@property(nonatomic,copy) NSString *remark;


/**
 是否置顶
 */
@property(nonatomic,assign) BOOL stick;


/**
 是否免打扰
 */
@property(nonatomic,assign) BOOL mute;


/**
 是否显示昵称
 */
@property(nonatomic,assign) BOOL showNick;


/**
 是否保存
 */
@property(nonatomic,assign) BOOL save;


/**
 频道版本号
 */
@property(nonatomic,assign) long long version;

/**
 扩展字段
 */
@property(nonatomic,strong) NSDictionary *extra;

@end

NS_ASSUME_NONNULL_END
