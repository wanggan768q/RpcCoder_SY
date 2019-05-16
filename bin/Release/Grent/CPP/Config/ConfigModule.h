/********************************************************************************************
* Copyright (C), 2011-2025, AGAN Tech. Co., Ltd.
* FileName:     ModuleConfig.h
* Author:       甘业清
* Description:  Config类，包含以下内容
*               ★模块基本信息函数
*               ★初始化结束回调函数
*               ★时间相当回调函数
*               ★用户创建上下线回调函数
*               ★模块数据修改及同步回调函数
*               ★服务器后台RPC函数
*               ★客户端RPC函数
* Version:      1.0
* History:
* <author>  <time>   <version >   <desc>
* 
********************************************************************************************/

#ifndef __MODULE_CONFIG_H
#define __MODULE_CONFIG_H


#include "ModuleBase.h"
#include "ConfigRpcWraper.h"

#include "AccumulateSignInCfg.h"
#include "ActivityRewardCfg.h"
#include "ActivitySevenDayTargetDetailsCfg.h"
#include "ActivitySpecLoginCfg.h"
#include "ActivityCfg.h"
#include "AllianceBuildingCfg.h"
#include "AllianceFlagCfg.h"
#include "AllianceLimitsCfg.h"
#include "ArenaRankRewardCfg.h"
#include "ArenaRewardCfg.h"
#include "AttackCfg.h"
#include "AttributeFormatConfigCfg.h"
#include "AuctionCfg.h"
#include "BattlefieldCfg.h"
#include "BuffConflictConfigCfg.h"
#include "BuffCfg.h"
#include "BuinessMainCfg.h"
#include "BuinessCfg.h"
#include "BulletCfg.h"
#include "CameraConfigCfg.h"
#include "CampBattleCfg.h"
#include "CgAnimationCfg.h"
#include "CharacterConfigCfg.h"
#include "CharacterCustomizeCfg.h"
#include "ChatConsumptionCfg.h"
#include "ChatmenuCfg.h"
#include "CreateRoleCfg.h"
#include "CreatureCombatBasicCfg.h"
#include "CreatureCombatCoeCfg.h"
#include "CreatureDummyCfg.h"
#include "CreatureHideCfg.h"
#include "CreatureSpawnCfg.h"
#include "CreatureTemperConfigCfg.h"
#include "CreatureCfg.h"
#include "CurrencyCfg.h"
#include "DamageFloatCfg.h"
#include "DropRateCfg.h"
#include "DropWeightCfg.h"
#include "DungeonListCfg.h"
#include "DungeonCfg.h"
#include "EquipBuildIndexCfg.h"
#include "EquipBuildCfg.h"
#include "EquipExtraAttributeCfg.h"
#include "EquipInheritCfg.h"
#include "EquipProtoCfg.h"
#include "EquipResonanceCfg.h"
#include "EquipSlotEnhanceCfg.h"
#include "EquipSlotRankupCfg.h"
#include "EquipSuitCfg.h"
#include "EventAreaCfg.h"
#include "EventObjCfg.h"
#include "ExperienceCfg.h"
#include "ExpressionActionCfg.h"
#include "FactionCfg.h"
#include "FriendGroupNanmeCfg.h"
#include "FunctionTutorialCfg.h"
#include "GeminsertCfg.h"
#include "GemCfg.h"
#include "GiftCfg.h"
#include "GlobalCfg.h"
#include "GMCodeCfg.h"
#include "HeadUpInfoCfg.h"
#include "HuntCfg.h"
#include "ItemProtoCfg.h"
#include "ItemSourceCfg.h"
#include "ItemTypeCfg.h"
#include "LeaderBoardIndexCfg.h"
#include "LeaderBoardCfg.h"
#include "LevelUpBonusCfg.h"
#include "LevelCfg.h"
#include "LimitCfg.h"
#include "MailCfg.h"
#include "MatchCfg.h"
#include "MercenaryCfg.h"
#include "MirrorCfg.h"
#include "MixInfoCfg.h"
#include "MonthlySignInCfg.h"
#include "MountCfg.h"
#include "NameFirstNameCfg.h"
#include "NameLastNameCfg.h"
#include "OnlineBonusCfg.h"
#include "OperationCfg.h"
#include "PetAttributeFormatConfigCfg.h"
#include "PetAttributeCfg.h"
#include "PetCaptureShowCfg.h"
#include "PetCaptureCfg.h"
#include "PetIndexCfg.h"
#include "PetProtoCfg.h"
#include "PetRankCfg.h"
#include "PetSkillCfg.h"
#include "PetTalentCfg.h"
#include "PotionCfg.h"
#include "ProfessionComboPointCfg.h"
#include "ProfessionCfg.h"
#include "QteUiCfg.h"
#include "QteCfg.h"
#include "QuestGroupCfg.h"
#include "QuestRandomCfg.h"
#include "QuestCfg.h"
#include "RechargeCfg.h"
#include "RoleAttributeCfg.h"
#include "RoleCfg.h"
#include "RuneCfg.h"
#include "SceneCfg.h"
#include "ServerListCfg.h"
#include "ServerScriptCfg.h"
#include "ShopitemsCfg.h"
#include "ShoplistCfg.h"
#include "SingleTowerCfg.h"
#include "SkillRageCfg.h"
#include "SkillSlotUpgradeCfg.h"
#include "SkillCfg.h"
#include "StarBattleCfg.h"
#include "StringBuffCfg.h"
#include "StringChatmenuCfg.h"
#include "StringCreatureCfg.h"
#include "StringErrorCfg.h"
#include "StringGuideCfg.h"
#include "StringHintCfg.h"
#include "StringItemCfg.h"
#include "StringMiscCfg.h"
#include "StringNoticeCfg.h"
#include "StringQuestCfg.h"
#include "StringSkillCfg.h"
#include "StringUiCfg.h"
#include "SummonMonsterCfg.h"
#include "SystemPreviewCfg.h"
#include "TeamMatchingGroupCfg.h"
#include "TeamMatchingCfg.h"
#include "TeleportTargetCfg.h"
#include "TrapCfg.h"
#include "TreasureLensCfg.h"
#include "TreasureLevelCfg.h"
#include "TreasureMapCfg.h"
#include "TreasureCfg.h"
#include "UICategoryCfg.h"
#include "ValueCfg.h"
#include "VechicleCfg.h"
#include "WayPointCfg.h"
#include "WorldBossCfg.h"
#include "WorldLevelCfg.h"



//Config实现类
class ModuleConfig : public ModuleBase
{
	DECLARE_INSTANCE(ModuleConfig);
public:
	friend class			ModuleMgr;

public:
	//Config实现类构造函数
	ModuleConfig();
	
	//Config实现类析构函数
	virtual					~ModuleConfig();

	//获取模块ID
	virtual	UINT8			GetModuleId();
	
	//获取模块名字
	virtual	TStr			GetModuleName();
	
	//获取模块同步(保存)数据版本及类名
	virtual map<INT32,TStr>	GetModuleDataVersionName();
	
	//模块数据保存类型
	virtual SavedDataTypeE	GetSavedDataType();

	//获取初始化顺序
	virtual int				GetInitializeOrder();
	
	//获取结束退出顺序
	virtual int				GetFinalizeOrder();
	
	//初始化
	virtual bool			Initialize();
	
	//结束退出
	virtual void			Finalize();

	//毫秒级Tick回调
	virtual void			OnTick( INT64 currentMiliSecond );
	
	//秒级Tick回调
	virtual void			OnSecondTick( time_t currentSecond );
	
	//分钟改变回调
	virtual void			OnMinuteChange( time_t currentSecond);
	
	//小时改变回调
	virtual void			OnHourChange( time_t currentSecond );
	
	//天改变回调
	virtual void			OnDayChange( time_t currentSecond );

	//创建用户回调
	virtual void			OnUserCreate( INT64 userId, const TStr& userName );
	
	//用户上线回调
	virtual void			OnUserOnline( INT64 userId, time_t lastLogoutTime );
	
	//用户下线回调
	virtual void			OnUserOffline( INT64 userId );

	//是否要同步数据到客户端
	virtual bool			NotSyncToClient( UINT16 usSyncId );
	
	//同步数据修改后回调
	virtual void			NotifySyncValueChanged(INT64 Key,UINT16 usSyncId, int nIndex=-1);

public:


private:
	 map<INT32,TStr>		m_mapSyncDataVersionName;
};

#endif