/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGate.cpp
* Author:       甘业清
* Description:  网关模块类，包含以下内容
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

#include "GateModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleGate);

//网关模块实现类构造函数
ModuleGate::ModuleGate()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_GATE_PING_REQUEST, &ModuleGate::RpcPing);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GATE_PING_REQUEST, new Some_Factory<GateRpcPingAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataGateV1";
		
}

//网关模块实现类析构函数
ModuleGate::~ModuleGate()
{

}


//获取模块ID
UINT8 ModuleGate::GetModuleId()
{
	return MODULE_ID_GATE;
}

//获取模块名字
TStr ModuleGate::GetModuleName()
{
	return "Gate";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleGate::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleGate::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleGate::GetInitializeOrder()
{
	return MODULE_ID_GATE;
}

//获取结束退出顺序
int ModuleGate::GetFinalizeOrder()
{
	return MODULE_ID_GATE;
}

//初始化
bool ModuleGate::Initialize()
{

	

	return true;
}

//结束退出
void ModuleGate::Finalize()
{

}


//毫秒级Tick回调
void ModuleGate::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGate::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGate::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGate::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGate::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGate::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleGate::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGate::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleGate::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleGate::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

