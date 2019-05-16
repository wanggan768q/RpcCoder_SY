/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcActivityImp.cpp
* Author:       甘业清
* Description:  活动类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ActivityModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientEliteMonsterInfo
* Description:    活动-->精英怪信息异步通知操作函数
* Input:          ActivityRpcEliteMonsterInfoNotifyWraper& Notify 精英怪信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivity::SendToClientEliteMonsterInfo( INT64 UserId, ActivityRpcEliteMonsterInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCreateObj
* Description:    活动-->生成对象同步调用操作函数
* Input:          ActivityRpcCreateObjAskWraper& Ask 生成对象请求
* Output:         ActivityRpcCreateObjReplyWraper& Reply 生成对象回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleActivity::RpcCreateObj( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientOpenActivity
* Description:    活动-->活动开启前通知异步通知操作函数
* Input:          ActivityRpcOpenActivityNotifyWraper& Notify 活动开启前通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivity::SendToClientOpenActivity( INT64 UserId, ActivityRpcOpenActivityNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcXingyao
* Description:    活动-->星耀王座进入同步调用操作函数
* Input:          ActivityRpcXingyaoAskWraper& Ask 星耀王座进入请求
* Output:         ActivityRpcXingyaoReplyWraper& Reply 星耀王座回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleActivity::RpcXingyao( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientActivityTime
* Description:    活动-->活动时间信息异步通知操作函数
* Input:          ActivityRpcActivityTimeNotifyWraper& Notify 活动时间信息通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivity::SendToClientActivityTime( INT64 UserId, ActivityRpcActivityTimeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReqActivityTime
* Description:    活动-->请求获取活动时间同步调用操作函数
* Input:          ActivityRpcReqActivityTimeAskWraper& Ask 请求获取活动时间请求
* Output:         ActivityRpcReqActivityTimeReplyWraper& Reply 请求获取活动时间回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleActivity::RpcReqActivityTime( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcXingyaoNPC
* Description:    活动-->星耀NPC同步调用操作函数
* Input:          ActivityRpcXingyaoNPCAskWraper& Ask 星耀NPC请求
* Output:         ActivityRpcXingyaoNPCReplyWraper& Reply 星耀NPC回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleActivity::RpcXingyaoNPC( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientXingyaoReward
* Description:    活动-->星耀高额奖励异步通知操作函数
* Input:          ActivityRpcXingyaoRewardNotifyWraper& Notify 星耀高额奖励通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivity::SendToClientXingyaoReward( INT64 UserId, ActivityRpcXingyaoRewardNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientOperationTime
* Description:    活动-->operation活动表时间异步通知操作函数
* Input:          ActivityRpcOperationTimeNotifyWraper& Notify operation活动表时间通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleActivity::SendToClientOperationTime( INT64 UserId, ActivityRpcOperationTimeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



