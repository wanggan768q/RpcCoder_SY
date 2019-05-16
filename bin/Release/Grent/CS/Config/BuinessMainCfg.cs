using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//生活技能总览配置数据类
public class BuinessMainElement
{
	public int id;               	//生活技能ID	生活技能ID
	public string comment;       	//注释	注释
	public int name;             	//生活技能名	文本id
	public int desc;             	//描述	文本id
	public string icon;          	//技能图标	资源名
	public li expend;            	//升级所需货币	前帮贡|后银币
	public int learn_desc;       	//学习二次确认	填写文本id
	public int change_desc;      	//更换二次确认	填写文本id
	public int info_desc;        	//更换界面文本	填写文本id
	public int up_value;         	//学习1次增加经验值	1次经验值
	public int need_lv;          	//开启所需玩家等级	开启条件
	public int mutual;           	//互斥关系	同数互斥
	public int item;             	//技能书	界面扣除
	public int item_times;       	//技能书每天可使用次数	填写次数
	public int item_exp;         	//技能书使用获得经验	填写经验
	public li make_items;        	//该技能可制作道具	填写道具组
	public int change_type;      	//扣cd是1扣钱是2	填写1或2即可
	public int cd_time;          	//更换成功后的cd时间	填写时间小时为单位
	public li currency;          	//更换所需货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	public int change_tips;      	//扣钱或时间时提示	填写文本id

	public bool IsValidate = false;
	public BuinessMainElement()
	{
		id = -1;
	}
};

//生活技能总览配置封装类
public class BuinessMainTable
{

	private BuinessMainTable()
	{
		m_mapElements = new Dictionary<int, BuinessMainElement>();
		m_emptyItem = new BuinessMainElement();
		m_vecAllElements = new List<BuinessMainElement>();
	}
	private Dictionary<int, BuinessMainElement> m_mapElements = null;
	private List<BuinessMainElement>	m_vecAllElements = null;
	private BuinessMainElement m_emptyItem = null;
	private static BuinessMainTable sInstance = null;

	public static BuinessMainTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuinessMainTable();
			return sInstance;
		}
	}

	public BuinessMainElement GetElement(int key)
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

  public List<BuinessMainElement> GetAllElement(Predicate<BuinessMainElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BuinessMain.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BuinessMain.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[BuinessMain.bin]未找到");
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
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("BuinessMain.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuinessMain.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("BuinessMain.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("BuinessMain.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("BuinessMain.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("BuinessMain.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="expend"){Ex.Logger.Log("BuinessMain.csv中字段[expend]位置不对应"); return false; }
		if(vecLine[6]!="learn_desc"){Ex.Logger.Log("BuinessMain.csv中字段[learn_desc]位置不对应"); return false; }
		if(vecLine[7]!="change_desc"){Ex.Logger.Log("BuinessMain.csv中字段[change_desc]位置不对应"); return false; }
		if(vecLine[8]!="info_desc"){Ex.Logger.Log("BuinessMain.csv中字段[info_desc]位置不对应"); return false; }
		if(vecLine[9]!="up_value"){Ex.Logger.Log("BuinessMain.csv中字段[up_value]位置不对应"); return false; }
		if(vecLine[10]!="need_lv"){Ex.Logger.Log("BuinessMain.csv中字段[need_lv]位置不对应"); return false; }
		if(vecLine[11]!="mutual"){Ex.Logger.Log("BuinessMain.csv中字段[mutual]位置不对应"); return false; }
		if(vecLine[12]!="item"){Ex.Logger.Log("BuinessMain.csv中字段[item]位置不对应"); return false; }
		if(vecLine[13]!="item_times"){Ex.Logger.Log("BuinessMain.csv中字段[item_times]位置不对应"); return false; }
		if(vecLine[14]!="item_exp"){Ex.Logger.Log("BuinessMain.csv中字段[item_exp]位置不对应"); return false; }
		if(vecLine[15]!="make_items"){Ex.Logger.Log("BuinessMain.csv中字段[make_items]位置不对应"); return false; }
		if(vecLine[16]!="change_type"){Ex.Logger.Log("BuinessMain.csv中字段[change_type]位置不对应"); return false; }
		if(vecLine[17]!="cd_time"){Ex.Logger.Log("BuinessMain.csv中字段[cd_time]位置不对应"); return false; }
		if(vecLine[18]!="currency"){Ex.Logger.Log("BuinessMain.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[19]!="change_tips"){Ex.Logger.Log("BuinessMain.csv中字段[change_tips]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuinessMainElement member = new BuinessMainElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.expend);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.learn_desc );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.change_desc );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.info_desc );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.need_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mutual );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_times );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_exp );
			readPos += GameAssist.ReadString( binContent, readPos, out member.make_items);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.change_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cd_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.currency);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.change_tips );

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
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("BuinessMain.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuinessMain.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("BuinessMain.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("BuinessMain.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("BuinessMain.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("BuinessMain.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="expend"){Ex.Logger.Log("BuinessMain.csv中字段[expend]位置不对应"); return false; }
		if(vecLine[6]!="learn_desc"){Ex.Logger.Log("BuinessMain.csv中字段[learn_desc]位置不对应"); return false; }
		if(vecLine[7]!="change_desc"){Ex.Logger.Log("BuinessMain.csv中字段[change_desc]位置不对应"); return false; }
		if(vecLine[8]!="info_desc"){Ex.Logger.Log("BuinessMain.csv中字段[info_desc]位置不对应"); return false; }
		if(vecLine[9]!="up_value"){Ex.Logger.Log("BuinessMain.csv中字段[up_value]位置不对应"); return false; }
		if(vecLine[10]!="need_lv"){Ex.Logger.Log("BuinessMain.csv中字段[need_lv]位置不对应"); return false; }
		if(vecLine[11]!="mutual"){Ex.Logger.Log("BuinessMain.csv中字段[mutual]位置不对应"); return false; }
		if(vecLine[12]!="item"){Ex.Logger.Log("BuinessMain.csv中字段[item]位置不对应"); return false; }
		if(vecLine[13]!="item_times"){Ex.Logger.Log("BuinessMain.csv中字段[item_times]位置不对应"); return false; }
		if(vecLine[14]!="item_exp"){Ex.Logger.Log("BuinessMain.csv中字段[item_exp]位置不对应"); return false; }
		if(vecLine[15]!="make_items"){Ex.Logger.Log("BuinessMain.csv中字段[make_items]位置不对应"); return false; }
		if(vecLine[16]!="change_type"){Ex.Logger.Log("BuinessMain.csv中字段[change_type]位置不对应"); return false; }
		if(vecLine[17]!="cd_time"){Ex.Logger.Log("BuinessMain.csv中字段[cd_time]位置不对应"); return false; }
		if(vecLine[18]!="currency"){Ex.Logger.Log("BuinessMain.csv中字段[currency]位置不对应"); return false; }
		if(vecLine[19]!="change_tips"){Ex.Logger.Log("BuinessMain.csv中字段[change_tips]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)20)
			{
				return false;
			}
			BuinessMainElement member = new BuinessMainElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.desc=Convert.ToInt32(vecLine[3]);
			member.icon=vecLine[4];
			member.expend=vecLine[5];
			member.learn_desc=Convert.ToInt32(vecLine[6]);
			member.change_desc=Convert.ToInt32(vecLine[7]);
			member.info_desc=Convert.ToInt32(vecLine[8]);
			member.up_value=Convert.ToInt32(vecLine[9]);
			member.need_lv=Convert.ToInt32(vecLine[10]);
			member.mutual=Convert.ToInt32(vecLine[11]);
			member.item=Convert.ToInt32(vecLine[12]);
			member.item_times=Convert.ToInt32(vecLine[13]);
			member.item_exp=Convert.ToInt32(vecLine[14]);
			member.make_items=vecLine[15];
			member.change_type=Convert.ToInt32(vecLine[16]);
			member.cd_time=Convert.ToInt32(vecLine[17]);
			member.currency=vecLine[18];
			member.change_tips=Convert.ToInt32(vecLine[19]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
