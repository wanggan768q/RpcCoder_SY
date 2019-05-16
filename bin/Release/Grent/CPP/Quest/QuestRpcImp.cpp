/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     CliRpcQuestImp.cpp
* Author:       甘业清
* Description:  Quest类，包含以下内容
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/
#include "QuestModule.h"
#include "MsgStreamMgr.h"


/********************************************************************************************
* Function:       SendToClientOnAcceptQuest
* Description:    Quest-->OnAcceptQuest异步通知操作函数
* Input:          QuestRpcOnAcceptQuestNotifyWraper& Notify OnAcceptQuest通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientOnAcceptQuest( INT64 UserId, QuestRpcOnAcceptQuestNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcCompleteQuestStep
* Description:    Quest-->CompleteQuestStep同步调用操作函数
* Input:          QuestRpcCompleteQuestStepAskWraper& Ask CompleteQuestStep请求
* Output:         QuestRpcCompleteQuestStepReplyWraper& Reply CompleteQuestStep回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcCompleteQuestStep( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientOnCompleteQuest
* Description:    Quest-->OnCompleteQuest异步通知操作函数
* Input:          QuestRpcOnCompleteQuestNotifyWraper& Notify OnCompleteQuest通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientOnCompleteQuest( INT64 UserId, QuestRpcOnCompleteQuestNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       SendToClientUpdateQuest
* Description:    Quest-->更新任务异步通知操作函数
* Input:          QuestRpcUpdateQuestNotifyWraper& Notify 更新任务通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientUpdateQuest( INT64 UserId, QuestRpcUpdateQuestNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcGiveUpQuest
* Description:    Quest-->放弃任务同步调用操作函数
* Input:          QuestRpcGiveUpQuestAskWraper& Ask 放弃任务请求
* Output:         QuestRpcGiveUpQuestReplyWraper& Reply 放弃任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcGiveUpQuest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCompleteQuest
* Description:    Quest-->完成任务同步调用操作函数
* Input:          QuestRpcCompleteQuestAskWraper& Ask 完成任务请求
* Output:         QuestRpcCompleteQuestReplyWraper& Reply 完成任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcCompleteQuest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcCompleteAcceptChatMenu
* Description:    Quest-->完成接受任务对话框同步调用操作函数
* Input:          QuestRpcCompleteAcceptChatMenuAskWraper& Ask 完成接受任务对话框请求
* Output:         QuestRpcCompleteAcceptChatMenuReplyWraper& Reply 完成接受任务对话框回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcCompleteAcceptChatMenu( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcAcceptQuest
* Description:    Quest-->客户端接受任务同步调用操作函数
* Input:          QuestRpcAcceptQuestAskWraper& Ask 客户端接受任务请求
* Output:         QuestRpcAcceptQuestReplyWraper& Reply 客户端接受任务回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcAcceptQuest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncQuest
* Description:    Quest-->SyncQuest同步调用操作函数
* Input:          QuestRpcSyncQuestAskWraper& Ask SyncQuest请求
* Output:         QuestRpcSyncQuestReplyWraper& Reply SyncQuest回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcSyncQuest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcGetReward
* Description:    Quest-->GetReward同步调用操作函数
* Input:          QuestRpcGetRewardAskWraper& Ask GetReward请求
* Output:         QuestRpcGetRewardReplyWraper& Reply GetReward回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcGetReward( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientRemoveQuestNotify
* Description:    Quest-->上次任务通知异步通知操作函数
* Input:          QuestRpcRemoveQuestNotifyNotifyWraper& Notify 上次任务通知通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientRemoveQuestNotify( INT64 UserId, QuestRpcRemoveQuestNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcGetQuestData
* Description:    Quest-->获取某个任务数据同步调用操作函数
* Input:          QuestRpcGetQuestDataAskWraper& Ask 获取某个任务数据请求
* Output:         QuestRpcGetQuestDataReplyWraper& Reply 获取某个任务数据回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcGetQuestData( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncDailyQuest
* Description:    Quest-->每日活动同步调用操作函数
* Input:          QuestRpcSyncDailyQuestAskWraper& Ask 每日活动请求
* Output:         QuestRpcSyncDailyQuestReplyWraper& Reply 每日活动回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcSyncDailyQuest( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientDailyQuestUpdate
* Description:    Quest-->每日活动任务更新异步通知操作函数
* Input:          QuestRpcDailyQuestUpdateNotifyWraper& Notify 每日活动任务更新通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientDailyQuestUpdate( INT64 UserId, QuestRpcDailyQuestUpdateNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcConsumeItem
* Description:    Quest-->任务消耗物品同步调用操作函数
* Input:          QuestRpcConsumeItemAskWraper& Ask 任务消耗物品请求
* Output:         QuestRpcConsumeItemReplyWraper& Reply 任务消耗物品回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcConsumeItem( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       RpcSyncCompleteQuestIds
* Description:    Quest-->完成任务id请求同步调用操作函数
* Input:          QuestRpcSyncCompleteQuestIdsAskWraper& Ask 完成任务id请求请求
* Output:         QuestRpcSyncCompleteQuestIdsReplyWraper& Reply 完成任务id请求回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcSyncCompleteQuestIds( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientCompleteQuestIdsNotify
* Description:    Quest-->完成的任务列表异步通知操作函数
* Input:          QuestRpcCompleteQuestIdsNotifyNotifyWraper& Notify 完成的任务列表通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientCompleteQuestIdsNotify( INT64 UserId, QuestRpcCompleteQuestIdsNotifyNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}

/********************************************************************************************
* Function:       RpcEliteFinishCount
* Description:    Quest-->精英怪击杀次数同步调用操作函数
* Input:          QuestRpcEliteFinishCountAskWraper& Ask 精英怪击杀次数请求
* Output:         QuestRpcEliteFinishCountReplyWraper& Reply 精英怪击杀次数回应
* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
********************************************************************************************/
static int ModuleQuest::RpcEliteFinishCount( CPlayer* pPlayer, CPacket* pPacket)
{

	//逻辑代码


	//设置返回结果
	Reply.SetResult(0);
	return 0;
}

/********************************************************************************************
* Function:       SendToClientSyncCanAcceptQuest
* Description:    Quest-->通知新可接任务异步通知操作函数
* Input:          QuestRpcSyncCanAcceptQuestNotifyWraper& Notify 通知新可接任务通知
* Input:          INT64 UserId 需要通知到的用户ID
* Output:         无
* Return:         无
********************************************************************************************/
void ModuleQuest::SendToClientSyncCanAcceptQuest( INT64 UserId, QuestRpcSyncCanAcceptQuestNotifyWraper& Notify )
{
	MsgStreamMgr::Instance().SendMsg( UserId, 0, Notify );
}



