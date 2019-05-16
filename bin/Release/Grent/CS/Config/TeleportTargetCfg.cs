using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//传送目标表配置数据类
public class TeleportTargetElement
{
	public int id;               	//序号	代表玩家传送到的目标点
	public string comment;       	//备注	
	public int map_id;           	//代表地图号id	
	public lf location;          	//代表untiy中的世界坐标	x|y|z
	public int face_rotate;      	//生成点朝向	用角度表示角色传送后的朝向，采用unity中生成点Y轴的旋转量
	public int type;             	//该出生点的类型	1为地图传送，代表从大地图传送到该图时，都会传送到该点 2为常规传送代表正常的一对一传送 3为地图和常规传送都会是这个点
	public int string_name;      	//传送点名称	在此填写传送到的位置名称
	public string icon;          	//传送点图标	该传送点在地图上显示的图标

	public bool IsValidate = false;
	public TeleportTargetElement()
	{
		id = -1;
	}
};

//传送目标表配置封装类
public class TeleportTargetTable
{

	private TeleportTargetTable()
	{
		m_mapElements = new Dictionary<int, TeleportTargetElement>();
		m_emptyItem = new TeleportTargetElement();
		m_vecAllElements = new List<TeleportTargetElement>();
	}
	private Dictionary<int, TeleportTargetElement> m_mapElements = null;
	private List<TeleportTargetElement>	m_vecAllElements = null;
	private TeleportTargetElement m_emptyItem = null;
	private static TeleportTargetTable sInstance = null;

	public static TeleportTargetTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TeleportTargetTable();
			return sInstance;
		}
	}

	public TeleportTargetElement GetElement(int key)
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

  public List<TeleportTargetElement> GetAllElement(Predicate<TeleportTargetElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TeleportTarget.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TeleportTarget.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TeleportTarget.bin]未找到");
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
			Ex.Logger.Log("TeleportTarget.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TeleportTarget.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TeleportTarget.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("TeleportTarget.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="location"){Ex.Logger.Log("TeleportTarget.csv中字段[location]位置不对应"); return false; }
		if(vecLine[4]!="face_rotate"){Ex.Logger.Log("TeleportTarget.csv中字段[face_rotate]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("TeleportTarget.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="string_name"){Ex.Logger.Log("TeleportTarget.csv中字段[string_name]位置不对应"); return false; }
		if(vecLine[7]!="icon"){Ex.Logger.Log("TeleportTarget.csv中字段[icon]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TeleportTargetElement member = new TeleportTargetElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.location);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.face_rotate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);

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
			Ex.Logger.Log("TeleportTarget.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TeleportTarget.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TeleportTarget.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("TeleportTarget.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="location"){Ex.Logger.Log("TeleportTarget.csv中字段[location]位置不对应"); return false; }
		if(vecLine[4]!="face_rotate"){Ex.Logger.Log("TeleportTarget.csv中字段[face_rotate]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("TeleportTarget.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="string_name"){Ex.Logger.Log("TeleportTarget.csv中字段[string_name]位置不对应"); return false; }
		if(vecLine[7]!="icon"){Ex.Logger.Log("TeleportTarget.csv中字段[icon]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			TeleportTargetElement member = new TeleportTargetElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.map_id=Convert.ToInt32(vecLine[2]);
			member.location=vecLine[3];
			member.face_rotate=Convert.ToInt32(vecLine[4]);
			member.type=Convert.ToInt32(vecLine[5]);
			member.string_name=Convert.ToInt32(vecLine[6]);
			member.icon=vecLine[7];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
