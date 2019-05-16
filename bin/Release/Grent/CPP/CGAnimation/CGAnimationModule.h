/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleCGAnimation.h
* Author:       甘业清
* Description:  动画播放模块类，包含以下内容
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

#ifndef __MODULE_CGANIMATION_H
#define __MODULE_CGANIMATION_H


#include "ModuleBase.h"
#include "CGAnimationRpcWraper.h"




//动画播放模块实现类
class ModuleCGAnimation : public ModuleBase
{
	DECLARE_INSTANCE(ModuleCGAnimation);
public:
	friend class			ModuleMgr;

public:
	//动画播放模块实现类构造函数
	ModuleCGAnimation();
	
	//动画播放模块实现类析构函数
	virtual					~ModuleCGAnimation();

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
	* Function:       RpcCgPlay
	* Description:    动画播放模块-->动画开始播放同步调用操作函数
	* Input:          CGAnimationRpcCgPlayAskWraper& Ask 动画开始播放请求
	* Output:         CGAnimationRpcCgPlayReplyWraper& Reply 动画开始播放回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCgPlay( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCgPlayNotify
	* Description:    动画播放模块-->通知异步通知操作函数
	* Input:          CGAnimationRpcCgPlayNotifyNotifyWraper& Notify 通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCgPlayNotify( INT64 UserId, CGAnimationRpcCgPlayNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientCgOverNotify
	* Description:    动画播放模块-->结束通知异步通知操作函数
	* Input:          CGAnimationRpcCgOverNotifyNotifyWraper& Notify 结束通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCgOverNotify( INT64 UserId, CGAnimationRpcCgOverNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCgSkip
	* Description:    动画播放模块-->跳过CG同步调用操作函数
	* Input:          CGAnimationRpcCgSkipAskWraper& Ask 跳过CG请求
	* Output:         CGAnimationRpcCgSkipReplyWraper& Reply 跳过CG回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCgSkip( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientScriptPlay
	* Description:    动画播放模块-->脚本播放异步通知操作函数
	* Input:          CGAnimationRpcScriptPlayNotifyWraper& Notify 脚本播放通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientScriptPlay( INT64 UserId, CGAnimationRpcScriptPlayNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif