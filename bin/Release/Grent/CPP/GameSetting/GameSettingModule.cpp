/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleGameSetting.cpp
* Author:       甘业清
* Description:  游戏设置类，包含以下内容
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

#include "GameSettingModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleGameSetting);

//游戏设置实现类构造函数
ModuleGameSetting::ModuleGameSetting()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST, &ModuleGameSetting::RpcSyncGameSetting);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GAMESETTING_SYNCGAMESETTING_REQUEST, new Some_Factory<GameSettingRpcSyncGameSettingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_GAMESETTING_SETTING_REQUEST, &ModuleGameSetting::RpcSetting);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_GAMESETTING_SETTING_REQUEST, new Some_Factory<GameSettingRpcSettingAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataGameSettingV1";
		
}

//游戏设置实现类析构函数
ModuleGameSetting::~ModuleGameSetting()
{

}


//获取模块ID
UINT8 ModuleGameSetting::GetModuleId()
{
	return MODULE_ID_GAMESETTING;
}

//获取模块名字
TStr ModuleGameSetting::GetModuleName()
{
	return "GameSetting";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleGameSetting::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleGameSetting::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleGameSetting::GetInitializeOrder()
{
	return MODULE_ID_GAMESETTING;
}

//获取结束退出顺序
int ModuleGameSetting::GetFinalizeOrder()
{
	return MODULE_ID_GAMESETTING;
}

//初始化
bool ModuleGameSetting::Initialize()
{

	

	return true;
}

//结束退出
void ModuleGameSetting::Finalize()
{

}


//毫秒级Tick回调
void ModuleGameSetting::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleGameSetting::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleGameSetting::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleGameSetting::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleGameSetting::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleGameSetting::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleGameSetting::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleGameSetting::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleGameSetting::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleGameSetting::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

