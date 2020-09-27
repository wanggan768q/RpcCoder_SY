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
#include "Game/PacketMgr.h"
#include "TeamRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




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
	RPC_CODE_TEAM_LEAVETEAM_REQUEST              = 1051,	//Team-->LeaveTeam-->请求
	RPC_CODE_TEAM_APPOINTTEAMLEADER_REQUEST      = 1052,	//Team-->AppointTeamLeader-->请求
	RPC_CODE_TEAM_CREATETEAM_REQUEST             = 1053,	//Team-->CreateTeam-->请求
	RPC_CODE_TEAM_DISSMISSTEAM_REQUEST           = 1054,	//Team-->DissmissTeam-->请求
	RPC_CODE_TEAM_NEWLEADER_NOTIFY               = 1055,	//Team-->NewLeader-->通知
	RPC_CODE_TEAM_KICKMEMBER_REQUEST             = 1056,	//Team-->KickMember-->请求
	RPC_CODE_TEAM_DISSMISSTEAMNOTIFY_NOTIFY      = 1057,	//Team-->DissmissTeamNotify-->通知
	RPC_CODE_TEAM_JOINTEAMNOTIFY_NOTIFY          = 1058,	//Team-->JoinTeamNotify-->通知
	RPC_CODE_TEAM_KICKMEMBERNOTIFY_NOTIFY        = 1059,	//Team-->KickMemberNotify-->通知
	RPC_CODE_TEAM_LEAVETEAMNOTIFY_NOTIFY         = 1060,	//Team-->LeaveTeam-->通知
	RPC_CODE_TEAM_SURROUNDINGTEAM_REQUEST        = 1061,	//Team-->SurroundingTeam-->请求
	RPC_CODE_TEAM_APPLYTEAM_REQUEST              = 1062,	//Team-->ApplyTeam-->请求
	RPC_CODE_TEAM_APPLYTEAMNOTIFY_NOTIFY         = 1063,	//Team-->ApplyTeamNotify-->通知
	RPC_CODE_TEAM_AGREEAPPLICANT_REQUEST         = 1064,	//Team-->AgreeApplicant-->请求
	RPC_CODE_TEAM_AGREEAPPLICANTNOTIFY_NOTIFY    = 1065,	//Team-->AgreeApplicantNotify-->通知
	RPC_CODE_TEAM_TEAMINFO_NOTIFY                = 1066,	//Team-->TeamInfo-->通知
	RPC_CODE_TEAM_UPDATETEAMMEMINFO_NOTIFY       = 1067,	//Team-->UpdateTeamMemInfo-->通知
	RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST       = 1068,	//Team-->跟随队长-->请求
	RPC_CODE_TEAM_SUMMONMEMBER_REQUEST           = 1069,	//Team-->召唤队员-->请求
	RPC_CODE_TEAM_SUMMONMEMBERNOTIFY_NOTIFY      = 1070,	//Team-->召唤队员-->通知
	RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST       = 1071,	//Team-->改变队伍目标-->请求
	RPC_CODE_TEAM_CHANGETEAMTARGETNOTIFY_NOTIFY  = 1072,	//Team-->设置服务器目标-->通知
	RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST          = 1073,	//Team-->转换队伍团队-->请求
	RPC_CODE_TEAM_CHANGETEAMTYPENOTIFY_NOTIFY    = 1074,	//Team-->转换队伍团队协议-->通知
	RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST       = 1075,	//Team-->邀请玩家-->请求
	RPC_CODE_TEAM_INVITETEAMMEMBERNOTIFY_NOTIFY  = 1076,	//Team-->邀请玩家广播-->通知
	RPC_CODE_TEAM_APPLYLISTNOTIFY_NOTIFY         = 1077,	//Team-->列表通知-->通知
	RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST          = 1078,	//Team-->AgreeJoinTeam-->请求
	RPC_CODE_TEAM_REFUSEMEMBER_REQUEST           = 1079,	//Team-->拒绝申请-->请求
	RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST         = 1080,	//Team-->清空申请列表-->请求
	RPC_CODE_TEAM_NOTEAMINVITE_REQUEST           = 1081,	//Team-->没有队伍邀请玩家-->请求
	RPC_CODE_TEAM_REJECTINVITE_REQUEST           = 1082,	//Team-->拒绝邀请-->请求
	RPC_CODE_TEAM_ENTERAUTOCOMBAT_NOTIFY         = 1083,	//Team-->进入自动战斗状态-->通知
	RPC_CODE_TEAM_HANGUPAUTOCOMBAT_NOTIFY        = 1084,	//Team-->挂起自动战斗-->通知
	RPC_CODE_TEAM_UPDATETEAMHPINFO_NOTIFY        = 1085,	//Team-->更新队伍快速刷新Hp-->通知
	RPC_CODE_TEAM_UPDATETEAMPOSINFO_NOTIFY       = 1086,	//Team-->更新队伍成员信息-->通知
	RPC_CODE_TEAM_UPDATETEAMBUFFINFO_NOTIFY      = 1087,	//Team-->更新队伍bufflist-->通知
	RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST          = 1088,	//Team-->暂停跟随-->请求
	RPC_CODE_TEAM_GOONFOLLOW_REQUEST             = 1089,	//Team-->继续跟随-->请求
	RPC_CODE_TEAM_UPDATEFOLLOWSTATUS_NOTIFY      = 1090,	//Team-->更新跟随状态-->通知
	RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST= 1091,	//Team-->请求玩家列表-->请求
	RPC_CODE_TEAM_ENTERTEAMFOLLOW_NOTIFY         = 1092,	//Team-->你加入了一支副本队伍，是否开启组队跟随功能，自动传送入队长所在副本-->通知
	RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST       = 1093,	//Team-->进入队长场景-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//Team实现类构造函数
	ModuleTeam()
	{
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
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST, &ModuleTeam::RpcFollowTeamLeader);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_FOLLOWTEAMLEADER_REQUEST, new Some_Factory<TeamRpcFollowTeamLeaderAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_SUMMONMEMBER_REQUEST, &ModuleTeam::RpcSummonMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_SUMMONMEMBER_REQUEST, new Some_Factory<TeamRpcSummonMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST, &ModuleTeam::RpcChangeTeamTarget);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_CHANGETEAMTARGET_REQUEST, new Some_Factory<TeamRpcChangeTeamTargetAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST, &ModuleTeam::RpcChangTeamType);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_CHANGTEAMTYPE_REQUEST, new Some_Factory<TeamRpcChangTeamTypeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST, &ModuleTeam::RpcInviteTeamMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_INVITETEAMMEMBER_REQUEST, new Some_Factory<TeamRpcInviteTeamMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST, &ModuleTeam::RpcAgreeJoinTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_AGREEJOINTEAM_REQUEST, new Some_Factory<TeamRpcAgreeJoinTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_REFUSEMEMBER_REQUEST, &ModuleTeam::RpcRefuseMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_REFUSEMEMBER_REQUEST, new Some_Factory<TeamRpcRefuseMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST, &ModuleTeam::RpcClearApplyList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_CLEARAPPLYLIST_REQUEST, new Some_Factory<TeamRpcClearApplyListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_NOTEAMINVITE_REQUEST, &ModuleTeam::RpcNoTeamInvite);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_NOTEAMINVITE_REQUEST, new Some_Factory<TeamRpcNoTeamInviteAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_REJECTINVITE_REQUEST, &ModuleTeam::RpcRejectInvite);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_REJECTINVITE_REQUEST, new Some_Factory<TeamRpcRejectInviteAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST, &ModuleTeam::RpcHangeUpFollow);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_HANGEUPFOLLOW_REQUEST, new Some_Factory<TeamRpcHangeUpFollowAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_GOONFOLLOW_REQUEST, &ModuleTeam::RpcGoOnFollow);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_GOONFOLLOW_REQUEST, new Some_Factory<TeamRpcGoOnFollowAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST, &ModuleTeam::RpcRequestNoTeamMemberList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_REQUESTNOTEAMMEMBERLIST_REQUEST, new Some_Factory<TeamRpcRequestNoTeamMemberListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST, &ModuleTeam::RpcEnterLeaderScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TEAM_ENTERLEADERSCENE_REQUEST, new Some_Factory<TeamRpcEnterLeaderSceneAsk>());

	}
	
	//Team实现类析构函数
	~ModuleTeam(){}


	static ModuleTeam & Instance()
	{
		static ModuleTeam sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
public:
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

	/********************************************************************************************
	* Function:       RpcFollowTeamLeader
	* Description:    Team-->跟随队长同步调用操作函数
	* Input:          TeamRpcFollowTeamLeaderAskWraper& Ask 跟随队长请求
	* Output:         TeamRpcFollowTeamLeaderReplyWraper& Reply 跟随队长回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcFollowTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSummonMember
	* Description:    Team-->召唤队员同步调用操作函数
	* Input:          TeamRpcSummonMemberAskWraper& Ask 召唤队员请求
	* Output:         TeamRpcSummonMemberReplyWraper& Reply 召唤队员回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSummonMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSummonMemberNotify
	* Description:    Team-->召唤队员异步通知操作函数
	* Input:          TeamRpcSummonMemberNotifyNotifyWraper& Notify 召唤队员通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSummonMemberNotify( INT64 UserId, TeamRpcSummonMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeTeamTarget
	* Description:    Team-->改变队伍目标同步调用操作函数
	* Input:          TeamRpcChangeTeamTargetAskWraper& Ask 改变队伍目标
	* Output:         TeamRpcChangeTeamTargetReplyWraper& Reply 改变队伍目标
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeTeamTarget( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeTeamTargetNotify
	* Description:    Team-->设置服务器目标异步通知操作函数
	* Input:          TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify 设置服务器目标通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeTeamTargetNotify( INT64 UserId, TeamRpcChangeTeamTargetNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangTeamType
	* Description:    Team-->转换队伍团队同步调用操作函数
	* Input:          TeamRpcChangTeamTypeAskWraper& Ask 转换队伍团队请求
	* Output:         TeamRpcChangTeamTypeReplyWraper& Reply 转换队伍团队回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangTeamType( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeTeamTypeNotify
	* Description:    Team-->转换队伍团队协议异步通知操作函数
	* Input:          TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify 转换队伍团队协议通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeTeamTypeNotify( INT64 UserId, TeamRpcChangeTeamTypeNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcInviteTeamMember
	* Description:    Team-->邀请玩家同步调用操作函数
	* Input:          TeamRpcInviteTeamMemberAskWraper& Ask 邀请玩家请求
	* Output:         TeamRpcInviteTeamMemberReplyWraper& Reply 邀请玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInviteTeamMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientInviteTeamMemberNotify
	* Description:    Team-->邀请玩家广播异步通知操作函数
	* Input:          TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify 邀请玩家广播通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientInviteTeamMemberNotify( INT64 UserId, TeamRpcInviteTeamMemberNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientApplyListNotify
	* Description:    Team-->列表通知异步通知操作函数
	* Input:          TeamRpcApplyListNotifyNotifyWraper& Notify 列表通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientApplyListNotify( INT64 UserId, TeamRpcApplyListNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcAgreeJoinTeam
	* Description:    Team-->AgreeJoinTeam同步调用操作函数
	* Input:          TeamRpcAgreeJoinTeamAskWraper& Ask AgreeJoinTeam请求
	* Output:         TeamRpcAgreeJoinTeamReplyWraper& Reply AgreeJoinTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeJoinTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRefuseMember
	* Description:    Team-->拒绝申请同步调用操作函数
	* Input:          TeamRpcRefuseMemberAskWraper& Ask 拒绝申请请求
	* Output:         TeamRpcRefuseMemberReplyWraper& Reply 拒绝申请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRefuseMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcClearApplyList
	* Description:    Team-->清空申请列表同步调用操作函数
	* Input:          TeamRpcClearApplyListAskWraper& Ask 清空申请列表请求
	* Output:         TeamRpcClearApplyListReplyWraper& Reply 清空申请列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcClearApplyList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcNoTeamInvite
	* Description:    Team-->没有队伍邀请玩家同步调用操作函数
	* Input:          TeamRpcNoTeamInviteAskWraper& Ask 没有队伍邀请玩家请求
	* Output:         TeamRpcNoTeamInviteReplyWraper& Reply 没有队伍邀请玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcNoTeamInvite( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRejectInvite
	* Description:    Team-->拒绝邀请同步调用操作函数
	* Input:          TeamRpcRejectInviteAskWraper& Ask 拒绝邀请请求
	* Output:         TeamRpcRejectInviteReplyWraper& Reply 拒绝邀请回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRejectInvite( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientEnterAutoCombat
	* Description:    Team-->进入自动战斗状态异步通知操作函数
	* Input:          TeamRpcEnterAutoCombatNotifyWraper& Notify 进入自动战斗状态通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientEnterAutoCombat( INT64 UserId, TeamRpcEnterAutoCombatNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientHangUpAutoCombat
	* Description:    Team-->挂起自动战斗异步通知操作函数
	* Input:          TeamRpcHangUpAutoCombatNotifyWraper& Notify 挂起自动战斗通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientHangUpAutoCombat( INT64 UserId, TeamRpcHangUpAutoCombatNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateTeamHpInfo
	* Description:    Team-->更新队伍快速刷新Hp异步通知操作函数
	* Input:          TeamRpcUpdateTeamHpInfoNotifyWraper& Notify 更新队伍快速刷新Hp通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateTeamHpInfo( INT64 UserId, TeamRpcUpdateTeamHpInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateTeamPosInfo
	* Description:    Team-->更新队伍成员信息异步通知操作函数
	* Input:          TeamRpcUpdateTeamPosInfoNotifyWraper& Notify 更新队伍成员信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateTeamPosInfo( INT64 UserId, TeamRpcUpdateTeamPosInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateTeamBuffInfo
	* Description:    Team-->更新队伍bufflist异步通知操作函数
	* Input:          TeamRpcUpdateTeamBuffInfoNotifyWraper& Notify 更新队伍bufflist通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateTeamBuffInfo( INT64 UserId, TeamRpcUpdateTeamBuffInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcHangeUpFollow
	* Description:    Team-->暂停跟随同步调用操作函数
	* Input:          TeamRpcHangeUpFollowAskWraper& Ask 暂停跟随请求
	* Output:         TeamRpcHangeUpFollowReplyWraper& Reply 暂停跟随回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcHangeUpFollow( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGoOnFollow
	* Description:    Team-->继续跟随同步调用操作函数
	* Input:          TeamRpcGoOnFollowAskWraper& Ask 继续跟随请求
	* Output:         TeamRpcGoOnFollowReplyWraper& Reply 继续跟随回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGoOnFollow( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientUpdateFollowStatus
	* Description:    Team-->更新跟随状态异步通知操作函数
	* Input:          TeamRpcUpdateFollowStatusNotifyWraper& Notify 更新跟随状态通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateFollowStatus( INT64 UserId, TeamRpcUpdateFollowStatusNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcRequestNoTeamMemberList
	* Description:    Team-->请求玩家列表同步调用操作函数
	* Input:          TeamRpcRequestNoTeamMemberListAskWraper& Ask 请求玩家列表请求
	* Output:         TeamRpcRequestNoTeamMemberListReplyWraper& Reply 请求玩家列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRequestNoTeamMemberList( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientEnterTeamFollow
	* Description:    Team-->你加入了一支副本队伍，是否开启组队跟随功能，自动传送入队长所在副本异步通知操作函数
	* Input:          TeamRpcEnterTeamFollowNotifyWraper& Notify 你加入了一支副本队伍，是否开启组队跟随功能，自动传送入队长所在副本通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientEnterTeamFollow( INT64 UserId, TeamRpcEnterTeamFollowNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcEnterLeaderScene
	* Description:    Team-->进入队长场景同步调用操作函数
	* Input:          TeamRpcEnterLeaderSceneAskWraper& Ask 进入队长场景请求
	* Output:         TeamRpcEnterLeaderSceneReplyWraper& Reply 进入队长场景回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterLeaderScene( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif