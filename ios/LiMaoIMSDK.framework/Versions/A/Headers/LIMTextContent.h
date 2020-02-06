//
//  LIMText.h
//  LiMaoIMSDK
//
//  Created by tt on 2019/11/29.
//

#import <Foundation/Foundation.h>
#import "LIMMessageContent.h"
NS_ASSUME_NONNULL_BEGIN

@interface LIMTextContent : LIMMessageContent

- (instancetype)initWithContent:(NSString*)content;

@property(nonatomic,copy) NSString *content;

@end

NS_ASSUME_NONNULL_END
