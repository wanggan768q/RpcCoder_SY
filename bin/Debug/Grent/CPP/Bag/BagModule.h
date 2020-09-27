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
#include "Game/PacketMgr.h"
#include "BagRpc.pb.h"
#include <memory>
#include <vector>
#include <functional>




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
	RPC_CODE_BAG_SALEITEM_REQUEST                = 1252,	//Bag-->SaleItem-->请求
	RPC_CODE_BAG_LOCKITEM_REQUEST                = 1253,	//Bag-->LockItem-->请求
	RPC_CODE_BAG_DEBLOCKING_REQUEST              = 1254,	//Bag-->解锁背包格子-->请求
	RPC_CODE_BAG_TAKEITEM_REQUEST                = 1255,	//Bag-->TakeItem-->请求
	RPC_CODE_BAG_TIDY_REQUEST                    = 1256,	//Bag-->整理-->请求
	RPC_CODE_BAG_TAKEALLBACKBAGS_REQUEST         = 1257,	//Bag-->临时背包全部取回-->请求
	RPC_CODE_BAG_BAGCHANGE_NOTIFY                = 1258,	//Bag-->背包数据推送-->通知
	RPC_CODE_BAG_MERGEITEM_REQUEST               = 1259,	//Bag-->MergeItem-->请求
	RPC_CODE_BAG_BAGSYNC_REQUEST                 = 1260,	//Bag-->背包数据初始化-->请求
	RPC_CODE_BAG_ADDITEM_NOTIFY                  = 1261,	//Bag-->新加物品-->通知
	RPC_CODE_BAG_CONSUMEITEM_REQUEST             = 1262,	//Bag-->根据物品id使用物品-->请求
	RPC_CODE_BAG_ITEMCHANGE_NOTIFY               = 1263,	//Bag-->物品改变-->通知
	RPC_CODE_BAG_CLICKITEM_REQUEST               = 1264,	//Bag-->点击物品-->请求
	RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST         = 1265,	//Bag-->通过位置删除物品-->请求
	RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST        = 1266,	//Bag-->清除背包红点-->请求

	};

	typedef std::function<bool()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
public:
	//Bag实现类构造函数
	ModuleBag()
	{
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_USEITEM_REQUEST, &ModuleBag::RpcUseItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_USEITEM_REQUEST, new Some_Factory<BagRpcUseItemAsk>());
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
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_MERGEITEM_REQUEST, &ModuleBag::RpcMergeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_MERGEITEM_REQUEST, new Some_Factory<BagRpcMergeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_BAGSYNC_REQUEST, &ModuleBag::RpcBagSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_BAGSYNC_REQUEST, new Some_Factory<BagRpcBagSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_CONSUMEITEM_REQUEST, &ModuleBag::RpcConsumeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_CONSUMEITEM_REQUEST, new Some_Factory<BagRpcConsumeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_CLICKITEM_REQUEST, &ModuleBag::RpcClickItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_CLICKITEM_REQUEST, new Some_Factory<BagRpcClickItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST, &ModuleBag::RpcRemoveItemByPos);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_REMOVEITEMBYPOS_REQUEST, new Some_Factory<BagRpcRemoveItemByPosAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST, &ModuleBag::RpcClearBagRedPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_BAG_CLEARBAGREDPOINT_REQUEST, new Some_Factory<BagRpcClearBagRedPointAsk>());

	}
	
	//Bag实现类析构函数
	~ModuleBag(){}


	static ModuleBag & Instance()
	{
		static ModuleBag sInstance;
		return sInstance;
	}
	
	bool Initialize();
	bool Reinitialize();

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	bool OnLoad()
	{
		bool bRet = true;
			for (auto it : m_vReLoadCb)
		{
			bRet &= it();
		}
		return bRet;
	}
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

	/********************************************************************************************
	* Function:       RpcRemoveItemByPos
	* Description:    Bag-->通过位置删除物品同步调用操作函数
	* Input:          BagRpcRemoveItemByPosAskWraper& Ask 通过位置删除物品请求
	* Output:         BagRpcRemoveItemByPosReplyWraper& Reply 通过位置删除物品回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcRemoveItemByPos( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcClearBagRedPoint
	* Description:    Bag-->清除背包红点同步调用操作函数
	* Input:          BagRpcClearBagRedPointAskWraper& Ask 清除背包红点请求
	* Output:         BagRpcClearBagRedPointReplyWraper& Reply 清除背包红点回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcClearBagRedPoint( CPlayer* pPlayer, CPacket* pPacket );


	reload_vec_type m_vReLoadCb;

};

#endif