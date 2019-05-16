/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleConfig.cpp
* Author:       甘业清
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



	
	m_mapSyncDataVersionName[1] = "SyncDataConfigV1";
		
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

	AccumulateSignInTable::Instance().Load();
	ActivityRewardTable::Instance().Load();
	ActivitySevenDayTargetDetailsTable::Instance().Load();
	ActivitySpecLoginTable::Instance().Load();
	ActivityTable::Instance().Load();
	AllianceBuildingTable::Instance().Load();
	AllianceFlagTable::Instance().Load();
	AllianceLimitsTable::Instance().Load();
	ArenaRankRewardTable::Instance().Load();
	ArenaRewardTable::Instance().Load();
	AttackTable::Instance().Load();
	AttributeFormatConfigTable::Instance().Load();
	AuctionTable::Instance().Load();
	BattlefieldTable::Instance().Load();
	BuffConflictConfigTable::Instance().Load();
	BuffTable::Instance().Load();
	BuinessMainTable::Instance().Load();
	BuinessTable::Instance().Load();
	BulletTable::Instance().Load();
	CameraConfigTable::Instance().Load();
	CampBattleTable::Instance().Load();
	CgAnimationTable::Instance().Load();
	CharacterConfigTable::Instance().Load();
	CharacterCustomizeTable::Instance().Load();
	ChatConsumptionTable::Instance().Load();
	ChatmenuTable::Instance().Load();
	CreateRoleTable::Instance().Load();
	CreatureCombatBasicTable::Instance().Load();
	CreatureCombatCoeTable::Instance().Load();
	CreatureDummyTable::Instance().Load();
	CreatureHideTable::Instance().Load();
	CreatureSpawnTable::Instance().Load();
	CreatureTemperConfigTable::Instance().Load();
	CreatureTable::Instance().Load();
	CurrencyTable::Instance().Load();
	DamageFloatTable::Instance().Load();
	DropRateTable::Instance().Load();
	DropWeightTable::Instance().Load();
	DungeonListTable::Instance().Load();
	DungeonTable::Instance().Load();
	EquipBuildIndexTable::Instance().Load();
	EquipBuildTable::Instance().Load();
	EquipExtraAttributeTable::Instance().Load();
	EquipInheritTable::Instance().Load();
	EquipProtoTable::Instance().Load();
	EquipResonanceTable::Instance().Load();
	EquipSlotEnhanceTable::Instance().Load();
	EquipSlotRankupTable::Instance().Load();
	EquipSuitTable::Instance().Load();
	EventAreaTable::Instance().Load();
	EventObjTable::Instance().Load();
	ExperienceTable::Instance().Load();
	ExpressionActionTable::Instance().Load();
	FactionTable::Instance().Load();
	FriendGroupNanmeTable::Instance().Load();
	FunctionTutorialTable::Instance().Load();
	GeminsertTable::Instance().Load();
	GemTable::Instance().Load();
	GiftTable::Instance().Load();
	GlobalTable::Instance().Load();
	GMCodeTable::Instance().Load();
	HeadUpInfoTable::Instance().Load();
	HuntTable::Instance().Load();
	ItemProtoTable::Instance().Load();
	ItemSourceTable::Instance().Load();
	ItemTypeTable::Instance().Load();
	LeaderBoardIndexTable::Instance().Load();
	LeaderBoardTable::Instance().Load();
	LevelUpBonusTable::Instance().Load();
	LevelTable::Instance().Load();
	LimitTable::Instance().Load();
	MailTable::Instance().Load();
	MatchTable::Instance().Load();
	MercenaryTable::Instance().Load();
	MirrorTable::Instance().Load();
	MixInfoTable::Instance().Load();
	MonthlySignInTable::Instance().Load();
	MountTable::Instance().Load();
	NameFirstNameTable::Instance().Load();
	NameLastNameTable::Instance().Load();
	OnlineBonusTable::Instance().Load();
	OperationTable::Instance().Load();
	PetAttributeFormatConfigTable::Instance().Load();
	PetAttributeTable::Instance().Load();
	PetCaptureShowTable::Instance().Load();
	PetCaptureTable::Instance().Load();
	PetIndexTable::Instance().Load();
	PetProtoTable::Instance().Load();
	PetRankTable::Instance().Load();
	PetSkillTable::Instance().Load();
	PetTalentTable::Instance().Load();
	PotionTable::Instance().Load();
	ProfessionComboPointTable::Instance().Load();
	ProfessionTable::Instance().Load();
	QteUiTable::Instance().Load();
	QteTable::Instance().Load();
	QuestGroupTable::Instance().Load();
	QuestRandomTable::Instance().Load();
	QuestTable::Instance().Load();
	RechargeTable::Instance().Load();
	RoleAttributeTable::Instance().Load();
	RoleTable::Instance().Load();
	RuneTable::Instance().Load();
	SceneTable::Instance().Load();
	ServerListTable::Instance().Load();
	ServerScriptTable::Instance().Load();
	ShopitemsTable::Instance().Load();
	ShoplistTable::Instance().Load();
	SingleTowerTable::Instance().Load();
	SkillRageTable::Instance().Load();
	SkillSlotUpgradeTable::Instance().Load();
	SkillTable::Instance().Load();
	StarBattleTable::Instance().Load();
	StringBuffTable::Instance().Load();
	StringChatmenuTable::Instance().Load();
	StringCreatureTable::Instance().Load();
	StringErrorTable::Instance().Load();
	StringGuideTable::Instance().Load();
	StringHintTable::Instance().Load();
	StringItemTable::Instance().Load();
	StringMiscTable::Instance().Load();
	StringNoticeTable::Instance().Load();
	StringQuestTable::Instance().Load();
	StringSkillTable::Instance().Load();
	StringUiTable::Instance().Load();
	SummonMonsterTable::Instance().Load();
	SystemPreviewTable::Instance().Load();
	TeamMatchingGroupTable::Instance().Load();
	TeamMatchingTable::Instance().Load();
	TeleportTargetTable::Instance().Load();
	TrapTable::Instance().Load();
	TreasureLensTable::Instance().Load();
	TreasureLevelTable::Instance().Load();
	TreasureMapTable::Instance().Load();
	TreasureTable::Instance().Load();
	UICategoryTable::Instance().Load();
	ValueTable::Instance().Load();
	VechicleTable::Instance().Load();
	WayPointTable::Instance().Load();
	WorldBossTable::Instance().Load();
	WorldLevelTable::Instance().Load();
	

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

