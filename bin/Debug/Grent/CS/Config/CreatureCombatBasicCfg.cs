using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC战斗属性表配置数据类
public class CreatureCombatBasicElement
{
	public int id;               	//ID号	模板类*1000+等级 模板关联CreatureCombatCoe; 等级关联Creature
	public int maxhp_min;        	//生命下限	生命下限
	public int maxhp_max;        	//生命上限	生命上限
	public int physic_attack_min;	//物理攻击力下限	物理攻击力下限
	public int physic_attack_max;	//物理攻击力上限	物理攻击力上限
	public int physic_defense;   	//物理防御力	物理防御力
	public int magic_attack_min; 	//魔法攻击力下限	魔法攻击力下限
	public int magic_attack_max; 	//魔法攻击力上限	魔法攻击力上限
	public int magic_defense;    	//魔法防御力	魔法防御力
	public int hit_value;        	//命中值	命中值
	public int miss_value;       	//闪避值	闪避值
	public int critical_value;   	//暴击值	暴击值
	public int tenacity_value;   	//韧性值	韧性值
	public int penetrate_value;  	//穿透值	穿透值
	public int dodge_value;      	//格挡值	格挡值
	public float life_per_sec;   	//生命恢复速度	生命恢复速度
	public float life_steal_chance;	//生命偷取几率	生命偷取几率
	public float life_steal_rate;	//生命偷取比例	生命偷取比例
	public float thorns_chance;  	//反弹率	反弹率
	public int thorns_amount;    	//反弹值	反弹值
	public int exp;              	//经验值	经验值
	public float knockback_res;  	//击退抵抗率	击退抵抗率
	public float hit_rate;       	//命中率	命中率
	public float miss_rate;      	//闪避率	闪避率
	public float critical_rate;  	//暴击率	暴击率
	public float tenacity_rate;  	//韧性率	韧性率
	public float penetrate_rate; 	//穿透率	穿透率
	public float dodge_rate;     	//格挡率	格挡率
	public float crit_dmg;       	//暴击伤害	暴击伤害
	public float crit_res;       	//暴击抵抗	暴击抵抗
	public float stun_rate;      	//眩晕命中	眩晕命中率
	public float stun_res_rate;  	//眩晕抵抗	眩晕抵抗率
	public float immobilize_rate;	//定身命中	定身命中率
	public float immobilize_res_rate;	//定身抵抗	定身抵抗率
	public float hit_fly_rate;   	//击飞命中	击飞命中率
	public float hit_fly_res_rate;	//击飞抵抗	击飞抵抗率
	public float freeze_rate;    	//冰冻命中	冰冻命中率
	public float freeze_res_rate;	//冰冻抵抗	冰冻抵抗率
	public float purify_rate;    	//净化命中	净化命中率
	public float purify_res_rate;	//净化抵抗	净化抵抗率
	public float dispel_rate;    	//驱散命中	驱散命中率
	public float dispel_res_rate;	//驱散抵抗	驱散抵抗率
	public float slience_rate;   	//沉默命中	沉默命中率
	public float slience_res_rate;	//沉默抵抗	沉默抵抗率
	public float break_rate;     	//打断命中	打断命中率
	public float break_res_rate; 	//打断抵抗	打断抵抗率
	public float damp_heal_rate; 	//禁疗命中	禁疗命中率
	public float damp_heal_res_rate;	//禁疗抵抗	禁疗抵抗率
	public int cri_dmg_value;    	//暴击加伤值	暴击加伤值
	public int cri_res_dmg_value;	//暴击免伤值	暴击免伤值
	public float block_dmg_value;	//格挡减伤值	格挡减伤值
	public float block_dmg_rate; 	//格挡减伤率	格挡减伤率
	public float block_res_dmg_value;	//格挡破伤值	格挡破伤值
	public float block_res_dmg_rate;	//格挡破伤率	格挡破伤率
	public float to_player_dmg_rate;	//对玩家伤害倍率	对玩家伤害倍率
	public float from_player_dmg_rate;	//受到玩家伤害倍率	受到玩家伤害倍率
	public float to_monster_dmg_rate;	//对所有怪物伤害倍率	对所有怪物伤害倍率
	public float from_monster_dmg_rate;	//受到所有怪物伤害倍率	受到所有怪物伤害倍率
	public float to_boss_dmg_rate;	//对BOSS伤害倍率	对BOSS伤害倍率
	public float from_boss_dmg_rate;	//受到BOSS伤害倍率	受到BOSS伤害倍率

	public bool IsValidate = false;
	public CreatureCombatBasicElement()
	{
		id = -1;
	}
};

//NPC战斗属性表配置封装类
public class CreatureCombatBasicTable
{

	private CreatureCombatBasicTable()
	{
		m_mapElements = new Dictionary<int, CreatureCombatBasicElement>();
		m_emptyItem = new CreatureCombatBasicElement();
		m_vecAllElements = new List<CreatureCombatBasicElement>();
	}
	private Dictionary<int, CreatureCombatBasicElement> m_mapElements = null;
	private List<CreatureCombatBasicElement>	m_vecAllElements = null;
	private CreatureCombatBasicElement m_emptyItem = null;
	private static CreatureCombatBasicTable sInstance = null;

	public static CreatureCombatBasicTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureCombatBasicTable();
			return sInstance;
		}
	}

	public CreatureCombatBasicElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<CreatureCombatBasicElement> GetAllElement(Predicate<CreatureCombatBasicElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureCombatBasic.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureCombatBasic.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureCombatBasic.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 60)
		{
			Ex.Logger.Log("CreatureCombatBasic.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="maxhp_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[maxhp_min]位置不对应"); return false; }
		if(vecLine[2]!="maxhp_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[maxhp_max]位置不对应"); return false; }
		if(vecLine[3]!="physic_attack_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_attack_min]位置不对应"); return false; }
		if(vecLine[4]!="physic_attack_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_attack_max]位置不对应"); return false; }
		if(vecLine[5]!="physic_defense"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[6]!="magic_attack_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_attack_min]位置不对应"); return false; }
		if(vecLine[7]!="magic_attack_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_attack_max]位置不对应"); return false; }
		if(vecLine[8]!="magic_defense"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[9]!="hit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[10]!="miss_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[miss_value]位置不对应"); return false; }
		if(vecLine[11]!="critical_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[critical_value]位置不对应"); return false; }
		if(vecLine[12]!="tenacity_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[tenacity_value]位置不对应"); return false; }
		if(vecLine[13]!="penetrate_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[14]!="dodge_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[15]!="life_per_sec"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应"); return false; }
		if(vecLine[16]!="life_steal_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应"); return false; }
		if(vecLine[17]!="life_steal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应"); return false; }
		if(vecLine[18]!="thorns_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应"); return false; }
		if(vecLine[19]!="thorns_amount"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应"); return false; }
		if(vecLine[20]!="exp"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[21]!="knockback_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[knockback_res]位置不对应"); return false; }
		if(vecLine[22]!="hit_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_rate]位置不对应"); return false; }
		if(vecLine[23]!="miss_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[miss_rate]位置不对应"); return false; }
		if(vecLine[24]!="critical_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[critical_rate]位置不对应"); return false; }
		if(vecLine[25]!="tenacity_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[tenacity_rate]位置不对应"); return false; }
		if(vecLine[26]!="penetrate_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_rate]位置不对应"); return false; }
		if(vecLine[27]!="dodge_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_rate]位置不对应"); return false; }
		if(vecLine[28]!="crit_dmg"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应"); return false; }
		if(vecLine[29]!="crit_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_res]位置不对应"); return false; }
		if(vecLine[30]!="stun_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[stun_rate]位置不对应"); return false; }
		if(vecLine[31]!="stun_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[stun_res_rate]位置不对应"); return false; }
		if(vecLine[32]!="immobilize_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[immobilize_rate]位置不对应"); return false; }
		if(vecLine[33]!="immobilize_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[immobilize_res_rate]位置不对应"); return false; }
		if(vecLine[34]!="hit_fly_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_fly_rate]位置不对应"); return false; }
		if(vecLine[35]!="hit_fly_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_fly_res_rate]位置不对应"); return false; }
		if(vecLine[36]!="freeze_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[freeze_rate]位置不对应"); return false; }
		if(vecLine[37]!="freeze_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[freeze_res_rate]位置不对应"); return false; }
		if(vecLine[38]!="purify_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[purify_rate]位置不对应"); return false; }
		if(vecLine[39]!="purify_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[purify_res_rate]位置不对应"); return false; }
		if(vecLine[40]!="dispel_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dispel_rate]位置不对应"); return false; }
		if(vecLine[41]!="dispel_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dispel_res_rate]位置不对应"); return false; }
		if(vecLine[42]!="slience_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[slience_rate]位置不对应"); return false; }
		if(vecLine[43]!="slience_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[slience_res_rate]位置不对应"); return false; }
		if(vecLine[44]!="break_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[break_rate]位置不对应"); return false; }
		if(vecLine[45]!="break_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[break_res_rate]位置不对应"); return false; }
		if(vecLine[46]!="damp_heal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[damp_heal_rate]位置不对应"); return false; }
		if(vecLine[47]!="damp_heal_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[damp_heal_res_rate]位置不对应"); return false; }
		if(vecLine[48]!="cri_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[cri_dmg_value]位置不对应"); return false; }
		if(vecLine[49]!="cri_res_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[cri_res_dmg_value]位置不对应"); return false; }
		if(vecLine[50]!="block_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_dmg_value]位置不对应"); return false; }
		if(vecLine[51]!="block_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_dmg_rate]位置不对应"); return false; }
		if(vecLine[52]!="block_res_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_res_dmg_value]位置不对应"); return false; }
		if(vecLine[53]!="block_res_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_res_dmg_rate]位置不对应"); return false; }
		if(vecLine[54]!="to_player_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_player_dmg_rate]位置不对应"); return false; }
		if(vecLine[55]!="from_player_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_player_dmg_rate]位置不对应"); return false; }
		if(vecLine[56]!="to_monster_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_monster_dmg_rate]位置不对应"); return false; }
		if(vecLine[57]!="from_monster_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_monster_dmg_rate]位置不对应"); return false; }
		if(vecLine[58]!="to_boss_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_boss_dmg_rate]位置不对应"); return false; }
		if(vecLine[59]!="from_boss_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_boss_dmg_rate]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureCombatBasicElement member = new CreatureCombatBasicElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.maxhp_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.maxhp_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_attack_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_attack_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_defense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_attack_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_attack_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_defense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hit_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.miss_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.critical_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tenacity_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.penetrate_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dodge_value );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_per_sec);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_steal_chance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_steal_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.thorns_chance);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.thorns_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exp );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.knockback_res);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.hit_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.miss_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.critical_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.tenacity_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.penetrate_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.dodge_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.crit_dmg);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.crit_res);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.stun_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.stun_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.immobilize_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.immobilize_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.hit_fly_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.hit_fly_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.freeze_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.freeze_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.purify_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.purify_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.dispel_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.dispel_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.slience_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.slience_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.break_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.break_res_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.damp_heal_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.damp_heal_res_rate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cri_dmg_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cri_res_dmg_value );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.block_dmg_value);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.block_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.block_res_dmg_value);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.block_res_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.to_player_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.from_player_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.to_monster_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.from_monster_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.to_boss_dmg_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.from_boss_dmg_rate);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 60)
		{
			Ex.Logger.Log("CreatureCombatBasic.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="maxhp_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[maxhp_min]位置不对应"); return false; }
		if(vecLine[2]!="maxhp_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[maxhp_max]位置不对应"); return false; }
		if(vecLine[3]!="physic_attack_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_attack_min]位置不对应"); return false; }
		if(vecLine[4]!="physic_attack_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_attack_max]位置不对应"); return false; }
		if(vecLine[5]!="physic_defense"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[6]!="magic_attack_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_attack_min]位置不对应"); return false; }
		if(vecLine[7]!="magic_attack_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_attack_max]位置不对应"); return false; }
		if(vecLine[8]!="magic_defense"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[9]!="hit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[10]!="miss_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[miss_value]位置不对应"); return false; }
		if(vecLine[11]!="critical_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[critical_value]位置不对应"); return false; }
		if(vecLine[12]!="tenacity_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[tenacity_value]位置不对应"); return false; }
		if(vecLine[13]!="penetrate_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[14]!="dodge_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[15]!="life_per_sec"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应"); return false; }
		if(vecLine[16]!="life_steal_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应"); return false; }
		if(vecLine[17]!="life_steal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应"); return false; }
		if(vecLine[18]!="thorns_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应"); return false; }
		if(vecLine[19]!="thorns_amount"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应"); return false; }
		if(vecLine[20]!="exp"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[21]!="knockback_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[knockback_res]位置不对应"); return false; }
		if(vecLine[22]!="hit_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_rate]位置不对应"); return false; }
		if(vecLine[23]!="miss_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[miss_rate]位置不对应"); return false; }
		if(vecLine[24]!="critical_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[critical_rate]位置不对应"); return false; }
		if(vecLine[25]!="tenacity_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[tenacity_rate]位置不对应"); return false; }
		if(vecLine[26]!="penetrate_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_rate]位置不对应"); return false; }
		if(vecLine[27]!="dodge_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_rate]位置不对应"); return false; }
		if(vecLine[28]!="crit_dmg"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应"); return false; }
		if(vecLine[29]!="crit_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_res]位置不对应"); return false; }
		if(vecLine[30]!="stun_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[stun_rate]位置不对应"); return false; }
		if(vecLine[31]!="stun_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[stun_res_rate]位置不对应"); return false; }
		if(vecLine[32]!="immobilize_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[immobilize_rate]位置不对应"); return false; }
		if(vecLine[33]!="immobilize_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[immobilize_res_rate]位置不对应"); return false; }
		if(vecLine[34]!="hit_fly_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_fly_rate]位置不对应"); return false; }
		if(vecLine[35]!="hit_fly_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_fly_res_rate]位置不对应"); return false; }
		if(vecLine[36]!="freeze_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[freeze_rate]位置不对应"); return false; }
		if(vecLine[37]!="freeze_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[freeze_res_rate]位置不对应"); return false; }
		if(vecLine[38]!="purify_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[purify_rate]位置不对应"); return false; }
		if(vecLine[39]!="purify_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[purify_res_rate]位置不对应"); return false; }
		if(vecLine[40]!="dispel_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dispel_rate]位置不对应"); return false; }
		if(vecLine[41]!="dispel_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dispel_res_rate]位置不对应"); return false; }
		if(vecLine[42]!="slience_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[slience_rate]位置不对应"); return false; }
		if(vecLine[43]!="slience_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[slience_res_rate]位置不对应"); return false; }
		if(vecLine[44]!="break_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[break_rate]位置不对应"); return false; }
		if(vecLine[45]!="break_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[break_res_rate]位置不对应"); return false; }
		if(vecLine[46]!="damp_heal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[damp_heal_rate]位置不对应"); return false; }
		if(vecLine[47]!="damp_heal_res_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[damp_heal_res_rate]位置不对应"); return false; }
		if(vecLine[48]!="cri_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[cri_dmg_value]位置不对应"); return false; }
		if(vecLine[49]!="cri_res_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[cri_res_dmg_value]位置不对应"); return false; }
		if(vecLine[50]!="block_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_dmg_value]位置不对应"); return false; }
		if(vecLine[51]!="block_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_dmg_rate]位置不对应"); return false; }
		if(vecLine[52]!="block_res_dmg_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_res_dmg_value]位置不对应"); return false; }
		if(vecLine[53]!="block_res_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_res_dmg_rate]位置不对应"); return false; }
		if(vecLine[54]!="to_player_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_player_dmg_rate]位置不对应"); return false; }
		if(vecLine[55]!="from_player_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_player_dmg_rate]位置不对应"); return false; }
		if(vecLine[56]!="to_monster_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_monster_dmg_rate]位置不对应"); return false; }
		if(vecLine[57]!="from_monster_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_monster_dmg_rate]位置不对应"); return false; }
		if(vecLine[58]!="to_boss_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[to_boss_dmg_rate]位置不对应"); return false; }
		if(vecLine[59]!="from_boss_dmg_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[from_boss_dmg_rate]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)60)
			{
				return false;
			}
			CreatureCombatBasicElement member = new CreatureCombatBasicElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.maxhp_min=Convert.ToInt32(vecLine[1]);
			member.maxhp_max=Convert.ToInt32(vecLine[2]);
			member.physic_attack_min=Convert.ToInt32(vecLine[3]);
			member.physic_attack_max=Convert.ToInt32(vecLine[4]);
			member.physic_defense=Convert.ToInt32(vecLine[5]);
			member.magic_attack_min=Convert.ToInt32(vecLine[6]);
			member.magic_attack_max=Convert.ToInt32(vecLine[7]);
			member.magic_defense=Convert.ToInt32(vecLine[8]);
			member.hit_value=Convert.ToInt32(vecLine[9]);
			member.miss_value=Convert.ToInt32(vecLine[10]);
			member.critical_value=Convert.ToInt32(vecLine[11]);
			member.tenacity_value=Convert.ToInt32(vecLine[12]);
			member.penetrate_value=Convert.ToInt32(vecLine[13]);
			member.dodge_value=Convert.ToInt32(vecLine[14]);
			member.life_per_sec=Convert.ToSingle(vecLine[15]);
			member.life_steal_chance=Convert.ToSingle(vecLine[16]);
			member.life_steal_rate=Convert.ToSingle(vecLine[17]);
			member.thorns_chance=Convert.ToSingle(vecLine[18]);
			member.thorns_amount=Convert.ToInt32(vecLine[19]);
			member.exp=Convert.ToInt32(vecLine[20]);
			member.knockback_res=Convert.ToSingle(vecLine[21]);
			member.hit_rate=Convert.ToSingle(vecLine[22]);
			member.miss_rate=Convert.ToSingle(vecLine[23]);
			member.critical_rate=Convert.ToSingle(vecLine[24]);
			member.tenacity_rate=Convert.ToSingle(vecLine[25]);
			member.penetrate_rate=Convert.ToSingle(vecLine[26]);
			member.dodge_rate=Convert.ToSingle(vecLine[27]);
			member.crit_dmg=Convert.ToSingle(vecLine[28]);
			member.crit_res=Convert.ToSingle(vecLine[29]);
			member.stun_rate=Convert.ToSingle(vecLine[30]);
			member.stun_res_rate=Convert.ToSingle(vecLine[31]);
			member.immobilize_rate=Convert.ToSingle(vecLine[32]);
			member.immobilize_res_rate=Convert.ToSingle(vecLine[33]);
			member.hit_fly_rate=Convert.ToSingle(vecLine[34]);
			member.hit_fly_res_rate=Convert.ToSingle(vecLine[35]);
			member.freeze_rate=Convert.ToSingle(vecLine[36]);
			member.freeze_res_rate=Convert.ToSingle(vecLine[37]);
			member.purify_rate=Convert.ToSingle(vecLine[38]);
			member.purify_res_rate=Convert.ToSingle(vecLine[39]);
			member.dispel_rate=Convert.ToSingle(vecLine[40]);
			member.dispel_res_rate=Convert.ToSingle(vecLine[41]);
			member.slience_rate=Convert.ToSingle(vecLine[42]);
			member.slience_res_rate=Convert.ToSingle(vecLine[43]);
			member.break_rate=Convert.ToSingle(vecLine[44]);
			member.break_res_rate=Convert.ToSingle(vecLine[45]);
			member.damp_heal_rate=Convert.ToSingle(vecLine[46]);
			member.damp_heal_res_rate=Convert.ToSingle(vecLine[47]);
			member.cri_dmg_value=Convert.ToInt32(vecLine[48]);
			member.cri_res_dmg_value=Convert.ToInt32(vecLine[49]);
			member.block_dmg_value=Convert.ToSingle(vecLine[50]);
			member.block_dmg_rate=Convert.ToSingle(vecLine[51]);
			member.block_res_dmg_value=Convert.ToSingle(vecLine[52]);
			member.block_res_dmg_rate=Convert.ToSingle(vecLine[53]);
			member.to_player_dmg_rate=Convert.ToSingle(vecLine[54]);
			member.from_player_dmg_rate=Convert.ToSingle(vecLine[55]);
			member.to_monster_dmg_rate=Convert.ToSingle(vecLine[56]);
			member.from_monster_dmg_rate=Convert.ToSingle(vecLine[57]);
			member.to_boss_dmg_rate=Convert.ToSingle(vecLine[58]);
			member.from_boss_dmg_rate=Convert.ToSingle(vecLine[59]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
