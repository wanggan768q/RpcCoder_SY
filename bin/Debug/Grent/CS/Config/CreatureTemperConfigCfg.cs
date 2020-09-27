using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC行为参数配置数据类
public class CreatureTemperConfigElement
{
	public int id;               	//性格ID	关联Creature
	public int search_style;     	// 索敌类型	0=范围索敌 1=全图索敌
	public float search_distance;	//锁敌距离	单位：米 进战半径 被动怪=0
	public int chase_type;       	//追敌类型	0=范围追敌 1=全图追敌
	public int chase_distance;   	//脱战半径	类型0有用 类型1没用 单位M
	public int chase_time;       	//回归时间	单位：毫秒
	public float chase_speed;    	//回归加速度	单位：米/秒
	public int hatred_area;      	//仇恨区域	进战后定期为区域内的玩家增加仇恨值 单位：米（半径） 别用！
	public int delay_min;        	//攻击延迟最小时间	两次攻击之间的延迟 单位：ms
	public int delay;            	//攻击延迟最大时间	两次攻击之间的延迟 单位：ms
	public float detection_distance;	//后退检测距离	攻击结束后检测目标包围盒与自己的距离小于该值后进行后退
	public float back_distance;  	//后退距离	注意后退距离要小于自己的攻击距离
	public float patrol_range;   	//巡逻范围	单位：米
	public int patrol_interval;  	//巡逻间隔	单位：毫秒
	public float harass_range;   	//绕敌圈半径	单位：米
	public int harass_probability1;	//在绕敌圈内绕敌几率	10000=%100
	public int harass_probability2;	//在绕地圈外绕敌几率	10000=%100
	public float harass_distance;	// 绕敌半径	单位：米
	public float harass_angle;   	// 绕敌角度	单位：度
	public int harass_timeout;   	// 绕敌超时时间	单位：毫秒
	public float cd_chase_dist;  	//技能cd时追敌距离	停止在拒敌x米处
	public float harass_speed;   	//加速绕敌速度	单位：米/秒

	public bool IsValidate = false;
	public CreatureTemperConfigElement()
	{
		id = -1;
	}
};

//NPC行为参数配置封装类
public class CreatureTemperConfigTable
{

	private CreatureTemperConfigTable()
	{
		m_mapElements = new Dictionary<int, CreatureTemperConfigElement>();
		m_emptyItem = new CreatureTemperConfigElement();
		m_vecAllElements = new List<CreatureTemperConfigElement>();
	}
	private Dictionary<int, CreatureTemperConfigElement> m_mapElements = null;
	private List<CreatureTemperConfigElement>	m_vecAllElements = null;
	private CreatureTemperConfigElement m_emptyItem = null;
	private static CreatureTemperConfigTable sInstance = null;

	public static CreatureTemperConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureTemperConfigTable();
			return sInstance;
		}
	}

	public CreatureTemperConfigElement GetElement(int key)
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

  public List<CreatureTemperConfigElement> GetAllElement(Predicate<CreatureTemperConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureTemperConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureTemperConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureTemperConfig.bin]未找到");
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
			Ex.Logger.Log("CreatureTemperConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="search_style"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[search_style]位置不对应"); return false; }
		if(vecLine[2]!="search_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[search_distance]位置不对应"); return false; }
		if(vecLine[3]!="chase_type"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_type]位置不对应"); return false; }
		if(vecLine[4]!="chase_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_distance]位置不对应"); return false; }
		if(vecLine[5]!="chase_time"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_time]位置不对应"); return false; }
		if(vecLine[6]!="chase_speed"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_speed]位置不对应"); return false; }
		if(vecLine[7]!="hatred_area"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[hatred_area]位置不对应"); return false; }
		if(vecLine[8]!="delay_min"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[delay_min]位置不对应"); return false; }
		if(vecLine[9]!="delay"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[delay]位置不对应"); return false; }
		if(vecLine[10]!="detection_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[detection_distance]位置不对应"); return false; }
		if(vecLine[11]!="back_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[back_distance]位置不对应"); return false; }
		if(vecLine[12]!="patrol_range"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[patrol_range]位置不对应"); return false; }
		if(vecLine[13]!="patrol_interval"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[patrol_interval]位置不对应"); return false; }
		if(vecLine[14]!="harass_range"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_range]位置不对应"); return false; }
		if(vecLine[15]!="harass_probability1"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_probability1]位置不对应"); return false; }
		if(vecLine[16]!="harass_probability2"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_probability2]位置不对应"); return false; }
		if(vecLine[17]!="harass_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_distance]位置不对应"); return false; }
		if(vecLine[18]!="harass_angle"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_angle]位置不对应"); return false; }
		if(vecLine[19]!="harass_timeout"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_timeout]位置不对应"); return false; }
		if(vecLine[20]!="cd_chase_dist"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[cd_chase_dist]位置不对应"); return false; }
		if(vecLine[21]!="harass_speed"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_speed]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureTemperConfigElement member = new CreatureTemperConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.search_style );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.search_distance);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chase_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chase_distance );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chase_time );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.chase_speed);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hatred_area );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.delay_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.delay );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.detection_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.back_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.patrol_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.patrol_interval );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.harass_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.harass_probability1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.harass_probability2 );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.harass_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.harass_angle);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.harass_timeout );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.cd_chase_dist);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.harass_speed);

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
			Ex.Logger.Log("CreatureTemperConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="search_style"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[search_style]位置不对应"); return false; }
		if(vecLine[2]!="search_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[search_distance]位置不对应"); return false; }
		if(vecLine[3]!="chase_type"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_type]位置不对应"); return false; }
		if(vecLine[4]!="chase_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_distance]位置不对应"); return false; }
		if(vecLine[5]!="chase_time"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_time]位置不对应"); return false; }
		if(vecLine[6]!="chase_speed"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[chase_speed]位置不对应"); return false; }
		if(vecLine[7]!="hatred_area"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[hatred_area]位置不对应"); return false; }
		if(vecLine[8]!="delay_min"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[delay_min]位置不对应"); return false; }
		if(vecLine[9]!="delay"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[delay]位置不对应"); return false; }
		if(vecLine[10]!="detection_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[detection_distance]位置不对应"); return false; }
		if(vecLine[11]!="back_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[back_distance]位置不对应"); return false; }
		if(vecLine[12]!="patrol_range"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[patrol_range]位置不对应"); return false; }
		if(vecLine[13]!="patrol_interval"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[patrol_interval]位置不对应"); return false; }
		if(vecLine[14]!="harass_range"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_range]位置不对应"); return false; }
		if(vecLine[15]!="harass_probability1"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_probability1]位置不对应"); return false; }
		if(vecLine[16]!="harass_probability2"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_probability2]位置不对应"); return false; }
		if(vecLine[17]!="harass_distance"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_distance]位置不对应"); return false; }
		if(vecLine[18]!="harass_angle"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_angle]位置不对应"); return false; }
		if(vecLine[19]!="harass_timeout"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_timeout]位置不对应"); return false; }
		if(vecLine[20]!="cd_chase_dist"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[cd_chase_dist]位置不对应"); return false; }
		if(vecLine[21]!="harass_speed"){Ex.Logger.Log("CreatureTemperConfig.csv中字段[harass_speed]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			CreatureTemperConfigElement member = new CreatureTemperConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.search_style=Convert.ToInt32(vecLine[1]);
			member.search_distance=Convert.ToSingle(vecLine[2]);
			member.chase_type=Convert.ToInt32(vecLine[3]);
			member.chase_distance=Convert.ToInt32(vecLine[4]);
			member.chase_time=Convert.ToInt32(vecLine[5]);
			member.chase_speed=Convert.ToSingle(vecLine[6]);
			member.hatred_area=Convert.ToInt32(vecLine[7]);
			member.delay_min=Convert.ToInt32(vecLine[8]);
			member.delay=Convert.ToInt32(vecLine[9]);
			member.detection_distance=Convert.ToSingle(vecLine[10]);
			member.back_distance=Convert.ToSingle(vecLine[11]);
			member.patrol_range=Convert.ToSingle(vecLine[12]);
			member.patrol_interval=Convert.ToInt32(vecLine[13]);
			member.harass_range=Convert.ToSingle(vecLine[14]);
			member.harass_probability1=Convert.ToInt32(vecLine[15]);
			member.harass_probability2=Convert.ToInt32(vecLine[16]);
			member.harass_distance=Convert.ToSingle(vecLine[17]);
			member.harass_angle=Convert.ToSingle(vecLine[18]);
			member.harass_timeout=Convert.ToInt32(vecLine[19]);
			member.cd_chase_dist=Convert.ToSingle(vecLine[20]);
			member.harass_speed=Convert.ToSingle(vecLine[21]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
