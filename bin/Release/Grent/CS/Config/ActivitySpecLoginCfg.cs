using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//运营登录活动表配置数据类
public class ActivitySpecLoginElement
{
	public int id;               	//主键id	活动id
	public string comment;       	//注释	策划用
	public string main_pic;      	//主图名称	填写图片名
	public string sub_pic;       	//文字图	填写文本图片名
	public int function_on;      	//是否开启	0 不开启 1 开启
	public int call;             	//支持开启弹窗提醒	0 不开启 1 开启
	public int group;            	//组别	同活动填写同组ID
	public int weight;           	//权重	标签列表内的显示权重
	public int level_min;        	//最低等级限制	可参与最低等级
	public int name_id;          	//名称id	string_UI
	public int describe_id;      	//描述文本id	string_UI
	public int open_type;        	//时间类型	1-开服后开启 2-固定日期开启
	public string open_time;     	//开启活动日期
默认服务器时间0点开启	type=1，该列-1 type=2，活动第1天年月日
	public int days;             	//活动所需登录天数	填写整数
	public int duration;         	//活动持续天数	填写整数
	public li day1_rewards;      	//道具ID|数量|是否中转	60013001|1|0
	public li day2_rewards;      	//道具ID|数量|是否中转	60012001|1|0
	public li day3_rewards;      	//道具ID|数量|是否中转	80432005|1|0
	public li day4_rewards;      	//道具ID|数量|是否中转	60030001|1|0
	public li day5_rewards;      	//道具ID|数量|是否中转	71000005|1|0
	public li day6_rewards;      	//道具ID|数量|是否中转	60011001|1|0
	public li day7_rewards;      	//道具ID|数量|是否中转	71000005|1|0

	public bool IsValidate = false;
	public ActivitySpecLoginElement()
	{
		id = -1;
	}
};

//运营登录活动表配置封装类
public class ActivitySpecLoginTable
{

	private ActivitySpecLoginTable()
	{
		m_mapElements = new Dictionary<int, ActivitySpecLoginElement>();
		m_emptyItem = new ActivitySpecLoginElement();
		m_vecAllElements = new List<ActivitySpecLoginElement>();
	}
	private Dictionary<int, ActivitySpecLoginElement> m_mapElements = null;
	private List<ActivitySpecLoginElement>	m_vecAllElements = null;
	private ActivitySpecLoginElement m_emptyItem = null;
	private static ActivitySpecLoginTable sInstance = null;

	public static ActivitySpecLoginTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ActivitySpecLoginTable();
			return sInstance;
		}
	}

	public ActivitySpecLoginElement GetElement(int key)
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

  public List<ActivitySpecLoginElement> GetAllElement(Predicate<ActivitySpecLoginElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ActivitySpecLogin.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ActivitySpecLogin.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ActivitySpecLogin.bin]未找到");
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
			Ex.Logger.Log("ActivitySpecLogin.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="main_pic"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[3]!="sub_pic"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[sub_pic]位置不对应"); return false; }
		if(vecLine[4]!="function_on"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[function_on]位置不对应"); return false; }
		if(vecLine[5]!="call"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[call]位置不对应"); return false; }
		if(vecLine[6]!="group"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[group]位置不对应"); return false; }
		if(vecLine[7]!="weight"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[8]!="level_min"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[9]!="name_id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[10]!="describe_id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[11]!="open_type"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[open_type]位置不对应"); return false; }
		if(vecLine[12]!="open_time"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[open_time]位置不对应"); return false; }
		if(vecLine[13]!="days"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[days]位置不对应"); return false; }
		if(vecLine[14]!="duration"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[15]!="day1_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day1_rewards]位置不对应"); return false; }
		if(vecLine[16]!="day2_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day2_rewards]位置不对应"); return false; }
		if(vecLine[17]!="day3_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day3_rewards]位置不对应"); return false; }
		if(vecLine[18]!="day4_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day4_rewards]位置不对应"); return false; }
		if(vecLine[19]!="day5_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day5_rewards]位置不对应"); return false; }
		if(vecLine[20]!="day6_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day6_rewards]位置不对应"); return false; }
		if(vecLine[21]!="day7_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day7_rewards]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ActivitySpecLoginElement member = new ActivitySpecLoginElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.main_pic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sub_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.function_on );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.call );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.weight );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.open_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.open_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.days );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration );
			readPos += GameAssist.ReadString( binContent, readPos, out member.day1_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day2_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day3_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day4_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day5_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day6_rewards);
			readPos += GameAssist.ReadString( binContent, readPos, out member.day7_rewards);

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
			Ex.Logger.Log("ActivitySpecLogin.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="main_pic"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[main_pic]位置不对应"); return false; }
		if(vecLine[3]!="sub_pic"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[sub_pic]位置不对应"); return false; }
		if(vecLine[4]!="function_on"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[function_on]位置不对应"); return false; }
		if(vecLine[5]!="call"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[call]位置不对应"); return false; }
		if(vecLine[6]!="group"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[group]位置不对应"); return false; }
		if(vecLine[7]!="weight"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[8]!="level_min"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[level_min]位置不对应"); return false; }
		if(vecLine[9]!="name_id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[10]!="describe_id"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[11]!="open_type"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[open_type]位置不对应"); return false; }
		if(vecLine[12]!="open_time"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[open_time]位置不对应"); return false; }
		if(vecLine[13]!="days"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[days]位置不对应"); return false; }
		if(vecLine[14]!="duration"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[15]!="day1_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day1_rewards]位置不对应"); return false; }
		if(vecLine[16]!="day2_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day2_rewards]位置不对应"); return false; }
		if(vecLine[17]!="day3_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day3_rewards]位置不对应"); return false; }
		if(vecLine[18]!="day4_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day4_rewards]位置不对应"); return false; }
		if(vecLine[19]!="day5_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day5_rewards]位置不对应"); return false; }
		if(vecLine[20]!="day6_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day6_rewards]位置不对应"); return false; }
		if(vecLine[21]!="day7_rewards"){Ex.Logger.Log("ActivitySpecLogin.csv中字段[day7_rewards]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			ActivitySpecLoginElement member = new ActivitySpecLoginElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.main_pic=vecLine[2];
			member.sub_pic=vecLine[3];
			member.function_on=Convert.ToInt32(vecLine[4]);
			member.call=Convert.ToInt32(vecLine[5]);
			member.group=Convert.ToInt32(vecLine[6]);
			member.weight=Convert.ToInt32(vecLine[7]);
			member.level_min=Convert.ToInt32(vecLine[8]);
			member.name_id=Convert.ToInt32(vecLine[9]);
			member.describe_id=Convert.ToInt32(vecLine[10]);
			member.open_type=Convert.ToInt32(vecLine[11]);
			member.open_time=vecLine[12];
			member.days=Convert.ToInt32(vecLine[13]);
			member.duration=Convert.ToInt32(vecLine[14]);
			member.day1_rewards=vecLine[15];
			member.day2_rewards=vecLine[16];
			member.day3_rewards=vecLine[17];
			member.day4_rewards=vecLine[18];
			member.day5_rewards=vecLine[19];
			member.day6_rewards=vecLine[20];
			member.day7_rewards=vecLine[21];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
