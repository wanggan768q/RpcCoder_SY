/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWorldBoss.cpp
* Author:       甘业清
* Description:  世界BOSS模块类，包含以下内容
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

#include "WorldBossModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleWorldBoss);

//世界BOSS模块实现类构造函数
ModuleWorldBoss::ModuleWorldBoss()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST, &ModuleWorldBoss::RpcWorldBossInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDBOSS_WORLDBOSSINFO_REQUEST, new Some_Factory<WorldBossRpcWorldBossInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST, &ModuleWorldBoss::RpcWorldBossRankInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDBOSS_WORLDBOSSRANKINFO_REQUEST, new Some_Factory<WorldBossRpcWorldBossRankInfoAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataWorldBossV1";
		
}

//世界BOSS模块实现类析构函数
ModuleWorldBoss::~ModuleWorldBoss()
{

}


//获取模块ID
UINT8 ModuleWorldBoss::GetModuleId()
{
	return MODULE_ID_WORLDBOSS;
}

//获取模块名字
TStr ModuleWorldBoss::GetModuleName()
{
	return "WorldBoss";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleWorldBoss::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleWorldBoss::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleWorldBoss::GetInitializeOrder()
{
	return MODULE_ID_WORLDBOSS;
}

//获取结束退出顺序
int ModuleWorldBoss::GetFinalizeOrder()
{
	return MODULE_ID_WORLDBOSS;
}

//初始化
bool ModuleWorldBoss::Initialize()
{

	

	return true;
}

//结束退出
void ModuleWorldBoss::Finalize()
{

}


//毫秒级Tick回调
void ModuleWorldBoss::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleWorldBoss::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleWorldBoss::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleWorldBoss::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleWorldBoss::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleWorldBoss::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleWorldBoss::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleWorldBoss::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleWorldBoss::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleWorldBoss::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

