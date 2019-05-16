using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色经验配置数据类
public class ExperienceElement
{
	public int id;               	//等级	等级
	public int exp;              	//本级经验	本级经验
	public int total_exp;        	//经验总和	经验总和
	public int blood_limit;      	//血池上限	血池上限
	public int z_exp;            	//占星经验值	1=10000
	public int l_exp;            	//猎魔经验值	1=10000
	public int j_exp;            	//精英怪经验值	1=10000
	public int coe_tenacity;     	//治疗暴击修正参数	视为治疗韧性

	public bool IsValidate = false;
	public ExperienceElement()
	{
		id = -1;
	}
};

//角色经验配置封装类
public class ExperienceTable
{

	private ExperienceTable()
	{
		m_mapElements = new Dictionary<int, ExperienceElement>();
		m_emptyItem = new ExperienceElement();
		m_vecAllElements = new List<ExperienceElement>();
	}
	private Dictionary<int, ExperienceElement> m_mapElements = null;
	private List<ExperienceElement>	m_vecAllElements = null;
	private ExperienceElement m_emptyItem = null;
	private static ExperienceTable sInstance = null;

	public static ExperienceTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ExperienceTable();
			return sInstance;
		}
	}

	public ExperienceElement GetElement(int key)
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

  public List<ExperienceElement> GetAllElement(Predicate<ExperienceElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Experience.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Experience.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Experience.bin]未找到");
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
			Ex.Logger.Log("Experience.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Experience.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="exp"){Ex.Logger.Log("Experience.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[2]!="total_exp"){Ex.Logger.Log("Experience.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[3]!="blood_limit"){Ex.Logger.Log("Experience.csv中字段[blood_limit]位置不对应"); return false; }
		if(vecLine[4]!="z_exp"){Ex.Logger.Log("Experience.csv中字段[z_exp]位置不对应"); return false; }
		if(vecLine[5]!="l_exp"){Ex.Logger.Log("Experience.csv中字段[l_exp]位置不对应"); return false; }
		if(vecLine[6]!="j_exp"){Ex.Logger.Log("Experience.csv中字段[j_exp]位置不对应"); return false; }
		if(vecLine[7]!="coe_tenacity"){Ex.Logger.Log("Experience.csv中字段[coe_tenacity]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ExperienceElement member = new ExperienceElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.total_exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.blood_limit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.z_exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.l_exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.j_exp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.coe_tenacity );

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
			Ex.Logger.Log("Experience.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Experience.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="exp"){Ex.Logger.Log("Experience.csv中字段[exp]位置不对应"); return false; }
		if(vecLine[2]!="total_exp"){Ex.Logger.Log("Experience.csv中字段[total_exp]位置不对应"); return false; }
		if(vecLine[3]!="blood_limit"){Ex.Logger.Log("Experience.csv中字段[blood_limit]位置不对应"); return false; }
		if(vecLine[4]!="z_exp"){Ex.Logger.Log("Experience.csv中字段[z_exp]位置不对应"); return false; }
		if(vecLine[5]!="l_exp"){Ex.Logger.Log("Experience.csv中字段[l_exp]位置不对应"); return false; }
		if(vecLine[6]!="j_exp"){Ex.Logger.Log("Experience.csv中字段[j_exp]位置不对应"); return false; }
		if(vecLine[7]!="coe_tenacity"){Ex.Logger.Log("Experience.csv中字段[coe_tenacity]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			ExperienceElement member = new ExperienceElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.exp=Convert.ToInt32(vecLine[1]);
			member.total_exp=Convert.ToInt32(vecLine[2]);
			member.blood_limit=Convert.ToInt32(vecLine[3]);
			member.z_exp=Convert.ToInt32(vecLine[4]);
			member.l_exp=Convert.ToInt32(vecLine[5]);
			member.j_exp=Convert.ToInt32(vecLine[6]);
			member.coe_tenacity=Convert.ToInt32(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
