using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//动画表配置数据类
public class CgAnimationElement
{
	public int id;               	// cg_id	动画id
	public string comment;       	//注释	
	public string animation_name;	//动画文件	
	public string path_name;     	//动画所需资源文件	
	public int duration;         	//动画时长	单位s
	public int can_skip;         	//是否可以跳过	
	public string script;        	//脚本文件	
	public int teleport_map;     	//	传送的地图Id
	public li teleport_list;     	//传送位置	动画结束后传送到该位置 x|y|z
	public int binding_monster_id;	//绑定的怪物ID	
	public int time_before_skip; 	//跳过时间	动画至少播放多少秒，才会出现跳过按钮
	public int Type;             	//Cg类型	0为默认 1为替换主角形象的 2为QTE类型 3为替换主角的QTE类型

	public bool IsValidate = false;
	public CgAnimationElement()
	{
		id = -1;
	}
};

//动画表配置封装类
public class CgAnimationTable
{

	private CgAnimationTable()
	{
		m_mapElements = new Dictionary<int, CgAnimationElement>();
		m_emptyItem = new CgAnimationElement();
		m_vecAllElements = new List<CgAnimationElement>();
	}
	private Dictionary<int, CgAnimationElement> m_mapElements = null;
	private List<CgAnimationElement>	m_vecAllElements = null;
	private CgAnimationElement m_emptyItem = null;
	private static CgAnimationTable sInstance = null;

	public static CgAnimationTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CgAnimationTable();
			return sInstance;
		}
	}

	public CgAnimationElement GetElement(int key)
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

  public List<CgAnimationElement> GetAllElement(Predicate<CgAnimationElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CgAnimation.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CgAnimation.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CgAnimation.bin]未找到");
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
			Ex.Logger.Log("CgAnimation.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CgAnimation.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CgAnimation.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="animation_name"){Ex.Logger.Log("CgAnimation.csv中字段[animation_name]位置不对应"); return false; }
		if(vecLine[3]!="path_name"){Ex.Logger.Log("CgAnimation.csv中字段[path_name]位置不对应"); return false; }
		if(vecLine[4]!="duration"){Ex.Logger.Log("CgAnimation.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[5]!="can_skip"){Ex.Logger.Log("CgAnimation.csv中字段[can_skip]位置不对应"); return false; }
		if(vecLine[6]!="script"){Ex.Logger.Log("CgAnimation.csv中字段[script]位置不对应"); return false; }
		if(vecLine[7]!="teleport_map"){Ex.Logger.Log("CgAnimation.csv中字段[teleport_map]位置不对应"); return false; }
		if(vecLine[8]!="teleport_list"){Ex.Logger.Log("CgAnimation.csv中字段[teleport_list]位置不对应"); return false; }
		if(vecLine[9]!="binding_monster_id"){Ex.Logger.Log("CgAnimation.csv中字段[binding_monster_id]位置不对应"); return false; }
		if(vecLine[10]!="time_before_skip"){Ex.Logger.Log("CgAnimation.csv中字段[time_before_skip]位置不对应"); return false; }
		if(vecLine[11]!="Type"){Ex.Logger.Log("CgAnimation.csv中字段[Type]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CgAnimationElement member = new CgAnimationElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.animation_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.path_name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.can_skip );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_map );
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleport_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.binding_monster_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.time_before_skip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Type );

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
			Ex.Logger.Log("CgAnimation.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CgAnimation.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CgAnimation.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="animation_name"){Ex.Logger.Log("CgAnimation.csv中字段[animation_name]位置不对应"); return false; }
		if(vecLine[3]!="path_name"){Ex.Logger.Log("CgAnimation.csv中字段[path_name]位置不对应"); return false; }
		if(vecLine[4]!="duration"){Ex.Logger.Log("CgAnimation.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[5]!="can_skip"){Ex.Logger.Log("CgAnimation.csv中字段[can_skip]位置不对应"); return false; }
		if(vecLine[6]!="script"){Ex.Logger.Log("CgAnimation.csv中字段[script]位置不对应"); return false; }
		if(vecLine[7]!="teleport_map"){Ex.Logger.Log("CgAnimation.csv中字段[teleport_map]位置不对应"); return false; }
		if(vecLine[8]!="teleport_list"){Ex.Logger.Log("CgAnimation.csv中字段[teleport_list]位置不对应"); return false; }
		if(vecLine[9]!="binding_monster_id"){Ex.Logger.Log("CgAnimation.csv中字段[binding_monster_id]位置不对应"); return false; }
		if(vecLine[10]!="time_before_skip"){Ex.Logger.Log("CgAnimation.csv中字段[time_before_skip]位置不对应"); return false; }
		if(vecLine[11]!="Type"){Ex.Logger.Log("CgAnimation.csv中字段[Type]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			CgAnimationElement member = new CgAnimationElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.animation_name=vecLine[2];
			member.path_name=vecLine[3];
			member.duration=Convert.ToInt32(vecLine[4]);
			member.can_skip=Convert.ToInt32(vecLine[5]);
			member.script=vecLine[6];
			member.teleport_map=Convert.ToInt32(vecLine[7]);
			member.teleport_list=vecLine[8];
			member.binding_monster_id=Convert.ToInt32(vecLine[9]);
			member.time_before_skip=Convert.ToInt32(vecLine[10]);
			member.Type=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
