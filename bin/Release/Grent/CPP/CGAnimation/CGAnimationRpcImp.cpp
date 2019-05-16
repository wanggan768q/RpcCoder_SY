/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcCGAnimationImp.cpp
* Author:       甘业清
* Description:  动画播放模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "CGAnimationModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcCgPlay
* Description:    动画播放模块-->动画开始播放同步调用操作函数
* Input:          CGAnimationRpcCgPlayAskWraper& Ask 动画开始播放请求
* Output:         CGAnimationRpcCgPlayReplyWraper& Reply 动画开始播放回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCGAnimation::RpcCgPlay( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCgPlayNotify
* Description:    动画播放模块-->通知异步通知操作函数
* Input:          CGAnimationRpcCgPlayNotifyNotifyWraper& Notify 通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCGAnimation::SendToClientCgPlayNotify( INT64 UserId, CGAnimationRpcCgPlayNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientCgOverNotify
* Description:    动画播放模块-->结束通知异步通知操作函数
* Input:          CGAnimationRpcCgOverNotifyNotifyWraper& Notify 结束通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCGAnimation::SendToClientCgOverNotify( INT64 UserId, CGAnimationRpcCgOverNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCgSkip
* Description:    动画播放模块-->跳过CG同步调用操作函数
* Input:          CGAnimationRpcCgSkipAskWraper& Ask 跳过CG请求
* Output:         CGAnimationRpcCgSkipReplyWraper& Reply 跳过CG回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCGAnimation::RpcCgSkip( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientScriptPlay
* Description:    动画播放模块-->脚本播放异步通知操作函数
* Input:          CGAnimationRpcScriptPlayNotifyWraper& Notify 脚本播放通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCGAnimation::SendToClientScriptPlay( INT64 UserId, CGAnimationRpcScriptPlayNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



