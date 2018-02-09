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
	RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST   = 853,	//世界服务器模块-->创建副本通知-->请求
	RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST      = 854,	//世界服务器模块-->CreateTeam-->请求
	RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST        = 855,	//世界服务器模块-->JoinTeam-->请求
	RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST       = 856,	//世界服务器模块-->LeaveTeam-->请求
	RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST= 857,	//世界服务器模块-->AppointTeamLeader-->请求
	RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST     = 858,	//世界服务器模块-->DismissTeam-->请求
	RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST      = 859,	//世界服务器模块-->KickMember-->请求
	RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST       = 860,	//世界服务器模块-->ApplyTeam-->请求
	RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST= 861,	//世界服务器模块-->AgreeTeamApplicant-->请求
	RPC_CODE_WORLDSERVER_LOGIN_REQUEST           = 862,	//世界服务器模块-->Login-->请求
	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST  = 863,	//世界服务器模块-->UpdateRoleInfo-->请求
	RPC_CODE_WORLDSERVER_LOGOUT_REQUEST          = 864,	//世界服务器模块-->Logout-->请求
	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST= 865,	//世界服务器模块-->CreateDungeonNotify-->请求
	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST     = 866,	//世界服务器模块-->ExitDungeon-->请求
	RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST  = 867,	//世界服务器模块-->ReleaseDungeon-->请求

	};

public:
	//世界服务器模块实现类构造函数
	ModuleWorldServer()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, &ModuleWorldServer::RpcChangeScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CHANGESCENE_REQUEST, new Some_Factory<WorldServerRpcChangeSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, &ModuleWorldServer::RpcEnterScene);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_ENTERSCENE_REQUEST, new Some_Factory<WorldServerRpcEnterSceneAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST, &ModuleWorldServer::RpcCreateDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CREATEDUNGEON_REQUEST, new Some_Factory<WorldServerRpcCreateDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST, &ModuleWorldServer::RpcCreateTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CREATETEAM_REQUEST, new Some_Factory<WorldServerRpcCreateTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST, &ModuleWorldServer::RpcJoinTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_JOINTEAM_REQUEST, new Some_Factory<WorldServerRpcJoinTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST, &ModuleWorldServer::RpcLeaveTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_LEAVETEAM_REQUEST, new Some_Factory<WorldServerRpcLeaveTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST, &ModuleWorldServer::RpcAppointTeamLeader);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_APPOINTTEAMLEADER_REQUEST, new Some_Factory<WorldServerRpcAppointTeamLeaderAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST, &ModuleWorldServer::RpcDismissTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_DISMISSTEAM_REQUEST, new Some_Factory<WorldServerRpcDismissTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST, &ModuleWorldServer::RpcKickMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_KICKMEMBER_REQUEST, new Some_Factory<WorldServerRpcKickMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST, &ModuleWorldServer::RpcApplyTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_APPLYTEAM_REQUEST, new Some_Factory<WorldServerRpcApplyTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST, &ModuleWorldServer::RpcAgreeTeamApplicant);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_AGREETEAMAPPLICANT_REQUEST, new Some_Factory<WorldServerRpcAgreeTeamApplicantAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_LOGIN_REQUEST, &ModuleWorldServer::RpcLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_LOGIN_REQUEST, new Some_Factory<WorldServerRpcLoginAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, &ModuleWorldServer::RpcUpdateRoleInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_UPDATEROLEINFO_REQUEST, new Some_Factory<WorldServerRpcUpdateRoleInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_LOGOUT_REQUEST, &ModuleWorldServer::RpcLogout);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_LOGOUT_REQUEST, new Some_Factory<WorldServerRpcLogoutAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, &ModuleWorldServer::RpcCreateDungeonNotify);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_CREATEDUNGEONNOTIFY_REQUEST, new Some_Factory<WorldServerRpcCreateDungeonNotifyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, &ModuleWorldServer::RpcExitDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_EXITDUNGEON_REQUEST, new Some_Factory<WorldServerRpcExitDungeonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST, &ModuleWorldServer::RpcReleaseDungeon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WORLDSERVER_RELEASEDUNGEON_REQUEST, new Some_Factory<WorldServerRpcReleaseDungeonAsk>());

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

	/********************************************************************************************
	* Function:       RpcCreateDungeon
	* Description:    世界服务器模块-->创建副本通知同步调用操作函数
	* Input:          WorldServerRpcCreateDungeonAskWraper& Ask 创建副本通知请求
	* Output:         WorldServerRpcCreateDungeonReplyWraper& Reply 创建副本通知回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateDungeon( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateTeam
	* Description:    世界服务器模块-->CreateTeam同步调用操作函数
	* Input:          WorldServerRpcCreateTeamAskWraper& Ask CreateTeam请求
	* Output:         WorldServerRpcCreateTeamReplyWraper& Reply CreateTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcJoinTeam
	* Description:    世界服务器模块-->JoinTeam同步调用操作函数
	* Input:          WorldServerRpcJoinTeamAskWraper& Ask JoinTeam请求
	* Output:         WorldServerRpcJoinTeamReplyWraper& Reply JoinTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcJoinTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLeaveTeam
	* Description:    世界服务器模块-->LeaveTeam同步调用操作函数
	* Input:          WorldServerRpcLeaveTeamAskWraper& Ask LeaveTeam请求
	* Output:         WorldServerRpcLeaveTeamReplyWraper& Reply LeaveTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLeaveTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAppointTeamLeader
	* Description:    世界服务器模块-->AppointTeamLeader同步调用操作函数
	* Input:          WorldServerRpcAppointTeamLeaderAskWraper& Ask AppointTeamLeader请求
	* Output:         WorldServerRpcAppointTeamLeaderReplyWraper& Reply AppointTeamLeader回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAppointTeamLeader( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDismissTeam
	* Description:    世界服务器模块-->DismissTeam同步调用操作函数
	* Input:          WorldServerRpcDismissTeamAskWraper& Ask DismissTeam请求
	* Output:         WorldServerRpcDismissTeamReplyWraper& Reply DismissTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDismissTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcKickMember
	* Description:    世界服务器模块-->KickMember同步调用操作函数
	* Input:          WorldServerRpcKickMemberAskWraper& Ask KickMember请求
	* Output:         WorldServerRpcKickMemberReplyWraper& Reply KickMember回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcKickMember( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcApplyTeam
	* Description:    世界服务器模块-->ApplyTeam同步调用操作函数
	* Input:          WorldServerRpcApplyTeamAskWraper& Ask ApplyTeam请求
	* Output:         WorldServerRpcApplyTeamReplyWraper& Reply ApplyTeam回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcApplyTeam( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAgreeTeamApplicant
	* Description:    世界服务器模块-->AgreeTeamApplicant同步调用操作函数
	* Input:          WorldServerRpcAgreeTeamApplicantAskWraper& Ask AgreeTeamApplicant请求
	* Output:         WorldServerRpcAgreeTeamApplicantReplyWraper& Reply AgreeTeamApplicant回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAgreeTeamApplicant( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLogin
	* Description:    世界服务器模块-->Login同步调用操作函数
	* Input:          WorldServerRpcLoginAskWraper& Ask Login请求
	* Output:         WorldServerRpcLoginReplyWraper& Reply Login回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogin( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUpdateRoleInfo
	* Description:    世界服务器模块-->UpdateRoleInfo同步调用操作函数
	* Input:          WorldServerRpcUpdateRoleInfoAskWraper& Ask UpdateRoleInfo请求
	* Output:         WorldServerRpcUpdateRoleInfoReplyWraper& Reply UpdateRoleInfo回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUpdateRoleInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLogout
	* Description:    世界服务器模块-->Logout同步调用操作函数
	* Input:          WorldServerRpcLogoutAskWraper& Ask Logout请求
	* Output:         WorldServerRpcLogoutReplyWraper& Reply Logout回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLogout( CPlayer* pPlayer, CPacket* pPacket );

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
	* Function:       RpcReleaseDungeon
	* Description:    世界服务器模块-->ReleaseDungeon同步调用操作函数
	* Input:          WorldServerRpcReleaseDungeonAskWraper& Ask ReleaseDungeon请求
	* Output:         WorldServerRpcReleaseDungeonReplyWraper& Reply ReleaseDungeon回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReleaseDungeon( CPlayer* pPlayer, CPacket* pPacket );



};

#endif