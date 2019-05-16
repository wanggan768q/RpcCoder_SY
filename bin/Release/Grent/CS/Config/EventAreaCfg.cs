using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//事件区域表配置数据类
public class EventAreaElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public li location_point_list;	//该区域的位置集合	此处填写4个路点位置，该事件区域通过这4个路点的位置来生成，该4个路点必须在同一个地图内,如果是圆，只填一个中心点
	public int area_type;        	//区域类型	0:多边形（最多六边，必须凸多边形）1:圆
	public float radius;         	//圆的半径	
	public int quest_id;         	//绑定任务id	所需的任务ID，只有当玩家拥有该任务以及符合下面的quest_step的条件时，该事件才会起作用。如果为0则代表没有任务限制
	public int quest_state;      	//任务状态	0：代表没有限制 1：为任务接受后，完成前可触发 2：为任务完成后可触发 
	public int switchType;       	//开关类型	1：场景加载时就打开 2：默认关闭
	public int event_type;       	//出生类型	1为副本型：该类型事件只能触发一次，副本重置后会消除该限制 2队伍型：该类型事件可反复触发，且只能由队长触发 3. 单人型：该类型事件可反复触发，没有队长和队员的限制 
	public li entry_buff_add;    	//进入时附加的buff	进入该区域后给玩家上的buff和持续时间 buffID|buffDuration
	public int leave_buff_remove;	//离开时删除的buff	离开该区域后删除玩家身上的buff buffID
	public int entry_mirror_id;  	//进入该区域后是否自动切换到镜像的ID	0为不切换
	public int leave_mirror_id;  	//离开该区域后是否脱离镜像（如果之前在镜像中）	1为脱离 2为不脱离 0为缺省
	public int cg_id;            	//需要播放的cg动画	需要播放的cg动画
	public string music;         	//所改变的背景音乐	所改变的背景音乐
	public string teleport_id;   	//所传送到的路点	所传送到的路点
	public int is_wall;          	//是否为物理墙（火墙），玩家无法穿过该区域	1为火墙 2为不是火墙
	public string script;        	//脚本路径	脚本路径
	public li quest_accept;      	//可接任务	区域内可能触发的任务,0为没有

	public bool IsValidate = false;
	public EventAreaElement()
	{
		id = -1;
	}
};

//事件区域表配置封装类
public class EventAreaTable
{

	private EventAreaTable()
	{
		m_mapElements = new Dictionary<int, EventAreaElement>();
		m_emptyItem = new EventAreaElement();
		m_vecAllElements = new List<EventAreaElement>();
	}
	private Dictionary<int, EventAreaElement> m_mapElements = null;
	private List<EventAreaElement>	m_vecAllElements = null;
	private EventAreaElement m_emptyItem = null;
	private static EventAreaTable sInstance = null;

	public static EventAreaTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EventAreaTable();
			return sInstance;
		}
	}

	public EventAreaElement GetElement(int key)
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

  public List<EventAreaElement> GetAllElement(Predicate<EventAreaElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EventArea.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EventArea.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EventArea.bin]未找到");
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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("EventArea.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EventArea.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EventArea.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="location_point_list"){Ex.Logger.Log("EventArea.csv中字段[location_point_list]位置不对应"); return false; }
		if(vecLine[3]!="area_type"){Ex.Logger.Log("EventArea.csv中字段[area_type]位置不对应"); return false; }
		if(vecLine[4]!="radius"){Ex.Logger.Log("EventArea.csv中字段[radius]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("EventArea.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[6]!="quest_state"){Ex.Logger.Log("EventArea.csv中字段[quest_state]位置不对应"); return false; }
		if(vecLine[7]!="switchType"){Ex.Logger.Log("EventArea.csv中字段[switchType]位置不对应"); return false; }
		if(vecLine[8]!="event_type"){Ex.Logger.Log("EventArea.csv中字段[event_type]位置不对应"); return false; }
		if(vecLine[9]!="entry_buff_add"){Ex.Logger.Log("EventArea.csv中字段[entry_buff_add]位置不对应"); return false; }
		if(vecLine[10]!="leave_buff_remove"){Ex.Logger.Log("EventArea.csv中字段[leave_buff_remove]位置不对应"); return false; }
		if(vecLine[11]!="entry_mirror_id"){Ex.Logger.Log("EventArea.csv中字段[entry_mirror_id]位置不对应"); return false; }
		if(vecLine[12]!="leave_mirror_id"){Ex.Logger.Log("EventArea.csv中字段[leave_mirror_id]位置不对应"); return false; }
		if(vecLine[13]!="cg_id"){Ex.Logger.Log("EventArea.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[14]!="music"){Ex.Logger.Log("EventArea.csv中字段[music]位置不对应"); return false; }
		if(vecLine[15]!="teleport_id"){Ex.Logger.Log("EventArea.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[16]!="is_wall"){Ex.Logger.Log("EventArea.csv中字段[is_wall]位置不对应"); return false; }
		if(vecLine[17]!="script"){Ex.Logger.Log("EventArea.csv中字段[script]位置不对应"); return false; }
		if(vecLine[18]!="quest_accept"){Ex.Logger.Log("EventArea.csv中字段[quest_accept]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EventAreaElement member = new EventAreaElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.location_point_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.area_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.radius);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_state );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.switchType );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.event_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.entry_buff_add);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_buff_remove );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.entry_mirror_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_mirror_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cg_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleport_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_wall );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadString( binContent, readPos, out member.quest_accept);

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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("EventArea.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EventArea.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EventArea.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="location_point_list"){Ex.Logger.Log("EventArea.csv中字段[location_point_list]位置不对应"); return false; }
		if(vecLine[3]!="area_type"){Ex.Logger.Log("EventArea.csv中字段[area_type]位置不对应"); return false; }
		if(vecLine[4]!="radius"){Ex.Logger.Log("EventArea.csv中字段[radius]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("EventArea.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[6]!="quest_state"){Ex.Logger.Log("EventArea.csv中字段[quest_state]位置不对应"); return false; }
		if(vecLine[7]!="switchType"){Ex.Logger.Log("EventArea.csv中字段[switchType]位置不对应"); return false; }
		if(vecLine[8]!="event_type"){Ex.Logger.Log("EventArea.csv中字段[event_type]位置不对应"); return false; }
		if(vecLine[9]!="entry_buff_add"){Ex.Logger.Log("EventArea.csv中字段[entry_buff_add]位置不对应"); return false; }
		if(vecLine[10]!="leave_buff_remove"){Ex.Logger.Log("EventArea.csv中字段[leave_buff_remove]位置不对应"); return false; }
		if(vecLine[11]!="entry_mirror_id"){Ex.Logger.Log("EventArea.csv中字段[entry_mirror_id]位置不对应"); return false; }
		if(vecLine[12]!="leave_mirror_id"){Ex.Logger.Log("EventArea.csv中字段[leave_mirror_id]位置不对应"); return false; }
		if(vecLine[13]!="cg_id"){Ex.Logger.Log("EventArea.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[14]!="music"){Ex.Logger.Log("EventArea.csv中字段[music]位置不对应"); return false; }
		if(vecLine[15]!="teleport_id"){Ex.Logger.Log("EventArea.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[16]!="is_wall"){Ex.Logger.Log("EventArea.csv中字段[is_wall]位置不对应"); return false; }
		if(vecLine[17]!="script"){Ex.Logger.Log("EventArea.csv中字段[script]位置不对应"); return false; }
		if(vecLine[18]!="quest_accept"){Ex.Logger.Log("EventArea.csv中字段[quest_accept]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)19)
			{
				return false;
			}
			EventAreaElement member = new EventAreaElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.location_point_list=vecLine[2];
			member.area_type=Convert.ToInt32(vecLine[3]);
			member.radius=Convert.ToSingle(vecLine[4]);
			member.quest_id=Convert.ToInt32(vecLine[5]);
			member.quest_state=Convert.ToInt32(vecLine[6]);
			member.switchType=Convert.ToInt32(vecLine[7]);
			member.event_type=Convert.ToInt32(vecLine[8]);
			member.entry_buff_add=vecLine[9];
			member.leave_buff_remove=Convert.ToInt32(vecLine[10]);
			member.entry_mirror_id=Convert.ToInt32(vecLine[11]);
			member.leave_mirror_id=Convert.ToInt32(vecLine[12]);
			member.cg_id=Convert.ToInt32(vecLine[13]);
			member.music=vecLine[14];
			member.teleport_id=vecLine[15];
			member.is_wall=Convert.ToInt32(vecLine[16]);
			member.script=vecLine[17];
			member.quest_accept=vecLine[18];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
