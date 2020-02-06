//
//  LIMMessageContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMUserInfo.h"
NS_ASSUME_NONNULL_BEGIN

/*!
 @提醒的类型
 */
typedef NS_ENUM(NSUInteger, LIMMentionedType) {
    /*!
     @所有人
     */
    LIM_Mentioned_All = 1,
    
    /*!
     @部分指定用户
     */
    LIM_Mentioned_Users = 2,
};


/**
  消息中的@提醒信息
 */
@interface LIMMentionedInfo : NSObject

/*!
 初始化@提醒信息
 
 @param type       @提醒的类型
 @param uids @的用户ID列表
 
 @return @提醒信息的对象
 */
- (instancetype)initWithMentionedType:(LIMMentionedType)type
                                 uids:(NSArray *)uids;

/*!
 @提醒的类型
 */
@property (nonatomic, assign) LIMMentionedType type;

/*!
 @的用户ID列表
 
 @discussion 如果type是@所有人，则可以传nil
 */
@property (nonatomic, strong) NSArray<NSString *> *uids;

/*!
 是否@了我
 */
@property (nonatomic, readonly) BOOL isMentionedMe;


@end

@class LIMMessage;
@interface LIMMessageContent : NSObject

//TODO: 这里要注意不能声明为strong 如果声明为strong message和media互相引用 就释放不掉了导致内存爆炸。
@property(nonatomic,weak) LIMMessage *message;

/**
  消息内容中携带的发送者的用户信息
 */
@property (nonatomic, strong) LIMUserInfo *senderUserInfo;

/*!
 消息中的@提醒信息
 */
@property (nonatomic, strong) LIMMentionedInfo *mentionedInfo;

/*!
 将消息内容序列化，编码成为可传输的json数据
 
 @discussion
 消息内容通过此方法，将消息中的所有数据，编码成为json数据，返回的json数据将用于网络传输。
 */
- (NSData *)encode;

// 上层无需实现encode 实现此方法即可
-(NSDictionary*) encodeWithJSON;

/*!
 将json数据的内容反序列化，解码生成可用的消息内容
 
 @param data    消息中的原始json数据
 
 @discussion
 网络传输的json数据，会通过此方法解码，获取消息内容中的所有数据，生成有效的消息内容。
 */
- (void)decode:(NSData *)data;

// 上层无序实现decode 实现此方法即可
-(void) decodeWithJSON:(NSDictionary*)contentDic;


/**
 你自定义的消息类型，在各个平台上需要保持一致
 @return 正文类型
 */
+(NSInteger) contentType;

/*!
 返回可搜索的关键内容列表
 
 @return 返回可搜索的关键内容列表
 
 @discussion 这里返回的关键内容列表将用于消息搜索，自定义消息必须要实现此接口才能进行搜索。
 */
- (NSString *)searchableWord;


/**
 返回在会话列表和本地通知中显示的消息内容摘要
 
 @return <#return value description#>
 */
- (NSString *)conversationDigest;


@end

NS_ASSUME_NONNULL_END
