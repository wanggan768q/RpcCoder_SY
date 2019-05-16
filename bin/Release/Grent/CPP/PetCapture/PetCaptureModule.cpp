/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePetCapture.cpp
* Author:       甘业清
* Description:  宠物捕获类，包含以下内容
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

#include "PetCaptureModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModulePetCapture);

//宠物捕获实现类构造函数
ModulePetCapture::ModulePetCapture()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_PETCAPTURE_CAPTURE_REQUEST, &ModulePetCapture::RpcCapture);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PETCAPTURE_CAPTURE_REQUEST, new Some_Factory<PetCaptureRpcCaptureAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST, &ModulePetCapture::RpcPetLocation);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PETCAPTURE_PETLOCATION_REQUEST, new Some_Factory<PetCaptureRpcPetLocationAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataPetCaptureV1";
		
}

//宠物捕获实现类析构函数
ModulePetCapture::~ModulePetCapture()
{

}


//获取模块ID
UINT8 ModulePetCapture::GetModuleId()
{
	return MODULE_ID_PETCAPTURE;
}

//获取模块名字
TStr ModulePetCapture::GetModuleName()
{
	return "PetCapture";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModulePetCapture::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModulePetCapture::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModulePetCapture::GetInitializeOrder()
{
	return MODULE_ID_PETCAPTURE;
}

//获取结束退出顺序
int ModulePetCapture::GetFinalizeOrder()
{
	return MODULE_ID_PETCAPTURE;
}

//初始化
bool ModulePetCapture::Initialize()
{

	

	return true;
}

//结束退出
void ModulePetCapture::Finalize()
{

}


//毫秒级Tick回调
void ModulePetCapture::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModulePetCapture::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModulePetCapture::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModulePetCapture::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModulePetCapture::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModulePetCapture::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModulePetCapture::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModulePetCapture::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModulePetCapture::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModulePetCapture::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

