/*gxb********************************************************************************************
* Copyright (C), 2011-2025, Ambition. Co., Ltd.
* FileName:     ModuleConfig.cpp
* Author:       郭晓波
* Description:  Config类，包含以下内容
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

#include "ConfigModule.h"
#include "BASE.h"
#include "MsgIdMgr.h"


IMPLEMENT_INSTANCE(ModuleConfig);

//Config实现类构造函数
ModuleConfig::ModuleConfig()
{



}

//Config实现类析构函数
ModuleConfig::~ModuleConfig()
{

}


//获取模块ID
UINT8 ModuleConfig::GetModuleId()
{
	return MODULE_ID_CONFIG;
}

//获取模块名字
TStr ModuleConfig::GetModuleName()
{
	return "Config";
}

//获取模块同步(保存)数据版本及类名
map<INT32,TStr> ModuleConfig::GetModuleDataVersionName()
{

	return m_mapSyncDataVersionName;
}

//模块数据保存类型
SavedDataTypeE	ModuleConfig::GetSavedDataType()
{
	return SAVE_ITEM_DATA;
}


//获取初始化顺序
int	ModuleConfig::GetInitializeOrder()
{
	return MODULE_ID_CONFIG;
}

//获取结束退出顺序
int ModuleConfig::GetFinalizeOrder()
{
	return MODULE_ID_CONFIG;
}

//初始化
bool ModuleConfig::Initialize()
{

	BaoShiTable::Instance().Load();
	BuffTable::Instance().Load();
	CreateRoleTable::Instance().Load();
	CreatureCombatBasicTable::Instance().Load();
	CreatureCombatCoeTable::Instance().Load();
	CreatureDummyTable::Instance().Load();
	CreatureSpawnTable::Instance().Load();
	CreatureTable::Instance().Load();
	ItemProtoTable::Instance().Load();
	RoleTable::Instance().Load();
	SceneTable::Instance().Load();
	SkillTable::Instance().Load();
	StringCreatureTable::Instance().Load();
	StringUiTable::Instance().Load();
	ValueTable::Instance().Load();
	WayPointTable::Instance().Load();
	

	return true;
}

//结束退出
void ModuleConfig::Finalize()
{

}


//毫秒级Tick回调
void ModuleConfig::OnTick( INT64 currentMiliSecond )
{

}

//秒级Tick回调
void ModuleConfig::OnSecondTick( time_t currentSecond )
{

}

//分钟改变回调
void ModuleConfig::OnMinuteChange( time_t currentSecond)
{

}

//小时改变回调
void ModuleConfig::OnHourChange( time_t currentSecond )
{

}

//天改变回调
void ModuleConfig::OnDayChange( time_t currentSecond )
{

}

//创建用户回调
void ModuleConfig::OnUserCreate( INT64 userId, const TStr& userName )
{

}

//用户上线回调
void ModuleConfig::OnUserOnline( INT64 userId, time_t lastLogoutTime )
{

}

//用户下线回调
void ModuleConfig::OnUserOffline( INT64 userId )
{

}

//是否要同步数据到客户端
bool ModuleConfig::NotSyncToClient( UINT16 usSyncId )
{

	return false;
}

//同步数据修改后回调
void ModuleConfig::NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex)
{

}

