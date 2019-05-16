/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcChatImp.cpp
* Author:       甘业清
* Description:  Chat类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ChatModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcChat
* Description:    Chat-->Chat同步调用操作函数
* Input:          ChatRpcChatAskWraper& Ask Chat请求
* Output:         ChatRpcChatReplyWraper& Reply Chat回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleChat::RpcChat( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientPushChatUpdates
* Description:    Chat-->PushChatUpdates异步通知操作函数
* Input:          ChatRpcPushChatUpdatesNotifyWraper& Notify PushChatUpdates通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientPushChatUpdates( INT64 UserId, ChatRpcPushChatUpdatesNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientPushMarquee
* Description:    Chat-->推送跑马灯异步通知操作函数
* Input:          ChatRpcPushMarqueeNotifyWraper& Notify 推送跑马灯通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientPushMarquee( INT64 UserId, ChatRpcPushMarqueeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientSay
* Description:    Chat-->玩家或NPC对象说话异步通知操作函数
* Input:          ChatRpcSayNotifyWraper& Notify 玩家或NPC对象说话通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleChat::SendToClientSay( INT64 UserId, ChatRpcSayNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



