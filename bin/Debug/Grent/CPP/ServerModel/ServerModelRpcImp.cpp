/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcServerModelImp.cpp
* Author:       郭晓波
* Description:  服务器内部模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ServerModelModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcLogin
* Description:    服务器内部模块-->服务器使用登录同步调用操作函数
* Input:          ServerModelRpcLoginAskWraper& Ask 服务器使用登录请求
* Output:         ServerModelRpcLoginReplyWraper& Reply 服务器使用登录回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleServerModel::RpcLogin( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



