using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//召唤小怪表配置数据类
public class SummonMonsterElement
{
	public int summon_id;        	//序号	序号
	public float group_id;       	//规定召唤怪的组	规定召唤怪的组
	public int npc_entry_id;     	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	public int map_id;           	//NPC所处的场景号	NPC所处的场景号
	public float location_x;     	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	public float location_y;     	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	public float location_z;     	//路点所处的场景的Z坐标	路点所处的场景的Z坐标

	public bool IsValidate = false;
	public SummonMonsterElement()
	{
		summon_id = -1;
	}
};

//召唤小怪表配置封装类
public class SummonMonsterTable
{

	private SummonMonsterTable()
	{
		m_mapElements = new Dictionary<int, SummonMonsterElement>();
		m_emptyItem = new SummonMonsterElement();
		m_vecAllElements = new List<SummonMonsterElement>();
	}
	private Dictionary<int, SummonMonsterElement> m_mapElements = null;
	private List<SummonMonsterElement>	m_vecAllElements = null;
	private SummonMonsterElement m_emptyItem = null;
	private static SummonMonsterTable sInstance = null;

	public static SummonMonsterTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SummonMonsterTable();
			return sInstance;
		}
	}

	public SummonMonsterElement GetElement(int key)
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

  public List<SummonMonsterElement> GetAllElement(Predicate<SummonMonsterElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SummonMonster.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SummonMonster.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SummonMonster.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("SummonMonster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="summon_id"){Ex.Logger.Log("SummonMonster.csv中字段[summon_id]位置不对应"); return false; }
		if(vecLine[1]!="group_id"){Ex.Logger.Log("SummonMonster.csv中字段[group_id]位置不对应"); return false; }
		if(vecLine[2]!="npc_entry_id"){Ex.Logger.Log("SummonMonster.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[3]!="map_id"){Ex.Logger.Log("SummonMonster.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[4]!="location_x"){Ex.Logger.Log("SummonMonster.csv中字段[location_x]位置不对应"); return false; }
		if(vecLine[5]!="location_y"){Ex.Logger.Log("SummonMonster.csv中字段[location_y]位置不对应"); return false; }
		if(vecLine[6]!="location_z"){Ex.Logger.Log("SummonMonster.csv中字段[location_z]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SummonMonsterElement member = new SummonMonsterElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.summon_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.group_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_entry_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.location_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.location_y);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.location_z);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.summon_id] = member;
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("SummonMonster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="summon_id"){Ex.Logger.Log("SummonMonster.csv中字段[summon_id]位置不对应"); return false; }
		if(vecLine[1]!="group_id"){Ex.Logger.Log("SummonMonster.csv中字段[group_id]位置不对应"); return false; }
		if(vecLine[2]!="npc_entry_id"){Ex.Logger.Log("SummonMonster.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[3]!="map_id"){Ex.Logger.Log("SummonMonster.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[4]!="location_x"){Ex.Logger.Log("SummonMonster.csv中字段[location_x]位置不对应"); return false; }
		if(vecLine[5]!="location_y"){Ex.Logger.Log("SummonMonster.csv中字段[location_y]位置不对应"); return false; }
		if(vecLine[6]!="location_z"){Ex.Logger.Log("SummonMonster.csv中字段[location_z]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			SummonMonsterElement member = new SummonMonsterElement();
			member.summon_id=Convert.ToInt32(vecLine[0]);
			member.group_id=Convert.ToSingle(vecLine[1]);
			member.npc_entry_id=Convert.ToInt32(vecLine[2]);
			member.map_id=Convert.ToInt32(vecLine[3]);
			member.location_x=Convert.ToSingle(vecLine[4]);
			member.location_y=Convert.ToSingle(vecLine[5]);
			member.location_z=Convert.ToSingle(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.summon_id] = member;
		}
		return true;
	}
};
