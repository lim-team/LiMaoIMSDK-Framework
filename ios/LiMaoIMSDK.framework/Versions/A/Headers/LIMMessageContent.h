//
//  LIMMessageContent.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMUserInfo.h"
#import <fmdb/FMDB.h>
@class LIMMessageContent;
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


///  初始化@提醒信息
/// @param type <#type description#>
- (instancetype)initWithMentionedType:(LIMMentionedType)type;
/*!
 初始化@提醒信息
 
 @param type       @提醒的类型
 @param uids @的用户ID列表
 
 @return @提醒信息的对象
 */
- (instancetype)initWithMentionedType:(LIMMentionedType)type
                                 uids:(NSArray *__nullable)uids;


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


/// 回复
@interface LIMReply : NSObject

@property(nonatomic,copy) NSString *messageID; // 被回复的消息ID
@property(nonatomic,assign) uint32_t messageSeq; // 被回复的消息seq

@property(nonatomic,copy) NSString *fromUID; // 被回复消息的发送者
@property(nonatomic,copy) NSString *fromName; // 被回复消息的发送者名称
@property(nonatomic,copy) NSString *rootMessageID; // 根消息ID（可为空）

@property(nonatomic,strong) LIMMessageContent *content; // 被回复的消息正文

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


/// 回复消息
@property(nonatomic,strong) LIMReply *reply;

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

// TODO: 解码消息只供DB使用（为了兼容MOS的@消息，因为@消息有DB操作 如果直接调用DB会与外面的DB发生冲突）
- (void)decode:(NSData *)data db:(FMDatabase*)db;

// 上层无序实现decode 实现此方法即可
-(void) decodeWithJSON:(NSDictionary*)contentDic;


/**
 你自定义的消息类型，在各个平台上需要保持一致
 @return 正文类型
 */
+(NSInteger) contentType;


/// 实际获取到的contentType （这种情况只会一个content对象被指定多个contentType的时候，可以通过这个属性获取到真实的contentType）
@property(nonatomic,assign,readonly) NSInteger realContentType;

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


/// 消息正文字典
@property(nonatomic,strong) NSDictionary *contentDict;

/**
 扩展字段
 */
@property(nonatomic,strong) NSMutableDictionary *extra;


@end

NS_ASSUME_NONNULL_END
