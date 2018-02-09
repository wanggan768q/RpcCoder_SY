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
	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST        = 653,	//副本-->进入副本通知-->请求
	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST = 654,	//副本-->队长创建副本以后通知我-->请求
	RPC_CODE_DUNGEON_SETTLEMENT_NOTIFY           = 655,	//副本-->Settlement-->通知

	};

public:
	//副本实现类构造函数
	ModuleDungeon()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, &ModuleDungeon::RpcCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_CREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, &ModuleDungeon::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_EXITDUNGEON_REQUEST, new Some_Factory<DungeonRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, &ModuleDungeon::RpcEnterDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_ENTERDUNGEON_REQUEST, new Some_Factory<DungeonRpcEnterDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, &ModuleDungeon::RpcInformCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_DUNGEON_INFORMCREATEDUNGEON_REQUEST, new Some_Factory<DungeonRpcInformCreateDungeonAsk>());

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

	/********************************************************************************************
	* Function:       RpcEnterDungeon
	* Description:    副本-->进入副本通知同步调用操作函数
	* Input:          DungeonRpcEnterDungeonAskWraper& Ask 进入副本通知请求
	* Output:         DungeonRpcEnterDungeonReplyWraper& Reply 进入副本通知回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInformCreateDungeon
	* Description:    副本-->队长创建副本以后通知我同步调用操作函数
	* Input:          DungeonRpcInformCreateDungeonAskWraper& Ask 队长创建副本以后通知我请求
	* Output:         DungeonRpcInformCreateDungeonReplyWraper& Reply 队长创建副本以后通知我回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInformCreateDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSettlement
	* Description:    副本-->Settlement异步通知操作函数
	* Input:          DungeonRpcSettlementNotifyWraper& Notify Settlement通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSettlement( INT64 UserId, DungeonRpcSettlementNotifyWraper& Notify );



};

#endif