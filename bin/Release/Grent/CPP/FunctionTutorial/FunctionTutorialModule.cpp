/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleFunctionTutorial.cpp
* Author:       甘业清
* Description:  功能引导类，包含以下内容
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

#include "FunctionTutorialModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleFunctionTutorial);

//功能引导实现类构造函数
ModuleFunctionTutorial::ModuleFunctionTutorial()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST, &ModuleFunctionTutorial::RpcSyncFunctionStep);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FUNCTIONTUTORIAL_SYNCFUNCTIONSTEP_REQUEST, new Some_Factory<FunctionTutorialRpcSyncFunctionStepAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST, &ModuleFunctionTutorial::RpcFinishStep);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FUNCTIONTUTORIAL_FINISHSTEP_REQUEST, new Some_Factory<FunctionTutorialRpcFinishStepAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST, &ModuleFunctionTutorial::RpcActiveStep);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_FUNCTIONTUTORIAL_ACTIVESTEP_REQUEST, new Some_Factory<FunctionTutorialRpcActiveStepAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataFunctionTutorialV1";
		
}

//功能引导实现类析构函数
ModuleFunctionTutorial::~ModuleFunctionTutorial()
{

}


//获取模块ID
UINT8 ModuleFunctionTutorial::GetModuleId()
{
	return MODULE_ID_FUNCTIONTUTORIAL;
}

//获取模块名字
TStr ModuleFunctionTutorial::GetModuleName()
{
	return "FunctionTutorial";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleFunctionTutorial::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleFunctionTutorial::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleFunctionTutorial::GetInitializeOrder()
{
	return MODULE_ID_FUNCTIONTUTORIAL;
}

//获取结束退出顺序
int ModuleFunctionTutorial::GetFinalizeOrder()
{
	return MODULE_ID_FUNCTIONTUTORIAL;
}

//初始化
bool ModuleFunctionTutorial::Initialize()
{

	

	return true;
}

//结束退出
void ModuleFunctionTutorial::Finalize()
{

}


//毫秒级Tick回调
void ModuleFunctionTutorial::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleFunctionTutorial::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleFunctionTutorial::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleFunctionTutorial::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleFunctionTutorial::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleFunctionTutorial::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleFunctionTutorial::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleFunctionTutorial::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleFunctionTutorial::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleFunctionTutorial::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

