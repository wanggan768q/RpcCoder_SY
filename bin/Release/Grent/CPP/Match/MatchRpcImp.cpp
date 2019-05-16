/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMatchImp.cpp
* Author:       甘业清
* Description:  匹配模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "MatchModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcAutoMatch
* Description:    匹配模块-->匹配同步调用操作函数
* Input:          MatchRpcAutoMatchAskWraper& Ask 匹配请求
* Output:         MatchRpcAutoMatchReplyWraper& Reply 匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMatch::RpcAutoMatch( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCancelMatch
* Description:    匹配模块-->取消匹配同步调用操作函数
* Input:          MatchRpcCancelMatchAskWraper& Ask 取消匹配请求
* Output:         MatchRpcCancelMatchReplyWraper& Reply 取消匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMatch::RpcCancelMatch( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCancelMatchNotify
* Description:    匹配模块-->取消匹配通知异步通知操作函数
* Input:          MatchRpcCancelMatchNotifyNotifyWraper& Notify 取消匹配通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatch::SendToClientCancelMatchNotify( INT64 UserId, MatchRpcCancelMatchNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientPrepareRoom
* Description:    匹配模块-->开始准备进入房间异步通知操作函数
* Input:          MatchRpcPrepareRoomNotifyWraper& Notify 开始准备进入房间通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatch::SendToClientPrepareRoom( INT64 UserId, MatchRpcPrepareRoomNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReady
* Description:    匹配模块-->准备同步调用操作函数
* Input:          MatchRpcReadyAskWraper& Ask 准备请求
* Output:         MatchRpcReadyReplyWraper& Reply 准备回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMatch::RpcReady( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCancelReady
* Description:    匹配模块-->取消准备同步调用操作函数
* Input:          MatchRpcCancelReadyAskWraper& Ask 取消准备请求
* Output:         MatchRpcCancelReadyReplyWraper& Reply 取消准备回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMatch::RpcCancelReady( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRoomCancel
* Description:    匹配模块-->房间取消异步通知操作函数
* Input:          MatchRpcRoomCancelNotifyWraper& Notify 房间取消通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatch::SendToClientRoomCancel( INT64 UserId, MatchRpcRoomCancelNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientMemberReady
* Description:    匹配模块-->成员准备异步通知操作函数
* Input:          MatchRpcMemberReadyNotifyWraper& Notify 成员准备通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleMatch::SendToClientMemberReady( INT64 UserId, MatchRpcMemberReadyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



