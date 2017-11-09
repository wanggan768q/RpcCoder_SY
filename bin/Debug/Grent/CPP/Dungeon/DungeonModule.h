/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleDungeon.h
* Author:       郭晓波
* Description:  副本类，包含以下内容
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

#ifndef __MODULE_DUNGEON_H
#define __MODULE_DUNGEON_H


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "DungeonRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//副本实现类
class ModuleDungeon
{
	
public:
	//副本类的枚举定义
	enum ConstDungeonE
	{
	MODULE_ID_DUNGEON                            = 6,	//副本模块ID
	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST       = 651,	//副本-->CreateDungeon-->请求
	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST         = 652,	//副本-->退出副本-->请求

	};

public:
	//副本实现类构造函数
	ModuleDungeon()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, &ModuleDungeon::RpcCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, &ModuleDungeon::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, new Some_Factory<DungeonRpcExitDungeonAsk>());

	}
	
	//副本实现类析构函数
	~ModuleDungeon(){}


	static ModuleDungeon Instance()
	{
		static ModuleDungeon sInstance;
		return sInstance;
	}
	
	bool Initialize();

public:
	/********************************************************************************************
	* Function:       RpcCreateDungeon
	* Description:    副本-->CreateDungeon同步调用操作函数
	* Input:          DungeonRpcCreateDungeonAskWraper& Ask CreateDungeon请求
	* Output:         DungeonRpcCreateDungeonReplyWraper& Reply CreateDungeon回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcExitDungeon
	* Description:    副本-->退出副本同步调用操作函数
	* Input:          DungeonRpcExitDungeonAskWraper& Ask 退出副本请求
	* Output:         DungeonRpcExitDungeonReplyWraper& Reply 退出副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcExitDungeon( CPlayer* pPlayer, CPacket* pPacket );



};

#endif