/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMedicament.cpp
* Author:       甘业清
* Description:  药剂类，包含以下内容
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

#include "MedicamentModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMedicament);

//药剂实现类构造函数
ModuleMedicament::ModuleMedicament()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_MEDICAMENT_FILLHP_REQUEST, &ModuleMedicament::RpcFillHp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MEDICAMENT_FILLHP_REQUEST, new Some_Factory<MedicamentRpcFillHpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST, &ModuleMedicament::RpcOneStepFillHp);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MEDICAMENT_ONESTEPFILLHP_REQUEST, new Some_Factory<MedicamentRpcOneStepFillHpAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST, &ModuleMedicament::RpcClientRefreshMedicament);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MEDICAMENT_CLIENTREFRESHMEDICAMENT_REQUEST, new Some_Factory<MedicamentRpcClientRefreshMedicamentAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST, &ModuleMedicament::RpcSyncMedicamentData);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MEDICAMENT_SYNCMEDICAMENTDATA_REQUEST, new Some_Factory<MedicamentRpcSyncMedicamentDataAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST, &ModuleMedicament::RpcMedicamentCD);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MEDICAMENT_MEDICAMENTCD_REQUEST, new Some_Factory<MedicamentRpcMedicamentCDAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataMedicamentV1";
		
}

//药剂实现类析构函数
ModuleMedicament::~ModuleMedicament()
{

}


//获取模块ID
UINT8 ModuleMedicament::GetModuleId()
{
	return MODULE_ID_MEDICAMENT;
}

//获取模块名字
TStr ModuleMedicament::GetModuleName()
{
	return "Medicament";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMedicament::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMedicament::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleMedicament::GetInitializeOrder()
{
	return MODULE_ID_MEDICAMENT;
}

//获取结束退出顺序
int ModuleMedicament::GetFinalizeOrder()
{
	return MODULE_ID_MEDICAMENT;
}

//初始化
bool ModuleMedicament::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMedicament::Finalize()
{

}


//毫秒级Tick回调
void ModuleMedicament::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMedicament::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMedicament::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMedicament::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMedicament::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMedicament::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMedicament::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMedicament::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMedicament::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMedicament::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

