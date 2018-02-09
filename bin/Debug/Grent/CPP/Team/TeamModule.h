/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleTeam.h
* Author:       郭晓波
* Description:  Team类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_TEAM_H
#define __MODULE_TEAM_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "TeamRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//Team实现类
class ModuleTeam
{
	
public:
	//Team类的枚举定义
	enum ConstTeamE
	{
	MODULE_ID_TEAM                               = 10,	//Team模块ID
	RPC_CODE_TEAM_JOINTEAM_REQUEST               = 1051,	//Team-->加入队伍-->请求
	RPC_CODE_TEAM_LEAVETEAM_REQUEST              = 1052,	//Team-->LeaveTeam-->请求
	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST      = 1053,	//Team-->AppointTeamLeader-->请求
	RPC_CODE_TEAM_CREATETEAM_REQUEST             = 1054,	//Team-->CreateTeam-->请求
	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST           = 1055,	//Team-->DissmissTeam-->请求
	RPC_CODE_TEAM_NEWLEADER_NOTIFY               = 1056,	//Team-->NewLeader-->通知
	RPC_CODE_TEAM_KICKMEMBER_REQUEST             = 1057,	//Team-->KickMember-->请求
	RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY      = 1058,	//Team-->DissmissTeamNotify-->通知
	RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY          = 1059,	//Team-->JoinTeamNotify-->通知
	RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY        = 1060,	//Team-->KickMemberNotify-->通知
	RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY         = 1061,	//Team-->LeaveTeam-->通知
	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST        = 1062,	//Team-->SurroundingTeam-->请求
	RPC_CODE_TEAM_APPLYTEAM_REQUEST              = 1063,	//Team-->ApplyTeam-->请求
	RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY         = 1064,	//Team-->ApplyTeamNotify-->通知
	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST         = 1065,	//Team-->AgreeApplicant-->请求
	RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY    = 1066,	//Team-->AgreeApplicantNotify-->通知
	RPC_CODE_TEAM_TEAMINFO_NOTIFY                = 1067,	//Team-->TeamInfo-->通知
	RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY       = 1068,	//Team-->UpdateTeamMemInfo-->通知

	};

public:
	//Team实现类构造函数
	ModuleTeam()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_JOINTEAM_REQUEST, &ModuleTeam::RpcJoinTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_JOINTEAM_REQUEST, new Some_Factory<TeamRpcJoinTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_LEAVETEAM_REQUEST, &ModuleTeam::RpcLeaveTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_LEAVETEAM_REQUEST, new Some_Factory<TeamRpcLeaveTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST, &ModuleTeam::RpcAppointTeamLeader);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST, new Some_Factory<TeamRpcAppointTeamLeaderAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_CREATETEAM_REQUEST, &ModuleTeam::RpcCreateTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_CREATETEAM_REQUEST, new Some_Factory<TeamRpcCreateTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST, &ModuleTeam::RpcDissmissTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST, new Some_Factory<TeamRpcDissmissTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_KICKMEMBER_REQUEST, &ModuleTeam::RpcKickMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_KICKMEMBER_REQUEST, new Some_Factory<TeamRpcKickMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST, &ModuleTeam::RpcSurroundingTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST, new Some_Factory<TeamRpcSurroundingTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_APPLYTEAM_REQUEST, &ModuleTeam::RpcApplyTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_APPLYTEAM_REQUEST, new Some_Factory<TeamRpcApplyTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST, &ModuleTeam::RpcAgreeApplicant);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST, new Some_Factory<TeamRpcAgreeApplicantAsk>());

	}
	
	//Team实现类析构函数
	~ModuleTeam(){}


	static ModuleTeam Instance()
	{
		static ModuleTeam sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcJoinTeam
	* Description:    Team-->加入队伍同步调用操作函数
	* Input:          TeamRpcJoinTeamAskWraper& Ask 加入队伍请求
	* Output:         TeamRpcJoinTeamReplyWraper& Reply 加入队伍回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcJoinTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLeaveTeam
	* Description:    Team-->LeaveTeam同步调用操作函数
	* Input:          TeamRpcLeaveTeamAskWraper& Ask LeaveTeam请求
	* Output:         TeamRpcLeaveTeamReplyWraper& Reply LeaveTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLeaveTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAppointTeamLeader
	* Description:    Team-->AppointTeamLeader同步调用操作函数
	* Input:          TeamRpcAppointTeamLeaderAskWraper& Ask AppointTeamLeader请求
	* Output:         TeamRpcAppointTeamLeaderReplyWraper& Reply AppointTeamLeader回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateTeam
	* Description:    Team-->CreateTeam同步调用操作函数
	* Input:          TeamRpcCreateTeamAskWraper& Ask 创建队伍创建副本请求
	* Output:         TeamRpcCreateTeamReplyWraper& Reply 创建队伍创建副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDissmissTeam
	* Description:    Team-->DissmissTeam同步调用操作函数
	* Input:          TeamRpcDissmissTeamAskWraper& Ask DissmissTeam请求
	* Output:         TeamRpcDissmissTeamReplyWraper& Reply DissmissTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDissmissTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewLeader
	* Description:    Team-->NewLeader异步通知操作函数
	* Input:          TeamRpcNewLeaderNotifyWraper& Notify NewLeader通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewLeader( INT64 UserId, TeamRpcNewLeaderNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcKickMember
	* Description:    Team-->KickMember同步调用操作函数
	* Input:          TeamRpcKickMemberAskWraper& Ask KickMember请求
	* Output:         TeamRpcKickMemberReplyWraper& Reply KickMember回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcKickMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDissmissTeamNotify
	* Description:    Team-->DissmissTeamNotify异步通知操作函数
	* Input:          TeamRpcDissmissTeamNotifyNotifyWraper& Notify DissmissTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDissmissTeamNotify( INT64 UserId, TeamRpcDissmissTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientJoinTeamNotify
	* Description:    Team-->JoinTeamNotify异步通知操作函数
	* Input:          TeamRpcJoinTeamNotifyNotifyWraper& Notify JoinTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientJoinTeamNotify( INT64 UserId, TeamRpcJoinTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientKickMemberNotify
	* Description:    Team-->KickMemberNotify异步通知操作函数
	* Input:          TeamRpcKickMemberNotifyNotifyWraper& Notify KickMemberNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKickMemberNotify( INT64 UserId, TeamRpcKickMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientLeaveTeamNotify
	* Description:    Team-->LeaveTeam异步通知操作函数
	* Input:          TeamRpcLeaveTeamNotifyNotifyWraper& Notify LeaveTeam通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientLeaveTeamNotify( INT64 UserId, TeamRpcLeaveTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSurroundingTeam
	* Description:    Team-->SurroundingTeam同步调用操作函数
	* Input:          TeamRpcSurroundingTeamAskWraper& Ask SurroundingTeam请求
	* Output:         TeamRpcSurroundingTeamReplyWraper& Reply SurroundingTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSurroundingTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcApplyTeam
	* Description:    Team-->ApplyTeam同步调用操作函数
	* Input:          TeamRpcApplyTeamAskWraper& Ask ApplyTeam请求
	* Output:         TeamRpcApplyTeamReplyWraper& Reply ApplyTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcApplyTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientApplyTeamNotify
	* Description:    Team-->ApplyTeamNotify异步通知操作函数
	* Input:          TeamRpcApplyTeamNotifyNotifyWraper& Notify ApplyTeamNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyTeamNotify( INT64 UserId, TeamRpcApplyTeamNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAgreeApplicant
	* Description:    Team-->AgreeApplicant同步调用操作函数
	* Input:          TeamRpcAgreeApplicantAskWraper& Ask AgreeApplicant请求
	* Output:         TeamRpcAgreeApplicantReplyWraper& Reply AgreeApplicant回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeApplicant( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientAgreeApplicantNotify
	* Description:    Team-->AgreeApplicantNotify异步通知操作函数
	* Input:          TeamRpcAgreeApplicantNotifyNotifyWraper& Notify AgreeApplicantNotify通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAgreeApplicantNotify( INT64 UserId, TeamRpcAgreeApplicantNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTeamInfo
	* Description:    Team-->TeamInfo异步通知操作函数
	* Input:          TeamRpcTeamInfoNotifyWraper& Notify TeamInfo通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTeamInfo( INT64 UserId, TeamRpcTeamInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateTeamMemInfo
	* Description:    Team-->UpdateTeamMemInfo异步通知操作函数
	* Input:          TeamRpcUpdateTeamMemInfoNotifyWraper& Notify UpdateTeamMemInfo通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateTeamMemInfo( INT64 UserId, TeamRpcUpdateTeamMemInfoNotifyWraper& Notify );



};

#endif