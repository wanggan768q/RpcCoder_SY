/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcWorldServerImp.cpp
* Author:       甘业清
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
* Function:       RpcUpdateRoleInfo
* Description:    世界服务器模块-->UpdateRoleInfo同步调用操作函数
* Input:          WorldServerRpcUpdateRoleInfoAskWraper& Ask UpdateRoleInfo请求
* Output:         WorldServerRpcUpdateRoleInfoReplyWraper& Reply UpdateRoleInfo回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcUpdateRoleInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateDungeonNotify
* Description:    世界服务器模块-->CreateDungeonNotify同步调用操作函数
* Input:          WorldServerRpcCreateDungeonNotifyAskWraper& Ask CreateDungeonNotify请求
* Output:         WorldServerRpcCreateDungeonNotifyReplyWraper& Reply CreateDungeonNotify回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcCreateDungeonNotify( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcExitDungeon
* Description:    世界服务器模块-->ExitDungeon同步调用操作函数
* Input:          WorldServerRpcExitDungeonAskWraper& Ask ExitDungeon请求
* Output:         WorldServerRpcExitDungeonReplyWraper& Reply ExitDungeon回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcExitDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcUpdateTeamInfo
* Description:    世界服务器模块-->UpdateTeamInfo同步调用操作函数
* Input:          WorldServerRpcUpdateTeamInfoAskWraper& Ask UpdateTeamInfo请求
* Output:         WorldServerRpcUpdateTeamInfoReplyWraper& Reply UpdateTeamInfo回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcUpdateTeamInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcPlayCgTeam
* Description:    世界服务器模块-->播放动画 队伍同步调用操作函数
* Input:          WorldServerRpcPlayCgTeamAskWraper& Ask 播放动画 队伍请求
* Output:         WorldServerRpcPlayCgTeamReplyWraper& Reply 播放动画 队伍回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcPlayCgTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSendMail
* Description:    世界服务器模块-->发送邮件同步调用操作函数
* Input:          WorldServerRpcSendMailAskWraper& Ask 发送邮件请求
* Output:         WorldServerRpcSendMailReplyWraper& Reply 发送邮件回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcSendMail( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChangeTeamType
* Description:    世界服务器模块-->改变队伍类型同步调用操作函数
* Input:          WorldServerRpcChangeTeamTypeAskWraper& Ask 改变队伍类型请求
* Output:         WorldServerRpcChangeTeamTypeReplyWraper& Reply 改变队伍类型回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcChangeTeamType( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAutoMatch
* Description:    世界服务器模块-->自动匹配同步调用操作函数
* Input:          WorldServerRpcAutoMatchAskWraper& Ask 自动匹配请求
* Output:         WorldServerRpcAutoMatchReplyWraper& Reply 自动匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcAutoMatch( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCancelMatch
* Description:    世界服务器模块-->取消匹配同步调用操作函数
* Input:          WorldServerRpcCancelMatchAskWraper& Ask 取消匹配请求
* Output:         WorldServerRpcCancelMatchReplyWraper& Reply 取消匹配回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcCancelMatch( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLoginGameServer
* Description:    世界服务器模块-->登录服务器同步调用操作函数
* Input:          WorldServerRpcLoginGameServerAskWraper& Ask Login请求
* Output:         WorldServerRpcLoginGameServerReplyWraper& Reply 登录服务器回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcLoginGameServer( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLogoutGameServer
* Description:    世界服务器模块-->LoginGameServer同步调用操作函数
* Input:          WorldServerRpcLogoutGameServerAskWraper& Ask Login回应
* Output:         WorldServerRpcLogoutGameServerReplyWraper& Reply LoginGameServer回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcLogoutGameServer( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetPlayerInfo
* Description:    世界服务器模块-->获取玩家信息同步调用操作函数
* Input:          WorldServerRpcGetPlayerInfoAskWraper& Ask 获取玩家信息请求
* Output:         WorldServerRpcGetPlayerInfoReplyWraper& Reply 获取玩家信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcGetPlayerInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



