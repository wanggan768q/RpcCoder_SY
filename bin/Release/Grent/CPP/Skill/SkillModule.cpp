/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleSkill.cpp
* Author:       甘业清
* Description:  技能模块类，包含以下内容
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

#include "SkillModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleSkill);

//技能模块实现类构造函数
ModuleSkill::ModuleSkill()
{

	g_pPacketMgr->registerHandle(	RPC_CODE_SKILL_SKILLINFO_REQUEST, &ModuleSkill::RpcSkillInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SKILL_SKILLINFO_REQUEST, new Some_Factory<SkillRpcSkillInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST, &ModuleSkill::RpcUpdateSkillInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SKILL_UPDATESKILLINFO_REQUEST, new Some_Factory<SkillRpcUpdateSkillInfoAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST, &ModuleSkill::RpcLevelUpSkillPos);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SKILL_LEVELUPSKILLPOS_REQUEST, new Some_Factory<SkillRpcLevelUpSkillPosAsk>());
	g_pPacketMgr->registerHandle(	RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST, &ModuleSkill::RpcSkillLevelInfo);
	g_pPacketMgr->registerPacketFacotry(	RPC_CODE_SKILL_SKILLLEVELINFO_REQUEST, new Some_Factory<SkillRpcSkillLevelInfoAsk>());


	
	m_mapSyncDataVersionName[1] = "SyncDataSkillV1";
		
}

//技能模块实现类析构函数
ModuleSkill::~ModuleSkill()
{

}


//获取模块ID
UINT8 ModuleSkill::GetModuleId()
{
	return MODULE_ID_SKILL;
}

//获取模块名字
TStr ModuleSkill::GetModuleName()
{
	return "Skill";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleSkill::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleSkill::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleSkill::GetInitializeOrder()
{
	return MODULE_ID_SKILL;
}

//获取结束退出顺序
int ModuleSkill::GetFinalizeOrder()
{
	return MODULE_ID_SKILL;
}

//初始化
bool ModuleSkill::Initialize()
{

	

	return true;
}

//结束退出
void ModuleSkill::Finalize()
{

}


//毫秒级Tick回调
void ModuleSkill::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleSkill::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleSkill::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleSkill::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleSkill::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleSkill::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleSkill::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleSkill::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleSkill::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleSkill::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

