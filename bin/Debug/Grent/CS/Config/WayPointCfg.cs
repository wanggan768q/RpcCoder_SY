using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//路点表配置数据类
public class WayPointElement
{
	public int waypoint_id;      	//路点ID	路点ID
	public string Comment;       	//	
	public int  spawn_map_id;    	//路点所在的场景号	路点所在的场景号
	public float spawn_x;        	//路点所处的场景的X坐标	路点所处的场景的X坐标
	public float spawn_y;        	//路点所处的场景的Y坐标	路点所处的场景的Y坐标
	public float spawn_z;        	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	public int waypoint_next_id; 	//下一个路点ID	下一个路点ID
	public string waypoint_animation;	//到达路点后播放的动画路径	到达路点后播放的动画路径
	public int waypoint_delay;   	//到达路点后停留的时间	到达路点后停留的时间

	public bool IsValidate = false;
	public WayPointElement()
	{
		waypoint_id = -1;
	}
};

//路点表配置封装类
public class WayPointTable
{

	private WayPointTable()
	{
		m_mapElements = new Dictionary<int, WayPointElement>();
		m_emptyItem = new WayPointElement();
		m_vecAllElements = new List<WayPointElement>();
	}
	private Dictionary<int, WayPointElement> m_mapElements = null;
	private List<WayPointElement>	m_vecAllElements = null;
	private WayPointElement m_emptyItem = null;
	private static WayPointTable sInstance = null;

	public static WayPointTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new WayPointTable();
			return sInstance;
		}
	}

	public WayPointElement GetElement(int key)
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

  public List<WayPointElement> GetAllElement(Predicate<WayPointElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("WayPoint.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("WayPoint.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[WayPoint.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("WayPoint.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="waypoint_id"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[1]!="Comment"){Ex.Logger.Log("WayPoint.csv中字段[Comment]位置不对应"); return false; }
		if(vecLine[2]!=" spawn_map_id"){Ex.Logger.Log("WayPoint.csv中字段[ spawn_map_id]位置不对应"); return false; }
		if(vecLine[3]!="spawn_x"){Ex.Logger.Log("WayPoint.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[4]!="spawn_y"){Ex.Logger.Log("WayPoint.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[5]!="spawn_z"){Ex.Logger.Log("WayPoint.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[6]!="waypoint_next_id"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_next_id]位置不对应"); return false; }
		if(vecLine[7]!="waypoint_animation"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_animation]位置不对应"); return false; }
		if(vecLine[8]!="waypoint_delay"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_delay]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			WayPointElement member = new WayPointElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.Comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member. spawn_map_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_y);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_z);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_next_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_animation);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_delay );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.waypoint_id] = member;
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("WayPoint.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="waypoint_id"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[1]!="Comment"){Ex.Logger.Log("WayPoint.csv中字段[Comment]位置不对应"); return false; }
		if(vecLine[2]!=" spawn_map_id"){Ex.Logger.Log("WayPoint.csv中字段[ spawn_map_id]位置不对应"); return false; }
		if(vecLine[3]!="spawn_x"){Ex.Logger.Log("WayPoint.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[4]!="spawn_y"){Ex.Logger.Log("WayPoint.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[5]!="spawn_z"){Ex.Logger.Log("WayPoint.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[6]!="waypoint_next_id"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_next_id]位置不对应"); return false; }
		if(vecLine[7]!="waypoint_animation"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_animation]位置不对应"); return false; }
		if(vecLine[8]!="waypoint_delay"){Ex.Logger.Log("WayPoint.csv中字段[waypoint_delay]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			WayPointElement member = new WayPointElement();
			member.waypoint_id=Convert.ToInt32(vecLine[0]);
			member.Comment=vecLine[1];
			member. spawn_map_id=Convert.ToInt32(vecLine[2]);
			member.spawn_x=Convert.ToSingle(vecLine[3]);
			member.spawn_y=Convert.ToSingle(vecLine[4]);
			member.spawn_z=Convert.ToSingle(vecLine[5]);
			member.waypoint_next_id=Convert.ToInt32(vecLine[6]);
			member.waypoint_animation=vecLine[7];
			member.waypoint_delay=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.waypoint_id] = member;
		}
		return true;
	}
};
