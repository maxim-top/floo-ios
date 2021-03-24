//
//  PushServiceListener.h
//  MaxIM
//
//  Created by 韩雨桐 on 2020/8/21.
//  Copyright © 2020 hyt. All rights reserved.
//
#import <Foundation/Foundation.h>


#include "bmx_push_service_listener.h"
#import "BMXPushServiceProtocol.h"
#import "BMXDelegatesContainer.h"


namespace floosdk {
    
    class PushServiceListener : public floo::BMXPushServiceListener {
        
        
       
    public:
        

        /**
         * @brief Push初始化完成通知。
         * @param bmxToken 当前push使用bmxToken
         **/
        virtual void onPushStart(const std::string bmxToken) override;

        /**
         * @brief Push功能停止通知。
         **/
        virtual void onPushStop() override;

        /**
         * @brief Push初始化完成后获取推送证书。
         * @param cert 从服务器获取的推送证书
         **/
        virtual void onCertRetrieved(const std::string cert) override;

        /**
         * @brief 设置用户推送成功回调。
         * @param operationId 操作id
         **/
        virtual void onSetTags(const std::string& operationId) override;

        /**
         * @brief 获取用户推送成功回调。
         * @param operationId 操作id
         **/
        virtual void onGetTags(const std::string& operationId) override;

        /**
         * @brief 删除用户推送成功回调。
         * @param operationId 操作id
         **/
        virtual void onDeleteTags(const std::string& operationId) override;

        /**
         * @brief 清空用户推送成功回调。
         * @param operationId 操作id
         **/
        virtual void onClearTags(const std::string& operationId) override;

        /**
         * @brief 接收到新的Push通知。
         * @param list Push通知列表
         **/
        virtual void onReceivePush(const floo::BMXMessageList& list) override;

        /**
         * @brief 发送Push上行消息状态变化通知。
         * @param msg 发生状态变化的上行消息
         * @param error 状态错误码
         **/
        virtual void onStatusChanged(floo::BMXMessagePtr msg, floo::BMXErrorCode error) override;
                
        

        //delegate
            
        virtual void addDelegate(id<BMXPushServiceProtocol> delegate, dispatch_queue_t queue);
            
        virtual void removeDelegate(id<BMXPushServiceProtocol> delegate);
            
            
        BMXDelegatesContainer<BMXPushServiceProtocol> *container;
            //
        private:
            NSObject *containerLock;
        };

    
}
