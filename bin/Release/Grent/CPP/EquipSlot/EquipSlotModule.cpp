/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEquipSlot.cpp
* Author:       甘业清
* Description:  装备槽类，包含以下内容
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

#include "EquipSlotModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleEquipSlot);

//装备槽实现类构造函数
ModuleEquipSlot::ModuleEquipSlot()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST, &ModuleEquipSlot::RpcSyncEquipSlot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOT_REQUEST, new Some_Factory<EquipSlotRpcSyncEquipSlotAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST, &ModuleEquipSlot::RpcEnhanceEquipSlot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPSLOT_ENHANCEEQUIPSLOT_REQUEST, new Some_Factory<EquipSlotRpcEnhanceEquipSlotAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST, &ModuleEquipSlot::RpcSyncEquipSlotStar);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPSLOT_SYNCEQUIPSLOTSTAR_REQUEST, new Some_Factory<EquipSlotRpcSyncEquipSlotStarAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST, &ModuleEquipSlot::RpcUpStarEquipSlot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPSLOT_UPSTAREQUIPSLOT_REQUEST, new Some_Factory<EquipSlotRpcUpStarEquipSlotAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataEquipSlotV1";
		
}

//装备槽实现类析构函数
ModuleEquipSlot::~ModuleEquipSlot()
{

}


//获取模块ID
UINT8 ModuleEquipSlot::GetModuleId()
{
	return MODULE_ID_EQUIPSLOT;
}

//获取模块名字
TStr ModuleEquipSlot::GetModuleName()
{
	return "EquipSlot";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleEquipSlot::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleEquipSlot::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleEquipSlot::GetInitializeOrder()
{
	return MODULE_ID_EQUIPSLOT;
}

//获取结束退出顺序
int ModuleEquipSlot::GetFinalizeOrder()
{
	return MODULE_ID_EQUIPSLOT;
}

//初始化
bool ModuleEquipSlot::Initialize()
{

	

	return true;
}

//结束退出
void ModuleEquipSlot::Finalize()
{

}


//毫秒级Tick回调
void ModuleEquipSlot::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleEquipSlot::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleEquipSlot::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleEquipSlot::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleEquipSlot::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleEquipSlot::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleEquipSlot::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleEquipSlot::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleEquipSlot::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleEquipSlot::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

