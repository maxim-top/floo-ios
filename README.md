# 蓝莺IM SDK，iOS本地库

蓝莺IM，是由[美信拓扑](https://www.maximtop.com/)团队研发的新一代即时通讯云服务，SDK设计简单集成方便，服务采用云原生技术和多云架构，私有云也可按月付费。

蓝莺IM SDK（代号 floo）底层使用 C++ 实现，各平台（Android、iOS、Linux等）在此基础上进行封装成本地库，以达到多平台复用的目的，并保持跨平台协议实现的一致性。

[![Scc Count Badge](https://sloc.xyz/github/maxim-top/floo-ios/?category=total&avg-wage=1)](https://github.com/maxim-top/floo-ios/) [![Scc Count Badge](https://sloc.xyz/github/maxim-top/floo-ios/?category=code&avg-wage=1)](https://github.com/maxim-top/floo-ios/)

## 介绍

整个类库库分为三部分：

1. 低级 API（Low-Level / 同步调用 / 以Service结尾）

主要有 BMXUserService、BMXChatService、BMXRosterService、BMXGroupService，会直接转调底层 C++ Service。

2. 高级 API（High-Level / 异步调用 / 以Manager结尾）

主要有 BMXUserManager、BMXChatManager、BMXRosterManager、BMXGroupManager。

3. 工具类 Utility

包括 BMXClient、BMXSDKConfig、BMXMessage、BMXConversation、BMXUserProfile、BMXGroup、BMXDevice等。

快速集成文档参考[蓝莺快速集成指南iOS版](https://docs.maximtop.com/quick-start/floo-ios-quick-start.html)，
详细文档可参考[floo-ios reference](https://docs.maximtop.com/reference/floo-ios.html)

祝玩得开心😊
