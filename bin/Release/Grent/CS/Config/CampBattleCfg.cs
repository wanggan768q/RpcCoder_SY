using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//阵营战军衔配置数据类
public class CampBattleElement
{
	public int id;               	//军衔ID	每个军衔所对应的唯一ID 军衔ID 不要变 从1开始顺序往下 中间不留空号
	public string comment;       	//注释	策划用
	public int rank_name;        	//段位名称	文本ID
	public int rank;             	//军阶级别	军阶级别对应的ID
	public string rank_picture;  	//军阶图片	军阶对应图标的图片资源
	public int stars;            	//星级	一个级别中所包含的星数
	public int stat_rankvalue;   	//升星军衔值	升星所消耗的军衔值
	public li break_reward;      	//突破奖励	突破时所获得的奖励（ 道具ID1|道具ID2|道具ID3）
	public li break_num;         	//突破奖励数量	突破时所获得的道具的数量，需与ID对应（道具数量1|道具数量2|道具数量3）
	public li season_award;      	//赛季奖励	赛季结束时所获得的奖励（赛季奖励道具ID1|赛季奖励道具ID2|赛季奖励道具ID3）
	public li season_num;        	//赛季奖励数量	赛季结束时所获得的奖励道具数量（赛季奖励道具数量1|赛季奖励道具数量2|赛季奖励道具数量3）
	public li high_award;        	//赛季高级奖励	赛季结束时所获得的高级奖励（赛季奖励道具ID1|赛季奖励道具ID2|赛季奖励道具ID3）
	public li high_num;          	//赛季高级奖励数量	赛季结束时所获得的高级奖励道具数量（赛季奖励道具数量1|赛季奖励道具数量2|赛季奖励道具数量3）

	public bool IsValidate = false;
	public CampBattleElement()
	{
		id = -1;
	}
};

//阵营战军衔配置封装类
public class CampBattleTable
{

	private CampBattleTable()
	{
		m_mapElements = new Dictionary<int, CampBattleElement>();
		m_emptyItem = new CampBattleElement();
		m_vecAllElements = new List<CampBattleElement>();
	}
	private Dictionary<int, CampBattleElement> m_mapElements = null;
	private List<CampBattleElement>	m_vecAllElements = null;
	private CampBattleElement m_emptyItem = null;
	private static CampBattleTable sInstance = null;

	public static CampBattleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CampBattleTable();
			return sInstance;
		}
	}

	public CampBattleElement GetElement(int key)
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

  public List<CampBattleElement> GetAllElement(Predicate<CampBattleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CampBattle.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CampBattle.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CampBattle.bin]未找到");
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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("CampBattle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CampBattle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CampBattle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_name"){Ex.Logger.Log("CampBattle.csv中字段[rank_name]位置不对应"); return false; }
		if(vecLine[3]!="rank"){Ex.Logger.Log("CampBattle.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[4]!="rank_picture"){Ex.Logger.Log("CampBattle.csv中字段[rank_picture]位置不对应"); return false; }
		if(vecLine[5]!="stars"){Ex.Logger.Log("CampBattle.csv中字段[stars]位置不对应"); return false; }
		if(vecLine[6]!="stat_rankvalue"){Ex.Logger.Log("CampBattle.csv中字段[stat_rankvalue]位置不对应"); return false; }
		if(vecLine[7]!="break_reward"){Ex.Logger.Log("CampBattle.csv中字段[break_reward]位置不对应"); return false; }
		if(vecLine[8]!="break_num"){Ex.Logger.Log("CampBattle.csv中字段[break_num]位置不对应"); return false; }
		if(vecLine[9]!="season_award"){Ex.Logger.Log("CampBattle.csv中字段[season_award]位置不对应"); return false; }
		if(vecLine[10]!="season_num"){Ex.Logger.Log("CampBattle.csv中字段[season_num]位置不对应"); return false; }
		if(vecLine[11]!="high_award"){Ex.Logger.Log("CampBattle.csv中字段[high_award]位置不对应"); return false; }
		if(vecLine[12]!="high_num"){Ex.Logger.Log("CampBattle.csv中字段[high_num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CampBattleElement member = new CampBattleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rank_picture);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stars );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stat_rankvalue );
			readPos += GameAssist.ReadString( binContent, readPos, out member.break_reward);
			readPos += GameAssist.ReadString( binContent, readPos, out member.break_num);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_award);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_num);
			readPos += GameAssist.ReadString( binContent, readPos, out member.high_award);
			readPos += GameAssist.ReadString( binContent, readPos, out member.high_num);

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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("CampBattle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CampBattle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CampBattle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank_name"){Ex.Logger.Log("CampBattle.csv中字段[rank_name]位置不对应"); return false; }
		if(vecLine[3]!="rank"){Ex.Logger.Log("CampBattle.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[4]!="rank_picture"){Ex.Logger.Log("CampBattle.csv中字段[rank_picture]位置不对应"); return false; }
		if(vecLine[5]!="stars"){Ex.Logger.Log("CampBattle.csv中字段[stars]位置不对应"); return false; }
		if(vecLine[6]!="stat_rankvalue"){Ex.Logger.Log("CampBattle.csv中字段[stat_rankvalue]位置不对应"); return false; }
		if(vecLine[7]!="break_reward"){Ex.Logger.Log("CampBattle.csv中字段[break_reward]位置不对应"); return false; }
		if(vecLine[8]!="break_num"){Ex.Logger.Log("CampBattle.csv中字段[break_num]位置不对应"); return false; }
		if(vecLine[9]!="season_award"){Ex.Logger.Log("CampBattle.csv中字段[season_award]位置不对应"); return false; }
		if(vecLine[10]!="season_num"){Ex.Logger.Log("CampBattle.csv中字段[season_num]位置不对应"); return false; }
		if(vecLine[11]!="high_award"){Ex.Logger.Log("CampBattle.csv中字段[high_award]位置不对应"); return false; }
		if(vecLine[12]!="high_num"){Ex.Logger.Log("CampBattle.csv中字段[high_num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)13)
			{
				return false;
			}
			CampBattleElement member = new CampBattleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.rank_name=Convert.ToInt32(vecLine[2]);
			member.rank=Convert.ToInt32(vecLine[3]);
			member.rank_picture=vecLine[4];
			member.stars=Convert.ToInt32(vecLine[5]);
			member.stat_rankvalue=Convert.ToInt32(vecLine[6]);
			member.break_reward=vecLine[7];
			member.break_num=vecLine[8];
			member.season_award=vecLine[9];
			member.season_num=vecLine[10];
			member.high_award=vecLine[11];
			member.high_num=vecLine[12];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
