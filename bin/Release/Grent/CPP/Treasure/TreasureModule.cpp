/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleTreasure.cpp
* Author:       甘业清
* Description:  珍宝阁类，包含以下内容
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

#include "TreasureModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleTreasure);

//珍宝阁实现类构造函数
ModuleTreasure::ModuleTreasure()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST, &ModuleTreasure::RpcTreasureDepotInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREDEPOTINFO_REQUEST, new Some_Factory<TreasureRpcTreasureDepotInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREINFO_REQUEST, &ModuleTreasure::RpcTreasureInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREINFO_REQUEST, new Some_Factory<TreasureRpcTreasureInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST, &ModuleTreasure::RpcTreasureUnlock);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREUNLOCK_REQUEST, new Some_Factory<TreasureRpcTreasureUnlockAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST, &ModuleTreasure::RpcTreasureEquip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREEQUIP_REQUEST, new Some_Factory<TreasureRpcTreasureEquipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST, &ModuleTreasure::RpcTreasureEquipSyc);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREEQUIPSYC_REQUEST, new Some_Factory<TreasureRpcTreasureEquipSycAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST, &ModuleTreasure::RpcTreasureDepotLvUp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREDEPOTLVUP_REQUEST, new Some_Factory<TreasureRpcTreasureDepotLvUpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST, &ModuleTreasure::RpcTreasureUnEquip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREUNEQUIP_REQUEST, new Some_Factory<TreasureRpcTreasureUnEquipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST, &ModuleTreasure::RpcTreasureDelayTime);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_TREASURE_TREASUREDELAYTIME_REQUEST, new Some_Factory<TreasureRpcTreasureDelayTimeAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataTreasureV1";
		
}

//珍宝阁实现类析构函数
ModuleTreasure::~ModuleTreasure()
{

}


//获取模块ID
UINT8 ModuleTreasure::GetModuleId()
{
	return MODULE_ID_TREASURE;
}

//获取模块名字
TStr ModuleTreasure::GetModuleName()
{
	return "Treasure";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleTreasure::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleTreasure::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleTreasure::GetInitializeOrder()
{
	return MODULE_ID_TREASURE;
}

//获取结束退出顺序
int ModuleTreasure::GetFinalizeOrder()
{
	return MODULE_ID_TREASURE;
}

//初始化
bool ModuleTreasure::Initialize()
{

	

	return true;
}

//结束退出
void ModuleTreasure::Finalize()
{

}


//毫秒级Tick回调
void ModuleTreasure::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleTreasure::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleTreasure::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleTreasure::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleTreasure::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleTreasure::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleTreasure::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleTreasure::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleTreasure::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleTreasure::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

