/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBuiness.h
* Author:       甘业清
* Description:  生活技能类，包含以下内容
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

#ifndef __MODULE_BUINESS_H
#define __MODULE_BUINESS_H


#include "ModuleBase.h"
#include "BuinessRpcWraper.h"




//生活技能实现类
class ModuleBuiness : public ModuleBase
{
	DECLARE_INSTANCE(ModuleBuiness);
public:
	friend class			ModuleMgr;

public:
	//生活技能实现类构造函数
	ModuleBuiness();
	
	//生活技能实现类析构函数
	virtual					~ModuleBuiness();

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
	* Function:       RpcBuinessSync
	* Description:    生活技能-->初始化同步调用操作函数
	* Input:          BuinessRpcBuinessSyncAskWraper& Ask 初始化请求
	* Output:         BuinessRpcBuinessSyncReplyWraper& Reply 初始化回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuinessSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuinessUnlock
	* Description:    生活技能-->解锁同步调用操作函数
	* Input:          BuinessRpcBuinessUnlockAskWraper& Ask 解锁请求
	* Output:         BuinessRpcBuinessUnlockReplyWraper& Reply 解锁回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuinessUnlock( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuinessStudy
	* Description:    生活技能-->学习技能同步调用操作函数
	* Input:          BuinessRpcBuinessStudyAskWraper& Ask 学习技能请求
	* Output:         BuinessRpcBuinessStudyReplyWraper& Reply 学习技能回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuinessStudy( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuinessMake
	* Description:    生活技能-->制作同步调用操作函数
	* Input:          BuinessRpcBuinessMakeAskWraper& Ask 制作请求
	* Output:         BuinessRpcBuinessMakeReplyWraper& Reply 制作回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuinessMake( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif