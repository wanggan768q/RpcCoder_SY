using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//activities_运营活动表配置数据类
public class OperationElement
{
	public int id;               	//主键id	活动id
	public string comment;       	//注释	策划用
	public int name;             	//名称ID	对应stringui表文字ID，显示在福利的右标签页上
	public int entry_location;   	//界面入口位置	1. 福利界面 2. 主界面 3. 运营活动界面
	public string main_pic;      	//背景图	Entry_location为1的话，此列无效 Entry_location为2的话，配置的是主界面入口的图标 Entry_location为3的话，配置的是界面的背景图 
	public int activity_type;    	//活动类型	1：七日任务
	public int activity_time_type;	//七日目标时间类型	0：从角色进入游戏时开始计时 1：配置指定日期
	public string target_type;   	//活动开始时间	如果activity_type列配置为0，此列不填
	public int recorded_data_days;	//记录数据天数	配置天数
	public int get_rewards_days; 	//活动结束天数	配置天数，玩家在此天数内可以领奖，如果超过此天数那么活动将会直接结束，从界面上消失
	public int level_min;        	//最低等级限制	可参与最低等级
	public li parameter1;        	//1日目标	对应目标表中的ID
	public li parameter2;        	//2日目标	对应目标表中的ID
	public li parameter3;        	//3日目标	对应目标表中的ID
	public li parameter4;        	//4日目标	对应目标表中的ID
	public li parameter5;        	//5日目标	对应目标表中的ID
	public li parameter6;        	//6日目标	对应目标表中的ID
	public li parameter7;        	//7日目标	对应目标表中的ID
	public li accumulate_point_quest_id;	//积分奖励	积分奖励是用任务的方式来实现，我会在此列中配置5个任务，这5个任务分别对应界面上的5个积分奖励
	public int Model_table;      	//模型表格	配置Model_display列的数据去哪个表格读取： 1：CharacterCustomize_角色自定义 2：CharacterConfig_模型配置
	public int Model_display;    	//模型展示	配置左侧展示的模型，对应模型表ID。
	public li accumulate_point;  	//积分奖励显示	客户端用，用于配置每个奖励要求的积分值

	public bool IsValidate = false;
	public OperationElement()
	{
		id = -1;
	}
};

//activities_运营活动表配置封装类
public class OperationTable
{

	private OperationTable()
	{
		m_mapElements = new Dictionary<int, OperationElement>();
		m_emptyItem = new OperationElement();
		m_vecAllElements = new List<OperationElement>();
	}
	private Dictionary<int, OperationElement> m_mapElements = null;
	private List<OperationElement>	m_vecAllElements = null;
	private OperationElement m_emptyItem = null;
	private static OperationTable sInstance = null;

	public static OperationTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new OperationTable();
			return sInstance;
		}
	}

	public OperationElement GetElement(int key)
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

  public List<OperationElement> GetAllElement(Predicate<OperationElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Operation.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Operation.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Operation.bin]未找到");
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
			Ex.Logger.Log("Operation.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Operation.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Operation.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Operation.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="entry_location"){Ex.Logger.Log("Operation.csv中字段[entry_location]位置不对应"); return false; }
		if(vecLine[4]!="main_pic"){Ex.Logger.Log("Operation.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[5]!="activity_type"){Ex.Logger.Log("Operation.csv中字段[activity_type]位置不对应"); return false; }
		if(vecLine[6]!="activity_time_type"){Ex.Logger.Log("Operation.csv中字段[activity_time_type]位置不对应"); return false; }
		if(vecLine[7]!="target_type"){Ex.Logger.Log("Operation.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[8]!="recorded_data_days"){Ex.Logger.Log("Operation.csv中字段[recorded_data_days]位置不对应"); return false; }
		if(vecLine[9]!="get_rewards_days"){Ex.Logger.Log("Operation.csv中字段[get_rewards_days]位置不对应"); return false; }
		if(vecLine[10]!="level_min"){Ex.Logger.Log("Operation.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[11]!="parameter1"){Ex.Logger.Log("Operation.csv中字段[parameter1]位置不对应"); return false; }
		if(vecLine[12]!="parameter2"){Ex.Logger.Log("Operation.csv中字段[parameter2]位置不对应"); return false; }
		if(vecLine[13]!="parameter3"){Ex.Logger.Log("Operation.csv中字段[parameter3]位置不对应"); return false; }
		if(vecLine[14]!="parameter4"){Ex.Logger.Log("Operation.csv中字段[parameter4]位置不对应"); return false; }
		if(vecLine[15]!="parameter5"){Ex.Logger.Log("Operation.csv中字段[parameter5]位置不对应"); return false; }
		if(vecLine[16]!="parameter6"){Ex.Logger.Log("Operation.csv中字段[parameter6]位置不对应"); return false; }
		if(vecLine[17]!="parameter7"){Ex.Logger.Log("Operation.csv中字段[parameter7]位置不对应"); return false; }
		if(vecLine[18]!="accumulate_point_quest_id"){Ex.Logger.Log("Operation.csv中字段[accumulate_point_quest_id]位置不对应"); return false; }
		if(vecLine[19]!="Model_table"){Ex.Logger.Log("Operation.csv中字段[Model_table]位置不对应"); return false; }
		if(vecLine[20]!="Model_display"){Ex.Logger.Log("Operation.csv中字段[Model_display]位置不对应"); return false; }
		if(vecLine[21]!="accumulate_point"){Ex.Logger.Log("Operation.csv中字段[accumulate_point]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			OperationElement member = new OperationElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.entry_location );
			readPos += GameAssist.ReadString( binContent, readPos, out member.main_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.activity_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.activity_time_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.target_type);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.recorded_data_days );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.get_rewards_days );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_min );
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.parameter7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.accumulate_point_quest_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Model_table );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Model_display );
			readPos += GameAssist.ReadString( binContent, readPos, out member.accumulate_point);

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
			Ex.Logger.Log("Operation.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Operation.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Operation.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Operation.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="entry_location"){Ex.Logger.Log("Operation.csv中字段[entry_location]位置不对应"); return false; }
		if(vecLine[4]!="main_pic"){Ex.Logger.Log("Operation.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[5]!="activity_type"){Ex.Logger.Log("Operation.csv中字段[activity_type]位置不对应"); return false; }
		if(vecLine[6]!="activity_time_type"){Ex.Logger.Log("Operation.csv中字段[activity_time_type]位置不对应"); return false; }
		if(vecLine[7]!="target_type"){Ex.Logger.Log("Operation.csv中字段[target_type]位置不对应"); return false; }
		if(vecLine[8]!="recorded_data_days"){Ex.Logger.Log("Operation.csv中字段[recorded_data_days]位置不对应"); return false; }
		if(vecLine[9]!="get_rewards_days"){Ex.Logger.Log("Operation.csv中字段[get_rewards_days]位置不对应"); return false; }
		if(vecLine[10]!="level_min"){Ex.Logger.Log("Operation.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[11]!="parameter1"){Ex.Logger.Log("Operation.csv中字段[parameter1]位置不对应"); return false; }
		if(vecLine[12]!="parameter2"){Ex.Logger.Log("Operation.csv中字段[parameter2]位置不对应"); return false; }
		if(vecLine[13]!="parameter3"){Ex.Logger.Log("Operation.csv中字段[parameter3]位置不对应"); return false; }
		if(vecLine[14]!="parameter4"){Ex.Logger.Log("Operation.csv中字段[parameter4]位置不对应"); return false; }
		if(vecLine[15]!="parameter5"){Ex.Logger.Log("Operation.csv中字段[parameter5]位置不对应"); return false; }
		if(vecLine[16]!="parameter6"){Ex.Logger.Log("Operation.csv中字段[parameter6]位置不对应"); return false; }
		if(vecLine[17]!="parameter7"){Ex.Logger.Log("Operation.csv中字段[parameter7]位置不对应"); return false; }
		if(vecLine[18]!="accumulate_point_quest_id"){Ex.Logger.Log("Operation.csv中字段[accumulate_point_quest_id]位置不对应"); return false; }
		if(vecLine[19]!="Model_table"){Ex.Logger.Log("Operation.csv中字段[Model_table]位置不对应"); return false; }
		if(vecLine[20]!="Model_display"){Ex.Logger.Log("Operation.csv中字段[Model_display]位置不对应"); return false; }
		if(vecLine[21]!="accumulate_point"){Ex.Logger.Log("Operation.csv中字段[accumulate_point]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			OperationElement member = new OperationElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.entry_location=Convert.ToInt32(vecLine[3]);
			member.main_pic=vecLine[4];
			member.activity_type=Convert.ToInt32(vecLine[5]);
			member.activity_time_type=Convert.ToInt32(vecLine[6]);
			member.target_type=vecLine[7];
			member.recorded_data_days=Convert.ToInt32(vecLine[8]);
			member.get_rewards_days=Convert.ToInt32(vecLine[9]);
			member.level_min=Convert.ToInt32(vecLine[10]);
			member.parameter1=vecLine[11];
			member.parameter2=vecLine[12];
			member.parameter3=vecLine[13];
			member.parameter4=vecLine[14];
			member.parameter5=vecLine[15];
			member.parameter6=vecLine[16];
			member.parameter7=vecLine[17];
			member.accumulate_point_quest_id=vecLine[18];
			member.Model_table=Convert.ToInt32(vecLine[19]);
			member.Model_display=Convert.ToInt32(vecLine[20]);
			member.accumulate_point=vecLine[21];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
