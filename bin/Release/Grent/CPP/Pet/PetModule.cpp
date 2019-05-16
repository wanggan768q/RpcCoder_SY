/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModulePet.cpp
* Author:       甘业清
* Description:  宠物模块类，包含以下内容
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

#include "PetModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModulePet);

//宠物模块实现类构造函数
ModulePet::ModulePet()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_PET_PETSYNC_REQUEST, &ModulePet::RpcPetSync);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_PETSYNC_REQUEST, new Some_Factory<PetRpcPetSyncAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_UNSUMMON_REQUEST, &ModulePet::RpcUnSummon);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_UNSUMMON_REQUEST, new Some_Factory<PetRpcUnSummonAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_LEVELUPGRADE_REQUEST, &ModulePet::RpcLevelUpgrade);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_LEVELUPGRADE_REQUEST, new Some_Factory<PetRpcLevelUpgradeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_STARUPGRADE_REQUEST, &ModulePet::RpcStarUpgrade);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_STARUPGRADE_REQUEST, new Some_Factory<PetRpcStarUpgradeAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_CHANGENAME_REQUEST, &ModulePet::RpcChangeName);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_CHANGENAME_REQUEST, new Some_Factory<PetRpcChangeNameAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_INHERIT_REQUEST, &ModulePet::RpcInherit);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_INHERIT_REQUEST, new Some_Factory<PetRpcInheritAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_SKILLINHERIT_REQUEST, &ModulePet::RpcSkillInherit);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_SKILLINHERIT_REQUEST, new Some_Factory<PetRpcSkillInheritAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_PASSIVESKILLS_REQUEST, &ModulePet::RpcPassiveSkills);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_PASSIVESKILLS_REQUEST, new Some_Factory<PetRpcPassiveSkillsAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_STUDYSKILL_REQUEST, &ModulePet::RpcStudySkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_STUDYSKILL_REQUEST, new Some_Factory<PetRpcStudySkillAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_LOCKSKILL_REQUEST, &ModulePet::RpcLockSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_LOCKSKILL_REQUEST, new Some_Factory<PetRpcLockSkillAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_PET_UNLOCKSKILL_REQUEST, &ModulePet::RpcUnLockSkill);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_PET_UNLOCKSKILL_REQUEST, new Some_Factory<PetRpcUnLockSkillAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataPetV1";
		
}

//宠物模块实现类析构函数
ModulePet::~ModulePet()
{

}


//获取模块ID
UINT8 ModulePet::GetModuleId()
{
	return MODULE_ID_PET;
}

//获取模块名字
TStr ModulePet::GetModuleName()
{
	return "Pet";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModulePet::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModulePet::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModulePet::GetInitializeOrder()
{
	return MODULE_ID_PET;
}

//获取结束退出顺序
int ModulePet::GetFinalizeOrder()
{
	return MODULE_ID_PET;
}

//初始化
bool ModulePet::Initialize()
{

	

	return true;
}

//结束退出
void ModulePet::Finalize()
{

}


//毫秒级Tick回调
void ModulePet::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModulePet::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModulePet::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModulePet::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModulePet::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModulePet::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModulePet::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModulePet::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModulePet::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModulePet::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

