/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWelfare.h
* Author:       甘业清
* Description:  福利类，包含以下内容
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

#ifndef __MODULE_WELFARE_H
#define __MODULE_WELFARE_H


#include "ModuleBase.h"
#include "WelfareRpcWraper.h"




//福利实现类
class ModuleWelfare : public ModuleBase
{
	DECLARE_INSTANCE(ModuleWelfare);
public:
	friend class			ModuleMgr;

public:
	//福利实现类构造函数
	ModuleWelfare();
	
	//福利实现类析构函数
	virtual					~ModuleWelfare();

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
	* Function:       RpcAccumulateSignIn
	* Description:    福利-->累计登陆福利同步调用操作函数
	* Input:          WelfareRpcAccumulateSignInAskWraper& Ask 累计登陆福利请求
	* Output:         WelfareRpcAccumulateSignInReplyWraper& Reply 累计登陆福利回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAccumulateSignIn( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAccumulateGetReward
	* Description:    福利-->领取累计登陆奖励同步调用操作函数
	* Input:          WelfareRpcAccumulateGetRewardAskWraper& Ask 领取累计登陆奖励请求
	* Output:         WelfareRpcAccumulateGetRewardReplyWraper& Reply 领取累计登陆奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAccumulateGetReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcOnlineBonus
	* Description:    福利-->今日在线福利同步调用操作函数
	* Input:          WelfareRpcOnlineBonusAskWraper& Ask 今日在线福利请求
	* Output:         WelfareRpcOnlineBonusReplyWraper& Reply 今日在线福利回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcOnlineBonus( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcOnlineGetReward
	* Description:    福利-->领取今日在线奖励同步调用操作函数
	* Input:          WelfareRpcOnlineGetRewardAskWraper& Ask 领取今日在线奖励请求
	* Output:         WelfareRpcOnlineGetRewardReplyWraper& Reply 领取今日在线奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcOnlineGetReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLevelBonus
	* Description:    福利-->等级福利同步调用操作函数
	* Input:          WelfareRpcLevelBonusAskWraper& Ask 等级福利请求
	* Output:         WelfareRpcLevelBonusReplyWraper& Reply 等级福利回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLevelBonus( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLevelBonusReward
	* Description:    福利-->领取等级福利奖励同步调用操作函数
	* Input:          WelfareRpcLevelBonusRewardAskWraper& Ask 领取等级福利奖励请求
	* Output:         WelfareRpcLevelBonusRewardReplyWraper& Reply 领取等级福利奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLevelBonusReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMonthSignInBonus
	* Description:    福利-->签到福利同步调用操作函数
	* Input:          WelfareRpcMonthSignInBonusAskWraper& Ask 签到福利请求
	* Output:         WelfareRpcMonthSignInBonusReplyWraper& Reply 签到福利回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMonthSignInBonus( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcMonthSignInReward
	* Description:    福利-->签到同步调用操作函数
	* Input:          WelfareRpcMonthSignInRewardAskWraper& Ask 签到请求
	* Output:         WelfareRpcMonthSignInRewardReplyWraper& Reply 签到回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMonthSignInReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientTodaySignIn
	* Description:    福利-->今日签到提醒异步通知操作函数
	* Input:          WelfareRpcTodaySignInNotifyWraper& Notify 今日签到提醒通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientTodaySignIn( INT64 UserId, WelfareRpcTodaySignInNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientSpecLogin
	* Description:    福利-->运营登录活动异步通知操作函数
	* Input:          WelfareRpcSpecLoginNotifyWraper& Notify 运营登录活动通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSpecLogin( INT64 UserId, WelfareRpcSpecLoginNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcSpecLoginReward
	* Description:    福利-->运营登录活动领取奖励同步调用操作函数
	* Input:          WelfareRpcSpecLoginRewardAskWraper& Ask 运营登录活动领取奖励请求
	* Output:         WelfareRpcSpecLoginRewardReplyWraper& Reply 运营登录活动领取奖励回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSpecLoginReward( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif