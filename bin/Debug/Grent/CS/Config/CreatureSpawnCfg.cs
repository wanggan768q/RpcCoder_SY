using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC位置表配置数据类
public class CreatureSpawnElement
{
	public int id;               	//序号	序号
	public int npc_entry_id;     	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	public int spawn_map_id;     	//NPC所处的场景号	NPC所处的场景号
	public float spawn_x;        	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	public float spawn_y;        	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	public float spawn_z;        	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	public int refresh_time;     	//NPC死亡后的刷新时间	NPC死亡后的刷新时间
	public int refresh_type;     	//NPC死亡后的刷新类型	NPC死亡后的刷新类型
	public string animation_default;	//默认动画路径	默认动画路径
	public string animation_delay;	//动画延迟时间	动画延迟时间
	public string waypoint_id;   	//该NPC的起始路点	该NPC的起始路点

	public bool IsValidate = false;
	public CreatureSpawnElement()
	{
		id = -1;
	}
};

//NPC位置表配置封装类
public class CreatureSpawnTable
{

	private CreatureSpawnTable()
	{
		m_mapElements = new Dictionary<int, CreatureSpawnElement>();
		m_emptyItem = new CreatureSpawnElement();
		m_vecAllElements = new List<CreatureSpawnElement>();
	}
	private Dictionary<int, CreatureSpawnElement> m_mapElements = null;
	private List<CreatureSpawnElement>	m_vecAllElements = null;
	private CreatureSpawnElement m_emptyItem = null;
	private static CreatureSpawnTable sInstance = null;

	public static CreatureSpawnTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureSpawnTable();
			return sInstance;
		}
	}

	public CreatureSpawnElement GetElement(int key)
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

  public List<CreatureSpawnElement> GetAllElement(Predicate<CreatureSpawnElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureSpawn.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureSpawn.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureSpawn.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("CreatureSpawn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureSpawn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="npc_entry_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[2]!="spawn_map_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_map_id]位置不对应"); return false; }
		if(vecLine[3]!="spawn_x"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[4]!="spawn_y"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[5]!="spawn_z"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[6]!="refresh_time"){Ex.Logger.Log("CreatureSpawn.csv中字段[refresh_time]位置不对应"); return false; }
		if(vecLine[7]!="refresh_type"){Ex.Logger.Log("CreatureSpawn.csv中字段[refresh_type]位置不对应"); return false; }
		if(vecLine[8]!="animation_default"){Ex.Logger.Log("CreatureSpawn.csv中字段[animation_default]位置不对应"); return false; }
		if(vecLine[9]!="animation_delay"){Ex.Logger.Log("CreatureSpawn.csv中字段[animation_delay]位置不对应"); return false; }
		if(vecLine[10]!="waypoint_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[waypoint_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureSpawnElement member = new CreatureSpawnElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_entry_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spawn_map_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_y);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_z);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.refresh_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.refresh_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.animation_default);
			readPos += GameAssist.ReadString( binContent, readPos, out member.animation_delay);
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_id);

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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("CreatureSpawn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureSpawn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="npc_entry_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[2]!="spawn_map_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_map_id]位置不对应"); return false; }
		if(vecLine[3]!="spawn_x"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[4]!="spawn_y"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[5]!="spawn_z"){Ex.Logger.Log("CreatureSpawn.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[6]!="refresh_time"){Ex.Logger.Log("CreatureSpawn.csv中字段[refresh_time]位置不对应"); return false; }
		if(vecLine[7]!="refresh_type"){Ex.Logger.Log("CreatureSpawn.csv中字段[refresh_type]位置不对应"); return false; }
		if(vecLine[8]!="animation_default"){Ex.Logger.Log("CreatureSpawn.csv中字段[animation_default]位置不对应"); return false; }
		if(vecLine[9]!="animation_delay"){Ex.Logger.Log("CreatureSpawn.csv中字段[animation_delay]位置不对应"); return false; }
		if(vecLine[10]!="waypoint_id"){Ex.Logger.Log("CreatureSpawn.csv中字段[waypoint_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			CreatureSpawnElement member = new CreatureSpawnElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.npc_entry_id=Convert.ToInt32(vecLine[1]);
			member.spawn_map_id=Convert.ToInt32(vecLine[2]);
			member.spawn_x=Convert.ToSingle(vecLine[3]);
			member.spawn_y=Convert.ToSingle(vecLine[4]);
			member.spawn_z=Convert.ToSingle(vecLine[5]);
			member.refresh_time=Convert.ToInt32(vecLine[6]);
			member.refresh_type=Convert.ToInt32(vecLine[7]);
			member.animation_default=vecLine[8];
			member.animation_delay=vecLine[9];
			member.waypoint_id=vecLine[10];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
