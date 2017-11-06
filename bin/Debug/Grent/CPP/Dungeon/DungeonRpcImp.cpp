/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcDungeonImp.cpp
* Author:       郭晓波
* Description:  副本类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "DungeonModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcCreateDungeon
* Description:    副本-->CreateDungeon同步调用操作函数
* Input:          DungeonRpcCreateDungeonAskWraper& Ask CreateDungeon请求
* Output:         DungeonRpcCreateDungeonReplyWraper& Reply CreateDungeon回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcCreateDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcExitDungeon
* Description:    副本-->退出副本同步调用操作函数
* Input:          DungeonRpcExitDungeonAskWraper& Ask 退出副本请求
* Output:         DungeonRpcExitDungeonReplyWraper& Reply 退出副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcExitDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



