//
//  LIMOfflineConversation.h
//  LiMaoIMSDK
//
//  Created by tt on 2020/9/30.
//

#import <Foundation/Foundation.h>
#import "LIMChannel.h"
#import "LIMMessage.h"
#import "LIMConversation.h"
NS_ASSUME_NONNULL_BEGIN



@interface LIMSyncConversationModel : NSObject

@property(nonatomic,strong) LIMChannel *channel; // 频道

@property(nonatomic,assign) NSInteger unread; // 消息未读数

@property(nonatomic,assign) NSTimeInterval timestamp; // 最后一次会话时间

@property(nonatomic,assign) uint32_t lastMsgSeq; // 最后一次会话的消息序列号

@property(nonatomic,copy) NSString *lastMsgClientNo; // 最后一次会话的消息客户端编号

@property(nonatomic,assign) long long version; // 数据版本

@property(nonatomic,strong) NSArray<LIMMessage*> *recents; // 会话的最新消息集合

@property(nonatomic,strong,readonly) LIMConversation *conversation;

@end

@interface LIMCMDModel : NSObject

@property(nonatomic,copy) NSString *cmd;
@property(nonatomic,strong) NSDictionary *param;

@end

@interface LIMSyncConversationWrapModel : NSObject

@property(nonatomic,strong) NSArray<LIMSyncConversationModel*> *conversations;
@property(nonatomic,assign) uint64_t cmdVersion;

@property(nonatomic,strong) NSArray<LIMCMDModel*> *cmds;

@end



NS_ASSUME_NONNULL_END
