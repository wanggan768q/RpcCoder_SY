/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivity.cpp
* Author:       甘业清
* Description:  活动类，包含以下内容
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

#include "ActivityModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleActivity);

//活动实现类构造函数
ModuleActivity::ModuleActivity()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST, &ModuleActivity::RpcCreateObj);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ACTIVITY_CREATEOBJ_REQUEST, new Some_Factory<ActivityRpcCreateObjAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ACTIVITY_XINGYAO_REQUEST, &ModuleActivity::RpcXingyao);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ACTIVITY_XINGYAO_REQUEST, new Some_Factory<ActivityRpcXingyaoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST, &ModuleActivity::RpcReqActivityTime);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ACTIVITY_REQACTIVITYTIME_REQUEST, new Some_Factory<ActivityRpcReqActivityTimeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST, &ModuleActivity::RpcXingyaoNPC);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_ACTIVITY_XINGYAONPC_REQUEST, new Some_Factory<ActivityRpcXingyaoNPCAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataActivityV1";
		
}

//活动实现类析构函数
ModuleActivity::~ModuleActivity()
{

}


//获取模块ID
UINT8 ModuleActivity::GetModuleId()
{
	return MODULE_ID_ACTIVITY;
}

//获取模块名字
TStr ModuleActivity::GetModuleName()
{
	return "Activity";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleActivity::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleActivity::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleActivity::GetInitializeOrder()
{
	return MODULE_ID_ACTIVITY;
}

//获取结束退出顺序
int ModuleActivity::GetFinalizeOrder()
{
	return MODULE_ID_ACTIVITY;
}

//初始化
bool ModuleActivity::Initialize()
{

	

	return true;
}

//结束退出
void ModuleActivity::Finalize()
{

}


//毫秒级Tick回调
void ModuleActivity::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleActivity::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleActivity::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleActivity::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleActivity::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleActivity::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleActivity::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleActivity::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleActivity::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleActivity::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

