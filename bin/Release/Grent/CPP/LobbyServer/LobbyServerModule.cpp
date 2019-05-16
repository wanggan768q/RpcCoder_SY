/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleLobbyServer.cpp
* Author:       甘业清
* Description:  大厅服务器类，包含以下内容
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

#include "LobbyServerModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleLobbyServer);

//大厅服务器实现类构造函数
ModuleLobbyServer::ModuleLobbyServer()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST, &ModuleLobbyServer::RpcGetServerList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_LOBBYSERVER_GETSERVERLIST_REQUEST, new Some_Factory<LobbyServerRpcGetServerListAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataLobbyServerV1";
		
}

//大厅服务器实现类析构函数
ModuleLobbyServer::~ModuleLobbyServer()
{

}


//获取模块ID
UINT8 ModuleLobbyServer::GetModuleId()
{
	return MODULE_ID_LOBBYSERVER;
}

//获取模块名字
TStr ModuleLobbyServer::GetModuleName()
{
	return "LobbyServer";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleLobbyServer::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleLobbyServer::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleLobbyServer::GetInitializeOrder()
{
	return MODULE_ID_LOBBYSERVER;
}

//获取结束退出顺序
int ModuleLobbyServer::GetFinalizeOrder()
{
	return MODULE_ID_LOBBYSERVER;
}

//初始化
bool ModuleLobbyServer::Initialize()
{

	

	return true;
}

//结束退出
void ModuleLobbyServer::Finalize()
{

}


//毫秒级Tick回调
void ModuleLobbyServer::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleLobbyServer::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleLobbyServer::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleLobbyServer::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleLobbyServer::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleLobbyServer::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleLobbyServer::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleLobbyServer::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleLobbyServer::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleLobbyServer::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

