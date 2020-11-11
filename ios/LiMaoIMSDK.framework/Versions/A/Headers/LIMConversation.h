//
//  LIMConversation.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/12/8.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
#import "LIMChannelInfo.h"
#import "LIMMessage.h"
NS_ASSUME_NONNULL_BEGIN

typedef enum : NSUInteger {
    LIMReminderTypeMentionMe = 1, // 有人@我
    LIMReminderTypeDraft = 2, // 草稿
} LIMReminderType;

@interface LIMReminder : NSObject

+(instancetype) initWithType:(LIMReminderType)type text:(NSString*)text data:(NSDictionary*)data;

/**
 提醒类型
 */
@property(nonatomic,assign) LIMReminderType type;


/**
 提醒文本
 */
@property(nonatomic,copy) NSString *text;


/**
 提醒包含的数据
 */
@property(nonatomic,strong) NSDictionary *data;


/**
 转换为字典

 @return <#return value description#>
 */
-(NSDictionary*) toDictionary;

@end

@interface LIMReminderManager : NSObject

/**
 提醒集合
 */
@property(nonatomic,strong) NSMutableArray *reminders;

/**
 追加提醒

 @param reminder <#reminder description#>
 */
-(void) appendReminder:(LIMReminder*)reminder;


/**
 移除指定的提醒项

 @param type <#type description#>
 */
-(void) removeReminder:(LIMReminderType)type;

/**
 合并提醒

 @param source 合并源
 @return <#return value description#>
 */
- (NSArray<LIMReminder*>*) mergeReminders:(NSArray<LIMReminder*>*)source;


@end


@interface LIMConversation : NSObject
/**
 频道
 */
@property(nonatomic,strong) LIMChannel *channel;
/**
 *  频道资料，可能为空，如果为空可以调用LIMChannelManager fetchChannelInfo:completion 触发频道信息变更委托
 */
@property(nullable,nonatomic,strong,readonly) LIMChannelInfo *channelInfo;
/**
 头像
 */
@property(nonatomic,copy) NSString *avatar;
/**
 最新一条消息的客户端seq
 */
//@property(nonatomic,assign) uint32_t lastClientSeq;
/// 最后一条消息的客户端编号
@property(nonatomic,copy) NSString *lastClientMsgNo;
/**
 最后一条消息
 */
@property(nonatomic,strong) LIMMessage *lastMessage;
/**
 最新一条消息时间 （10位时间戳到秒）
 */
@property(nonatomic,assign) NSInteger lastMsgTimestamp;

/// 已预览至的message_seq （这里注意是预览不是已读至）
@property(nonatomic,assign) uint32_t browseTo;
/**
 未读消息数量
 */
@property(nonatomic,assign) NSInteger unreadCount;
/**
 提醒管理
 */
@property(nonatomic,strong) LIMReminderManager *reminderManager;
/**
 扩展数据
 */
@property(nonatomic,strong) NSDictionary *extra;
/// 数据版本
@property(nonatomic,assign) long long version;
// 是否已删除
@property(nonatomic,assign) NSInteger isDeleted;

/// 重新加载最后一条消息（重新从数据库里获取）
-(void) reloadLastMessage;

@end

NS_ASSUME_NONNULL_END
