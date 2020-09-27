using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//召唤小怪表配置数据类
public class SummonMonsterElement
{
	public int id;               	//同一个召唤组共享仇恨	同一个召唤组共享仇恨
	public int type;             	//类型，0固定位置，1随机，2召唤者位置偏移生成 ，3技能目标脚下生成	类型，0固定位置，1随机，2召唤者位置偏移生成
	public int npc_entry_id;     	//NPC总表中的ENTRY ID	NPC总表中的ENTRY ID
	public int num;              	//数量	数量
	public li pars;              	//参数，随机填半径，0原点
如果是召唤者位置偏移，填X|Z，一次召唤多个就顺序填，比如召唤2个，那么位置必须填成X1|Z1|X2|Z2	固定位置，路点id
	public int dead_delete;      	//主人死亡是否删除，0不删除	主人死亡是否删除，0不删除
	public int leave_fight_delete;	//脱战是否删除，0不删除	脱战是否删除，0不删除
	public int alive_time;       	//存活时间，-1无限，单位S	存活时间，-1无限，单位S
	public int max_num;          	//上限，达到上限不召唤	上限，达到上限不召唤
	public int group_id;         	//给召唤ID分组，ID相同的为同组，同组内共享召唤上限，取组内召唤上限的最小值	给召唤ID分组，ID相同的为同组，同组内共享召唤上限，取组内召唤上限的最小值
	public int follow_switch;    	//跟随切换地图，仅玩家角色召唤的怪物生效	0不跟随，1跟随

	public bool IsValidate = false;
	public SummonMonsterElement()
	{
		id = -1;
	}
};

//召唤小怪表配置封装类
public class SummonMonsterTable
{

	private SummonMonsterTable()
	{
		m_mapElements = new Dictionary<int, SummonMonsterElement>();
		m_emptyItem = new SummonMonsterElement();
		m_vecAllElements = new List<SummonMonsterElement>();
	}
	private Dictionary<int, SummonMonsterElement> m_mapElements = null;
	private List<SummonMonsterElement>	m_vecAllElements = null;
	private SummonMonsterElement m_emptyItem = null;
	private static SummonMonsterTable sInstance = null;

	public static SummonMonsterTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SummonMonsterTable();
			return sInstance;
		}
	}

	public SummonMonsterElement GetElement(int key)
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

  public List<SummonMonsterElement> GetAllElement(Predicate<SummonMonsterElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SummonMonster.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SummonMonster.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SummonMonster.bin]未找到");
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
			Ex.Logger.Log("SummonMonster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SummonMonster.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("SummonMonster.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="npc_entry_id"){Ex.Logger.Log("SummonMonster.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[3]!="num"){Ex.Logger.Log("SummonMonster.csv中字段[num]位置不对应"); return false; }
		if(vecLine[4]!="pars"){Ex.Logger.Log("SummonMonster.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[5]!="dead_delete"){Ex.Logger.Log("SummonMonster.csv中字段[dead_delete]位置不对应"); return false; }
		if(vecLine[6]!="leave_fight_delete"){Ex.Logger.Log("SummonMonster.csv中字段[leave_fight_delete]位置不对应"); return false; }
		if(vecLine[7]!="alive_time"){Ex.Logger.Log("SummonMonster.csv中字段[alive_time]位置不对应"); return false; }
		if(vecLine[8]!="max_num"){Ex.Logger.Log("SummonMonster.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[9]!="group_id"){Ex.Logger.Log("SummonMonster.csv中字段[group_id]位置不对应"); return false; }
		if(vecLine[10]!="follow_switch"){Ex.Logger.Log("SummonMonster.csv中字段[follow_switch]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SummonMonsterElement member = new SummonMonsterElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_entry_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.num );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dead_delete );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_fight_delete );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.alive_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.group_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.follow_switch );

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
			Ex.Logger.Log("SummonMonster.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SummonMonster.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="type"){Ex.Logger.Log("SummonMonster.csv中字段[type]位置不对应"); return false; }
		if(vecLine[2]!="npc_entry_id"){Ex.Logger.Log("SummonMonster.csv中字段[npc_entry_id]位置不对应"); return false; }
		if(vecLine[3]!="num"){Ex.Logger.Log("SummonMonster.csv中字段[num]位置不对应"); return false; }
		if(vecLine[4]!="pars"){Ex.Logger.Log("SummonMonster.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[5]!="dead_delete"){Ex.Logger.Log("SummonMonster.csv中字段[dead_delete]位置不对应"); return false; }
		if(vecLine[6]!="leave_fight_delete"){Ex.Logger.Log("SummonMonster.csv中字段[leave_fight_delete]位置不对应"); return false; }
		if(vecLine[7]!="alive_time"){Ex.Logger.Log("SummonMonster.csv中字段[alive_time]位置不对应"); return false; }
		if(vecLine[8]!="max_num"){Ex.Logger.Log("SummonMonster.csv中字段[max_num]位置不对应"); return false; }
		if(vecLine[9]!="group_id"){Ex.Logger.Log("SummonMonster.csv中字段[group_id]位置不对应"); return false; }
		if(vecLine[10]!="follow_switch"){Ex.Logger.Log("SummonMonster.csv中字段[follow_switch]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			SummonMonsterElement member = new SummonMonsterElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.type=Convert.ToInt32(vecLine[1]);
			member.npc_entry_id=Convert.ToInt32(vecLine[2]);
			member.num=Convert.ToInt32(vecLine[3]);
			member.pars=vecLine[4];
			member.dead_delete=Convert.ToInt32(vecLine[5]);
			member.leave_fight_delete=Convert.ToInt32(vecLine[6]);
			member.alive_time=Convert.ToInt32(vecLine[7]);
			member.max_num=Convert.ToInt32(vecLine[8]);
			member.group_id=Convert.ToInt32(vecLine[9]);
			member.follow_switch=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
