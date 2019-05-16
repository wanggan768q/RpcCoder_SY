/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleMail.cpp
* Author:       甘业清
* Description:  邮件类，包含以下内容
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

#include "MailModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleMail);

//邮件实现类构造函数
ModuleMail::ModuleMail()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_MAIL_INITMAIL_REQUEST, &ModuleMail::RpcInitMail);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MAIL_INITMAIL_REQUEST, new Some_Factory<MailRpcInitMailAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MAIL_READMAIL_REQUEST, &ModuleMail::RpcReadMail);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MAIL_READMAIL_REQUEST, new Some_Factory<MailRpcReadMailAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MAIL_DELETEMAIL_REQUEST, &ModuleMail::RpcDeleteMail);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MAIL_DELETEMAIL_REQUEST, new Some_Factory<MailRpcDeleteMailAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_MAIL_GETMAIL_REQUEST, &ModuleMail::RpcGetMail);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_MAIL_GETMAIL_REQUEST, new Some_Factory<MailRpcGetMailAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataMailV1";
		
}

//邮件实现类析构函数
ModuleMail::~ModuleMail()
{

}


//获取模块ID
UINT8 ModuleMail::GetModuleId()
{
	return MODULE_ID_MAIL;
}

//获取模块名字
TStr ModuleMail::GetModuleName()
{
	return "Mail";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleMail::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleMail::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleMail::GetInitializeOrder()
{
	return MODULE_ID_MAIL;
}

//获取结束退出顺序
int ModuleMail::GetFinalizeOrder()
{
	return MODULE_ID_MAIL;
}

//初始化
bool ModuleMail::Initialize()
{

	

	return true;
}

//结束退出
void ModuleMail::Finalize()
{

}


//毫秒级Tick回调
void ModuleMail::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleMail::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleMail::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleMail::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleMail::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleMail::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleMail::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleMail::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleMail::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleMail::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

