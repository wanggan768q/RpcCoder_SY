/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcBagImp.cpp
* Author:       郭晓波
* Description:  Bag类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "BagModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcUseItem
* Description:    Bag-->UseItem同步调用操作函数
* Input:          BagRpcUseItemAskWraper& Ask UseItem请求
* Output:         BagRpcUseItemReplyWraper& Reply UseItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcUseItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSaleItem
* Description:    Bag-->SaleItem同步调用操作函数
* Input:          BagRpcSaleItemAskWraper& Ask SaleItem请求
* Output:         BagRpcSaleItemReplyWraper& Reply SaleItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcSaleItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcLockItem
* Description:    Bag-->LockItem同步调用操作函数
* Input:          BagRpcLockItemAskWraper& Ask LockItem请求
* Output:         BagRpcLockItemReplyWraper& Reply LockItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcLockItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDeblocking
* Description:    Bag-->解锁背包格子同步调用操作函数
* Input:          BagRpcDeblockingAskWraper& Ask 解锁背包格子请求
* Output:         BagRpcDeblockingReplyWraper& Reply 解锁背包格子回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcDeblocking( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTakeItem
* Description:    Bag-->TakeItem同步调用操作函数
* Input:          BagRpcTakeItemAskWraper& Ask TakeItem请求
* Output:         BagRpcTakeItemReplyWraper& Reply TakeItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcTakeItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTidy
* Description:    Bag-->整理同步调用操作函数
* Input:          BagRpcTidyAskWraper& Ask 整理请求
* Output:         BagRpcTidyReplyWraper& Reply 整理回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcTidy( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcTakeAllBackBags
* Description:    Bag-->临时背包全部取回同步调用操作函数
* Input:          BagRpcTakeAllBackBagsAskWraper& Ask 临时背包全部取回请求
* Output:         BagRpcTakeAllBackBagsReplyWraper& Reply 临时背包全部取回回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcTakeAllBackBags( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientBagChange
* Description:    Bag-->背包数据推送异步通知操作函数
* Input:          BagRpcBagChangeNotifyWraper& Notify 背包数据推送通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleBag::SendToClientBagChange( INT64 UserId, BagRpcBagChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcMergeItem
* Description:    Bag-->MergeItem同步调用操作函数
* Input:          BagRpcMergeItemAskWraper& Ask MergeItem请求
* Output:         BagRpcMergeItemReplyWraper& Reply MergeItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcMergeItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBagSync
* Description:    Bag-->背包数据初始化同步调用操作函数
* Input:          BagRpcBagSyncAskWraper& Ask 背包数据初始化请求
* Output:         BagRpcBagSyncReplyWraper& Reply 背包数据初始化回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcBagSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientAddItem
* Description:    Bag-->新加物品异步通知操作函数
* Input:          BagRpcAddItemNotifyWraper& Notify 新加物品通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleBag::SendToClientAddItem( INT64 UserId, BagRpcAddItemNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcConsumeItem
* Description:    Bag-->根据物品id使用物品同步调用操作函数
* Input:          BagRpcConsumeItemAskWraper& Ask 根据物品id使用物品请求
* Output:         BagRpcConsumeItemReplyWraper& Reply 根据物品id使用物品回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcConsumeItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientItemChange
* Description:    Bag-->物品改变异步通知操作函数
* Input:          BagRpcItemChangeNotifyWraper& Notify 物品改变通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleBag::SendToClientItemChange( INT64 UserId, BagRpcItemChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcClickItem
* Description:    Bag-->点击物品同步调用操作函数
* Input:          BagRpcClickItemAskWraper& Ask 点击物品请求
* Output:         BagRpcClickItemReplyWraper& Reply 点击物品回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcClickItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRemoveItemByPos
* Description:    Bag-->通过位置删除物品同步调用操作函数
* Input:          BagRpcRemoveItemByPosAskWraper& Ask 通过位置删除物品请求
* Output:         BagRpcRemoveItemByPosReplyWraper& Reply 通过位置删除物品回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcRemoveItemByPos( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcClearBagRedPoint
* Description:    Bag-->清除背包红点同步调用操作函数
* Input:          BagRpcClearBagRedPointAskWraper& Ask 清除背包红点请求
* Output:         BagRpcClearBagRedPointReplyWraper& Reply 清除背包红点回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcClearBagRedPoint( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



