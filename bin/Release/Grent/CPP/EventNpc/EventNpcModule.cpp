/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEventNpc.cpp
* Author:       甘业清
* Description:  可交互的怪 类，包含以下内容
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

#include "EventNpcModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleEventNpc);

//可交互的怪 实现类构造函数
ModuleEventNpc::ModuleEventNpc()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST, &ModuleEventNpc::RpcBeginEvent);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EVENTNPC_BEGINEVENT_REQUEST, new Some_Factory<EventNpcRpcBeginEventAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EVENTNPC_ENDEVENT_REQUEST, &ModuleEventNpc::RpcEndEvent);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EVENTNPC_ENDEVENT_REQUEST, new Some_Factory<EventNpcRpcEndEventAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataEventNpcV1";
		
}

//可交互的怪 实现类析构函数
ModuleEventNpc::~ModuleEventNpc()
{

}


//获取模块ID
UINT8 ModuleEventNpc::GetModuleId()
{
	return MODULE_ID_EVENTNPC;
}

//获取模块名字
TStr ModuleEventNpc::GetModuleName()
{
	return "EventNpc";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleEventNpc::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleEventNpc::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleEventNpc::GetInitializeOrder()
{
	return MODULE_ID_EVENTNPC;
}

//获取结束退出顺序
int ModuleEventNpc::GetFinalizeOrder()
{
	return MODULE_ID_EVENTNPC;
}

//初始化
bool ModuleEventNpc::Initialize()
{

	

	return true;
}

//结束退出
void ModuleEventNpc::Finalize()
{

}


//毫秒级Tick回调
void ModuleEventNpc::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleEventNpc::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleEventNpc::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleEventNpc::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleEventNpc::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleEventNpc::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleEventNpc::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleEventNpc::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleEventNpc::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleEventNpc::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

