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

/********************************************************************************************
* Function:       RpcCreateDungeon
* Description:    世界服务器模块-->创建副本通知同步调用操作函数
* Input:          WorldServerRpcCreateDungeonAskWraper& Ask 创建副本通知请求
* Output:         WorldServerRpcCreateDungeonReplyWraper& Reply 创建副本通知回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcCreateDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateTeam
* Description:    世界服务器模块-->CreateTeam同步调用操作函数
* Input:          WorldServerRpcCreateTeamAskWraper& Ask CreateTeam请求
* Output:         WorldServerRpcCreateTeamReplyWraper& Reply CreateTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcCreateTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcJoinTeam
* Description:    世界服务器模块-->JoinTeam同步调用操作函数
* Input:          WorldServerRpcJoinTeamAskWraper& Ask JoinTeam请求
* Output:         WorldServerRpcJoinTeamReplyWraper& Reply JoinTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcJoinTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLeaveTeam
* Description:    世界服务器模块-->LeaveTeam同步调用操作函数
* Input:          WorldServerRpcLeaveTeamAskWraper& Ask LeaveTeam请求
* Output:         WorldServerRpcLeaveTeamReplyWraper& Reply LeaveTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcLeaveTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAppointTeamLeader
* Description:    世界服务器模块-->AppointTeamLeader同步调用操作函数
* Input:          WorldServerRpcAppointTeamLeaderAskWraper& Ask AppointTeamLeader请求
* Output:         WorldServerRpcAppointTeamLeaderReplyWraper& Reply AppointTeamLeader回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDismissTeam
* Description:    世界服务器模块-->DismissTeam同步调用操作函数
* Input:          WorldServerRpcDismissTeamAskWraper& Ask DismissTeam请求
* Output:         WorldServerRpcDismissTeamReplyWraper& Reply DismissTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcDismissTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcKickMember
* Description:    世界服务器模块-->KickMember同步调用操作函数
* Input:          WorldServerRpcKickMemberAskWraper& Ask KickMember请求
* Output:         WorldServerRpcKickMemberReplyWraper& Reply KickMember回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcKickMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcApplyTeam
* Description:    世界服务器模块-->ApplyTeam同步调用操作函数
* Input:          WorldServerRpcApplyTeamAskWraper& Ask ApplyTeam请求
* Output:         WorldServerRpcApplyTeamReplyWraper& Reply ApplyTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcApplyTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAgreeTeamApplicant
* Description:    世界服务器模块-->AgreeTeamApplicant同步调用操作函数
* Input:          WorldServerRpcAgreeTeamApplicantAskWraper& Ask AgreeTeamApplicant请求
* Output:         WorldServerRpcAgreeTeamApplicantReplyWraper& Reply AgreeTeamApplicant回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcAgreeTeamApplicant( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLogin
* Description:    世界服务器模块-->Login同步调用操作函数
* Input:          WorldServerRpcLoginAskWraper& Ask Login请求
* Output:         WorldServerRpcLoginReplyWraper& Reply Login回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcLogin( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

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
* Function:       RpcLogout
* Description:    世界服务器模块-->Logout同步调用操作函数
* Input:          WorldServerRpcLogoutAskWraper& Ask Logout请求
* Output:         WorldServerRpcLogoutReplyWraper& Reply Logout回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcLogout( CPlayer* pPlayer, CPacket* pPacket)
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
* Function:       RpcReleaseDungeon
* Description:    世界服务器模块-->ReleaseDungeon同步调用操作函数
* Input:          WorldServerRpcReleaseDungeonAskWraper& Ask ReleaseDungeon请求
* Output:         WorldServerRpcReleaseDungeonReplyWraper& Reply ReleaseDungeon回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldServer::RpcReleaseDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



