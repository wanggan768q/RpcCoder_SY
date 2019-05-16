/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTeam.cpp
* Author:       甘业清
* Description:  Team类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "TeamModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTeam);

//Team实现类构造函数
ModuleTeam::ModuleTeam()
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


	
	m_mapSyncDataVersionName[1] = "SyncDataTeamV1";
		
}

//Team实现类析构函数
ModuleTeam::~ModuleTeam()
{

}


//获取模块ID
UINT8 ModuleTeam::GetModuleId()
{
	return MODULE_ID_TEAM;
}

//获取模块名字
TStr ModuleTeam::GetModuleName()
{
	return "Team";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTeam::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTeam::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleTeam::GetInitializeOrder()
{
	return MODULE_ID_TEAM;
}

//获取结束退出顺序
int ModuleTeam::GetFinalizeOrder()
{
	return MODULE_ID_TEAM;
}

//初始化
bool ModuleTeam::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTeam::Finalize()
{

}


//毫秒级Tick回调
void ModuleTeam::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTeam::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTeam::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTeam::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTeam::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTeam::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTeam::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTeam::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTeam::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTeam::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

