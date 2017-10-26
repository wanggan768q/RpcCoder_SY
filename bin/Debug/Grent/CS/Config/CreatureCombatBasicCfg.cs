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
	public string note;          	//中文注释	中文注释
	public int hp_min;           	//生命下限	生命下限
	public int hp_max;           	//生命上限	生命上限
	public int p_atk_min;        	//物理攻击力下限	物理攻击力下限
	public int p_atk_max;        	//物理攻击力上限	物理攻击力上限
	public int p_def;            	//物理防御力	物理防御力
	public int s_atk_min;        	//魔法攻击力下限	魔法攻击力下限
	public int s_atk_max;        	//魔法攻击力上限	魔法攻击力上限
	public int s_def;            	//魔法防御力	魔法防御力
	public int hit_value;        	//命中值	命中值
	public int dodge_value;      	//闪避值	闪避值
	public int crit_value;       	//暴击值	暴击值
	public int resilience_value; 	//韧性值	韧性值
	public int penetrate_value;  	//穿透值	穿透值
	public int block_value;      	//格挡值	格挡值
	public float life_per_sec;   	//生命恢复速度	生命恢复速度
	public float life_steal_chance;	//生命偷取几率	生命偷取几率
	public float life_steal_rate;	//生命偷取比例	生命偷取比例
	public float thorns_chance;  	//反弹率	反弹率
	public int thorns_amount;    	//反弹值	反弹值
	public int exp;              	//经验值	经验值
	public float knockback_res;  	//击退抵抗率	击退抵抗率
	public float hit;            	//命中率	命中率
	public float dodge;          	//闪避率	闪避率
	public float crit;           	//暴击率	暴击率
	public float resilience;     	//韧性	韧性
	public float penetrate;      	//穿透率	穿透率
	public float block;          	//格挡率	格挡率
	public float crit_dmg;       	//暴击伤害	暴击伤害
	public float crit_res;       	//暴击抵抗	暴击抵抗

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
		if(vecLine.Count != 31)
		{
			Ex.Logger.Log("CreatureCombatBasic.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="note"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[note]位置不对应"); return false; }
		if(vecLine[2]!="hp_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hp_min]位置不对应"); return false; }
		if(vecLine[3]!="hp_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hp_max]位置不对应"); return false; }
		if(vecLine[4]!="p_atk_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_atk_min]位置不对应"); return false; }
		if(vecLine[5]!="p_atk_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_atk_max]位置不对应"); return false; }
		if(vecLine[6]!="p_def"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_def]位置不对应"); return false; }
		if(vecLine[7]!="s_atk_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_atk_min]位置不对应"); return false; }
		if(vecLine[8]!="s_atk_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_atk_max]位置不对应"); return false; }
		if(vecLine[9]!="s_def"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_def]位置不对应"); return false; }
		if(vecLine[10]!="hit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[11]!="dodge_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[12]!="crit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_value]位置不对应"); return false; }
		if(vecLine[13]!="resilience_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[resilience_value]位置不对应"); return false; }
		if(vecLine[14]!="penetrate_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[15]!="block_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_value]位置不对应"); return false; }
		if(vecLine[16]!="life_per_sec"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应"); return false; }
		if(vecLine[17]!="life_steal_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应"); return false; }
		if(vecLine[18]!="life_steal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应"); return false; }
		if(vecLine[19]!="thorns_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应"); return false; }
		if(vecLine[20]!="thorns_amount"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应"); return false; }
		if(vecLine[21]!="exp"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[22]!="knockback_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[knockback_res]位置不对应"); return false; }
		if(vecLine[23]!="hit"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit]位置不对应"); return false; }
		if(vecLine[24]!="dodge"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge]位置不对应"); return false; }
		if(vecLine[25]!="crit"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit]位置不对应"); return false; }
		if(vecLine[26]!="resilience"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[resilience]位置不对应"); return false; }
		if(vecLine[27]!="penetrate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate]位置不对应"); return false; }
		if(vecLine[28]!="block"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block]位置不对应"); return false; }
		if(vecLine[29]!="crit_dmg"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应"); return false; }
		if(vecLine[30]!="crit_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_res]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureCombatBasicElement member = new CreatureCombatBasicElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.note);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hp_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hp_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.p_atk_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.p_atk_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.p_def );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.s_atk_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.s_atk_max );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.s_def );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hit_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dodge_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.crit_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.resilience_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.penetrate_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.block_value );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_per_sec);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_steal_chance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.life_steal_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.thorns_chance);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.thorns_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exp );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.knockback_res);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.hit);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.dodge);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.crit);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.resilience);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.penetrate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.block);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.crit_dmg);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.crit_res);

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
		if(vecLine.Count != 31)
		{
			Ex.Logger.Log("CreatureCombatBasic.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="note"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[note]位置不对应"); return false; }
		if(vecLine[2]!="hp_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hp_min]位置不对应"); return false; }
		if(vecLine[3]!="hp_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hp_max]位置不对应"); return false; }
		if(vecLine[4]!="p_atk_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_atk_min]位置不对应"); return false; }
		if(vecLine[5]!="p_atk_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_atk_max]位置不对应"); return false; }
		if(vecLine[6]!="p_def"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[p_def]位置不对应"); return false; }
		if(vecLine[7]!="s_atk_min"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_atk_min]位置不对应"); return false; }
		if(vecLine[8]!="s_atk_max"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_atk_max]位置不对应"); return false; }
		if(vecLine[9]!="s_def"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[s_def]位置不对应"); return false; }
		if(vecLine[10]!="hit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[11]!="dodge_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[12]!="crit_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_value]位置不对应"); return false; }
		if(vecLine[13]!="resilience_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[resilience_value]位置不对应"); return false; }
		if(vecLine[14]!="penetrate_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[15]!="block_value"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block_value]位置不对应"); return false; }
		if(vecLine[16]!="life_per_sec"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_per_sec]位置不对应"); return false; }
		if(vecLine[17]!="life_steal_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_chance]位置不对应"); return false; }
		if(vecLine[18]!="life_steal_rate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[life_steal_rate]位置不对应"); return false; }
		if(vecLine[19]!="thorns_chance"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_chance]位置不对应"); return false; }
		if(vecLine[20]!="thorns_amount"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[thorns_amount]位置不对应"); return false; }
		if(vecLine[21]!="exp"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[22]!="knockback_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[knockback_res]位置不对应"); return false; }
		if(vecLine[23]!="hit"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[hit]位置不对应"); return false; }
		if(vecLine[24]!="dodge"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[dodge]位置不对应"); return false; }
		if(vecLine[25]!="crit"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit]位置不对应"); return false; }
		if(vecLine[26]!="resilience"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[resilience]位置不对应"); return false; }
		if(vecLine[27]!="penetrate"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[penetrate]位置不对应"); return false; }
		if(vecLine[28]!="block"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[block]位置不对应"); return false; }
		if(vecLine[29]!="crit_dmg"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_dmg]位置不对应"); return false; }
		if(vecLine[30]!="crit_res"){Ex.Logger.Log("CreatureCombatBasic.csv中字段[crit_res]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)31)
			{
				return false;
			}
			CreatureCombatBasicElement member = new CreatureCombatBasicElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.note=vecLine[1];
			member.hp_min=Convert.ToInt32(vecLine[2]);
			member.hp_max=Convert.ToInt32(vecLine[3]);
			member.p_atk_min=Convert.ToInt32(vecLine[4]);
			member.p_atk_max=Convert.ToInt32(vecLine[5]);
			member.p_def=Convert.ToInt32(vecLine[6]);
			member.s_atk_min=Convert.ToInt32(vecLine[7]);
			member.s_atk_max=Convert.ToInt32(vecLine[8]);
			member.s_def=Convert.ToInt32(vecLine[9]);
			member.hit_value=Convert.ToInt32(vecLine[10]);
			member.dodge_value=Convert.ToInt32(vecLine[11]);
			member.crit_value=Convert.ToInt32(vecLine[12]);
			member.resilience_value=Convert.ToInt32(vecLine[13]);
			member.penetrate_value=Convert.ToInt32(vecLine[14]);
			member.block_value=Convert.ToInt32(vecLine[15]);
			member.life_per_sec=Convert.ToSingle(vecLine[16]);
			member.life_steal_chance=Convert.ToSingle(vecLine[17]);
			member.life_steal_rate=Convert.ToSingle(vecLine[18]);
			member.thorns_chance=Convert.ToSingle(vecLine[19]);
			member.thorns_amount=Convert.ToInt32(vecLine[20]);
			member.exp=Convert.ToInt32(vecLine[21]);
			member.knockback_res=Convert.ToSingle(vecLine[22]);
			member.hit=Convert.ToSingle(vecLine[23]);
			member.dodge=Convert.ToSingle(vecLine[24]);
			member.crit=Convert.ToSingle(vecLine[25]);
			member.resilience=Convert.ToSingle(vecLine[26]);
			member.penetrate=Convert.ToSingle(vecLine[27]);
			member.block=Convert.ToSingle(vecLine[28]);
			member.crit_dmg=Convert.ToSingle(vecLine[29]);
			member.crit_res=Convert.ToSingle(vecLine[30]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
