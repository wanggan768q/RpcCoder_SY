/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWorldServer.h
* Author:       甘业清
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


#include "ModuleBase.h"
#include "WorldServerRpcWraper.h"




//世界服务器模块实现类
class ModuleWorldServer : public ModuleBase
{
	DECLARE_INSTANCE(ModuleWorldServer);
public:
	friend class			ModuleMgr;

public:
	//世界服务器模块实现类构造函数
	ModuleWorldServer();
	
	//世界服务器模块实现类析构函数
	virtual					~ModuleWorldServer();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:
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
	* Function:       RpcPlayCgTeam
	* Description:    世界服务器模块-->播放动画 队伍同步调用操作函数
	* Input:          WorldServerRpcPlayCgTeamAskWraper& Ask 播放动画 队伍请求
	* Output:         WorldServerRpcPlayCgTeamReplyWraper& Reply 播放动画 队伍回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPlayCgTeam( CPlayer* pPlayer, CPacket* pPacket );

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



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif