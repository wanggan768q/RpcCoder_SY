/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSmallMap.cpp
* Author:       甘业清
* Description:  小地图相关类，包含以下内容
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

#include "SmallMapModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleSmallMap);

//小地图相关实现类构造函数
ModuleSmallMap::ModuleSmallMap()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataSmallMapV1";
		
}

//小地图相关实现类析构函数
ModuleSmallMap::~ModuleSmallMap()
{

}


//获取模块ID
UINT8 ModuleSmallMap::GetModuleId()
{
	return MODULE_ID_SMALLMAP;
}

//获取模块名字
TStr ModuleSmallMap::GetModuleName()
{
	return "SmallMap";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleSmallMap::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleSmallMap::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleSmallMap::GetInitializeOrder()
{
	return MODULE_ID_SMALLMAP;
}

//获取结束退出顺序
int ModuleSmallMap::GetFinalizeOrder()
{
	return MODULE_ID_SMALLMAP;
}

//初始化
bool ModuleSmallMap::Initialize()
{

	

	return true;
}

//结束退出
void ModuleSmallMap::Finalize()
{

}


//毫秒级Tick回调
void ModuleSmallMap::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSmallMap::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSmallMap::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSmallMap::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSmallMap::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSmallMap::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleSmallMap::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSmallMap::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleSmallMap::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleSmallMap::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

