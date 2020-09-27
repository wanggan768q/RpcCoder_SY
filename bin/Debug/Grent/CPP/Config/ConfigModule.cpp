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
#include "AccumulateSignInCfg.h"
#include "ActionEventCfg.h"
#include "ActivityRewardCfg.h"
#include "ActivitySevenDayTargetDetailsCfg.h"
#include "ActivitySpecLoginCfg.h"
#include "ActivityCfg.h"
#include "AllianceBossCfg.h"
#include "AllianceBuildingCfg.h"
#include "AllianceFlagCfg.h"
#include "AllianceLimitsCfg.h"
#include "AllianceNameColorCfg.h"
#include "AlliancePositionCfg.h"
#include "AllianceSkillBaseCfg.h"
#include "AllianceSkillLevelCfg.h"
#include "AllianceTowerCfg.h"
#include "AllianceWelfareCfg.h"
#include "ArenaBuffCfg.h"
#include "ArenaMatchCfg.h"
#include "ArenaRankRewardCfg.h"
#include "ArenaRewardCfg.h"
#include "AttackCfg.h"
#include "AttributeCategoryCfg.h"
#include "AttributeFormatConfigCfg.h"
#include "AuctionCfg.h"
#include "BackpackUnlockCfg.h"
#include "BattlefieldCfg.h"
#include "BubbleChatCfg.h"
#include "BuffConflictConfigCfg.h"
#include "BuffrRenovateCfg.h"
#include "BuffCfg.h"
#include "BuinessMainCfg.h"
#include "BuinessCfg.h"
#include "BulletCfg.h"
#include "BusinessNPCCfg.h"
#include "BusinessQuestCfg.h"
#include "CameraConfigCfg.h"
#include "CampBattleCfg.h"
#include "CampCfg.h"
#include "CatchMountsItemCfg.h"
#include "CatchMountsCfg.h"
#include "CgAnimationCfg.h"
#include "ChapterQuestUiCfg.h"
#include "CharacterConfigCfg.h"
#include "CharacterCustomizeCfg.h"
#include "ChatConsumptionCfg.h"
#include "ChatmenuCfg.h"
#include "ClientQuestTargetTypeCfg.h"
#include "ContractEventCfg.h"
#include "ContractPrivilegeCfg.h"
#include "ContractTaskCfg.h"
#include "CreateRoleCfg.h"
#include "CreatureCombatBasicCfg.h"
#include "CreatureCombatCoeCfg.h"
#include "CreatureCombatCorCfg.h"
#include "CreatureDummyCfg.h"
#include "CreatureHideCfg.h"
#include "CreatureIntroduceUiCfg.h"
#include "CreatureSpawnCfg.h"
#include "CreatureTemperConfigCfg.h"
#include "CreatureCfg.h"
#include "CurrencyCfg.h"
#include "DamageFloatCfg.h"
#include "DropRateCfg.h"
#include "DropWeightCfg.h"
#include "DungeonListCfg.h"
#include "DungeonCfg.h"
#include "EmblemBoxCfg.h"
#include "EmblemMakeCfg.h"
#include "EmblemPromotionCfg.h"
#include "EmblemProtoCfg.h"
#include "EmblemRecastCfg.h"
#include "EquipBuildIndexCfg.h"
#include "EquipBuildCfg.h"
#include "EquipDisplayCfg.h"
#include "EquipExtraAttributeCfg.h"
#include "EquipInheritCfg.h"
#include "EquipProtoCfg.h"
#include "EquipRefineCfg.h"
#include "EquipResonanceCfg.h"
#include "EquipSlotEnhanceCfg.h"
#include "EquipSlotRankupCfg.h"
#include "EquipSuitCfg.h"
#include "EssentialSuitCfg.h"
#include "EventAreaCfg.h"
#include "EventObjCfg.h"
#include "ExperienceCfg.h"
#include "ExpressionActionCfg.h"
#include "FactionCfg.h"
#include "FSAppearanceCfg.h"
#include "FSBodyCfg.h"
#include "FSCameraCfg.h"
#include "FSColorCfg.h"
#include "FSExportCfg.h"
#include "FSFirstMenuCfg.h"
#include "FSFourMenuCfg.h"
#include "FSFourUICfg.h"
#include "FSHairCfg.h"
#include "FSPictureCfg.h"
#include "FSPrefabCfg.h"
#include "FSRobotCfg.h"
#include "FSRoleCfg.h"
#include "FSSecondMenuCfg.h"
#include "FSThirdMenuCfg.h"
#include "FunctionTutorialCfg.h"
#include "GeminsertCfg.h"
#include "GemsuitCfg.h"
#include "GemtypeCfg.h"
#include "GemCfg.h"
#include "GiftCfg.h"
#include "GlobalCfg.h"
#include "GMCodeCfg.h"
#include "HeadFlagCfg.h"
#include "HeadHealthresCfg.h"
#include "HeadUpInfoCfg.h"
#include "HuntCfg.h"
#include "ItemDissolveFilterCfg.h"
#include "ItemOptionalCfg.h"
#include "ItemProtoCfg.h"
#include "ItemSourceCfg.h"
#include "ItemTypeCfg.h"
#include "KillChainNameCfg.h"
#include "LayerCfg.h"
#include "LeaderBoardIndexCfg.h"
#include "LeaderBoardCfg.h"
#include "LevelUpBonusCfg.h"
#include "LevelCfg.h"
#include "LifeCollectAreaCfg.h"
#include "LifeCollectorCfg.h"
#include "LifeCollectCfg.h"
#include "LifeMakeCfg.h"
#include "LifeSkillLvCfg.h"
#include "LifeSkillRelevanCfg.h"
#include "LifeSkillCfg.h"
#include "LimitCfg.h"
#include "LinkStringCfg.h"
#include "MagicFlexibleCfg.h"
#include "MagicMotionCfg.h"
#include "MailCfg.h"
#include "MainAttributeCfg.h"
#include "MatchCfg.h"
#include "MercenaryCfg.h"
#include "MiniMapConfigCfg.h"
#include "MirrorCfg.h"
#include "MixInfoCfg.h"
#include "MonthlySignInCfg.h"
#include "MountCloseCfg.h"
#include "MountExpCfg.h"
#include "MountIdCfg.h"
#include "MountSkillTypeCfg.h"
#include "MountSkillCfg.h"
#include "MountSystemCfg.h"
#include "MountCfg.h"
#include "NameFirstNameCfg.h"
#include "NameLastNameCfg.h"
#include "OnlineBattleCfg.h"
#include "OnlineBonusCfg.h"
#include "OperationActivitiesAllServerAimsTimesCfg.h"
#include "OperationActivitiesExchangeDetailsCfg.h"
#include "OperationActivitiesFestalBOSSAwardCfg.h"
#include "OperationActivitiesFestalBOSStimeCfg.h"
#include "OperationActivitiesFestalBossCfg.h"
#include "OperationActivitiesTimelimitDropPropDeleteCfg.h"
#include "OperationActivitiesTimelimitDropCfg.h"
#include "OperationActivitiesCfg.h"
#include "OperationCfg.h"
#include "PerformanceCfg.h"
#include "PetAttributeFormatConfigCfg.h"
#include "PetAttributeCfg.h"
#include "PetCaptureDropCfg.h"
#include "PetCaptureShowCfg.h"
#include "PetCaptureWayCfg.h"
#include "PetCaptureCfg.h"
#include "PetFeedCfg.h"
#include "PetIndexCfg.h"
#include "PetProtoCfg.h"
#include "PetRankCfg.h"
#include "PetReleaseCfg.h"
#include "PetSkillCfg.h"
#include "PetTalentCfg.h"
#include "PotionCfg.h"
#include "ProfessionComboPointCfg.h"
#include "ProfessionCfg.h"
#include "PveRobotAttributeCfg.h"
#include "PveRobotConfigCfg.h"
#include "PvpRobotAttributeCfg.h"
#include "PvpRobotConfigCfg.h"
#include "QteUiCfg.h"
#include "QteCfg.h"
#include "QuestGroupCfg.h"
#include "QuestRandomCfg.h"
#include "QuestCfg.h"
#include "RechargeCfg.h"
#include "RedPointCfg.h"
#include "RewardRecoveryCfg.h"
#include "RoleAttributeCfg.h"
#include "RoleCfg.h"
#include "RuneCfg.h"
#include "SceneCfg.h"
#include "ServerListCfg.h"
#include "ServerScriptCfg.h"
#include "ShapeshiftCfg.h"
#include "ShopitemsCfg.h"
#include "ShoplistCfg.h"
#include "ShoutCfg.h"
#include "SingleTowerOverallCfg.h"
#include "SingleTowerCfg.h"
#include "SkillPrepareCfg.h"
#include "SkillRageCfg.h"
#include "SkillSlotUpgradeCfg.h"
#include "SkillUpgradeCfg.h"
#include "SkillValueModCfg.h"
#include "SkillCfg.h"
#include "SoulBuildIndexCfg.h"
#include "SoulBuildCfg.h"
#include "SoulInlayAttributesCfg.h"
#include "SoulPropertyCfg.h"
#include "SoulSuitCfg.h"
#include "SoulTroughCfg.h"
#include "SoulUpgradeCfg.h"
#include "StarBattleMapCfg.h"
#include "StarBattleCfg.h"
#include "StringBuffCfg.h"
#include "StringChapterCfg.h"
#include "StringChatmenuCfg.h"
#include "StringCreatureCfg.h"
#include "StringErrorCfg.h"
#include "StringGuideCfg.h"
#include "StringHintCfg.h"
#include "StringItemCfg.h"
#include "StringMiniMapCfg.h"
#include "StringMiscCfg.h"
#include "StringNameFemaleNameCfg.h"
#include "StringNameLastNameCfg.h"
#include "StringNameMaleNameCfg.h"
#include "StringNoticeCfg.h"
#include "StringQuestCfg.h"
#include "StringRobotNameMalenameCfg.h"
#include "StringSkillCfg.h"
#include "StringUiCfg.h"
#include "SummonMonsterCfg.h"
#include "SystemPreviewCfg.h"
#include "SystemUnlockCfg.h"
#include "TalentDirectionCfg.h"
#include "TalentSkillLevelCfg.h"
#include "TalentSkillCfg.h"
#include "TalentCfg.h"
#include "TargetCfg.h"
#include "TeamMatchingGroupCfg.h"
#include "TeamMatchingCfg.h"
#include "TeleportTargetCfg.h"
#include "TimeLineCfg.h"
#include "TitleListCfg.h"
#include "TrapCfg.h"
#include "TreasureLensCfg.h"
#include "TreasureLevelCfg.h"
#include "TreasureMapCfg.h"
#include "TreasureCfg.h"
#include "UICategoryCfg.h"
#include "ValueCfg.h"
#include "VechicleCfg.h"
#include "WarningCfg.h"
#include "WayPointCfg.h"
#include "WeatherCfg.h"
#include "WorldBossCfg.h"
#include "WorldEliteCfg.h"
#include "WorldEventCfg.h"
#include "WorldLevelCfg.h"
#include "ZoneTextCfg.h"



//初始化
bool ModuleConfig::Initialize()
{

	if(!AccumulateSignInTable::Instance().Load()) return false;
	if(!ActionEventTable::Instance().Load()) return false;
	if(!ActivityRewardTable::Instance().Load()) return false;
	if(!ActivitySevenDayTargetDetailsTable::Instance().Load()) return false;
	if(!ActivitySpecLoginTable::Instance().Load()) return false;
	if(!ActivityTable::Instance().Load()) return false;
	if(!AllianceBossTable::Instance().Load()) return false;
	if(!AllianceBuildingTable::Instance().Load()) return false;
	if(!AllianceFlagTable::Instance().Load()) return false;
	if(!AllianceLimitsTable::Instance().Load()) return false;
	if(!AllianceNameColorTable::Instance().Load()) return false;
	if(!AlliancePositionTable::Instance().Load()) return false;
	if(!AllianceSkillBaseTable::Instance().Load()) return false;
	if(!AllianceSkillLevelTable::Instance().Load()) return false;
	if(!AllianceTowerTable::Instance().Load()) return false;
	if(!AllianceWelfareTable::Instance().Load()) return false;
	if(!ArenaBuffTable::Instance().Load()) return false;
	if(!ArenaMatchTable::Instance().Load()) return false;
	if(!ArenaRankRewardTable::Instance().Load()) return false;
	if(!ArenaRewardTable::Instance().Load()) return false;
	if(!AttackTable::Instance().Load()) return false;
	if(!AttributeCategoryTable::Instance().Load()) return false;
	if(!AttributeFormatConfigTable::Instance().Load()) return false;
	if(!AuctionTable::Instance().Load()) return false;
	if(!BackpackUnlockTable::Instance().Load()) return false;
	if(!BattlefieldTable::Instance().Load()) return false;
	if(!BubbleChatTable::Instance().Load()) return false;
	if(!BuffConflictConfigTable::Instance().Load()) return false;
	if(!BuffrRenovateTable::Instance().Load()) return false;
	if(!BuffTable::Instance().Load()) return false;
	if(!BuinessMainTable::Instance().Load()) return false;
	if(!BuinessTable::Instance().Load()) return false;
	if(!BulletTable::Instance().Load()) return false;
	if(!BusinessNPCTable::Instance().Load()) return false;
	if(!BusinessQuestTable::Instance().Load()) return false;
	if(!CameraConfigTable::Instance().Load()) return false;
	if(!CampBattleTable::Instance().Load()) return false;
	if(!CampTable::Instance().Load()) return false;
	if(!CatchMountsItemTable::Instance().Load()) return false;
	if(!CatchMountsTable::Instance().Load()) return false;
	if(!CgAnimationTable::Instance().Load()) return false;
	if(!ChapterQuestUiTable::Instance().Load()) return false;
	if(!CharacterConfigTable::Instance().Load()) return false;
	if(!CharacterCustomizeTable::Instance().Load()) return false;
	if(!ChatConsumptionTable::Instance().Load()) return false;
	if(!ChatmenuTable::Instance().Load()) return false;
	if(!ClientQuestTargetTypeTable::Instance().Load()) return false;
	if(!ContractEventTable::Instance().Load()) return false;
	if(!ContractPrivilegeTable::Instance().Load()) return false;
	if(!ContractTaskTable::Instance().Load()) return false;
	if(!CreateRoleTable::Instance().Load()) return false;
	if(!CreatureCombatBasicTable::Instance().Load()) return false;
	if(!CreatureCombatCoeTable::Instance().Load()) return false;
	if(!CreatureCombatCorTable::Instance().Load()) return false;
	if(!CreatureDummyTable::Instance().Load()) return false;
	if(!CreatureHideTable::Instance().Load()) return false;
	if(!CreatureIntroduceUiTable::Instance().Load()) return false;
	if(!CreatureSpawnTable::Instance().Load()) return false;
	if(!CreatureTemperConfigTable::Instance().Load()) return false;
	if(!CreatureTable::Instance().Load()) return false;
	if(!CurrencyTable::Instance().Load()) return false;
	if(!DamageFloatTable::Instance().Load()) return false;
	if(!DropRateTable::Instance().Load()) return false;
	if(!DropWeightTable::Instance().Load()) return false;
	if(!DungeonListTable::Instance().Load()) return false;
	if(!DungeonTable::Instance().Load()) return false;
	if(!EmblemBoxTable::Instance().Load()) return false;
	if(!EmblemMakeTable::Instance().Load()) return false;
	if(!EmblemPromotionTable::Instance().Load()) return false;
	if(!EmblemProtoTable::Instance().Load()) return false;
	if(!EmblemRecastTable::Instance().Load()) return false;
	if(!EquipBuildIndexTable::Instance().Load()) return false;
	if(!EquipBuildTable::Instance().Load()) return false;
	if(!EquipDisplayTable::Instance().Load()) return false;
	if(!EquipExtraAttributeTable::Instance().Load()) return false;
	if(!EquipInheritTable::Instance().Load()) return false;
	if(!EquipProtoTable::Instance().Load()) return false;
	if(!EquipRefineTable::Instance().Load()) return false;
	if(!EquipResonanceTable::Instance().Load()) return false;
	if(!EquipSlotEnhanceTable::Instance().Load()) return false;
	if(!EquipSlotRankupTable::Instance().Load()) return false;
	if(!EquipSuitTable::Instance().Load()) return false;
	if(!EssentialSuitTable::Instance().Load()) return false;
	if(!EventAreaTable::Instance().Load()) return false;
	if(!EventObjTable::Instance().Load()) return false;
	if(!ExperienceTable::Instance().Load()) return false;
	if(!ExpressionActionTable::Instance().Load()) return false;
	if(!FactionTable::Instance().Load()) return false;
	if(!FSAppearanceTable::Instance().Load()) return false;
	if(!FSBodyTable::Instance().Load()) return false;
	if(!FSCameraTable::Instance().Load()) return false;
	if(!FSColorTable::Instance().Load()) return false;
	if(!FSExportTable::Instance().Load()) return false;
	if(!FSFirstMenuTable::Instance().Load()) return false;
	if(!FSFourMenuTable::Instance().Load()) return false;
	if(!FSFourUITable::Instance().Load()) return false;
	if(!FSHairTable::Instance().Load()) return false;
	if(!FSPictureTable::Instance().Load()) return false;
	if(!FSPrefabTable::Instance().Load()) return false;
	if(!FSRobotTable::Instance().Load()) return false;
	if(!FSRoleTable::Instance().Load()) return false;
	if(!FSSecondMenuTable::Instance().Load()) return false;
	if(!FSThirdMenuTable::Instance().Load()) return false;
	if(!FunctionTutorialTable::Instance().Load()) return false;
	if(!GeminsertTable::Instance().Load()) return false;
	if(!GemsuitTable::Instance().Load()) return false;
	if(!GemtypeTable::Instance().Load()) return false;
	if(!GemTable::Instance().Load()) return false;
	if(!GiftTable::Instance().Load()) return false;
	if(!GlobalTable::Instance().Load()) return false;
	if(!GMCodeTable::Instance().Load()) return false;
	if(!HeadFlagTable::Instance().Load()) return false;
	if(!HeadHealthresTable::Instance().Load()) return false;
	if(!HeadUpInfoTable::Instance().Load()) return false;
	if(!HuntTable::Instance().Load()) return false;
	if(!ItemDissolveFilterTable::Instance().Load()) return false;
	if(!ItemOptionalTable::Instance().Load()) return false;
	if(!ItemProtoTable::Instance().Load()) return false;
	if(!ItemSourceTable::Instance().Load()) return false;
	if(!ItemTypeTable::Instance().Load()) return false;
	if(!KillChainNameTable::Instance().Load()) return false;
	if(!LayerTable::Instance().Load()) return false;
	if(!LeaderBoardIndexTable::Instance().Load()) return false;
	if(!LeaderBoardTable::Instance().Load()) return false;
	if(!LevelUpBonusTable::Instance().Load()) return false;
	if(!LevelTable::Instance().Load()) return false;
	if(!LifeCollectAreaTable::Instance().Load()) return false;
	if(!LifeCollectorTable::Instance().Load()) return false;
	if(!LifeCollectTable::Instance().Load()) return false;
	if(!LifeMakeTable::Instance().Load()) return false;
	if(!LifeSkillLvTable::Instance().Load()) return false;
	if(!LifeSkillRelevanTable::Instance().Load()) return false;
	if(!LifeSkillTable::Instance().Load()) return false;
	if(!LimitTable::Instance().Load()) return false;
	if(!LinkStringTable::Instance().Load()) return false;
	if(!MagicFlexibleTable::Instance().Load()) return false;
	if(!MagicMotionTable::Instance().Load()) return false;
	if(!MailTable::Instance().Load()) return false;
	if(!MainAttributeTable::Instance().Load()) return false;
	if(!MatchTable::Instance().Load()) return false;
	if(!MercenaryTable::Instance().Load()) return false;
	if(!MiniMapConfigTable::Instance().Load()) return false;
	if(!MirrorTable::Instance().Load()) return false;
	if(!MixInfoTable::Instance().Load()) return false;
	if(!MonthlySignInTable::Instance().Load()) return false;
	if(!MountCloseTable::Instance().Load()) return false;
	if(!MountExpTable::Instance().Load()) return false;
	if(!MountIdTable::Instance().Load()) return false;
	if(!MountSkillTypeTable::Instance().Load()) return false;
	if(!MountSkillTable::Instance().Load()) return false;
	if(!MountSystemTable::Instance().Load()) return false;
	if(!MountTable::Instance().Load()) return false;
	if(!NameFirstNameTable::Instance().Load()) return false;
	if(!NameLastNameTable::Instance().Load()) return false;
	if(!OnlineBattleTable::Instance().Load()) return false;
	if(!OnlineBonusTable::Instance().Load()) return false;
	if(!OperationActivitiesAllServerAimsTimesTable::Instance().Load()) return false;
	if(!OperationActivitiesExchangeDetailsTable::Instance().Load()) return false;
	if(!OperationActivitiesFestalBOSSAwardTable::Instance().Load()) return false;
	if(!OperationActivitiesFestalBOSStimeTable::Instance().Load()) return false;
	if(!OperationActivitiesFestalBossTable::Instance().Load()) return false;
	if(!OperationActivitiesTimelimitDropPropDeleteTable::Instance().Load()) return false;
	if(!OperationActivitiesTimelimitDropTable::Instance().Load()) return false;
	if(!OperationActivitiesTable::Instance().Load()) return false;
	if(!OperationTable::Instance().Load()) return false;
	if(!PerformanceTable::Instance().Load()) return false;
	if(!PetAttributeFormatConfigTable::Instance().Load()) return false;
	if(!PetAttributeTable::Instance().Load()) return false;
	if(!PetCaptureDropTable::Instance().Load()) return false;
	if(!PetCaptureShowTable::Instance().Load()) return false;
	if(!PetCaptureWayTable::Instance().Load()) return false;
	if(!PetCaptureTable::Instance().Load()) return false;
	if(!PetFeedTable::Instance().Load()) return false;
	if(!PetIndexTable::Instance().Load()) return false;
	if(!PetProtoTable::Instance().Load()) return false;
	if(!PetRankTable::Instance().Load()) return false;
	if(!PetReleaseTable::Instance().Load()) return false;
	if(!PetSkillTable::Instance().Load()) return false;
	if(!PetTalentTable::Instance().Load()) return false;
	if(!PotionTable::Instance().Load()) return false;
	if(!ProfessionComboPointTable::Instance().Load()) return false;
	if(!ProfessionTable::Instance().Load()) return false;
	if(!PveRobotAttributeTable::Instance().Load()) return false;
	if(!PveRobotConfigTable::Instance().Load()) return false;
	if(!PvpRobotAttributeTable::Instance().Load()) return false;
	if(!PvpRobotConfigTable::Instance().Load()) return false;
	if(!QteUiTable::Instance().Load()) return false;
	if(!QteTable::Instance().Load()) return false;
	if(!QuestGroupTable::Instance().Load()) return false;
	if(!QuestRandomTable::Instance().Load()) return false;
	if(!QuestTable::Instance().Load()) return false;
	if(!RechargeTable::Instance().Load()) return false;
	if(!RedPointTable::Instance().Load()) return false;
	if(!RewardRecoveryTable::Instance().Load()) return false;
	if(!RoleAttributeTable::Instance().Load()) return false;
	if(!RoleTable::Instance().Load()) return false;
	if(!RuneTable::Instance().Load()) return false;
	if(!SceneTable::Instance().Load()) return false;
	if(!ServerListTable::Instance().Load()) return false;
	if(!ServerScriptTable::Instance().Load()) return false;
	if(!ShapeshiftTable::Instance().Load()) return false;
	if(!ShopitemsTable::Instance().Load()) return false;
	if(!ShoplistTable::Instance().Load()) return false;
	if(!ShoutTable::Instance().Load()) return false;
	if(!SingleTowerOverallTable::Instance().Load()) return false;
	if(!SingleTowerTable::Instance().Load()) return false;
	if(!SkillPrepareTable::Instance().Load()) return false;
	if(!SkillRageTable::Instance().Load()) return false;
	if(!SkillSlotUpgradeTable::Instance().Load()) return false;
	if(!SkillUpgradeTable::Instance().Load()) return false;
	if(!SkillValueModTable::Instance().Load()) return false;
	if(!SkillTable::Instance().Load()) return false;
	if(!SoulBuildIndexTable::Instance().Load()) return false;
	if(!SoulBuildTable::Instance().Load()) return false;
	if(!SoulInlayAttributesTable::Instance().Load()) return false;
	if(!SoulPropertyTable::Instance().Load()) return false;
	if(!SoulSuitTable::Instance().Load()) return false;
	if(!SoulTroughTable::Instance().Load()) return false;
	if(!SoulUpgradeTable::Instance().Load()) return false;
	if(!StarBattleMapTable::Instance().Load()) return false;
	if(!StarBattleTable::Instance().Load()) return false;
	if(!StringBuffTable::Instance().Load()) return false;
	if(!StringChapterTable::Instance().Load()) return false;
	if(!StringChatmenuTable::Instance().Load()) return false;
	if(!StringCreatureTable::Instance().Load()) return false;
	if(!StringErrorTable::Instance().Load()) return false;
	if(!StringGuideTable::Instance().Load()) return false;
	if(!StringHintTable::Instance().Load()) return false;
	if(!StringItemTable::Instance().Load()) return false;
	if(!StringMiniMapTable::Instance().Load()) return false;
	if(!StringMiscTable::Instance().Load()) return false;
	if(!StringNameFemaleNameTable::Instance().Load()) return false;
	if(!StringNameLastNameTable::Instance().Load()) return false;
	if(!StringNameMaleNameTable::Instance().Load()) return false;
	if(!StringNoticeTable::Instance().Load()) return false;
	if(!StringQuestTable::Instance().Load()) return false;
	if(!StringRobotNameMalenameTable::Instance().Load()) return false;
	if(!StringSkillTable::Instance().Load()) return false;
	if(!StringUiTable::Instance().Load()) return false;
	if(!SummonMonsterTable::Instance().Load()) return false;
	if(!SystemPreviewTable::Instance().Load()) return false;
	if(!SystemUnlockTable::Instance().Load()) return false;
	if(!TalentDirectionTable::Instance().Load()) return false;
	if(!TalentSkillLevelTable::Instance().Load()) return false;
	if(!TalentSkillTable::Instance().Load()) return false;
	if(!TalentTable::Instance().Load()) return false;
	if(!TargetTable::Instance().Load()) return false;
	if(!TeamMatchingGroupTable::Instance().Load()) return false;
	if(!TeamMatchingTable::Instance().Load()) return false;
	if(!TeleportTargetTable::Instance().Load()) return false;
	if(!TimeLineTable::Instance().Load()) return false;
	if(!TitleListTable::Instance().Load()) return false;
	if(!TrapTable::Instance().Load()) return false;
	if(!TreasureLensTable::Instance().Load()) return false;
	if(!TreasureLevelTable::Instance().Load()) return false;
	if(!TreasureMapTable::Instance().Load()) return false;
	if(!TreasureTable::Instance().Load()) return false;
	if(!UICategoryTable::Instance().Load()) return false;
	if(!ValueTable::Instance().Load()) return false;
	if(!VechicleTable::Instance().Load()) return false;
	if(!WarningTable::Instance().Load()) return false;
	if(!WayPointTable::Instance().Load()) return false;
	if(!WeatherTable::Instance().Load()) return false;
	if(!WorldBossTable::Instance().Load()) return false;
	if(!WorldEliteTable::Instance().Load()) return false;
	if(!WorldEventTable::Instance().Load()) return false;
	if(!WorldLevelTable::Instance().Load()) return false;
	if(!ZoneTextTable::Instance().Load()) return false;
	
	return OnLoad();
}

bool ModuleConfig::Reinitialize()
{
		if(!AccumulateSignInTable::Instance().ReLoad()) return false;
	if(!ActionEventTable::Instance().ReLoad()) return false;
	if(!ActivityRewardTable::Instance().ReLoad()) return false;
	if(!ActivitySevenDayTargetDetailsTable::Instance().ReLoad()) return false;
	if(!ActivitySpecLoginTable::Instance().ReLoad()) return false;
	if(!ActivityTable::Instance().ReLoad()) return false;
	if(!AllianceBossTable::Instance().ReLoad()) return false;
	if(!AllianceBuildingTable::Instance().ReLoad()) return false;
	if(!AllianceFlagTable::Instance().ReLoad()) return false;
	if(!AllianceLimitsTable::Instance().ReLoad()) return false;
	if(!AllianceNameColorTable::Instance().ReLoad()) return false;
	if(!AlliancePositionTable::Instance().ReLoad()) return false;
	if(!AllianceSkillBaseTable::Instance().ReLoad()) return false;
	if(!AllianceSkillLevelTable::Instance().ReLoad()) return false;
	if(!AllianceTowerTable::Instance().ReLoad()) return false;
	if(!AllianceWelfareTable::Instance().ReLoad()) return false;
	if(!ArenaBuffTable::Instance().ReLoad()) return false;
	if(!ArenaMatchTable::Instance().ReLoad()) return false;
	if(!ArenaRankRewardTable::Instance().ReLoad()) return false;
	if(!ArenaRewardTable::Instance().ReLoad()) return false;
	if(!AttackTable::Instance().ReLoad()) return false;
	if(!AttributeCategoryTable::Instance().ReLoad()) return false;
	if(!AttributeFormatConfigTable::Instance().ReLoad()) return false;
	if(!AuctionTable::Instance().ReLoad()) return false;
	if(!BackpackUnlockTable::Instance().ReLoad()) return false;
	if(!BattlefieldTable::Instance().ReLoad()) return false;
	if(!BubbleChatTable::Instance().ReLoad()) return false;
	if(!BuffConflictConfigTable::Instance().ReLoad()) return false;
	if(!BuffrRenovateTable::Instance().ReLoad()) return false;
	if(!BuffTable::Instance().ReLoad()) return false;
	if(!BuinessMainTable::Instance().ReLoad()) return false;
	if(!BuinessTable::Instance().ReLoad()) return false;
	if(!BulletTable::Instance().ReLoad()) return false;
	if(!BusinessNPCTable::Instance().ReLoad()) return false;
	if(!BusinessQuestTable::Instance().ReLoad()) return false;
	if(!CameraConfigTable::Instance().ReLoad()) return false;
	if(!CampBattleTable::Instance().ReLoad()) return false;
	if(!CampTable::Instance().ReLoad()) return false;
	if(!CatchMountsItemTable::Instance().ReLoad()) return false;
	if(!CatchMountsTable::Instance().ReLoad()) return false;
	if(!CgAnimationTable::Instance().ReLoad()) return false;
	if(!ChapterQuestUiTable::Instance().ReLoad()) return false;
	if(!CharacterConfigTable::Instance().ReLoad()) return false;
	if(!CharacterCustomizeTable::Instance().ReLoad()) return false;
	if(!ChatConsumptionTable::Instance().ReLoad()) return false;
	if(!ChatmenuTable::Instance().ReLoad()) return false;
	if(!ClientQuestTargetTypeTable::Instance().ReLoad()) return false;
	if(!ContractEventTable::Instance().ReLoad()) return false;
	if(!ContractPrivilegeTable::Instance().ReLoad()) return false;
	if(!ContractTaskTable::Instance().ReLoad()) return false;
	if(!CreateRoleTable::Instance().ReLoad()) return false;
	if(!CreatureCombatBasicTable::Instance().ReLoad()) return false;
	if(!CreatureCombatCoeTable::Instance().ReLoad()) return false;
	if(!CreatureCombatCorTable::Instance().ReLoad()) return false;
	if(!CreatureDummyTable::Instance().ReLoad()) return false;
	if(!CreatureHideTable::Instance().ReLoad()) return false;
	if(!CreatureIntroduceUiTable::Instance().ReLoad()) return false;
	if(!CreatureSpawnTable::Instance().ReLoad()) return false;
	if(!CreatureTemperConfigTable::Instance().ReLoad()) return false;
	if(!CreatureTable::Instance().ReLoad()) return false;
	if(!CurrencyTable::Instance().ReLoad()) return false;
	if(!DamageFloatTable::Instance().ReLoad()) return false;
	if(!DropRateTable::Instance().ReLoad()) return false;
	if(!DropWeightTable::Instance().ReLoad()) return false;
	if(!DungeonListTable::Instance().ReLoad()) return false;
	if(!DungeonTable::Instance().ReLoad()) return false;
	if(!EmblemBoxTable::Instance().ReLoad()) return false;
	if(!EmblemMakeTable::Instance().ReLoad()) return false;
	if(!EmblemPromotionTable::Instance().ReLoad()) return false;
	if(!EmblemProtoTable::Instance().ReLoad()) return false;
	if(!EmblemRecastTable::Instance().ReLoad()) return false;
	if(!EquipBuildIndexTable::Instance().ReLoad()) return false;
	if(!EquipBuildTable::Instance().ReLoad()) return false;
	if(!EquipDisplayTable::Instance().ReLoad()) return false;
	if(!EquipExtraAttributeTable::Instance().ReLoad()) return false;
	if(!EquipInheritTable::Instance().ReLoad()) return false;
	if(!EquipProtoTable::Instance().ReLoad()) return false;
	if(!EquipRefineTable::Instance().ReLoad()) return false;
	if(!EquipResonanceTable::Instance().ReLoad()) return false;
	if(!EquipSlotEnhanceTable::Instance().ReLoad()) return false;
	if(!EquipSlotRankupTable::Instance().ReLoad()) return false;
	if(!EquipSuitTable::Instance().ReLoad()) return false;
	if(!EssentialSuitTable::Instance().ReLoad()) return false;
	if(!EventAreaTable::Instance().ReLoad()) return false;
	if(!EventObjTable::Instance().ReLoad()) return false;
	if(!ExperienceTable::Instance().ReLoad()) return false;
	if(!ExpressionActionTable::Instance().ReLoad()) return false;
	if(!FactionTable::Instance().ReLoad()) return false;
	if(!FSAppearanceTable::Instance().ReLoad()) return false;
	if(!FSBodyTable::Instance().ReLoad()) return false;
	if(!FSCameraTable::Instance().ReLoad()) return false;
	if(!FSColorTable::Instance().ReLoad()) return false;
	if(!FSExportTable::Instance().ReLoad()) return false;
	if(!FSFirstMenuTable::Instance().ReLoad()) return false;
	if(!FSFourMenuTable::Instance().ReLoad()) return false;
	if(!FSFourUITable::Instance().ReLoad()) return false;
	if(!FSHairTable::Instance().ReLoad()) return false;
	if(!FSPictureTable::Instance().ReLoad()) return false;
	if(!FSPrefabTable::Instance().ReLoad()) return false;
	if(!FSRobotTable::Instance().ReLoad()) return false;
	if(!FSRoleTable::Instance().ReLoad()) return false;
	if(!FSSecondMenuTable::Instance().ReLoad()) return false;
	if(!FSThirdMenuTable::Instance().ReLoad()) return false;
	if(!FunctionTutorialTable::Instance().ReLoad()) return false;
	if(!GeminsertTable::Instance().ReLoad()) return false;
	if(!GemsuitTable::Instance().ReLoad()) return false;
	if(!GemtypeTable::Instance().ReLoad()) return false;
	if(!GemTable::Instance().ReLoad()) return false;
	if(!GiftTable::Instance().ReLoad()) return false;
	if(!GlobalTable::Instance().ReLoad()) return false;
	if(!GMCodeTable::Instance().ReLoad()) return false;
	if(!HeadFlagTable::Instance().ReLoad()) return false;
	if(!HeadHealthresTable::Instance().ReLoad()) return false;
	if(!HeadUpInfoTable::Instance().ReLoad()) return false;
	if(!HuntTable::Instance().ReLoad()) return false;
	if(!ItemDissolveFilterTable::Instance().ReLoad()) return false;
	if(!ItemOptionalTable::Instance().ReLoad()) return false;
	if(!ItemProtoTable::Instance().ReLoad()) return false;
	if(!ItemSourceTable::Instance().ReLoad()) return false;
	if(!ItemTypeTable::Instance().ReLoad()) return false;
	if(!KillChainNameTable::Instance().ReLoad()) return false;
	if(!LayerTable::Instance().ReLoad()) return false;
	if(!LeaderBoardIndexTable::Instance().ReLoad()) return false;
	if(!LeaderBoardTable::Instance().ReLoad()) return false;
	if(!LevelUpBonusTable::Instance().ReLoad()) return false;
	if(!LevelTable::Instance().ReLoad()) return false;
	if(!LifeCollectAreaTable::Instance().ReLoad()) return false;
	if(!LifeCollectorTable::Instance().ReLoad()) return false;
	if(!LifeCollectTable::Instance().ReLoad()) return false;
	if(!LifeMakeTable::Instance().ReLoad()) return false;
	if(!LifeSkillLvTable::Instance().ReLoad()) return false;
	if(!LifeSkillRelevanTable::Instance().ReLoad()) return false;
	if(!LifeSkillTable::Instance().ReLoad()) return false;
	if(!LimitTable::Instance().ReLoad()) return false;
	if(!LinkStringTable::Instance().ReLoad()) return false;
	if(!MagicFlexibleTable::Instance().ReLoad()) return false;
	if(!MagicMotionTable::Instance().ReLoad()) return false;
	if(!MailTable::Instance().ReLoad()) return false;
	if(!MainAttributeTable::Instance().ReLoad()) return false;
	if(!MatchTable::Instance().ReLoad()) return false;
	if(!MercenaryTable::Instance().ReLoad()) return false;
	if(!MiniMapConfigTable::Instance().ReLoad()) return false;
	if(!MirrorTable::Instance().ReLoad()) return false;
	if(!MixInfoTable::Instance().ReLoad()) return false;
	if(!MonthlySignInTable::Instance().ReLoad()) return false;
	if(!MountCloseTable::Instance().ReLoad()) return false;
	if(!MountExpTable::Instance().ReLoad()) return false;
	if(!MountIdTable::Instance().ReLoad()) return false;
	if(!MountSkillTypeTable::Instance().ReLoad()) return false;
	if(!MountSkillTable::Instance().ReLoad()) return false;
	if(!MountSystemTable::Instance().ReLoad()) return false;
	if(!MountTable::Instance().ReLoad()) return false;
	if(!NameFirstNameTable::Instance().ReLoad()) return false;
	if(!NameLastNameTable::Instance().ReLoad()) return false;
	if(!OnlineBattleTable::Instance().ReLoad()) return false;
	if(!OnlineBonusTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesAllServerAimsTimesTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesExchangeDetailsTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesFestalBOSSAwardTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesFestalBOSStimeTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesFestalBossTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesTimelimitDropPropDeleteTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesTimelimitDropTable::Instance().ReLoad()) return false;
	if(!OperationActivitiesTable::Instance().ReLoad()) return false;
	if(!OperationTable::Instance().ReLoad()) return false;
	if(!PerformanceTable::Instance().ReLoad()) return false;
	if(!PetAttributeFormatConfigTable::Instance().ReLoad()) return false;
	if(!PetAttributeTable::Instance().ReLoad()) return false;
	if(!PetCaptureDropTable::Instance().ReLoad()) return false;
	if(!PetCaptureShowTable::Instance().ReLoad()) return false;
	if(!PetCaptureWayTable::Instance().ReLoad()) return false;
	if(!PetCaptureTable::Instance().ReLoad()) return false;
	if(!PetFeedTable::Instance().ReLoad()) return false;
	if(!PetIndexTable::Instance().ReLoad()) return false;
	if(!PetProtoTable::Instance().ReLoad()) return false;
	if(!PetRankTable::Instance().ReLoad()) return false;
	if(!PetReleaseTable::Instance().ReLoad()) return false;
	if(!PetSkillTable::Instance().ReLoad()) return false;
	if(!PetTalentTable::Instance().ReLoad()) return false;
	if(!PotionTable::Instance().ReLoad()) return false;
	if(!ProfessionComboPointTable::Instance().ReLoad()) return false;
	if(!ProfessionTable::Instance().ReLoad()) return false;
	if(!PveRobotAttributeTable::Instance().ReLoad()) return false;
	if(!PveRobotConfigTable::Instance().ReLoad()) return false;
	if(!PvpRobotAttributeTable::Instance().ReLoad()) return false;
	if(!PvpRobotConfigTable::Instance().ReLoad()) return false;
	if(!QteUiTable::Instance().ReLoad()) return false;
	if(!QteTable::Instance().ReLoad()) return false;
	if(!QuestGroupTable::Instance().ReLoad()) return false;
	if(!QuestRandomTable::Instance().ReLoad()) return false;
	if(!QuestTable::Instance().ReLoad()) return false;
	if(!RechargeTable::Instance().ReLoad()) return false;
	if(!RedPointTable::Instance().ReLoad()) return false;
	if(!RewardRecoveryTable::Instance().ReLoad()) return false;
	if(!RoleAttributeTable::Instance().ReLoad()) return false;
	if(!RoleTable::Instance().ReLoad()) return false;
	if(!RuneTable::Instance().ReLoad()) return false;
	if(!SceneTable::Instance().ReLoad()) return false;
	if(!ServerListTable::Instance().ReLoad()) return false;
	if(!ServerScriptTable::Instance().ReLoad()) return false;
	if(!ShapeshiftTable::Instance().ReLoad()) return false;
	if(!ShopitemsTable::Instance().ReLoad()) return false;
	if(!ShoplistTable::Instance().ReLoad()) return false;
	if(!ShoutTable::Instance().ReLoad()) return false;
	if(!SingleTowerOverallTable::Instance().ReLoad()) return false;
	if(!SingleTowerTable::Instance().ReLoad()) return false;
	if(!SkillPrepareTable::Instance().ReLoad()) return false;
	if(!SkillRageTable::Instance().ReLoad()) return false;
	if(!SkillSlotUpgradeTable::Instance().ReLoad()) return false;
	if(!SkillUpgradeTable::Instance().ReLoad()) return false;
	if(!SkillValueModTable::Instance().ReLoad()) return false;
	if(!SkillTable::Instance().ReLoad()) return false;
	if(!SoulBuildIndexTable::Instance().ReLoad()) return false;
	if(!SoulBuildTable::Instance().ReLoad()) return false;
	if(!SoulInlayAttributesTable::Instance().ReLoad()) return false;
	if(!SoulPropertyTable::Instance().ReLoad()) return false;
	if(!SoulSuitTable::Instance().ReLoad()) return false;
	if(!SoulTroughTable::Instance().ReLoad()) return false;
	if(!SoulUpgradeTable::Instance().ReLoad()) return false;
	if(!StarBattleMapTable::Instance().ReLoad()) return false;
	if(!StarBattleTable::Instance().ReLoad()) return false;
	if(!StringBuffTable::Instance().ReLoad()) return false;
	if(!StringChapterTable::Instance().ReLoad()) return false;
	if(!StringChatmenuTable::Instance().ReLoad()) return false;
	if(!StringCreatureTable::Instance().ReLoad()) return false;
	if(!StringErrorTable::Instance().ReLoad()) return false;
	if(!StringGuideTable::Instance().ReLoad()) return false;
	if(!StringHintTable::Instance().ReLoad()) return false;
	if(!StringItemTable::Instance().ReLoad()) return false;
	if(!StringMiniMapTable::Instance().ReLoad()) return false;
	if(!StringMiscTable::Instance().ReLoad()) return false;
	if(!StringNameFemaleNameTable::Instance().ReLoad()) return false;
	if(!StringNameLastNameTable::Instance().ReLoad()) return false;
	if(!StringNameMaleNameTable::Instance().ReLoad()) return false;
	if(!StringNoticeTable::Instance().ReLoad()) return false;
	if(!StringQuestTable::Instance().ReLoad()) return false;
	if(!StringRobotNameMalenameTable::Instance().ReLoad()) return false;
	if(!StringSkillTable::Instance().ReLoad()) return false;
	if(!StringUiTable::Instance().ReLoad()) return false;
	if(!SummonMonsterTable::Instance().ReLoad()) return false;
	if(!SystemPreviewTable::Instance().ReLoad()) return false;
	if(!SystemUnlockTable::Instance().ReLoad()) return false;
	if(!TalentDirectionTable::Instance().ReLoad()) return false;
	if(!TalentSkillLevelTable::Instance().ReLoad()) return false;
	if(!TalentSkillTable::Instance().ReLoad()) return false;
	if(!TalentTable::Instance().ReLoad()) return false;
	if(!TargetTable::Instance().ReLoad()) return false;
	if(!TeamMatchingGroupTable::Instance().ReLoad()) return false;
	if(!TeamMatchingTable::Instance().ReLoad()) return false;
	if(!TeleportTargetTable::Instance().ReLoad()) return false;
	if(!TimeLineTable::Instance().ReLoad()) return false;
	if(!TitleListTable::Instance().ReLoad()) return false;
	if(!TrapTable::Instance().ReLoad()) return false;
	if(!TreasureLensTable::Instance().ReLoad()) return false;
	if(!TreasureLevelTable::Instance().ReLoad()) return false;
	if(!TreasureMapTable::Instance().ReLoad()) return false;
	if(!TreasureTable::Instance().ReLoad()) return false;
	if(!UICategoryTable::Instance().ReLoad()) return false;
	if(!ValueTable::Instance().ReLoad()) return false;
	if(!VechicleTable::Instance().ReLoad()) return false;
	if(!WarningTable::Instance().ReLoad()) return false;
	if(!WayPointTable::Instance().ReLoad()) return false;
	if(!WeatherTable::Instance().ReLoad()) return false;
	if(!WorldBossTable::Instance().ReLoad()) return false;
	if(!WorldEliteTable::Instance().ReLoad()) return false;
	if(!WorldEventTable::Instance().ReLoad()) return false;
	if(!WorldLevelTable::Instance().ReLoad()) return false;
	if(!ZoneTextTable::Instance().ReLoad()) return false;

	return OnLoad();
}
