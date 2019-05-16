using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//七日目标表配置数据类
public class ActivitySevenDayTargetElement
{
	public int id;               	//主键id	活动id
	public string comment;       	//注释	策划用
	public int name;             	//名称ID	对应stringui表文字ID，显示在福利的右标签页上
	public string main_pic;      	//背景图	配置资源图的名字
	public int activity_type;    	//七日目标时间类型	0：从角色进入游戏时开始计时 1：配置指定日期
	public string target_type;   	//活动开始时间	如果activity_type列配置为0，此列不填
	public int recorded_data_days;	//记录数据天数	配置天数
	public int get_rewards_days; 	//活动结束天数	配置天数，玩家在此天数内可以领奖，如果超过此天数那么活动将会直接结束，从界面上消失
	public int level_min;        	//最低等级限制	可参与最低等级
	public li target1;           	//1日目标	对应目标表中的ID
	public li target2;           	//2日目标	对应目标表中的ID
	public li target3;           	//3日目标	对应目标表中的ID
	public li target4;           	//4日目标	对应目标表中的ID
	public li target5;           	//5日目标	对应目标表中的ID
	public li target6;           	//6日目标	对应目标表中的ID
	public li target7;           	//7日目标	对应目标表中的ID
	public int accumulate_point_id;	//积分道具ID	对应物品表中的ID
	public li accumulate_point_requirement;	//积分奖励要求	配置每个阶段奖励要求的积分数量
	public li accumulate_point_reward;	//积分奖励详情	道具ID1|数量1|是否中转|道具ID2|数量2|是否中转
	public li ultimate_prize_requirement;	//最终大奖积分要求	道具1积分要求|道具2积分要求
	public li ultimate_prize_reward;	//最终大奖详情	道具ID1|数量1|是否中转|道具ID2|数量2|是否中转
	public string ultimate_prize_show1;	//最终大奖领取前图片资源	仅客户端使用，对应资源表图片ID
	public string ultimate_prize_show2;	//最终大奖领取后图片资源	仅客户端使用，对应资源表图片ID
	public string ultimate_prize_item;	//最终大奖展示物品	仅客户端使用，点击最终大奖处的图标时，会显示配在此处的物品的tips

	public bool IsValidate = false;
	public ActivitySevenDayTargetElement()
	{
		id = -1;
	}
};

//七日目标表配置封装类
public class ActivitySevenDayTargetTable
{

	private ActivitySevenDayTargetTable()
	{
		m_mapElements = new Dictionary<int, ActivitySevenDayTargetElement>();
		m_emptyItem = new ActivitySevenDayTargetElement();
		m_vecAllElements = new List<ActivitySevenDayTargetElement>();
	}
	private Dictionary<int, ActivitySevenDayTargetElement> m_mapElements = null;
	private List<ActivitySevenDayTargetElement>	m_vecAllElements = null;
	private ActivitySevenDayTargetElement m_emptyItem = null;
	private static ActivitySevenDayTargetTable sInstance = null;

	public static ActivitySevenDayTargetTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ActivitySevenDayTargetTable();
			return sInstance;
		}
	}

	public ActivitySevenDayTargetElement GetElement(int key)
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

  public List<ActivitySevenDayTargetElement> GetAllElement(Predicate<ActivitySevenDayTargetElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ActivitySevenDayTarget.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ActivitySevenDayTarget.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ActivitySevenDayTarget.bin]未找到");
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
		if(vecLine.Count != 24)
		{
			Ex.Logger.Log("ActivitySevenDayTarget.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="main_pic"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[4]!="activity_type"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[activity_type]位置不对应"); return false; }
		if(vecLine[5]!="target_type"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[6]!="recorded_data_days"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[recorded_data_days]位置不对应"); return false; }
		if(vecLine[7]!="get_rewards_days"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[get_rewards_days]位置不对应"); return false; }
		if(vecLine[8]!="level_min"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[9]!="target1"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target1]位置不对应"); return false; }
		if(vecLine[10]!="target2"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target2]位置不对应"); return false; }
		if(vecLine[11]!="target3"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target3]位置不对应"); return false; }
		if(vecLine[12]!="target4"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target4]位置不对应"); return false; }
		if(vecLine[13]!="target5"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target5]位置不对应"); return false; }
		if(vecLine[14]!="target6"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target6]位置不对应"); return false; }
		if(vecLine[15]!="target7"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target7]位置不对应"); return false; }
		if(vecLine[16]!="accumulate_point_id"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_id]位置不对应"); return false; }
		if(vecLine[17]!="accumulate_point_requirement"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_requirement]位置不对应"); return false; }
		if(vecLine[18]!="accumulate_point_reward"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_reward]位置不对应"); return false; }
		if(vecLine[19]!="ultimate_prize_requirement"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_requirement]位置不对应"); return false; }
		if(vecLine[20]!="ultimate_prize_reward"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_reward]位置不对应"); return false; }
		if(vecLine[21]!="ultimate_prize_show1"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_show1]位置不对应"); return false; }
		if(vecLine[22]!="ultimate_prize_show2"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_show2]位置不对应"); return false; }
		if(vecLine[23]!="ultimate_prize_item"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_item]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ActivitySevenDayTargetElement member = new ActivitySevenDayTargetElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.main_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.activity_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_type);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recorded_data_days );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.get_rewards_days );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_min );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.target7);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.accumulate_point_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.accumulate_point_requirement);
			readPos += GameAssist.ReadString( binContent, readPos, out member.accumulate_point_reward);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ultimate_prize_requirement);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ultimate_prize_reward);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ultimate_prize_show1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ultimate_prize_show2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.ultimate_prize_item);

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
		if(vecLine.Count != 24)
		{
			Ex.Logger.Log("ActivitySevenDayTarget.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="main_pic"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[4]!="activity_type"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[activity_type]位置不对应"); return false; }
		if(vecLine[5]!="target_type"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[6]!="recorded_data_days"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[recorded_data_days]位置不对应"); return false; }
		if(vecLine[7]!="get_rewards_days"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[get_rewards_days]位置不对应"); return false; }
		if(vecLine[8]!="level_min"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[9]!="target1"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target1]位置不对应"); return false; }
		if(vecLine[10]!="target2"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target2]位置不对应"); return false; }
		if(vecLine[11]!="target3"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target3]位置不对应"); return false; }
		if(vecLine[12]!="target4"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target4]位置不对应"); return false; }
		if(vecLine[13]!="target5"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target5]位置不对应"); return false; }
		if(vecLine[14]!="target6"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target6]位置不对应"); return false; }
		if(vecLine[15]!="target7"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[target7]位置不对应"); return false; }
		if(vecLine[16]!="accumulate_point_id"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_id]位置不对应"); return false; }
		if(vecLine[17]!="accumulate_point_requirement"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_requirement]位置不对应"); return false; }
		if(vecLine[18]!="accumulate_point_reward"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[accumulate_point_reward]位置不对应"); return false; }
		if(vecLine[19]!="ultimate_prize_requirement"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_requirement]位置不对应"); return false; }
		if(vecLine[20]!="ultimate_prize_reward"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_reward]位置不对应"); return false; }
		if(vecLine[21]!="ultimate_prize_show1"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_show1]位置不对应"); return false; }
		if(vecLine[22]!="ultimate_prize_show2"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_show2]位置不对应"); return false; }
		if(vecLine[23]!="ultimate_prize_item"){Ex.Logger.Log("ActivitySevenDayTarget.csv中字段[ultimate_prize_item]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)24)
			{
				return false;
			}
			ActivitySevenDayTargetElement member = new ActivitySevenDayTargetElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.main_pic=vecLine[3];
			member.activity_type=Convert.ToInt32(vecLine[4]);
			member.target_type=vecLine[5];
			member.recorded_data_days=Convert.ToInt32(vecLine[6]);
			member.get_rewards_days=Convert.ToInt32(vecLine[7]);
			member.level_min=Convert.ToInt32(vecLine[8]);
			member.target1=vecLine[9];
			member.target2=vecLine[10];
			member.target3=vecLine[11];
			member.target4=vecLine[12];
			member.target5=vecLine[13];
			member.target6=vecLine[14];
			member.target7=vecLine[15];
			member.accumulate_point_id=Convert.ToInt32(vecLine[16]);
			member.accumulate_point_requirement=vecLine[17];
			member.accumulate_point_reward=vecLine[18];
			member.ultimate_prize_requirement=vecLine[19];
			member.ultimate_prize_reward=vecLine[20];
			member.ultimate_prize_show1=vecLine[21];
			member.ultimate_prize_show2=vecLine[22];
			member.ultimate_prize_item=vecLine[23];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
