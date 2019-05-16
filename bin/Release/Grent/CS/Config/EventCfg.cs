using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//事件表配置数据类
public class EventElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int quest_id;         	//绑定任务id	所需的任务ID，只有当玩家拥有该任务以及符合下面的quest_step的条件时，该事件才会起作用。如果为0则代表没有任务限制
	public int quest_state;      	//任务状态	1：为任务接受后，完成前可触发 2：为任务完成后可触发
	public int spawn_type;       	//出生类型	1：场景加载时就出现 2：为脚本刷新
	public li entry_buff_add;    	//进入时附加的buff	进入该区域后给玩家上的buff和持续时间 buffID|buffDuration
	public int leave_buff_remove;	//离开时删除的buff	离开该区域后删除玩家身上的buff buffID
	public int entry_mirror_id;  	//进入该区域后是否自动切换到镜像的ID	0为不切换
	public int leave_mirror_id;  	//离开该区域后是否脱离镜像（如果之前在镜像中）	1为脱离 2为不脱离 0为缺省
	public int cg_id;            	//需要播放的cg动画	需要播放的cg动画
	public string music;         	//所改变的背景音乐	所改变的背景音乐
	public string teleport_id;   	//所传送到的路点（会跨场景）	所传送到的路点（会跨场景）
	public int is_wall;          	//是否为物理墙（火墙），玩家无法穿过该区域	1为火墙 2为不是火墙
	public string script;        	//脚本路径	脚本路径

	public bool IsValidate = false;
	public EventElement()
	{
		id = -1;
	}
};

//事件表配置封装类
public class EventTable
{

	private EventTable()
	{
		m_mapElements = new Dictionary<int, EventElement>();
		m_emptyItem = new EventElement();
		m_vecAllElements = new List<EventElement>();
	}
	private Dictionary<int, EventElement> m_mapElements = null;
	private List<EventElement>	m_vecAllElements = null;
	private EventElement m_emptyItem = null;
	private static EventTable sInstance = null;

	public static EventTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EventTable();
			return sInstance;
		}
	}

	public EventElement GetElement(int key)
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

  public List<EventElement> GetAllElement(Predicate<EventElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Event.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Event.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Event.bin]未找到");
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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("Event.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Event.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Event.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Event.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_state"){Ex.Logger.Log("Event.csv中字段[quest_state]位置不对应"); return false; }
		if(vecLine[4]!="spawn_type"){Ex.Logger.Log("Event.csv中字段[spawn_type]位置不对应"); return false; }
		if(vecLine[5]!="entry_buff_add"){Ex.Logger.Log("Event.csv中字段[entry_buff_add]位置不对应"); return false; }
		if(vecLine[6]!="leave_buff_remove"){Ex.Logger.Log("Event.csv中字段[leave_buff_remove]位置不对应"); return false; }
		if(vecLine[7]!="entry_mirror_id"){Ex.Logger.Log("Event.csv中字段[entry_mirror_id]位置不对应"); return false; }
		if(vecLine[8]!="leave_mirror_id"){Ex.Logger.Log("Event.csv中字段[leave_mirror_id]位置不对应"); return false; }
		if(vecLine[9]!="cg_id"){Ex.Logger.Log("Event.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[10]!="music"){Ex.Logger.Log("Event.csv中字段[music]位置不对应"); return false; }
		if(vecLine[11]!="teleport_id"){Ex.Logger.Log("Event.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[12]!="is_wall"){Ex.Logger.Log("Event.csv中字段[is_wall]位置不对应"); return false; }
		if(vecLine[13]!="script"){Ex.Logger.Log("Event.csv中字段[script]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EventElement member = new EventElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_state );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spawn_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.entry_buff_add);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_buff_remove );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.entry_mirror_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_mirror_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cg_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.teleport_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_wall );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);

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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("Event.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Event.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Event.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("Event.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_state"){Ex.Logger.Log("Event.csv中字段[quest_state]位置不对应"); return false; }
		if(vecLine[4]!="spawn_type"){Ex.Logger.Log("Event.csv中字段[spawn_type]位置不对应"); return false; }
		if(vecLine[5]!="entry_buff_add"){Ex.Logger.Log("Event.csv中字段[entry_buff_add]位置不对应"); return false; }
		if(vecLine[6]!="leave_buff_remove"){Ex.Logger.Log("Event.csv中字段[leave_buff_remove]位置不对应"); return false; }
		if(vecLine[7]!="entry_mirror_id"){Ex.Logger.Log("Event.csv中字段[entry_mirror_id]位置不对应"); return false; }
		if(vecLine[8]!="leave_mirror_id"){Ex.Logger.Log("Event.csv中字段[leave_mirror_id]位置不对应"); return false; }
		if(vecLine[9]!="cg_id"){Ex.Logger.Log("Event.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[10]!="music"){Ex.Logger.Log("Event.csv中字段[music]位置不对应"); return false; }
		if(vecLine[11]!="teleport_id"){Ex.Logger.Log("Event.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[12]!="is_wall"){Ex.Logger.Log("Event.csv中字段[is_wall]位置不对应"); return false; }
		if(vecLine[13]!="script"){Ex.Logger.Log("Event.csv中字段[script]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			EventElement member = new EventElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.quest_id=Convert.ToInt32(vecLine[2]);
			member.quest_state=Convert.ToInt32(vecLine[3]);
			member.spawn_type=Convert.ToInt32(vecLine[4]);
			member.entry_buff_add=vecLine[5];
			member.leave_buff_remove=Convert.ToInt32(vecLine[6]);
			member.entry_mirror_id=Convert.ToInt32(vecLine[7]);
			member.leave_mirror_id=Convert.ToInt32(vecLine[8]);
			member.cg_id=Convert.ToInt32(vecLine[9]);
			member.music=vecLine[10];
			member.teleport_id=vecLine[11];
			member.is_wall=Convert.ToInt32(vecLine[12]);
			member.script=vecLine[13];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
