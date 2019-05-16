/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleStringNotice.cpp
* Author:       甘业清
* Description:  文本提示类，包含以下内容
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

#include "StringNoticeModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleStringNotice);

//文本提示实现类构造函数
ModuleStringNotice::ModuleStringNotice()
{



	
	m_mapSyncDataVersionName[1] = "SyncDataStringNoticeV1";
		
}

//文本提示实现类析构函数
ModuleStringNotice::~ModuleStringNotice()
{

}


//获取模块ID
UINT8 ModuleStringNotice::GetModuleId()
{
	return MODULE_ID_STRINGNOTICE;
}

//获取模块名字
TStr ModuleStringNotice::GetModuleName()
{
	return "StringNotice";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleStringNotice::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleStringNotice::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleStringNotice::GetInitializeOrder()
{
	return MODULE_ID_STRINGNOTICE;
}

//获取结束退出顺序
int ModuleStringNotice::GetFinalizeOrder()
{
	return MODULE_ID_STRINGNOTICE;
}

//初始化
bool ModuleStringNotice::Initialize()
{

	

	return true;
}

//结束退出
void ModuleStringNotice::Finalize()
{

}


//毫秒级Tick回调
void ModuleStringNotice::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleStringNotice::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleStringNotice::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleStringNotice::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleStringNotice::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleStringNotice::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleStringNotice::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleStringNotice::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleStringNotice::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleStringNotice::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

