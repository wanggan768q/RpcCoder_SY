using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//竞技场排行奖励配置数据类
public class ArenaRankRewardElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int rank_min;         	//最低区间	最低区间
	public int rank_max;         	//最高区间	最高区间
	public li reward1_id;        	//排名奖励1	道具ID|数量|是否需要中转
	public li reward2_id;        	//排名奖励2	道具ID|数量|是否需要中转
	public li reward3_id;        	//排名奖励3	道具ID|数量|是否需要中转
	public li reward4_id;        	//排名奖励4	道具ID|数量|是否需要中转

	public bool IsValidate = false;
	public ArenaRankRewardElement()
	{
		id = -1;
	}
};

//竞技场排行奖励配置封装类
public class ArenaRankRewardTable
{

	private ArenaRankRewardTable()
	{
		m_mapElements = new Dictionary<int, ArenaRankRewardElement>();
		m_emptyItem = new ArenaRankRewardElement();
		m_vecAllElements = new List<ArenaRankRewardElement>();
	}
	private Dictionary<int, ArenaRankRewardElement> m_mapElements = null;
	private List<ArenaRankRewardElement>	m_vecAllElements = null;
	private ArenaRankRewardElement m_emptyItem = null;
	private static ArenaRankRewardTable sInstance = null;

	public static ArenaRankRewardTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ArenaRankRewardTable();
			return sInstance;
		}
	}

	public ArenaRankRewardElement GetElement(int key)
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

  public List<ArenaRankRewardElement> GetAllElement(Predicate<ArenaRankRewardElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ArenaRankReward.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ArenaRankReward.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ArenaRankReward.bin]未找到");
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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("ArenaRankReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ArenaRankReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ArenaRankReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_min"){Ex.Logger.Log("ArenaRankReward.csv中字段[rank_min]位置不对应"); return false; }
		if(vecLine[3]!="rank_max"){Ex.Logger.Log("ArenaRankReward.csv中字段[rank_max]位置不对应"); return false; }
		if(vecLine[4]!="reward1_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward1_id]位置不对应"); return false; }
		if(vecLine[5]!="reward2_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward2_id]位置不对应"); return false; }
		if(vecLine[6]!="reward3_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward3_id]位置不对应"); return false; }
		if(vecLine[7]!="reward4_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward4_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ArenaRankRewardElement member = new ArenaRankRewardElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank_min );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank_max );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward4_id);

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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("ArenaRankReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ArenaRankReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ArenaRankReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_min"){Ex.Logger.Log("ArenaRankReward.csv中字段[rank_min]位置不对应"); return false; }
		if(vecLine[3]!="rank_max"){Ex.Logger.Log("ArenaRankReward.csv中字段[rank_max]位置不对应"); return false; }
		if(vecLine[4]!="reward1_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward1_id]位置不对应"); return false; }
		if(vecLine[5]!="reward2_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward2_id]位置不对应"); return false; }
		if(vecLine[6]!="reward3_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward3_id]位置不对应"); return false; }
		if(vecLine[7]!="reward4_id"){Ex.Logger.Log("ArenaRankReward.csv中字段[reward4_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			ArenaRankRewardElement member = new ArenaRankRewardElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.rank_min=Convert.ToInt32(vecLine[2]);
			member.rank_max=Convert.ToInt32(vecLine[3]);
			member.reward1_id=vecLine[4];
			member.reward2_id=vecLine[5];
			member.reward3_id=vecLine[6];
			member.reward4_id=vecLine[7];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
