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
* Function:       RpcSync
* Description:    Bag-->请求背包数据同步调用操作函数
* Input:          BagRpcSyncAskWraper& Ask 请求背包数据请求
* Output:         BagRpcSyncReplyWraper& Reply 请求背包数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBag::RpcSync( CPlayer* pPlayer, CPacket* pPacket)
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



