/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcLoginImp.cpp
* Author:       郭晓波
* Description:  登录模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "LoginModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcConnect
* Description:    登录模块-->连接验证同步调用操作函数
* Input:          LoginRpcConnectAskWraper& Ask 连接验证请求
* Output:         LoginRpcConnectReplyWraper& Reply 连接验证回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcConnect( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLogin
* Description:    登录模块-->登录同步调用操作函数
* Input:          LoginRpcLoginAskWraper& Ask 登录请求
* Output:         LoginRpcLoginReplyWraper& Reply 登录回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcLogin( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



