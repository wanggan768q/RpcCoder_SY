/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcGameSettingImp.cpp
* Author:       甘业清
* Description:  游戏设置类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "GameSettingModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcSyncGameSetting
* Description:    游戏设置-->同步同步调用操作函数
* Input:          GameSettingRpcSyncGameSettingAskWraper& Ask 同步请求
* Output:         GameSettingRpcSyncGameSettingReplyWraper& Reply 同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleGameSetting::RpcSyncGameSetting( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSetting
* Description:    游戏设置-->设置同步调用操作函数
* Input:          GameSettingRpcSettingAskWraper& Ask 设置请求
* Output:         GameSettingRpcSettingReplyWraper& Reply 设置回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleGameSetting::RpcSetting( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientGameSettingNotify
* Description:    游戏设置-->设置 通知异步通知操作函数
* Input:          GameSettingRpcGameSettingNotifyNotifyWraper& Notify 设置 通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleGameSetting::SendToClientGameSettingNotify( INT64 UserId, GameSettingRpcGameSettingNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



