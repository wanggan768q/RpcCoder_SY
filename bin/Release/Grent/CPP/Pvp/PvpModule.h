/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePvp.h
* Author:       甘业清
* Description:  Pvp类，包含以下内容
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

#ifndef __MODULE_PVP_H
#define __MODULE_PVP_H


#include "ModuleBase.h"
#include "PvpRpcWraper.h"




//Pvp实现类
class ModulePvp : public ModuleBase
{
	DECLARE_INSTANCE(ModulePvp);
public:
	friend class			ModuleMgr;

public:
	//Pvp实现类构造函数
	ModulePvp();
	
	//Pvp实现类析构函数
	virtual					~ModulePvp();

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
	* Function:       RpcRank
	* Description:    Pvp-->Rank同步调用操作函数
	* Input:          PvpRpcRankAskWraper& Ask Rank请求
	* Output:         PvpRpcRankReplyWraper& Reply Rank回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRank( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMatch
	* Description:    Pvp-->匹配同步调用操作函数
	* Input:          PvpRpcMatchAskWraper& Ask Match请求
	* Output:         PvpRpcMatchReplyWraper& Reply Match回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMatch( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientMatchNotify
	* Description:    Pvp-->匹配的通知异步通知操作函数
	* Input:          PvpRpcMatchNotifyNotifyWraper& Notify 匹配的通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMatchNotify( INT64 UserId, PvpRpcMatchNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcMatchCancle
	* Description:    Pvp-->取消匹配同步调用操作函数
	* Input:          PvpRpcMatchCancleAskWraper& Ask MatchCancle请求
	* Output:         PvpRpcMatchCancleReplyWraper& Reply MatchCancle回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMatchCancle( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientMatchCancleNotify
	* Description:    Pvp-->取消匹配通知异步通知操作函数
	* Input:          PvpRpcMatchCancleNotifyNotifyWraper& Notify 取消匹配通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMatchCancleNotify( INT64 UserId, PvpRpcMatchCancleNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcPvpBattleInfoSync
	* Description:    Pvp-->请求战斗信息同步调用操作函数
	* Input:          PvpRpcPvpBattleInfoSyncAskWraper& Ask 请求战斗信息请求
	* Output:         PvpRpcPvpBattleInfoSyncReplyWraper& Reply 请求战斗信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPvpBattleInfoSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientPvpBattleStart
	* Description:    Pvp-->PvpBattleStart异步通知操作函数
	* Input:          PvpRpcPvpBattleStartNotifyWraper& Notify PvpBattleStart通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPvpBattleStart( INT64 UserId, PvpRpcPvpBattleStartNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientPvpBattleEnd
	* Description:    Pvp-->PvpBattleEnd异步通知操作函数
	* Input:          PvpRpcPvpBattleEndNotifyWraper& Notify PvpBattleEnd通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPvpBattleEnd( INT64 UserId, PvpRpcPvpBattleEndNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcPlayerReady
	* Description:    Pvp-->PlayerReady同步调用操作函数
	* Input:          PvpRpcPlayerReadyAskWraper& Ask PlayerReady请求
	* Output:         PvpRpcPlayerReadyReplyWraper& Reply PlayerReady回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcPlayerReady( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientPlayerReadyNotify
	* Description:    Pvp-->玩家准备的通知异步通知操作函数
	* Input:          PvpRpcPlayerReadyNotifyNotifyWraper& Notify 玩家准备的通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientPlayerReadyNotify( INT64 UserId, PvpRpcPlayerReadyNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientReadyFaild
	* Description:    Pvp-->等待确认超时异步通知操作函数
	* Input:          PvpRpcReadyFaildNotifyWraper& Notify 等待确认超时通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReadyFaild( INT64 UserId, PvpRpcReadyFaildNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientMatchSucess
	* Description:    Pvp-->匹配完成异步通知操作函数
	* Input:          PvpRpcMatchSucessNotifyWraper& Notify 匹配完成通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMatchSucess( INT64 UserId, PvpRpcMatchSucessNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientRankChange
	* Description:    Pvp-->段位变化异步通知操作函数
	* Input:          PvpRpcRankChangeNotifyWraper& Notify 段位变化通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRankChange( INT64 UserId, PvpRpcRankChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReturnLastScene
	* Description:    Pvp-->返回同步调用操作函数
	* Input:          PvpRpcReturnLastSceneAskWraper& Ask 返回请求
	* Output:         PvpRpcReturnLastSceneReplyWraper& Reply 返回回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReturnLastScene( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientArenaStartTime
	* Description:    Pvp-->通知开始时间异步通知操作函数
	* Input:          PvpRpcArenaStartTimeNotifyWraper& Notify 通知开始时间通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientArenaStartTime( INT64 UserId, PvpRpcArenaStartTimeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateKillCount
	* Description:    Pvp-->更新击杀数量异步通知操作函数
	* Input:          PvpRpcUpdateKillCountNotifyWraper& Notify 更新击杀数量通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateKillCount( INT64 UserId, PvpRpcUpdateKillCountNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientArenaLeftTime
	* Description:    Pvp-->剩余时间异步通知操作函数
	* Input:          PvpRpcArenaLeftTimeNotifyWraper& Notify 剩余时间通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientArenaLeftTime( INT64 UserId, PvpRpcArenaLeftTimeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcLastRank
	* Description:    Pvp-->上个赛季的排行同步调用操作函数
	* Input:          PvpRpcLastRankAskWraper& Ask 上个赛季的排行请求
	* Output:         PvpRpcLastRankReplyWraper& Reply 上个赛季的排行回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLastRank( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNewSeason
	* Description:    Pvp-->新赛季通知异步通知操作函数
	* Input:          PvpRpcNewSeasonNotifyWraper& Notify 新赛季通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNewSeason( INT64 UserId, PvpRpcNewSeasonNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcGetSeasonReward
	* Description:    Pvp-->领取奖励同步调用操作函数
	* Input:          PvpRpcGetSeasonRewardAskWraper& Ask 领取奖励请求
	* Output:         PvpRpcGetSeasonRewardReplyWraper& Reply 领取奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetSeasonReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientReconnect
	* Description:    Pvp-->重连异步通知操作函数
	* Input:          PvpRpcReconnectNotifyWraper& Notify 重连通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientReconnect( INT64 UserId, PvpRpcReconnectNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcGetReward
	* Description:    Pvp-->获取奖励同步调用操作函数
	* Input:          PvpRpcGetRewardAskWraper& Ask 获取奖励请求
	* Output:         PvpRpcGetRewardReplyWraper& Reply 获取奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetReward( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif