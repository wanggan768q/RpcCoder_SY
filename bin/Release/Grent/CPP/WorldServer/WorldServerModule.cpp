/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWorldServer.cpp
* Author:       甘业清
* Description:  世界服务器模块类，包含以下内容
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

#include "WorldServerModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleWorldServer);

//世界服务器模块实现类构造函数
ModuleWorldServer::ModuleWorldServer()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, &ModuleWorldServer::RpcUpdateRoleInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, new Some_Factory<WorldServerRpcUpdateRoleInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, &ModuleWorldServer::RpcCreateDungeonNotify);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, new Some_Factory<WorldServerRpcCreateDungeonNotifyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, &ModuleWorldServer::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, new Some_Factory<WorldServerRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST, &ModuleWorldServer::RpcUpdateTeamInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST, new Some_Factory<WorldServerRpcUpdateTeamInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST, &ModuleWorldServer::RpcPlayCgTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_PLAYCGTEAM_REQUEST, new Some_Factory<WorldServerRpcPlayCgTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST, &ModuleWorldServer::RpcSendMail);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST, new Some_Factory<WorldServerRpcSendMailAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST, &ModuleWorldServer::RpcChangeTeamType);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST, new Some_Factory<WorldServerRpcChangeTeamTypeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST, &ModuleWorldServer::RpcAutoMatch);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST, new Some_Factory<WorldServerRpcAutoMatchAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST, &ModuleWorldServer::RpcCancelMatch);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST, new Some_Factory<WorldServerRpcCancelMatchAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST, &ModuleWorldServer::RpcLoginGameServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST, new Some_Factory<WorldServerRpcLoginGameServerAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST, &ModuleWorldServer::RpcLogoutGameServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST, new Some_Factory<WorldServerRpcLogoutGameServerAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST, &ModuleWorldServer::RpcGetPlayerInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST, new Some_Factory<WorldServerRpcGetPlayerInfoAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataWorldServerV1";
		
}

//世界服务器模块实现类析构函数
ModuleWorldServer::~ModuleWorldServer()
{

}


//获取模块ID
UINT8 ModuleWorldServer::GetModuleId()
{
	return MODULE_ID_WORLDSERVER;
}

//获取模块名字
TStr ModuleWorldServer::GetModuleName()
{
	return "WorldServer";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleWorldServer::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleWorldServer::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleWorldServer::GetInitializeOrder()
{
	return MODULE_ID_WORLDSERVER;
}

//获取结束退出顺序
int ModuleWorldServer::GetFinalizeOrder()
{
	return MODULE_ID_WORLDSERVER;
}

//初始化
bool ModuleWorldServer::Initialize()
{

	

	return true;
}

//结束退出
void ModuleWorldServer::Finalize()
{

}


//毫秒级Tick回调
void ModuleWorldServer::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleWorldServer::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleWorldServer::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleWorldServer::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleWorldServer::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleWorldServer::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleWorldServer::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleWorldServer::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleWorldServer::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleWorldServer::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

