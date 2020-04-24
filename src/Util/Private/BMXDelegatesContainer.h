#import <Foundation/Foundation.h>

@class BMXMulticastDelegateEnumerator;

@interface BMXDelegatesContainer : NSObject

- (void)addDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate delegateQueue:(dispatch_queue_t)delegateQueue;
- (void)removeDelegate:(id)delegate;

- (void)removeAllDelegates;

- (NSUInteger)count;
- (NSUInteger)countOfClass:(Class)aClass;
- (NSUInteger)countForSelector:(SEL)aSelector;

- (BOOL)hasDelegateThatRespondsToSelector:(SEL)aSelector;

- (BMXMulticastDelegateEnumerator *)delegateEnumerator;

@end


@interface BMXMulticastDelegateEnumerator : NSObject

- (NSUInteger)count;
- (NSUInteger)countOfClass:(Class)aClass;
- (NSUInteger)countForSelector:(SEL)aSelector;

- (BOOL)getNextDelegate:(id *)delPtr delegateQueue:(dispatch_queue_t *)dqPtr;
- (BOOL)getNextDelegate:(id *)delPtr delegateQueue:(dispatch_queue_t *)dqPtr ofClass:(Class)aClass;
- (BOOL)getNextDelegate:(id *)delPtr delegateQueue:(dispatch_queue_t *)dqPtr forSelector:(SEL)aSelector;

@end
