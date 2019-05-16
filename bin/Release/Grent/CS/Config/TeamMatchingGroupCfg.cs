using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//队伍匹配目标组表配置数据类
public class TeamMatchingGroupElement
{
	public int id;               	//匹配ID	ID
	public int group_name;       	//匹配目标组名称	客户端分类专用，配置文字ID
	public string group_comment; 	//匹配目标组名称（策划用）	策划用
	public int group_type;       	//针对队伍类型	0：5人小队 1：多人团队
	public li parameter;         	//目标ID	对应队伍匹配目标表中的ID，多个活动用|分隔

	public bool IsValidate = false;
	public TeamMatchingGroupElement()
	{
		id = -1;
	}
};

//队伍匹配目标组表配置封装类
public class TeamMatchingGroupTable
{

	private TeamMatchingGroupTable()
	{
		m_mapElements = new Dictionary<int, TeamMatchingGroupElement>();
		m_emptyItem = new TeamMatchingGroupElement();
		m_vecAllElements = new List<TeamMatchingGroupElement>();
	}
	private Dictionary<int, TeamMatchingGroupElement> m_mapElements = null;
	private List<TeamMatchingGroupElement>	m_vecAllElements = null;
	private TeamMatchingGroupElement m_emptyItem = null;
	private static TeamMatchingGroupTable sInstance = null;

	public static TeamMatchingGroupTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TeamMatchingGroupTable();
			return sInstance;
		}
	}

	public TeamMatchingGroupElement GetElement(int key)
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

  public List<TeamMatchingGroupElement> GetAllElement(Predicate<TeamMatchingGroupElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TeamMatchingGroup.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TeamMatchingGroup.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TeamMatchingGroup.bin]未找到");
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
			Ex.Logger.Log("TeamMatchingGroup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="group_name"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_name]位置不对应"); return false; }
		if(vecLine[2]!="group_comment"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_comment]位置不对应"); return false; }
		if(vecLine[3]!="group_type"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_type]位置不对应"); return false; }
		if(vecLine[4]!="parameter"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[parameter]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TeamMatchingGroupElement member = new TeamMatchingGroupElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.group_comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter);

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
			Ex.Logger.Log("TeamMatchingGroup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="group_name"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_name]位置不对应"); return false; }
		if(vecLine[2]!="group_comment"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_comment]位置不对应"); return false; }
		if(vecLine[3]!="group_type"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[group_type]位置不对应"); return false; }
		if(vecLine[4]!="parameter"){Ex.Logger.Log("TeamMatchingGroup.csv中字段[parameter]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			TeamMatchingGroupElement member = new TeamMatchingGroupElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.group_name=Convert.ToInt32(vecLine[1]);
			member.group_comment=vecLine[2];
			member.group_type=Convert.ToInt32(vecLine[3]);
			member.parameter=vecLine[4];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
