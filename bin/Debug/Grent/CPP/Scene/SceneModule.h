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
	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST     = 351,	//场景模块-->进入场景完成-->请求
	RPC_CODE_SCENE_DELETEPLAYER_NOTIFY           = 352,	//场景模块-->玩家离开视野-->通知
	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST     = 353,	//场景模块-->连接场景服务器-->请求
	RPC_CODE_SCENE_CHANGESCENE_REQUEST           = 354,	//场景模块-->多线程移除场景上的玩家-->请求
	RPC_CODE_SCENE_CREATEOBJ_NOTIFY              = 355,	//场景模块-->创建物体-->通知
	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST      = 356,	//场景模块-->SurroundingHuman-->请求
	RPC_CODE_SCENE_CENTERSCENE_NOTIFY            = 357,	//场景模块-->进入场景-->通知
	RPC_CODE_SCENE_SENTERSCENE_NOTIFY            = 358,	//场景模块-->进入场景返回-->通知
	RPC_CODE_SCENE_OBJDIE_NOTIFY                 = 359,	//场景模块-->ObjDie-->通知
	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST   = 360,	//场景模块-->collide 场景切换-->请求

	};

public:
	//场景模块实现类构造函数
	ModuleScene()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, &ModuleScene::RpcLoadSceneComplete);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_LOADSCENECOMPLETE_REQUEST, new Some_Factory<SceneRpcLoadSceneCompleteAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, &ModuleScene::RpcConnectGameServer);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CONNECTGAMESERVER_REQUEST, new Some_Factory<SceneRpcConnectGameServerAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CHANGESCENE_REQUEST, &ModuleScene::RpcChangeScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CHANGESCENE_REQUEST, new Some_Factory<SceneRpcChangeSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, &ModuleScene::RpcSurroundingHuman);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_SURROUNDINGHUMAN_REQUEST, new Some_Factory<SceneRpcSurroundingHumanAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_CENTERSCENE_NOTIFY, &ModuleScene::RpcCEnterScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_CENTERSCENE_NOTIFY, new Some_Factory<SceneRpcCEnterSceneNotify>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, &ModuleScene::RpcCollide_ChangeScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SCENE_COLLIDE_CHANGESCENE_REQUEST, new Some_Factory<SceneRpcCollide_ChangeSceneAsk>());

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
	* Function:       RpcChangeScene
	* Description:    场景模块-->多线程移除场景上的玩家同步调用操作函数
	* Input:          SceneRpcChangeSceneAskWraper& Ask 多线程移除场景上的玩家请求
	* Output:         SceneRpcChangeSceneReplyWraper& Reply 多线程移除场景上的玩家回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeScene( CPlayer* pPlayer, CPacket* pPacket );

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



};

#endif