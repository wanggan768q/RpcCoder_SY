using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//等级奖励表配置数据类
public class LevelUpBonusElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int required_lv;      	//需求角色等级	
	public li lv_reward1_id;     	//等级奖励1	道具ID|数量|是否需要中转
	public li lv_reward2_id;     	//等级奖励2	道具ID|数量|是否需要中转
	public li lv_reward3_id;     	//等级奖励3	道具ID|数量|是否需要中转
	public li lv_reward4_id;     	//等级奖励4	道具ID|数量|是否需要中转

	public bool IsValidate = false;
	public LevelUpBonusElement()
	{
		id = -1;
	}
};

//等级奖励表配置封装类
public class LevelUpBonusTable
{

	private LevelUpBonusTable()
	{
		m_mapElements = new Dictionary<int, LevelUpBonusElement>();
		m_emptyItem = new LevelUpBonusElement();
		m_vecAllElements = new List<LevelUpBonusElement>();
	}
	private Dictionary<int, LevelUpBonusElement> m_mapElements = null;
	private List<LevelUpBonusElement>	m_vecAllElements = null;
	private LevelUpBonusElement m_emptyItem = null;
	private static LevelUpBonusTable sInstance = null;

	public static LevelUpBonusTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LevelUpBonusTable();
			return sInstance;
		}
	}

	public LevelUpBonusElement GetElement(int key)
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

  public List<LevelUpBonusElement> GetAllElement(Predicate<LevelUpBonusElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("LevelUpBonus.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("LevelUpBonus.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[LevelUpBonus.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("LevelUpBonus.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LevelUpBonus.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LevelUpBonus.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_lv"){Ex.Logger.Log("LevelUpBonus.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[3]!="lv_reward1_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward1_id]位置不对应"); return false; }
		if(vecLine[4]!="lv_reward2_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward2_id]位置不对应"); return false; }
		if(vecLine[5]!="lv_reward3_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward3_id]位置不对应"); return false; }
		if(vecLine[6]!="lv_reward4_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward4_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LevelUpBonusElement member = new LevelUpBonusElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_lv );
			readPos += GameAssist.ReadString( binContent, readPos, out member.lv_reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.lv_reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.lv_reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.lv_reward4_id);

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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("LevelUpBonus.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LevelUpBonus.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LevelUpBonus.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_lv"){Ex.Logger.Log("LevelUpBonus.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[3]!="lv_reward1_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward1_id]位置不对应"); return false; }
		if(vecLine[4]!="lv_reward2_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward2_id]位置不对应"); return false; }
		if(vecLine[5]!="lv_reward3_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward3_id]位置不对应"); return false; }
		if(vecLine[6]!="lv_reward4_id"){Ex.Logger.Log("LevelUpBonus.csv中字段[lv_reward4_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			LevelUpBonusElement member = new LevelUpBonusElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.required_lv=Convert.ToInt32(vecLine[2]);
			member.lv_reward1_id=vecLine[3];
			member.lv_reward2_id=vecLine[4];
			member.lv_reward3_id=vecLine[5];
			member.lv_reward4_id=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
