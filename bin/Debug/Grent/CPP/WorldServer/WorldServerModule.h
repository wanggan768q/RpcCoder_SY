/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleWorldServer.h
* Author:       郭晓波
* Description:  世界服务器模块类，包含以下内容
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

#ifndef __MODULE_WORLDSERVER_H
#define __MODULE_WORLDSERVER_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "WorldServerRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//世界服务器模块实现类
class ModuleWorldServer
{
	
public:
	//世界服务器模块类的枚举定义
	enum ConstWorldServerE
	{
	MODULE_ID_WORLDSERVER                        = 8,	//世界服务器模块模块ID
	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST     = 851,	//世界服务器模块-->通知世界服务器切换场景-->请求
	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST      = 852,	//世界服务器模块-->进入场景-->请求

	};

public:
	//世界服务器模块实现类构造函数
	ModuleWorldServer()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, &ModuleWorldServer::RpcChangeScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, new Some_Factory<WorldServerRpcChangeSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, &ModuleWorldServer::RpcEnterScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, new Some_Factory<WorldServerRpcEnterSceneAsk>());

	}
	
	//世界服务器模块实现类析构函数
	~ModuleWorldServer(){}


	static ModuleWorldServer Instance()
	{
		static ModuleWorldServer sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcChangeScene
	* Description:    世界服务器模块-->通知世界服务器切换场景同步调用操作函数
	* Input:          WorldServerRpcChangeSceneAskWraper& Ask 通知世界服务器切换场景请求
	* Output:         WorldServerRpcChangeSceneReplyWraper& Reply 通知世界服务器切换场景回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEnterScene
	* Description:    世界服务器模块-->进入场景同步调用操作函数
	* Input:          WorldServerRpcEnterSceneAskWraper& Ask 进入场景请求
	* Output:         WorldServerRpcEnterSceneReplyWraper& Reply 进入场景回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterScene( CPlayer* pPlayer, CPacket* pPacket );



};

#endif