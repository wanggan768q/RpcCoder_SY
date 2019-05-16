/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcBulletScreenImp.cpp
* Author:       甘业清
* Description:  弹幕类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "BulletScreenModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcBulletScreenOpt
* Description:    弹幕-->弹幕设置同步调用操作函数
* Input:          BulletScreenRpcBulletScreenOptAskWraper& Ask 弹幕设置请求
* Output:         BulletScreenRpcBulletScreenOptReplyWraper& Reply 弹幕设置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBulletScreen::RpcBulletScreenOpt( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCGBulletScreen
* Description:    弹幕-->过场动画弹幕请求同步调用操作函数
* Input:          BulletScreenRpcCGBulletScreenAskWraper& Ask 过场动画弹幕请求请求
* Output:         BulletScreenRpcCGBulletScreenReplyWraper& Reply 过场动画弹幕请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBulletScreen::RpcCGBulletScreen( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSendBulletScreenCG
* Description:    弹幕-->发布过场弹幕同步调用操作函数
* Input:          BulletScreenRpcSendBulletScreenCGAskWraper& Ask 发布过场弹幕请求
* Output:         BulletScreenRpcSendBulletScreenCGReplyWraper& Reply 发布过场弹幕回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBulletScreen::RpcSendBulletScreenCG( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



