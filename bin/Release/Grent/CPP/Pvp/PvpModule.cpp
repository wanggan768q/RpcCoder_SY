/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePvp.cpp
* Author:       甘业清
* Description:  Pvp类，包含以下内容
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

#include "PvpModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModulePvp);

//Pvp实现类构造函数
ModulePvp::ModulePvp()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_RANK_REQUEST, &ModulePvp::RpcRank);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_RANK_REQUEST, new Some_Factory<PvpRpcRankAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_MATCH_REQUEST, &ModulePvp::RpcMatch);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_MATCH_REQUEST, new Some_Factory<PvpRpcMatchAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_MATCHCANCLE_REQUEST, &ModulePvp::RpcMatchCancle);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_MATCHCANCLE_REQUEST, new Some_Factory<PvpRpcMatchCancleAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST, &ModulePvp::RpcPvpBattleInfoSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_PVPBATTLEINFOSYNC_REQUEST, new Some_Factory<PvpRpcPvpBattleInfoSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_PLAYERREADY_REQUEST, &ModulePvp::RpcPlayerReady);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_PLAYERREADY_REQUEST, new Some_Factory<PvpRpcPlayerReadyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_RETURNLASTSCENE_REQUEST, &ModulePvp::RpcReturnLastScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_RETURNLASTSCENE_REQUEST, new Some_Factory<PvpRpcReturnLastSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_LASTRANK_REQUEST, &ModulePvp::RpcLastRank);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_LASTRANK_REQUEST, new Some_Factory<PvpRpcLastRankAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_GETSEASONREWARD_REQUEST, &ModulePvp::RpcGetSeasonReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_GETSEASONREWARD_REQUEST, new Some_Factory<PvpRpcGetSeasonRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PVP_GETREWARD_REQUEST, &ModulePvp::RpcGetReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PVP_GETREWARD_REQUEST, new Some_Factory<PvpRpcGetRewardAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataPvpV1";
		
}

//Pvp实现类析构函数
ModulePvp::~ModulePvp()
{

}


//获取模块ID
UINT8 ModulePvp::GetModuleId()
{
	return MODULE_ID_PVP;
}

//获取模块名字
TStr ModulePvp::GetModuleName()
{
	return "Pvp";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModulePvp::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModulePvp::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModulePvp::GetInitializeOrder()
{
	return MODULE_ID_PVP;
}

//获取结束退出顺序
int ModulePvp::GetFinalizeOrder()
{
	return MODULE_ID_PVP;
}

//初始化
bool ModulePvp::Initialize()
{

	

	return true;
}

//结束退出
void ModulePvp::Finalize()
{

}


//毫秒级Tick回调
void ModulePvp::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModulePvp::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModulePvp::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModulePvp::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModulePvp::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModulePvp::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModulePvp::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModulePvp::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModulePvp::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModulePvp::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

