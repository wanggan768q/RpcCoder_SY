/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBaseAttr.cpp
* Author:       甘业清
* Description:  基础数据类，包含以下内容
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

#include "BaseAttrModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleBaseAttr);

//基础数据实现类构造函数
ModuleBaseAttr::ModuleBaseAttr()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_BASEATTR_SYNCDATA_REQUEST, &ModuleBaseAttr::RpcSyncData);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BASEATTR_SYNCDATA_REQUEST, new Some_Factory<BaseAttrRpcSyncDataAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataBaseAttrV1";
		
}

//基础数据实现类析构函数
ModuleBaseAttr::~ModuleBaseAttr()
{

}


//获取模块ID
UINT8 ModuleBaseAttr::GetModuleId()
{
	return MODULE_ID_BASEATTR;
}

//获取模块名字
TStr ModuleBaseAttr::GetModuleName()
{
	return "BaseAttr";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleBaseAttr::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleBaseAttr::GetSavedDataType()
{
	return SAVE_USER_DATA;
}


//获取初始化顺序
int	ModuleBaseAttr::GetInitializeOrder()
{
	return MODULE_ID_BASEATTR;
}

//获取结束退出顺序
int ModuleBaseAttr::GetFinalizeOrder()
{
	return MODULE_ID_BASEATTR;
}

//初始化
bool ModuleBaseAttr::Initialize()
{

	

	return true;
}

//结束退出
void ModuleBaseAttr::Finalize()
{

}


//毫秒级Tick回调
void ModuleBaseAttr::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleBaseAttr::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleBaseAttr::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleBaseAttr::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleBaseAttr::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleBaseAttr::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleBaseAttr::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleBaseAttr::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleBaseAttr::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleBaseAttr::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

