/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleAuction.cpp
* Author:       甘业清
* Description:  拍卖行类，包含以下内容
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

#include "AuctionModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleAuction);

//拍卖行实现类构造函数
ModuleAuction::ModuleAuction()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_AUCTIONINFO_REQUEST, &ModuleAuction::RpcAuctionInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_AUCTIONINFO_REQUEST, new Some_Factory<AuctionRpcAuctionInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_SELLITEM_REQUEST, &ModuleAuction::RpcSellItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_SELLITEM_REQUEST, new Some_Factory<AuctionRpcSellItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_SELLAGAIN_REQUEST, &ModuleAuction::RpcSellAgain);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_SELLAGAIN_REQUEST, new Some_Factory<AuctionRpcSellAgainAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_BUY_REQUEST, &ModuleAuction::RpcBuy);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_BUY_REQUEST, new Some_Factory<AuctionRpcBuyAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_GETITEM_REQUEST, &ModuleAuction::RpcGetItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_GETITEM_REQUEST, new Some_Factory<AuctionRpcGetItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_RECORD_REQUEST, &ModuleAuction::RpcRecord);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_RECORD_REQUEST, new Some_Factory<AuctionRpcRecordAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST, &ModuleAuction::RpcItemInfoByClass);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_ITEMINFOBYCLASS_REQUEST, new Some_Factory<AuctionRpcItemInfoByClassAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_SALEPREPARE_REQUEST, &ModuleAuction::RpcSalePrepare);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_SALEPREPARE_REQUEST, new Some_Factory<AuctionRpcSalePrepareAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_GETITEMBACK_REQUEST, &ModuleAuction::RpcGetItemBack);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_GETITEMBACK_REQUEST, new Some_Factory<AuctionRpcGetItemBackAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_AUCTION_GETMYSALELIST_REQUEST, &ModuleAuction::RpcGetMySaleList);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_AUCTION_GETMYSALELIST_REQUEST, new Some_Factory<AuctionRpcGetMySaleListAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataAuctionV1";
		
}

//拍卖行实现类析构函数
ModuleAuction::~ModuleAuction()
{

}


//获取模块ID
UINT8 ModuleAuction::GetModuleId()
{
	return MODULE_ID_AUCTION;
}

//获取模块名字
TStr ModuleAuction::GetModuleName()
{
	return "Auction";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleAuction::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleAuction::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleAuction::GetInitializeOrder()
{
	return MODULE_ID_AUCTION;
}

//获取结束退出顺序
int ModuleAuction::GetFinalizeOrder()
{
	return MODULE_ID_AUCTION;
}

//初始化
bool ModuleAuction::Initialize()
{

	

	return true;
}

//结束退出
void ModuleAuction::Finalize()
{

}


//毫秒级Tick回调
void ModuleAuction::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleAuction::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleAuction::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleAuction::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleAuction::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleAuction::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleAuction::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleAuction::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleAuction::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleAuction::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

