/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleRedDot.cpp
* Author:       甘业清
* Description:  红点系统类，包含以下内容
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

#include "RedDotModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleRedDot);

//红点系统实现类构造函数
ModuleRedDot::ModuleRedDot()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_REDDOT_SYNCREDDOT_REQUEST, &ModuleRedDot::RpcSyncRedDot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_REDDOT_SYNCREDDOT_REQUEST, new Some_Factory<RedDotRpcSyncRedDotAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST, &ModuleRedDot::RpcRemoveRedDot);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_REDDOT_REMOVEREDDOT_REQUEST, new Some_Factory<RedDotRpcRemoveRedDotAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataRedDotV1";
		
}

//红点系统实现类析构函数
ModuleRedDot::~ModuleRedDot()
{

}


//获取模块ID
UINT8 ModuleRedDot::GetModuleId()
{
	return MODULE_ID_REDDOT;
}

//获取模块名字
TStr ModuleRedDot::GetModuleName()
{
	return "RedDot";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleRedDot::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleRedDot::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleRedDot::GetInitializeOrder()
{
	return MODULE_ID_REDDOT;
}

//获取结束退出顺序
int ModuleRedDot::GetFinalizeOrder()
{
	return MODULE_ID_REDDOT;
}

//初始化
bool ModuleRedDot::Initialize()
{

	

	return true;
}

//结束退出
void ModuleRedDot::Finalize()
{

}


//毫秒级Tick回调
void ModuleRedDot::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleRedDot::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleRedDot::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleRedDot::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleRedDot::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleRedDot::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleRedDot::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleRedDot::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleRedDot::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleRedDot::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

