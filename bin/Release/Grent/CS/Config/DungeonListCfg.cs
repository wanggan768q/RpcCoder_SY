using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//副本查找器地下城手册配置数据类
public class DungeonListElement
{
	public int id;               	//序号	序号
	public string comment;       	//策划用	备注
	public int dungeon_type;     	//副本类型	1=5人 2=10人
	public int dungeon_name;     	//副本名	string_id
	public int unlock_lv;        	//解锁等级	整数
	public int kill_refresh;     	//击杀次数刷新时间	1=每日刷新 7=每周刷新
	public int single_id;        	//单人难度id	填写ID
	public li single_bossid;     	//单人bossid	填写副本表bossid
	public li single_number;     	//单人boss挑战次数	填写每日获得奖励次数
	public li single_rewards;    	//单人难度奖励	展示道具id
	public int normal_id;        	//普通难度id	填写ID
	public li normal_bossid;     	//普通bossid	填写副本表bossid
	public li normal_number;     	//普通boss挑战次数	填写每日获得奖励次数
	public li normal_rewards;    	//普通难度奖励	展示道具id
	public int hero_id;          	//英雄难度id	填写ID
	public li hero_bossid;       	//英雄bossid	填写副本表bossid
	public li hero_number;       	//英雄boss挑战次数	填写每日获得奖励次数
	public li hero_rewards;      	//英雄难度奖励	展示道具id
	public string map_pic;       	//地图图片	填写图片名
	public li boss1_single;      	//boss1单人模式奖励展示	展示道具id
	public li boss1_normal;      	//boss1普通模式奖励展示	展示道具id
	public li boss1_hero;        	//boss1英雄模式奖励展示	展示道具id
	public li boss2_single;      	//boss2单人模式奖励展示	展示道具id
	public li boss2_normal;      	//boss2普通模式奖励展示	展示道具id
	public li boss2_hero;        	//boss2英雄模式奖励展示	展示道具id

	public bool IsValidate = false;
	public DungeonListElement()
	{
		id = -1;
	}
};

//副本查找器地下城手册配置封装类
public class DungeonListTable
{

	private DungeonListTable()
	{
		m_mapElements = new Dictionary<int, DungeonListElement>();
		m_emptyItem = new DungeonListElement();
		m_vecAllElements = new List<DungeonListElement>();
	}
	private Dictionary<int, DungeonListElement> m_mapElements = null;
	private List<DungeonListElement>	m_vecAllElements = null;
	private DungeonListElement m_emptyItem = null;
	private static DungeonListTable sInstance = null;

	public static DungeonListTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new DungeonListTable();
			return sInstance;
		}
	}

	public DungeonListElement GetElement(int key)
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

  public List<DungeonListElement> GetAllElement(Predicate<DungeonListElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("DungeonList.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("DungeonList.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[DungeonList.bin]未找到");
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
		if(vecLine.Count != 25)
		{
			Ex.Logger.Log("DungeonList.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DungeonList.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("DungeonList.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="dungeon_type"){Ex.Logger.Log("DungeonList.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_name"){Ex.Logger.Log("DungeonList.csv中字段[dungeon_name]位置不对应"); return false; }
		if(vecLine[4]!="unlock_lv"){Ex.Logger.Log("DungeonList.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[5]!="kill_refresh"){Ex.Logger.Log("DungeonList.csv中字段[kill_refresh]位置不对应"); return false; }
		if(vecLine[6]!="single_id"){Ex.Logger.Log("DungeonList.csv中字段[single_id]位置不对应"); return false; }
		if(vecLine[7]!="single_bossid"){Ex.Logger.Log("DungeonList.csv中字段[single_bossid]位置不对应"); return false; }
		if(vecLine[8]!="single_number"){Ex.Logger.Log("DungeonList.csv中字段[single_number]位置不对应"); return false; }
		if(vecLine[9]!="single_rewards"){Ex.Logger.Log("DungeonList.csv中字段[single_rewards]位置不对应"); return false; }
		if(vecLine[10]!="normal_id"){Ex.Logger.Log("DungeonList.csv中字段[normal_id]位置不对应"); return false; }
		if(vecLine[11]!="normal_bossid"){Ex.Logger.Log("DungeonList.csv中字段[normal_bossid]位置不对应"); return false; }
		if(vecLine[12]!="normal_number"){Ex.Logger.Log("DungeonList.csv中字段[normal_number]位置不对应"); return false; }
		if(vecLine[13]!="normal_rewards"){Ex.Logger.Log("DungeonList.csv中字段[normal_rewards]位置不对应"); return false; }
		if(vecLine[14]!="hero_id"){Ex.Logger.Log("DungeonList.csv中字段[hero_id]位置不对应"); return false; }
		if(vecLine[15]!="hero_bossid"){Ex.Logger.Log("DungeonList.csv中字段[hero_bossid]位置不对应"); return false; }
		if(vecLine[16]!="hero_number"){Ex.Logger.Log("DungeonList.csv中字段[hero_number]位置不对应"); return false; }
		if(vecLine[17]!="hero_rewards"){Ex.Logger.Log("DungeonList.csv中字段[hero_rewards]位置不对应"); return false; }
		if(vecLine[18]!="map_pic"){Ex.Logger.Log("DungeonList.csv中字段[map_pic]位置不对应"); return false; }
		if(vecLine[19]!="boss1_single"){Ex.Logger.Log("DungeonList.csv中字段[boss1_single]位置不对应"); return false; }
		if(vecLine[20]!="boss1_normal"){Ex.Logger.Log("DungeonList.csv中字段[boss1_normal]位置不对应"); return false; }
		if(vecLine[21]!="boss1_hero"){Ex.Logger.Log("DungeonList.csv中字段[boss1_hero]位置不对应"); return false; }
		if(vecLine[22]!="boss2_single"){Ex.Logger.Log("DungeonList.csv中字段[boss2_single]位置不对应"); return false; }
		if(vecLine[23]!="boss2_normal"){Ex.Logger.Log("DungeonList.csv中字段[boss2_normal]位置不对应"); return false; }
		if(vecLine[24]!="boss2_hero"){Ex.Logger.Log("DungeonList.csv中字段[boss2_hero]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DungeonListElement member = new DungeonListElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.kill_refresh );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.single_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.single_bossid);
			readPos += GameAssist.ReadString( binContent, readPos, out member.single_number);
			readPos += GameAssist.ReadString( binContent, readPos, out member.single_rewards);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.normal_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.normal_bossid);
			readPos += GameAssist.ReadString( binContent, readPos, out member.normal_number);
			readPos += GameAssist.ReadString( binContent, readPos, out member.normal_rewards);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hero_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.hero_bossid);
			readPos += GameAssist.ReadString( binContent, readPos, out member.hero_number);
			readPos += GameAssist.ReadString( binContent, readPos, out member.hero_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_pic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss1_single);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss1_normal);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss1_hero);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss2_single);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss2_normal);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss2_hero);

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
		if(vecLine.Count != 25)
		{
			Ex.Logger.Log("DungeonList.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DungeonList.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("DungeonList.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="dungeon_type"){Ex.Logger.Log("DungeonList.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[3]!="dungeon_name"){Ex.Logger.Log("DungeonList.csv中字段[dungeon_name]位置不对应"); return false; }
		if(vecLine[4]!="unlock_lv"){Ex.Logger.Log("DungeonList.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[5]!="kill_refresh"){Ex.Logger.Log("DungeonList.csv中字段[kill_refresh]位置不对应"); return false; }
		if(vecLine[6]!="single_id"){Ex.Logger.Log("DungeonList.csv中字段[single_id]位置不对应"); return false; }
		if(vecLine[7]!="single_bossid"){Ex.Logger.Log("DungeonList.csv中字段[single_bossid]位置不对应"); return false; }
		if(vecLine[8]!="single_number"){Ex.Logger.Log("DungeonList.csv中字段[single_number]位置不对应"); return false; }
		if(vecLine[9]!="single_rewards"){Ex.Logger.Log("DungeonList.csv中字段[single_rewards]位置不对应"); return false; }
		if(vecLine[10]!="normal_id"){Ex.Logger.Log("DungeonList.csv中字段[normal_id]位置不对应"); return false; }
		if(vecLine[11]!="normal_bossid"){Ex.Logger.Log("DungeonList.csv中字段[normal_bossid]位置不对应"); return false; }
		if(vecLine[12]!="normal_number"){Ex.Logger.Log("DungeonList.csv中字段[normal_number]位置不对应"); return false; }
		if(vecLine[13]!="normal_rewards"){Ex.Logger.Log("DungeonList.csv中字段[normal_rewards]位置不对应"); return false; }
		if(vecLine[14]!="hero_id"){Ex.Logger.Log("DungeonList.csv中字段[hero_id]位置不对应"); return false; }
		if(vecLine[15]!="hero_bossid"){Ex.Logger.Log("DungeonList.csv中字段[hero_bossid]位置不对应"); return false; }
		if(vecLine[16]!="hero_number"){Ex.Logger.Log("DungeonList.csv中字段[hero_number]位置不对应"); return false; }
		if(vecLine[17]!="hero_rewards"){Ex.Logger.Log("DungeonList.csv中字段[hero_rewards]位置不对应"); return false; }
		if(vecLine[18]!="map_pic"){Ex.Logger.Log("DungeonList.csv中字段[map_pic]位置不对应"); return false; }
		if(vecLine[19]!="boss1_single"){Ex.Logger.Log("DungeonList.csv中字段[boss1_single]位置不对应"); return false; }
		if(vecLine[20]!="boss1_normal"){Ex.Logger.Log("DungeonList.csv中字段[boss1_normal]位置不对应"); return false; }
		if(vecLine[21]!="boss1_hero"){Ex.Logger.Log("DungeonList.csv中字段[boss1_hero]位置不对应"); return false; }
		if(vecLine[22]!="boss2_single"){Ex.Logger.Log("DungeonList.csv中字段[boss2_single]位置不对应"); return false; }
		if(vecLine[23]!="boss2_normal"){Ex.Logger.Log("DungeonList.csv中字段[boss2_normal]位置不对应"); return false; }
		if(vecLine[24]!="boss2_hero"){Ex.Logger.Log("DungeonList.csv中字段[boss2_hero]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)25)
			{
				return false;
			}
			DungeonListElement member = new DungeonListElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.dungeon_type=Convert.ToInt32(vecLine[2]);
			member.dungeon_name=Convert.ToInt32(vecLine[3]);
			member.unlock_lv=Convert.ToInt32(vecLine[4]);
			member.kill_refresh=Convert.ToInt32(vecLine[5]);
			member.single_id=Convert.ToInt32(vecLine[6]);
			member.single_bossid=vecLine[7];
			member.single_number=vecLine[8];
			member.single_rewards=vecLine[9];
			member.normal_id=Convert.ToInt32(vecLine[10]);
			member.normal_bossid=vecLine[11];
			member.normal_number=vecLine[12];
			member.normal_rewards=vecLine[13];
			member.hero_id=Convert.ToInt32(vecLine[14]);
			member.hero_bossid=vecLine[15];
			member.hero_number=vecLine[16];
			member.hero_rewards=vecLine[17];
			member.map_pic=vecLine[18];
			member.boss1_single=vecLine[19];
			member.boss1_normal=vecLine[20];
			member.boss1_hero=vecLine[21];
			member.boss2_single=vecLine[22];
			member.boss2_normal=vecLine[23];
			member.boss2_hero=vecLine[24];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
