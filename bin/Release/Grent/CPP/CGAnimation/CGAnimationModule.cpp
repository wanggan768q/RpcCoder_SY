/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleCGAnimation.cpp
* Author:       甘业清
* Description:  动画播放模块类，包含以下内容
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

#include "CGAnimationModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleCGAnimation);

//动画播放模块实现类构造函数
ModuleCGAnimation::ModuleCGAnimation()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CGANIMATION_CGPLAY_REQUEST, &ModuleCGAnimation::RpcCgPlay);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CGANIMATION_CGPLAY_REQUEST, new Some_Factory<CGAnimationRpcCgPlayAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CGANIMATION_CGSKIP_REQUEST, &ModuleCGAnimation::RpcCgSkip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CGANIMATION_CGSKIP_REQUEST, new Some_Factory<CGAnimationRpcCgSkipAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataCGAnimationV1";
		
}

//动画播放模块实现类析构函数
ModuleCGAnimation::~ModuleCGAnimation()
{

}


//获取模块ID
UINT8 ModuleCGAnimation::GetModuleId()
{
	return MODULE_ID_CGANIMATION;
}

//获取模块名字
TStr ModuleCGAnimation::GetModuleName()
{
	return "CGAnimation";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleCGAnimation::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleCGAnimation::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleCGAnimation::GetInitializeOrder()
{
	return MODULE_ID_CGANIMATION;
}

//获取结束退出顺序
int ModuleCGAnimation::GetFinalizeOrder()
{
	return MODULE_ID_CGANIMATION;
}

//初始化
bool ModuleCGAnimation::Initialize()
{

	

	return true;
}

//结束退出
void ModuleCGAnimation::Finalize()
{

}


//毫秒级Tick回调
void ModuleCGAnimation::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleCGAnimation::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleCGAnimation::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleCGAnimation::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleCGAnimation::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleCGAnimation::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleCGAnimation::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleCGAnimation::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleCGAnimation::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleCGAnimation::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

