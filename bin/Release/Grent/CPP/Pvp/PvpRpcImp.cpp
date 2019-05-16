/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcPvpImp.cpp
* Author:       甘业清
* Description:  Pvp类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "PvpModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       RpcRank
* Description:    Pvp-->Rank同步调用操作函数
* Input:          PvpRpcRankAskWraper& Ask Rank请求
* Output:         PvpRpcRankReplyWraper& Reply Rank回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcRank( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcMatch
* Description:    Pvp-->匹配同步调用操作函数
* Input:          PvpRpcMatchAskWraper& Ask Match请求
* Output:         PvpRpcMatchReplyWraper& Reply Match回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcMatch( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientMatchNotify
* Description:    Pvp-->匹配的通知异步通知操作函数
* Input:          PvpRpcMatchNotifyNotifyWraper& Notify 匹配的通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientMatchNotify( INT64 UserId, PvpRpcMatchNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcMatchCancle
* Description:    Pvp-->取消匹配同步调用操作函数
* Input:          PvpRpcMatchCancleAskWraper& Ask MatchCancle请求
* Output:         PvpRpcMatchCancleReplyWraper& Reply MatchCancle回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcMatchCancle( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientMatchCancleNotify
* Description:    Pvp-->取消匹配通知异步通知操作函数
* Input:          PvpRpcMatchCancleNotifyNotifyWraper& Notify 取消匹配通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientMatchCancleNotify( INT64 UserId, PvpRpcMatchCancleNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcPvpBattleInfoSync
* Description:    Pvp-->请求战斗信息同步调用操作函数
* Input:          PvpRpcPvpBattleInfoSyncAskWraper& Ask 请求战斗信息请求
* Output:         PvpRpcPvpBattleInfoSyncReplyWraper& Reply 请求战斗信息回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcPvpBattleInfoSync( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientPvpBattleStart
* Description:    Pvp-->PvpBattleStart异步通知操作函数
* Input:          PvpRpcPvpBattleStartNotifyWraper& Notify PvpBattleStart通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientPvpBattleStart( INT64 UserId, PvpRpcPvpBattleStartNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientPvpBattleEnd
* Description:    Pvp-->PvpBattleEnd异步通知操作函数
* Input:          PvpRpcPvpBattleEndNotifyWraper& Notify PvpBattleEnd通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientPvpBattleEnd( INT64 UserId, PvpRpcPvpBattleEndNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcPlayerReady
* Description:    Pvp-->PlayerReady同步调用操作函数
* Input:          PvpRpcPlayerReadyAskWraper& Ask PlayerReady请求
* Output:         PvpRpcPlayerReadyReplyWraper& Reply PlayerReady回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcPlayerReady( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientPlayerReadyNotify
* Description:    Pvp-->玩家准备的通知异步通知操作函数
* Input:          PvpRpcPlayerReadyNotifyNotifyWraper& Notify 玩家准备的通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientPlayerReadyNotify( INT64 UserId, PvpRpcPlayerReadyNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientReadyFaild
* Description:    Pvp-->等待确认超时异步通知操作函数
* Input:          PvpRpcReadyFaildNotifyWraper& Notify 等待确认超时通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientReadyFaild( INT64 UserId, PvpRpcReadyFaildNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientMatchSucess
* Description:    Pvp-->匹配完成异步通知操作函数
* Input:          PvpRpcMatchSucessNotifyWraper& Notify 匹配完成通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientMatchSucess( INT64 UserId, PvpRpcMatchSucessNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientRankChange
* Description:    Pvp-->段位变化异步通知操作函数
* Input:          PvpRpcRankChangeNotifyWraper& Notify 段位变化通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientRankChange( INT64 UserId, PvpRpcRankChangeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcReturnLastScene
* Description:    Pvp-->返回同步调用操作函数
* Input:          PvpRpcReturnLastSceneAskWraper& Ask 返回请求
* Output:         PvpRpcReturnLastSceneReplyWraper& Reply 返回回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcReturnLastScene( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientArenaStartTime
* Description:    Pvp-->通知开始时间异步通知操作函数
* Input:          PvpRpcArenaStartTimeNotifyWraper& Notify 通知开始时间通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientArenaStartTime( INT64 UserId, PvpRpcArenaStartTimeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateKillCount
* Description:    Pvp-->更新击杀数量异步通知操作函数
* Input:          PvpRpcUpdateKillCountNotifyWraper& Notify 更新击杀数量通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientUpdateKillCount( INT64 UserId, PvpRpcUpdateKillCountNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientArenaLeftTime
* Description:    Pvp-->剩余时间异步通知操作函数
* Input:          PvpRpcArenaLeftTimeNotifyWraper& Notify 剩余时间通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientArenaLeftTime( INT64 UserId, PvpRpcArenaLeftTimeNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcLastRank
* Description:    Pvp-->上个赛季的排行同步调用操作函数
* Input:          PvpRpcLastRankAskWraper& Ask 上个赛季的排行请求
* Output:         PvpRpcLastRankReplyWraper& Reply 上个赛季的排行回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcLastRank( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientNewSeason
* Description:    Pvp-->新赛季通知异步通知操作函数
* Input:          PvpRpcNewSeasonNotifyWraper& Notify 新赛季通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientNewSeason( INT64 UserId, PvpRpcNewSeasonNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcGetSeasonReward
* Description:    Pvp-->领取奖励同步调用操作函数
* Input:          PvpRpcGetSeasonRewardAskWraper& Ask 领取奖励请求
* Output:         PvpRpcGetSeasonRewardReplyWraper& Reply 领取奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcGetSeasonReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientReconnect
* Description:    Pvp-->重连异步通知操作函数
* Input:          PvpRpcReconnectNotifyWraper& Notify 重连通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModulePvp::SendToClientReconnect( INT64 UserId, PvpRpcReconnectNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcGetReward
* Description:    Pvp-->获取奖励同步调用操作函数
* Input:          PvpRpcGetRewardAskWraper& Ask 获取奖励请求
* Output:         PvpRpcGetRewardReplyWraper& Reply 获取奖励回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModulePvp::RpcGetReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}



