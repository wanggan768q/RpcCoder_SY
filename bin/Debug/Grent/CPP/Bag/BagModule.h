/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleBag.h
* Author:       郭晓波
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


#include "PacketFactory.h"
#include "include/PacketMgr.h"
#include "BagRpc.pb.h"
#include <memory>





class CPlayer;
class CPacket;

extern std::unique_ptr<PacketMgr> g_pPacketMgr;

//Bag实现类
class ModuleBag
{
	
public:
	//Bag类的枚举定义
	enum ConstBagE
	{
	MODULE_ID_BAG                                = 12,	//Bag模块ID
	RPC_CODE_BAG_USEITEM_REQUEST                 = 1251,	//Bag-->UseItem-->请求
	RPC_CODE_BAG_SYNC_REQUEST                    = 1252,	//Bag-->请求背包数据-->请求
	RPC_CODE_BAG_SALEITEM_REQUEST                = 1253,	//Bag-->SaleItem-->请求
	RPC_CODE_BAG_LOCKITEM_REQUEST                = 1254,	//Bag-->LockItem-->请求
	RPC_CODE_BAG_DEBLOCKING_REQUEST              = 1255,	//Bag-->解锁背包格子-->请求
	RPC_CODE_BAG_TAKEITEM_REQUEST                = 1256,	//Bag-->TakeItem-->请求
	RPC_CODE_BAG_TIDY_REQUEST                    = 1257,	//Bag-->整理-->请求
	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST         = 1258,	//Bag-->临时背包全部取回-->请求
	RPC_CODE_BAG_BAGCHANGE_NOTIFY                = 1259,	//Bag-->背包数据推送-->通知

	};

public:
	//Bag实现类构造函数
	ModuleBag()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_USEITEM_REQUEST, &ModuleBag::RpcUseItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_USEITEM_REQUEST, new Some_Factory<BagRpcUseItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_SYNC_REQUEST, &ModuleBag::RpcSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_SYNC_REQUEST, new Some_Factory<BagRpcSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_SALEITEM_REQUEST, &ModuleBag::RpcSaleItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_SALEITEM_REQUEST, new Some_Factory<BagRpcSaleItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_LOCKITEM_REQUEST, &ModuleBag::RpcLockItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_LOCKITEM_REQUEST, new Some_Factory<BagRpcLockItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_DEBLOCKING_REQUEST, &ModuleBag::RpcDeblocking);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_DEBLOCKING_REQUEST, new Some_Factory<BagRpcDeblockingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TAKEITEM_REQUEST, &ModuleBag::RpcTakeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TAKEITEM_REQUEST, new Some_Factory<BagRpcTakeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TIDY_REQUEST, &ModuleBag::RpcTidy);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TIDY_REQUEST, new Some_Factory<BagRpcTidyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, &ModuleBag::RpcTakeAllBackBags);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST, new Some_Factory<BagRpcTakeAllBackBagsAsk>());

	}
	
	//Bag实现类析构函数
	~ModuleBag(){}


	static ModuleBag Instance()
	{
		static ModuleBag sInstance;
		return sInstance;
	}
	
	bool Initialize();

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
	* Function:       RpcSync
	* Description:    Bag-->请求背包数据同步调用操作函数
	* Input:          BagRpcSyncAskWraper& Ask 请求背包数据请求
	* Output:         BagRpcSyncReplyWraper& Reply 请求背包数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSync( CPlayer* pPlayer, CPacket* pPacket );

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



};

#endif