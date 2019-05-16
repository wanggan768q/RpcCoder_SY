/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcCurrencyImp.cpp
* Author:       甘业清
* Description:  货币类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "CurrencyModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcTransfrom
* Description:    货币-->货币兑换同步调用操作函数
* Input:          CurrencyRpcTransfromAskWraper& Ask 货币兑换请求
* Output:         CurrencyRpcTransfromReplyWraper& Reply 货币兑换回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCurrency::RpcTransfrom( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcShow
* Description:    货币-->货币展示同步调用操作函数
* Input:          CurrencyRpcShowAskWraper& Ask 货币展示请求
* Output:         CurrencyRpcShowReplyWraper& Reply 货币展示回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCurrency::RpcShow( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



