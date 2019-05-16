/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcShopImp.cpp
* Author:       甘业清
* Description:  商店类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ShopModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcBuyItem
* Description:    商店-->BuyItem同步调用操作函数
* Input:          ShopRpcBuyItemAskWraper& Ask BuyItem请求
* Output:         ShopRpcBuyItemReplyWraper& Reply BuyItem回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleShop::RpcBuyItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcShopInfo
* Description:    商店-->ShopInfo同步调用操作函数
* Input:          ShopRpcShopInfoAskWraper& Ask ShopInfo请求
* Output:         ShopRpcShopInfoReplyWraper& Reply ShopInfo回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleShop::RpcShopInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



