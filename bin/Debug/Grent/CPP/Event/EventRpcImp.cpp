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
* Function:       SendToClientObjAttrChange
* Description:    事件模块-->属性改变异步通知操作函数
* Input:          EventRpcObjAttrChangeNotifyWraper& Notify 属性改变通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientObjAttrChange( INT64 UserId, EventRpcObjAttrChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientCoinChange
* Description:    事件模块-->货币的变化通知异步通知操作函数
* Input:          EventRpcCoinChangeNotifyWraper& Notify 货币的变化通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientCoinChange( INT64 UserId, EventRpcCoinChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientMovePos
* Description:    事件模块-->按点移动异步通知操作函数
* Input:          EventRpcMovePosNotifyWraper& Notify 按点移动通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientMovePos( INT64 UserId, EventRpcMovePosNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDir
* Description:    事件模块-->朝向异步通知操作函数
* Input:          EventRpcDirNotifyWraper& Notify 朝向通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientDir( INT64 UserId, EventRpcDirNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientStartFadeout
* Description:    事件模块-->开始淡出效果异步通知操作函数
* Input:          EventRpcStartFadeoutNotifyWraper& Notify 开始淡出效果通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientStartFadeout( INT64 UserId, EventRpcStartFadeoutNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientCinematicStart
* Description:    事件模块-->通知表演开始异步通知操作函数
* Input:          EventRpcCinematicStartNotifyWraper& Notify 通知表演开始通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientCinematicStart( INT64 UserId, EventRpcCinematicStartNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientCinematicEnd
* Description:    事件模块-->通知表演结束异步通知操作函数
* Input:          EventRpcCinematicEndNotifyWraper& Notify 通知表演结束通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleEvent::SendToClientCinematicEnd( INT64 UserId, EventRpcCinematicEndNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



