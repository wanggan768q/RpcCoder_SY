/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleDungeon.cpp
* Author:       甘业清
* Description:  副本类，包含以下内容
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

#include "DungeonModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleDungeon);

//副本实现类构造函数
ModuleDungeon::ModuleDungeon()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, &ModuleDungeon::RpcCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, &ModuleDungeon::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, new Some_Factory<DungeonRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, &ModuleDungeon::RpcEnterDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, new Some_Factory<DungeonRpcEnterDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, &ModuleDungeon::RpcInformCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcInformCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, &ModuleDungeon::RpcDungeonSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_DUNGEONSYNC_REQUEST, new Some_Factory<DungeonRpcDungeonSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, &ModuleDungeon::RpcDungeonListInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_DUNGEONLISTINFO_REQUEST, new Some_Factory<DungeonRpcDungeonListInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, &ModuleDungeon::RpcCreateTutorial);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATETUTORIAL_REQUEST, new Some_Factory<DungeonRpcCreateTutorialAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, &ModuleDungeon::RpcQuitTutorial);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_QUITTUTORIAL_REQUEST, new Some_Factory<DungeonRpcQuitTutorialAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataDungeonV1";
		
}

//副本实现类析构函数
ModuleDungeon::~ModuleDungeon()
{

}


//获取模块ID
UINT8 ModuleDungeon::GetModuleId()
{
	return MODULE_ID_DUNGEON;
}

//获取模块名字
TStr ModuleDungeon::GetModuleName()
{
	return "Dungeon";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleDungeon::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleDungeon::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleDungeon::GetInitializeOrder()
{
	return MODULE_ID_DUNGEON;
}

//获取结束退出顺序
int ModuleDungeon::GetFinalizeOrder()
{
	return MODULE_ID_DUNGEON;
}

//初始化
bool ModuleDungeon::Initialize()
{

	

	return true;
}

//结束退出
void ModuleDungeon::Finalize()
{

}


//毫秒级Tick回调
void ModuleDungeon::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleDungeon::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleDungeon::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleDungeon::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleDungeon::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleDungeon::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleDungeon::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleDungeon::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleDungeon::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleDungeon::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

