/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFight.cpp
* Author:       甘业清
* Description:  战斗类，包含以下内容
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

#include "FightModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleFight);

//战斗实现类构造函数
ModuleFight::ModuleFight()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_FIGHT_USESKILL_REQUEST, &ModuleFight::RpcUseSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FIGHT_USESKILL_REQUEST, new Some_Factory<FightRpcUseSkillAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataFightV1";
		
}

//战斗实现类析构函数
ModuleFight::~ModuleFight()
{

}


//获取模块ID
UINT8 ModuleFight::GetModuleId()
{
	return MODULE_ID_FIGHT;
}

//获取模块名字
TStr ModuleFight::GetModuleName()
{
	return "Fight";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleFight::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleFight::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleFight::GetInitializeOrder()
{
	return MODULE_ID_FIGHT;
}

//获取结束退出顺序
int ModuleFight::GetFinalizeOrder()
{
	return MODULE_ID_FIGHT;
}

//初始化
bool ModuleFight::Initialize()
{

	

	return true;
}

//结束退出
void ModuleFight::Finalize()
{

}


//毫秒级Tick回调
void ModuleFight::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleFight::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleFight::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleFight::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleFight::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleFight::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleFight::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleFight::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleFight::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleFight::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

