/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleScene.cpp
* Author:       甘业清
* Description:  场景模块类，包含以下内容
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

#include "SceneModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleScene);

//场景模块实现类构造函数
ModuleScene::ModuleScene()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, &ModuleScene::RpcLoadSceneComplete);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, new Some_Factory<SceneRpcLoadSceneCompleteAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, &ModuleScene::RpcConnectGameServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, new Some_Factory<SceneRpcConnectGameServerAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, &ModuleScene::RpcSurroundingHuman);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, new Some_Factory<SceneRpcSurroundingHumanAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CENTERSCENE_NOTIFY, &ModuleScene::RpcCEnterScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CENTERSCENE_NOTIFY, new Some_Factory<SceneRpcCEnterSceneNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, &ModuleScene::RpcCollide_ChangeScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, new Some_Factory<SceneRpcCollide_ChangeSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_ENTERMIRROR_REQUEST, &ModuleScene::RpcEnterMirror);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_ENTERMIRROR_REQUEST, new Some_Factory<SceneRpcEnterMirrorAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST, &ModuleScene::RpcExitMirrorScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST, new Some_Factory<SceneRpcExitMirrorSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CHANGELINE_REQUEST, &ModuleScene::RpcChangeLine);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CHANGELINE_REQUEST, new Some_Factory<SceneRpcChangeLineAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_PING_REQUEST, &ModuleScene::RpcPing);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_PING_REQUEST, new Some_Factory<SceneRpcPingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_LOGOUTGAME_REQUEST, &ModuleScene::RpcLogOutGame);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_LOGOUTGAME_REQUEST, new Some_Factory<SceneRpcLogOutGameAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST, &ModuleScene::RpcShowFilmFinish);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST, new Some_Factory<SceneRpcShowFilmFinishAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_SPECOBJPOS_REQUEST, &ModuleScene::RpcSpecObjPos);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_SPECOBJPOS_REQUEST, new Some_Factory<SceneRpcSpecObjPosAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataSceneV1";
		
}

//场景模块实现类析构函数
ModuleScene::~ModuleScene()
{

}


//获取模块ID
UINT8 ModuleScene::GetModuleId()
{
	return MODULE_ID_SCENE;
}

//获取模块名字
TStr ModuleScene::GetModuleName()
{
	return "Scene";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleScene::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleScene::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleScene::GetInitializeOrder()
{
	return MODULE_ID_SCENE;
}

//获取结束退出顺序
int ModuleScene::GetFinalizeOrder()
{
	return MODULE_ID_SCENE;
}

//初始化
bool ModuleScene::Initialize()
{

	

	return true;
}

//结束退出
void ModuleScene::Finalize()
{

}


//毫秒级Tick回调
void ModuleScene::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleScene::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleScene::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleScene::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleScene::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleScene::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleScene::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleScene::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleScene::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleScene::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

