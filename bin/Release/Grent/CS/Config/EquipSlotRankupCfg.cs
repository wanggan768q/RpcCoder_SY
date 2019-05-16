using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备升星配置数据类
public class EquipSlotRankupElement
{
	public int id;               	//星级ID	每个阶级所对应的唯一ID
	public string comment;       	//阶级注释	策划用
	public int rank;             	//符文数量	当前等级显示用
	public int level;            	//星级数量	当前等级显示用
	public float rankup_rate;    	//成功率	升至下级需要 1表示100%
	public float rankdown_rate;  	//降级率	升至下级需要 1表示100%
	public li rankup_require;    	//升星道具	升至下级需要 道具id|道具数量
	public li safe_rankup_require;	//保底升星道具	升至下级需要 道具id|道具数量
	public int attribute;        	//属性成长	当前级别 属性成长百分比 1表示1%
	public int unlock_needed;    	//需要解锁	当前级别需求 该等级需要解锁
	public int slot_1_requirement;	//解锁需求	当前级别武器栏解锁需要达到的爬塔等级
	public int slot_2_requirement;	//解锁需求	当前级别耳坠解锁需要达到的爬塔等级
	public int slot_3_requirement;	//解锁需求	当前级别项链解锁需要达到的爬塔等级
	public int slot_4_requirement;	//解锁需求	当前级别戒指解锁需要达到的爬塔等级
	public int slot_5_requirement;	//解锁需求	当前级别头盔解锁需要达到的爬塔等级
	public int slot_6_requirement;	//解锁需求	当前级别胸甲解锁需要达到的爬塔等级
	public int slot_7_requirement;	//解锁需求	当前级别臂甲解锁需要达到的爬塔等级
	public int slot_8_requirement;	//解锁需求	当前级别腿甲解锁需要达到的爬塔等级

	public bool IsValidate = false;
	public EquipSlotRankupElement()
	{
		id = -1;
	}
};

//装备升星配置封装类
public class EquipSlotRankupTable
{

	private EquipSlotRankupTable()
	{
		m_mapElements = new Dictionary<int, EquipSlotRankupElement>();
		m_emptyItem = new EquipSlotRankupElement();
		m_vecAllElements = new List<EquipSlotRankupElement>();
	}
	private Dictionary<int, EquipSlotRankupElement> m_mapElements = null;
	private List<EquipSlotRankupElement>	m_vecAllElements = null;
	private EquipSlotRankupElement m_emptyItem = null;
	private static EquipSlotRankupTable sInstance = null;

	public static EquipSlotRankupTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipSlotRankupTable();
			return sInstance;
		}
	}

	public EquipSlotRankupElement GetElement(int key)
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

  public List<EquipSlotRankupElement> GetAllElement(Predicate<EquipSlotRankupElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipSlotRankup.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipSlotRankup.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipSlotRankup.bin]未找到");
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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("EquipSlotRankup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSlotRankup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSlotRankup.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[3]!="level"){Ex.Logger.Log("EquipSlotRankup.csv中字段[level]位置不对应"); return false; }
		if(vecLine[4]!="rankup_rate"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankup_rate]位置不对应"); return false; }
		if(vecLine[5]!="rankdown_rate"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankdown_rate]位置不对应"); return false; }
		if(vecLine[6]!="rankup_require"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankup_require]位置不对应"); return false; }
		if(vecLine[7]!="safe_rankup_require"){Ex.Logger.Log("EquipSlotRankup.csv中字段[safe_rankup_require]位置不对应"); return false; }
		if(vecLine[8]!="attribute"){Ex.Logger.Log("EquipSlotRankup.csv中字段[attribute]位置不对应"); return false; }
		if(vecLine[9]!="unlock_needed"){Ex.Logger.Log("EquipSlotRankup.csv中字段[unlock_needed]位置不对应"); return false; }
		if(vecLine[10]!="slot_1_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_1_requirement]位置不对应"); return false; }
		if(vecLine[11]!="slot_2_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_2_requirement]位置不对应"); return false; }
		if(vecLine[12]!="slot_3_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_3_requirement]位置不对应"); return false; }
		if(vecLine[13]!="slot_4_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_4_requirement]位置不对应"); return false; }
		if(vecLine[14]!="slot_5_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_5_requirement]位置不对应"); return false; }
		if(vecLine[15]!="slot_6_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_6_requirement]位置不对应"); return false; }
		if(vecLine[16]!="slot_7_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_7_requirement]位置不对应"); return false; }
		if(vecLine[17]!="slot_8_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_8_requirement]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipSlotRankupElement member = new EquipSlotRankupElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rankup_rate);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rankdown_rate);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rankup_require);
			readPos += GameAssist.ReadString( binContent, readPos, out member.safe_rankup_require);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attribute );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_needed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_1_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_2_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_3_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_4_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_5_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_6_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_7_requirement );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.slot_8_requirement );

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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("EquipSlotRankup.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSlotRankup.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSlotRankup.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="rank"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[3]!="level"){Ex.Logger.Log("EquipSlotRankup.csv中字段[level]位置不对应"); return false; }
		if(vecLine[4]!="rankup_rate"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankup_rate]位置不对应"); return false; }
		if(vecLine[5]!="rankdown_rate"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankdown_rate]位置不对应"); return false; }
		if(vecLine[6]!="rankup_require"){Ex.Logger.Log("EquipSlotRankup.csv中字段[rankup_require]位置不对应"); return false; }
		if(vecLine[7]!="safe_rankup_require"){Ex.Logger.Log("EquipSlotRankup.csv中字段[safe_rankup_require]位置不对应"); return false; }
		if(vecLine[8]!="attribute"){Ex.Logger.Log("EquipSlotRankup.csv中字段[attribute]位置不对应"); return false; }
		if(vecLine[9]!="unlock_needed"){Ex.Logger.Log("EquipSlotRankup.csv中字段[unlock_needed]位置不对应"); return false; }
		if(vecLine[10]!="slot_1_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_1_requirement]位置不对应"); return false; }
		if(vecLine[11]!="slot_2_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_2_requirement]位置不对应"); return false; }
		if(vecLine[12]!="slot_3_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_3_requirement]位置不对应"); return false; }
		if(vecLine[13]!="slot_4_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_4_requirement]位置不对应"); return false; }
		if(vecLine[14]!="slot_5_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_5_requirement]位置不对应"); return false; }
		if(vecLine[15]!="slot_6_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_6_requirement]位置不对应"); return false; }
		if(vecLine[16]!="slot_7_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_7_requirement]位置不对应"); return false; }
		if(vecLine[17]!="slot_8_requirement"){Ex.Logger.Log("EquipSlotRankup.csv中字段[slot_8_requirement]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)18)
			{
				return false;
			}
			EquipSlotRankupElement member = new EquipSlotRankupElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.rank=Convert.ToInt32(vecLine[2]);
			member.level=Convert.ToInt32(vecLine[3]);
			member.rankup_rate=Convert.ToSingle(vecLine[4]);
			member.rankdown_rate=Convert.ToSingle(vecLine[5]);
			member.rankup_require=vecLine[6];
			member.safe_rankup_require=vecLine[7];
			member.attribute=Convert.ToInt32(vecLine[8]);
			member.unlock_needed=Convert.ToInt32(vecLine[9]);
			member.slot_1_requirement=Convert.ToInt32(vecLine[10]);
			member.slot_2_requirement=Convert.ToInt32(vecLine[11]);
			member.slot_3_requirement=Convert.ToInt32(vecLine[12]);
			member.slot_4_requirement=Convert.ToInt32(vecLine[13]);
			member.slot_5_requirement=Convert.ToInt32(vecLine[14]);
			member.slot_6_requirement=Convert.ToInt32(vecLine[15]);
			member.slot_7_requirement=Convert.ToInt32(vecLine[16]);
			member.slot_8_requirement=Convert.ToInt32(vecLine[17]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
