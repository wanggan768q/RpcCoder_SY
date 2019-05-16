/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcClimTowerImp.cpp
* Author:       甘业清
* Description:  爬塔玩法类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "ClimTowerModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientOpenRule
* Description:    爬塔玩法-->玩法开启规则异步通知操作函数
* Input:          ClimTowerRpcOpenRuleNotifyWraper& Notify 玩法开启规则通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleClimTower::SendToClientOpenRule( INT64 UserId, ClimTowerRpcOpenRuleNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcEnter
* Description:    爬塔玩法-->进入爬塔活动同步调用操作函数
* Input:          ClimTowerRpcEnterAskWraper& Ask 进入爬塔活动请求
* Output:         ClimTowerRpcEnterReplyWraper& Reply 进入爬塔活动回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleClimTower::RpcEnter( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcChallenge
* Description:    爬塔玩法-->挑战同步调用操作函数
* Input:          ClimTowerRpcChallengeAskWraper& Ask 挑战请求
* Output:         ClimTowerRpcChallengeReplyWraper& Reply 挑战回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleClimTower::RpcChallenge( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcRank
* Description:    爬塔玩法-->获取排行榜信息同步调用操作函数
* Input:          ClimTowerRpcRankAskWraper& Ask 获取排行榜信息请求
* Output:         ClimTowerRpcRankReplyWraper& Reply 获取排行榜信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleClimTower::RpcRank( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcFirstVicReward
* Description:    爬塔玩法-->首次通关奖励领奖同步调用操作函数
* Input:          ClimTowerRpcFirstVicRewardAskWraper& Ask 首次通关奖励领奖请求
* Output:         ClimTowerRpcFirstVicRewardReplyWraper& Reply 首次通关奖励领奖回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleClimTower::RpcFirstVicReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNextLayer
* Description:    爬塔玩法-->下一层通知异步通知操作函数
* Input:          ClimTowerRpcNextLayerNotifyWraper& Notify 下一层通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleClimTower::SendToClientNextLayer( INT64 UserId, ClimTowerRpcNextLayerNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientChallengeEnd
* Description:    爬塔玩法-->挑战结束异步通知操作函数
* Input:          ClimTowerRpcChallengeEndNotifyWraper& Notify 挑战结束通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleClimTower::SendToClientChallengeEnd( INT64 UserId, ClimTowerRpcChallengeEndNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientWaveRefresh
* Description:    爬塔玩法-->每波怪物刷新通知异步通知操作函数
* Input:          ClimTowerRpcWaveRefreshNotifyWraper& Notify 每波怪物刷新通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleClimTower::SendToClientWaveRefresh( INT64 UserId, ClimTowerRpcWaveRefreshNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



