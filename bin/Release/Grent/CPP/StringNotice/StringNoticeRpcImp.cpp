/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcStringNoticeImp.cpp
* Author:       甘业清
* Description:  文本提示类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "StringNoticeModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientNotice
* Description:    文本提示-->通知异步通知操作函数
* Input:          StringNoticeRpcNoticeNotifyWraper& Notify 通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleStringNotice::SendToClientNotice( INT64 UserId, StringNoticeRpcNoticeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



