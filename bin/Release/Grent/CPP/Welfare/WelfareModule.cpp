/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWelfare.cpp
* Author:       甘业清
* Description:  福利类，包含以下内容
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

#include "WelfareModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleWelfare);

//福利实现类构造函数
ModuleWelfare::ModuleWelfare()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST, &ModuleWelfare::RpcAccumulateSignIn);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_ACCUMULATESIGNIN_REQUEST, new Some_Factory<WelfareRpcAccumulateSignInAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST, &ModuleWelfare::RpcAccumulateGetReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_ACCUMULATEGETREWARD_REQUEST, new Some_Factory<WelfareRpcAccumulateGetRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_ONLINEBONUS_REQUEST, &ModuleWelfare::RpcOnlineBonus);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_ONLINEBONUS_REQUEST, new Some_Factory<WelfareRpcOnlineBonusAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST, &ModuleWelfare::RpcOnlineGetReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_ONLINEGETREWARD_REQUEST, new Some_Factory<WelfareRpcOnlineGetRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_LEVELBONUS_REQUEST, &ModuleWelfare::RpcLevelBonus);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_LEVELBONUS_REQUEST, new Some_Factory<WelfareRpcLevelBonusAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST, &ModuleWelfare::RpcLevelBonusReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_LEVELBONUSREWARD_REQUEST, new Some_Factory<WelfareRpcLevelBonusRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST, &ModuleWelfare::RpcMonthSignInBonus);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_MONTHSIGNINBONUS_REQUEST, new Some_Factory<WelfareRpcMonthSignInBonusAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST, &ModuleWelfare::RpcMonthSignInReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_MONTHSIGNINREWARD_REQUEST, new Some_Factory<WelfareRpcMonthSignInRewardAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST, &ModuleWelfare::RpcSpecLoginReward);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WELFARE_SPECLOGINREWARD_REQUEST, new Some_Factory<WelfareRpcSpecLoginRewardAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataWelfareV1";
		
}

//福利实现类析构函数
ModuleWelfare::~ModuleWelfare()
{

}


//获取模块ID
UINT8 ModuleWelfare::GetModuleId()
{
	return MODULE_ID_WELFARE;
}

//获取模块名字
TStr ModuleWelfare::GetModuleName()
{
	return "Welfare";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleWelfare::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleWelfare::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleWelfare::GetInitializeOrder()
{
	return MODULE_ID_WELFARE;
}

//获取结束退出顺序
int ModuleWelfare::GetFinalizeOrder()
{
	return MODULE_ID_WELFARE;
}

//初始化
bool ModuleWelfare::Initialize()
{

	

	return true;
}

//结束退出
void ModuleWelfare::Finalize()
{

}


//毫秒级Tick回调
void ModuleWelfare::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleWelfare::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleWelfare::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleWelfare::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleWelfare::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleWelfare::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleWelfare::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleWelfare::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleWelfare::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleWelfare::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

