/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcLobbyServerImp.cpp
* Author:       甘业清
* Description:  大厅服务器类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "LobbyServerModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcGetServerList
* Description:    大厅服务器-->获取服务器列表同步调用操作函数
* Input:          LobbyServerRpcGetServerListAskWraper& Ask 获取服务器列表请求
* Output:         LobbyServerRpcGetServerListReplyWraper& Reply 获取服务器列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLobbyServer::RpcGetServerList( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



