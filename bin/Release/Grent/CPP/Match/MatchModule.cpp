/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMatch.cpp
* Author:       甘业清
* Description:  匹配模块类，包含以下内容
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

#include "MatchModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMatch);

//匹配模块实现类构造函数
ModuleMatch::ModuleMatch()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_MATCH_AUTOMATCH_REQUEST, &ModuleMatch::RpcAutoMatch);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MATCH_AUTOMATCH_REQUEST, new Some_Factory<MatchRpcAutoMatchAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MATCH_CANCELMATCH_REQUEST, &ModuleMatch::RpcCancelMatch);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MATCH_CANCELMATCH_REQUEST, new Some_Factory<MatchRpcCancelMatchAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MATCH_READY_REQUEST, &ModuleMatch::RpcReady);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MATCH_READY_REQUEST, new Some_Factory<MatchRpcReadyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MATCH_CANCELREADY_REQUEST, &ModuleMatch::RpcCancelReady);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MATCH_CANCELREADY_REQUEST, new Some_Factory<MatchRpcCancelReadyAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataMatchV1";
		
}

//匹配模块实现类析构函数
ModuleMatch::~ModuleMatch()
{

}


//获取模块ID
UINT8 ModuleMatch::GetModuleId()
{
	return MODULE_ID_MATCH;
}

//获取模块名字
TStr ModuleMatch::GetModuleName()
{
	return "Match";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMatch::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMatch::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleMatch::GetInitializeOrder()
{
	return MODULE_ID_MATCH;
}

//获取结束退出顺序
int ModuleMatch::GetFinalizeOrder()
{
	return MODULE_ID_MATCH;
}

//初始化
bool ModuleMatch::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMatch::Finalize()
{

}


//毫秒级Tick回调
void ModuleMatch::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMatch::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMatch::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMatch::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMatch::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMatch::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMatch::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMatch::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMatch::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMatch::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

