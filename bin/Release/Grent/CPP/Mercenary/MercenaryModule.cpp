/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMercenary.cpp
* Author:       甘业清
* Description:  佣兵类，包含以下内容
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

#include "MercenaryModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMercenary);

//佣兵实现类构造函数
ModuleMercenary::ModuleMercenary()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_MERCENARY_INQUEUE_REQUEST, &ModuleMercenary::RpcInQueue);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MERCENARY_INQUEUE_REQUEST, new Some_Factory<MercenaryRpcInQueueAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MERCENARY_OUTQUEUE_REQUEST, &ModuleMercenary::RpcOutQueue);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MERCENARY_OUTQUEUE_REQUEST, new Some_Factory<MercenaryRpcOutQueueAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MERCENARY_AUTOSET_REQUEST, &ModuleMercenary::RpcAutoSet);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MERCENARY_AUTOSET_REQUEST, new Some_Factory<MercenaryRpcAutoSetAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MERCENARY_INFO_REQUEST, &ModuleMercenary::RpcInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MERCENARY_INFO_REQUEST, new Some_Factory<MercenaryRpcInfoAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataMercenaryV1";
		
}

//佣兵实现类析构函数
ModuleMercenary::~ModuleMercenary()
{

}


//获取模块ID
UINT8 ModuleMercenary::GetModuleId()
{
	return MODULE_ID_MERCENARY;
}

//获取模块名字
TStr ModuleMercenary::GetModuleName()
{
	return "Mercenary";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMercenary::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMercenary::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleMercenary::GetInitializeOrder()
{
	return MODULE_ID_MERCENARY;
}

//获取结束退出顺序
int ModuleMercenary::GetFinalizeOrder()
{
	return MODULE_ID_MERCENARY;
}

//初始化
bool ModuleMercenary::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMercenary::Finalize()
{

}


//毫秒级Tick回调
void ModuleMercenary::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMercenary::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMercenary::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMercenary::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMercenary::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMercenary::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMercenary::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMercenary::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMercenary::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMercenary::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

