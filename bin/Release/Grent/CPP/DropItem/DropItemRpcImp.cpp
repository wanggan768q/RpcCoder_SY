/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcDropItemImp.cpp
* Author:       甘业清
* Description:  掉落类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "DropItemModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientDropTtems
* Description:    掉落-->掉落通知异步通知操作函数
* Input:          DropItemRpcDropTtemsNotifyWraper& Notify 掉落通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleDropItem::SendToClientDropTtems( INT64 UserId, DropItemRpcDropTtemsNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



