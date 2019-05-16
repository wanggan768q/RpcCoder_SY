/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAuction.h
* Author:       甘业清
* Description:  拍卖行类，包含以下内容
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

#ifndef __MODULE_AUCTION_H
#define __MODULE_AUCTION_H


#include "ModuleBase.h"
#include "AuctionRpcWraper.h"




//拍卖行实现类
class ModuleAuction : public ModuleBase
{
	DECLARE_INSTANCE(ModuleAuction);
public:
	friend class			ModuleMgr;

public:
	//拍卖行实现类构造函数
	ModuleAuction();
	
	//拍卖行实现类析构函数
	virtual					~ModuleAuction();

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
	* Function:       RpcAuctionInfo
	* Description:    拍卖行-->查询拍卖行信息同步调用操作函数
	* Input:          AuctionRpcAuctionInfoAskWraper& Ask 级别
	* Output:         AuctionRpcAuctionInfoReplyWraper& Reply 查询拍卖行信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAuctionInfo( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSellItem
	* Description:    拍卖行-->请求上架同步调用操作函数
	* Input:          AuctionRpcSellItemAskWraper& Ask 请求上架请求
	* Output:         AuctionRpcSellItemReplyWraper& Reply 请求上架回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSellItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSellAgain
	* Description:    拍卖行-->重新上架同步调用操作函数
	* Input:          AuctionRpcSellAgainAskWraper& Ask 重新上架请求
	* Output:         AuctionRpcSellAgainReplyWraper& Reply 重新上架回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSellAgain( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcBuy
	* Description:    拍卖行-->购买同步调用操作函数
	* Input:          AuctionRpcBuyAskWraper& Ask 购买请求
	* Output:         AuctionRpcBuyReplyWraper& Reply 购买回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcBuy( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetItem
	* Description:    拍卖行-->取回拍卖道具同步调用操作函数
	* Input:          AuctionRpcGetItemAskWraper& Ask 取回交易记录中物品
	* Output:         AuctionRpcGetItemReplyWraper& Reply 取回拍卖道具回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcRecord
	* Description:    拍卖行-->交易记录同步调用操作函数
	* Input:          AuctionRpcRecordAskWraper& Ask 交易记录请求
	* Output:         AuctionRpcRecordReplyWraper& Reply 交易记录回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRecord( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcItemInfoByClass
	* Description:    拍卖行-->按类别查询简单信息同步调用操作函数
	* Input:          AuctionRpcItemInfoByClassAskWraper& Ask 按类别查询简单信息请求
	* Output:         AuctionRpcItemInfoByClassReplyWraper& Reply 按类别查询简单信息回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcItemInfoByClass( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSalePrepare
	* Description:    拍卖行-->预上架同步调用操作函数
	* Input:          AuctionRpcSalePrepareAskWraper& Ask 预上架请求
	* Output:         AuctionRpcSalePrepareReplyWraper& Reply 预上架回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSalePrepare( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetItemBack
	* Description:    拍卖行-->取回上架物品同步调用操作函数
	* Input:          AuctionRpcGetItemBackAskWraper& Ask 取回上架物品请求
	* Output:         AuctionRpcGetItemBackReplyWraper& Reply 取回上架物品回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetItemBack( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetMySaleList
	* Description:    拍卖行-->玩家当前拍卖列表同步调用操作函数
	* Input:          AuctionRpcGetMySaleListAskWraper& Ask 玩家当前拍卖列表请求
	* Output:         AuctionRpcGetMySaleListReplyWraper& Reply 玩家当前拍卖列表回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetMySaleList( CPlayer* pPlayer, CPacket* pPacket );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif