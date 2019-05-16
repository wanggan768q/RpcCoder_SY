/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEquipment.cpp
* Author:       甘业清
* Description:  装备类，包含以下内容
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

#include "EquipmentModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleEquipment);

//装备实现类构造函数
ModuleEquipment::ModuleEquipment()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIP_REQUEST, &ModuleEquipment::RpcEquip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIP_REQUEST, new Some_Factory<EquipmentRpcEquipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST, &ModuleEquipment::RpcUnEquip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_UNEQUIP_REQUEST, new Some_Factory<EquipmentRpcUnEquipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST, &ModuleEquipment::RpcSwitchEquipSet);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_SWITCHEQUIPSET_REQUEST, new Some_Factory<EquipmentRpcSwitchEquipSetAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST, &ModuleEquipment::RpcSyncEquip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_SYNCEQUIP_REQUEST, new Some_Factory<EquipmentRpcSyncEquipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST, &ModuleEquipment::RpcResonanceUnlock);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_RESONANCEUNLOCK_REQUEST, new Some_Factory<EquipmentRpcResonanceUnlockAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST, &ModuleEquipment::RpcEquipDoResonance);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPDORESONANCE_REQUEST, new Some_Factory<EquipmentRpcEquipDoResonanceAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST, &ModuleEquipment::RpcEquipResonanceSave);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPRESONANCESAVE_REQUEST, new Some_Factory<EquipmentRpcEquipResonanceSaveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST, &ModuleEquipment::RpcEquipResonanceSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPRESONANCESYNC_REQUEST, new Some_Factory<EquipmentRpcEquipResonanceSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST, &ModuleEquipment::RpcEquipWashSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPWASHSYNC_REQUEST, new Some_Factory<EquipmentRpcEquipWashSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST, &ModuleEquipment::RpcEquipWash);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPWASH_REQUEST, new Some_Factory<EquipmentRpcEquipWashAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST, &ModuleEquipment::RpcEquipWashSave);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPWASHSAVE_REQUEST, new Some_Factory<EquipmentRpcEquipWashSaveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST, &ModuleEquipment::RpcEquipBuildSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPBUILDSYNC_REQUEST, new Some_Factory<EquipmentRpcEquipBuildSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST, &ModuleEquipment::RpcEquipBuild);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPBUILD_REQUEST, new Some_Factory<EquipmentRpcEquipBuildAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST, &ModuleEquipment::RpcGetPlayerInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_GETPLAYERINFO_REQUEST, new Some_Factory<EquipmentRpcGetPlayerInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST, &ModuleEquipment::RpcEquipInherit);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EQUIPMENT_EQUIPINHERIT_REQUEST, new Some_Factory<EquipmentRpcEquipInheritAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataEquipmentV1";
		
}

//装备实现类析构函数
ModuleEquipment::~ModuleEquipment()
{

}


//获取模块ID
UINT8 ModuleEquipment::GetModuleId()
{
	return MODULE_ID_EQUIPMENT;
}

//获取模块名字
TStr ModuleEquipment::GetModuleName()
{
	return "Equipment";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleEquipment::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleEquipment::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleEquipment::GetInitializeOrder()
{
	return MODULE_ID_EQUIPMENT;
}

//获取结束退出顺序
int ModuleEquipment::GetFinalizeOrder()
{
	return MODULE_ID_EQUIPMENT;
}

//初始化
bool ModuleEquipment::Initialize()
{

	

	return true;
}

//结束退出
void ModuleEquipment::Finalize()
{

}


//毫秒级Tick回调
void ModuleEquipment::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleEquipment::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleEquipment::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleEquipment::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleEquipment::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleEquipment::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleEquipment::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleEquipment::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleEquipment::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleEquipment::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

