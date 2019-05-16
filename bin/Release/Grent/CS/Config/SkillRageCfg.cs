using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//技能仇恨表配置数据类
public class SkillRageElement
{
	public int id;               	//技能ID	填写仇恨系数或仇恨值需要特殊处理的技能ID 未在本表中出现的技能，仇恨倍率和仇恨值默认均为1
	public string skill_name;    	//技能名称	技能名称，策划用
	public float rage_rate;      	//仇恨倍率	可正负，小数
	public int rage_value;       	//仇恨值	可正负，整数
	public string comment;       	//备注	备注

	public bool IsValidate = false;
	public SkillRageElement()
	{
		id = -1;
	}
};

//技能仇恨表配置封装类
public class SkillRageTable
{

	private SkillRageTable()
	{
		m_mapElements = new Dictionary<int, SkillRageElement>();
		m_emptyItem = new SkillRageElement();
		m_vecAllElements = new List<SkillRageElement>();
	}
	private Dictionary<int, SkillRageElement> m_mapElements = null;
	private List<SkillRageElement>	m_vecAllElements = null;
	private SkillRageElement m_emptyItem = null;
	private static SkillRageTable sInstance = null;

	public static SkillRageTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SkillRageTable();
			return sInstance;
		}
	}

	public SkillRageElement GetElement(int key)
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

  public List<SkillRageElement> GetAllElement(Predicate<SkillRageElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SkillRage.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SkillRage.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SkillRage.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("SkillRage.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SkillRage.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="skill_name"){Ex.Logger.Log("SkillRage.csv中字段[skill_name]位置不对应"); return false; }
		if(vecLine[2]!="rage_rate"){Ex.Logger.Log("SkillRage.csv中字段[rage_rate]位置不对应"); return false; }
		if(vecLine[3]!="rage_value"){Ex.Logger.Log("SkillRage.csv中字段[rage_value]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("SkillRage.csv中字段[comment]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SkillRageElement member = new SkillRageElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_name);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rage_rate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rage_value );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);

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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("SkillRage.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SkillRage.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="skill_name"){Ex.Logger.Log("SkillRage.csv中字段[skill_name]位置不对应"); return false; }
		if(vecLine[2]!="rage_rate"){Ex.Logger.Log("SkillRage.csv中字段[rage_rate]位置不对应"); return false; }
		if(vecLine[3]!="rage_value"){Ex.Logger.Log("SkillRage.csv中字段[rage_value]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("SkillRage.csv中字段[comment]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			SkillRageElement member = new SkillRageElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.skill_name=vecLine[1];
			member.rage_rate=Convert.ToSingle(vecLine[2]);
			member.rage_value=Convert.ToInt32(vecLine[3]);
			member.comment=vecLine[4];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
