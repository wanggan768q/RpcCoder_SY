/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEventObj.cpp
* Author:       甘业清
* Description:  EventObj类，包含以下内容
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

#include "EventObjModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleEventObj);

//EventObj实现类构造函数
ModuleEventObj::ModuleEventObj()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST, &ModuleEventObj::RpcEventBegin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EVENTOBJ_EVENTBEGIN_REQUEST, new Some_Factory<EventObjRpcEventBeginAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EVENTOBJ_EVENTEND_REQUEST, &ModuleEventObj::RpcEventEnd);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EVENTOBJ_EVENTEND_REQUEST, new Some_Factory<EventObjRpcEventEndAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST, &ModuleEventObj::RpcEventStop);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EVENTOBJ_EVENTSTOP_REQUEST, new Some_Factory<EventObjRpcEventStopAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataEventObjV1";
		
}

//EventObj实现类析构函数
ModuleEventObj::~ModuleEventObj()
{

}


//获取模块ID
UINT8 ModuleEventObj::GetModuleId()
{
	return MODULE_ID_EVENTOBJ;
}

//获取模块名字
TStr ModuleEventObj::GetModuleName()
{
	return "EventObj";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleEventObj::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleEventObj::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleEventObj::GetInitializeOrder()
{
	return MODULE_ID_EVENTOBJ;
}

//获取结束退出顺序
int ModuleEventObj::GetFinalizeOrder()
{
	return MODULE_ID_EVENTOBJ;
}

//初始化
bool ModuleEventObj::Initialize()
{

	

	return true;
}

//结束退出
void ModuleEventObj::Finalize()
{

}


//毫秒级Tick回调
void ModuleEventObj::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleEventObj::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleEventObj::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleEventObj::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleEventObj::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleEventObj::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleEventObj::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleEventObj::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleEventObj::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleEventObj::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

