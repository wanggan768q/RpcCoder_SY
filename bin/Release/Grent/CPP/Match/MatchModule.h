/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMatch.h
* Author:       甘业清
* Description:  匹配模块类，包含以下内容
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

#ifndef __MODULE_MATCH_H
#define __MODULE_MATCH_H


#include "ModuleBase.h"
#include "MatchRpcWraper.h"




//匹配模块实现类
class ModuleMatch : public ModuleBase
{
	DECLARE_INSTANCE(ModuleMatch);
public:
	friend class			ModuleMgr;

public:
	//匹配模块实现类构造函数
	ModuleMatch();
	
	//匹配模块实现类析构函数
	virtual					~ModuleMatch();

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
	* Function:       RpcAutoMatch
	* Description:    匹配模块-->匹配同步调用操作函数
	* Input:          MatchRpcAutoMatchAskWraper& Ask 匹配请求
	* Output:         MatchRpcAutoMatchReplyWraper& Reply 匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAutoMatch( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCancelMatch
	* Description:    匹配模块-->取消匹配同步调用操作函数
	* Input:          MatchRpcCancelMatchAskWraper& Ask 取消匹配请求
	* Output:         MatchRpcCancelMatchReplyWraper& Reply 取消匹配回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCancelMatch( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCancelMatchNotify
	* Description:    匹配模块-->取消匹配通知异步通知操作函数
	* Input:          MatchRpcCancelMatchNotifyNotifyWraper& Notify 取消匹配通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCancelMatchNotify( INT64 UserId, MatchRpcCancelMatchNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientPrepareRoom
	* Description:    匹配模块-->开始准备进入房间异步通知操作函数
	* Input:          MatchRpcPrepareRoomNotifyWraper& Notify 开始准备进入房间通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPrepareRoom( INT64 UserId, MatchRpcPrepareRoomNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReady
	* Description:    匹配模块-->准备同步调用操作函数
	* Input:          MatchRpcReadyAskWraper& Ask 准备请求
	* Output:         MatchRpcReadyReplyWraper& Reply 准备回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReady( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCancelReady
	* Description:    匹配模块-->取消准备同步调用操作函数
	* Input:          MatchRpcCancelReadyAskWraper& Ask 取消准备请求
	* Output:         MatchRpcCancelReadyReplyWraper& Reply 取消准备回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCancelReady( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRoomCancel
	* Description:    匹配模块-->房间取消异步通知操作函数
	* Input:          MatchRpcRoomCancelNotifyWraper& Notify 房间取消通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRoomCancel( INT64 UserId, MatchRpcRoomCancelNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientMemberReady
	* Description:    匹配模块-->成员准备异步通知操作函数
	* Input:          MatchRpcMemberReadyNotifyWraper& Notify 成员准备通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMemberReady( INT64 UserId, MatchRpcMemberReadyNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif