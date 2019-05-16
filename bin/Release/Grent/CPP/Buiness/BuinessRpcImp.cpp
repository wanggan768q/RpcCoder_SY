/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcBuinessImp.cpp
* Author:       甘业清
* Description:  生活技能类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "BuinessModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcBuinessSync
* Description:    生活技能-->初始化同步调用操作函数
* Input:          BuinessRpcBuinessSyncAskWraper& Ask 初始化请求
* Output:         BuinessRpcBuinessSyncReplyWraper& Reply 初始化回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBuiness::RpcBuinessSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBuinessUnlock
* Description:    生活技能-->解锁同步调用操作函数
* Input:          BuinessRpcBuinessUnlockAskWraper& Ask 解锁请求
* Output:         BuinessRpcBuinessUnlockReplyWraper& Reply 解锁回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBuiness::RpcBuinessUnlock( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBuinessStudy
* Description:    生活技能-->学习技能同步调用操作函数
* Input:          BuinessRpcBuinessStudyAskWraper& Ask 学习技能请求
* Output:         BuinessRpcBuinessStudyReplyWraper& Reply 学习技能回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBuiness::RpcBuinessStudy( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcBuinessMake
* Description:    生活技能-->制作同步调用操作函数
* Input:          BuinessRpcBuinessMakeAskWraper& Ask 制作请求
* Output:         BuinessRpcBuinessMakeReplyWraper& Reply 制作回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleBuiness::RpcBuinessMake( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



