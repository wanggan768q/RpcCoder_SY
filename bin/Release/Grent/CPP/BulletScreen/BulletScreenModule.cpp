/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBulletScreen.cpp
* Author:       甘业清
* Description:  弹幕类，包含以下内容
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

#include "BulletScreenModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleBulletScreen);

//弹幕实现类构造函数
ModuleBulletScreen::ModuleBulletScreen()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST, &ModuleBulletScreen::RpcBulletScreenOpt);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BULLETSCREEN_BULLETSCREENOPT_REQUEST, new Some_Factory<BulletScreenRpcBulletScreenOptAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST, &ModuleBulletScreen::RpcCGBulletScreen);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BULLETSCREEN_CGBULLETSCREEN_REQUEST, new Some_Factory<BulletScreenRpcCGBulletScreenAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST, &ModuleBulletScreen::RpcSendBulletScreenCG);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BULLETSCREEN_SENDBULLETSCREENCG_REQUEST, new Some_Factory<BulletScreenRpcSendBulletScreenCGAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataBulletScreenV1";
		
}

//弹幕实现类析构函数
ModuleBulletScreen::~ModuleBulletScreen()
{

}


//获取模块ID
UINT8 ModuleBulletScreen::GetModuleId()
{
	return MODULE_ID_BULLETSCREEN;
}

//获取模块名字
TStr ModuleBulletScreen::GetModuleName()
{
	return "BulletScreen";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleBulletScreen::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleBulletScreen::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleBulletScreen::GetInitializeOrder()
{
	return MODULE_ID_BULLETSCREEN;
}

//获取结束退出顺序
int ModuleBulletScreen::GetFinalizeOrder()
{
	return MODULE_ID_BULLETSCREEN;
}

//初始化
bool ModuleBulletScreen::Initialize()
{

	

	return true;
}

//结束退出
void ModuleBulletScreen::Finalize()
{

}


//毫秒级Tick回调
void ModuleBulletScreen::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBulletScreen::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBulletScreen::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBulletScreen::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBulletScreen::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBulletScreen::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleBulletScreen::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBulletScreen::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleBulletScreen::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleBulletScreen::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

