using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//定时规则配置数据类
public class TimerManagerElement
{
	public int id;               	//序号	主键id
	public string comment;       	//注释	定时器描述
	public int month_week;       	//每月第几周	0不用处理
	public int month_week_range; 	//0无限制|正数前几周负数后几周	0无限制|正数前几周负数后几周
	public li week;              	//0无星期限制|n星期n	0无星期限制|n星期n
	public string timerbegin;    	//定时每天开始时间	定时每天开始时间
	public int interval;         	//时间间隔	整数
	public string timerend;      	//根据时间间隔+开始时间	此列暂时无用
	public int nextbegin;        	//下次开始时间	下次重新执行时间逻辑0按照间隔继续，非0按照新时间
	public string expired;       	//定时器是否可以失效	0 永不失效 其他失效时间
	public string expired_date;  	//失效日期	0永不失效其他定时器失效日期
	public int crossday;         	//跨天处理	0 不特殊处理 1 根据timerend跨天重新计算

	public bool IsValidate = false;
	public TimerManagerElement()
	{
		id = -1;
	}
};

//定时规则配置封装类
public class TimerManagerTable
{

	private TimerManagerTable()
	{
		m_mapElements = new Dictionary<int, TimerManagerElement>();
		m_emptyItem = new TimerManagerElement();
		m_vecAllElements = new List<TimerManagerElement>();
	}
	private Dictionary<int, TimerManagerElement> m_mapElements = null;
	private List<TimerManagerElement>	m_vecAllElements = null;
	private TimerManagerElement m_emptyItem = null;
	private static TimerManagerTable sInstance = null;

	public static TimerManagerTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TimerManagerTable();
			return sInstance;
		}
	}

	public TimerManagerElement GetElement(int key)
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

  public List<TimerManagerElement> GetAllElement(Predicate<TimerManagerElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TimerManager.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TimerManager.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TimerManager.bin]未找到");
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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("TimerManager.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TimerManager.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TimerManager.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="month_week"){Ex.Logger.Log("TimerManager.csv中字段[month_week]位置不对应"); return false; }
		if(vecLine[3]!="month_week_range"){Ex.Logger.Log("TimerManager.csv中字段[month_week_range]位置不对应"); return false; }
		if(vecLine[4]!="week"){Ex.Logger.Log("TimerManager.csv中字段[week]位置不对应"); return false; }
		if(vecLine[5]!="timerbegin"){Ex.Logger.Log("TimerManager.csv中字段[timerbegin]位置不对应"); return false; }
		if(vecLine[6]!="interval"){Ex.Logger.Log("TimerManager.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[7]!="timerend"){Ex.Logger.Log("TimerManager.csv中字段[timerend]位置不对应"); return false; }
		if(vecLine[8]!="nextbegin"){Ex.Logger.Log("TimerManager.csv中字段[nextbegin]位置不对应"); return false; }
		if(vecLine[9]!="expired"){Ex.Logger.Log("TimerManager.csv中字段[expired]位置不对应"); return false; }
		if(vecLine[10]!="expired_date"){Ex.Logger.Log("TimerManager.csv中字段[expired_date]位置不对应"); return false; }
		if(vecLine[11]!="crossday"){Ex.Logger.Log("TimerManager.csv中字段[crossday]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TimerManagerElement member = new TimerManagerElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.month_week );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.month_week_range );
			readPos += GameAssist.ReadString( binContent, readPos, out member.week);
			readPos += GameAssist.ReadString( binContent, readPos, out member.timerbegin);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadString( binContent, readPos, out member.timerend);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.nextbegin );
			readPos += GameAssist.ReadString( binContent, readPos, out member.expired);
			readPos += GameAssist.ReadString( binContent, readPos, out member.expired_date);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.crossday );

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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("TimerManager.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TimerManager.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TimerManager.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="month_week"){Ex.Logger.Log("TimerManager.csv中字段[month_week]位置不对应"); return false; }
		if(vecLine[3]!="month_week_range"){Ex.Logger.Log("TimerManager.csv中字段[month_week_range]位置不对应"); return false; }
		if(vecLine[4]!="week"){Ex.Logger.Log("TimerManager.csv中字段[week]位置不对应"); return false; }
		if(vecLine[5]!="timerbegin"){Ex.Logger.Log("TimerManager.csv中字段[timerbegin]位置不对应"); return false; }
		if(vecLine[6]!="interval"){Ex.Logger.Log("TimerManager.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[7]!="timerend"){Ex.Logger.Log("TimerManager.csv中字段[timerend]位置不对应"); return false; }
		if(vecLine[8]!="nextbegin"){Ex.Logger.Log("TimerManager.csv中字段[nextbegin]位置不对应"); return false; }
		if(vecLine[9]!="expired"){Ex.Logger.Log("TimerManager.csv中字段[expired]位置不对应"); return false; }
		if(vecLine[10]!="expired_date"){Ex.Logger.Log("TimerManager.csv中字段[expired_date]位置不对应"); return false; }
		if(vecLine[11]!="crossday"){Ex.Logger.Log("TimerManager.csv中字段[crossday]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			TimerManagerElement member = new TimerManagerElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.month_week=Convert.ToInt32(vecLine[2]);
			member.month_week_range=Convert.ToInt32(vecLine[3]);
			member.week=vecLine[4];
			member.timerbegin=vecLine[5];
			member.interval=Convert.ToInt32(vecLine[6]);
			member.timerend=vecLine[7];
			member.nextbegin=Convert.ToInt32(vecLine[8]);
			member.expired=vecLine[9];
			member.expired_date=vecLine[10];
			member.crossday=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
