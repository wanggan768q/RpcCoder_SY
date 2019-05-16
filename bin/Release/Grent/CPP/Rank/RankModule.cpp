/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleRank.cpp
* Author:       甘业清
* Description:  排行榜类，包含以下内容
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

#include "RankModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleRank);

//排行榜实现类构造函数
ModuleRank::ModuleRank()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_RANK_RANK_REQUEST, &ModuleRank::RpcRank);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_RANK_RANK_REQUEST, new Some_Factory<RankRpcRankAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataRankV1";
		
}

//排行榜实现类析构函数
ModuleRank::~ModuleRank()
{

}


//获取模块ID
UINT8 ModuleRank::GetModuleId()
{
	return MODULE_ID_RANK;
}

//获取模块名字
TStr ModuleRank::GetModuleName()
{
	return "Rank";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleRank::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleRank::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleRank::GetInitializeOrder()
{
	return MODULE_ID_RANK;
}

//获取结束退出顺序
int ModuleRank::GetFinalizeOrder()
{
	return MODULE_ID_RANK;
}

//初始化
bool ModuleRank::Initialize()
{

	

	return true;
}

//结束退出
void ModuleRank::Finalize()
{

}


//毫秒级Tick回调
void ModuleRank::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleRank::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleRank::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleRank::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleRank::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleRank::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleRank::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleRank::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleRank::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleRank::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

