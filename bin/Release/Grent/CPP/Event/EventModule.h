/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEvent.h
* Author:       甘业清
* Description:  事件模块类，包含以下内容
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

#ifndef __MODULE_EVENT_H
#define __MODULE_EVENT_H


#include "ModuleBase.h"
#include "EventRpcWraper.h"




//事件模块实现类
class ModuleEvent : public ModuleBase
{
	DECLARE_INSTANCE(ModuleEvent);
public:
	friend class			ModuleMgr;

public:
	//事件模块实现类构造函数
	ModuleEvent();
	
	//事件模块实现类析构函数
	virtual					~ModuleEvent();

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
	* Function:       SendToClientMove
	* Description:    事件模块-->ObjMove异步通知操作函数
	* Input:          EventRpcMoveNotifyWraper& Notify ObjMove通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMove( INT64 UserId, EventRpcMoveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientStopMove
	* Description:    事件模块-->ObjStopMove异步通知操作函数
	* Input:          EventRpcStopMoveNotifyWraper& Notify ObjStopMove通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientStopMove( INT64 UserId, EventRpcStopMoveNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientObjAttrChange
	* Description:    事件模块-->属性改变异步通知操作函数
	* Input:          EventRpcObjAttrChangeNotifyWraper& Notify 属性改变通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientObjAttrChange( INT64 UserId, EventRpcObjAttrChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCoinChange
	* Description:    事件模块-->货币的变化通知异步通知操作函数
	* Input:          EventRpcCoinChangeNotifyWraper& Notify 货币的变化通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCoinChange( INT64 UserId, EventRpcCoinChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientMovePos
	* Description:    事件模块-->按点移动异步通知操作函数
	* Input:          EventRpcMovePosNotifyWraper& Notify 按点移动通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientMovePos( INT64 UserId, EventRpcMovePosNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif