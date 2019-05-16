using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//七日目标详情表配置数据类
public class ActivitySevenDayTargetDetailsElement
{
	public int id;               	//目标ID	活动id
	public string comment;       	//注释	策划用
	public int target_group_id;  	//前置目标ID	对应本表的活动ID，配置了此列数据后，需要前置活动奖励领取完成后，才会显示。
	public int quest_id;         	//任务id	对应任务表中的ID
	public int describe_id;      	//描述文本id	只用于界面上显示
	public int describe_num;     	//目标最大计数	只用于界面上显示
	public li drop_display;      	//奖励显示	只用于界面上显示
	public int point_reward;     	//奖励积分（没用）	完成任务后奖励给玩家的积分数量
	public int uicategory_id;    	//前往界面ID（客户端用）	对应界面类型表中的ID

	public bool IsValidate = false;
	public ActivitySevenDayTargetDetailsElement()
	{
		id = -1;
	}
};

//七日目标详情表配置封装类
public class ActivitySevenDayTargetDetailsTable
{

	private ActivitySevenDayTargetDetailsTable()
	{
		m_mapElements = new Dictionary<int, ActivitySevenDayTargetDetailsElement>();
		m_emptyItem = new ActivitySevenDayTargetDetailsElement();
		m_vecAllElements = new List<ActivitySevenDayTargetDetailsElement>();
	}
	private Dictionary<int, ActivitySevenDayTargetDetailsElement> m_mapElements = null;
	private List<ActivitySevenDayTargetDetailsElement>	m_vecAllElements = null;
	private ActivitySevenDayTargetDetailsElement m_emptyItem = null;
	private static ActivitySevenDayTargetDetailsTable sInstance = null;

	public static ActivitySevenDayTargetDetailsTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ActivitySevenDayTargetDetailsTable();
			return sInstance;
		}
	}

	public ActivitySevenDayTargetDetailsElement GetElement(int key)
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

  public List<ActivitySevenDayTargetDetailsElement> GetAllElement(Predicate<ActivitySevenDayTargetDetailsElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ActivitySevenDayTargetDetails.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ActivitySevenDayTargetDetails.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ActivitySevenDayTargetDetails.bin]未找到");
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
			Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="target_group_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[target_group_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[4]!="describe_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[5]!="describe_num"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[describe_num]位置不对应"); return false; }
		if(vecLine[6]!="drop_display"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[drop_display]位置不对应"); return false; }
		if(vecLine[7]!="point_reward"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[point_reward]位置不对应"); return false; }
		if(vecLine[8]!="uicategory_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[uicategory_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ActivitySevenDayTargetDetailsElement member = new ActivitySevenDayTargetDetailsElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_group_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describe_num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_display);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.point_reward );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.uicategory_id );

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
			Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="target_group_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[target_group_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[4]!="describe_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[describe_id]位置不对应"); return false; }
		if(vecLine[5]!="describe_num"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[describe_num]位置不对应"); return false; }
		if(vecLine[6]!="drop_display"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[drop_display]位置不对应"); return false; }
		if(vecLine[7]!="point_reward"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[point_reward]位置不对应"); return false; }
		if(vecLine[8]!="uicategory_id"){Ex.Logger.Log("ActivitySevenDayTargetDetails.csv中字段[uicategory_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			ActivitySevenDayTargetDetailsElement member = new ActivitySevenDayTargetDetailsElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.target_group_id=Convert.ToInt32(vecLine[2]);
			member.quest_id=Convert.ToInt32(vecLine[3]);
			member.describe_id=Convert.ToInt32(vecLine[4]);
			member.describe_num=Convert.ToInt32(vecLine[5]);
			member.drop_display=vecLine[6];
			member.point_reward=Convert.ToInt32(vecLine[7]);
			member.uicategory_id=Convert.ToInt32(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
