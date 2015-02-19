#import <Foundation/Foundation.h>

@interface FBLogger : NSObject

@property (copy, nonatomic) NSString *contents;

@property (nonatomic, readonly) NSUInteger loggerSerialNumber;
@property (copy, nonatomic, readonly) NSString *loggingBehavior;  /*BP_LOG_BEHAVIOR* constants in BPSession.h*/
@property (nonatomic, readonly) BOOL isActive;

- (instancetype)initWithLoggingBehavior:(NSString *)loggingBehavior;    // 事例方法
- (void)appendString:(NSString *)string;
- (void)appendFormat:(NSString *)formatString, ... NS_FORMAT_FUNCTION(1,2);
- (void)appendKey:(NSString *)key value:(NSString *)value;
- (void)emitToNSLog;    // 发出登录信息，清除登录内容
+ (NSUInteger)newSerialNumber;                  //返回一个全局唯一SerialNumber用于关联多个输出相同的logger。 
+ (void)singleShotLogEntry:(NSString *)loggingBehavior      /*根据是否匹配上指定的行为写一个登录入口*/
                  logEntry:(NSString *)logEntry;
+ (void)singleShotLogEntry:(NSString *)loggingBehavior
              formatString:(NSString *)formatString, ... NS_FORMAT_FUNCTION(2,3);
+ (void)singleShotLogEntry:(NSString *)loggingBehavior
              timestampTag:(NSObject *)timestampTag
              formatString:(NSString *)formatString, ... NS_FORMAT_FUNCTION(3,4);
+ (void)registerCurrentTime:(NSString *)loggingBehavior     /*用current" time注册一个timestamp标签,然后由singleShotLogEntry检索*/
                    withTag:(NSObject *)timestampTag;
+ (void)registerStringToReplace:(NSString *)replace
                    replaceWith:(NSString *)replaceWith;
@end
