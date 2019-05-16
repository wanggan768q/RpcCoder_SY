/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcDungeonImp.cpp
* Author:       甘业清
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

/********************************************************************************************
* Function:       RpcEnterDungeon
* Description:    副本-->进入副本通知同步调用操作函数
* Input:          DungeonRpcEnterDungeonAskWraper& Ask 进入副本通知请求
* Output:         DungeonRpcEnterDungeonReplyWraper& Reply 进入副本通知回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcEnterDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcInformCreateDungeon
* Description:    副本-->队长创建副本以后通知我同步调用操作函数
* Input:          DungeonRpcInformCreateDungeonAskWraper& Ask 队长创建副本以后通知我请求
* Output:         DungeonRpcInformCreateDungeonReplyWraper& Reply 队长创建副本以后通知我回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcInformCreateDungeon( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSettlement
* Description:    副本-->Settlement异步通知操作函数
* Input:          DungeonRpcSettlementNotifyWraper& Notify Settlement通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientSettlement( INT64 UserId, DungeonRpcSettlementNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDungeonData
* Description:    副本-->战况信息异步通知操作函数
* Input:          DungeonRpcDungeonDataNotifyWraper& Notify 战况信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientDungeonData( INT64 UserId, DungeonRpcDungeonDataNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcDungeonSync
* Description:    副本-->副本数据请求同步调用操作函数
* Input:          DungeonRpcDungeonSyncAskWraper& Ask 副本数据请求请求
* Output:         DungeonRpcDungeonSyncReplyWraper& Reply 副本数据请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcDungeonSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcDungeonListInfo
* Description:    副本-->副本挑战信息同步调用操作函数
* Input:          DungeonRpcDungeonListInfoAskWraper& Ask 副本挑战信息请求
* Output:         DungeonRpcDungeonListInfoReplyWraper& Reply 副本挑战信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcDungeonListInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCreateTutorial
* Description:    副本-->创建序章副本同步调用操作函数
* Input:          DungeonRpcCreateTutorialAskWraper& Ask 创建序章副本请求
* Output:         DungeonRpcCreateTutorialReplyWraper& Reply 创建序章副本回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcCreateTutorial( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcQuitTutorial
* Description:    副本-->强制退出序章同步调用操作函数
* Input:          DungeonRpcQuitTutorialAskWraper& Ask 强制退出序章请求
* Output:         DungeonRpcQuitTutorialReplyWraper& Reply 强制退出序章回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleDungeon::RpcQuitTutorial( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDungeonTarget
* Description:    副本-->副本目标异步通知操作函数
* Input:          DungeonRpcDungeonTargetNotifyWraper& Notify 副本目标通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientDungeonTarget( INT64 UserId, DungeonRpcDungeonTargetNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientTargetContentChange
* Description:    副本-->副本子任务完成情况异步通知操作函数
* Input:          DungeonRpcTargetContentChangeNotifyWraper& Notify 副本子任务完成情况通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientTargetContentChange( INT64 UserId, DungeonRpcTargetContentChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDungeon_Notify
* Description:    副本-->副本提示异步通知操作函数
* Input:          DungeonRpcDungeon_NotifyNotifyWraper& Notify 副本提示通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDungeon::SendToClientDungeon_Notify( INT64 UserId, DungeonRpcDungeon_NotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



