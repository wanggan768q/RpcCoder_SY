using UnityEngine;
using System.Collections;

public class ConfigLoad : MonoBehaviour {

	private string textContent;

	public IEnumerator LoadConfig () {

		yield return StartCoroutine(LoadData("AccumulateSignIn.csv"));
		AccumulateSignInTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivityReward.csv"));
		ActivityRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivitySevenDayTargetDetails.csv"));
		ActivitySevenDayTargetDetailsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ActivitySpecLogin.csv"));
		ActivitySpecLoginTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Activity.csv"));
		ActivityTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceBuilding.csv"));
		AllianceBuildingTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceFlag.csv"));
		AllianceFlagTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AllianceLimits.csv"));
		AllianceLimitsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaRankReward.csv"));
		ArenaRankRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ArenaReward.csv"));
		ArenaRewardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Attack.csv"));
		AttackTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("AttributeFormatConfig.csv"));
		AttributeFormatConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Auction.csv"));
		AuctionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Battlefield.csv"));
		BattlefieldTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuffConflictConfig.csv"));
		BuffConflictConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buff.csv"));
		BuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuinessMain.csv"));
		BuinessMainTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buiness.csv"));
		BuinessTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Bullet.csv"));
		BulletTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CameraConfig.csv"));
		CameraConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CampBattle.csv"));
		CampBattleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CgAnimation.csv"));
		CgAnimationTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CharacterConfig.csv"));
		CharacterConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CharacterCustomize.csv"));
		CharacterCustomizeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ChatConsumption.csv"));
		ChatConsumptionTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Chatmenu.csv"));
		ChatmenuTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreateRole.csv"));
		CreateRoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatBasic.csv"));
		CreatureCombatBasicTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatCoe.csv"));
		CreatureCombatCoeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureDummy.csv"));
		CreatureDummyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureHide.csv"));
		CreatureHideTable.Instance.LoadCsv(textContent);

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

		yield return StartCoroutine(LoadData("EquipBuildIndex.csv"));
		EquipBuildIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipBuild.csv"));
		EquipBuildTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipExtraAttribute.csv"));
		EquipExtraAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipInherit.csv"));
		EquipInheritTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipProto.csv"));
		EquipProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipResonance.csv"));
		EquipResonanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSlotEnhance.csv"));
		EquipSlotEnhanceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSlotRankup.csv"));
		EquipSlotRankupTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("EquipSuit.csv"));
		EquipSuitTable.Instance.LoadCsv(textContent);

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

		yield return StartCoroutine(LoadData("FriendGroupNanme.csv"));
		FriendGroupNanmeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("FunctionTutorial.csv"));
		FunctionTutorialTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Geminsert.csv"));
		GeminsertTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gem.csv"));
		GemTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Gift.csv"));
		GiftTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Global.csv"));
		GlobalTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("GMCode.csv"));
		GMCodeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("HeadUpInfo.csv"));
		HeadUpInfoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Hunt.csv"));
		HuntTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemProto.csv"));
		ItemProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemSource.csv"));
		ItemSourceTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemType.csv"));
		ItemTypeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LeaderBoardIndex.csv"));
		LeaderBoardIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LeaderBoard.csv"));
		LeaderBoardTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("LevelUpBonus.csv"));
		LevelUpBonusTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Level.csv"));
		LevelTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Limit.csv"));
		LimitTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mail.csv"));
		MailTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Match.csv"));
		MatchTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mercenary.csv"));
		MercenaryTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mirror.csv"));
		MirrorTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MixInfo.csv"));
		MixInfoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("MonthlySignIn.csv"));
		MonthlySignInTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Mount.csv"));
		MountTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("NameFirstName.csv"));
		NameFirstNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("NameLastName.csv"));
		NameLastNameTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("OnlineBonus.csv"));
		OnlineBonusTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Operation.csv"));
		OperationTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetAttributeFormatConfig.csv"));
		PetAttributeFormatConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetAttribute.csv"));
		PetAttributeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCaptureShow.csv"));
		PetCaptureShowTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetCapture.csv"));
		PetCaptureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetIndex.csv"));
		PetIndexTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetProto.csv"));
		PetProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("PetRank.csv"));
		PetRankTable.Instance.LoadCsv(textContent);

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

		yield return StartCoroutine(LoadData("Shopitems.csv"));
		ShopitemsTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Shoplist.csv"));
		ShoplistTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SingleTower.csv"));
		SingleTowerTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillRage.csv"));
		SkillRageTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SkillSlotUpgrade.csv"));
		SkillSlotUpgradeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Skill.csv"));
		SkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StarBattle.csv"));
		StarBattleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringBuff.csv"));
		StringBuffTable.Instance.LoadCsv(textContent);

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

		yield return StartCoroutine(LoadData("StringMisc.csv"));
		StringMiscTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringNotice.csv"));
		StringNoticeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringQuest.csv"));
		StringQuestTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringSkill.csv"));
		StringSkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringUi.csv"));
		StringUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SummonMonster.csv"));
		SummonMonsterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SystemPreview.csv"));
		SystemPreviewTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeamMatchingGroup.csv"));
		TeamMatchingGroupTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeamMatching.csv"));
		TeamMatchingTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("TeleportTarget.csv"));
		TeleportTargetTable.Instance.LoadCsv(textContent);

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

		yield return StartCoroutine(LoadData("WayPoint.csv"));
		WayPointTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldBoss.csv"));
		WorldBossTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WorldLevel.csv"));
		WorldLevelTable.Instance.LoadCsv(textContent);



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
