using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//匹配控制表配置数据类
public class MatchElement
{
	public int id;               	//匹配类型	对应任务组别
	public string comment;       	//匹配类型描述	
	public int per_camp_player_size;	//每个阵营多少人	
	public int per_room_camp_size;	//每个房间多少阵营	
	public int per_team_member_size;	//每个队伍多少人	
	public int is_rank;          	//是否是排位	
	public int rank_strategy;    	//0:使用匹配成直接入队
1:匹配成功创建房间	
	public int extern_section;   	//扩展段位	
	public int team_section_span;	//段位跨度(如果一个队伍段位跨度超过这个，那么则不能匹配)	
	public li sections_list;     	//段位数量	
	public int member_leave_cancel_team;	//一人退出是否取消全队匹配	
	public int profession_size;  	//职业个数,一般有一个队最好有几个不同职业,0为可以相同	
	public int custom_room;      	//可不可以创建自定义模拟房间,只能程序改该值	
	public int dungeon_configid; 	//副本id	
	public int scene_configid;   	//场景id	

	public bool IsValidate = false;
	public MatchElement()
	{
		id = -1;
	}
};

//匹配控制表配置封装类
public class MatchTable
{

	private MatchTable()
	{
		m_mapElements = new Dictionary<int, MatchElement>();
		m_emptyItem = new MatchElement();
		m_vecAllElements = new List<MatchElement>();
	}
	private Dictionary<int, MatchElement> m_mapElements = null;
	private List<MatchElement>	m_vecAllElements = null;
	private MatchElement m_emptyItem = null;
	private static MatchTable sInstance = null;

	public static MatchTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MatchTable();
			return sInstance;
		}
	}

	public MatchElement GetElement(int key)
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

  public List<MatchElement> GetAllElement(Predicate<MatchElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Match.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Match.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Match.bin]未找到");
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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Match.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Match.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Match.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="per_camp_player_size"){Ex.Logger.Log("Match.csv中字段[per_camp_player_size]位置不对应"); return false; }
		if(vecLine[3]!="per_room_camp_size"){Ex.Logger.Log("Match.csv中字段[per_room_camp_size]位置不对应"); return false; }
		if(vecLine[4]!="per_team_member_size"){Ex.Logger.Log("Match.csv中字段[per_team_member_size]位置不对应"); return false; }
		if(vecLine[5]!="is_rank"){Ex.Logger.Log("Match.csv中字段[is_rank]位置不对应"); return false; }
		if(vecLine[6]!="rank_strategy"){Ex.Logger.Log("Match.csv中字段[rank_strategy]位置不对应"); return false; }
		if(vecLine[7]!="extern_section"){Ex.Logger.Log("Match.csv中字段[extern_section]位置不对应"); return false; }
		if(vecLine[8]!="team_section_span"){Ex.Logger.Log("Match.csv中字段[team_section_span]位置不对应"); return false; }
		if(vecLine[9]!="sections_list"){Ex.Logger.Log("Match.csv中字段[sections_list]位置不对应"); return false; }
		if(vecLine[10]!="member_leave_cancel_team"){Ex.Logger.Log("Match.csv中字段[member_leave_cancel_team]位置不对应"); return false; }
		if(vecLine[11]!="profession_size"){Ex.Logger.Log("Match.csv中字段[profession_size]位置不对应"); return false; }
		if(vecLine[12]!="custom_room"){Ex.Logger.Log("Match.csv中字段[custom_room]位置不对应"); return false; }
		if(vecLine[13]!="dungeon_configid"){Ex.Logger.Log("Match.csv中字段[dungeon_configid]位置不对应"); return false; }
		if(vecLine[14]!="scene_configid"){Ex.Logger.Log("Match.csv中字段[scene_configid]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MatchElement member = new MatchElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.per_camp_player_size );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.per_room_camp_size );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.per_team_member_size );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank_strategy );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.extern_section );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.team_section_span );
			readPos += GameAssist.ReadString( binContent, readPos, out member.sections_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.member_leave_cancel_team );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_size );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.custom_room );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_configid );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_configid );

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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Match.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Match.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Match.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="per_camp_player_size"){Ex.Logger.Log("Match.csv中字段[per_camp_player_size]位置不对应"); return false; }
		if(vecLine[3]!="per_room_camp_size"){Ex.Logger.Log("Match.csv中字段[per_room_camp_size]位置不对应"); return false; }
		if(vecLine[4]!="per_team_member_size"){Ex.Logger.Log("Match.csv中字段[per_team_member_size]位置不对应"); return false; }
		if(vecLine[5]!="is_rank"){Ex.Logger.Log("Match.csv中字段[is_rank]位置不对应"); return false; }
		if(vecLine[6]!="rank_strategy"){Ex.Logger.Log("Match.csv中字段[rank_strategy]位置不对应"); return false; }
		if(vecLine[7]!="extern_section"){Ex.Logger.Log("Match.csv中字段[extern_section]位置不对应"); return false; }
		if(vecLine[8]!="team_section_span"){Ex.Logger.Log("Match.csv中字段[team_section_span]位置不对应"); return false; }
		if(vecLine[9]!="sections_list"){Ex.Logger.Log("Match.csv中字段[sections_list]位置不对应"); return false; }
		if(vecLine[10]!="member_leave_cancel_team"){Ex.Logger.Log("Match.csv中字段[member_leave_cancel_team]位置不对应"); return false; }
		if(vecLine[11]!="profession_size"){Ex.Logger.Log("Match.csv中字段[profession_size]位置不对应"); return false; }
		if(vecLine[12]!="custom_room"){Ex.Logger.Log("Match.csv中字段[custom_room]位置不对应"); return false; }
		if(vecLine[13]!="dungeon_configid"){Ex.Logger.Log("Match.csv中字段[dungeon_configid]位置不对应"); return false; }
		if(vecLine[14]!="scene_configid"){Ex.Logger.Log("Match.csv中字段[scene_configid]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)15)
			{
				return false;
			}
			MatchElement member = new MatchElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.per_camp_player_size=Convert.ToInt32(vecLine[2]);
			member.per_room_camp_size=Convert.ToInt32(vecLine[3]);
			member.per_team_member_size=Convert.ToInt32(vecLine[4]);
			member.is_rank=Convert.ToInt32(vecLine[5]);
			member.rank_strategy=Convert.ToInt32(vecLine[6]);
			member.extern_section=Convert.ToInt32(vecLine[7]);
			member.team_section_span=Convert.ToInt32(vecLine[8]);
			member.sections_list=vecLine[9];
			member.member_leave_cancel_team=Convert.ToInt32(vecLine[10]);
			member.profession_size=Convert.ToInt32(vecLine[11]);
			member.custom_room=Convert.ToInt32(vecLine[12]);
			member.dungeon_configid=Convert.ToInt32(vecLine[13]);
			member.scene_configid=Convert.ToInt32(vecLine[14]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
