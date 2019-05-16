using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//排行榜表配置数据类
public class LeaderBoardElement
{
	public int id;               	//排行榜id	对应到具体每个主题、榜单
	public string comment;       	//注释	策划用
	public int theme;            	//对应主题	1：综合 2：个人 3：公会 4：PVP 5：活动
	public int theme_name;       	//排行榜名称	对应StringUi表中的ID
	public li update_time;       	//更新时间	 1：分钟刷新 2：小时刷新 3：天刷新
	public li settlement_time;   	//结算时间	分类|日期|时间 0：每天结算1次|几点|几分 1：每周结算1次|周几|几点 2：每月结算1次|几号|几点 3：每月固定0点结算2次|几号|几号
	public int billing_empty;    	//结算清空	结算是否清空榜单数据 0：不清空 1：清空 
	public int enable;           	//是否启用	0：不启用 1：启用
	public li sort_index;        	//分类索引	对应奖励表的ID

	public bool IsValidate = false;
	public LeaderBoardElement()
	{
		id = -1;
	}
};

//排行榜表配置封装类
public class LeaderBoardTable
{

	private LeaderBoardTable()
	{
		m_mapElements = new Dictionary<int, LeaderBoardElement>();
		m_emptyItem = new LeaderBoardElement();
		m_vecAllElements = new List<LeaderBoardElement>();
	}
	private Dictionary<int, LeaderBoardElement> m_mapElements = null;
	private List<LeaderBoardElement>	m_vecAllElements = null;
	private LeaderBoardElement m_emptyItem = null;
	private static LeaderBoardTable sInstance = null;

	public static LeaderBoardTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LeaderBoardTable();
			return sInstance;
		}
	}

	public LeaderBoardElement GetElement(int key)
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

  public List<LeaderBoardElement> GetAllElement(Predicate<LeaderBoardElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("LeaderBoard.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("LeaderBoard.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[LeaderBoard.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("LeaderBoard.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LeaderBoard.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LeaderBoard.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="theme"){Ex.Logger.Log("LeaderBoard.csv中字段[theme]位置不对应"); return false; }
		if(vecLine[3]!="theme_name"){Ex.Logger.Log("LeaderBoard.csv中字段[theme_name]位置不对应"); return false; }
		if(vecLine[4]!="update_time"){Ex.Logger.Log("LeaderBoard.csv中字段[update_time]位置不对应"); return false; }
		if(vecLine[5]!="settlement_time"){Ex.Logger.Log("LeaderBoard.csv中字段[settlement_time]位置不对应"); return false; }
		if(vecLine[6]!="billing_empty"){Ex.Logger.Log("LeaderBoard.csv中字段[billing_empty]位置不对应"); return false; }
		if(vecLine[7]!="enable"){Ex.Logger.Log("LeaderBoard.csv中字段[enable]位置不对应"); return false; }
		if(vecLine[8]!="sort_index"){Ex.Logger.Log("LeaderBoard.csv中字段[sort_index]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LeaderBoardElement member = new LeaderBoardElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.theme );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.theme_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.update_time);
			readPos += GameAssist.ReadString( binContent, readPos, out member.settlement_time);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.billing_empty );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.enable );
			readPos += GameAssist.ReadString( binContent, readPos, out member.sort_index);

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("LeaderBoard.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LeaderBoard.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LeaderBoard.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="theme"){Ex.Logger.Log("LeaderBoard.csv中字段[theme]位置不对应"); return false; }
		if(vecLine[3]!="theme_name"){Ex.Logger.Log("LeaderBoard.csv中字段[theme_name]位置不对应"); return false; }
		if(vecLine[4]!="update_time"){Ex.Logger.Log("LeaderBoard.csv中字段[update_time]位置不对应"); return false; }
		if(vecLine[5]!="settlement_time"){Ex.Logger.Log("LeaderBoard.csv中字段[settlement_time]位置不对应"); return false; }
		if(vecLine[6]!="billing_empty"){Ex.Logger.Log("LeaderBoard.csv中字段[billing_empty]位置不对应"); return false; }
		if(vecLine[7]!="enable"){Ex.Logger.Log("LeaderBoard.csv中字段[enable]位置不对应"); return false; }
		if(vecLine[8]!="sort_index"){Ex.Logger.Log("LeaderBoard.csv中字段[sort_index]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			LeaderBoardElement member = new LeaderBoardElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.theme=Convert.ToInt32(vecLine[2]);
			member.theme_name=Convert.ToInt32(vecLine[3]);
			member.update_time=vecLine[4];
			member.settlement_time=vecLine[5];
			member.billing_empty=Convert.ToInt32(vecLine[6]);
			member.enable=Convert.ToInt32(vecLine[7]);
			member.sort_index=vecLine[8];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
