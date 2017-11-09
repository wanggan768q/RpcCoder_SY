/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcWorldServerImp.cpp
* Author:       郭晓波
* Description:  世界服务器模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "WorldServerModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcChangeScene
* Description:    世界服务器模块-->通知世界服务器切换场景同步调用操作函数
* Input:          WorldServerRpcChangeSceneAskWraper& Ask 通知世界服务器切换场景请求
* Output:         WorldServerRpcChangeSceneReplyWraper& Reply 通知世界服务器切换场景回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcChangeScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEnterScene
* Description:    世界服务器模块-->进入场景同步调用操作函数
* Input:          WorldServerRpcEnterSceneAskWraper& Ask 进入场景请求
* Output:         WorldServerRpcEnterSceneReplyWraper& Reply 进入场景回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcEnterScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



