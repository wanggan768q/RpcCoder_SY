using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//副本表配置数据类
public class DungeonElement
{
	public int id;               	//序号	序号
	public string comment;       	//	
	public int map_id;           	//场景ID	
	public int dungeon_type;     	//副本类型	0：野外 1：副本 2：竞技场
	public int difficult;        	//难度	
	public int required_num;     	//所需玩家数量	
	public int required_last_dungeon_id;	//所需前置副本ID	
	public int reset_type;       	//重置类型	
	public int finish_amount;    	//允许玩家完成次数	
	public int name_id;          	//副本名字ID	
	public int describle_id;     	//副本描述ID	
	public string reward_boss_ui;	//boss掉落数组	
	public int First_reward_ui;  	//首通奖励礼包ID	
	public int general_reward__ui;	//非首通奖励礼包ID	
	public int is_transfer;      	//是否需要装备中转表	
	public string start_music;   	//开启音乐	
	public string loop_music;    	//循环音乐	
	public int endingboss_id;    	//最后boss ID	
	public int duration_time;    	//副本存活时间	
	public int conclusion_time;  	//副本结算时间	
	public int start_time;       	//副本开启时间	
	public int end_time;         	//副本关闭时间	

	public bool IsValidate = false;
	public DungeonElement()
	{
		id = -1;
	}
};

//副本表配置封装类
public class DungeonTable
{

	private DungeonTable()
	{
		m_mapElements = new Dictionary<int, DungeonElement>();
		m_emptyItem = new DungeonElement();
		m_vecAllElements = new List<DungeonElement>();
	}
	private Dictionary<int, DungeonElement> m_mapElements = null;
	private List<DungeonElement>	m_vecAllElements = null;
	private DungeonElement m_emptyItem = null;
	private static DungeonTable sInstance = null;

	public static DungeonTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new DungeonTable();
			return sInstance;
		}
	}

	public DungeonElement GetElement(int key)
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

  public List<DungeonElement> GetAllElement(Predicate<DungeonElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Dungeon.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Dungeon.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Dungeon.bin]未找到");
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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Dungeon.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[4]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[5]!="required_num"){Ex.Logger.Log("Dungeon.csv中字段[required_num]位置不对应"); return false; }
		if(vecLine[6]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[7]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[8]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[9]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[10]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[11]!="reward_boss_ui"){Ex.Logger.Log("Dungeon.csv中字段[reward_boss_ui]位置不对应"); return false; }
		if(vecLine[12]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[13]!="general_reward__ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[14]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[15]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[16]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[17]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[18]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[19]!="conclusion_time"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_time]位置不对应"); return false; }
		if(vecLine[20]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[21]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DungeonElement member = new DungeonElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.map_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.difficult );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_last_dungeon_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reset_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.finish_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describle_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_boss_ui);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.First_reward_ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.general_reward__ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_transfer );
			readPos += GameAssist.ReadString( binContent, readPos, out member.start_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.endingboss_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.conclusion_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.start_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.end_time );

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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("Dungeon.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Dungeon.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Dungeon.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="map_id"){Ex.Logger.Log("Dungeon.csv中字段[map_id]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_type"){Ex.Logger.Log("Dungeon.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[4]!="difficult"){Ex.Logger.Log("Dungeon.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[5]!="required_num"){Ex.Logger.Log("Dungeon.csv中字段[required_num]位置不对应"); return false; }
		if(vecLine[6]!="required_last_dungeon_id"){Ex.Logger.Log("Dungeon.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[7]!="reset_type"){Ex.Logger.Log("Dungeon.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[8]!="finish_amount"){Ex.Logger.Log("Dungeon.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[9]!="name_id"){Ex.Logger.Log("Dungeon.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[10]!="describle_id"){Ex.Logger.Log("Dungeon.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[11]!="reward_boss_ui"){Ex.Logger.Log("Dungeon.csv中字段[reward_boss_ui]位置不对应"); return false; }
		if(vecLine[12]!="First_reward_ui"){Ex.Logger.Log("Dungeon.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[13]!="general_reward__ui"){Ex.Logger.Log("Dungeon.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[14]!="is_transfer"){Ex.Logger.Log("Dungeon.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[15]!="start_music"){Ex.Logger.Log("Dungeon.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[16]!="loop_music"){Ex.Logger.Log("Dungeon.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[17]!="endingboss_id"){Ex.Logger.Log("Dungeon.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[18]!="duration_time"){Ex.Logger.Log("Dungeon.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[19]!="conclusion_time"){Ex.Logger.Log("Dungeon.csv中字段[conclusion_time]位置不对应"); return false; }
		if(vecLine[20]!="start_time"){Ex.Logger.Log("Dungeon.csv中字段[start_time]位置不对应"); return false; }
		if(vecLine[21]!="end_time"){Ex.Logger.Log("Dungeon.csv中字段[end_time]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			DungeonElement member = new DungeonElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.map_id=Convert.ToInt32(vecLine[2]);
			member.dungeon_type=Convert.ToInt32(vecLine[3]);
			member.difficult=Convert.ToInt32(vecLine[4]);
			member.required_num=Convert.ToInt32(vecLine[5]);
			member.required_last_dungeon_id=Convert.ToInt32(vecLine[6]);
			member.reset_type=Convert.ToInt32(vecLine[7]);
			member.finish_amount=Convert.ToInt32(vecLine[8]);
			member.name_id=Convert.ToInt32(vecLine[9]);
			member.describle_id=Convert.ToInt32(vecLine[10]);
			member.reward_boss_ui=vecLine[11];
			member.First_reward_ui=Convert.ToInt32(vecLine[12]);
			member.general_reward__ui=Convert.ToInt32(vecLine[13]);
			member.is_transfer=Convert.ToInt32(vecLine[14]);
			member.start_music=vecLine[15];
			member.loop_music=vecLine[16];
			member.endingboss_id=Convert.ToInt32(vecLine[17]);
			member.duration_time=Convert.ToInt32(vecLine[18]);
			member.conclusion_time=Convert.ToInt32(vecLine[19]);
			member.start_time=Convert.ToInt32(vecLine[20]);
			member.end_time=Convert.ToInt32(vecLine[21]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
