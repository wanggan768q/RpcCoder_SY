/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcTreasureMapImp.cpp
* Author:       甘业清
* Description:  藏宝图类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "TreasureMapModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcTreasureMapSync
* Description:    藏宝图-->同步同步调用操作函数
* Input:          TreasureMapRpcTreasureMapSyncAskWraper& Ask 同步请求
* Output:         TreasureMapRpcTreasureMapSyncReplyWraper& Reply 同步回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleTreasureMap::RpcTreasureMapSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientTreasureMapChange
* Description:    藏宝图-->变化异步通知操作函数
* Input:          TreasureMapRpcTreasureMapChangeNotifyWraper& Notify 变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleTreasureMap::SendToClientTreasureMapChange( INT64 UserId, TreasureMapRpcTreasureMapChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



