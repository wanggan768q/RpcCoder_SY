/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleJewel.cpp
* Author:       甘业清
* Description:  宝石模块类，包含以下内容
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

#include "JewelModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleJewel);

//宝石模块实现类构造函数
ModuleJewel::ModuleJewel()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_JEWELSYNC_REQUEST, &ModuleJewel::RpcJewelSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_JEWELSYNC_REQUEST, new Some_Factory<JewelRpcJewelSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_INSETJEWEL_REQUEST, &ModuleJewel::RpcInsetJewel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_INSETJEWEL_REQUEST, new Some_Factory<JewelRpcInsetJewelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST, &ModuleJewel::RpcRemoveJewel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_REMOVEJEWEL_REQUEST, new Some_Factory<JewelRpcRemoveJewelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST, &ModuleJewel::RpcCompoundJewel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_COMPOUNDJEWEL_REQUEST, new Some_Factory<JewelRpcCompoundJewelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST, &ModuleJewel::RpcCompoundSetJewel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_COMPOUNDSETJEWEL_REQUEST, new Some_Factory<JewelRpcCompoundSetJewelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST, &ModuleJewel::RpcUnlockJewelSlot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_UNLOCKJEWELSLOT_REQUEST, new Some_Factory<JewelRpcUnlockJewelSlotAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST, &ModuleJewel::RpcQuickCompound);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_JEWEL_QUICKCOMPOUND_REQUEST, new Some_Factory<JewelRpcQuickCompoundAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataJewelV1";
		
}

//宝石模块实现类析构函数
ModuleJewel::~ModuleJewel()
{

}


//获取模块ID
UINT8 ModuleJewel::GetModuleId()
{
	return MODULE_ID_JEWEL;
}

//获取模块名字
TStr ModuleJewel::GetModuleName()
{
	return "Jewel";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleJewel::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleJewel::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleJewel::GetInitializeOrder()
{
	return MODULE_ID_JEWEL;
}

//获取结束退出顺序
int ModuleJewel::GetFinalizeOrder()
{
	return MODULE_ID_JEWEL;
}

//初始化
bool ModuleJewel::Initialize()
{

	

	return true;
}

//结束退出
void ModuleJewel::Finalize()
{

}


//毫秒级Tick回调
void ModuleJewel::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleJewel::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleJewel::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleJewel::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleJewel::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleJewel::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleJewel::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleJewel::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleJewel::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleJewel::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

