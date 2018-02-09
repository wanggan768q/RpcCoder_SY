/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcBaseAttrImp.cpp
* Author:       郭晓波
* Description:  基础数据类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "BaseAttrModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncData
* Description:    基础数据-->同步玩家数据同步调用操作函数
* Input:          BaseAttrRpcSyncDataAskWraper& Ask 同步玩家数据请求
* Output:         BaseAttrRpcSyncDataReplyWraper& Reply 同步玩家数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBaseAttr::RpcSyncData( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSync
* Description:    基础数据-->数据推送异步通知操作函数
* Input:          BaseAttrRpcSyncNotifyWraper& Notify 数据推送通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleBaseAttr::SendToClientSync( INT64 UserId, BaseAttrRpcSyncNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



