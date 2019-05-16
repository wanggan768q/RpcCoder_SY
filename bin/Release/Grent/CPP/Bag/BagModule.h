/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleBag.h
* Author:       甘业清
* Description:  Bag类，包含以下内容
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

#ifndef __MODULE_BAG_H
#define __MODULE_BAG_H


#include "ModuleBase.h"
#include "BagRpcWraper.h"




//Bag实现类
class ModuleBag : public ModuleBase
{
	DECLARE_INSTANCE(ModuleBag);
public:
	friend class			ModuleMgr;

public:
	//Bag实现类构造函数
	ModuleBag();
	
	//Bag实现类析构函数
	virtual					~ModuleBag();

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
	* Function:       RpcUseItem
	* Description:    Bag-->UseItem同步调用操作函数
	* Input:          BagRpcUseItemAskWraper& Ask UseItem请求
	* Output:         BagRpcUseItemReplyWraper& Reply UseItem回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcUseItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSaleItem
	* Description:    Bag-->SaleItem同步调用操作函数
	* Input:          BagRpcSaleItemAskWraper& Ask SaleItem请求
	* Output:         BagRpcSaleItemReplyWraper& Reply SaleItem回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSaleItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcLockItem
	* Description:    Bag-->LockItem同步调用操作函数
	* Input:          BagRpcLockItemAskWraper& Ask LockItem请求
	* Output:         BagRpcLockItemReplyWraper& Reply LockItem回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcLockItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcDeblocking
	* Description:    Bag-->解锁背包格子同步调用操作函数
	* Input:          BagRpcDeblockingAskWraper& Ask 解锁背包格子请求
	* Output:         BagRpcDeblockingReplyWraper& Reply 解锁背包格子回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcDeblocking( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTakeItem
	* Description:    Bag-->TakeItem同步调用操作函数
	* Input:          BagRpcTakeItemAskWraper& Ask TakeItem请求
	* Output:         BagRpcTakeItemReplyWraper& Reply TakeItem回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTakeItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTidy
	* Description:    Bag-->整理同步调用操作函数
	* Input:          BagRpcTidyAskWraper& Ask 整理请求
	* Output:         BagRpcTidyReplyWraper& Reply 整理回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTidy( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcTakeAllBackBags
	* Description:    Bag-->临时背包全部取回同步调用操作函数
	* Input:          BagRpcTakeAllBackBagsAskWraper& Ask 临时背包全部取回请求
	* Output:         BagRpcTakeAllBackBagsReplyWraper& Reply 临时背包全部取回回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcTakeAllBackBags( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientBagChange
	* Description:    Bag-->背包数据推送异步通知操作函数
	* Input:          BagRpcBagChangeNotifyWraper& Notify 背包数据推送通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientBagChange( INT64 UserId, BagRpcBagChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcMergeItem
	* Description:    Bag-->MergeItem同步调用操作函数
	* Input:          BagRpcMergeItemAskWraper& Ask MergeItem请求
	* Output:         BagRpcMergeItemReplyWraper& Reply MergeItem回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcMergeItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBagSync
	* Description:    Bag-->背包数据初始化同步调用操作函数
	* Input:          BagRpcBagSyncAskWraper& Ask 背包数据初始化请求
	* Output:         BagRpcBagSyncReplyWraper& Reply 背包数据初始化回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBagSync( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientAddItem
	* Description:    Bag-->新加物品异步通知操作函数
	* Input:          BagRpcAddItemNotifyWraper& Notify 新加物品通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientAddItem( INT64 UserId, BagRpcAddItemNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcConsumeItem
	* Description:    Bag-->根据物品id使用物品同步调用操作函数
	* Input:          BagRpcConsumeItemAskWraper& Ask 根据物品id使用物品请求
	* Output:         BagRpcConsumeItemReplyWraper& Reply 根据物品id使用物品回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcConsumeItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientItemChange
	* Description:    Bag-->物品改变异步通知操作函数
	* Input:          BagRpcItemChangeNotifyWraper& Notify 物品改变通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientItemChange( INT64 UserId, BagRpcItemChangeNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcClickItem
	* Description:    Bag-->点击物品同步调用操作函数
	* Input:          BagRpcClickItemAskWraper& Ask 点击物品请求
	* Output:         BagRpcClickItemReplyWraper& Reply 点击物品回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcClickItem( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif