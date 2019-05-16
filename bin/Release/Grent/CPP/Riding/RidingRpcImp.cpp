/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcRidingImp.cpp
* Author:       甘业清
* Description:  坐骑类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "RidingModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcRiding
* Description:    坐骑-->上马同步调用操作函数
* Input:          RidingRpcRidingAskWraper& Ask 上马请求
* Output:         RidingRpcRidingReplyWraper& Reply 上马回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleRiding::RpcRiding( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUnRiding
* Description:    坐骑-->下马同步调用操作函数
* Input:          RidingRpcUnRidingAskWraper& Ask 下马请求
* Output:         RidingRpcUnRidingReplyWraper& Reply 下马回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleRiding::RpcUnRiding( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



