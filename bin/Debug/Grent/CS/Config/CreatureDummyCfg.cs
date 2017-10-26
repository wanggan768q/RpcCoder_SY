using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//多NPC巡逻盒子表配置数据类
public class CreatureDummyElement
{
	public int dummy_id;         	//序号	序号
	public int spawn_map_id;     	//dummy所在的场景ID	dummy所在的场景ID
	public float spawn_x;        	//NPC所处的场景的X坐标	NPC所处的场景的X坐标
	public float spawn_y;        	//NPC所处的场景的Y坐标	NPC所处的场景的Y坐标
	public float spawn_z;        	//路点所处的场景的Z坐标	路点所处的场景的Z坐标
	public float move_speed;     	//dummy的移动速度	dummy的移动速度
	public int attached_npc_01;  	//所附带的NPC ID	所附带的NPC ID
	public int attached_npc_02;  	//所附带的NPC ID	所附带的NPC ID
	public int attached_npc_03;  	//所附带的NPC ID	所附带的NPC ID
	public int attached_npc_04;  	//所附带的NPC ID	所附带的NPC ID
	public int attached_npc_05;  	//所附带的NPC ID	所附带的NPC ID
	public int waypoint_start;   	//dummy的出生路点	dummy的出生路点

	public bool IsValidate = false;
	public CreatureDummyElement()
	{
		dummy_id = -1;
	}
};

//多NPC巡逻盒子表配置封装类
public class CreatureDummyTable
{

	private CreatureDummyTable()
	{
		m_mapElements = new Dictionary<int, CreatureDummyElement>();
		m_emptyItem = new CreatureDummyElement();
		m_vecAllElements = new List<CreatureDummyElement>();
	}
	private Dictionary<int, CreatureDummyElement> m_mapElements = null;
	private List<CreatureDummyElement>	m_vecAllElements = null;
	private CreatureDummyElement m_emptyItem = null;
	private static CreatureDummyTable sInstance = null;

	public static CreatureDummyTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureDummyTable();
			return sInstance;
		}
	}

	public CreatureDummyElement GetElement(int key)
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

  public List<CreatureDummyElement> GetAllElement(Predicate<CreatureDummyElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureDummy.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureDummy.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureDummy.bin]未找到");
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
			Ex.Logger.Log("CreatureDummy.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="dummy_id"){Ex.Logger.Log("CreatureDummy.csv中字段[dummy_id]位置不对应"); return false; }
		if(vecLine[1]!="spawn_map_id"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_map_id]位置不对应"); return false; }
		if(vecLine[2]!="spawn_x"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[3]!="spawn_y"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[4]!="spawn_z"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[5]!="move_speed"){Ex.Logger.Log("CreatureDummy.csv中字段[move_speed]位置不对应"); return false; }
		if(vecLine[6]!="attached_npc_01"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_01]位置不对应"); return false; }
		if(vecLine[7]!="attached_npc_02"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_02]位置不对应"); return false; }
		if(vecLine[8]!="attached_npc_03"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_03]位置不对应"); return false; }
		if(vecLine[9]!="attached_npc_04"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_04]位置不对应"); return false; }
		if(vecLine[10]!="attached_npc_05"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_05]位置不对应"); return false; }
		if(vecLine[11]!="waypoint_start"){Ex.Logger.Log("CreatureDummy.csv中字段[waypoint_start]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureDummyElement member = new CreatureDummyElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dummy_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spawn_map_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_y);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.spawn_z);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.move_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attached_npc_01 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attached_npc_02 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attached_npc_03 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attached_npc_04 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attached_npc_05 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.waypoint_start );

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.dummy_id] = member;
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
			Ex.Logger.Log("CreatureDummy.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="dummy_id"){Ex.Logger.Log("CreatureDummy.csv中字段[dummy_id]位置不对应"); return false; }
		if(vecLine[1]!="spawn_map_id"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_map_id]位置不对应"); return false; }
		if(vecLine[2]!="spawn_x"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_x]位置不对应"); return false; }
		if(vecLine[3]!="spawn_y"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_y]位置不对应"); return false; }
		if(vecLine[4]!="spawn_z"){Ex.Logger.Log("CreatureDummy.csv中字段[spawn_z]位置不对应"); return false; }
		if(vecLine[5]!="move_speed"){Ex.Logger.Log("CreatureDummy.csv中字段[move_speed]位置不对应"); return false; }
		if(vecLine[6]!="attached_npc_01"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_01]位置不对应"); return false; }
		if(vecLine[7]!="attached_npc_02"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_02]位置不对应"); return false; }
		if(vecLine[8]!="attached_npc_03"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_03]位置不对应"); return false; }
		if(vecLine[9]!="attached_npc_04"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_04]位置不对应"); return false; }
		if(vecLine[10]!="attached_npc_05"){Ex.Logger.Log("CreatureDummy.csv中字段[attached_npc_05]位置不对应"); return false; }
		if(vecLine[11]!="waypoint_start"){Ex.Logger.Log("CreatureDummy.csv中字段[waypoint_start]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			CreatureDummyElement member = new CreatureDummyElement();
			member.dummy_id=Convert.ToInt32(vecLine[0]);
			member.spawn_map_id=Convert.ToInt32(vecLine[1]);
			member.spawn_x=Convert.ToSingle(vecLine[2]);
			member.spawn_y=Convert.ToSingle(vecLine[3]);
			member.spawn_z=Convert.ToSingle(vecLine[4]);
			member.move_speed=Convert.ToSingle(vecLine[5]);
			member.attached_npc_01=Convert.ToInt32(vecLine[6]);
			member.attached_npc_02=Convert.ToInt32(vecLine[7]);
			member.attached_npc_03=Convert.ToInt32(vecLine[8]);
			member.attached_npc_04=Convert.ToInt32(vecLine[9]);
			member.attached_npc_05=Convert.ToInt32(vecLine[10]);
			member.waypoint_start=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.dummy_id] = member;
		}
		return true;
	}
};
