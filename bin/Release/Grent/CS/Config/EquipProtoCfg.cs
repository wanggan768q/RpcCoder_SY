using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备原型配置数据类
public class EquipProtoElement
{
	public int id;               	//装备ID	{equip(0)}_{class(0)}_{lv(000)}_{rank(0)}_{suit(0)}_{part(0)}:    equip-2,    class-0_物理;1_法术;2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    suit-0_非套装;1_1天赋;2_2天赋    part-1_武器;2_耳环;3_项链;4_戒指;5_帽子;6_盔甲;7_臂甲;8_腿甲
	public string comment;       	//道具注释	策划用
	public int equip_level;      	//装备等级	根据装备等级 生成后缀属性区间
	public int refine_cost;      	//洗练消耗	对该装备进行洗练时 消耗的软货币值
	public li basic_attribute_1; 	//基础属性条目1	分别对应 条目id|条目区间下限|条目区间上限
	public li basic_attribute_2; 	//基础属性条目2	分别对应 条目id|条目区间下限|条目区间上限
	public li basic_attribute_3; 	//基础属性条目3	分别对应 条目id|条目区间下限|条目区间上限
	public li extra_attribute_num;	//后缀属性数量	分别对应 数量下限|数量上限
	public int extra_attribute_type;	//后缀属性分类	（暂不使用） 0全部 1攻击向 2防御向
	public int special_skill_id; 	//特殊技能组id	对应特殊技能组id，如果不会生成特殊技能则不填
	public int suit_id;          	//套装id	该装备所对应的套装id

	public bool IsValidate = false;
	public EquipProtoElement()
	{
		id = -1;
	}
};

//装备原型配置封装类
public class EquipProtoTable
{

	private EquipProtoTable()
	{
		m_mapElements = new Dictionary<int, EquipProtoElement>();
		m_emptyItem = new EquipProtoElement();
		m_vecAllElements = new List<EquipProtoElement>();
	}
	private Dictionary<int, EquipProtoElement> m_mapElements = null;
	private List<EquipProtoElement>	m_vecAllElements = null;
	private EquipProtoElement m_emptyItem = null;
	private static EquipProtoTable sInstance = null;

	public static EquipProtoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipProtoTable();
			return sInstance;
		}
	}

	public EquipProtoElement GetElement(int key)
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

  public List<EquipProtoElement> GetAllElement(Predicate<EquipProtoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipProto.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipProto.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipProto.bin]未找到");
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
			Ex.Logger.Log("EquipProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="equip_level"){Ex.Logger.Log("EquipProto.csv中字段[equip_level]位置不对应"); return false; }
		if(vecLine[3]!="refine_cost"){Ex.Logger.Log("EquipProto.csv中字段[refine_cost]位置不对应"); return false; }
		if(vecLine[4]!="basic_attribute_1"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_1]位置不对应"); return false; }
		if(vecLine[5]!="basic_attribute_2"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_2]位置不对应"); return false; }
		if(vecLine[6]!="basic_attribute_3"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_3]位置不对应"); return false; }
		if(vecLine[7]!="extra_attribute_num"){Ex.Logger.Log("EquipProto.csv中字段[extra_attribute_num]位置不对应"); return false; }
		if(vecLine[8]!="extra_attribute_type"){Ex.Logger.Log("EquipProto.csv中字段[extra_attribute_type]位置不对应"); return false; }
		if(vecLine[9]!="special_skill_id"){Ex.Logger.Log("EquipProto.csv中字段[special_skill_id]位置不对应"); return false; }
		if(vecLine[10]!="suit_id"){Ex.Logger.Log("EquipProto.csv中字段[suit_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipProtoElement member = new EquipProtoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.equip_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.refine_cost );
			readPos += GameAssist.ReadString( binContent, readPos, out member.basic_attribute_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.basic_attribute_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.basic_attribute_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_attribute_num);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.extra_attribute_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.special_skill_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.suit_id );

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
			Ex.Logger.Log("EquipProto.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipProto.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipProto.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="equip_level"){Ex.Logger.Log("EquipProto.csv中字段[equip_level]位置不对应"); return false; }
		if(vecLine[3]!="refine_cost"){Ex.Logger.Log("EquipProto.csv中字段[refine_cost]位置不对应"); return false; }
		if(vecLine[4]!="basic_attribute_1"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_1]位置不对应"); return false; }
		if(vecLine[5]!="basic_attribute_2"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_2]位置不对应"); return false; }
		if(vecLine[6]!="basic_attribute_3"){Ex.Logger.Log("EquipProto.csv中字段[basic_attribute_3]位置不对应"); return false; }
		if(vecLine[7]!="extra_attribute_num"){Ex.Logger.Log("EquipProto.csv中字段[extra_attribute_num]位置不对应"); return false; }
		if(vecLine[8]!="extra_attribute_type"){Ex.Logger.Log("EquipProto.csv中字段[extra_attribute_type]位置不对应"); return false; }
		if(vecLine[9]!="special_skill_id"){Ex.Logger.Log("EquipProto.csv中字段[special_skill_id]位置不对应"); return false; }
		if(vecLine[10]!="suit_id"){Ex.Logger.Log("EquipProto.csv中字段[suit_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			EquipProtoElement member = new EquipProtoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.equip_level=Convert.ToInt32(vecLine[2]);
			member.refine_cost=Convert.ToInt32(vecLine[3]);
			member.basic_attribute_1=vecLine[4];
			member.basic_attribute_2=vecLine[5];
			member.basic_attribute_3=vecLine[6];
			member.extra_attribute_num=vecLine[7];
			member.extra_attribute_type=Convert.ToInt32(vecLine[8]);
			member.special_skill_id=Convert.ToInt32(vecLine[9]);
			member.suit_id=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
