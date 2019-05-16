/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcExpressionActionImp.cpp
* Author:       甘业清
* Description:  表情动作类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ExpressionActionModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSync
* Description:    表情动作-->数据同步同步调用操作函数
* Input:          ExpressionActionRpcSyncAskWraper& Ask 数据同步请求
* Output:         ExpressionActionRpcSyncReplyWraper& Reply 数据同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleExpressionAction::RpcSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSetWheel
* Description:    表情动作-->设置轮盘同步调用操作函数
* Input:          ExpressionActionRpcSetWheelAskWraper& Ask 设置轮盘请求
* Output:         ExpressionActionRpcSetWheelReplyWraper& Reply 设置轮盘回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleExpressionAction::RpcSetWheel( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUseAction
* Description:    表情动作-->使用表情同步调用操作函数
* Input:          ExpressionActionRpcUseActionAskWraper& Ask 使用表情请求
* Output:         ExpressionActionRpcUseActionReplyWraper& Reply 使用表情回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleExpressionAction::RpcUseAction( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUseActionNotify
* Description:    表情动作-->使用表情通知异步通知操作函数
* Input:          ExpressionActionRpcUseActionNotifyNotifyWraper& Notify 使用表情通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleExpressionAction::SendToClientUseActionNotify( INT64 UserId, ExpressionActionRpcUseActionNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



