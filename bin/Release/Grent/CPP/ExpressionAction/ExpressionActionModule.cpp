/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleExpressionAction.cpp
* Author:       甘业清
* Description:  表情动作类，包含以下内容
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

#include "ExpressionActionModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleExpressionAction);

//表情动作实现类构造函数
ModuleExpressionAction::ModuleExpressionAction()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST, &ModuleExpressionAction::RpcSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EXPRESSIONACTION_SYNC_REQUEST, new Some_Factory<ExpressionActionRpcSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST, &ModuleExpressionAction::RpcSetWheel);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EXPRESSIONACTION_SETWHEEL_REQUEST, new Some_Factory<ExpressionActionRpcSetWheelAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST, &ModuleExpressionAction::RpcUseAction);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_EXPRESSIONACTION_USEACTION_REQUEST, new Some_Factory<ExpressionActionRpcUseActionAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataExpressionActionV1";
		
}

//表情动作实现类析构函数
ModuleExpressionAction::~ModuleExpressionAction()
{

}


//获取模块ID
UINT8 ModuleExpressionAction::GetModuleId()
{
	return MODULE_ID_EXPRESSIONACTION;
}

//获取模块名字
TStr ModuleExpressionAction::GetModuleName()
{
	return "ExpressionAction";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleExpressionAction::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleExpressionAction::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleExpressionAction::GetInitializeOrder()
{
	return MODULE_ID_EXPRESSIONACTION;
}

//获取结束退出顺序
int ModuleExpressionAction::GetFinalizeOrder()
{
	return MODULE_ID_EXPRESSIONACTION;
}

//初始化
bool ModuleExpressionAction::Initialize()
{

	

	return true;
}

//结束退出
void ModuleExpressionAction::Finalize()
{

}


//毫秒级Tick回调
void ModuleExpressionAction::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleExpressionAction::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleExpressionAction::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleExpressionAction::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleExpressionAction::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleExpressionAction::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleExpressionAction::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleExpressionAction::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleExpressionAction::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleExpressionAction::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

