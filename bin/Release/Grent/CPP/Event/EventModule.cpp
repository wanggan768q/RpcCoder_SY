/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEvent.cpp
* Author:       甘业清
* Description:  事件模块类，包含以下内容
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

#include "EventModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleEvent);

//事件模块实现类构造函数
ModuleEvent::ModuleEvent()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataEventV1";
		
}

//事件模块实现类析构函数
ModuleEvent::~ModuleEvent()
{

}


//获取模块ID
UINT8 ModuleEvent::GetModuleId()
{
	return MODULE_ID_EVENT;
}

//获取模块名字
TStr ModuleEvent::GetModuleName()
{
	return "Event";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleEvent::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleEvent::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleEvent::GetInitializeOrder()
{
	return MODULE_ID_EVENT;
}

//获取结束退出顺序
int ModuleEvent::GetFinalizeOrder()
{
	return MODULE_ID_EVENT;
}

//初始化
bool ModuleEvent::Initialize()
{

	

	return true;
}

//结束退出
void ModuleEvent::Finalize()
{

}


//毫秒级Tick回调
void ModuleEvent::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleEvent::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleEvent::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleEvent::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleEvent::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleEvent::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleEvent::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleEvent::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleEvent::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleEvent::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

