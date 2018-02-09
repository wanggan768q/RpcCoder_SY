using UnityEngine;
using System.Collections;

public class ConfigLoad : MonoBehaviour {

	private string textContent;

	public IEnumerator LoadConfig () {

		yield return StartCoroutine(LoadData("AttributeFormatConfig.csv"));
		AttributeFormatConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BaoShi.csv"));
		BaoShiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("BuffConflictConfig.csv"));
		BuffConflictConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Buff.csv"));
		BuffTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CameraConfig.csv"));
		CameraConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CharacterConfig.csv"));
		CharacterConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreateRole.csv"));
		CreateRoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatBasic.csv"));
		CreatureCombatBasicTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureCombatCoe.csv"));
		CreatureCombatCoeTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureDummy.csv"));
		CreatureDummyTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureSpawn.csv"));
		CreatureSpawnTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("CreatureTemperConfig.csv"));
		CreatureTemperConfigTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Creature.csv"));
		CreatureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Dungeon.csv"));
		DungeonTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Global.csv"));
		GlobalTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ItemProto.csv"));
		ItemProtoTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Role.csv"));
		RoleTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Scene.csv"));
		SceneTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ServerList.csv"));
		ServerListTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("ServerScript.csv"));
		ServerScriptTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Skill.csv"));
		SkillTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringCreature.csv"));
		StringCreatureTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("StringUi.csv"));
		StringUiTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("SummonMonster.csv"));
		SummonMonsterTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("Value.csv"));
		ValueTable.Instance.LoadCsv(textContent);

		yield return StartCoroutine(LoadData("WayPoint.csv"));
		WayPointTable.Instance.LoadCsv(textContent);



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
