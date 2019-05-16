/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleClimTower.h
* Author:       甘业清
* Description:  爬塔玩法类，包含以下内容
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

#ifndef __MODULE_CLIMTOWER_H
#define __MODULE_CLIMTOWER_H


#include "ModuleBase.h"
#include "ClimTowerRpcWraper.h"




//爬塔玩法实现类
class ModuleClimTower : public ModuleBase
{
	DECLARE_INSTANCE(ModuleClimTower);
public:
	friend class			ModuleMgr;

public:
	//爬塔玩法实现类构造函数
	ModuleClimTower();
	
	//爬塔玩法实现类析构函数
	virtual					~ModuleClimTower();

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
	* Function:       SendToClientOpenRule
	* Description:    爬塔玩法-->玩法开启规则异步通知操作函数
	* Input:          ClimTowerRpcOpenRuleNotifyWraper& Notify 玩法开启规则通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOpenRule( INT64 UserId, ClimTowerRpcOpenRuleNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcEnter
	* Description:    爬塔玩法-->进入爬塔活动同步调用操作函数
	* Input:          ClimTowerRpcEnterAskWraper& Ask 进入爬塔活动请求
	* Output:         ClimTowerRpcEnterReplyWraper& Reply 进入爬塔活动回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEnter( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChallenge
	* Description:    爬塔玩法-->挑战同步调用操作函数
	* Input:          ClimTowerRpcChallengeAskWraper& Ask 挑战请求
	* Output:         ClimTowerRpcChallengeReplyWraper& Reply 挑战回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChallenge( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRank
	* Description:    爬塔玩法-->获取排行榜信息同步调用操作函数
	* Input:          ClimTowerRpcRankAskWraper& Ask 获取排行榜信息请求
	* Output:         ClimTowerRpcRankReplyWraper& Reply 获取排行榜信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRank( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcFirstVicReward
	* Description:    爬塔玩法-->首次通关奖励领奖同步调用操作函数
	* Input:          ClimTowerRpcFirstVicRewardAskWraper& Ask 首次通关奖励领奖请求
	* Output:         ClimTowerRpcFirstVicRewardReplyWraper& Reply 首次通关奖励领奖回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcFirstVicReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientNextLayer
	* Description:    爬塔玩法-->下一层通知异步通知操作函数
	* Input:          ClimTowerRpcNextLayerNotifyWraper& Notify 下一层通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientNextLayer( INT64 UserId, ClimTowerRpcNextLayerNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientChallengeEnd
	* Description:    爬塔玩法-->挑战结束异步通知操作函数
	* Input:          ClimTowerRpcChallengeEndNotifyWraper& Notify 挑战结束通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientChallengeEnd( INT64 UserId, ClimTowerRpcChallengeEndNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientWaveRefresh
	* Description:    爬塔玩法-->每波怪物刷新通知异步通知操作函数
	* Input:          ClimTowerRpcWaveRefreshNotifyWraper& Notify 每波怪物刷新通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientWaveRefresh( INT64 UserId, ClimTowerRpcWaveRefreshNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif