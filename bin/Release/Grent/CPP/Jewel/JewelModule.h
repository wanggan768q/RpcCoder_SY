/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleJewel.h
* Author:       甘业清
* Description:  宝石模块类，包含以下内容
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

#ifndef __MODULE_JEWEL_H
#define __MODULE_JEWEL_H


#include "ModuleBase.h"
#include "JewelRpcWraper.h"




//宝石模块实现类
class ModuleJewel : public ModuleBase
{
	DECLARE_INSTANCE(ModuleJewel);
public:
	friend class			ModuleMgr;

public:
	//宝石模块实现类构造函数
	ModuleJewel();
	
	//宝石模块实现类析构函数
	virtual					~ModuleJewel();

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
	* Function:       RpcJewelSync
	* Description:    宝石模块-->同步同步调用操作函数
	* Input:          JewelRpcJewelSyncAskWraper& Ask 同步请求
	* Output:         JewelRpcJewelSyncReplyWraper& Reply 同步回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcJewelSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcInsetJewel
	* Description:    宝石模块-->镶嵌同步调用操作函数
	* Input:          JewelRpcInsetJewelAskWraper& Ask 镶嵌请求
	* Output:         JewelRpcInsetJewelReplyWraper& Reply 镶嵌回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcInsetJewel( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRemoveJewel
	* Description:    宝石模块-->摘除宝石同步调用操作函数
	* Input:          JewelRpcRemoveJewelAskWraper& Ask 摘除宝石请求
	* Output:         JewelRpcRemoveJewelReplyWraper& Reply 摘除宝石回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRemoveJewel( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCompoundJewel
	* Description:    宝石模块-->合成宝石同步调用操作函数
	* Input:          JewelRpcCompoundJewelAskWraper& Ask 合成宝石请求
	* Output:         JewelRpcCompoundJewelReplyWraper& Reply 合成宝石回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCompoundJewel( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCompoundSetJewel
	* Description:    宝石模块-->对已镶嵌的宝石合成同步调用操作函数
	* Input:          JewelRpcCompoundSetJewelAskWraper& Ask 对已镶嵌的宝石合成请求
	* Output:         JewelRpcCompoundSetJewelReplyWraper& Reply 对已镶嵌的宝石合成回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCompoundSetJewel( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcUnlockJewelSlot
	* Description:    宝石模块-->解锁同步调用操作函数
	* Input:          JewelRpcUnlockJewelSlotAskWraper& Ask 解锁请求
	* Output:         JewelRpcUnlockJewelSlotReplyWraper& Reply 解锁回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUnlockJewelSlot( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcQuickCompound
	* Description:    宝石模块-->快速合成同步调用操作函数
	* Input:          JewelRpcQuickCompoundAskWraper& Ask 快速合成请求
	* Output:         JewelRpcQuickCompoundReplyWraper& Reply 快速合成回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcQuickCompound( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif