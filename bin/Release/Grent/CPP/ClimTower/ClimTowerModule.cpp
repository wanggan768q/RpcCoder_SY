/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleClimTower.cpp
* Author:       甘业清
* Description:  爬塔玩法类，包含以下内容
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

#include "ClimTowerModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleClimTower);

//爬塔玩法实现类构造函数
ModuleClimTower::ModuleClimTower()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CLIMTOWER_ENTER_REQUEST, &ModuleClimTower::RpcEnter);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CLIMTOWER_ENTER_REQUEST, new Some_Factory<ClimTowerRpcEnterAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST, &ModuleClimTower::RpcChallenge);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CLIMTOWER_CHALLENGE_REQUEST, new Some_Factory<ClimTowerRpcChallengeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CLIMTOWER_RANK_REQUEST, &ModuleClimTower::RpcRank);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CLIMTOWER_RANK_REQUEST, new Some_Factory<ClimTowerRpcRankAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST, &ModuleClimTower::RpcFirstVicReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CLIMTOWER_FIRSTVICREWARD_REQUEST, new Some_Factory<ClimTowerRpcFirstVicRewardAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataClimTowerV1";
		
}

//爬塔玩法实现类析构函数
ModuleClimTower::~ModuleClimTower()
{

}


//获取模块ID
UINT8 ModuleClimTower::GetModuleId()
{
	return MODULE_ID_CLIMTOWER;
}

//获取模块名字
TStr ModuleClimTower::GetModuleName()
{
	return "ClimTower";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleClimTower::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleClimTower::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleClimTower::GetInitializeOrder()
{
	return MODULE_ID_CLIMTOWER;
}

//获取结束退出顺序
int ModuleClimTower::GetFinalizeOrder()
{
	return MODULE_ID_CLIMTOWER;
}

//初始化
bool ModuleClimTower::Initialize()
{

	

	return true;
}

//结束退出
void ModuleClimTower::Finalize()
{

}


//毫秒级Tick回调
void ModuleClimTower::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleClimTower::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleClimTower::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleClimTower::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleClimTower::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleClimTower::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleClimTower::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleClimTower::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleClimTower::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleClimTower::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

