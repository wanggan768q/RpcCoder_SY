using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//快速反应事件表配置数据类
public class QteElement
{
	public int id;               	//数据索引	1：测试 5：奥斯提温 7：马鬃草原 8：野外战场 9：精灵之森 10：帕尔派岛 15：科尔努斯 
	public string comment;       	//任务备注	仅策划用
	public int duration;         	//事件时长	规定qte的持续时间，单位为毫秒
	public int qte_type;         	//qte类型	1：单次点击类型 2：连续点击类型 3：hold点击类型 4：拼图型 5：刷卡型 6：旋转型 7: 涂抹型
	public int qteui_id;         	//qte界面表ID	
	public li start_pos;         	//qte起始位置	x|y,以屏幕中心点为0，0点，正上方为y轴正方向计算
	public int deviation_value;  	//qte起始点的偏差值	允许偏差的范围 以点击的位置为中心，半径为该字段值的圆形区域
	public int click_counts;     	//连点次数	当qte_type为2时，该字段规定连续点击的次数
	public int click_up_factor;  	//连点上升系数	达到目标APM,水银柱条每秒增加该字段点数,,水银柱条最大值100
	public int click_down_factor;	//连点下降系数	未达到目标APM,水银柱条每秒减少该字段点数,下降系数不可大于上升系数
	public int click_hold_time;  	//按住时间	当qte_type为3时，该字段规定点击至少需要的时间。只要时间到达，即算成功（跟抬手时机无关），单位为毫秒。填写0代表该字段不生效
	public int swap_target_angle;	//刷卡方向角度	以起始位置为中心，正上方为y轴正方向做计算的刷卡方向角度
	public int swap_target_deviation;	//刷卡方向偏差值	允许偏差的范围 以起始的位置为中心，偏转角度（绝对值） 最大为180，代表无方向规定
	public int swap_distance;    	//刷卡的距离	大于该距离算成功，单位为像素
	public li puzzle_orignal_size;	//起始位置的宽高	宽高为像素
	public li puzzle_target_size;	//目标位置的坐标和宽高	以屏幕正中为0，0 宽高为像素
	public int puzzle_target_deviation;	//目标位置的偏差值	允许偏差的范围 以目标的位置为中心，半径为该字段值的圆形区域
	public int puzzle_name;      	//拼图碎片的资源名	由美术提供的资源名
	public int rotate_type;      	//旋转类型	1为顺时针，2为逆时针
	public int rotate_max_range; 	//点击和旋转时检测的最大半径	起始位置为中心，允许产生的最大偏差值
	public int rotate_min_range; 	//点击和旋转时检测的最小半径	起始位置为中心，允许产生的最小偏差值
	public int rotate_angle;     	//旋转角度	所旋转的角度，超过了该角度即视为成功，与抬手时机无关
	public int wipep_length;     	//涂抹长度	在屏幕上涂抹的长度,单位:像素

	public bool IsValidate = false;
	public QteElement()
	{
		id = -1;
	}
};

//快速反应事件表配置封装类
public class QteTable
{

	private QteTable()
	{
		m_mapElements = new Dictionary<int, QteElement>();
		m_emptyItem = new QteElement();
		m_vecAllElements = new List<QteElement>();
	}
	private Dictionary<int, QteElement> m_mapElements = null;
	private List<QteElement>	m_vecAllElements = null;
	private QteElement m_emptyItem = null;
	private static QteTable sInstance = null;

	public static QteTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new QteTable();
			return sInstance;
		}
	}

	public QteElement GetElement(int key)
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

  public List<QteElement> GetAllElement(Predicate<QteElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Qte.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Qte.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Qte.bin]未找到");
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
		if(vecLine.Count != 23)
		{
			Ex.Logger.Log("Qte.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Qte.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Qte.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="duration"){Ex.Logger.Log("Qte.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[3]!="qte_type"){Ex.Logger.Log("Qte.csv中字段[qte_type]位置不对应"); return false; }
		if(vecLine[4]!="qteui_id"){Ex.Logger.Log("Qte.csv中字段[qteui_id]位置不对应"); return false; }
		if(vecLine[5]!="start_pos"){Ex.Logger.Log("Qte.csv中字段[start_pos]位置不对应"); return false; }
		if(vecLine[6]!="deviation_value"){Ex.Logger.Log("Qte.csv中字段[deviation_value]位置不对应"); return false; }
		if(vecLine[7]!="click_counts"){Ex.Logger.Log("Qte.csv中字段[click_counts]位置不对应"); return false; }
		if(vecLine[8]!="click_up_factor"){Ex.Logger.Log("Qte.csv中字段[click_up_factor]位置不对应"); return false; }
		if(vecLine[9]!="click_down_factor"){Ex.Logger.Log("Qte.csv中字段[click_down_factor]位置不对应"); return false; }
		if(vecLine[10]!="click_hold_time"){Ex.Logger.Log("Qte.csv中字段[click_hold_time]位置不对应"); return false; }
		if(vecLine[11]!="swap_target_angle"){Ex.Logger.Log("Qte.csv中字段[swap_target_angle]位置不对应"); return false; }
		if(vecLine[12]!="swap_target_deviation"){Ex.Logger.Log("Qte.csv中字段[swap_target_deviation]位置不对应"); return false; }
		if(vecLine[13]!="swap_distance"){Ex.Logger.Log("Qte.csv中字段[swap_distance]位置不对应"); return false; }
		if(vecLine[14]!="puzzle_orignal_size"){Ex.Logger.Log("Qte.csv中字段[puzzle_orignal_size]位置不对应"); return false; }
		if(vecLine[15]!="puzzle_target_size"){Ex.Logger.Log("Qte.csv中字段[puzzle_target_size]位置不对应"); return false; }
		if(vecLine[16]!="puzzle_target_deviation"){Ex.Logger.Log("Qte.csv中字段[puzzle_target_deviation]位置不对应"); return false; }
		if(vecLine[17]!="puzzle_name"){Ex.Logger.Log("Qte.csv中字段[puzzle_name]位置不对应"); return false; }
		if(vecLine[18]!="rotate_type"){Ex.Logger.Log("Qte.csv中字段[rotate_type]位置不对应"); return false; }
		if(vecLine[19]!="rotate_max_range"){Ex.Logger.Log("Qte.csv中字段[rotate_max_range]位置不对应"); return false; }
		if(vecLine[20]!="rotate_min_range"){Ex.Logger.Log("Qte.csv中字段[rotate_min_range]位置不对应"); return false; }
		if(vecLine[21]!="rotate_angle"){Ex.Logger.Log("Qte.csv中字段[rotate_angle]位置不对应"); return false; }
		if(vecLine[22]!="wipep_length"){Ex.Logger.Log("Qte.csv中字段[wipep_length]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			QteElement member = new QteElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.qte_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.qteui_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.start_pos);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.deviation_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.click_counts );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.click_up_factor );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.click_down_factor );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.click_hold_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.swap_target_angle );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.swap_target_deviation );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.swap_distance );
			readPos += GameAssist.ReadString( binContent, readPos, out member.puzzle_orignal_size);
			readPos += GameAssist.ReadString( binContent, readPos, out member.puzzle_target_size);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.puzzle_target_deviation );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.puzzle_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rotate_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rotate_max_range );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rotate_min_range );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rotate_angle );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.wipep_length );

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
		if(vecLine.Count != 23)
		{
			Ex.Logger.Log("Qte.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Qte.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Qte.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="duration"){Ex.Logger.Log("Qte.csv中字段[duration]位置不对应"); return false; }
		if(vecLine[3]!="qte_type"){Ex.Logger.Log("Qte.csv中字段[qte_type]位置不对应"); return false; }
		if(vecLine[4]!="qteui_id"){Ex.Logger.Log("Qte.csv中字段[qteui_id]位置不对应"); return false; }
		if(vecLine[5]!="start_pos"){Ex.Logger.Log("Qte.csv中字段[start_pos]位置不对应"); return false; }
		if(vecLine[6]!="deviation_value"){Ex.Logger.Log("Qte.csv中字段[deviation_value]位置不对应"); return false; }
		if(vecLine[7]!="click_counts"){Ex.Logger.Log("Qte.csv中字段[click_counts]位置不对应"); return false; }
		if(vecLine[8]!="click_up_factor"){Ex.Logger.Log("Qte.csv中字段[click_up_factor]位置不对应"); return false; }
		if(vecLine[9]!="click_down_factor"){Ex.Logger.Log("Qte.csv中字段[click_down_factor]位置不对应"); return false; }
		if(vecLine[10]!="click_hold_time"){Ex.Logger.Log("Qte.csv中字段[click_hold_time]位置不对应"); return false; }
		if(vecLine[11]!="swap_target_angle"){Ex.Logger.Log("Qte.csv中字段[swap_target_angle]位置不对应"); return false; }
		if(vecLine[12]!="swap_target_deviation"){Ex.Logger.Log("Qte.csv中字段[swap_target_deviation]位置不对应"); return false; }
		if(vecLine[13]!="swap_distance"){Ex.Logger.Log("Qte.csv中字段[swap_distance]位置不对应"); return false; }
		if(vecLine[14]!="puzzle_orignal_size"){Ex.Logger.Log("Qte.csv中字段[puzzle_orignal_size]位置不对应"); return false; }
		if(vecLine[15]!="puzzle_target_size"){Ex.Logger.Log("Qte.csv中字段[puzzle_target_size]位置不对应"); return false; }
		if(vecLine[16]!="puzzle_target_deviation"){Ex.Logger.Log("Qte.csv中字段[puzzle_target_deviation]位置不对应"); return false; }
		if(vecLine[17]!="puzzle_name"){Ex.Logger.Log("Qte.csv中字段[puzzle_name]位置不对应"); return false; }
		if(vecLine[18]!="rotate_type"){Ex.Logger.Log("Qte.csv中字段[rotate_type]位置不对应"); return false; }
		if(vecLine[19]!="rotate_max_range"){Ex.Logger.Log("Qte.csv中字段[rotate_max_range]位置不对应"); return false; }
		if(vecLine[20]!="rotate_min_range"){Ex.Logger.Log("Qte.csv中字段[rotate_min_range]位置不对应"); return false; }
		if(vecLine[21]!="rotate_angle"){Ex.Logger.Log("Qte.csv中字段[rotate_angle]位置不对应"); return false; }
		if(vecLine[22]!="wipep_length"){Ex.Logger.Log("Qte.csv中字段[wipep_length]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)23)
			{
				return false;
			}
			QteElement member = new QteElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.duration=Convert.ToInt32(vecLine[2]);
			member.qte_type=Convert.ToInt32(vecLine[3]);
			member.qteui_id=Convert.ToInt32(vecLine[4]);
			member.start_pos=vecLine[5];
			member.deviation_value=Convert.ToInt32(vecLine[6]);
			member.click_counts=Convert.ToInt32(vecLine[7]);
			member.click_up_factor=Convert.ToInt32(vecLine[8]);
			member.click_down_factor=Convert.ToInt32(vecLine[9]);
			member.click_hold_time=Convert.ToInt32(vecLine[10]);
			member.swap_target_angle=Convert.ToInt32(vecLine[11]);
			member.swap_target_deviation=Convert.ToInt32(vecLine[12]);
			member.swap_distance=Convert.ToInt32(vecLine[13]);
			member.puzzle_orignal_size=vecLine[14];
			member.puzzle_target_size=vecLine[15];
			member.puzzle_target_deviation=Convert.ToInt32(vecLine[16]);
			member.puzzle_name=Convert.ToInt32(vecLine[17]);
			member.rotate_type=Convert.ToInt32(vecLine[18]);
			member.rotate_max_range=Convert.ToInt32(vecLine[19]);
			member.rotate_min_range=Convert.ToInt32(vecLine[20]);
			member.rotate_angle=Convert.ToInt32(vecLine[21]);
			member.wipep_length=Convert.ToInt32(vecLine[22]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
