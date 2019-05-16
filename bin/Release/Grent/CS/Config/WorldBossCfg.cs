using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//野外首领配置数据类
public class WorldBossElement
{
	public int id;               	//	
	public int creature_id;      	//NPCid	
	public string comment;       	//备注	
	public string boss_icon;     	//首领图标路径	圆形小图标
	public li boss_level_range;  	//boss的等级区间	所在地图等级区间 min|max
	public int boss_spawn_id;    	//boss的出生ID	boss的出生ID
	public li player_level_range;	//获得奖励的等级区间	min|max
	public int birth_area_name_id;	//出生地点文本ID	
	public int boss_discrible_id;	//描述文本ID	
	public int boss_disappear_time;	//首领删除时长	秒
	public li boss_refresh_time; 	//每日刷新时间	每日首次刷新时间 hh|mm|ss
	public int refresh_interval; 	//刷新间隔	每次刷新的时间间隔 单位min
	public int refresh_times;    	//刷新次数	每天刷新次数
	public int birth_waypoint_id;	//出生路点id	
	public li player_waypoint_range;	//圆环寻路点区域半径	min|max （单位m）
	public li reward_attend;     	//参与奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public li display_attend;    	//参与奖显示	道具显示
	public li reward_final;      	//最后一击奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public li display_final;     	//最后一击奖显示	道具显示
	public li reward_highest_damage;	//最高伤害奖掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public li display_highest_damage;	//最高伤害奖显示	道具显示
	public li rank_1_range;      	//第1阶梯排名范围	min|max
	public li reward_rank1;      	//第1阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public li rank_2_range;      	//第2阶梯排名范围	min|max
	public li reward_rank2;      	//第2阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public li rank_3_range;      	//第3阶梯排名范围	min|max
	public li reward_rank3;      	//第3阶梯奖励掉落	归属|计算方式|掉落包id （归属类型：0个人；1组队） （掉落计算：1概率；2权值）
	public int leaderboardindexid;	//对应排行榜索引表Id	关联排行榜索引表Id

	public bool IsValidate = false;
	public WorldBossElement()
	{
		id = -1;
	}
};

//野外首领配置封装类
public class WorldBossTable
{

	private WorldBossTable()
	{
		m_mapElements = new Dictionary<int, WorldBossElement>();
		m_emptyItem = new WorldBossElement();
		m_vecAllElements = new List<WorldBossElement>();
	}
	private Dictionary<int, WorldBossElement> m_mapElements = null;
	private List<WorldBossElement>	m_vecAllElements = null;
	private WorldBossElement m_emptyItem = null;
	private static WorldBossTable sInstance = null;

	public static WorldBossTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new WorldBossTable();
			return sInstance;
		}
	}

	public WorldBossElement GetElement(int key)
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

  public List<WorldBossElement> GetAllElement(Predicate<WorldBossElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("WorldBoss.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("WorldBoss.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[WorldBoss.bin]未找到");
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
		if(vecLine.Count != 28)
		{
			Ex.Logger.Log("WorldBoss.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("WorldBoss.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="creature_id"){Ex.Logger.Log("WorldBoss.csv中字段[creature_id]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("WorldBoss.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="boss_icon"){Ex.Logger.Log("WorldBoss.csv中字段[boss_icon]位置不对应"); return false; }
		if(vecLine[4]!="boss_level_range"){Ex.Logger.Log("WorldBoss.csv中字段[boss_level_range]位置不对应"); return false; }
		if(vecLine[5]!="boss_spawn_id"){Ex.Logger.Log("WorldBoss.csv中字段[boss_spawn_id]位置不对应"); return false; }
		if(vecLine[6]!="player_level_range"){Ex.Logger.Log("WorldBoss.csv中字段[player_level_range]位置不对应"); return false; }
		if(vecLine[7]!="birth_area_name_id"){Ex.Logger.Log("WorldBoss.csv中字段[birth_area_name_id]位置不对应"); return false; }
		if(vecLine[8]!="boss_discrible_id"){Ex.Logger.Log("WorldBoss.csv中字段[boss_discrible_id]位置不对应"); return false; }
		if(vecLine[9]!="boss_disappear_time"){Ex.Logger.Log("WorldBoss.csv中字段[boss_disappear_time]位置不对应"); return false; }
		if(vecLine[10]!="boss_refresh_time"){Ex.Logger.Log("WorldBoss.csv中字段[boss_refresh_time]位置不对应"); return false; }
		if(vecLine[11]!="refresh_interval"){Ex.Logger.Log("WorldBoss.csv中字段[refresh_interval]位置不对应"); return false; }
		if(vecLine[12]!="refresh_times"){Ex.Logger.Log("WorldBoss.csv中字段[refresh_times]位置不对应"); return false; }
		if(vecLine[13]!="birth_waypoint_id"){Ex.Logger.Log("WorldBoss.csv中字段[birth_waypoint_id]位置不对应"); return false; }
		if(vecLine[14]!="player_waypoint_range"){Ex.Logger.Log("WorldBoss.csv中字段[player_waypoint_range]位置不对应"); return false; }
		if(vecLine[15]!="reward_attend"){Ex.Logger.Log("WorldBoss.csv中字段[reward_attend]位置不对应"); return false; }
		if(vecLine[16]!="display_attend"){Ex.Logger.Log("WorldBoss.csv中字段[display_attend]位置不对应"); return false; }
		if(vecLine[17]!="reward_final"){Ex.Logger.Log("WorldBoss.csv中字段[reward_final]位置不对应"); return false; }
		if(vecLine[18]!="display_final"){Ex.Logger.Log("WorldBoss.csv中字段[display_final]位置不对应"); return false; }
		if(vecLine[19]!="reward_highest_damage"){Ex.Logger.Log("WorldBoss.csv中字段[reward_highest_damage]位置不对应"); return false; }
		if(vecLine[20]!="display_highest_damage"){Ex.Logger.Log("WorldBoss.csv中字段[display_highest_damage]位置不对应"); return false; }
		if(vecLine[21]!="rank_1_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_1_range]位置不对应"); return false; }
		if(vecLine[22]!="reward_rank1"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank1]位置不对应"); return false; }
		if(vecLine[23]!="rank_2_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_2_range]位置不对应"); return false; }
		if(vecLine[24]!="reward_rank2"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank2]位置不对应"); return false; }
		if(vecLine[25]!="rank_3_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_3_range]位置不对应"); return false; }
		if(vecLine[26]!="reward_rank3"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank3]位置不对应"); return false; }
		if(vecLine[27]!="leaderboardindexid"){Ex.Logger.Log("WorldBoss.csv中字段[leaderboardindexid]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			WorldBossElement member = new WorldBossElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_level_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.boss_spawn_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.player_level_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.birth_area_name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.boss_discrible_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.boss_disappear_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.boss_refresh_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.refresh_interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.refresh_times );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.birth_waypoint_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.player_waypoint_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_attend);
			readPos += GameAssist.ReadString( binContent, readPos, out member.display_attend);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_final);
			readPos += GameAssist.ReadString( binContent, readPos, out member.display_final);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_highest_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.display_highest_damage);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rank_1_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_rank1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rank_2_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_rank2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rank_3_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_rank3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leaderboardindexid );

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
		if(vecLine.Count != 28)
		{
			Ex.Logger.Log("WorldBoss.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("WorldBoss.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="creature_id"){Ex.Logger.Log("WorldBoss.csv中字段[creature_id]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("WorldBoss.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="boss_icon"){Ex.Logger.Log("WorldBoss.csv中字段[boss_icon]位置不对应"); return false; }
		if(vecLine[4]!="boss_level_range"){Ex.Logger.Log("WorldBoss.csv中字段[boss_level_range]位置不对应"); return false; }
		if(vecLine[5]!="boss_spawn_id"){Ex.Logger.Log("WorldBoss.csv中字段[boss_spawn_id]位置不对应"); return false; }
		if(vecLine[6]!="player_level_range"){Ex.Logger.Log("WorldBoss.csv中字段[player_level_range]位置不对应"); return false; }
		if(vecLine[7]!="birth_area_name_id"){Ex.Logger.Log("WorldBoss.csv中字段[birth_area_name_id]位置不对应"); return false; }
		if(vecLine[8]!="boss_discrible_id"){Ex.Logger.Log("WorldBoss.csv中字段[boss_discrible_id]位置不对应"); return false; }
		if(vecLine[9]!="boss_disappear_time"){Ex.Logger.Log("WorldBoss.csv中字段[boss_disappear_time]位置不对应"); return false; }
		if(vecLine[10]!="boss_refresh_time"){Ex.Logger.Log("WorldBoss.csv中字段[boss_refresh_time]位置不对应"); return false; }
		if(vecLine[11]!="refresh_interval"){Ex.Logger.Log("WorldBoss.csv中字段[refresh_interval]位置不对应"); return false; }
		if(vecLine[12]!="refresh_times"){Ex.Logger.Log("WorldBoss.csv中字段[refresh_times]位置不对应"); return false; }
		if(vecLine[13]!="birth_waypoint_id"){Ex.Logger.Log("WorldBoss.csv中字段[birth_waypoint_id]位置不对应"); return false; }
		if(vecLine[14]!="player_waypoint_range"){Ex.Logger.Log("WorldBoss.csv中字段[player_waypoint_range]位置不对应"); return false; }
		if(vecLine[15]!="reward_attend"){Ex.Logger.Log("WorldBoss.csv中字段[reward_attend]位置不对应"); return false; }
		if(vecLine[16]!="display_attend"){Ex.Logger.Log("WorldBoss.csv中字段[display_attend]位置不对应"); return false; }
		if(vecLine[17]!="reward_final"){Ex.Logger.Log("WorldBoss.csv中字段[reward_final]位置不对应"); return false; }
		if(vecLine[18]!="display_final"){Ex.Logger.Log("WorldBoss.csv中字段[display_final]位置不对应"); return false; }
		if(vecLine[19]!="reward_highest_damage"){Ex.Logger.Log("WorldBoss.csv中字段[reward_highest_damage]位置不对应"); return false; }
		if(vecLine[20]!="display_highest_damage"){Ex.Logger.Log("WorldBoss.csv中字段[display_highest_damage]位置不对应"); return false; }
		if(vecLine[21]!="rank_1_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_1_range]位置不对应"); return false; }
		if(vecLine[22]!="reward_rank1"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank1]位置不对应"); return false; }
		if(vecLine[23]!="rank_2_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_2_range]位置不对应"); return false; }
		if(vecLine[24]!="reward_rank2"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank2]位置不对应"); return false; }
		if(vecLine[25]!="rank_3_range"){Ex.Logger.Log("WorldBoss.csv中字段[rank_3_range]位置不对应"); return false; }
		if(vecLine[26]!="reward_rank3"){Ex.Logger.Log("WorldBoss.csv中字段[reward_rank3]位置不对应"); return false; }
		if(vecLine[27]!="leaderboardindexid"){Ex.Logger.Log("WorldBoss.csv中字段[leaderboardindexid]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)28)
			{
				return false;
			}
			WorldBossElement member = new WorldBossElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.creature_id=Convert.ToInt32(vecLine[1]);
			member.comment=vecLine[2];
			member.boss_icon=vecLine[3];
			member.boss_level_range=vecLine[4];
			member.boss_spawn_id=Convert.ToInt32(vecLine[5]);
			member.player_level_range=vecLine[6];
			member.birth_area_name_id=Convert.ToInt32(vecLine[7]);
			member.boss_discrible_id=Convert.ToInt32(vecLine[8]);
			member.boss_disappear_time=Convert.ToInt32(vecLine[9]);
			member.boss_refresh_time=vecLine[10];
			member.refresh_interval=Convert.ToInt32(vecLine[11]);
			member.refresh_times=Convert.ToInt32(vecLine[12]);
			member.birth_waypoint_id=Convert.ToInt32(vecLine[13]);
			member.player_waypoint_range=vecLine[14];
			member.reward_attend=vecLine[15];
			member.display_attend=vecLine[16];
			member.reward_final=vecLine[17];
			member.display_final=vecLine[18];
			member.reward_highest_damage=vecLine[19];
			member.display_highest_damage=vecLine[20];
			member.rank_1_range=vecLine[21];
			member.reward_rank1=vecLine[22];
			member.rank_2_range=vecLine[23];
			member.reward_rank2=vecLine[24];
			member.rank_3_range=vecLine[25];
			member.reward_rank3=vecLine[26];
			member.leaderboardindexid=Convert.ToInt32(vecLine[27]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
