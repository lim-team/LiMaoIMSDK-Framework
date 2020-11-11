//
//  LIMChannelInfo.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/23.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
#import "LIMConst.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMChannelInfoFollowStrange = 0, // 未关注
    LIMChannelInfoFollowFriend = 1, // 已关注
     LIMChannelInfoFollowAll = 2,
} LIMChannelInfoFollow;

// 扩展字段的key
typedef NSString *LIMChannelExtraKey NS_STRING_ENUM;

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
 频道备注
 */
@property(nonatomic,copy) NSString *remark;


/// 展示的名字（如果remark为空则显示name，如果remark有值则显示remark）
@property(nonatomic,copy) NSString *displayName;


/**
频道公告
 */
@property(nonatomic,copy) NSString *notice;


/**
 频道logo
 */
@property(nonatomic,copy) NSString *logo;





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


/// 是否全员禁言
@property(nonatomic,assign) BOOL forbidden;


/// 群聊邀请确认
@property(nonatomic,assign) BOOL invite;

/**
 频道版本号
 */
@property(nonatomic,assign) long long version;


/// 频道状态 0.正常  2.黑名单
@property(nonatomic,assign) NSInteger status;


/// 是否在线
@property(nonatomic,assign) BOOL online;


/// 频道类别
@property(nonatomic,copy) NSString *category;


/// 最后一次离线时间
@property(nonatomic,assign) NSTimeInterval lastOffline;
/**
 扩展字段
 */
@property(nonatomic,strong) NSMutableDictionary<LIMChannelExtraKey,id> *extra;

/// 获取扩展字段内的值
/// @param key <#key description#>
-(id) extraValueForKey:(LIMChannelExtraKey)key;

-(id) extraValueForKey:(LIMChannelExtraKey)key defaultValue:(id _Nullable)value;

-(void) setExtraValue:(id)value forKey:(LIMChannelExtraKey)key;

-(BOOL) settingForKey:(LIMChannelExtraKey)key defaultValue:(BOOL)on;

-(void) setSettingValue:(BOOL)on forKey:(LIMChannelExtraKey)key;
@end

NS_ASSUME_NONNULL_END
