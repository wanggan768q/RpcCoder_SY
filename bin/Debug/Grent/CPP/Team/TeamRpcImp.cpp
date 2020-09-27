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

/********************************************************************************************
* Function:       RpcFollowTeamLeader
* Description:    Team-->跟随队长同步调用操作函数
* Input:          TeamRpcFollowTeamLeaderAskWraper& Ask 跟随队长请求
* Output:         TeamRpcFollowTeamLeaderReplyWraper& Reply 跟随队长回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcFollowTeamLeader( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSummonMember
* Description:    Team-->召唤队员同步调用操作函数
* Input:          TeamRpcSummonMemberAskWraper& Ask 召唤队员请求
* Output:         TeamRpcSummonMemberReplyWraper& Reply 召唤队员回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcSummonMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSummonMemberNotify
* Description:    Team-->召唤队员异步通知操作函数
* Input:          TeamRpcSummonMemberNotifyNotifyWraper& Notify 召唤队员通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientSummonMemberNotify( INT64 UserId, TeamRpcSummonMemberNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcChangeTeamTarget
* Description:    Team-->改变队伍目标同步调用操作函数
* Input:          TeamRpcChangeTeamTargetAskWraper& Ask 改变队伍目标
* Output:         TeamRpcChangeTeamTargetReplyWraper& Reply 改变队伍目标
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcChangeTeamTarget( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientChangeTeamTargetNotify
* Description:    Team-->设置服务器目标异步通知操作函数
* Input:          TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify 设置服务器目标通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientChangeTeamTargetNotify( INT64 UserId, TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcChangTeamType
* Description:    Team-->转换队伍团队同步调用操作函数
* Input:          TeamRpcChangTeamTypeAskWraper& Ask 转换队伍团队请求
* Output:         TeamRpcChangTeamTypeReplyWraper& Reply 转换队伍团队回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcChangTeamType( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientChangeTeamTypeNotify
* Description:    Team-->转换队伍团队协议异步通知操作函数
* Input:          TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify 转换队伍团队协议通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientChangeTeamTypeNotify( INT64 UserId, TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcInviteTeamMember
* Description:    Team-->邀请玩家同步调用操作函数
* Input:          TeamRpcInviteTeamMemberAskWraper& Ask 邀请玩家请求
* Output:         TeamRpcInviteTeamMemberReplyWraper& Reply 邀请玩家回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcInviteTeamMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientInviteTeamMemberNotify
* Description:    Team-->邀请玩家广播异步通知操作函数
* Input:          TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify 邀请玩家广播通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientInviteTeamMemberNotify( INT64 UserId, TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientApplyListNotify
* Description:    Team-->列表通知异步通知操作函数
* Input:          TeamRpcApplyListNotifyNotifyWraper& Notify 列表通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientApplyListNotify( INT64 UserId, TeamRpcApplyListNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcAgreeJoinTeam
* Description:    Team-->AgreeJoinTeam同步调用操作函数
* Input:          TeamRpcAgreeJoinTeamAskWraper& Ask AgreeJoinTeam请求
* Output:         TeamRpcAgreeJoinTeamReplyWraper& Reply AgreeJoinTeam回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcAgreeJoinTeam( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRefuseMember
* Description:    Team-->拒绝申请同步调用操作函数
* Input:          TeamRpcRefuseMemberAskWraper& Ask 拒绝申请请求
* Output:         TeamRpcRefuseMemberReplyWraper& Reply 拒绝申请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcRefuseMember( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcClearApplyList
* Description:    Team-->清空申请列表同步调用操作函数
* Input:          TeamRpcClearApplyListAskWraper& Ask 清空申请列表请求
* Output:         TeamRpcClearApplyListReplyWraper& Reply 清空申请列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcClearApplyList( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcNoTeamInvite
* Description:    Team-->没有队伍邀请玩家同步调用操作函数
* Input:          TeamRpcNoTeamInviteAskWraper& Ask 没有队伍邀请玩家请求
* Output:         TeamRpcNoTeamInviteReplyWraper& Reply 没有队伍邀请玩家回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcNoTeamInvite( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRejectInvite
* Description:    Team-->拒绝邀请同步调用操作函数
* Input:          TeamRpcRejectInviteAskWraper& Ask 拒绝邀请请求
* Output:         TeamRpcRejectInviteReplyWraper& Reply 拒绝邀请回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcRejectInvite( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientEnterAutoCombat
* Description:    Team-->进入自动战斗状态异步通知操作函数
* Input:          TeamRpcEnterAutoCombatNotifyWraper& Notify 进入自动战斗状态通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientEnterAutoCombat( INT64 UserId, TeamRpcEnterAutoCombatNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientHangUpAutoCombat
* Description:    Team-->挂起自动战斗异步通知操作函数
* Input:          TeamRpcHangUpAutoCombatNotifyWraper& Notify 挂起自动战斗通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientHangUpAutoCombat( INT64 UserId, TeamRpcHangUpAutoCombatNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateTeamHpInfo
* Description:    Team-->更新队伍快速刷新Hp异步通知操作函数
* Input:          TeamRpcUpdateTeamHpInfoNotifyWraper& Notify 更新队伍快速刷新Hp通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateTeamHpInfo( INT64 UserId, TeamRpcUpdateTeamHpInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateTeamPosInfo
* Description:    Team-->更新队伍成员信息异步通知操作函数
* Input:          TeamRpcUpdateTeamPosInfoNotifyWraper& Notify 更新队伍成员信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateTeamPosInfo( INT64 UserId, TeamRpcUpdateTeamPosInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateTeamBuffInfo
* Description:    Team-->更新队伍bufflist异步通知操作函数
* Input:          TeamRpcUpdateTeamBuffInfoNotifyWraper& Notify 更新队伍bufflist通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateTeamBuffInfo( INT64 UserId, TeamRpcUpdateTeamBuffInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcHangeUpFollow
* Description:    Team-->暂停跟随同步调用操作函数
* Input:          TeamRpcHangeUpFollowAskWraper& Ask 暂停跟随请求
* Output:         TeamRpcHangeUpFollowReplyWraper& Reply 暂停跟随回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcHangeUpFollow( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGoOnFollow
* Description:    Team-->继续跟随同步调用操作函数
* Input:          TeamRpcGoOnFollowAskWraper& Ask 继续跟随请求
* Output:         TeamRpcGoOnFollowReplyWraper& Reply 继续跟随回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcGoOnFollow( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientUpdateFollowStatus
* Description:    Team-->更新跟随状态异步通知操作函数
* Input:          TeamRpcUpdateFollowStatusNotifyWraper& Notify 更新跟随状态通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientUpdateFollowStatus( INT64 UserId, TeamRpcUpdateFollowStatusNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcRequestNoTeamMemberList
* Description:    Team-->请求玩家列表同步调用操作函数
* Input:          TeamRpcRequestNoTeamMemberListAskWraper& Ask 请求玩家列表请求
* Output:         TeamRpcRequestNoTeamMemberListReplyWraper& Reply 请求玩家列表回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcRequestNoTeamMemberList( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientEnterTeamFollow
* Description:    Team-->你加入了一支副本队伍，是否开启组队跟随功能，自动传送入队长所在副本异步通知操作函数
* Input:          TeamRpcEnterTeamFollowNotifyWraper& Notify 你加入了一支副本队伍，是否开启组队跟随功能，自动传送入队长所在副本通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTeam::SendToClientEnterTeamFollow( INT64 UserId, TeamRpcEnterTeamFollowNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcEnterLeaderScene
* Description:    Team-->进入队长场景同步调用操作函数
* Input:          TeamRpcEnterLeaderSceneAskWraper& Ask 进入队长场景请求
* Output:         TeamRpcEnterLeaderSceneReplyWraper& Reply 进入队长场景回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTeam::RpcEnterLeaderScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



