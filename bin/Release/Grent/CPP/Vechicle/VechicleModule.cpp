/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleVechicle.cpp
* Author:       甘业清
* Description:  载具（变身）类，包含以下内容
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

#include "VechicleModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleVechicle);

//载具（变身）实现类构造函数
ModuleVechicle::ModuleVechicle()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_VECHICLE_QUITVECHILE_REQUEST, &ModuleVechicle::RpcQuitVechile);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_VECHICLE_QUITVECHILE_REQUEST, new Some_Factory<VechicleRpcQuitVechileAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataVechicleV1";
		
}

//载具（变身）实现类析构函数
ModuleVechicle::~ModuleVechicle()
{

}


//获取模块ID
UINT8 ModuleVechicle::GetModuleId()
{
	return MODULE_ID_VECHICLE;
}

//获取模块名字
TStr ModuleVechicle::GetModuleName()
{
	return "Vechicle";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleVechicle::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleVechicle::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleVechicle::GetInitializeOrder()
{
	return MODULE_ID_VECHICLE;
}

//获取结束退出顺序
int ModuleVechicle::GetFinalizeOrder()
{
	return MODULE_ID_VECHICLE;
}

//初始化
bool ModuleVechicle::Initialize()
{

	

	return true;
}

//结束退出
void ModuleVechicle::Finalize()
{

}


//毫秒级Tick回调
void ModuleVechicle::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleVechicle::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleVechicle::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleVechicle::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleVechicle::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleVechicle::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleVechicle::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleVechicle::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleVechicle::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleVechicle::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

