/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleRiding.cpp
* Author:       甘业清
* Description:  坐骑类，包含以下内容
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

#include "RidingModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleRiding);

//坐骑实现类构造函数
ModuleRiding::ModuleRiding()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_RIDING_RIDING_REQUEST, &ModuleRiding::RpcRiding);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_RIDING_RIDING_REQUEST, new Some_Factory<RidingRpcRidingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_RIDING_UNRIDING_REQUEST, &ModuleRiding::RpcUnRiding);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_RIDING_UNRIDING_REQUEST, new Some_Factory<RidingRpcUnRidingAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataRidingV1";
		
}

//坐骑实现类析构函数
ModuleRiding::~ModuleRiding()
{

}


//获取模块ID
UINT8 ModuleRiding::GetModuleId()
{
	return MODULE_ID_RIDING;
}

//获取模块名字
TStr ModuleRiding::GetModuleName()
{
	return "Riding";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleRiding::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleRiding::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleRiding::GetInitializeOrder()
{
	return MODULE_ID_RIDING;
}

//获取结束退出顺序
int ModuleRiding::GetFinalizeOrder()
{
	return MODULE_ID_RIDING;
}

//初始化
bool ModuleRiding::Initialize()
{

	

	return true;
}

//结束退出
void ModuleRiding::Finalize()
{

}


//毫秒级Tick回调
void ModuleRiding::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleRiding::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleRiding::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleRiding::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleRiding::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleRiding::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleRiding::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleRiding::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleRiding::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleRiding::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

