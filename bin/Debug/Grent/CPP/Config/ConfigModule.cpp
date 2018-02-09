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
#


//初始化
bool ModuleConfig::Initialize()
{

	AttributeFormatConfigTable::Instance().Load();
	BaoShiTable::Instance().Load();
	BuffConflictConfigTable::Instance().Load();
	BuffTable::Instance().Load();
	CameraConfigTable::Instance().Load();
	CharacterConfigTable::Instance().Load();
	CreateRoleTable::Instance().Load();
	CreatureCombatBasicTable::Instance().Load();
	CreatureCombatCoeTable::Instance().Load();
	CreatureDummyTable::Instance().Load();
	CreatureSpawnTable::Instance().Load();
	CreatureTemperConfigTable::Instance().Load();
	CreatureTable::Instance().Load();
	DungeonTable::Instance().Load();
	GlobalTable::Instance().Load();
	ItemProtoTable::Instance().Load();
	RoleTable::Instance().Load();
	SceneTable::Instance().Load();
	ServerListTable::Instance().Load();
	ServerScriptTable::Instance().Load();
	SkillTable::Instance().Load();
	StringCreatureTable::Instance().Load();
	StringUiTable::Instance().Load();
	SummonMonsterTable::Instance().Load();
	ValueTable::Instance().Load();
	WayPointTable::Instance().Load();
	

	return true;
}
