/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleDungeon.h
* Author:       甘业清
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


#include "ModuleBase.h"
#include "DungeonRpcWraper.h"




//副本实现类
class ModuleDungeon : public ModuleBase
{
	DECLARE_INSTANCE(ModuleDungeon);
public:
	friend class			ModuleMgr;

public:
	//副本实现类构造函数
	ModuleDungeon();
	
	//副本实现类析构函数
	virtual					~ModuleDungeon();

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

	/********************************************************************************************
	* Function:       SendToClientDungeonData
	* Description:    副本-->战况信息异步通知操作函数
	* Input:          DungeonRpcDungeonDataNotifyWraper& Notify 战况信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonData( INT64 UserId, DungeonRpcDungeonDataNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcDungeonSync
	* Description:    副本-->副本数据请求同步调用操作函数
	* Input:          DungeonRpcDungeonSyncAskWraper& Ask 副本数据请求请求
	* Output:         DungeonRpcDungeonSyncReplyWraper& Reply 副本数据请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDungeonSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDungeonListInfo
	* Description:    副本-->副本挑战信息同步调用操作函数
	* Input:          DungeonRpcDungeonListInfoAskWraper& Ask 副本挑战信息请求
	* Output:         DungeonRpcDungeonListInfoReplyWraper& Reply 副本挑战信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDungeonListInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCreateTutorial
	* Description:    副本-->创建序章副本同步调用操作函数
	* Input:          DungeonRpcCreateTutorialAskWraper& Ask 创建序章副本请求
	* Output:         DungeonRpcCreateTutorialReplyWraper& Reply 创建序章副本回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateTutorial( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcQuitTutorial
	* Description:    副本-->强制退出序章同步调用操作函数
	* Input:          DungeonRpcQuitTutorialAskWraper& Ask 强制退出序章请求
	* Output:         DungeonRpcQuitTutorialReplyWraper& Reply 强制退出序章回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcQuitTutorial( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDungeonTarget
	* Description:    副本-->副本目标异步通知操作函数
	* Input:          DungeonRpcDungeonTargetNotifyWraper& Notify 副本目标通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeonTarget( INT64 UserId, DungeonRpcDungeonTargetNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientTargetContentChange
	* Description:    副本-->副本子任务完成情况异步通知操作函数
	* Input:          DungeonRpcTargetContentChangeNotifyWraper& Notify 副本子任务完成情况通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTargetContentChange( INT64 UserId, DungeonRpcTargetContentChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientDungeon_Notify
	* Description:    副本-->副本提示异步通知操作函数
	* Input:          DungeonRpcDungeon_NotifyNotifyWraper& Notify 副本提示通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDungeon_Notify( INT64 UserId, DungeonRpcDungeon_NotifyNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif