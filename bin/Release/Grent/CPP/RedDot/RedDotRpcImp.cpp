/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcRedDotImp.cpp
* Author:       甘业清
* Description:  红点系统类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "RedDotModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncRedDot
* Description:    红点系统-->同步同步调用操作函数
* Input:          RedDotRpcSyncRedDotAskWraper& Ask 同步请求
* Output:         RedDotRpcSyncRedDotReplyWraper& Reply 同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleRedDot::RpcSyncRedDot( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRemoveRedDot
* Description:    红点系统-->删除红点同步调用操作函数
* Input:          RedDotRpcRemoveRedDotAskWraper& Ask 删除红点请求
* Output:         RedDotRpcRemoveRedDotReplyWraper& Reply 删除红点回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleRedDot::RpcRemoveRedDot( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUpdateRedDot
* Description:    红点系统-->更新异步通知操作函数
* Input:          RedDotRpcUpdateRedDotNotifyWraper& Notify 更新通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleRedDot::SendToClientUpdateRedDot( INT64 UserId, RedDotRpcUpdateRedDotNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



