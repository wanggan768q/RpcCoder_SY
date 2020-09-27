/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleChat.h
* Author:       郭晓波
* Description:  Chat类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_CHAT_H
#define __MODULE_CHAT_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "ChatRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//Chat实现类
class ModuleChat
{
	
public:
	//Chat类的枚举定义
	enum ConstChatE
	{
	MODULE_ID_CHAT                               = 13,	//Chat模块ID
	RPC_CODE_CHAT_CHAT_REQUEST                   = 1351,	//Chat-->Chat-->请求
	RPC_CODE_CHAT_PUSHCHATUPDATES_NOTIFY         = 1352,	//Chat-->PushChatUpdates-->通知
	RPC_CODE_CHAT_PUSHMARQUEE_NOTIFY             = 1353,	//Chat-->推送跑马灯-->通知
	RPC_CODE_CHAT_SAY_NOTIFY                     = 1354,	//Chat-->玩家或NPC对象说话-->通知
	RPC_CODE_CHAT_SERVERCHAT_NOTIFY              = 1355,	//Chat-->服务器通知-->通知

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//Chat实现类构造函数
	ModuleChat()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_CHAT_CHAT_REQUEST, &ModuleChat::RpcChat);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CHAT_CHAT_REQUEST, new Some_Factory<ChatRpcChatAsk>());

	}
	
	//Chat实现类析构函数
	~ModuleChat(){}


	static ModuleChat & Instance()
	{
		static ModuleChat sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
public:
	/********************************************************************************************
	* Function:       RpcChat
	* Description:    Chat-->Chat同步调用操作函数
	* Input:          ChatRpcChatAskWraper& Ask Chat请求
	* Output:         ChatRpcChatReplyWraper& Reply Chat回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChat( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientPushChatUpdates
	* Description:    Chat-->PushChatUpdates异步通知操作函数
	* Input:          ChatRpcPushChatUpdatesNotifyWraper& Notify PushChatUpdates通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPushChatUpdates( INT64 UserId, ChatRpcPushChatUpdatesNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientPushMarquee
	* Description:    Chat-->推送跑马灯异步通知操作函数
	* Input:          ChatRpcPushMarqueeNotifyWraper& Notify 推送跑马灯通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPushMarquee( INT64 UserId, ChatRpcPushMarqueeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSay
	* Description:    Chat-->玩家或NPC对象说话异步通知操作函数
	* Input:          ChatRpcSayNotifyWraper& Notify 玩家或NPC对象说话通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSay( INT64 UserId, ChatRpcSayNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientServerChat
	* Description:    Chat-->服务器通知异步通知操作函数
	* Input:          ChatRpcServerChatNotifyWraper& Notify 服务器通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientServerChat( INT64 UserId, ChatRpcServerChatNotifyWraper& Notify );


	reload_vec_type m_vReLoadCb;

};

#endif