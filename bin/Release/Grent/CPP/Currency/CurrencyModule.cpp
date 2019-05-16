/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleCurrency.cpp
* Author:       甘业清
* Description:  货币类，包含以下内容
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

#include "CurrencyModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleCurrency);

//货币实现类构造函数
ModuleCurrency::ModuleCurrency()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_CURRENCY_TRANSFROM_REQUEST, &ModuleCurrency::RpcTransfrom);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CURRENCY_TRANSFROM_REQUEST, new Some_Factory<CurrencyRpcTransfromAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_CURRENCY_SHOW_REQUEST, &ModuleCurrency::RpcShow);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_CURRENCY_SHOW_REQUEST, new Some_Factory<CurrencyRpcShowAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataCurrencyV1";
		
}

//货币实现类析构函数
ModuleCurrency::~ModuleCurrency()
{

}


//获取模块ID
UINT8 ModuleCurrency::GetModuleId()
{
	return MODULE_ID_CURRENCY;
}

//获取模块名字
TStr ModuleCurrency::GetModuleName()
{
	return "Currency";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleCurrency::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleCurrency::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleCurrency::GetInitializeOrder()
{
	return MODULE_ID_CURRENCY;
}

//获取结束退出顺序
int ModuleCurrency::GetFinalizeOrder()
{
	return MODULE_ID_CURRENCY;
}

//初始化
bool ModuleCurrency::Initialize()
{

	

	return true;
}

//结束退出
void ModuleCurrency::Finalize()
{

}


//毫秒级Tick回调
void ModuleCurrency::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleCurrency::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleCurrency::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleCurrency::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleCurrency::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleCurrency::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleCurrency::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleCurrency::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleCurrency::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleCurrency::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

