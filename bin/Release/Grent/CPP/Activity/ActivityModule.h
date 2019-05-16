/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleActivity.h
* Author:       甘业清
* Description:  活动类，包含以下内容
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

#ifndef __MODULE_ACTIVITY_H
#define __MODULE_ACTIVITY_H


#include "ModuleBase.h"
#include "ActivityRpcWraper.h"




//活动实现类
class ModuleActivity : public ModuleBase
{
	DECLARE_INSTANCE(ModuleActivity);
public:
	friend class			ModuleMgr;

public:
	//活动实现类构造函数
	ModuleActivity();
	
	//活动实现类析构函数
	virtual					~ModuleActivity();

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
	* Function:       SendToClientEliteMonsterInfo
	* Description:    活动-->精英怪信息异步通知操作函数
	* Input:          ActivityRpcEliteMonsterInfoNotifyWraper& Notify 精英怪信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientEliteMonsterInfo( INT64 UserId, ActivityRpcEliteMonsterInfoNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCreateObj
	* Description:    活动-->生成对象同步调用操作函数
	* Input:          ActivityRpcCreateObjAskWraper& Ask 生成对象请求
	* Output:         ActivityRpcCreateObjReplyWraper& Reply 生成对象回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCreateObj( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientOpenActivity
	* Description:    活动-->活动开启前通知异步通知操作函数
	* Input:          ActivityRpcOpenActivityNotifyWraper& Notify 活动开启前通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOpenActivity( INT64 UserId, ActivityRpcOpenActivityNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcXingyao
	* Description:    活动-->星耀王座进入同步调用操作函数
	* Input:          ActivityRpcXingyaoAskWraper& Ask 星耀王座进入请求
	* Output:         ActivityRpcXingyaoReplyWraper& Reply 星耀王座回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcXingyao( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientActivityTime
	* Description:    活动-->活动时间信息异步通知操作函数
	* Input:          ActivityRpcActivityTimeNotifyWraper& Notify 活动时间信息通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientActivityTime( INT64 UserId, ActivityRpcActivityTimeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcReqActivityTime
	* Description:    活动-->请求获取活动时间同步调用操作函数
	* Input:          ActivityRpcReqActivityTimeAskWraper& Ask 请求获取活动时间请求
	* Output:         ActivityRpcReqActivityTimeReplyWraper& Reply 请求获取活动时间回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcReqActivityTime( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcXingyaoNPC
	* Description:    活动-->星耀NPC同步调用操作函数
	* Input:          ActivityRpcXingyaoNPCAskWraper& Ask 星耀NPC请求
	* Output:         ActivityRpcXingyaoNPCReplyWraper& Reply 星耀NPC回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcXingyaoNPC( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientXingyaoReward
	* Description:    活动-->星耀高额奖励异步通知操作函数
	* Input:          ActivityRpcXingyaoRewardNotifyWraper& Notify 星耀高额奖励通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientXingyaoReward( INT64 UserId, ActivityRpcXingyaoRewardNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientOperationTime
	* Description:    活动-->operation活动表时间异步通知操作函数
	* Input:          ActivityRpcOperationTimeNotifyWraper& Notify operation活动表时间通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOperationTime( INT64 UserId, ActivityRpcOperationTimeNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif