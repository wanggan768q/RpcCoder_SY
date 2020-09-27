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
#include "Game/PacketMgr.h"
#include "WorldServerRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




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
	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST= 851,	//世界服务器模块-->CreateDungeonNotify-->请求
	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST     = 852,	//世界服务器模块-->ExitDungeon-->请求
	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST  = 853,	//世界服务器模块-->UpdateTeamInfo-->请求
	RPC_CODE_WORLDSERVER_SENDMAIL_REQUEST        = 854,	//世界服务器模块-->发送邮件-->请求
	RPC_CODE_WORLDSERVER_CHANGETEAMTYPE_REQUEST  = 855,	//世界服务器模块-->改变队伍类型-->请求
	RPC_CODE_WORLDSERVER_AUTOMATCH_REQUEST       = 856,	//世界服务器模块-->自动匹配-->请求
	RPC_CODE_WORLDSERVER_CANCELMATCH_REQUEST     = 857,	//世界服务器模块-->取消匹配-->请求
	RPC_CODE_WORLDSERVER_LOGINGAMESERVER_REQUEST = 858,	//世界服务器模块-->登录服务器-->请求
	RPC_CODE_WORLDSERVER_LOGOUTGAMESERVER_REQUEST= 859,	//世界服务器模块-->LoginGameServer-->请求
	RPC_CODE_WORLDSERVER_GETPLAYERINFO_REQUEST   = 860,	//世界服务器模块-->获取玩家信息-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//世界服务器模块实现类构造函数
	ModuleWorldServer()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, &ModuleWorldServer::RpcCreateDungeonNotify);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, new Some_Factory<WorldServerRpcCreateDungeonNotifyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, &ModuleWorldServer::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, new Some_Factory<WorldServerRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST, &ModuleWorldServer::RpcUpdateTeamInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_UPDATETEAMINFO_REQUEST, new Some_Factory<WorldServerRpcUpdateTeamInfoAsk>());
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

	}
	
	//世界服务器模块实现类析构函数
	~ModuleWorldServer(){}


	static ModuleWorldServer & Instance()
	{
		static ModuleWorldServer sInstance;
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
	* Function:       RpcCreateDungeonNotify
	* Description:    世界服务器模块-->CreateDungeonNotify同步调用操作函数
	* Input:          WorldServerRpcCreateDungeonNotifyAskWraper& Ask CreateDungeonNotify请求
	* Output:         WorldServerRpcCreateDungeonNotifyReplyWraper& Reply CreateDungeonNotify回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateDungeonNotify( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcExitDungeon
	* Description:    世界服务器模块-->ExitDungeon同步调用操作函数
	* Input:          WorldServerRpcExitDungeonAskWraper& Ask ExitDungeon请求
	* Output:         WorldServerRpcExitDungeonReplyWraper& Reply ExitDungeon回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcExitDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUpdateTeamInfo
	* Description:    世界服务器模块-->UpdateTeamInfo同步调用操作函数
	* Input:          WorldServerRpcUpdateTeamInfoAskWraper& Ask UpdateTeamInfo请求
	* Output:         WorldServerRpcUpdateTeamInfoReplyWraper& Reply UpdateTeamInfo回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUpdateTeamInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSendMail
	* Description:    世界服务器模块-->发送邮件同步调用操作函数
	* Input:          WorldServerRpcSendMailAskWraper& Ask 发送邮件请求
	* Output:         WorldServerRpcSendMailReplyWraper& Reply 发送邮件回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSendMail( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChangeTeamType
	* Description:    世界服务器模块-->改变队伍类型同步调用操作函数
	* Input:          WorldServerRpcChangeTeamTypeAskWraper& Ask 改变队伍类型请求
	* Output:         WorldServerRpcChangeTeamTypeReplyWraper& Reply 改变队伍类型回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeTeamType( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAutoMatch
	* Description:    世界服务器模块-->自动匹配同步调用操作函数
	* Input:          WorldServerRpcAutoMatchAskWraper& Ask 自动匹配请求
	* Output:         WorldServerRpcAutoMatchReplyWraper& Reply 自动匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAutoMatch( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCancelMatch
	* Description:    世界服务器模块-->取消匹配同步调用操作函数
	* Input:          WorldServerRpcCancelMatchAskWraper& Ask 取消匹配请求
	* Output:         WorldServerRpcCancelMatchReplyWraper& Reply 取消匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCancelMatch( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLoginGameServer
	* Description:    世界服务器模块-->登录服务器同步调用操作函数
	* Input:          WorldServerRpcLoginGameServerAskWraper& Ask Login请求
	* Output:         WorldServerRpcLoginGameServerReplyWraper& Reply 登录服务器回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLoginGameServer( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLogoutGameServer
	* Description:    世界服务器模块-->LoginGameServer同步调用操作函数
	* Input:          WorldServerRpcLogoutGameServerAskWraper& Ask Login回应
	* Output:         WorldServerRpcLogoutGameServerReplyWraper& Reply LoginGameServer回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogoutGameServer( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetPlayerInfo
	* Description:    世界服务器模块-->获取玩家信息同步调用操作函数
	* Input:          WorldServerRpcGetPlayerInfoAskWraper& Ask 获取玩家信息请求
	* Output:         WorldServerRpcGetPlayerInfoReplyWraper& Reply 获取玩家信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetPlayerInfo( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif