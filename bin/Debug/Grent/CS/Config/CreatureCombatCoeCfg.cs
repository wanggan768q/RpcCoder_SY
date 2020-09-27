using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC战斗系数表配置数据类
public class CreatureCombatCoeElement
{
	public int id;               	//ID号	关联Creature
	public int template_id;      	//对应模板	关联CreatureCombatbasic
	public float maxhp_rate;     	//生命比例	
	public float physic_attack_rate;	//物理攻击力比例	参数1：攻击类型系数，怪物都同时具有物理攻击和魔法攻击 参数2：怪物数量系数，每组怪有多少只
	public float physic_defense_rate;	//物理防御力比例	
	public float magic_attack_rate;	//魔法攻击力比例	
	public float magic_defense_rate;	//魔法防御力比例	
	public float exp_rate;       	//经验比例	

	public bool IsValidate = false;
	public CreatureCombatCoeElement()
	{
		id = -1;
	}
};

//NPC战斗系数表配置封装类
public class CreatureCombatCoeTable
{

	private CreatureCombatCoeTable()
	{
		m_mapElements = new Dictionary<int, CreatureCombatCoeElement>();
		m_emptyItem = new CreatureCombatCoeElement();
		m_vecAllElements = new List<CreatureCombatCoeElement>();
	}
	private Dictionary<int, CreatureCombatCoeElement> m_mapElements = null;
	private List<CreatureCombatCoeElement>	m_vecAllElements = null;
	private CreatureCombatCoeElement m_emptyItem = null;
	private static CreatureCombatCoeTable sInstance = null;

	public static CreatureCombatCoeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureCombatCoeTable();
			return sInstance;
		}
	}

	public CreatureCombatCoeElement GetElement(int key)
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

  public List<CreatureCombatCoeElement> GetAllElement(Predicate<CreatureCombatCoeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureCombatCoe.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureCombatCoe.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureCombatCoe.bin]未找到");
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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("CreatureCombatCoe.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="template_id"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[template_id]位置不对应"); return false; }
		if(vecLine[2]!="maxhp_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[maxhp_rate]位置不对应"); return false; }
		if(vecLine[3]!="physic_attack_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[physic_attack_rate]位置不对应"); return false; }
		if(vecLine[4]!="physic_defense_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[physic_defense_rate]位置不对应"); return false; }
		if(vecLine[5]!="magic_attack_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[magic_attack_rate]位置不对应"); return false; }
		if(vecLine[6]!="magic_defense_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[magic_defense_rate]位置不对应"); return false; }
		if(vecLine[7]!="exp_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[exp_rate]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureCombatCoeElement member = new CreatureCombatCoeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.template_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.maxhp_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.physic_attack_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.physic_defense_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.magic_attack_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.magic_defense_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.exp_rate);

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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("CreatureCombatCoe.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="template_id"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[template_id]位置不对应"); return false; }
		if(vecLine[2]!="maxhp_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[maxhp_rate]位置不对应"); return false; }
		if(vecLine[3]!="physic_attack_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[physic_attack_rate]位置不对应"); return false; }
		if(vecLine[4]!="physic_defense_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[physic_defense_rate]位置不对应"); return false; }
		if(vecLine[5]!="magic_attack_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[magic_attack_rate]位置不对应"); return false; }
		if(vecLine[6]!="magic_defense_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[magic_defense_rate]位置不对应"); return false; }
		if(vecLine[7]!="exp_rate"){Ex.Logger.Log("CreatureCombatCoe.csv中字段[exp_rate]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			CreatureCombatCoeElement member = new CreatureCombatCoeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.template_id=Convert.ToInt32(vecLine[1]);
			member.maxhp_rate=Convert.ToSingle(vecLine[2]);
			member.physic_attack_rate=Convert.ToSingle(vecLine[3]);
			member.physic_defense_rate=Convert.ToSingle(vecLine[4]);
			member.magic_attack_rate=Convert.ToSingle(vecLine[5]);
			member.magic_defense_rate=Convert.ToSingle(vecLine[6]);
			member.exp_rate=Convert.ToSingle(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
