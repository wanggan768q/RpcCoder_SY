/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleItemOperation.cpp
* Author:       甘业清
* Description:  道具操作类，包含以下内容
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

#include "ItemOperationModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleItemOperation);

//道具操作实现类构造函数
ModuleItemOperation::ModuleItemOperation()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST, &ModuleItemOperation::RpcItemResolveSettingSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ITEMOPERATION_ITEMRESOLVESETTINGSYNC_REQUEST, new Some_Factory<ItemOperationRpcItemResolveSettingSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST, &ModuleItemOperation::RpcItemResolve);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ITEMOPERATION_ITEMRESOLVE_REQUEST, new Some_Factory<ItemOperationRpcItemResolveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST, &ModuleItemOperation::RpcChangeSetting);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ITEMOPERATION_CHANGESETTING_REQUEST, new Some_Factory<ItemOperationRpcChangeSettingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST, &ModuleItemOperation::RpcBatchResolve);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ITEMOPERATION_BATCHRESOLVE_REQUEST, new Some_Factory<ItemOperationRpcBatchResolveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST, &ModuleItemOperation::RpcItemCompound);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ITEMOPERATION_ITEMCOMPOUND_REQUEST, new Some_Factory<ItemOperationRpcItemCompoundAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataItemOperationV1";
		
}

//道具操作实现类析构函数
ModuleItemOperation::~ModuleItemOperation()
{

}


//获取模块ID
UINT8 ModuleItemOperation::GetModuleId()
{
	return MODULE_ID_ITEMOPERATION;
}

//获取模块名字
TStr ModuleItemOperation::GetModuleName()
{
	return "ItemOperation";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleItemOperation::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleItemOperation::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleItemOperation::GetInitializeOrder()
{
	return MODULE_ID_ITEMOPERATION;
}

//获取结束退出顺序
int ModuleItemOperation::GetFinalizeOrder()
{
	return MODULE_ID_ITEMOPERATION;
}

//初始化
bool ModuleItemOperation::Initialize()
{

	

	return true;
}

//结束退出
void ModuleItemOperation::Finalize()
{

}


//毫秒级Tick回调
void ModuleItemOperation::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleItemOperation::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleItemOperation::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleItemOperation::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleItemOperation::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleItemOperation::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleItemOperation::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleItemOperation::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleItemOperation::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleItemOperation::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

