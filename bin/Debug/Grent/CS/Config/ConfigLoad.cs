using UnityEngine;
using System.Collections;

public class ConfigLoad : MonoBehaviour {

	private string textContent;

	public IEnumerator LoadConfig () {

		yield return StartCoroutine(LoadData("AccumulateSignIn.csv"));
		AccumulateSignInTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActionEvent.csv"));
		ActionEventTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivityReward.csv"));
		ActivityRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivitySevenDayTargetDetails.csv"));
		ActivitySevenDayTargetDetailsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivitySpecLogin.csv"));
		ActivitySpecLoginTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Activity.csv"));
		ActivityTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceBoss.csv"));
		AllianceBossTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceBuilding.csv"));
		AllianceBuildingTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceFlag.csv"));
		AllianceFlagTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceLimits.csv"));
		AllianceLimitsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceNameColor.csv"));
		AllianceNameColorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AlliancePosition.csv"));
		AlliancePositionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceSkillBase.csv"));
		AllianceSkillBaseTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceSkillLevel.csv"));
		AllianceSkillLevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceTower.csv"));
		AllianceTowerTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceWelfare.csv"));
		AllianceWelfareTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaBuff.csv"));
		ArenaBuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaMatch.csv"));
		ArenaMatchTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaRankReward.csv"));
		ArenaRankRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaReward.csv"));
		ArenaRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Attack.csv"));
		AttackTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AttributeCategory.csv"));
		AttributeCategoryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AttributeFormatConfig.csv"));
		AttributeFormatConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Auction.csv"));
		AuctionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BackpackUnlock.csv"));
		BackpackUnlockTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Battlefield.csv"));
		BattlefieldTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BubbleChat.csv"));
		BubbleChatTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuffConflictConfig.csv"));
		BuffConflictConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuffrRenovate.csv"));
		BuffrRenovateTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buff.csv"));
		BuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuinessMain.csv"));
		BuinessMainTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buiness.csv"));
		BuinessTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Bullet.csv"));
		BulletTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BusinessNPC.csv"));
		BusinessNPCTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BusinessQuest.csv"));
		BusinessQuestTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CameraConfig.csv"));
		CameraConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CampBattle.csv"));
		CampBattleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Camp.csv"));
		CampTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CatchMountsItem.csv"));
		CatchMountsItemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CatchMounts.csv"));
		CatchMountsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CgAnimation.csv"));
		CgAnimationTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ChapterQuestUi.csv"));
		ChapterQuestUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CharacterConfig.csv"));
		CharacterConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CharacterCustomize.csv"));
		CharacterCustomizeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ChatConsumption.csv"));
		ChatConsumptionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Chatmenu.csv"));
		ChatmenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ClientQuestTargetType.csv"));
		ClientQuestTargetTypeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ContractEvent.csv"));
		ContractEventTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ContractPrivilege.csv"));
		ContractPrivilegeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ContractTask.csv"));
		ContractTaskTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreateRole.csv"));
		CreateRoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatBasic.csv"));
		CreatureCombatBasicTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatCoe.csv"));
		CreatureCombatCoeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatCor.csv"));
		CreatureCombatCorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureDummy.csv"));
		CreatureDummyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureHide.csv"));
		CreatureHideTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureIntroduceUi.csv"));
		CreatureIntroduceUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureSpawn.csv"));
		CreatureSpawnTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureTemperConfig.csv"));
		CreatureTemperConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Creature.csv"));
		CreatureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Currency.csv"));
		CurrencyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("DamageFloat.csv"));
		DamageFloatTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("DropRate.csv"));
		DropRateTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("DropWeight.csv"));
		DropWeightTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("DungeonList.csv"));
		DungeonListTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Dungeon.csv"));
		DungeonTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EmblemBox.csv"));
		EmblemBoxTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EmblemMake.csv"));
		EmblemMakeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EmblemPromotion.csv"));
		EmblemPromotionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EmblemProto.csv"));
		EmblemProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EmblemRecast.csv"));
		EmblemRecastTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipBuildIndex.csv"));
		EquipBuildIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipBuild.csv"));
		EquipBuildTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipDisplay.csv"));
		EquipDisplayTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipExtraAttribute.csv"));
		EquipExtraAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipInherit.csv"));
		EquipInheritTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipProto.csv"));
		EquipProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipRefine.csv"));
		EquipRefineTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipResonance.csv"));
		EquipResonanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSlotEnhance.csv"));
		EquipSlotEnhanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSlotRankup.csv"));
		EquipSlotRankupTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSuit.csv"));
		EquipSuitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EssentialSuit.csv"));
		EssentialSuitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EventArea.csv"));
		EventAreaTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EventObj.csv"));
		EventObjTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Experience.csv"));
		ExperienceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ExpressionAction.csv"));
		ExpressionActionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Faction.csv"));
		FactionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSAppearance.csv"));
		FSAppearanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSBody.csv"));
		FSBodyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSCamera.csv"));
		FSCameraTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSColor.csv"));
		FSColorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSExport.csv"));
		FSExportTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSFirstMenu.csv"));
		FSFirstMenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSFourMenu.csv"));
		FSFourMenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSFourUI.csv"));
		FSFourUITable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSHair.csv"));
		FSHairTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSPicture.csv"));
		FSPictureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSPrefab.csv"));
		FSPrefabTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSRobot.csv"));
		FSRobotTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSRole.csv"));
		FSRoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSSecondMenu.csv"));
		FSSecondMenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FSThirdMenu.csv"));
		FSThirdMenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FunctionTutorial.csv"));
		FunctionTutorialTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Geminsert.csv"));
		GeminsertTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gemsuit.csv"));
		GemsuitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gemtype.csv"));
		GemtypeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gem.csv"));
		GemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gift.csv"));
		GiftTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Global.csv"));
		GlobalTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("GMCode.csv"));
		GMCodeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeadFlag.csv"));
		HeadFlagTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeadHealthres.csv"));
		HeadHealthresTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeadUpInfo.csv"));
		HeadUpInfoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Hunt.csv"));
		HuntTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemDissolveFilter.csv"));
		ItemDissolveFilterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemOptional.csv"));
		ItemOptionalTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemProto.csv"));
		ItemProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemSource.csv"));
		ItemSourceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemType.csv"));
		ItemTypeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("KillChainName.csv"));
		KillChainNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Layer.csv"));
		LayerTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LeaderBoardIndex.csv"));
		LeaderBoardIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LeaderBoard.csv"));
		LeaderBoardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LevelUpBonus.csv"));
		LevelUpBonusTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Level.csv"));
		LevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeCollectArea.csv"));
		LifeCollectAreaTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeCollector.csv"));
		LifeCollectorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeCollect.csv"));
		LifeCollectTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeMake.csv"));
		LifeMakeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeSkillLv.csv"));
		LifeSkillLvTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeSkillRelevan.csv"));
		LifeSkillRelevanTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LifeSkill.csv"));
		LifeSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Limit.csv"));
		LimitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LinkString.csv"));
		LinkStringTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MagicFlexible.csv"));
		MagicFlexibleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MagicMotion.csv"));
		MagicMotionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mail.csv"));
		MailTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MainAttribute.csv"));
		MainAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Match.csv"));
		MatchTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mercenary.csv"));
		MercenaryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MiniMapConfig.csv"));
		MiniMapConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mirror.csv"));
		MirrorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MixInfo.csv"));
		MixInfoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MonthlySignIn.csv"));
		MonthlySignInTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountClose.csv"));
		MountCloseTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountExp.csv"));
		MountExpTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountId.csv"));
		MountIdTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountSkillType.csv"));
		MountSkillTypeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountSkill.csv"));
		MountSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MountSystem.csv"));
		MountSystemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mount.csv"));
		MountTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("NameFirstName.csv"));
		NameFirstNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("NameLastName.csv"));
		NameLastNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OnlineBattle.csv"));
		OnlineBattleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OnlineBonus.csv"));
		OnlineBonusTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesAllServerAimsTimes.csv"));
		OperationActivitiesAllServerAimsTimesTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesExchangeDetails.csv"));
		OperationActivitiesExchangeDetailsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesFestalBOSSAward.csv"));
		OperationActivitiesFestalBOSSAwardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesFestalBOSStime.csv"));
		OperationActivitiesFestalBOSStimeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesFestalBoss.csv"));
		OperationActivitiesFestalBossTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesTimelimitDropPropDelete.csv"));
		OperationActivitiesTimelimitDropPropDeleteTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivitiesTimelimitDrop.csv"));
		OperationActivitiesTimelimitDropTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OperationActivities.csv"));
		OperationActivitiesTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Operation.csv"));
		OperationTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Performance.csv"));
		PerformanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetAttributeFormatConfig.csv"));
		PetAttributeFormatConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetAttribute.csv"));
		PetAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCaptureDrop.csv"));
		PetCaptureDropTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCaptureShow.csv"));
		PetCaptureShowTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCaptureWay.csv"));
		PetCaptureWayTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCapture.csv"));
		PetCaptureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetFeed.csv"));
		PetFeedTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetIndex.csv"));
		PetIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetProto.csv"));
		PetProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetRank.csv"));
		PetRankTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetRelease.csv"));
		PetReleaseTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetSkill.csv"));
		PetSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetTalent.csv"));
		PetTalentTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Potion.csv"));
		PotionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ProfessionComboPoint.csv"));
		ProfessionComboPointTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Profession.csv"));
		ProfessionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PveRobotAttribute.csv"));
		PveRobotAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PveRobotConfig.csv"));
		PveRobotConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PvpRobotAttribute.csv"));
		PvpRobotAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PvpRobotConfig.csv"));
		PvpRobotConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("QteUi.csv"));
		QteUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Qte.csv"));
		QteTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("QuestGroup.csv"));
		QuestGroupTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("QuestRandom.csv"));
		QuestRandomTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Quest.csv"));
		QuestTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Recharge.csv"));
		RechargeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("RedPoint.csv"));
		RedPointTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("RewardRecovery.csv"));
		RewardRecoveryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("RoleAttribute.csv"));
		RoleAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Role.csv"));
		RoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Rune.csv"));
		RuneTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Scene.csv"));
		SceneTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ServerList.csv"));
		ServerListTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ServerScript.csv"));
		ServerScriptTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shapeshift.csv"));
		ShapeshiftTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shopitems.csv"));
		ShopitemsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shoplist.csv"));
		ShoplistTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shout.csv"));
		ShoutTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SingleTowerOverall.csv"));
		SingleTowerOverallTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SingleTower.csv"));
		SingleTowerTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillPrepare.csv"));
		SkillPrepareTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillRage.csv"));
		SkillRageTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillSlotUpgrade.csv"));
		SkillSlotUpgradeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillUpgrade.csv"));
		SkillUpgradeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillValueMod.csv"));
		SkillValueModTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Skill.csv"));
		SkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulBuildIndex.csv"));
		SoulBuildIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulBuild.csv"));
		SoulBuildTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulInlayAttributes.csv"));
		SoulInlayAttributesTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulProperty.csv"));
		SoulPropertyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulSuit.csv"));
		SoulSuitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulTrough.csv"));
		SoulTroughTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SoulUpgrade.csv"));
		SoulUpgradeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StarBattleMap.csv"));
		StarBattleMapTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StarBattle.csv"));
		StarBattleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringBuff.csv"));
		StringBuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringChapter.csv"));
		StringChapterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringChatmenu.csv"));
		StringChatmenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringCreature.csv"));
		StringCreatureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringError.csv"));
		StringErrorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringGuide.csv"));
		StringGuideTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringHint.csv"));
		StringHintTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringItem.csv"));
		StringItemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringMiniMap.csv"));
		StringMiniMapTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringMisc.csv"));
		StringMiscTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringNameFemaleName.csv"));
		StringNameFemaleNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringNameLastName.csv"));
		StringNameLastNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringNameMaleName.csv"));
		StringNameMaleNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringNotice.csv"));
		StringNoticeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringQuest.csv"));
		StringQuestTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringRobotNameMalename.csv"));
		StringRobotNameMalenameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringSkill.csv"));
		StringSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringUi.csv"));
		StringUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SummonMonster.csv"));
		SummonMonsterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SystemPreview.csv"));
		SystemPreviewTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SystemUnlock.csv"));
		SystemUnlockTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TalentDirection.csv"));
		TalentDirectionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TalentSkillLevel.csv"));
		TalentSkillLevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TalentSkill.csv"));
		TalentSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Talent.csv"));
		TalentTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Target.csv"));
		TargetTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeamMatchingGroup.csv"));
		TeamMatchingGroupTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeamMatching.csv"));
		TeamMatchingTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeleportTarget.csv"));
		TeleportTargetTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TimeLine.csv"));
		TimeLineTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TitleList.csv"));
		TitleListTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Trap.csv"));
		TrapTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TreasureLens.csv"));
		TreasureLensTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TreasureLevel.csv"));
		TreasureLevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TreasureMap.csv"));
		TreasureMapTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Treasure.csv"));
		TreasureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("UICategory.csv"));
		UICategoryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Value.csv"));
		ValueTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Vechicle.csv"));
		VechicleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Warning.csv"));
		WarningTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WayPoint.csv"));
		WayPointTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Weather.csv"));
		WeatherTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldBoss.csv"));
		WorldBossTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldElite.csv"));
		WorldEliteTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldEvent.csv"));
		WorldEventTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldLevel.csv"));
		WorldLevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ZoneText.csv"));
		ZoneTextTable.Instance.LoadCsv(textContent);



		yield return true;
	}

    IEnumerator LoadData (string name) {

		string path = Ex.Utils.GetStreamingAssetsFilePath(name, "CSV");
	
		WWW www = new WWW(path);
		yield return www;

		textContent = www.text;
		yield return true;
	}
}
