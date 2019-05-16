/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcMercenaryImp.cpp
* Author:       甘业清
* Description:  佣兵类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "MercenaryModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcInQueue
* Description:    佣兵-->入队同步调用操作函数
* Input:          MercenaryRpcInQueueAskWraper& Ask 入队请求
* Output:         MercenaryRpcInQueueReplyWraper& Reply 入队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMercenary::RpcInQueue( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcOutQueue
* Description:    佣兵-->出队同步调用操作函数
* Input:          MercenaryRpcOutQueueAskWraper& Ask 出队请求
* Output:         MercenaryRpcOutQueueReplyWraper& Reply 出队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMercenary::RpcOutQueue( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAutoSet
* Description:    佣兵-->自动配置同步调用操作函数
* Input:          MercenaryRpcAutoSetAskWraper& Ask 自动配置请求
* Output:         MercenaryRpcAutoSetReplyWraper& Reply 自动配置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMercenary::RpcAutoSet( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInfo
* Description:    佣兵-->请求佣兵信息同步调用操作函数
* Input:          MercenaryRpcInfoAskWraper& Ask 佣兵信息请求
* Output:         MercenaryRpcInfoReplyWraper& Reply 佣兵信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleMercenary::RpcInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



