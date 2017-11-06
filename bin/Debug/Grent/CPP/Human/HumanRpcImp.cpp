/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcHumanImp.cpp
* Author:       郭晓波
* Description:  玩家模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "HumanModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcMove
* Description:    玩家模块-->human move同步调用操作函数
* Input:          HumanRpcMoveAskWraper& Ask human move请求
* Output:         HumanRpcMoveReplyWraper& Reply human move回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcMove( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcStopMove
* Description:    玩家模块-->客户端停止移动同步调用操作函数
* Input:          HumanRpcStopMoveAskWraper& Ask 客户端停止移动请求
* Output:         HumanRpcStopMoveReplyWraper& Reply 客户端停止移动回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcStopMove( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMovementVerification
* Description:    玩家模块-->移动验证同步调用操作函数
* Input:          HumanRpcMovementVerificationAskWraper& Ask 移动验证请求
* Output:         HumanRpcMovementVerificationReplyWraper& Reply 移动验证回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleHuman::RpcMovementVerification( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCGMoveCheck
* Description:    玩家模块-->客户端位置校验异步通知操作函数
* Input:          HumanRpcCGMoveCheckNotifyWraper& Notify 客户端位置校验通知
* Output:         无
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位无效
********************************************************************************************/
int ModuleHuman::RpcCGMoveCheck( INT64 UserId, HumanRpcCGMoveCheckNotifyWraper& Notify )
{

	//检测字段[方向]数据范围
	if( Notify.GetDir()<-1 && Notify.GetDir()!=0)
	{
		assert(false);
		return 0;
	}
	if( Notify.GetDir()>10000000 && Notify.GetDir()!=0)
	{
		assert(false);
		return 0;
	}

	//逻辑代码


	return 0;
}

/********************************************************************************************
* Function:       SendToClientGCMoveCheck
* Description:    玩家模块-->服务器位置校验通知异步通知操作函数
* Input:          HumanRpcGCMoveCheckNotifyWraper& Notify 服务器位置校验通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleHuman::SendToClientGCMoveCheck( INT64 UserId, HumanRpcGCMoveCheckNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



