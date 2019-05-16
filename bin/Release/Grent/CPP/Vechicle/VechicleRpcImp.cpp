/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcVechicleImp.cpp
* Author:       甘业清
* Description:  载具（变身）类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "VechicleModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcQuitVechile
* Description:    载具（变身）-->退出载具同步调用操作函数
* Input:          VechicleRpcQuitVechileAskWraper& Ask 退出载具请求
* Output:         VechicleRpcQuitVechileReplyWraper& Reply 退出载具回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleVechicle::RpcQuitVechile( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



