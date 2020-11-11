//
//  LIMConst.h
//  Pods
//
//  Created by tt on 2019/11/25.
//



// 正文类型
typedef enum : NSUInteger {
    LIM_TEXT = 1, // 文本消息
    LIM_IMAGE = 2, // 图片消息
    LIM_GIF = 3, // gif表情
    LIM_VOICE = 4, // 语音消息
    LIM_CMD = 99, // 命令消息
    LIM_UNKNOWN = 0, // 未知消息
} LIMContentType;



// 消息状态
typedef enum : NSUInteger {
    LIM_MESSAGE_WAITSEND, // 等待发送
    LIM_MESSAGE_SUCCESS, // 发送成功
    LIM_MESSAGE_ONLYSAVE, // 仅仅保存消息（不做重发处理）
    LIM_MESSAGE_UPLOADING, // 上传中
    LIM_MESSAGE_FAIL, // 发送失败
} LIMMessageStatus;


typedef enum : uint8_t {
    NONE,
    LIM_CONNECT = 1, // 客户端请求连接到服务器(c2s)
    LIM_CONNACK =2, //  服务端收到连接请求后确认的报文(s2c)
    LIM_SEND = 3, // 发送消息(c2s)
    LIM_SENDACK = 4,  // 收到消息确认的报文(s2c)
    LIM_RECV = 5,   //收取消息(s2c)
    LIM_RECVACK = 6, // 收取消息确认(c2s)
    LIM_PING = 7, //ping请求
    LIM_PONG = 8, // 对ping请求的相应
    LIM_DISCONNECT = 9 // 断开连接
} LIMPacketType;


typedef enum : uint8_t {
    ERROR,
    SUCCESS = 1, // 认证成功
    AUTHFAIL = 2, // 认证失败（一般是token不正确）
} LIMReason;

// 频道类型
typedef enum : uint8_t {
    LIM_PERSON = 1, // 个人
    LIM_GROUP = 2 // 群组
} LIMChannelType;

// 协议类型
typedef enum : NSUInteger {
    LIM_PROTO_LIMAO,
    LIM_PROTO_MOS
} LIMProto;


// 排序序号因子
#define LIMOrderSeqFactor 1000
