/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcWGImp.cpp
* Author:       郭晓波
* Description:  WG类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "WGModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcInformCreateTeam
* Description:    WG-->InformCreateTeam同步调用操作函数
* Input:          WGRpcInformCreateTeamAskWraper& Ask InformCreateTeam请求
* Output:         WGRpcInformCreateTeamReplyWraper& Reply InformCreateTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformCreateTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformJoinTeam
* Description:    WG-->InformJoinTeam同步调用操作函数
* Input:          WGRpcInformJoinTeamAskWraper& Ask InformJoinTeam请求
* Output:         WGRpcInformJoinTeamReplyWraper& Reply InformJoinTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformJoinTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformLeave
* Description:    WG-->InformLeave同步调用操作函数
* Input:          WGRpcInformLeaveAskWraper& Ask InformLeave请求
* Output:         WGRpcInformLeaveReplyWraper& Reply InformLeave回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformLeave( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformAppointTeamLeader
* Description:    WG-->InformAppointTeamLeader同步调用操作函数
* Input:          WGRpcInformAppointTeamLeaderAskWraper& Ask InformAppointTeamLeader请求
* Output:         WGRpcInformAppointTeamLeaderReplyWraper& Reply InformAppointTeamLeader回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformKickTeamMember
* Description:    WG-->InformKickTeamMember同步调用操作函数
* Input:          WGRpcInformKickTeamMemberAskWraper& Ask InformKickTeamMember请求
* Output:         WGRpcInformKickTeamMemberReplyWraper& Reply InformKickTeamMember回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformKickTeamMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformDissmissTeam
* Description:    WG-->InformDissmissTeam同步调用操作函数
* Input:          WGRpcInformDissmissTeamAskWraper& Ask InformDissmissTeam请求
* Output:         WGRpcInformDissmissTeamReplyWraper& Reply InformDissmissTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformDissmissTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformApplyTeam
* Description:    WG-->InformApply同步调用操作函数
* Input:          WGRpcInformApplyTeamAskWraper& Ask InformApply请求
* Output:         WGRpcInformApplyTeamReplyWraper& Reply InformApply回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformApplyTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAgreeTeamApplicant
* Description:    WG-->AgreeTeamApplicant同步调用操作函数
* Input:          WGRpcAgreeTeamApplicantAskWraper& Ask AgreeTeamApplicant请求
* Output:         WGRpcAgreeTeamApplicantReplyWraper& Reply AgreeTeamApplicant回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcAgreeTeamApplicant( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformLogin
* Description:    WG-->InformLogin同步调用操作函数
* Input:          WGRpcInformLoginAskWraper& Ask InformLogin请求
* Output:         WGRpcInformLoginReplyWraper& Reply InformLogin回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWG::RpcInformLogin( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



