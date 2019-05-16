/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleCampFigth.h
* Author:       甘业清
* Description:  CampFigth类，包含以下内容
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

#ifndef __MODULE_CAMPFIGTH_H
#define __MODULE_CAMPFIGTH_H


#include "ModuleBase.h"
#include "CampFigthRpcWraper.h"




//CampFigth实现类
class ModuleCampFigth : public ModuleBase
{
	DECLARE_INSTANCE(ModuleCampFigth);
public:
	friend class			ModuleMgr;

public:
	//CampFigth实现类构造函数
	ModuleCampFigth();
	
	//CampFigth实现类析构函数
	virtual					~ModuleCampFigth();

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
	* Function:       RpcMilitaryBroken
	* Description:    CampFigth-->MilitaryBroken同步调用操作函数
	* Input:          CampFigthRpcMilitaryBrokenAskWraper& Ask MilitaryBroken请求
	* Output:         CampFigthRpcMilitaryBrokenReplyWraper& Reply MilitaryBroken回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMilitaryBroken( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCampFightContribution
	* Description:    CampFigth-->CampFightContribution异步通知操作函数
	* Input:          CampFigthRpcCampFightContributionNotifyWraper& Notify CampFightContribution通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCampFightContribution( INT64 UserId, CampFigthRpcCampFightContributionNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientObjKillBroadcast
	* Description:    CampFigth-->ObjKillBroadcast异步通知操作函数
	* Input:          CampFigthRpcObjKillBroadcastNotifyWraper& Notify ObjKillBroadcast通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjKillBroadcast( INT64 UserId, CampFigthRpcObjKillBroadcastNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientNpcBirth
	* Description:    CampFigth-->NpcBirth异步通知操作函数
	* Input:          CampFigthRpcNpcBirthNotifyWraper& Notify NpcBirth通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNpcBirth( INT64 UserId, CampFigthRpcNpcBirthNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcGetMilitaryValue
	* Description:    CampFigth-->GetMilitaryValue同步调用操作函数
	* Input:          CampFigthRpcGetMilitaryValueAskWraper& Ask GetMilitaryValue请求
	* Output:         CampFigthRpcGetMilitaryValueReplyWraper& Reply GetMilitaryValue回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetMilitaryValue( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientKillDeadInfo
	* Description:    CampFigth-->KillDeadInfo异步通知操作函数
	* Input:          CampFigthRpcKillDeadInfoNotifyWraper& Notify KillDeadInfo通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientKillDeadInfo( INT64 UserId, CampFigthRpcKillDeadInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcWorship
	* Description:    CampFigth-->Worship同步调用操作函数
	* Input:          CampFigthRpcWorshipAskWraper& Ask Worship请求
	* Output:         CampFigthRpcWorshipReplyWraper& Reply Worship回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcWorship( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcWorshipRank
	* Description:    CampFigth-->WorshipRank同步调用操作函数
	* Input:          CampFigthRpcWorshipRankAskWraper& Ask WorshipRank请求
	* Output:         CampFigthRpcWorshipRankReplyWraper& Reply WorshipRank回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcWorshipRank( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewSeason
	* Description:    CampFigth-->新赛季异步通知操作函数
	* Input:          CampFigthRpcNewSeasonNotifyWraper& Notify 新赛季通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewSeason( INT64 UserId, CampFigthRpcNewSeasonNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSyncRankReward
	* Description:    CampFigth-->同步段位奖励同步调用操作函数
	* Input:          CampFigthRpcSyncRankRewardAskWraper& Ask 同步段位奖励请求
	* Output:         CampFigthRpcSyncRankRewardReplyWraper& Reply 同步段位奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncRankReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetRankReward
	* Description:    CampFigth-->获取段位奖励同步调用操作函数
	* Input:          CampFigthRpcGetRankRewardAskWraper& Ask 获取段位奖励请求
	* Output:         CampFigthRpcGetRankRewardReplyWraper& Reply 获取段位奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetRankReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEnterBattleScene
	* Description:    CampFigth-->进入战场同步调用操作函数
	* Input:          CampFigthRpcEnterBattleSceneAskWraper& Ask 进入战场请求
	* Output:         CampFigthRpcEnterBattleSceneReplyWraper& Reply 进入战场回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnterBattleScene( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif