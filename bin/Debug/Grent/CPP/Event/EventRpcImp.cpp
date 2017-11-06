/********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     CliRpcEventImp.cpp
* Author:       郭晓波
* Description:  事件模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "EventModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientMove
* Description:    事件模块-->ObjMove异步通知操作函数
* Input:          EventRpcMoveNotifyWraper& Notify ObjMove通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientMove( INT64 UserId, EventRpcMoveNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientStopMove
* Description:    事件模块-->ObjStopMove异步通知操作函数
* Input:          EventRpcStopMoveNotifyWraper& Notify ObjStopMove通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientStopMove( INT64 UserId, EventRpcStopMoveNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientBossDied
* Description:    事件模块-->Boss死亡异步通知操作函数
* Input:          EventRpcBossDiedNotifyWraper& Notify Boss死亡通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientBossDied( INT64 UserId, EventRpcBossDiedNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



