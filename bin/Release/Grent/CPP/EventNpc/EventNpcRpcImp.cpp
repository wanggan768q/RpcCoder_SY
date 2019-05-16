/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcEventNpcImp.cpp
* Author:       甘业清
* Description:  可交互的怪 类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "EventNpcModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcBeginEvent
* Description:    可交互的怪 -->开始交互同步调用操作函数
* Input:          EventNpcRpcBeginEventAskWraper& Ask 开始交互请求
* Output:         EventNpcRpcBeginEventReplyWraper& Reply 开始交互回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEventNpc::RpcBeginEvent( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEndEvent
* Description:    可交互的怪 -->交互结束同步调用操作函数
* Input:          EventNpcRpcEndEventAskWraper& Ask 交互结束请求
* Output:         EventNpcRpcEndEventReplyWraper& Reply 交互结束回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEventNpc::RpcEndEvent( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientActivityBegin
* Description:    可交互的怪 -->活动开始异步通知操作函数
* Input:          EventNpcRpcActivityBeginNotifyWraper& Notify 活动开始通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEventNpc::SendToClientActivityBegin( INT64 UserId, EventNpcRpcActivityBeginNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



