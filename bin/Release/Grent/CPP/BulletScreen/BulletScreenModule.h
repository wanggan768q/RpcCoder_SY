/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBulletScreen.h
* Author:       甘业清
* Description:  弹幕类，包含以下内容
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

#ifndef __MODULE_BULLETSCREEN_H
#define __MODULE_BULLETSCREEN_H


#include "ModuleBase.h"
#include "BulletScreenRpcWraper.h"




//弹幕实现类
class ModuleBulletScreen : public ModuleBase
{
	DECLARE_INSTANCE(ModuleBulletScreen);
public:
	friend class			ModuleMgr;

public:
	//弹幕实现类构造函数
	ModuleBulletScreen();
	
	//弹幕实现类析构函数
	virtual					~ModuleBulletScreen();

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
	* Function:       RpcBulletScreenOpt
	* Description:    弹幕-->弹幕设置同步调用操作函数
	* Input:          BulletScreenRpcBulletScreenOptAskWraper& Ask 弹幕设置请求
	* Output:         BulletScreenRpcBulletScreenOptReplyWraper& Reply 弹幕设置回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBulletScreenOpt( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCGBulletScreen
	* Description:    弹幕-->过场动画弹幕请求同步调用操作函数
	* Input:          BulletScreenRpcCGBulletScreenAskWraper& Ask 过场动画弹幕请求请求
	* Output:         BulletScreenRpcCGBulletScreenReplyWraper& Reply 过场动画弹幕请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCGBulletScreen( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSendBulletScreenCG
	* Description:    弹幕-->发布过场弹幕同步调用操作函数
	* Input:          BulletScreenRpcSendBulletScreenCGAskWraper& Ask 发布过场弹幕请求
	* Output:         BulletScreenRpcSendBulletScreenCGReplyWraper& Reply 发布过场弹幕回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSendBulletScreenCG( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif