/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleCampFigth.cpp
* Author:       甘业清
* Description:  CampFigth类，包含以下内容
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

#include "CampFigthModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleCampFigth);

//CampFigth实现类构造函数
ModuleCampFigth::ModuleCampFigth()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST, &ModuleCampFigth::RpcMilitaryBroken);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_MILITARYBROKEN_REQUEST, new Some_Factory<CampFigthRpcMilitaryBrokenAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST, &ModuleCampFigth::RpcGetMilitaryValue);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_GETMILITARYVALUE_REQUEST, new Some_Factory<CampFigthRpcGetMilitaryValueAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST, &ModuleCampFigth::RpcWorship);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_WORSHIP_REQUEST, new Some_Factory<CampFigthRpcWorshipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST, &ModuleCampFigth::RpcWorshipRank);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_WORSHIPRANK_REQUEST, new Some_Factory<CampFigthRpcWorshipRankAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST, &ModuleCampFigth::RpcSyncRankReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_SYNCRANKREWARD_REQUEST, new Some_Factory<CampFigthRpcSyncRankRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST, &ModuleCampFigth::RpcGetRankReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_GETRANKREWARD_REQUEST, new Some_Factory<CampFigthRpcGetRankRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST, &ModuleCampFigth::RpcEnterBattleScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CAMPFIGTH_ENTERBATTLESCENE_REQUEST, new Some_Factory<CampFigthRpcEnterBattleSceneAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataCampFigthV1";
		
}

//CampFigth实现类析构函数
ModuleCampFigth::~ModuleCampFigth()
{

}


//获取模块ID
UINT8 ModuleCampFigth::GetModuleId()
{
	return MODULE_ID_CAMPFIGTH;
}

//获取模块名字
TStr ModuleCampFigth::GetModuleName()
{
	return "CampFigth";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleCampFigth::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleCampFigth::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleCampFigth::GetInitializeOrder()
{
	return MODULE_ID_CAMPFIGTH;
}

//获取结束退出顺序
int ModuleCampFigth::GetFinalizeOrder()
{
	return MODULE_ID_CAMPFIGTH;
}

//初始化
bool ModuleCampFigth::Initialize()
{

	

	return true;
}

//结束退出
void ModuleCampFigth::Finalize()
{

}


//毫秒级Tick回调
void ModuleCampFigth::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleCampFigth::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleCampFigth::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleCampFigth::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleCampFigth::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleCampFigth::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleCampFigth::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleCampFigth::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleCampFigth::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleCampFigth::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

