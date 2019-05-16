/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleHuman.cpp
* Author:       甘业清
* Description:  玩家模块类，包含以下内容
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

#include "HumanModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleHuman);

//玩家模块实现类构造函数
ModuleHuman::ModuleHuman()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVE_REQUEST, &ModuleHuman::RpcMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVE_REQUEST, new Some_Factory<HumanRpcMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, &ModuleHuman::RpcStopMove);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_STOPMOVE_REQUEST, new Some_Factory<HumanRpcStopMoveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVECHECK_NOTIFY, &ModuleHuman::RpcMoveCheck);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVECHECK_NOTIFY, new Some_Factory<HumanRpcMoveCheckNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_RESPAWN_REQUEST, &ModuleHuman::RpcRespawn);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_RESPAWN_REQUEST, new Some_Factory<HumanRpcRespawnAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_MOVEPOS_REQUEST, &ModuleHuman::RpcMovePos);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_MOVEPOS_REQUEST, new Some_Factory<HumanRpcMovePosAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY, &ModuleHuman::RpcChangeAnimationState);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CHANGEANIMATIONSTATE_NOTIFY, new Some_Factory<HumanRpcChangeAnimationStateNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, &ModuleHuman::RpcFuncNotice);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_FUNCNOTICE_REQUEST, new Some_Factory<HumanRpcFuncNoticeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, &ModuleHuman::RpcFuncNoticeChange);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_FUNCNOTICECHANGE_REQUEST, new Some_Factory<HumanRpcFuncNoticeChangeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, &ModuleHuman::RpcClientAttributes);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_HUMAN_CLIENTATTRIBUTES_NOTIFY, new Some_Factory<HumanRpcClientAttributesNotify>());


	
	m_mapSyncDataVersionName[1] = "SyncDataHumanV1";
		
}

//玩家模块实现类析构函数
ModuleHuman::~ModuleHuman()
{

}


//获取模块ID
UINT8 ModuleHuman::GetModuleId()
{
	return MODULE_ID_HUMAN;
}

//获取模块名字
TStr ModuleHuman::GetModuleName()
{
	return "Human";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleHuman::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleHuman::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleHuman::GetInitializeOrder()
{
	return MODULE_ID_HUMAN;
}

//获取结束退出顺序
int ModuleHuman::GetFinalizeOrder()
{
	return MODULE_ID_HUMAN;
}

//初始化
bool ModuleHuman::Initialize()
{

	

	return true;
}

//结束退出
void ModuleHuman::Finalize()
{

}


//毫秒级Tick回调
void ModuleHuman::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleHuman::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleHuman::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleHuman::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleHuman::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleHuman::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleHuman::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleHuman::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleHuman::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleHuman::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

