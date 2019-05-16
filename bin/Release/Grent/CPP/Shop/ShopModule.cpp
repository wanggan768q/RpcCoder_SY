/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleShop.cpp
* Author:       甘业清
* Description:  商店类，包含以下内容
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

#include "ShopModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleShop);

//商店实现类构造函数
ModuleShop::ModuleShop()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_SHOP_BUYITEM_REQUEST, &ModuleShop::RpcBuyItem);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SHOP_BUYITEM_REQUEST, new Some_Factory<ShopRpcBuyItemAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SHOP_SHOPINFO_REQUEST, &ModuleShop::RpcShopInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SHOP_SHOPINFO_REQUEST, new Some_Factory<ShopRpcShopInfoAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataShopV1";
		
}

//商店实现类析构函数
ModuleShop::~ModuleShop()
{

}


//获取模块ID
UINT8 ModuleShop::GetModuleId()
{
	return MODULE_ID_SHOP;
}

//获取模块名字
TStr ModuleShop::GetModuleName()
{
	return "Shop";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleShop::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleShop::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleShop::GetInitializeOrder()
{
	return MODULE_ID_SHOP;
}

//获取结束退出顺序
int ModuleShop::GetFinalizeOrder()
{
	return MODULE_ID_SHOP;
}

//初始化
bool ModuleShop::Initialize()
{

	

	return true;
}

//结束退出
void ModuleShop::Finalize()
{

}


//毫秒级Tick回调
void ModuleShop::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleShop::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleShop::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleShop::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleShop::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleShop::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleShop::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleShop::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleShop::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleShop::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

