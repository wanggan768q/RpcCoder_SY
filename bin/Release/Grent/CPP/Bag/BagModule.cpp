/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBag.cpp
* Author:       甘业清
* Description:  Bag类，包含以下内容
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

#include "BagModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleBag);

//Bag实现类构造函数
ModuleBag::ModuleBag()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_USEITEM_REQUEST, &ModuleBag::RpcUseItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_USEITEM_REQUEST, new Some_Factory<BagRpcUseItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_SALEITEM_REQUEST, &ModuleBag::RpcSaleItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_SALEITEM_REQUEST, new Some_Factory<BagRpcSaleItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_LOCKITEM_REQUEST, &ModuleBag::RpcLockItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_LOCKITEM_REQUEST, new Some_Factory<BagRpcLockItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_DEBLOCKING_REQUEST, &ModuleBag::RpcDeblocking);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_DEBLOCKING_REQUEST, new Some_Factory<BagRpcDeblockingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TAKEITEM_REQUEST, &ModuleBag::RpcTakeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TAKEITEM_REQUEST, new Some_Factory<BagRpcTakeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TIDY_REQUEST, &ModuleBag::RpcTidy);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TIDY_REQUEST, new Some_Factory<BagRpcTidyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, &ModuleBag::RpcTakeAllBackBags);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, new Some_Factory<BagRpcTakeAllBackBagsAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_MERGEITEM_REQUEST, &ModuleBag::RpcMergeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_MERGEITEM_REQUEST, new Some_Factory<BagRpcMergeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_BAGSYNC_REQUEST, &ModuleBag::RpcBagSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_BAGSYNC_REQUEST, new Some_Factory<BagRpcBagSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_CONSUMEITEM_REQUEST, &ModuleBag::RpcConsumeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_CONSUMEITEM_REQUEST, new Some_Factory<BagRpcConsumeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_CLICKITEM_REQUEST, &ModuleBag::RpcClickItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_CLICKITEM_REQUEST, new Some_Factory<BagRpcClickItemAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataBagV1";
		
}

//Bag实现类析构函数
ModuleBag::~ModuleBag()
{

}


//获取模块ID
UINT8 ModuleBag::GetModuleId()
{
	return MODULE_ID_BAG;
}

//获取模块名字
TStr ModuleBag::GetModuleName()
{
	return "Bag";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleBag::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleBag::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleBag::GetInitializeOrder()
{
	return MODULE_ID_BAG;
}

//获取结束退出顺序
int ModuleBag::GetFinalizeOrder()
{
	return MODULE_ID_BAG;
}

//初始化
bool ModuleBag::Initialize()
{

	

	return true;
}

//结束退出
void ModuleBag::Finalize()
{

}


//毫秒级Tick回调
void ModuleBag::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBag::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBag::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBag::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBag::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBag::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleBag::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBag::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleBag::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleBag::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

