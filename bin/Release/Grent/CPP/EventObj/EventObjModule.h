/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleEventObj.h
* Author:       甘业清
* Description:  EventObj类，包含以下内容
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

#ifndef __MODULE_EVENTOBJ_H
#define __MODULE_EVENTOBJ_H


#include "ModuleBase.h"
#include "EventObjRpcWraper.h"




//EventObj实现类
class ModuleEventObj : public ModuleBase
{
	DECLARE_INSTANCE(ModuleEventObj);
public:
	friend class			ModuleMgr;

public:
	//EventObj实现类构造函数
	ModuleEventObj();
	
	//EventObj实现类析构函数
	virtual					~ModuleEventObj();

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
	* Function:       RpcEventBegin
	* Description:    EventObj-->EventBegin同步调用操作函数
	* Input:          EventObjRpcEventBeginAskWraper& Ask EventBegin请求
	* Output:         EventObjRpcEventBeginReplyWraper& Reply EventBegin回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEventBegin( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEventEnd
	* Description:    EventObj-->EventEnd同步调用操作函数
	* Input:          EventObjRpcEventEndAskWraper& Ask EventEnd请求
	* Output:         EventObjRpcEventEndReplyWraper& Reply EventEnd回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEventEnd( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcEventStop
	* Description:    EventObj-->EventStop同步调用操作函数
	* Input:          EventObjRpcEventStopAskWraper& Ask EventStop请求
	* Output:         EventObjRpcEventStopReplyWraper& Reply EventStop回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEventStop( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientEventStopNotify
	* Description:    EventObj-->交互停止通知异步通知操作函数
	* Input:          EventObjRpcEventStopNotifyNotifyWraper& Notify 交互停止通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientEventStopNotify( INT64 UserId, EventObjRpcEventStopNotifyNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif