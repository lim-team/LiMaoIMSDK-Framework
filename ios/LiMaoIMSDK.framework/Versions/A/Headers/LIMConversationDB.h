//
//  LIMConversationDB.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMConversation.h"
#import "LIMDB.h"
NS_ASSUME_NONNULL_BEGIN
@class LIMConversationAddOrUpdateResult;
@interface LIMConversationDB : NSObject

+ (LIMConversationDB *)shared;


/**
 添加或修改最近会话

 @param conversation <#conversation description#>
 */
-(void) addOrUpdateConversation:(LIMConversation*)conversation;


/**
 查询指定频道的最近会话

 @param channel <#channel description#>
 @param db <#db description#>
 @return <#return value description#>
 */
-(LIMConversation*) getConversationWithChannel:(LIMChannel*)channel db:(FMDatabase*)db;

/**
 查询频道类的最近会话数据

 @return <#return value description#>
 */
-(NSArray<LIMConversation*>*) getConversationList;


/**
 获取最近会话

 @param channel 频道
 @return <#return value description#>
 */
-(LIMConversation*) getConversation:(LIMChannel*)channel;


/**
 通过最后一条消息的客户端序号获取最近会话

 @param lastClientSeq 最后一条消息的序号
 @return <#return value description#>
 */
-(LIMConversation*) getConversationWithLastClientSeq:(uint32_t)lastClientSeq;

/**
 更新最近会话

 @param conversation <#conversation description#>
 */
-(void) updateConversation:(LIMConversation*)conversation;
/**
 更新最近会话

 @param conversation <#conversation description#>
 @param db <#db description#>
 */
-(void) updateConversation:(LIMConversation*)conversation db:(FMDatabase*)db;


/**
 插入最近会话

 @param conversation <#conversation description#>
 @param db <#db description#>
 */
-(void) insertConversation:(LIMConversation*)conversation db:(FMDatabase*)db;


/**
 清除指定频道的未读消息

 @param channel <#channel description#>
 */
-(void) clearConversationUnreadCount:(LIMChannel*)channel;

/**
 更新最近会话的标题和头像

 @param channel <#channel description#>
 @param title <#title description#>
 @param avatar <#avatar description#>
 @param db <#db description#>
 */
-(void) updateConversation:(LIMChannel*)channel title:(NSString*)title avatar:(NSString*) avatar db:(FMDatabase*)db;



/**
 追加提醒

 @param reminder 提醒项
 @param channel 频道
 @return 追加后的z最近会话
 */
-(LIMConversation*) appendReminder:(LIMReminder*) reminder channel:(LIMChannel*)channel;


/**
清除指定频道的所有提醒

 @param channel 频道
 @return <#return value description#>
 */
-(LIMConversation*) clearAllReminder:(LIMChannel*)channel;


/**
 清除指定频道指定类型的提醒

 @param channel 频道
 @param type 提醒类型
 @return <#return value description#>
 */
-(LIMConversation*) clearReminder:(LIMChannel*)channel type:(NSInteger)type;

@end

// 最近会话添加或修改结果
@interface LIMConversationAddOrUpdateResult : NSObject

@property(nonatomic,assign) BOOL insert;

@property(nonatomic,strong) LIMConversation *conversation;

+(instancetype) initWithInsert:(BOOL)insert conversation:(LIMConversation*)conversation;
@end

NS_ASSUME_NONNULL_END