/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBuiness.cpp
* Author:       甘业清
* Description:  生活技能类，包含以下内容
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

#include "BuinessModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleBuiness);

//生活技能实现类构造函数
ModuleBuiness::ModuleBuiness()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_BUINESS_BUINESSSYNC_REQUEST, &ModuleBuiness::RpcBuinessSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BUINESS_BUINESSSYNC_REQUEST, new Some_Factory<BuinessRpcBuinessSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST, &ModuleBuiness::RpcBuinessUnlock);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BUINESS_BUINESSUNLOCK_REQUEST, new Some_Factory<BuinessRpcBuinessUnlockAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST, &ModuleBuiness::RpcBuinessStudy);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BUINESS_BUINESSSTUDY_REQUEST, new Some_Factory<BuinessRpcBuinessStudyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BUINESS_BUINESSMAKE_REQUEST, &ModuleBuiness::RpcBuinessMake);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BUINESS_BUINESSMAKE_REQUEST, new Some_Factory<BuinessRpcBuinessMakeAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataBuinessV1";
		
}

//生活技能实现类析构函数
ModuleBuiness::~ModuleBuiness()
{

}


//获取模块ID
UINT8 ModuleBuiness::GetModuleId()
{
	return MODULE_ID_BUINESS;
}

//获取模块名字
TStr ModuleBuiness::GetModuleName()
{
	return "Buiness";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleBuiness::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleBuiness::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleBuiness::GetInitializeOrder()
{
	return MODULE_ID_BUINESS;
}

//获取结束退出顺序
int ModuleBuiness::GetFinalizeOrder()
{
	return MODULE_ID_BUINESS;
}

//初始化
bool ModuleBuiness::Initialize()
{

	

	return true;
}

//结束退出
void ModuleBuiness::Finalize()
{

}


//毫秒级Tick回调
void ModuleBuiness::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBuiness::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBuiness::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBuiness::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBuiness::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBuiness::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleBuiness::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBuiness::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleBuiness::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleBuiness::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

