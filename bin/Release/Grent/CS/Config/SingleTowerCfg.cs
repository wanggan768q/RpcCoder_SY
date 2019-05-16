using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//单人爬塔配置数据类
public class SingleTowerElement
{
	public int id;               	//层数id	 所在层数，最小为1，为唯一值；
	public li reward_1;          	//奖励1	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li reward_2;          	//奖励2	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li reward_3;          	//奖励3	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li reward_4;          	//奖励4	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li reward_5;          	//奖励5	本层通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li first_reward_1;    	//首次通关奖励1	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li first_reward_2;    	//首次通关奖励2	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li first_reward_3;    	//首次通关奖励3	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li first_reward_4;    	//首次通关奖励4	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public li first_reward_5;    	//首次通关奖励5	本层首次通关发放的奖励，格式为：道具ID|数量，对应道具表（ItemProto_道具原型），没有则填-1；
	public int monster1_id;      	//怪物1id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster1_wave;    	//怪物1波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster1_count;   	//怪物1数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group1;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster2_id;      	//怪物2id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster2_wave;    	//怪物2波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster2_count;   	//怪物2数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group2;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster3_id;      	//怪物3id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster3_wave;    	//怪物3波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster3_count;   	//怪物3数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group3;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster4_id;      	//怪物4id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster4_wave;    	//怪物4波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster4_count;   	//怪物4数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group4;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster5_id;      	//怪物5id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster5_wave;    	//怪物5波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster5_count;   	//怪物5数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group5;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster6_id;      	//怪物6id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster6_wave;    	//怪物6波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster6_count;   	//怪物6数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group6;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster7_id;      	//怪物7id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster7_wave;    	//怪物7波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster7_count;   	//怪物7数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group7;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster8_id;      	//怪物8id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster8_wave;    	//怪物8波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster8_count;   	//怪物8数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group8;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。
	public int monster9_id;      	//怪物9id	对应总npc表（Creature_总NPC表），没有则填-1
	public int monster9_wave;    	//怪物9波数	代表本怪物是第几波刷新出来的，如果同一组的monster_id填-1，本列则无效；
	public int monster9_count;   	//怪物9数量	代表本波怪物刷新的数目，如果同一组的monster_id填-1，本列则无效
	public li waypoint_group9;   	//怪物刷新坐标组	对应WayPoint_路点表中的id，为一个数组，可以同时填多个waypoint id，用“|“分隔，本层怪物刷新点从该数组中随机抽取。

	public bool IsValidate = false;
	public SingleTowerElement()
	{
		id = -1;
	}
};

//单人爬塔配置封装类
public class SingleTowerTable
{

	private SingleTowerTable()
	{
		m_mapElements = new Dictionary<int, SingleTowerElement>();
		m_emptyItem = new SingleTowerElement();
		m_vecAllElements = new List<SingleTowerElement>();
	}
	private Dictionary<int, SingleTowerElement> m_mapElements = null;
	private List<SingleTowerElement>	m_vecAllElements = null;
	private SingleTowerElement m_emptyItem = null;
	private static SingleTowerTable sInstance = null;

	public static SingleTowerTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SingleTowerTable();
			return sInstance;
		}
	}

	public SingleTowerElement GetElement(int key)
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

  public List<SingleTowerElement> GetAllElement(Predicate<SingleTowerElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SingleTower.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SingleTower.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SingleTower.bin]未找到");
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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("SingleTower.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SingleTower.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="reward_1"){Ex.Logger.Log("SingleTower.csv中字段[reward_1]位置不对应"); return false; }
		if(vecLine[2]!="reward_2"){Ex.Logger.Log("SingleTower.csv中字段[reward_2]位置不对应"); return false; }
		if(vecLine[3]!="reward_3"){Ex.Logger.Log("SingleTower.csv中字段[reward_3]位置不对应"); return false; }
		if(vecLine[4]!="reward_4"){Ex.Logger.Log("SingleTower.csv中字段[reward_4]位置不对应"); return false; }
		if(vecLine[5]!="reward_5"){Ex.Logger.Log("SingleTower.csv中字段[reward_5]位置不对应"); return false; }
		if(vecLine[6]!="first_reward_1"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_1]位置不对应"); return false; }
		if(vecLine[7]!="first_reward_2"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_2]位置不对应"); return false; }
		if(vecLine[8]!="first_reward_3"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_3]位置不对应"); return false; }
		if(vecLine[9]!="first_reward_4"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_4]位置不对应"); return false; }
		if(vecLine[10]!="first_reward_5"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_5]位置不对应"); return false; }
		if(vecLine[11]!="monster1_id"){Ex.Logger.Log("SingleTower.csv中字段[monster1_id]位置不对应"); return false; }
		if(vecLine[12]!="monster1_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster1_wave]位置不对应"); return false; }
		if(vecLine[13]!="monster1_count"){Ex.Logger.Log("SingleTower.csv中字段[monster1_count]位置不对应"); return false; }
		if(vecLine[14]!="waypoint_group1"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group1]位置不对应"); return false; }
		if(vecLine[15]!="monster2_id"){Ex.Logger.Log("SingleTower.csv中字段[monster2_id]位置不对应"); return false; }
		if(vecLine[16]!="monster2_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster2_wave]位置不对应"); return false; }
		if(vecLine[17]!="monster2_count"){Ex.Logger.Log("SingleTower.csv中字段[monster2_count]位置不对应"); return false; }
		if(vecLine[18]!="waypoint_group2"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group2]位置不对应"); return false; }
		if(vecLine[19]!="monster3_id"){Ex.Logger.Log("SingleTower.csv中字段[monster3_id]位置不对应"); return false; }
		if(vecLine[20]!="monster3_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster3_wave]位置不对应"); return false; }
		if(vecLine[21]!="monster3_count"){Ex.Logger.Log("SingleTower.csv中字段[monster3_count]位置不对应"); return false; }
		if(vecLine[22]!="waypoint_group3"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group3]位置不对应"); return false; }
		if(vecLine[23]!="monster4_id"){Ex.Logger.Log("SingleTower.csv中字段[monster4_id]位置不对应"); return false; }
		if(vecLine[24]!="monster4_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster4_wave]位置不对应"); return false; }
		if(vecLine[25]!="monster4_count"){Ex.Logger.Log("SingleTower.csv中字段[monster4_count]位置不对应"); return false; }
		if(vecLine[26]!="waypoint_group4"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group4]位置不对应"); return false; }
		if(vecLine[27]!="monster5_id"){Ex.Logger.Log("SingleTower.csv中字段[monster5_id]位置不对应"); return false; }
		if(vecLine[28]!="monster5_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster5_wave]位置不对应"); return false; }
		if(vecLine[29]!="monster5_count"){Ex.Logger.Log("SingleTower.csv中字段[monster5_count]位置不对应"); return false; }
		if(vecLine[30]!="waypoint_group5"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group5]位置不对应"); return false; }
		if(vecLine[31]!="monster6_id"){Ex.Logger.Log("SingleTower.csv中字段[monster6_id]位置不对应"); return false; }
		if(vecLine[32]!="monster6_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster6_wave]位置不对应"); return false; }
		if(vecLine[33]!="monster6_count"){Ex.Logger.Log("SingleTower.csv中字段[monster6_count]位置不对应"); return false; }
		if(vecLine[34]!="waypoint_group6"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group6]位置不对应"); return false; }
		if(vecLine[35]!="monster7_id"){Ex.Logger.Log("SingleTower.csv中字段[monster7_id]位置不对应"); return false; }
		if(vecLine[36]!="monster7_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster7_wave]位置不对应"); return false; }
		if(vecLine[37]!="monster7_count"){Ex.Logger.Log("SingleTower.csv中字段[monster7_count]位置不对应"); return false; }
		if(vecLine[38]!="waypoint_group7"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group7]位置不对应"); return false; }
		if(vecLine[39]!="monster8_id"){Ex.Logger.Log("SingleTower.csv中字段[monster8_id]位置不对应"); return false; }
		if(vecLine[40]!="monster8_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster8_wave]位置不对应"); return false; }
		if(vecLine[41]!="monster8_count"){Ex.Logger.Log("SingleTower.csv中字段[monster8_count]位置不对应"); return false; }
		if(vecLine[42]!="waypoint_group8"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group8]位置不对应"); return false; }
		if(vecLine[43]!="monster9_id"){Ex.Logger.Log("SingleTower.csv中字段[monster9_id]位置不对应"); return false; }
		if(vecLine[44]!="monster9_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster9_wave]位置不对应"); return false; }
		if(vecLine[45]!="monster9_count"){Ex.Logger.Log("SingleTower.csv中字段[monster9_count]位置不对应"); return false; }
		if(vecLine[46]!="waypoint_group9"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group9]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SingleTowerElement member = new SingleTowerElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_reward_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_reward_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_reward_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_reward_4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.first_reward_5);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster1_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster1_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster1_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster2_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster2_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster2_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster3_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster3_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster3_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster4_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster4_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster4_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group4);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster5_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster5_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster5_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group5);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster6_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster6_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster6_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group6);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster7_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster7_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster7_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group7);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster8_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster8_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster8_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group8);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster9_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster9_wave );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.monster9_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_group9);

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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("SingleTower.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SingleTower.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="reward_1"){Ex.Logger.Log("SingleTower.csv中字段[reward_1]位置不对应"); return false; }
		if(vecLine[2]!="reward_2"){Ex.Logger.Log("SingleTower.csv中字段[reward_2]位置不对应"); return false; }
		if(vecLine[3]!="reward_3"){Ex.Logger.Log("SingleTower.csv中字段[reward_3]位置不对应"); return false; }
		if(vecLine[4]!="reward_4"){Ex.Logger.Log("SingleTower.csv中字段[reward_4]位置不对应"); return false; }
		if(vecLine[5]!="reward_5"){Ex.Logger.Log("SingleTower.csv中字段[reward_5]位置不对应"); return false; }
		if(vecLine[6]!="first_reward_1"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_1]位置不对应"); return false; }
		if(vecLine[7]!="first_reward_2"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_2]位置不对应"); return false; }
		if(vecLine[8]!="first_reward_3"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_3]位置不对应"); return false; }
		if(vecLine[9]!="first_reward_4"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_4]位置不对应"); return false; }
		if(vecLine[10]!="first_reward_5"){Ex.Logger.Log("SingleTower.csv中字段[first_reward_5]位置不对应"); return false; }
		if(vecLine[11]!="monster1_id"){Ex.Logger.Log("SingleTower.csv中字段[monster1_id]位置不对应"); return false; }
		if(vecLine[12]!="monster1_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster1_wave]位置不对应"); return false; }
		if(vecLine[13]!="monster1_count"){Ex.Logger.Log("SingleTower.csv中字段[monster1_count]位置不对应"); return false; }
		if(vecLine[14]!="waypoint_group1"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group1]位置不对应"); return false; }
		if(vecLine[15]!="monster2_id"){Ex.Logger.Log("SingleTower.csv中字段[monster2_id]位置不对应"); return false; }
		if(vecLine[16]!="monster2_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster2_wave]位置不对应"); return false; }
		if(vecLine[17]!="monster2_count"){Ex.Logger.Log("SingleTower.csv中字段[monster2_count]位置不对应"); return false; }
		if(vecLine[18]!="waypoint_group2"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group2]位置不对应"); return false; }
		if(vecLine[19]!="monster3_id"){Ex.Logger.Log("SingleTower.csv中字段[monster3_id]位置不对应"); return false; }
		if(vecLine[20]!="monster3_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster3_wave]位置不对应"); return false; }
		if(vecLine[21]!="monster3_count"){Ex.Logger.Log("SingleTower.csv中字段[monster3_count]位置不对应"); return false; }
		if(vecLine[22]!="waypoint_group3"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group3]位置不对应"); return false; }
		if(vecLine[23]!="monster4_id"){Ex.Logger.Log("SingleTower.csv中字段[monster4_id]位置不对应"); return false; }
		if(vecLine[24]!="monster4_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster4_wave]位置不对应"); return false; }
		if(vecLine[25]!="monster4_count"){Ex.Logger.Log("SingleTower.csv中字段[monster4_count]位置不对应"); return false; }
		if(vecLine[26]!="waypoint_group4"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group4]位置不对应"); return false; }
		if(vecLine[27]!="monster5_id"){Ex.Logger.Log("SingleTower.csv中字段[monster5_id]位置不对应"); return false; }
		if(vecLine[28]!="monster5_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster5_wave]位置不对应"); return false; }
		if(vecLine[29]!="monster5_count"){Ex.Logger.Log("SingleTower.csv中字段[monster5_count]位置不对应"); return false; }
		if(vecLine[30]!="waypoint_group5"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group5]位置不对应"); return false; }
		if(vecLine[31]!="monster6_id"){Ex.Logger.Log("SingleTower.csv中字段[monster6_id]位置不对应"); return false; }
		if(vecLine[32]!="monster6_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster6_wave]位置不对应"); return false; }
		if(vecLine[33]!="monster6_count"){Ex.Logger.Log("SingleTower.csv中字段[monster6_count]位置不对应"); return false; }
		if(vecLine[34]!="waypoint_group6"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group6]位置不对应"); return false; }
		if(vecLine[35]!="monster7_id"){Ex.Logger.Log("SingleTower.csv中字段[monster7_id]位置不对应"); return false; }
		if(vecLine[36]!="monster7_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster7_wave]位置不对应"); return false; }
		if(vecLine[37]!="monster7_count"){Ex.Logger.Log("SingleTower.csv中字段[monster7_count]位置不对应"); return false; }
		if(vecLine[38]!="waypoint_group7"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group7]位置不对应"); return false; }
		if(vecLine[39]!="monster8_id"){Ex.Logger.Log("SingleTower.csv中字段[monster8_id]位置不对应"); return false; }
		if(vecLine[40]!="monster8_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster8_wave]位置不对应"); return false; }
		if(vecLine[41]!="monster8_count"){Ex.Logger.Log("SingleTower.csv中字段[monster8_count]位置不对应"); return false; }
		if(vecLine[42]!="waypoint_group8"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group8]位置不对应"); return false; }
		if(vecLine[43]!="monster9_id"){Ex.Logger.Log("SingleTower.csv中字段[monster9_id]位置不对应"); return false; }
		if(vecLine[44]!="monster9_wave"){Ex.Logger.Log("SingleTower.csv中字段[monster9_wave]位置不对应"); return false; }
		if(vecLine[45]!="monster9_count"){Ex.Logger.Log("SingleTower.csv中字段[monster9_count]位置不对应"); return false; }
		if(vecLine[46]!="waypoint_group9"){Ex.Logger.Log("SingleTower.csv中字段[waypoint_group9]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)47)
			{
				return false;
			}
			SingleTowerElement member = new SingleTowerElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.reward_1=vecLine[1];
			member.reward_2=vecLine[2];
			member.reward_3=vecLine[3];
			member.reward_4=vecLine[4];
			member.reward_5=vecLine[5];
			member.first_reward_1=vecLine[6];
			member.first_reward_2=vecLine[7];
			member.first_reward_3=vecLine[8];
			member.first_reward_4=vecLine[9];
			member.first_reward_5=vecLine[10];
			member.monster1_id=Convert.ToInt32(vecLine[11]);
			member.monster1_wave=Convert.ToInt32(vecLine[12]);
			member.monster1_count=Convert.ToInt32(vecLine[13]);
			member.waypoint_group1=vecLine[14];
			member.monster2_id=Convert.ToInt32(vecLine[15]);
			member.monster2_wave=Convert.ToInt32(vecLine[16]);
			member.monster2_count=Convert.ToInt32(vecLine[17]);
			member.waypoint_group2=vecLine[18];
			member.monster3_id=Convert.ToInt32(vecLine[19]);
			member.monster3_wave=Convert.ToInt32(vecLine[20]);
			member.monster3_count=Convert.ToInt32(vecLine[21]);
			member.waypoint_group3=vecLine[22];
			member.monster4_id=Convert.ToInt32(vecLine[23]);
			member.monster4_wave=Convert.ToInt32(vecLine[24]);
			member.monster4_count=Convert.ToInt32(vecLine[25]);
			member.waypoint_group4=vecLine[26];
			member.monster5_id=Convert.ToInt32(vecLine[27]);
			member.monster5_wave=Convert.ToInt32(vecLine[28]);
			member.monster5_count=Convert.ToInt32(vecLine[29]);
			member.waypoint_group5=vecLine[30];
			member.monster6_id=Convert.ToInt32(vecLine[31]);
			member.monster6_wave=Convert.ToInt32(vecLine[32]);
			member.monster6_count=Convert.ToInt32(vecLine[33]);
			member.waypoint_group6=vecLine[34];
			member.monster7_id=Convert.ToInt32(vecLine[35]);
			member.monster7_wave=Convert.ToInt32(vecLine[36]);
			member.monster7_count=Convert.ToInt32(vecLine[37]);
			member.waypoint_group7=vecLine[38];
			member.monster8_id=Convert.ToInt32(vecLine[39]);
			member.monster8_wave=Convert.ToInt32(vecLine[40]);
			member.monster8_count=Convert.ToInt32(vecLine[41]);
			member.waypoint_group8=vecLine[42];
			member.monster9_id=Convert.ToInt32(vecLine[43]);
			member.monster9_wave=Convert.ToInt32(vecLine[44]);
			member.monster9_count=Convert.ToInt32(vecLine[45]);
			member.waypoint_group9=vecLine[46];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
