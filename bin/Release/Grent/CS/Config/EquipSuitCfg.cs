using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备套装配置数据类
public class EquipSuitElement
{
	public int id;               	//套装id	标示套装等级，职业，品质 class{0}+level{000}+rank{0}+index{0}    class-2_骑士;3_法师;4_游侠;5_神秘使;6_战士;7_盗贼    lv-001~999    rank-0_白;1_绿;2_蓝;3_紫;4_橙;5_红    index-1_套装1;2_套装2
	public string comment;       	//道具注释	策划用
	public int name;             	//套装名称	从String_Item表中进行查询
	public int desc;             	//套装描述	从String_Item表中进行查询
	public li slot_1_equip;      	//对应武器	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_2_equip;      	//对应耳环	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_3_equip;      	//对应项链	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_4_equip;      	//对应戒指	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_5_equip;      	//对应帽子	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_6_equip;      	//对应胸甲	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_7_equip;      	//对应臂甲	item_proto中id 可以填入复数个 第一个为默认显示
	public li slot_8_equip;      	//对应腿甲	item_proto中id 可以填入复数个 第一个为默认显示
	public int effect_count;     	//效果数量	程序使用 用来计算套装的效果数量
	public ls suit_effect_1;     	//套装效果1	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_2;     	//套装效果2	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_3;     	//套装效果3	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_4;     	//套装效果4	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_5;     	//套装效果5	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_6;     	//套装效果6	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_7;     	//套装效果7	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_8;     	//套装效果8	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_9;     	//套装效果9	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_10;    	//套装效果10	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_11;    	//套装效果11	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值
	public ls suit_effect_12;    	//套装效果12	分别表示 套装数量| 类型(1属性；2特技)| 加值类型(0值；1百分比)| 对应类型id| 类型值

	public bool IsValidate = false;
	public EquipSuitElement()
	{
		id = -1;
	}
};

//装备套装配置封装类
public class EquipSuitTable
{

	private EquipSuitTable()
	{
		m_mapElements = new Dictionary<int, EquipSuitElement>();
		m_emptyItem = new EquipSuitElement();
		m_vecAllElements = new List<EquipSuitElement>();
	}
	private Dictionary<int, EquipSuitElement> m_mapElements = null;
	private List<EquipSuitElement>	m_vecAllElements = null;
	private EquipSuitElement m_emptyItem = null;
	private static EquipSuitTable sInstance = null;

	public static EquipSuitTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipSuitTable();
			return sInstance;
		}
	}

	public EquipSuitElement GetElement(int key)
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

  public List<EquipSuitElement> GetAllElement(Predicate<EquipSuitElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipSuit.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipSuit.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipSuit.bin]未找到");
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
		if(vecLine.Count != 25)
		{
			Ex.Logger.Log("EquipSuit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSuit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSuit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("EquipSuit.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("EquipSuit.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="slot_1_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_1_equip]位置不对应"); return false; }
		if(vecLine[5]!="slot_2_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_2_equip]位置不对应"); return false; }
		if(vecLine[6]!="slot_3_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_3_equip]位置不对应"); return false; }
		if(vecLine[7]!="slot_4_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_4_equip]位置不对应"); return false; }
		if(vecLine[8]!="slot_5_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_5_equip]位置不对应"); return false; }
		if(vecLine[9]!="slot_6_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_6_equip]位置不对应"); return false; }
		if(vecLine[10]!="slot_7_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_7_equip]位置不对应"); return false; }
		if(vecLine[11]!="slot_8_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_8_equip]位置不对应"); return false; }
		if(vecLine[12]!="effect_count"){Ex.Logger.Log("EquipSuit.csv中字段[effect_count]位置不对应"); return false; }
		if(vecLine[13]!="suit_effect_1"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_1]位置不对应"); return false; }
		if(vecLine[14]!="suit_effect_2"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_2]位置不对应"); return false; }
		if(vecLine[15]!="suit_effect_3"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_3]位置不对应"); return false; }
		if(vecLine[16]!="suit_effect_4"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_4]位置不对应"); return false; }
		if(vecLine[17]!="suit_effect_5"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_5]位置不对应"); return false; }
		if(vecLine[18]!="suit_effect_6"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_6]位置不对应"); return false; }
		if(vecLine[19]!="suit_effect_7"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_7]位置不对应"); return false; }
		if(vecLine[20]!="suit_effect_8"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_8]位置不对应"); return false; }
		if(vecLine[21]!="suit_effect_9"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_9]位置不对应"); return false; }
		if(vecLine[22]!="suit_effect_10"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_10]位置不对应"); return false; }
		if(vecLine[23]!="suit_effect_11"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_11]位置不对应"); return false; }
		if(vecLine[24]!="suit_effect_12"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_12]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipSuitElement member = new EquipSuitElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_1_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_2_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_3_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_4_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_5_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_6_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_7_equip);
			readPos += GameAssist.ReadString( binContent, readPos, out member.slot_8_equip);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect_count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_8);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_9);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_10);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.suit_effect_12);

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
		if(vecLine.Count != 25)
		{
			Ex.Logger.Log("EquipSuit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipSuit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipSuit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("EquipSuit.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("EquipSuit.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="slot_1_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_1_equip]位置不对应"); return false; }
		if(vecLine[5]!="slot_2_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_2_equip]位置不对应"); return false; }
		if(vecLine[6]!="slot_3_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_3_equip]位置不对应"); return false; }
		if(vecLine[7]!="slot_4_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_4_equip]位置不对应"); return false; }
		if(vecLine[8]!="slot_5_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_5_equip]位置不对应"); return false; }
		if(vecLine[9]!="slot_6_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_6_equip]位置不对应"); return false; }
		if(vecLine[10]!="slot_7_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_7_equip]位置不对应"); return false; }
		if(vecLine[11]!="slot_8_equip"){Ex.Logger.Log("EquipSuit.csv中字段[slot_8_equip]位置不对应"); return false; }
		if(vecLine[12]!="effect_count"){Ex.Logger.Log("EquipSuit.csv中字段[effect_count]位置不对应"); return false; }
		if(vecLine[13]!="suit_effect_1"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_1]位置不对应"); return false; }
		if(vecLine[14]!="suit_effect_2"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_2]位置不对应"); return false; }
		if(vecLine[15]!="suit_effect_3"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_3]位置不对应"); return false; }
		if(vecLine[16]!="suit_effect_4"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_4]位置不对应"); return false; }
		if(vecLine[17]!="suit_effect_5"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_5]位置不对应"); return false; }
		if(vecLine[18]!="suit_effect_6"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_6]位置不对应"); return false; }
		if(vecLine[19]!="suit_effect_7"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_7]位置不对应"); return false; }
		if(vecLine[20]!="suit_effect_8"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_8]位置不对应"); return false; }
		if(vecLine[21]!="suit_effect_9"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_9]位置不对应"); return false; }
		if(vecLine[22]!="suit_effect_10"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_10]位置不对应"); return false; }
		if(vecLine[23]!="suit_effect_11"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_11]位置不对应"); return false; }
		if(vecLine[24]!="suit_effect_12"){Ex.Logger.Log("EquipSuit.csv中字段[suit_effect_12]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)25)
			{
				return false;
			}
			EquipSuitElement member = new EquipSuitElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.desc=Convert.ToInt32(vecLine[3]);
			member.slot_1_equip=vecLine[4];
			member.slot_2_equip=vecLine[5];
			member.slot_3_equip=vecLine[6];
			member.slot_4_equip=vecLine[7];
			member.slot_5_equip=vecLine[8];
			member.slot_6_equip=vecLine[9];
			member.slot_7_equip=vecLine[10];
			member.slot_8_equip=vecLine[11];
			member.effect_count=Convert.ToInt32(vecLine[12]);
			member.suit_effect_1=vecLine[13];
			member.suit_effect_2=vecLine[14];
			member.suit_effect_3=vecLine[15];
			member.suit_effect_4=vecLine[16];
			member.suit_effect_5=vecLine[17];
			member.suit_effect_6=vecLine[18];
			member.suit_effect_7=vecLine[19];
			member.suit_effect_8=vecLine[20];
			member.suit_effect_9=vecLine[21];
			member.suit_effect_10=vecLine[22];
			member.suit_effect_11=vecLine[23];
			member.suit_effect_12=vecLine[24];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
