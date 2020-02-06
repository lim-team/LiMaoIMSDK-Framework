//
//  LIMData.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/25.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface LIMDataWrite : NSObject

-(void) writeUint8:(uint8_t)v;

-(void) writeUint16:(uint16_t)v;

-(void) writeUint32:(uint32_t)v;

-(void) writeUint64:(uint64_t)v;

-(void) writeString:(NSString*)v;

-(void) writeData:(NSData*) data;


-(NSData*) toData;
@end

@interface LIMDataRead : NSObject

-(instancetype) initWithData:(NSData*) data;

-(uint8_t) readUint8;

-(uint16_t) readUint16;

-(uint32_t) readUint32;

-(uint64_t) readUint64;

-(int64_t) readint64;

-(NSString*) readString;

-(uint32_t) readLenth;
// 字节里是否包含完整的长度
-(BOOL) lengthFull;
// 长度的长度
-(int) lenthLength;
-(NSData*) remainingData;

@end

void numberHNMemcpy(void *dest, const void *src, unsigned int count);
NS_ASSUME_NONNULL_END
