/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcWorldBossImp.cpp
* Author:       甘业清
* Description:  世界BOSS模块类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "WorldBossModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcWorldBossInfo
* Description:    世界BOSS模块-->世界BOSS信息同步调用操作函数
* Input:          WorldBossRpcWorldBossInfoAskWraper& Ask 世界BOSS信息请求
* Output:         WorldBossRpcWorldBossInfoReplyWraper& Reply 世界BOSS信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldBoss::RpcWorldBossInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcWorldBossRankInfo
* Description:    世界BOSS模块-->世界BOSS排行榜信息同步调用操作函数
* Input:          WorldBossRpcWorldBossRankInfoAskWraper& Ask 世界BOSS伤害排行信息请求
* Output:         WorldBossRpcWorldBossRankInfoReplyWraper& Reply 世界BOSS伤害排行信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleWorldBoss::RpcWorldBossRankInfo( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



