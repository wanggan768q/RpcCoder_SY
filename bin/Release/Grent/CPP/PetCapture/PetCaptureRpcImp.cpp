/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcPetCaptureImp.cpp
* Author:       甘业清
* Description:  宠物捕获类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "PetCaptureModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcCapture
* Description:    宠物捕获-->宠物捕获同步调用操作函数
* Input:          PetCaptureRpcCaptureAskWraper& Ask 宠物捕获请求
* Output:         PetCaptureRpcCaptureReplyWraper& Reply 宠物捕获回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePetCapture::RpcCapture( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCapturePet
* Description:    宠物捕获-->捕获到宠物广播异步通知操作函数
* Input:          PetCaptureRpcCapturePetNotifyWraper& Notify 捕获到宠物广播通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePetCapture::SendToClientCapturePet( INT64 UserId, PetCaptureRpcCapturePetNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientLogin
* Description:    宠物捕获-->宠物捕获登录异步通知操作函数
* Input:          PetCaptureRpcLoginNotifyWraper& Notify 宠物捕获登录通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePetCapture::SendToClientLogin( INT64 UserId, PetCaptureRpcLoginNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcPetLocation
* Description:    宠物捕获-->宠物npc位置同步调用操作函数
* Input:          PetCaptureRpcPetLocationAskWraper& Ask 宠物npc位置请求
* Output:         PetCaptureRpcPetLocationReplyWraper& Reply 宠物npc位置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePetCapture::RpcPetLocation( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



