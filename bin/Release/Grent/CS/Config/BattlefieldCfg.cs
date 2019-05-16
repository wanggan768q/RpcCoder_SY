using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//战场配置表配置数据类
public class BattlefieldElement
{
	public int id;               	//ID	ID
	public string comment;       	//阶级注释	策划用
	public int element_type;     	//元素类型	1：怪物 2：交互OBJ 3：传送点 4：玩家
	public int element_id;       	//元素ID	与元素类型对应 如元素类型为1，则此处为总NPC表ID 如元素类型为2，则此处为场景obj表ID 如元素类型为3，则此处为teleport_target表的ID
	public int ranked;           	//获得军衔值	击杀该怪物或交互OBJ获得的军衔值数目
	public int honored;          	//获得荣誉值	击杀该怪物或交互OBJ获得的荣誉值数目
	public int contribution;     	//获得贡献值	击杀该怪物或交互OBJ获得的贡献值数目
	public int birth_reminder;   	//出生提示	该元素刷新时是否拥有提示 0：没有 1：有
	public int death_reminder;   	//死亡提示	该元素死亡时是否拥有提示 0：没有 1：有
	public int activity;         	//获得活跃度	击杀该怪物或交互OBJ获得的活跃度数目

	public bool IsValidate = false;
	public BattlefieldElement()
	{
		id = -1;
	}
};

//战场配置表配置封装类
public class BattlefieldTable
{

	private BattlefieldTable()
	{
		m_mapElements = new Dictionary<int, BattlefieldElement>();
		m_emptyItem = new BattlefieldElement();
		m_vecAllElements = new List<BattlefieldElement>();
	}
	private Dictionary<int, BattlefieldElement> m_mapElements = null;
	private List<BattlefieldElement>	m_vecAllElements = null;
	private BattlefieldElement m_emptyItem = null;
	private static BattlefieldTable sInstance = null;

	public static BattlefieldTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BattlefieldTable();
			return sInstance;
		}
	}

	public BattlefieldElement GetElement(int key)
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

  public List<BattlefieldElement> GetAllElement(Predicate<BattlefieldElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Battlefield.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Battlefield.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Battlefield.bin]未找到");
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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("Battlefield.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Battlefield.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Battlefield.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="element_type"){Ex.Logger.Log("Battlefield.csv中字段[element_type]位置不对应"); return false; }
		if(vecLine[3]!="element_id"){Ex.Logger.Log("Battlefield.csv中字段[element_id]位置不对应"); return false; }
		if(vecLine[4]!="ranked"){Ex.Logger.Log("Battlefield.csv中字段[ranked]位置不对应"); return false; }
		if(vecLine[5]!="honored"){Ex.Logger.Log("Battlefield.csv中字段[honored]位置不对应"); return false; }
		if(vecLine[6]!="contribution"){Ex.Logger.Log("Battlefield.csv中字段[contribution]位置不对应"); return false; }
		if(vecLine[7]!="birth_reminder"){Ex.Logger.Log("Battlefield.csv中字段[birth_reminder]位置不对应"); return false; }
		if(vecLine[8]!="death_reminder"){Ex.Logger.Log("Battlefield.csv中字段[death_reminder]位置不对应"); return false; }
		if(vecLine[9]!="activity"){Ex.Logger.Log("Battlefield.csv中字段[activity]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BattlefieldElement member = new BattlefieldElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.element_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.element_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ranked );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.honored );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.contribution );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.birth_reminder );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.death_reminder );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.activity );

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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("Battlefield.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Battlefield.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Battlefield.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="element_type"){Ex.Logger.Log("Battlefield.csv中字段[element_type]位置不对应"); return false; }
		if(vecLine[3]!="element_id"){Ex.Logger.Log("Battlefield.csv中字段[element_id]位置不对应"); return false; }
		if(vecLine[4]!="ranked"){Ex.Logger.Log("Battlefield.csv中字段[ranked]位置不对应"); return false; }
		if(vecLine[5]!="honored"){Ex.Logger.Log("Battlefield.csv中字段[honored]位置不对应"); return false; }
		if(vecLine[6]!="contribution"){Ex.Logger.Log("Battlefield.csv中字段[contribution]位置不对应"); return false; }
		if(vecLine[7]!="birth_reminder"){Ex.Logger.Log("Battlefield.csv中字段[birth_reminder]位置不对应"); return false; }
		if(vecLine[8]!="death_reminder"){Ex.Logger.Log("Battlefield.csv中字段[death_reminder]位置不对应"); return false; }
		if(vecLine[9]!="activity"){Ex.Logger.Log("Battlefield.csv中字段[activity]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)10)
			{
				return false;
			}
			BattlefieldElement member = new BattlefieldElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.element_type=Convert.ToInt32(vecLine[2]);
			member.element_id=Convert.ToInt32(vecLine[3]);
			member.ranked=Convert.ToInt32(vecLine[4]);
			member.honored=Convert.ToInt32(vecLine[5]);
			member.contribution=Convert.ToInt32(vecLine[6]);
			member.birth_reminder=Convert.ToInt32(vecLine[7]);
			member.death_reminder=Convert.ToInt32(vecLine[8]);
			member.activity=Convert.ToInt32(vecLine[9]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
