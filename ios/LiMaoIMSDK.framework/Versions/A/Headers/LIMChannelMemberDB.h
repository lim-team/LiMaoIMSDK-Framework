//
//  LIMChannelMemberDB.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/1/20.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMMemberRoleCommon,
    LIMMemberRoleCreator,
    LIMMemberRoleManager,
} LIMMemberRole;

@interface LIMChannelMember : NSObject

@property(nonatomic,copy)    NSString *channelId; // 频道ID
@property(nonatomic,assign)  uint8_t channelType; // 频道类型
@property(nonatomic,copy) NSString *memberAvatar; // 成员头像
@property(nonatomic,copy)    NSString *memberUid; // 成员uid
@property(nonatomic,copy)    NSString *memberName; // 成员名称
@property(nonatomic,copy)    NSString *memberRemark; // 成员备注
@property(nonatomic,assign)   LIMMemberRole  role; // 成员角色
@property(nonatomic,strong) NSNumber *version; // 版本
@property(nonatomic,strong) NSMutableDictionary *extra; // 扩展字段

@property(nonatomic,strong) NSString *createdAt; // 成员加入时间
@property(nonatomic,strong) NSString *updatedAt; // 成员数据最后一次更新时间

@property(nonatomic,assign) BOOL isDeleted; // 是否已删除

@end

@interface LIMChannelMemberDB : NSObject

+ (LIMChannelMemberDB *)shared;


/**
 添加或更新成员

 @param members <#members description#>
 */
-(void) addOrUpdateMembers:(NSArray<LIMChannelMember*>*)members;


/**
 获取频道的成员最新同步key

 @param channel 频道信息
 @return <#return value description#>
 */
-(NSString*) getMemberLastSyncKey:(LIMChannel*)channel;


/**
 获取频道对应的成员列表

 @param channel 频道
 @return <#return value description#>
 */
-(NSArray<LIMChannelMember*>*) getMembersWithChannel:(LIMChannel*)channel;


/// 获取管理员和创建者列表
/// @param channel 频道
-(NSArray<LIMChannelMember*>*) getManagerAndCreator:(LIMChannel*)channel;

/**
 获取频道内指定uid的成员列表

 @param channel <#channel description#>
 @param uids <#uids description#>
 @return <#return value description#>
 */
-(NSArray<LIMChannelMember*>*) getMembersWithChannel:(LIMChannel*)channel uids:(NSArray<NSString*>*)uids;


/**
 分页查询频道成员数

 @param channel 频道
 @param page 页码
 @param pageSize 页大小
 @return <#return value description#>
 */
-(NSArray<LIMChannelMember*>*) getMembersWithChannel:(LIMChannel*)channel page:(NSInteger)page pageSize:(NSInteger)pageSize;


/**
 是否是管理员 （群主或管理者）

 @param channel 频道
 @param uid 用户UID
 @return <#return value description#>
 */
-(BOOL) isManager:(LIMChannel*)channel memberUID:(NSString*)uid;


/**
 是否是创建者

 @param channel 频道
 @param uid 用户UID
 @return <#return value description#>
 */
-(BOOL) isCreator:(LIMChannel*)channel memberUID:(NSString*)uid;


/// 成员是否存在频道里
/// @param channel 频道对象
/// @param uid 成员uid
-(BOOL) exist:(LIMChannel*)channel uid:(NSString*)uid;

/**
 获取指定的成员信息

 @param channel 频道
 @param uid 成员UID
 @return 成员信息
 */
- (LIMChannelMember*)get:(LIMChannel*)channel  memberUID:(NSString *)uid;
@end

NS_ASSUME_NONNULL_END
