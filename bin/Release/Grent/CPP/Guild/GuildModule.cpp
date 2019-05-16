/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGuild.cpp
* Author:       甘业清
* Description:  公会类，包含以下内容
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

#include "GuildModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleGuild);

//公会实现类构造函数
ModuleGuild::ModuleGuild()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_GUILDBASEINFO_REQUEST, &ModuleGuild::RpcGuildBaseInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_GUILDBASEINFO_REQUEST, new Some_Factory<GuildRpcGuildBaseInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_KICKMEMBER_REQUEST, &ModuleGuild::RpcKickMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_KICKMEMBER_REQUEST, new Some_Factory<GuildRpcKickMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKVACATION_REQUEST, &ModuleGuild::RpcAskVacation);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKVACATION_REQUEST, new Some_Factory<GuildRpcAskVacationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST, &ModuleGuild::RpcAskApplyList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKAPPLYLIST_REQUEST, new Some_Factory<GuildRpcAskApplyListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST, &ModuleGuild::RpcApplyGuildOperation);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_APPLYGUILDOPERATION_REQUEST, new Some_Factory<GuildRpcApplyGuildOperationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST, &ModuleGuild::RpcApplyLimitSetting);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_APPLYLIMITSETTING_REQUEST, new Some_Factory<GuildRpcApplyLimitSettingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST, &ModuleGuild::RpcAskJurisdictionList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKJURISDICTIONLIST_REQUEST, new Some_Factory<GuildRpcAskJurisdictionListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_SETJURISDICTION_REQUEST, &ModuleGuild::RpcSetJurisdiction);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_SETJURISDICTION_REQUEST, new Some_Factory<GuildRpcSetJurisdictionAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST, &ModuleGuild::RpcAskVacationList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKVACATIONLIST_REQUEST, new Some_Factory<GuildRpcAskVacationListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST, &ModuleGuild::RpcVacationGuildOperation);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_VACATIONGUILDOPERATION_REQUEST, new Some_Factory<GuildRpcVacationGuildOperationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST, &ModuleGuild::RpcAskBuildingInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKBUILDINGINFO_REQUEST, new Some_Factory<GuildRpcAskBuildingInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_BUILDINGLVUP_REQUEST, &ModuleGuild::RpcBuildingLvUp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_BUILDINGLVUP_REQUEST, new Some_Factory<GuildRpcBuildingLvUpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST, &ModuleGuild::RpcBuildingLvSpeedUp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_BUILDINGLVSPEEDUP_REQUEST, new Some_Factory<GuildRpcBuildingLvSpeedUpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST, &ModuleGuild::RpcAskBuildingContributionList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKBUILDINGCONTRIBUTIONLIST_REQUEST, new Some_Factory<GuildRpcAskBuildingContributionListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST, &ModuleGuild::RpcAskGuildEventList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKGUILDEVENTLIST_REQUEST, new Some_Factory<GuildRpcAskGuildEventListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST, &ModuleGuild::RpcAskGuildInfoList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKGUILDINFOLIST_REQUEST, new Some_Factory<GuildRpcAskGuildInfoListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_SEARCHGUILD_REQUEST, &ModuleGuild::RpcSearchGuild);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_SEARCHGUILD_REQUEST, new Some_Factory<GuildRpcSearchGuildAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_JOINGUILD_REQUEST, &ModuleGuild::RpcJoinGuild);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_JOINGUILD_REQUEST, new Some_Factory<GuildRpcJoinGuildAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_CREATEGUILD_REQUEST, &ModuleGuild::RpcCreateGuild);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_CREATEGUILD_REQUEST, new Some_Factory<GuildRpcCreateGuildAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_CHANGEFLAG_REQUEST, &ModuleGuild::RpcChangeFlag);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_CHANGEFLAG_REQUEST, new Some_Factory<GuildRpcChangeFlagAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST, &ModuleGuild::RpcGuildChangeName);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_GUILDCHANGENAME_REQUEST, new Some_Factory<GuildRpcGuildChangeNameAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST, &ModuleGuild::RpcAskGuildMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_ASKGUILDMEMBER_REQUEST, new Some_Factory<GuildRpcAskGuildMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_QUITEGUILD_REQUEST, &ModuleGuild::RpcQuiteGuild);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_QUITEGUILD_REQUEST, new Some_Factory<GuildRpcQuiteGuildAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_SETOFFICE_REQUEST, &ModuleGuild::RpcSetOffice);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_SETOFFICE_REQUEST, new Some_Factory<GuildRpcSetOfficeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_CHANGECREED_REQUEST, &ModuleGuild::RpcChangeCreed);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_CHANGECREED_REQUEST, new Some_Factory<GuildRpcChangeCreedAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST, &ModuleGuild::RpcForbiddenChat);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GUILD_FORBIDDENCHAT_REQUEST, new Some_Factory<GuildRpcForbiddenChatAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataGuildV1";
		
}

//公会实现类析构函数
ModuleGuild::~ModuleGuild()
{

}


//获取模块ID
UINT8 ModuleGuild::GetModuleId()
{
	return MODULE_ID_GUILD;
}

//获取模块名字
TStr ModuleGuild::GetModuleName()
{
	return "Guild";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleGuild::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleGuild::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleGuild::GetInitializeOrder()
{
	return MODULE_ID_GUILD;
}

//获取结束退出顺序
int ModuleGuild::GetFinalizeOrder()
{
	return MODULE_ID_GUILD;
}

//初始化
bool ModuleGuild::Initialize()
{

	

	return true;
}

//结束退出
void ModuleGuild::Finalize()
{

}


//毫秒级Tick回调
void ModuleGuild::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGuild::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGuild::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGuild::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGuild::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGuild::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleGuild::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGuild::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleGuild::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleGuild::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

