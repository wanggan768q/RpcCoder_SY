/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleQuest.h
* Author:       甘业清
* Description:  Quest类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_QUEST_H
#define __MODULE_QUEST_H


#include "ModuleBase.h"
#include "QuestRpcWraper.h"




//Quest实现类
class ModuleQuest : public ModuleBase
{
	DECLARE_INSTANCE(ModuleQuest);
public:
	friend class			ModuleMgr;

public:
	//Quest实现类构造函数
	ModuleQuest();
	
	//Quest实现类析构函数
	virtual					~ModuleQuest();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:
	/********************************************************************************************
	* Function:       SendToClientOnAcceptQuest
	* Description:    Quest-->OnAcceptQuest异步通知操作函数
	* Input:          QuestRpcOnAcceptQuestNotifyWraper& Notify OnAcceptQuest通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOnAcceptQuest( INT64 UserId, QuestRpcOnAcceptQuestNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcCompleteQuestStep
	* Description:    Quest-->CompleteQuestStep同步调用操作函数
	* Input:          QuestRpcCompleteQuestStepAskWraper& Ask CompleteQuestStep请求
	* Output:         QuestRpcCompleteQuestStepReplyWraper& Reply CompleteQuestStep回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCompleteQuestStep( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientOnCompleteQuest
	* Description:    Quest-->OnCompleteQuest异步通知操作函数
	* Input:          QuestRpcOnCompleteQuestNotifyWraper& Notify OnCompleteQuest通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientOnCompleteQuest( INT64 UserId, QuestRpcOnCompleteQuestNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       SendToClientUpdateQuest
	* Description:    Quest-->更新任务异步通知操作函数
	* Input:          QuestRpcUpdateQuestNotifyWraper& Notify 更新任务通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientUpdateQuest( INT64 UserId, QuestRpcUpdateQuestNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcGiveUpQuest
	* Description:    Quest-->放弃任务同步调用操作函数
	* Input:          QuestRpcGiveUpQuestAskWraper& Ask 放弃任务请求
	* Output:         QuestRpcGiveUpQuestReplyWraper& Reply 放弃任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGiveUpQuest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCompleteQuest
	* Description:    Quest-->完成任务同步调用操作函数
	* Input:          QuestRpcCompleteQuestAskWraper& Ask 完成任务请求
	* Output:         QuestRpcCompleteQuestReplyWraper& Reply 完成任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCompleteQuest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcCompleteAcceptChatMenu
	* Description:    Quest-->完成接受任务对话框同步调用操作函数
	* Input:          QuestRpcCompleteAcceptChatMenuAskWraper& Ask 完成接受任务对话框请求
	* Output:         QuestRpcCompleteAcceptChatMenuReplyWraper& Reply 完成接受任务对话框回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcCompleteAcceptChatMenu( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcAcceptQuest
	* Description:    Quest-->客户端接受任务同步调用操作函数
	* Input:          QuestRpcAcceptQuestAskWraper& Ask 客户端接受任务请求
	* Output:         QuestRpcAcceptQuestReplyWraper& Reply 客户端接受任务回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcAcceptQuest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSyncQuest
	* Description:    Quest-->SyncQuest同步调用操作函数
	* Input:          QuestRpcSyncQuestAskWraper& Ask SyncQuest请求
	* Output:         QuestRpcSyncQuestReplyWraper& Reply SyncQuest回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncQuest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcGetReward
	* Description:    Quest-->GetReward同步调用操作函数
	* Input:          QuestRpcGetRewardAskWraper& Ask GetReward请求
	* Output:         QuestRpcGetRewardReplyWraper& Reply GetReward回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetReward( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientRemoveQuestNotify
	* Description:    Quest-->上次任务通知异步通知操作函数
	* Input:          QuestRpcRemoveQuestNotifyNotifyWraper& Notify 上次任务通知通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientRemoveQuestNotify( INT64 UserId, QuestRpcRemoveQuestNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcGetQuestData
	* Description:    Quest-->获取某个任务数据同步调用操作函数
	* Input:          QuestRpcGetQuestDataAskWraper& Ask 获取某个任务数据请求
	* Output:         QuestRpcGetQuestDataReplyWraper& Reply 获取某个任务数据回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcGetQuestData( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSyncDailyQuest
	* Description:    Quest-->每日活动同步调用操作函数
	* Input:          QuestRpcSyncDailyQuestAskWraper& Ask 每日活动请求
	* Output:         QuestRpcSyncDailyQuestReplyWraper& Reply 每日活动回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncDailyQuest( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientDailyQuestUpdate
	* Description:    Quest-->每日活动任务更新异步通知操作函数
	* Input:          QuestRpcDailyQuestUpdateNotifyWraper& Notify 每日活动任务更新通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientDailyQuestUpdate( INT64 UserId, QuestRpcDailyQuestUpdateNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcConsumeItem
	* Description:    Quest-->任务消耗物品同步调用操作函数
	* Input:          QuestRpcConsumeItemAskWraper& Ask 任务消耗物品请求
	* Output:         QuestRpcConsumeItemReplyWraper& Reply 任务消耗物品回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcConsumeItem( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       RpcSyncCompleteQuestIds
	* Description:    Quest-->完成任务id请求同步调用操作函数
	* Input:          QuestRpcSyncCompleteQuestIdsAskWraper& Ask 完成任务id请求请求
	* Output:         QuestRpcSyncCompleteQuestIdsReplyWraper& Reply 完成任务id请求回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcSyncCompleteQuestIds( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientCompleteQuestIdsNotify
	* Description:    Quest-->完成的任务列表异步通知操作函数
	* Input:          QuestRpcCompleteQuestIdsNotifyNotifyWraper& Notify 完成的任务列表通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientCompleteQuestIdsNotify( INT64 UserId, QuestRpcCompleteQuestIdsNotifyNotifyWraper& Notify );

	/********************************************************************************************
	* Function:       RpcEliteFinishCount
	* Description:    Quest-->精英怪击杀次数同步调用操作函数
	* Input:          QuestRpcEliteFinishCountAskWraper& Ask 精英怪击杀次数请求
	* Output:         QuestRpcEliteFinishCountReplyWraper& Reply 精英怪击杀次数回应
	* Return:         int 高16位为系统返回值RpcCallErrorCodeE，获取方法GET_RPC_ERROR_CODE(ret) 
	*                     低16位为操作返回值，获取方法GET_OPERATION_RET_CODE(ret)
	********************************************************************************************/
	static int RpcEliteFinishCount( CPlayer* pPlayer, CPacket* pPacket );

	/********************************************************************************************
	* Function:       SendToClientSyncCanAcceptQuest
	* Description:    Quest-->通知新可接任务异步通知操作函数
	* Input:          QuestRpcSyncCanAcceptQuestNotifyWraper& Notify 通知新可接任务通知
	* Input:          INT64 UserId 需要通知到的用户ID
	* Output:         无
	* Return:         无
	********************************************************************************************/
	//virtual void SendToClientSyncCanAcceptQuest( INT64 UserId, QuestRpcSyncCanAcceptQuestNotifyWraper& Notify );



private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif