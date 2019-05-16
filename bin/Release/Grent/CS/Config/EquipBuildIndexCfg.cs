using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//打造索引表配置数据类
public class EquipBuildIndexElement
{
	public int id;               	//配方ID	该配方内装备所对应的等级分组 4:40级 5:50级 6:60级 7:70级 8:80级 9:90级 10:100级
	public int delta_level;      	//等级差	等级差
	public li formula_mage;      	//法师对应配方	依次填入该等级该职业对应的配方，用|隔开
	public li formula_paladin;   	//圣骑对应配方	依次填入该等级该职业对应的配方，用|隔开
	public li formula_ranger;    	//游侠对应配方	依次填入该等级该职业对应的配方，用|隔开
	public li formula_mystic;    	//神秘使对应配方	依次填入该等级该职业对应的配方，用|隔开
	public li formula_berserker; 	//狂战士对应配方	依次填入该等级该职业对应的配方，用|隔开
	public int artifact_limit;   	//神器值上限	该配方对应的神器值上限

	public bool IsValidate = false;
	public EquipBuildIndexElement()
	{
		id = -1;
	}
};

//打造索引表配置封装类
public class EquipBuildIndexTable
{

	private EquipBuildIndexTable()
	{
		m_mapElements = new Dictionary<int, EquipBuildIndexElement>();
		m_emptyItem = new EquipBuildIndexElement();
		m_vecAllElements = new List<EquipBuildIndexElement>();
	}
	private Dictionary<int, EquipBuildIndexElement> m_mapElements = null;
	private List<EquipBuildIndexElement>	m_vecAllElements = null;
	private EquipBuildIndexElement m_emptyItem = null;
	private static EquipBuildIndexTable sInstance = null;

	public static EquipBuildIndexTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipBuildIndexTable();
			return sInstance;
		}
	}

	public EquipBuildIndexElement GetElement(int key)
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

  public List<EquipBuildIndexElement> GetAllElement(Predicate<EquipBuildIndexElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipBuildIndex.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipBuildIndex.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipBuildIndex.bin]未找到");
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
			Ex.Logger.Log("EquipBuildIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipBuildIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="delta_level"){Ex.Logger.Log("EquipBuildIndex.csv中字段[delta_level]位置不对应"); return false; }
		if(vecLine[2]!="formula_mage"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_mage]位置不对应"); return false; }
		if(vecLine[3]!="formula_paladin"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_paladin]位置不对应"); return false; }
		if(vecLine[4]!="formula_ranger"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_ranger]位置不对应"); return false; }
		if(vecLine[5]!="formula_mystic"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_mystic]位置不对应"); return false; }
		if(vecLine[6]!="formula_berserker"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_berserker]位置不对应"); return false; }
		if(vecLine[7]!="artifact_limit"){Ex.Logger.Log("EquipBuildIndex.csv中字段[artifact_limit]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipBuildIndexElement member = new EquipBuildIndexElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.delta_level );
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_mage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_paladin);
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_ranger);
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_mystic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_berserker);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.artifact_limit );

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
			Ex.Logger.Log("EquipBuildIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipBuildIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="delta_level"){Ex.Logger.Log("EquipBuildIndex.csv中字段[delta_level]位置不对应"); return false; }
		if(vecLine[2]!="formula_mage"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_mage]位置不对应"); return false; }
		if(vecLine[3]!="formula_paladin"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_paladin]位置不对应"); return false; }
		if(vecLine[4]!="formula_ranger"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_ranger]位置不对应"); return false; }
		if(vecLine[5]!="formula_mystic"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_mystic]位置不对应"); return false; }
		if(vecLine[6]!="formula_berserker"){Ex.Logger.Log("EquipBuildIndex.csv中字段[formula_berserker]位置不对应"); return false; }
		if(vecLine[7]!="artifact_limit"){Ex.Logger.Log("EquipBuildIndex.csv中字段[artifact_limit]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			EquipBuildIndexElement member = new EquipBuildIndexElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.delta_level=Convert.ToInt32(vecLine[1]);
			member.formula_mage=vecLine[2];
			member.formula_paladin=vecLine[3];
			member.formula_ranger=vecLine[4];
			member.formula_mystic=vecLine[5];
			member.formula_berserker=vecLine[6];
			member.artifact_limit=Convert.ToInt32(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
