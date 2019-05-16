using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//活动奖励表配置数据类
public class ActivityRewardElement
{
	public int id;               	//主键id	活动奖励id
	public string comment;       	//注释	活跃度奖励
	public int active_value;     	//活跃度	
	public string icon;          	//宝箱图标	
	public string icon_open;     	//宝箱图标开启后	
	public int quest_id;         	//奖励包id	

	public bool IsValidate = false;
	public ActivityRewardElement()
	{
		id = -1;
	}
};

//活动奖励表配置封装类
public class ActivityRewardTable
{

	private ActivityRewardTable()
	{
		m_mapElements = new Dictionary<int, ActivityRewardElement>();
		m_emptyItem = new ActivityRewardElement();
		m_vecAllElements = new List<ActivityRewardElement>();
	}
	private Dictionary<int, ActivityRewardElement> m_mapElements = null;
	private List<ActivityRewardElement>	m_vecAllElements = null;
	private ActivityRewardElement m_emptyItem = null;
	private static ActivityRewardTable sInstance = null;

	public static ActivityRewardTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ActivityRewardTable();
			return sInstance;
		}
	}

	public ActivityRewardElement GetElement(int key)
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

  public List<ActivityRewardElement> GetAllElement(Predicate<ActivityRewardElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ActivityReward.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ActivityReward.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ActivityReward.bin]未找到");
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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("ActivityReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivityReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivityReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="active_value"){Ex.Logger.Log("ActivityReward.csv中字段[active_value]位置不对应"); return false; }
		if(vecLine[3]!="icon"){Ex.Logger.Log("ActivityReward.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[4]!="icon_open"){Ex.Logger.Log("ActivityReward.csv中字段[icon_open]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("ActivityReward.csv中字段[quest_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ActivityRewardElement member = new ActivityRewardElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.active_value );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon_open);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );

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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("ActivityReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivityReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivityReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="active_value"){Ex.Logger.Log("ActivityReward.csv中字段[active_value]位置不对应"); return false; }
		if(vecLine[3]!="icon"){Ex.Logger.Log("ActivityReward.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[4]!="icon_open"){Ex.Logger.Log("ActivityReward.csv中字段[icon_open]位置不对应"); return false; }
		if(vecLine[5]!="quest_id"){Ex.Logger.Log("ActivityReward.csv中字段[quest_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			ActivityRewardElement member = new ActivityRewardElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.active_value=Convert.ToInt32(vecLine[2]);
			member.icon=vecLine[3];
			member.icon_open=vecLine[4];
			member.quest_id=Convert.ToInt32(vecLine[5]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
