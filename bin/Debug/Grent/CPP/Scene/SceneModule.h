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
#include "include/PacketMgr.h"
#include "SceneRpc.pb.h"
#include <memory>





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
	RPC_CODE_SCENE_ENTERSCENE_REQUEST            = 351,	//场景模块-->进入场景-->请求
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 352,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_NEWPLAYER_NOTIFY              = 353,	//场景模块-->新玩家进入视野-->通知
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 354,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 355,	//场景模块-->连接场景服务器-->请求

	};

public:
	//场景模块实现类构造函数
	ModuleScene()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_ENTERSCENE_REQUEST, &ModuleScene::RpcEnterScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_ENTERSCENE_REQUEST, new Some_Factory<SceneRpcEnterSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, &ModuleScene::RpcLoadSceneComplete);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, new Some_Factory<SceneRpcLoadSceneCompleteAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, &ModuleScene::RpcConnectGameServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, new Some_Factory<SceneRpcConnectGameServerAsk>());

	}
	
	//场景模块实现类析构函数
	~ModuleScene(){}


	static ModuleScene Instance()
	{
		static ModuleScene sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcEnterScene
	* Description:    场景模块-->进入场景同步调用操作函数
	* Input:          SceneRpcEnterSceneAskWraper& Ask 进入场景请求
	* Output:         SceneRpcEnterSceneReplyWraper& Reply 进入场景回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterScene( CPlayer* pPlayer, CPacket* pPacket );

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
	* Function:       SendToClientNewPlayer
	* Description:    场景模块-->新玩家进入视野异步通知操作函数
	* Input:          SceneRpcNewPlayerNotifyWraper& Notify 新玩家进入视野通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewPlayer( INT64 UserId, SceneRpcNewPlayerNotifyWraper& Notify );

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



};

#endif