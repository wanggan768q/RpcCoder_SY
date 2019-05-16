/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleContact.cpp
* Author:       甘业清
* Description:  联系人类，包含以下内容
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

#include "ContactModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleContact);

//联系人实现类构造函数
ModuleContact::ModuleContact()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_ADDFRIEND_REQUEST, &ModuleContact::RpcAddFriend);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_ADDFRIEND_REQUEST, new Some_Factory<ContactRpcAddFriendAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST, &ModuleContact::RpcCancelRelationShip);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_CANCELRELATIONSHIP_REQUEST, new Some_Factory<ContactRpcCancelRelationShipAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST, &ModuleContact::RpcAddBlackList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_ADDBLACKLIST_REQUEST, new Some_Factory<ContactRpcAddBlackListAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST, &ModuleContact::RpcSyncAddressBook);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SYNCADDRESSBOOK_REQUEST, new Some_Factory<ContactRpcSyncAddressBookAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_CONTACTSETTING_REQUEST, &ModuleContact::RpcContactSetting);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_CONTACTSETTING_REQUEST, new Some_Factory<ContactRpcContactSettingAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST, &ModuleContact::RpcCreateFriendGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_CREATEFRIENDGROUP_REQUEST, new Some_Factory<ContactRpcCreateFriendGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST, &ModuleContact::RpcMoveToFriendGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_MOVETOFRIENDGROUP_REQUEST, new Some_Factory<ContactRpcMoveToFriendGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST, &ModuleContact::RpcRemoveFriendGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_REMOVEFRIENDGROUP_REQUEST, new Some_Factory<ContactRpcRemoveFriendGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_RENAMEGROUP_REQUEST, &ModuleContact::RpcRenameGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_RENAMEGROUP_REQUEST, new Some_Factory<ContactRpcRenameGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST, &ModuleContact::RpcAgreeApplication);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_AGREEAPPLICATION_REQUEST, new Some_Factory<ContactRpcAgreeApplicationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST, &ModuleContact::RpcSetFriendGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SETFRIENDGROUP_REQUEST, new Some_Factory<ContactRpcSetFriendGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_REJECTAPPLY_REQUEST, &ModuleContact::RpcRejectApply);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_REJECTAPPLY_REQUEST, new Some_Factory<ContactRpcRejectApplyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST, &ModuleContact::RpcRecommendContact);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_RECOMMENDCONTACT_REQUEST, new Some_Factory<ContactRpcRecommendContactAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_REJECTALL_REQUEST, &ModuleContact::RpcRejectAll);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_REJECTALL_REQUEST, new Some_Factory<ContactRpcRejectAllAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST, &ModuleContact::RpcAddFriendShipPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_ADDFRIENDSHIPPOINT_REQUEST, new Some_Factory<ContactRpcAddFriendShipPointAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SORTGROUP_REQUEST, &ModuleContact::RpcSortGroup);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SORTGROUP_REQUEST, new Some_Factory<ContactRpcSortGroupAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST, &ModuleContact::RpcSetFriendAlias);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SETFRIENDALIAS_REQUEST, new Some_Factory<ContactRpcSetFriendAliasAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST, &ModuleContact::RpcSendFriendGiftPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SENDFRIENDGIFTPOINT_REQUEST, new Some_Factory<ContactRpcSendFriendGiftPointAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST, &ModuleContact::RpcAcquireGiftPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_ACQUIREGIFTPOINT_REQUEST, new Some_Factory<ContactRpcAcquireGiftPointAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST, &ModuleContact::RpcSendAllFriendGiftPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_SENDALLFRIENDGIFTPOINT_REQUEST, new Some_Factory<ContactRpcSendAllFriendGiftPointAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST, &ModuleContact::RpcAcquireAllGiftPoint);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_ACQUIREALLGIFTPOINT_REQUEST, new Some_Factory<ContactRpcAcquireAllGiftPointAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST, &ModuleContact::RpcDeleteGroupRole);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_DELETEGROUPROLE_REQUEST, new Some_Factory<ContactRpcDeleteGroupRoleAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST, &ModuleContact::RpcAgreeAllApplication);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_AGREEALLAPPLICATION_REQUEST, new Some_Factory<ContactRpcAgreeAllApplicationAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_CHATTO_REQUEST, &ModuleContact::RpcChatTo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_CHATTO_REQUEST, new Some_Factory<ContactRpcChatToAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CONTACT_READMSG_REQUEST, &ModuleContact::RpcReadMsg);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CONTACT_READMSG_REQUEST, new Some_Factory<ContactRpcReadMsgAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataContactV1";
		
}

//联系人实现类析构函数
ModuleContact::~ModuleContact()
{

}


//获取模块ID
UINT8 ModuleContact::GetModuleId()
{
	return MODULE_ID_CONTACT;
}

//获取模块名字
TStr ModuleContact::GetModuleName()
{
	return "Contact";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleContact::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleContact::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleContact::GetInitializeOrder()
{
	return MODULE_ID_CONTACT;
}

//获取结束退出顺序
int ModuleContact::GetFinalizeOrder()
{
	return MODULE_ID_CONTACT;
}

//初始化
bool ModuleContact::Initialize()
{

	

	return true;
}

//结束退出
void ModuleContact::Finalize()
{

}


//毫秒级Tick回调
void ModuleContact::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleContact::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleContact::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleContact::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleContact::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleContact::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleContact::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleContact::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleContact::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleContact::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

