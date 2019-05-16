/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcLoginImp.cpp
* Author:       甘业清
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

/********************************************************************************************
* Function:       RpcSelectCharacter
* Description:    登录模块-->选择角色同步调用操作函数
* Input:          LoginRpcSelectCharacterAskWraper& Ask 选择角色请求
* Output:         LoginRpcSelectCharacterReplyWraper& Reply 选择角色回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcSelectCharacter( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateCharacter
* Description:    登录模块-->创建角色同步调用操作函数
* Input:          LoginRpcCreateCharacterAskWraper& Ask 创建角色请求
* Output:         LoginRpcCreateCharacterReplyWraper& Reply 创建角色回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcCreateCharacter( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDeleteCharacter
* Description:    登录模块-->删除角色同步调用操作函数
* Input:          LoginRpcDeleteCharacterAskWraper& Ask 删除角色请求
* Output:         LoginRpcDeleteCharacterReplyWraper& Reply 删除角色回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcDeleteCharacter( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTest
* Description:    登录模块-->Test同步调用操作函数
* Input:          LoginRpcTestAskWraper& Ask Test请求
* Output:         LoginRpcTestReplyWraper& Reply Test回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcTest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTest1
* Description:    登录模块-->Test1同步调用操作函数
* Input:          LoginRpcTest1AskWraper& Ask Test1请求
* Output:         LoginRpcTest1ReplyWraper& Reply Test1回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleLogin::RpcTest1( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientLoginLineUp
* Description:    登录模块-->登录 排队通知异步通知操作函数
* Input:          LoginRpcLoginLineUpNotifyWraper& Notify 登录 排队通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleLogin::SendToClientLoginLineUp( INT64 UserId, LoginRpcLoginLineUpNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientLoginEnterGame
* Description:    登录模块-->可以登录服务器的通知异步通知操作函数
* Input:          LoginRpcLoginEnterGameNotifyWraper& Notify 可以登录服务器的通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleLogin::SendToClientLoginEnterGame( INT64 UserId, LoginRpcLoginEnterGameNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



