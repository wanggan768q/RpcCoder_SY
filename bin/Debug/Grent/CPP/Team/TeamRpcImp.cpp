/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcTeamImp.cpp
* Author:       郭晓波
* Description:  Team类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TeamModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcJoinTeam
* Description:    Team-->加入队伍同步调用操作函数
* Input:          TeamRpcJoinTeamAskWraper& Ask 加入队伍请求
* Output:         TeamRpcJoinTeamReplyWraper& Reply 加入队伍回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcJoinTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLeaveTeam
* Description:    Team-->LeaveTeam同步调用操作函数
* Input:          TeamRpcLeaveTeamAskWraper& Ask LeaveTeam请求
* Output:         TeamRpcLeaveTeamReplyWraper& Reply LeaveTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcLeaveTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAppointTeamLeader
* Description:    Team-->AppointTeamLeader同步调用操作函数
* Input:          TeamRpcAppointTeamLeaderAskWraper& Ask AppointTeamLeader请求
* Output:         TeamRpcAppointTeamLeaderReplyWraper& Reply AppointTeamLeader回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateTeam
* Description:    Team-->CreateTeam同步调用操作函数
* Input:          TeamRpcCreateTeamAskWraper& Ask 创建队伍创建副本请求
* Output:         TeamRpcCreateTeamReplyWraper& Reply 创建队伍创建副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcCreateTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDissmissTeam
* Description:    Team-->DissmissTeam同步调用操作函数
* Input:          TeamRpcDissmissTeamAskWraper& Ask DissmissTeam请求
* Output:         TeamRpcDissmissTeamReplyWraper& Reply DissmissTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcDissmissTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewLeader
* Description:    Team-->NewLeader异步通知操作函数
* Input:          TeamRpcNewLeaderNotifyWraper& Notify NewLeader通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientNewLeader( INT64 UserId, TeamRpcNewLeaderNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcKickMember
* Description:    Team-->KickMember同步调用操作函数
* Input:          TeamRpcKickMemberAskWraper& Ask KickMember请求
* Output:         TeamRpcKickMemberReplyWraper& Reply KickMember回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcKickMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDissmissTeamNotify
* Description:    Team-->DissmissTeamNotify异步通知操作函数
* Input:          TeamRpcDissmissTeamNotifyNotifyWraper& Notify DissmissTeamNotify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientDissmissTeamNotify( INT64 UserId, TeamRpcDissmissTeamNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientJoinTeamNotify
* Description:    Team-->JoinTeamNotify异步通知操作函数
* Input:          TeamRpcJoinTeamNotifyNotifyWraper& Notify JoinTeamNotify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientJoinTeamNotify( INT64 UserId, TeamRpcJoinTeamNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientKickMemberNotify
* Description:    Team-->KickMemberNotify异步通知操作函数
* Input:          TeamRpcKickMemberNotifyNotifyWraper& Notify KickMemberNotify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientKickMemberNotify( INT64 UserId, TeamRpcKickMemberNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientLeaveTeamNotify
* Description:    Team-->LeaveTeam异步通知操作函数
* Input:          TeamRpcLeaveTeamNotifyNotifyWraper& Notify LeaveTeam通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientLeaveTeamNotify( INT64 UserId, TeamRpcLeaveTeamNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSurroundingTeam
* Description:    Team-->SurroundingTeam同步调用操作函数
* Input:          TeamRpcSurroundingTeamAskWraper& Ask SurroundingTeam请求
* Output:         TeamRpcSurroundingTeamReplyWraper& Reply SurroundingTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcSurroundingTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcApplyTeam
* Description:    Team-->ApplyTeam同步调用操作函数
* Input:          TeamRpcApplyTeamAskWraper& Ask ApplyTeam请求
* Output:         TeamRpcApplyTeamReplyWraper& Reply ApplyTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcApplyTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientApplyTeamNotify
* Description:    Team-->ApplyTeamNotify异步通知操作函数
* Input:          TeamRpcApplyTeamNotifyNotifyWraper& Notify ApplyTeamNotify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientApplyTeamNotify( INT64 UserId, TeamRpcApplyTeamNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcAgreeApplicant
* Description:    Team-->AgreeApplicant同步调用操作函数
* Input:          TeamRpcAgreeApplicantAskWraper& Ask AgreeApplicant请求
* Output:         TeamRpcAgreeApplicantReplyWraper& Reply AgreeApplicant回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcAgreeApplicant( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientAgreeApplicantNotify
* Description:    Team-->AgreeApplicantNotify异步通知操作函数
* Input:          TeamRpcAgreeApplicantNotifyNotifyWraper& Notify AgreeApplicantNotify通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientAgreeApplicantNotify( INT64 UserId, TeamRpcAgreeApplicantNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientTeamInfo
* Description:    Team-->TeamInfo异步通知操作函数
* Input:          TeamRpcTeamInfoNotifyWraper& Notify TeamInfo通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientTeamInfo( INT64 UserId, TeamRpcTeamInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateTeamMemInfo
* Description:    Team-->UpdateTeamMemInfo异步通知操作函数
* Input:          TeamRpcUpdateTeamMemInfoNotifyWraper& Notify UpdateTeamMemInfo通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateTeamMemInfo( INT64 UserId, TeamRpcUpdateTeamMemInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



