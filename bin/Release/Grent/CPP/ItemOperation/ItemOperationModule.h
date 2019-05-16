/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleItemOperation.h
* Author:       甘业清
* Description:  道具操作类，包含以下内容
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

#ifndef __MODULE_ITEMOPERATION_H
#define __MODULE_ITEMOPERATION_H


#include "ModuleBase.h"
#include "ItemOperationRpcWraper.h"




//道具操作实现类
class ModuleItemOperation : public ModuleBase
{
	DECLARE_INSTANCE(ModuleItemOperation);
public:
	friend class			ModuleMgr;

public:
	//道具操作实现类构造函数
	ModuleItemOperation();
	
	//道具操作实现类析构函数
	virtual					~ModuleItemOperation();

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
	* Function:       RpcItemResolveSettingSync
	* Description:    道具操作-->道具分解界面初始化同步调用操作函数
	* Input:          ItemOperationRpcItemResolveSettingSyncAskWraper& Ask 道具分解界面初始化请求
	* Output:         ItemOperationRpcItemResolveSettingSyncReplyWraper& Reply 道具分解界面初始化回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcItemResolveSettingSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcItemResolve
	* Description:    道具操作-->道具分解同步调用操作函数
	* Input:          ItemOperationRpcItemResolveAskWraper& Ask 道具分解请求
	* Output:         ItemOperationRpcItemResolveReplyWraper& Reply 道具分解回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcItemResolve( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcChangeSetting
	* Description:    道具操作-->更改设置同步调用操作函数
	* Input:          ItemOperationRpcChangeSettingAskWraper& Ask 更改设置请求
	* Output:         ItemOperationRpcChangeSettingReplyWraper& Reply 更改设置回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcChangeSetting( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBatchResolve
	* Description:    道具操作-->一键分解同步调用操作函数
	* Input:          ItemOperationRpcBatchResolveAskWraper& Ask 一键分解请求
	* Output:         ItemOperationRpcBatchResolveReplyWraper& Reply 一键分解回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBatchResolve( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcItemCompound
	* Description:    道具操作-->道具合成同步调用操作函数
	* Input:          ItemOperationRpcItemCompoundAskWraper& Ask 道具合成请求
	* Output:         ItemOperationRpcItemCompoundReplyWraper& Reply 道具合成回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcItemCompound( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif