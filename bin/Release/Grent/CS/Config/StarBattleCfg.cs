using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//星耀王座配置数据类
public class StarBattleElement
{
	public int id;               	//主键id	进入npc的id乘以10+1
	public string comment;       	//备注	
	public int scene_id;         	//场景id	
	public int npc_id;           	//npc id	进入镜像的npc id
	public int survival_tm;      	//npc存活时长	npc在场景存活的时长 单位：分钟
	public li mirror_id;         	//镜像id	通过npc进入的镜像id
	public li waypoint_id;       	//路点id	随机刷新的路点
	public int team_num;         	//队伍数量	同一个npc可以进入最大的队伍数量
	public string refresh;       	//刷新时间	宠物npc在第一个场景刷新的时间
	public int reward;           	//普通奖励	奖励id
	public li high_reward;       	//高额奖励	前n名完成的队伍获得高额奖励 奖励id|数量

	public bool IsValidate = false;
	public StarBattleElement()
	{
		id = -1;
	}
};

//星耀王座配置封装类
public class StarBattleTable
{

	private StarBattleTable()
	{
		m_mapElements = new Dictionary<int, StarBattleElement>();
		m_emptyItem = new StarBattleElement();
		m_vecAllElements = new List<StarBattleElement>();
	}
	private Dictionary<int, StarBattleElement> m_mapElements = null;
	private List<StarBattleElement>	m_vecAllElements = null;
	private StarBattleElement m_emptyItem = null;
	private static StarBattleTable sInstance = null;

	public static StarBattleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new StarBattleTable();
			return sInstance;
		}
	}

	public StarBattleElement GetElement(int key)
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

  public List<StarBattleElement> GetAllElement(Predicate<StarBattleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("StarBattle.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("StarBattle.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[StarBattle.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("StarBattle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StarBattle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StarBattle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="scene_id"){Ex.Logger.Log("StarBattle.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[3]!="npc_id"){Ex.Logger.Log("StarBattle.csv中字段[npc_id]位置不对应"); return false; }
		if(vecLine[4]!="survival_tm"){Ex.Logger.Log("StarBattle.csv中字段[survival_tm]位置不对应"); return false; }
		if(vecLine[5]!="mirror_id"){Ex.Logger.Log("StarBattle.csv中字段[mirror_id]位置不对应"); return false; }
		if(vecLine[6]!="waypoint_id"){Ex.Logger.Log("StarBattle.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[7]!="team_num"){Ex.Logger.Log("StarBattle.csv中字段[team_num]位置不对应"); return false; }
		if(vecLine[8]!="refresh"){Ex.Logger.Log("StarBattle.csv中字段[refresh]位置不对应"); return false; }
		if(vecLine[9]!="reward"){Ex.Logger.Log("StarBattle.csv中字段[reward]位置不对应"); return false; }
		if(vecLine[10]!="high_reward"){Ex.Logger.Log("StarBattle.csv中字段[high_reward]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			StarBattleElement member = new StarBattleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.survival_tm );
			readPos += GameAssist.ReadString( binContent, readPos, out member.mirror_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.waypoint_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.team_num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.refresh);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reward );
			readPos += GameAssist.ReadString( binContent, readPos, out member.high_reward);

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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("StarBattle.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("StarBattle.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("StarBattle.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="scene_id"){Ex.Logger.Log("StarBattle.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[3]!="npc_id"){Ex.Logger.Log("StarBattle.csv中字段[npc_id]位置不对应"); return false; }
		if(vecLine[4]!="survival_tm"){Ex.Logger.Log("StarBattle.csv中字段[survival_tm]位置不对应"); return false; }
		if(vecLine[5]!="mirror_id"){Ex.Logger.Log("StarBattle.csv中字段[mirror_id]位置不对应"); return false; }
		if(vecLine[6]!="waypoint_id"){Ex.Logger.Log("StarBattle.csv中字段[waypoint_id]位置不对应"); return false; }
		if(vecLine[7]!="team_num"){Ex.Logger.Log("StarBattle.csv中字段[team_num]位置不对应"); return false; }
		if(vecLine[8]!="refresh"){Ex.Logger.Log("StarBattle.csv中字段[refresh]位置不对应"); return false; }
		if(vecLine[9]!="reward"){Ex.Logger.Log("StarBattle.csv中字段[reward]位置不对应"); return false; }
		if(vecLine[10]!="high_reward"){Ex.Logger.Log("StarBattle.csv中字段[high_reward]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			StarBattleElement member = new StarBattleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.scene_id=Convert.ToInt32(vecLine[2]);
			member.npc_id=Convert.ToInt32(vecLine[3]);
			member.survival_tm=Convert.ToInt32(vecLine[4]);
			member.mirror_id=vecLine[5];
			member.waypoint_id=vecLine[6];
			member.team_num=Convert.ToInt32(vecLine[7]);
			member.refresh=vecLine[8];
			member.reward=Convert.ToInt32(vecLine[9]);
			member.high_reward=vecLine[10];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
