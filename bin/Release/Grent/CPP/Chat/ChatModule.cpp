/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleChat.cpp
* Author:       甘业清
* Description:  Chat类，包含以下内容
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

#include "ChatModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleChat);

//Chat实现类构造函数
ModuleChat::ModuleChat()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CHAT_CHAT_REQUEST, &ModuleChat::RpcChat);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CHAT_CHAT_REQUEST, new Some_Factory<ChatRpcChatAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataChatV1";
		
}

//Chat实现类析构函数
ModuleChat::~ModuleChat()
{

}


//获取模块ID
UINT8 ModuleChat::GetModuleId()
{
	return MODULE_ID_CHAT;
}

//获取模块名字
TStr ModuleChat::GetModuleName()
{
	return "Chat";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleChat::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleChat::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleChat::GetInitializeOrder()
{
	return MODULE_ID_CHAT;
}

//获取结束退出顺序
int ModuleChat::GetFinalizeOrder()
{
	return MODULE_ID_CHAT;
}

//初始化
bool ModuleChat::Initialize()
{

	

	return true;
}

//结束退出
void ModuleChat::Finalize()
{

}


//毫秒级Tick回调
void ModuleChat::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleChat::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleChat::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleChat::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleChat::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleChat::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleChat::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleChat::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleChat::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleChat::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

