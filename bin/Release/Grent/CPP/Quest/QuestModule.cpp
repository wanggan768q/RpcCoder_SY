/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleQuest.cpp
* Author:       甘业清
* Description:  Quest类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#include "QuestModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleQuest);

//Quest实现类构造函数
ModuleQuest::ModuleQuest()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST, &ModuleQuest::RpcCompleteQuestStep);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_COMPLETEQUESTSTEP_REQUEST, new Some_Factory<QuestRpcCompleteQuestStepAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_GIVEUPQUEST_REQUEST, &ModuleQuest::RpcGiveUpQuest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_GIVEUPQUEST_REQUEST, new Some_Factory<QuestRpcGiveUpQuestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_COMPLETEQUEST_REQUEST, &ModuleQuest::RpcCompleteQuest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_COMPLETEQUEST_REQUEST, new Some_Factory<QuestRpcCompleteQuestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST, &ModuleQuest::RpcCompleteAcceptChatMenu);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_COMPLETEACCEPTCHATMENU_REQUEST, new Some_Factory<QuestRpcCompleteAcceptChatMenuAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_ACCEPTQUEST_REQUEST, &ModuleQuest::RpcAcceptQuest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_ACCEPTQUEST_REQUEST, new Some_Factory<QuestRpcAcceptQuestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_SYNCQUEST_REQUEST, &ModuleQuest::RpcSyncQuest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_SYNCQUEST_REQUEST, new Some_Factory<QuestRpcSyncQuestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_GETREWARD_REQUEST, &ModuleQuest::RpcGetReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_GETREWARD_REQUEST, new Some_Factory<QuestRpcGetRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_GETQUESTDATA_REQUEST, &ModuleQuest::RpcGetQuestData);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_GETQUESTDATA_REQUEST, new Some_Factory<QuestRpcGetQuestDataAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST, &ModuleQuest::RpcSyncDailyQuest);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_SYNCDAILYQUEST_REQUEST, new Some_Factory<QuestRpcSyncDailyQuestAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_CONSUMEITEM_REQUEST, &ModuleQuest::RpcConsumeItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_CONSUMEITEM_REQUEST, new Some_Factory<QuestRpcConsumeItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST, &ModuleQuest::RpcSyncCompleteQuestIds);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_SYNCCOMPLETEQUESTIDS_REQUEST, new Some_Factory<QuestRpcSyncCompleteQuestIdsAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST, &ModuleQuest::RpcEliteFinishCount);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_QUEST_ELITEFINISHCOUNT_REQUEST, new Some_Factory<QuestRpcEliteFinishCountAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataQuestV1";
		
}

//Quest实现类析构函数
ModuleQuest::~ModuleQuest()
{

}


//获取模块ID
UINT8 ModuleQuest::GetModuleId()
{
	return MODULE_ID_QUEST;
}

//获取模块名字
TStr ModuleQuest::GetModuleName()
{
	return "Quest";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleQuest::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleQuest::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleQuest::GetInitializeOrder()
{
	return MODULE_ID_QUEST;
}

//获取结束退出顺序
int ModuleQuest::GetFinalizeOrder()
{
	return MODULE_ID_QUEST;
}

//初始化
bool ModuleQuest::Initialize()
{

	

	return true;
}

//结束退出
void ModuleQuest::Finalize()
{

}


//毫秒级Tick回调
void ModuleQuest::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleQuest::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleQuest::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleQuest::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleQuest::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleQuest::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleQuest::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleQuest::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleQuest::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleQuest::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

