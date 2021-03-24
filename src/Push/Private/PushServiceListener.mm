//
//  PushServiceListener.m
//  MaxIM
//
//  Created by 韩雨桐 on 2020/8/21.
//  Copyright © 2020 hyt. All rights reserved.
//

#import "PushServiceListener.h"
#import "BMXStringUtil.h"
#import "BMXMessageObject+Private.h"
#import "BMXError+Private.h"

namespace floosdk {
            

        /**
         * @brief Push初始化完成通知。
         * @param bmxToken 当前push使用bmxToken
         **/
        void PushServiceListener ::  onPushStart(const std::string bmxToken) {
            if (container) {
                [container pushStartDidFinished:[BMXStringUtil stdToNSString:bmxToken]];
            }
        }

        /**
         * @brief Push功能停止通知。
         **/
        void PushServiceListener ::  onPushStop() {
            if (container) {
                [container pushStartDidStopped];
            }
        }

        /**
         * @brief Push初始化完成后获取推送证书。
         * @param cert 从服务器获取的推送证书
         **/
        void PushServiceListener ::  onCertRetrieved(const std::string cert) {
            if (container) {
                [container certRetrieved:[BMXStringUtil stdToNSString:cert]];
            }
        }

        /**
         * @brief 设置用户推送成功回调。
         * @param operationId 操作id
         **/
        void PushServiceListener ::  onSetTags(const std::string& operationId) {
            if (container) {
                [container setTagsDidFinished:[BMXStringUtil stdToNSString:operationId]];
            }
        }

        /**
         * @brief 获取用户推送成功回调。
         * @param operationId 操作id
         **/
        void PushServiceListener ::  onGetTags(const std::string& operationId) {
            if (container) {
                [container getTagsDidFinished:[BMXStringUtil stdToNSString:operationId]];
            }
        }

        /**
         * @brief 删除用户推送成功回调。
         * @param operationId 操作id
         **/
        void PushServiceListener ::  onDeleteTags(const std::string& operationId) {
            if (container ) {
                [container deleteTagsDidFinished:[BMXStringUtil stdToNSString:operationId]];
            }
        }

        /**
         * @brief 清空用户推送成功回调。
         * @param operationId 操作id
         **/
        void PushServiceListener ::  onClearTags(const std::string& operationId) {
            if (container) {
                [container clearedTags:[BMXStringUtil stdToNSString:operationId]];
            }
        }

        /**
         * @brief 接收到新的Push通知。
         * @param list Push通知列表
         **/
        void PushServiceListener ::  onReceivePush(const floo::BMXMessageList& list) {
            if (container && list.size()) {
                NSMutableArray *messages = [NSMutableArray array];
                floo::BMXMessageList::const_iterator ite = list.begin();
                for (; ite != list.end(); ++ite) {
                    if ((*ite).get() != nullptr) {
                        
                        BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:*ite];
                        [messages addObject:message];
                    }
                }
                [container receivedPush:messages];
            }
        }

        /**
         * @brief 发送Push上行消息状态变化通知。
         * @param msg 发生状态变化的上行消息
         * @param error 状态错误码
         **/
        void PushServiceListener ::  onStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error) {
            BMXMessageObject *message = [[BMXMessageObject alloc] initWithMessagePtr:msg];
            if (container) {
                [container pushMessageStatusChanged:message error:[
                                                                   BMXError bmx_ErrorWith:error]];
            }
        }
                
        

        //delegate
            
        void PushServiceListener ::  addDelegate(id<BMXPushServiceProtocol> delegate, dispatch_queue_t queue) {
            if (!container) {
                container = [(BMXDelegatesContainer<BMXPushServiceProtocol> *)[BMXDelegatesContainer alloc] init];
            }
            
            if (!containerLock) {
                containerLock = [[NSObject alloc] init];
            }
            
            if (delegate) {
                if (!queue) {
                    queue = dispatch_get_main_queue();
                }
                
                @synchronized (containerLock) {
                    [container addDelegate:delegate delegateQueue:queue];
                }
            }
    
    
        }
            
        void PushServiceListener ::  removeDelegate(id<BMXPushServiceProtocol> delegate) {
    
                if (container && delegate) {
                    if (!containerLock) {
                        containerLock = [[NSObject alloc] init];
                    }
                    
                    @synchronized (containerLock) {
                        [container removeDelegate:delegate];
                    }
                    
                }
            }
            
            
        
}
