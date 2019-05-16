using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//功能引导表配置数据类
public class FunctionTutorialElement
{
	public int id;               	//引导条目	界面或者按钮的id id = function * 100 +index
	public string comment;       	//引导描述	不使用
	public int is_on;            	//引导开关	0.未开启 1.开启 未开启的引导在游戏中不使用  只针对index为1的生效
	public int function_id;      	//功能条目	用来标识该引导对应的功能，无特殊意义
	public int index;            	//引导步骤	用来生成id 无特殊意义
	public int trigger_type;     	//引导触发条件	枚举如下 1.完成任务 2.领取任务 3.打开界面 4.等级提升 5.装备等级(无法使用) 6.背包充满 7.获得道具 8.使用道具
	public int trigger_param;    	//条件参数	根据枚举类型决定 1.任务ID 2.任务ID 3.不填—调用prefab字段 4.等级 5.装备等级 6.不填 7.道具ID 8.道具ID
	public int next_step;        	//下一步骤	引导完成后触发下一引导的id  如果不填，表示该引导没有下一步，完成后该引导内容结束
	public int tutor_type;       	//引导类型	根据枚举确认引导类型 0.强制引导； 1.非强制引导-文本提示； 2.非强制引导-按钮闪烁
	public int is_key_step;      	//是否是关键步骤	如果为1,则为代表这个步骤完成则本条引导完成
	public string prefab;        	//界面资源名称	对应该引导需要影响到的界面
	public ls resource;          	//资源名称	填入资源对应的名字 对应界面 界面中的原件名称 如果是List中的资源,则listview的名字|cell的index|cell中的按钮的名称
	public int show_all_btn;     	//是否显示全部按钮	0 - 隐藏 1 - 显示
	public int action_type;      	//响应条件	强制引导响应玩家的方式 1.点击按钮；（点击对应按钮的功能后该引导结束） 2.点击指定区域；（点击对应区域，不触发该页面的按钮功能该引导结束） 3.点击任意区域；（点击任意区域，不触发该页面的按钮功能该引导结束）  非强制引导都是点击按钮
	public int zone_shape;       	//指引区形状	该指引区显示时的形状 0.圆形 1.矩形
	public lf zone_pos;          	//指定区域位置	x|y  以屏幕中心为0|0点计算
	public lf zone_scale;        	//指引区缩放	百分比 宽度|高度 1=100%  不填代表 1|1  action_type不为1的话,代表像素大小
	public int zone_focus;       	//是否聚焦	0.无聚焦 1.有聚焦效果
	public float zone_delay;     	//指引区延迟显示时间	
	public int text_type;        	//指引文本类型	强制引导枚举如下 1：附带讲解员图片 2：不附带讲解员图片 3：绑定按钮  非强制引导都是绑定按钮
	public int text_position;    	//文字位置	文字位置根据指引类型不同而有不同的含义 text_type为1时  1：界面左侧  2：界面右侧 text_type为2时 由1-9决定文字在界面中的位置 963 852 741 text_type为3时 由1-4决定文字相对于按钮的位置    1                     2    △                     △   ┌────────┐     │要显示的文字│   └────────┘     ▽                     ▽       3                     4
	public li text_offset;       	//文本框偏移量	数组，对应像素（需自适应） 横向偏移量|纵向偏移量 
	public int text_string;      	//指引文本	对应StringGuide表中的id

	public bool IsValidate = false;
	public FunctionTutorialElement()
	{
		id = -1;
	}
};

//功能引导表配置封装类
public class FunctionTutorialTable
{

	private FunctionTutorialTable()
	{
		m_mapElements = new Dictionary<int, FunctionTutorialElement>();
		m_emptyItem = new FunctionTutorialElement();
		m_vecAllElements = new List<FunctionTutorialElement>();
	}
	private Dictionary<int, FunctionTutorialElement> m_mapElements = null;
	private List<FunctionTutorialElement>	m_vecAllElements = null;
	private FunctionTutorialElement m_emptyItem = null;
	private static FunctionTutorialTable sInstance = null;

	public static FunctionTutorialTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new FunctionTutorialTable();
			return sInstance;
		}
	}

	public FunctionTutorialElement GetElement(int key)
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

  public List<FunctionTutorialElement> GetAllElement(Predicate<FunctionTutorialElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("FunctionTutorial.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("FunctionTutorial.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[FunctionTutorial.bin]未找到");
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
			Ex.Logger.Log("FunctionTutorial.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("FunctionTutorial.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("FunctionTutorial.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_on"){Ex.Logger.Log("FunctionTutorial.csv中字段[is_on]位置不对应"); return false; }
		if(vecLine[3]!="function_id"){Ex.Logger.Log("FunctionTutorial.csv中字段[function_id]位置不对应"); return false; }
		if(vecLine[4]!="index"){Ex.Logger.Log("FunctionTutorial.csv中字段[index]位置不对应"); return false; }
		if(vecLine[5]!="trigger_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[trigger_type]位置不对应"); return false; }
		if(vecLine[6]!="trigger_param"){Ex.Logger.Log("FunctionTutorial.csv中字段[trigger_param]位置不对应"); return false; }
		if(vecLine[7]!="next_step"){Ex.Logger.Log("FunctionTutorial.csv中字段[next_step]位置不对应"); return false; }
		if(vecLine[8]!="tutor_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[tutor_type]位置不对应"); return false; }
		if(vecLine[9]!="is_key_step"){Ex.Logger.Log("FunctionTutorial.csv中字段[is_key_step]位置不对应"); return false; }
		if(vecLine[10]!="prefab"){Ex.Logger.Log("FunctionTutorial.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[11]!="resource"){Ex.Logger.Log("FunctionTutorial.csv中字段[resource]位置不对应"); return false; }
		if(vecLine[12]!="show_all_btn"){Ex.Logger.Log("FunctionTutorial.csv中字段[show_all_btn]位置不对应"); return false; }
		if(vecLine[13]!="action_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[action_type]位置不对应"); return false; }
		if(vecLine[14]!="zone_shape"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_shape]位置不对应"); return false; }
		if(vecLine[15]!="zone_pos"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_pos]位置不对应"); return false; }
		if(vecLine[16]!="zone_scale"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_scale]位置不对应"); return false; }
		if(vecLine[17]!="zone_focus"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_focus]位置不对应"); return false; }
		if(vecLine[18]!="zone_delay"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_delay]位置不对应"); return false; }
		if(vecLine[19]!="text_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_type]位置不对应"); return false; }
		if(vecLine[20]!="text_position"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_position]位置不对应"); return false; }
		if(vecLine[21]!="text_offset"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_offset]位置不对应"); return false; }
		if(vecLine[22]!="text_string"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_string]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			FunctionTutorialElement member = new FunctionTutorialElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_on );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.function_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.index );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.trigger_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.trigger_param );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_step );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tutor_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_key_step );
			readPos += GameAssist.ReadString( binContent, readPos, out member.prefab);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.show_all_btn );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.action_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.zone_shape );
			readPos += GameAssist.ReadString( binContent, readPos, out member.zone_pos);
			readPos += GameAssist.ReadString( binContent, readPos, out member.zone_scale);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.zone_focus );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.zone_delay);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.text_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.text_position );
			readPos += GameAssist.ReadString( binContent, readPos, out member.text_offset);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.text_string );

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
			Ex.Logger.Log("FunctionTutorial.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("FunctionTutorial.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("FunctionTutorial.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_on"){Ex.Logger.Log("FunctionTutorial.csv中字段[is_on]位置不对应"); return false; }
		if(vecLine[3]!="function_id"){Ex.Logger.Log("FunctionTutorial.csv中字段[function_id]位置不对应"); return false; }
		if(vecLine[4]!="index"){Ex.Logger.Log("FunctionTutorial.csv中字段[index]位置不对应"); return false; }
		if(vecLine[5]!="trigger_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[trigger_type]位置不对应"); return false; }
		if(vecLine[6]!="trigger_param"){Ex.Logger.Log("FunctionTutorial.csv中字段[trigger_param]位置不对应"); return false; }
		if(vecLine[7]!="next_step"){Ex.Logger.Log("FunctionTutorial.csv中字段[next_step]位置不对应"); return false; }
		if(vecLine[8]!="tutor_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[tutor_type]位置不对应"); return false; }
		if(vecLine[9]!="is_key_step"){Ex.Logger.Log("FunctionTutorial.csv中字段[is_key_step]位置不对应"); return false; }
		if(vecLine[10]!="prefab"){Ex.Logger.Log("FunctionTutorial.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[11]!="resource"){Ex.Logger.Log("FunctionTutorial.csv中字段[resource]位置不对应"); return false; }
		if(vecLine[12]!="show_all_btn"){Ex.Logger.Log("FunctionTutorial.csv中字段[show_all_btn]位置不对应"); return false; }
		if(vecLine[13]!="action_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[action_type]位置不对应"); return false; }
		if(vecLine[14]!="zone_shape"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_shape]位置不对应"); return false; }
		if(vecLine[15]!="zone_pos"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_pos]位置不对应"); return false; }
		if(vecLine[16]!="zone_scale"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_scale]位置不对应"); return false; }
		if(vecLine[17]!="zone_focus"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_focus]位置不对应"); return false; }
		if(vecLine[18]!="zone_delay"){Ex.Logger.Log("FunctionTutorial.csv中字段[zone_delay]位置不对应"); return false; }
		if(vecLine[19]!="text_type"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_type]位置不对应"); return false; }
		if(vecLine[20]!="text_position"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_position]位置不对应"); return false; }
		if(vecLine[21]!="text_offset"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_offset]位置不对应"); return false; }
		if(vecLine[22]!="text_string"){Ex.Logger.Log("FunctionTutorial.csv中字段[text_string]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)23)
			{
				return false;
			}
			FunctionTutorialElement member = new FunctionTutorialElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.is_on=Convert.ToInt32(vecLine[2]);
			member.function_id=Convert.ToInt32(vecLine[3]);
			member.index=Convert.ToInt32(vecLine[4]);
			member.trigger_type=Convert.ToInt32(vecLine[5]);
			member.trigger_param=Convert.ToInt32(vecLine[6]);
			member.next_step=Convert.ToInt32(vecLine[7]);
			member.tutor_type=Convert.ToInt32(vecLine[8]);
			member.is_key_step=Convert.ToInt32(vecLine[9]);
			member.prefab=vecLine[10];
			member.resource=vecLine[11];
			member.show_all_btn=Convert.ToInt32(vecLine[12]);
			member.action_type=Convert.ToInt32(vecLine[13]);
			member.zone_shape=Convert.ToInt32(vecLine[14]);
			member.zone_pos=vecLine[15];
			member.zone_scale=vecLine[16];
			member.zone_focus=Convert.ToInt32(vecLine[17]);
			member.zone_delay=Convert.ToSingle(vecLine[18]);
			member.text_type=Convert.ToInt32(vecLine[19]);
			member.text_position=Convert.ToInt32(vecLine[20]);
			member.text_offset=vecLine[21];
			member.text_string=Convert.ToInt32(vecLine[22]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
