using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能配置数据类
public class SkillElement
{
	public int id;               	//技能ID	技能ID
	public int ligic_id;         	//技能释放的逻辑：	技能释放的逻辑：
	public int charge_or_interval;	//在一段时间之内，释放多少次伤害（BUFF）	在一段时间之内，释放多少次伤害（BUFF）
	public int cooldown_id;      	//冷却ID组ID（-1：表示没有冷却组）	冷却ID组ID（-1：表示没有冷却组）
	public int cooldown_time;    	//冷却的时间(毫秒单位)	冷却的时间(毫秒单位)
	public int charge_time;      	//引唱的时间（毫秒为单位）	引唱的时间（毫秒为单位）
	public int channel_time;     	//引导的时间（毫秒为单位）	引导的时间（毫秒为单位）
	public li pars;              	//参数	参数
	public int attack_type;      	//攻击的类型:0:物理攻击,1:法术攻击,2:物理&法术攻击	攻击的类型:0:物理攻击,1:法术攻击,2:物理&法术攻击
	public int attack_rate;      	//技能伤害系数	技能伤害系数
	public int attack_value;     	//技能伤害附加	技能伤害附加
	public int attack_range;     	//技能释放距离	技能释放距离

	public bool IsValidate = false;
	public SkillElement()
	{
		id = -1;
	}
};

//技能配置封装类
public class SkillTable
{

	private SkillTable()
	{
		m_mapElements = new Dictionary<int, SkillElement>();
		m_emptyItem = new SkillElement();
		m_vecAllElements = new List<SkillElement>();
	}
	private Dictionary<int, SkillElement> m_mapElements = null;
	private List<SkillElement>	m_vecAllElements = null;
	private SkillElement m_emptyItem = null;
	private static SkillTable sInstance = null;

	public static SkillTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SkillTable();
			return sInstance;
		}
	}

	public SkillElement GetElement(int key)
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

  public List<SkillElement> GetAllElement(Predicate<SkillElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Skill.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Skill.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Skill.bin]未找到");
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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="ligic_id"){Ex.Logger.Log("Skill.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[2]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[3]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[4]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[5]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[6]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[7]!="pars"){Ex.Logger.Log("Skill.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("Skill.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="attack_rate"){Ex.Logger.Log("Skill.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[10]!="attack_value"){Ex.Logger.Log("Skill.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[11]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillElement member = new SkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ligic_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_or_interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cooldown_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.charge_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.channel_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_range );

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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("Skill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Skill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="ligic_id"){Ex.Logger.Log("Skill.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[2]!="charge_or_interval"){Ex.Logger.Log("Skill.csv中字段[charge_or_interval]位置不对应"); return false; }
		if(vecLine[3]!="cooldown_id"){Ex.Logger.Log("Skill.csv中字段[cooldown_id]位置不对应"); return false; }
		if(vecLine[4]!="cooldown_time"){Ex.Logger.Log("Skill.csv中字段[cooldown_time]位置不对应"); return false; }
		if(vecLine[5]!="charge_time"){Ex.Logger.Log("Skill.csv中字段[charge_time]位置不对应"); return false; }
		if(vecLine[6]!="channel_time"){Ex.Logger.Log("Skill.csv中字段[channel_time]位置不对应"); return false; }
		if(vecLine[7]!="pars"){Ex.Logger.Log("Skill.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("Skill.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="attack_rate"){Ex.Logger.Log("Skill.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[10]!="attack_value"){Ex.Logger.Log("Skill.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[11]!="attack_range"){Ex.Logger.Log("Skill.csv中字段[attack_range]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			SkillElement member = new SkillElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.ligic_id=Convert.ToInt32(vecLine[1]);
			member.charge_or_interval=Convert.ToInt32(vecLine[2]);
			member.cooldown_id=Convert.ToInt32(vecLine[3]);
			member.cooldown_time=Convert.ToInt32(vecLine[4]);
			member.charge_time=Convert.ToInt32(vecLine[5]);
			member.channel_time=Convert.ToInt32(vecLine[6]);
			member.pars=vecLine[7];
			member.attack_type=Convert.ToInt32(vecLine[8]);
			member.attack_rate=Convert.ToInt32(vecLine[9]);
			member.attack_value=Convert.ToInt32(vecLine[10]);
			member.attack_range=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
