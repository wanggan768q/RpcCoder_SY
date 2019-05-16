using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//竞技场结算奖励配置数据类
public class ArenaRewardElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int stage_name;       	//段位名称	文本ID
	public int stage;            	//段位类型	暂时不用
	public int required_star;    	//星级	升到下一段位需要获得的星数
	public string comment_next;  	//备注	下赛季对应的段位
	public int next_season_stage;	//段位	下赛季继承的对应段位的ID序号
	public int next_season_required_star;	//星级	下赛季继承段位的初始星数
	public li round_win_reward1_id;	//单场奖励1（胜利）	道具ID|数量|是否需要中转
	public li round_win_reward2_id;	//单场奖励2（胜利）	道具ID|数量|是否需要中转
	public li round_win_reward3_id;	//单场奖励3（胜利）	道具ID|数量|是否需要中转
	public li round_win_reward4_id;	//单场奖励4（胜利）	道具ID|数量|是否需要中转
	public li round_win_reward5_id;	//单场奖励1（失败）	道具ID|数量|是否需要中转
	public li round_win_reward6_id;	//单场奖励2（失败）	道具ID|数量|是否需要中转
	public li round_win_reward7_id;	//单场奖励3（失败）	道具ID|数量|是否需要中转
	public li round_win_reward8_id;	//单场奖励4（失败）	道具ID|数量|是否需要中转
	public li season_reward1_id; 	//本赛季最高段位奖励1	道具ID|数量|是否需要中转
	public li season_reward2_id; 	//本赛季最高段位奖励2	道具ID|数量|是否需要中转
	public li season_reward3_id; 	//本赛季最高段位奖励3	道具ID|数量|是否需要中转
	public li season_reward4_id; 	//本赛季最高段位奖励4	道具ID|数量|是否需要中转
	public string icon;          	//图标	图标

	public bool IsValidate = false;
	public ArenaRewardElement()
	{
		id = -1;
	}
};

//竞技场结算奖励配置封装类
public class ArenaRewardTable
{

	private ArenaRewardTable()
	{
		m_mapElements = new Dictionary<int, ArenaRewardElement>();
		m_emptyItem = new ArenaRewardElement();
		m_vecAllElements = new List<ArenaRewardElement>();
	}
	private Dictionary<int, ArenaRewardElement> m_mapElements = null;
	private List<ArenaRewardElement>	m_vecAllElements = null;
	private ArenaRewardElement m_emptyItem = null;
	private static ArenaRewardTable sInstance = null;

	public static ArenaRewardTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ArenaRewardTable();
			return sInstance;
		}
	}

	public ArenaRewardElement GetElement(int key)
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

  public List<ArenaRewardElement> GetAllElement(Predicate<ArenaRewardElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ArenaReward.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ArenaReward.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ArenaReward.bin]未找到");
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
		if(vecLine.Count != 21)
		{
			Ex.Logger.Log("ArenaReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ArenaReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ArenaReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="stage_name"){Ex.Logger.Log("ArenaReward.csv中字段[stage_name]位置不对应"); return false; }
		if(vecLine[3]!="stage"){Ex.Logger.Log("ArenaReward.csv中字段[stage]位置不对应"); return false; }
		if(vecLine[4]!="required_star"){Ex.Logger.Log("ArenaReward.csv中字段[required_star]位置不对应"); return false; }
		if(vecLine[5]!="comment_next"){Ex.Logger.Log("ArenaReward.csv中字段[comment_next]位置不对应"); return false; }
		if(vecLine[6]!="next_season_stage"){Ex.Logger.Log("ArenaReward.csv中字段[next_season_stage]位置不对应"); return false; }
		if(vecLine[7]!="next_season_required_star"){Ex.Logger.Log("ArenaReward.csv中字段[next_season_required_star]位置不对应"); return false; }
		if(vecLine[8]!="round_win_reward1_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward1_id]位置不对应"); return false; }
		if(vecLine[9]!="round_win_reward2_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward2_id]位置不对应"); return false; }
		if(vecLine[10]!="round_win_reward3_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward3_id]位置不对应"); return false; }
		if(vecLine[11]!="round_win_reward4_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward4_id]位置不对应"); return false; }
		if(vecLine[12]!="round_win_reward5_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward5_id]位置不对应"); return false; }
		if(vecLine[13]!="round_win_reward6_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward6_id]位置不对应"); return false; }
		if(vecLine[14]!="round_win_reward7_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward7_id]位置不对应"); return false; }
		if(vecLine[15]!="round_win_reward8_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward8_id]位置不对应"); return false; }
		if(vecLine[16]!="season_reward1_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward1_id]位置不对应"); return false; }
		if(vecLine[17]!="season_reward2_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward2_id]位置不对应"); return false; }
		if(vecLine[18]!="season_reward3_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward3_id]位置不对应"); return false; }
		if(vecLine[19]!="season_reward4_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward4_id]位置不对应"); return false; }
		if(vecLine[20]!="icon"){Ex.Logger.Log("ArenaReward.csv中字段[icon]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ArenaRewardElement member = new ArenaRewardElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stage_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stage );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_star );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment_next);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_season_stage );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_season_required_star );
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward4_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward5_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward6_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward7_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.round_win_reward8_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.season_reward4_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);

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
		if(vecLine.Count != 21)
		{
			Ex.Logger.Log("ArenaReward.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ArenaReward.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ArenaReward.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="stage_name"){Ex.Logger.Log("ArenaReward.csv中字段[stage_name]位置不对应"); return false; }
		if(vecLine[3]!="stage"){Ex.Logger.Log("ArenaReward.csv中字段[stage]位置不对应"); return false; }
		if(vecLine[4]!="required_star"){Ex.Logger.Log("ArenaReward.csv中字段[required_star]位置不对应"); return false; }
		if(vecLine[5]!="comment_next"){Ex.Logger.Log("ArenaReward.csv中字段[comment_next]位置不对应"); return false; }
		if(vecLine[6]!="next_season_stage"){Ex.Logger.Log("ArenaReward.csv中字段[next_season_stage]位置不对应"); return false; }
		if(vecLine[7]!="next_season_required_star"){Ex.Logger.Log("ArenaReward.csv中字段[next_season_required_star]位置不对应"); return false; }
		if(vecLine[8]!="round_win_reward1_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward1_id]位置不对应"); return false; }
		if(vecLine[9]!="round_win_reward2_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward2_id]位置不对应"); return false; }
		if(vecLine[10]!="round_win_reward3_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward3_id]位置不对应"); return false; }
		if(vecLine[11]!="round_win_reward4_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward4_id]位置不对应"); return false; }
		if(vecLine[12]!="round_win_reward5_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward5_id]位置不对应"); return false; }
		if(vecLine[13]!="round_win_reward6_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward6_id]位置不对应"); return false; }
		if(vecLine[14]!="round_win_reward7_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward7_id]位置不对应"); return false; }
		if(vecLine[15]!="round_win_reward8_id"){Ex.Logger.Log("ArenaReward.csv中字段[round_win_reward8_id]位置不对应"); return false; }
		if(vecLine[16]!="season_reward1_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward1_id]位置不对应"); return false; }
		if(vecLine[17]!="season_reward2_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward2_id]位置不对应"); return false; }
		if(vecLine[18]!="season_reward3_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward3_id]位置不对应"); return false; }
		if(vecLine[19]!="season_reward4_id"){Ex.Logger.Log("ArenaReward.csv中字段[season_reward4_id]位置不对应"); return false; }
		if(vecLine[20]!="icon"){Ex.Logger.Log("ArenaReward.csv中字段[icon]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)21)
			{
				return false;
			}
			ArenaRewardElement member = new ArenaRewardElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.stage_name=Convert.ToInt32(vecLine[2]);
			member.stage=Convert.ToInt32(vecLine[3]);
			member.required_star=Convert.ToInt32(vecLine[4]);
			member.comment_next=vecLine[5];
			member.next_season_stage=Convert.ToInt32(vecLine[6]);
			member.next_season_required_star=Convert.ToInt32(vecLine[7]);
			member.round_win_reward1_id=vecLine[8];
			member.round_win_reward2_id=vecLine[9];
			member.round_win_reward3_id=vecLine[10];
			member.round_win_reward4_id=vecLine[11];
			member.round_win_reward5_id=vecLine[12];
			member.round_win_reward6_id=vecLine[13];
			member.round_win_reward7_id=vecLine[14];
			member.round_win_reward8_id=vecLine[15];
			member.season_reward1_id=vecLine[16];
			member.season_reward2_id=vecLine[17];
			member.season_reward3_id=vecLine[18];
			member.season_reward4_id=vecLine[19];
			member.icon=vecLine[20];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
