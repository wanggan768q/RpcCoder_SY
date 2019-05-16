using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//坐骑表配置数据类
public class MountElement
{
	public int id;               	//配置ID	ID需与角色自定义表 中的坐骑一一对应
	public string comment;       	//注释	仅策划用
	public ls animation_list;    	//动画列表	坐骑的动画状态
	public float initial_velocity;	//初始速率（废弃）	坐骑动画的默认速率（m/s）

	public bool IsValidate = false;
	public MountElement()
	{
		id = -1;
	}
};

//坐骑表配置封装类
public class MountTable
{

	private MountTable()
	{
		m_mapElements = new Dictionary<int, MountElement>();
		m_emptyItem = new MountElement();
		m_vecAllElements = new List<MountElement>();
	}
	private Dictionary<int, MountElement> m_mapElements = null;
	private List<MountElement>	m_vecAllElements = null;
	private MountElement m_emptyItem = null;
	private static MountTable sInstance = null;

	public static MountTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MountTable();
			return sInstance;
		}
	}

	public MountElement GetElement(int key)
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

  public List<MountElement> GetAllElement(Predicate<MountElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Mount.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Mount.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Mount.bin]未找到");
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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("Mount.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mount.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mount.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="animation_list"){Ex.Logger.Log("Mount.csv中字段[animation_list]位置不对应"); return false; }
		if(vecLine[3]!="initial_velocity"){Ex.Logger.Log("Mount.csv中字段[initial_velocity]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MountElement member = new MountElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.animation_list);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.initial_velocity);

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
		if(vecLine.Count != 4)
		{
			Ex.Logger.Log("Mount.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mount.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mount.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="animation_list"){Ex.Logger.Log("Mount.csv中字段[animation_list]位置不对应"); return false; }
		if(vecLine[3]!="initial_velocity"){Ex.Logger.Log("Mount.csv中字段[initial_velocity]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)4)
			{
				return false;
			}
			MountElement member = new MountElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.animation_list=vecLine[2];
			member.initial_velocity=Convert.ToSingle(vecLine[3]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
