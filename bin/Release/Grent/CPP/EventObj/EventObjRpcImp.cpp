/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcEventObjImp.cpp
* Author:       甘业清
* Description:  EventObj类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "EventObjModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcEventBegin
* Description:    EventObj-->EventBegin同步调用操作函数
* Input:          EventObjRpcEventBeginAskWraper& Ask EventBegin请求
* Output:         EventObjRpcEventBeginReplyWraper& Reply EventBegin回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEventObj::RpcEventBegin( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEventEnd
* Description:    EventObj-->EventEnd同步调用操作函数
* Input:          EventObjRpcEventEndAskWraper& Ask EventEnd请求
* Output:         EventObjRpcEventEndReplyWraper& Reply EventEnd回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEventObj::RpcEventEnd( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEventStop
* Description:    EventObj-->EventStop同步调用操作函数
* Input:          EventObjRpcEventStopAskWraper& Ask EventStop请求
* Output:         EventObjRpcEventStopReplyWraper& Reply EventStop回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleEventObj::RpcEventStop( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientEventStopNotify
* Description:    EventObj-->交互停止通知异步通知操作函数
* Input:          EventObjRpcEventStopNotifyNotifyWraper& Notify 交互停止通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEventObj::SendToClientEventStopNotify( INT64 UserId, EventObjRpcEventStopNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



