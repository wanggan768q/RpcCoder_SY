/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcSmallMapImp.cpp
* Author:       甘业清
* Description:  小地图相关类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "SmallMapModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientNewObj
* Description:    小地图相关-->新的对象创建异步通知操作函数
* Input:          SmallMapRpcNewObjNotifyWraper& Notify 新的对象创建通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSmallMap::SendToClientNewObj( INT64 UserId, SmallMapRpcNewObjNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientDelObj
* Description:    小地图相关-->删除obj异步通知操作函数
* Input:          SmallMapRpcDelObjNotifyWraper& Notify 删除obj通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleSmallMap::SendToClientDelObj( INT64 UserId, SmallMapRpcDelObjNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



