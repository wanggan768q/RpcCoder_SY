using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色配置数据类
public class CreateRoleElement
{
	public int id;               	//种族	种族
	public li occupation;        	//职业	1:战士 2:法师
	public li sex;               	//性别	1:男性 2:女性

	public bool IsValidate = false;
	public CreateRoleElement()
	{
		id = -1;
	}
};

//角色配置封装类
public class CreateRoleTable
{

	private CreateRoleTable()
	{
		m_mapElements = new Dictionary<int, CreateRoleElement>();
		m_emptyItem = new CreateRoleElement();
		m_vecAllElements = new List<CreateRoleElement>();
	}
	private Dictionary<int, CreateRoleElement> m_mapElements = null;
	private List<CreateRoleElement>	m_vecAllElements = null;
	private CreateRoleElement m_emptyItem = null;
	private static CreateRoleTable sInstance = null;

	public static CreateRoleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreateRoleTable();
			return sInstance;
		}
	}

	public CreateRoleElement GetElement(int key)
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

  public List<CreateRoleElement> GetAllElement(Predicate<CreateRoleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreateRole.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreateRole.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreateRole.bin]未找到");
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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("CreateRole.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreateRole.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="occupation"){Ex.Logger.Log("CreateRole.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[2]!="sex"){Ex.Logger.Log("CreateRole.csv中字段[sex]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreateRoleElement member = new CreateRoleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occupation);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sex);

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
		if(vecLine.Count != 3)
		{
			Ex.Logger.Log("CreateRole.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreateRole.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="occupation"){Ex.Logger.Log("CreateRole.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[2]!="sex"){Ex.Logger.Log("CreateRole.csv中字段[sex]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)3)
			{
				return false;
			}
			CreateRoleElement member = new CreateRoleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.occupation=vecLine[1];
			member.sex=vecLine[2];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
