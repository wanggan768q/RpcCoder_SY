/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcCampFigthImp.cpp
* Author:       甘业清
* Description:  CampFigth类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "CampFigthModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcMilitaryBroken
* Description:    CampFigth-->MilitaryBroken同步调用操作函数
* Input:          CampFigthRpcMilitaryBrokenAskWraper& Ask MilitaryBroken请求
* Output:         CampFigthRpcMilitaryBrokenReplyWraper& Reply MilitaryBroken回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcMilitaryBroken( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCampFightContribution
* Description:    CampFigth-->CampFightContribution异步通知操作函数
* Input:          CampFigthRpcCampFightContributionNotifyWraper& Notify CampFightContribution通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCampFigth::SendToClientCampFightContribution( INT64 UserId, CampFigthRpcCampFightContributionNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientObjKillBroadcast
* Description:    CampFigth-->ObjKillBroadcast异步通知操作函数
* Input:          CampFigthRpcObjKillBroadcastNotifyWraper& Notify ObjKillBroadcast通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCampFigth::SendToClientObjKillBroadcast( INT64 UserId, CampFigthRpcObjKillBroadcastNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientNpcBirth
* Description:    CampFigth-->NpcBirth异步通知操作函数
* Input:          CampFigthRpcNpcBirthNotifyWraper& Notify NpcBirth通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCampFigth::SendToClientNpcBirth( INT64 UserId, CampFigthRpcNpcBirthNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcGetMilitaryValue
* Description:    CampFigth-->GetMilitaryValue同步调用操作函数
* Input:          CampFigthRpcGetMilitaryValueAskWraper& Ask GetMilitaryValue请求
* Output:         CampFigthRpcGetMilitaryValueReplyWraper& Reply GetMilitaryValue回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcGetMilitaryValue( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientKillDeadInfo
* Description:    CampFigth-->KillDeadInfo异步通知操作函数
* Input:          CampFigthRpcKillDeadInfoNotifyWraper& Notify KillDeadInfo通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCampFigth::SendToClientKillDeadInfo( INT64 UserId, CampFigthRpcKillDeadInfoNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcWorship
* Description:    CampFigth-->Worship同步调用操作函数
* Input:          CampFigthRpcWorshipAskWraper& Ask Worship请求
* Output:         CampFigthRpcWorshipReplyWraper& Reply Worship回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcWorship( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcWorshipRank
* Description:    CampFigth-->WorshipRank同步调用操作函数
* Input:          CampFigthRpcWorshipRankAskWraper& Ask WorshipRank请求
* Output:         CampFigthRpcWorshipRankReplyWraper& Reply WorshipRank回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcWorshipRank( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewSeason
* Description:    CampFigth-->新赛季异步通知操作函数
* Input:          CampFigthRpcNewSeasonNotifyWraper& Notify 新赛季通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleCampFigth::SendToClientNewSeason( INT64 UserId, CampFigthRpcNewSeasonNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcSyncRankReward
* Description:    CampFigth-->同步段位奖励同步调用操作函数
* Input:          CampFigthRpcSyncRankRewardAskWraper& Ask 同步段位奖励请求
* Output:         CampFigthRpcSyncRankRewardReplyWraper& Reply 同步段位奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcSyncRankReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetRankReward
* Description:    CampFigth-->获取段位奖励同步调用操作函数
* Input:          CampFigthRpcGetRankRewardAskWraper& Ask 获取段位奖励请求
* Output:         CampFigthRpcGetRankRewardReplyWraper& Reply 获取段位奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcGetRankReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcEnterBattleScene
* Description:    CampFigth-->进入战场同步调用操作函数
* Input:          CampFigthRpcEnterBattleSceneAskWraper& Ask 进入战场请求
* Output:         CampFigthRpcEnterBattleSceneReplyWraper& Reply 进入战场回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleCampFigth::RpcEnterBattleScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



