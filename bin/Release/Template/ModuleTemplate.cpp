/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     Module$Template$.cpp
* Author:       甘业清
* Description:  $ModCName$类，包含以下内容
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

#include "$Template$Module.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(Module$Template$);

//$ModCName$实现类构造函数
Module$Template$::Module$Template$()
{

$CliOperationImpl$

	
	m_mapSyncDataVersionName[$SyncDataVersion$] = "SyncData$Template$V$SyncDataVersion$";
		
}

//$ModCName$实现类析构函数
Module$Template$::~Module$Template$()
{

}


//获取模块ID
UINT8 Module$Template$::GetModuleId()
{
	return MODULE_ID_$TEMPLATE$;
}

//获取模块名字
TStr Module$Template$::GetModuleName()
{
	return "$Template$";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> Module$Template$::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	Module$Template$::GetSavedDataType()
{
	return $DataSaveType$;
}


//获取初始化顺序
int	Module$Template$::GetInitializeOrder()
{
	return MODULE_ID_$TEMPLATE$;
}

//获取结束退出顺序
int Module$Template$::GetFinalizeOrder()
{
	return MODULE_ID_$TEMPLATE$;
}

//初始化
bool Module$Template$::Initialize()
{

$LoadConfig$	

	return true;
}

//结束退出
void Module$Template$::Finalize()
{

}


//毫秒级Tick回调
void Module$Template$::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void Module$Template$::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void Module$Template$::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void Module$Template$::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void Module$Template$::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void Module$Template$::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void Module$Template$::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void Module$Template$::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool Module$Template$::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void Module$Template$::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

