using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//陷阱表配置数据类
public class TrapElement
{
	public int id;               	//陷阱ID	陷阱ID
	public string comment;       	//备注	备注
	public int location_type;    	//生成陷阱位置类型	陷阱生成位置类型 0：读表生成 1：技能选择位置 2：技能目标位置 3：固定坐标位置 4：陷阱触发的陷阱
	public int trap_count;       	//陷阱数量	生成陷阱的数量
	public int generate_type;    	//生成陷阱类型	生成方式 0=平行 1=扇形
	public float trap_gap;       	//生成陷阱间隔参数	如果生成方式是0，则填入间隔距离（m）； 如果生成方式是1，则填入角度。
	public float generate_distance;	//生成陷阱距离	生成距离
	public int delay_time;       	//生成陷阱后attack/触发检测延迟	释放陷阱一定时间后，开始生效attack触发机制，单位：ms
	public int duration;         	//陷阱持续时间	陷阱持续时间，单位：ms
	public int interval;         	//陷阱效果触发间隔时间	触发间隔时间，单位：ms
	public int max_trigger_count;	//陷阱最大触发次数	最大有效触发attack次数，未击中目标的attack不计入次数统计
	public string trap_model_name;	//陷阱模型名称	模型名称或者特效名称
	public string end_effect;    	//陷阱消失时播放特效	陷阱消失时播放的特效，没有为空
	public float trigger_range;  	//触发半径	陷阱检测触碰圆形区域的半径，若和attack触发相同可填0，则按照attack区域形状持续进行脉冲 单位：m
	public li attack_id_list;    	//attack的ID列表	陷阱触发效果的attackIdList,多个attack用连接符“|”连接
	public int auto_trigger;     	//自动触发	0:没人进入区域，不会自动触发下一个陷阱 1:时间到了，自动触发下一个陷阱
	public int next_trap_id;     	//下一个陷阱ID	陷阱触发后生成的下一个陷阱ID，当前陷阱消失，在当前位置生成新陷阱，无触发时，填0
	public int is_disappear;     	//是否消失	达到最大触发次数后是否立即消失， 1 = 立即消失， 0 = 达到最大触发次数后会等到持续时间结束后再消失
	public int hitOnce;          	//是否只受到一次伤害	同一人在陷阱持续时间内，是否只受到一次伤害 1= 只受一次伤害 0 = 可受到多次伤害

	public bool IsValidate = false;
	public TrapElement()
	{
		id = -1;
	}
};

//陷阱表配置封装类
public class TrapTable
{

	private TrapTable()
	{
		m_mapElements = new Dictionary<int, TrapElement>();
		m_emptyItem = new TrapElement();
		m_vecAllElements = new List<TrapElement>();
	}
	private Dictionary<int, TrapElement> m_mapElements = null;
	private List<TrapElement>	m_vecAllElements = null;
	private TrapElement m_emptyItem = null;
	private static TrapTable sInstance = null;

	public static TrapTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TrapTable();
			return sInstance;
		}
	}

	public TrapElement GetElement(int key)
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

  public List<TrapElement> GetAllElement(Predicate<TrapElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Trap.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Trap.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Trap.bin]未找到");
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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("Trap.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Trap.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Trap.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="location_type"){Ex.Logger.Log("Trap.csv中字段[location_type]位置不对应"); return false; }
		if(vecLine[3]!="trap_count"){Ex.Logger.Log("Trap.csv中字段[trap_count]位置不对应"); return false; }
		if(vecLine[4]!="generate_type"){Ex.Logger.Log("Trap.csv中字段[generate_type]位置不对应"); return false; }
		if(vecLine[5]!="trap_gap"){Ex.Logger.Log("Trap.csv中字段[trap_gap]位置不对应"); return false; }
		if(vecLine[6]!="generate_distance"){Ex.Logger.Log("Trap.csv中字段[generate_distance]位置不对应"); return false; }
		if(vecLine[7]!="delay_time"){Ex.Logger.Log("Trap.csv中字段[delay_time]位置不对应"); return false; }
		if(vecLine[8]!="duration"){Ex.Logger.Log("Trap.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[9]!="interval"){Ex.Logger.Log("Trap.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[10]!="max_trigger_count"){Ex.Logger.Log("Trap.csv中字段[max_trigger_count]位置不对应"); return false; }
		if(vecLine[11]!="trap_model_name"){Ex.Logger.Log("Trap.csv中字段[trap_model_name]位置不对应"); return false; }
		if(vecLine[12]!="end_effect"){Ex.Logger.Log("Trap.csv中字段[end_effect]位置不对应"); return false; }
		if(vecLine[13]!="trigger_range"){Ex.Logger.Log("Trap.csv中字段[trigger_range]位置不对应"); return false; }
		if(vecLine[14]!="attack_id_list"){Ex.Logger.Log("Trap.csv中字段[attack_id_list]位置不对应"); return false; }
		if(vecLine[15]!="auto_trigger"){Ex.Logger.Log("Trap.csv中字段[auto_trigger]位置不对应"); return false; }
		if(vecLine[16]!="next_trap_id"){Ex.Logger.Log("Trap.csv中字段[next_trap_id]位置不对应"); return false; }
		if(vecLine[17]!="is_disappear"){Ex.Logger.Log("Trap.csv中字段[is_disappear]位置不对应"); return false; }
		if(vecLine[18]!="hitOnce"){Ex.Logger.Log("Trap.csv中字段[hitOnce]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TrapElement member = new TrapElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.location_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.trap_count );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.generate_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.trap_gap);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.generate_distance);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.delay_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_trigger_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.trap_model_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.end_effect);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.trigger_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attack_id_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auto_trigger );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_trap_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_disappear );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hitOnce );

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
		if(vecLine.Count != 19)
		{
			Ex.Logger.Log("Trap.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Trap.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Trap.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="location_type"){Ex.Logger.Log("Trap.csv中字段[location_type]位置不对应"); return false; }
		if(vecLine[3]!="trap_count"){Ex.Logger.Log("Trap.csv中字段[trap_count]位置不对应"); return false; }
		if(vecLine[4]!="generate_type"){Ex.Logger.Log("Trap.csv中字段[generate_type]位置不对应"); return false; }
		if(vecLine[5]!="trap_gap"){Ex.Logger.Log("Trap.csv中字段[trap_gap]位置不对应"); return false; }
		if(vecLine[6]!="generate_distance"){Ex.Logger.Log("Trap.csv中字段[generate_distance]位置不对应"); return false; }
		if(vecLine[7]!="delay_time"){Ex.Logger.Log("Trap.csv中字段[delay_time]位置不对应"); return false; }
		if(vecLine[8]!="duration"){Ex.Logger.Log("Trap.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[9]!="interval"){Ex.Logger.Log("Trap.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[10]!="max_trigger_count"){Ex.Logger.Log("Trap.csv中字段[max_trigger_count]位置不对应"); return false; }
		if(vecLine[11]!="trap_model_name"){Ex.Logger.Log("Trap.csv中字段[trap_model_name]位置不对应"); return false; }
		if(vecLine[12]!="end_effect"){Ex.Logger.Log("Trap.csv中字段[end_effect]位置不对应"); return false; }
		if(vecLine[13]!="trigger_range"){Ex.Logger.Log("Trap.csv中字段[trigger_range]位置不对应"); return false; }
		if(vecLine[14]!="attack_id_list"){Ex.Logger.Log("Trap.csv中字段[attack_id_list]位置不对应"); return false; }
		if(vecLine[15]!="auto_trigger"){Ex.Logger.Log("Trap.csv中字段[auto_trigger]位置不对应"); return false; }
		if(vecLine[16]!="next_trap_id"){Ex.Logger.Log("Trap.csv中字段[next_trap_id]位置不对应"); return false; }
		if(vecLine[17]!="is_disappear"){Ex.Logger.Log("Trap.csv中字段[is_disappear]位置不对应"); return false; }
		if(vecLine[18]!="hitOnce"){Ex.Logger.Log("Trap.csv中字段[hitOnce]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)19)
			{
				return false;
			}
			TrapElement member = new TrapElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.location_type=Convert.ToInt32(vecLine[2]);
			member.trap_count=Convert.ToInt32(vecLine[3]);
			member.generate_type=Convert.ToInt32(vecLine[4]);
			member.trap_gap=Convert.ToSingle(vecLine[5]);
			member.generate_distance=Convert.ToSingle(vecLine[6]);
			member.delay_time=Convert.ToInt32(vecLine[7]);
			member.duration=Convert.ToInt32(vecLine[8]);
			member.interval=Convert.ToInt32(vecLine[9]);
			member.max_trigger_count=Convert.ToInt32(vecLine[10]);
			member.trap_model_name=vecLine[11];
			member.end_effect=vecLine[12];
			member.trigger_range=Convert.ToSingle(vecLine[13]);
			member.attack_id_list=vecLine[14];
			member.auto_trigger=Convert.ToInt32(vecLine[15]);
			member.next_trap_id=Convert.ToInt32(vecLine[16]);
			member.is_disappear=Convert.ToInt32(vecLine[17]);
			member.hitOnce=Convert.ToInt32(vecLine[18]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
