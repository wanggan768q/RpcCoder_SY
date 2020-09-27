/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleScene.h
* Author:       郭晓波
* Description:  场景模块类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_SCENE_H
#define __MODULE_SCENE_H


#include "PacketFactory.h"
#include "Game/PacketMgr.h"
#include "SceneRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//场景模块实现类
class ModuleScene
{
	
public:
	//场景模块类的枚举定义
	enum ConstSceneE
	{
	MODULE_ID_SCENE                              = 3,	//场景模块模块ID
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 351,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 352,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 353,	//场景模块-->连接场景服务器-->请求
	RPC_CODE_SCENE_CREATEOBJ_NOTIFY              = 354,	//场景模块-->创建物体-->通知
	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST      = 355,	//场景模块-->SurroundingHuman-->请求
	RPC_CODE_SCENE_CENTERSCENE_NOTIFY            = 356,	//场景模块-->进入场景-->通知
	RPC_CODE_SCENE_SENTERSCENE_NOTIFY            = 357,	//场景模块-->进入场景返回-->通知
	RPC_CODE_SCENE_OBJDIE_NOTIFY                 = 358,	//场景模块-->ObjDie-->通知
	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST   = 359,	//场景模块-->collide 场景切换-->请求
	RPC_CODE_SCENE_ENTERMIRROR_REQUEST           = 360,	//场景模块-->进入镜像-->请求
	RPC_CODE_SCENE_SENTERMIRRORSCENE_NOTIFY      = 361,	//场景模块-->进入镜像场景-->通知
	RPC_CODE_SCENE_EXITMIRRORSCENE_REQUEST       = 362,	//场景模块-->退出镜像-->请求
	RPC_CODE_SCENE_CHANGESCENELEAVE_NOTIFY       = 363,	//场景模块-->ChangeSceneLeave-->通知
	RPC_CODE_SCENE_CHANGELINE_REQUEST            = 364,	//场景模块-->ChangeLine-->请求
	RPC_CODE_SCENE_PING_REQUEST                  = 365,	//场景模块-->ping-->请求
	RPC_CODE_SCENE_SYNCSCENELINESTATS_NOTIFY     = 366,	//场景模块-->同步场景分线繁忙状态-->通知
	RPC_CODE_SCENE_LOGOUTGAME_REQUEST            = 367,	//场景模块-->离开GameServer-->请求
	RPC_CODE_SCENE_KICKOUTGAME_NOTIFY            = 368,	//场景模块-->被提出场景-->通知
	RPC_CODE_SCENE_SHOWFILMFINISH_REQUEST        = 369,	//场景模块-->前端通知后端剧情动画播放完毕-->请求
	RPC_CODE_SCENE_SPECOBJPOS_REQUEST            = 370,	//场景模块-->SpecObjPos-->请求
	RPC_CODE_SCENE_DAYNIGHTCHANGE_NOTIFY         = 371,	//场景模块-->昼夜变化-->通知
	RPC_CODE_SCENE_WEATHERCHANGE_NOTIFY          = 372,	//场景模块-->天气变化-->通知
	RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST        = 373,	//场景模块-->ChangeZone-->请求
	RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST       = 374,	//场景模块-->返回源服-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//场景模块实现类构造函数
	ModuleScene()
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
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST, &ModuleScene::RpcWantChangeZone);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_WANTCHANGEZONE_REQUEST, new Some_Factory<SceneRpcWantChangeZoneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST, &ModuleScene::RpcReturnSrcServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_RETURNSRCSERVER_REQUEST, new Some_Factory<SceneRpcReturnSrcServerAsk>());

	}
	
	//场景模块实现类析构函数
	~ModuleScene(){}


	static ModuleScene & Instance()
	{
		static ModuleScene sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
public:
	/********************************************************************************************
	* Function:       RpcLoadSceneComplete
	* Description:    场景模块-->进入场景完成同步调用操作函数
	* Input:          SceneRpcLoadSceneCompleteAskWraper& Ask 进入场景完成请求
	* Output:         SceneRpcLoadSceneCompleteReplyWraper& Reply 进入场景完成回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLoadSceneComplete( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDeletePlayer
	* Description:    场景模块-->玩家离开视野异步通知操作函数
	* Input:          SceneRpcDeletePlayerNotifyWraper& Notify 删除玩家通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDeletePlayer( INT64 UserId, SceneRpcDeletePlayerNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcConnectGameServer
	* Description:    场景模块-->连接场景服务器同步调用操作函数
	* Input:          SceneRpcConnectGameServerAskWraper& Ask 连接场景服务器请求
	* Output:         SceneRpcConnectGameServerReplyWraper& Reply 连接场景服务器回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcConnectGameServer( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCreateObj
	* Description:    场景模块-->创建物体异步通知操作函数
	* Input:          SceneRpcCreateObjNotifyWraper& Notify 创建物体通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCreateObj( INT64 UserId, SceneRpcCreateObjNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSurroundingHuman
	* Description:    场景模块-->SurroundingHuman同步调用操作函数
	* Input:          SceneRpcSurroundingHumanAskWraper& Ask SurroundingHuman请求
	* Output:         SceneRpcSurroundingHumanReplyWraper& Reply SurroundingHuman回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSurroundingHuman( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCEnterScene
	* Description:    场景模块-->进入场景异步通知操作函数
	* Input:          SceneRpcCEnterSceneNotifyWraper& Notify 进入场景通知
	* Output:         无
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位无效
	********************************************************************************************/
	static int RpcCEnterScene(  CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSEnterScene
	* Description:    场景模块-->进入场景返回异步通知操作函数
	* Input:          SceneRpcSEnterSceneNotifyWraper& Notify 进入场景返回通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSEnterScene( INT64 UserId, SceneRpcSEnterSceneNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientObjDie
	* Description:    场景模块-->ObjDie异步通知操作函数
	* Input:          SceneRpcObjDieNotifyWraper& Notify ObjDie通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjDie( INT64 UserId, SceneRpcObjDieNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCollide_ChangeScene
	* Description:    场景模块-->collide 场景切换同步调用操作函数
	* Input:          SceneRpcCollide_ChangeSceneAskWraper& Ask collide请求
	* Output:         SceneRpcCollide_ChangeSceneReplyWraper& Reply collide回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCollide_ChangeScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEnterMirror
	* Description:    场景模块-->进入镜像同步调用操作函数
	* Input:          SceneRpcEnterMirrorAskWraper& Ask 进入镜像请求
	* Output:         SceneRpcEnterMirrorReplyWraper& Reply 进入镜像回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterMirror( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSEnterMirrorScene
	* Description:    场景模块-->进入镜像场景异步通知操作函数
	* Input:          SceneRpcSEnterMirrorSceneNotifyWraper& Notify 进入镜像场景通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSEnterMirrorScene( INT64 UserId, SceneRpcSEnterMirrorSceneNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcExitMirrorScene
	* Description:    场景模块-->退出镜像同步调用操作函数
	* Input:          SceneRpcExitMirrorSceneAskWraper& Ask 退出镜像请求
	* Output:         SceneRpcExitMirrorSceneReplyWraper& Reply 退出镜像回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcExitMirrorScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientChangeSceneLeave
	* Description:    场景模块-->ChangeSceneLeave异步通知操作函数
	* Input:          SceneRpcChangeSceneLeaveNotifyWraper& Notify ChangeSceneLeave通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChangeSceneLeave( INT64 UserId, SceneRpcChangeSceneLeaveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcChangeLine
	* Description:    场景模块-->ChangeLine同步调用操作函数
	* Input:          SceneRpcChangeLineAskWraper& Ask ChangeLine请求
	* Output:         SceneRpcChangeLineReplyWraper& Reply ChangeLine回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeLine( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcPing
	* Description:    场景模块-->ping同步调用操作函数
	* Input:          SceneRpcPingAskWraper& Ask ping请求
	* Output:         SceneRpcPingReplyWraper& Reply ping回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPing( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSyncSceneLineStats
	* Description:    场景模块-->同步场景分线繁忙状态异步通知操作函数
	* Input:          SceneRpcSyncSceneLineStatsNotifyWraper& Notify 同步场景分线繁忙状态通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSyncSceneLineStats( INT64 UserId, SceneRpcSyncSceneLineStatsNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcLogOutGame
	* Description:    场景模块-->离开GameServer同步调用操作函数
	* Input:          SceneRpcLogOutGameAskWraper& Ask 离开GameServer请求
	* Output:         SceneRpcLogOutGameReplyWraper& Reply 离开GameServer回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogOutGame( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientKickOutGame
	* Description:    场景模块-->被提出场景异步通知操作函数
	* Input:          SceneRpcKickOutGameNotifyWraper& Notify 被提出场景通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKickOutGame( INT64 UserId, SceneRpcKickOutGameNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcShowFilmFinish
	* Description:    场景模块-->前端通知后端剧情动画播放完毕同步调用操作函数
	* Input:          SceneRpcShowFilmFinishAskWraper& Ask 前端通知后端剧情动画播放完毕请求
	* Output:         SceneRpcShowFilmFinishReplyWraper& Reply 前端通知后端剧情动画播放完毕回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcShowFilmFinish( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSpecObjPos
	* Description:    场景模块-->SpecObjPos同步调用操作函数
	* Input:          SceneRpcSpecObjPosAskWraper& Ask SpecObjPos请求
	* Output:         SceneRpcSpecObjPosReplyWraper& Reply SpecObjPos回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSpecObjPos( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDayNightChange
	* Description:    场景模块-->昼夜变化异步通知操作函数
	* Input:          SceneRpcDayNightChangeNotifyWraper& Notify 昼夜变化通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDayNightChange( INT64 UserId, SceneRpcDayNightChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientWeatherChange
	* Description:    场景模块-->天气变化异步通知操作函数
	* Input:          SceneRpcWeatherChangeNotifyWraper& Notify 天气变化通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientWeatherChange( INT64 UserId, SceneRpcWeatherChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcWantChangeZone
	* Description:    场景模块-->ChangeZone同步调用操作函数
	* Input:          SceneRpcWantChangeZoneAskWraper& Ask ChangeZone请求
	* Output:         SceneRpcWantChangeZoneReplyWraper& Reply ChangeZone回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcWantChangeZone( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcReturnSrcServer
	* Description:    场景模块-->返回源服同步调用操作函数
	* Input:          SceneRpcReturnSrcServerAskWraper& Ask 返回源服请求
	* Output:         SceneRpcReturnSrcServerReplyWraper& Reply 返回源服回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReturnSrcServer( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif