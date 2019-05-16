/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleWG.cpp
* Author:       甘业清
* Description:  WG类，包含以下内容
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

#include "WGModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleWG);

//WG实现类构造函数
ModuleWG::ModuleWG()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMJOINTEAM_REQUEST, &ModuleWG::RpcInformJoinTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMJOINTEAM_REQUEST, new Some_Factory<WGRpcInformJoinTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMLEAVE_REQUEST, &ModuleWG::RpcInformLeave);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMLEAVE_REQUEST, new Some_Factory<WGRpcInformLeaveAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, &ModuleWG::RpcInformAppointTeamLeader);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMAPPOINTTEAMLEADER_REQUEST, new Some_Factory<WGRpcInformAppointTeamLeaderAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, &ModuleWG::RpcInformKickTeamMember);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMKICKTEAMMEMBER_REQUEST, new Some_Factory<WGRpcInformKickTeamMemberAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, &ModuleWG::RpcInformDissmissTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMDISSMISSTEAM_REQUEST, new Some_Factory<WGRpcInformDissmissTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, &ModuleWG::RpcInformApplyTeam);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMAPPLYTEAM_REQUEST, new Some_Factory<WGRpcInformApplyTeamAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, &ModuleWG::RpcAgreeTeamApplicant);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_AGREETEAMAPPLICANT_REQUEST, new Some_Factory<WGRpcAgreeTeamApplicantAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_WG_INFORMLOGIN_REQUEST, &ModuleWG::RpcInformLogin);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_WG_INFORMLOGIN_REQUEST, new Some_Factory<WGRpcInformLoginAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataWGV1";
		
}

//WG实现类析构函数
ModuleWG::~ModuleWG()
{

}


//获取模块ID
UINT8 ModuleWG::GetModuleId()
{
	return MODULE_ID_WG;
}

//获取模块名字
TStr ModuleWG::GetModuleName()
{
	return "WG";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleWG::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleWG::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleWG::GetInitializeOrder()
{
	return MODULE_ID_WG;
}

//获取结束退出顺序
int ModuleWG::GetFinalizeOrder()
{
	return MODULE_ID_WG;
}

//初始化
bool ModuleWG::Initialize()
{

	

	return true;
}

//结束退出
void ModuleWG::Finalize()
{

}


//毫秒级Tick回调
void ModuleWG::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleWG::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleWG::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleWG::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleWG::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleWG::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleWG::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleWG::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleWG::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleWG::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

