using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//装备共鸣配置数据类
public class EquipResonanceElement
{
	public int id;               	//阶级ID	每个阶级所对应的唯一ID
	public string comment;       	//阶级注释	策划用
	public int marquee;          	//跑马灯	0不显示 1显示
	public string roman_picture; 	//罗马数字图片	左侧菜单中的罗马数字图片资源
	public string roman_picture2;	//罗马数字底图	底板中的罗马数字图片资源
	public int ui_text1;         	//界面文本1	按照id引用string_ui表中的文本信息
	public int ui_text2;         	//界面文本2	按照id引用string_ui表中的文本信息
	public int ui_text3;         	//界面文本3	按照id引用string_ui表中的文本信息
	public li occupation;        	//适用职业	1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使
	public int rank;             	//级别	
	public int unlock_level;     	//解锁等级	该阶级解锁所需要的装备的等级
	public int unlock_rank;      	//解锁稀有度	该阶级解锁所需要的装备的稀有度 2：蓝色（稀有） 3：紫色（史诗） 4：橙色（传说）
	public lf attribute1;        	//属性条目/对应系数1	属性条目id|属性等级系数
	public lf attribute2;        	//属性条目/对应系数2	属性条目id|属性等级系数
	public lf attribute3;        	//属性条目/对应系数3	属性条目id|属性等级系数
	public lf attribute4;        	//属性条目/对应系数4	属性条目id|属性等级系数
	public lf single_interval;   	//单项区间	区间下限|区间上限
	public lf sum_interval;      	//和区间	和区间下限|和区间上限
	public int first_level;      	//初始等级	解锁该阶级时所有属性的初始等级
	public int level_limit;      	//等级上限	该阶级所有属性等级的上限值
	public int item_cost;        	//消耗道具ID	进行属性培养时消耗的道具ID
	public int num;              	//数量	消耗的道具数量

	public bool IsValidate = false;
	public EquipResonanceElement()
	{
		id = -1;
	}
};

//装备共鸣配置封装类
public class EquipResonanceTable
{

	private EquipResonanceTable()
	{
		m_mapElements = new Dictionary<int, EquipResonanceElement>();
		m_emptyItem = new EquipResonanceElement();
		m_vecAllElements = new List<EquipResonanceElement>();
	}
	private Dictionary<int, EquipResonanceElement> m_mapElements = null;
	private List<EquipResonanceElement>	m_vecAllElements = null;
	private EquipResonanceElement m_emptyItem = null;
	private static EquipResonanceTable sInstance = null;

	public static EquipResonanceTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipResonanceTable();
			return sInstance;
		}
	}

	public EquipResonanceElement GetElement(int key)
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

  public List<EquipResonanceElement> GetAllElement(Predicate<EquipResonanceElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipResonance.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipResonance.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipResonance.bin]未找到");
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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("EquipResonance.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipResonance.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipResonance.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="marquee"){Ex.Logger.Log("EquipResonance.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[3]!="roman_picture"){Ex.Logger.Log("EquipResonance.csv中字段[roman_picture]位置不对应"); return false; }
		if(vecLine[4]!="roman_picture2"){Ex.Logger.Log("EquipResonance.csv中字段[roman_picture2]位置不对应"); return false; }
		if(vecLine[5]!="ui_text1"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text1]位置不对应"); return false; }
		if(vecLine[6]!="ui_text2"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text2]位置不对应"); return false; }
		if(vecLine[7]!="ui_text3"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text3]位置不对应"); return false; }
		if(vecLine[8]!="occupation"){Ex.Logger.Log("EquipResonance.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("EquipResonance.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="unlock_level"){Ex.Logger.Log("EquipResonance.csv中字段[unlock_level]位置不对应"); return false; }
		if(vecLine[11]!="unlock_rank"){Ex.Logger.Log("EquipResonance.csv中字段[unlock_rank]位置不对应"); return false; }
		if(vecLine[12]!="attribute1"){Ex.Logger.Log("EquipResonance.csv中字段[attribute1]位置不对应"); return false; }
		if(vecLine[13]!="attribute2"){Ex.Logger.Log("EquipResonance.csv中字段[attribute2]位置不对应"); return false; }
		if(vecLine[14]!="attribute3"){Ex.Logger.Log("EquipResonance.csv中字段[attribute3]位置不对应"); return false; }
		if(vecLine[15]!="attribute4"){Ex.Logger.Log("EquipResonance.csv中字段[attribute4]位置不对应"); return false; }
		if(vecLine[16]!="single_interval"){Ex.Logger.Log("EquipResonance.csv中字段[single_interval]位置不对应"); return false; }
		if(vecLine[17]!="sum_interval"){Ex.Logger.Log("EquipResonance.csv中字段[sum_interval]位置不对应"); return false; }
		if(vecLine[18]!="first_level"){Ex.Logger.Log("EquipResonance.csv中字段[first_level]位置不对应"); return false; }
		if(vecLine[19]!="level_limit"){Ex.Logger.Log("EquipResonance.csv中字段[level_limit]位置不对应"); return false; }
		if(vecLine[20]!="item_cost"){Ex.Logger.Log("EquipResonance.csv中字段[item_cost]位置不对应"); return false; }
		if(vecLine[21]!="num"){Ex.Logger.Log("EquipResonance.csv中字段[num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipResonanceElement member = new EquipResonanceElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.marquee );
			readPos += GameAssist.ReadString( binContent, readPos, out member.roman_picture);
			readPos += GameAssist.ReadString( binContent, readPos, out member.roman_picture2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_text1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_text2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ui_text3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occupation);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_rank );
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.single_interval);
			readPos += GameAssist.ReadString( binContent, readPos, out member.sum_interval);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.first_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_limit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_cost );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.num );

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
		if(vecLine.Count != 22)
		{
			Ex.Logger.Log("EquipResonance.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipResonance.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipResonance.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="marquee"){Ex.Logger.Log("EquipResonance.csv中字段[marquee]位置不对应"); return false; }
		if(vecLine[3]!="roman_picture"){Ex.Logger.Log("EquipResonance.csv中字段[roman_picture]位置不对应"); return false; }
		if(vecLine[4]!="roman_picture2"){Ex.Logger.Log("EquipResonance.csv中字段[roman_picture2]位置不对应"); return false; }
		if(vecLine[5]!="ui_text1"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text1]位置不对应"); return false; }
		if(vecLine[6]!="ui_text2"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text2]位置不对应"); return false; }
		if(vecLine[7]!="ui_text3"){Ex.Logger.Log("EquipResonance.csv中字段[ui_text3]位置不对应"); return false; }
		if(vecLine[8]!="occupation"){Ex.Logger.Log("EquipResonance.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[9]!="rank"){Ex.Logger.Log("EquipResonance.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[10]!="unlock_level"){Ex.Logger.Log("EquipResonance.csv中字段[unlock_level]位置不对应"); return false; }
		if(vecLine[11]!="unlock_rank"){Ex.Logger.Log("EquipResonance.csv中字段[unlock_rank]位置不对应"); return false; }
		if(vecLine[12]!="attribute1"){Ex.Logger.Log("EquipResonance.csv中字段[attribute1]位置不对应"); return false; }
		if(vecLine[13]!="attribute2"){Ex.Logger.Log("EquipResonance.csv中字段[attribute2]位置不对应"); return false; }
		if(vecLine[14]!="attribute3"){Ex.Logger.Log("EquipResonance.csv中字段[attribute3]位置不对应"); return false; }
		if(vecLine[15]!="attribute4"){Ex.Logger.Log("EquipResonance.csv中字段[attribute4]位置不对应"); return false; }
		if(vecLine[16]!="single_interval"){Ex.Logger.Log("EquipResonance.csv中字段[single_interval]位置不对应"); return false; }
		if(vecLine[17]!="sum_interval"){Ex.Logger.Log("EquipResonance.csv中字段[sum_interval]位置不对应"); return false; }
		if(vecLine[18]!="first_level"){Ex.Logger.Log("EquipResonance.csv中字段[first_level]位置不对应"); return false; }
		if(vecLine[19]!="level_limit"){Ex.Logger.Log("EquipResonance.csv中字段[level_limit]位置不对应"); return false; }
		if(vecLine[20]!="item_cost"){Ex.Logger.Log("EquipResonance.csv中字段[item_cost]位置不对应"); return false; }
		if(vecLine[21]!="num"){Ex.Logger.Log("EquipResonance.csv中字段[num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)22)
			{
				return false;
			}
			EquipResonanceElement member = new EquipResonanceElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.marquee=Convert.ToInt32(vecLine[2]);
			member.roman_picture=vecLine[3];
			member.roman_picture2=vecLine[4];
			member.ui_text1=Convert.ToInt32(vecLine[5]);
			member.ui_text2=Convert.ToInt32(vecLine[6]);
			member.ui_text3=Convert.ToInt32(vecLine[7]);
			member.occupation=vecLine[8];
			member.rank=Convert.ToInt32(vecLine[9]);
			member.unlock_level=Convert.ToInt32(vecLine[10]);
			member.unlock_rank=Convert.ToInt32(vecLine[11]);
			member.attribute1=vecLine[12];
			member.attribute2=vecLine[13];
			member.attribute3=vecLine[14];
			member.attribute4=vecLine[15];
			member.single_interval=vecLine[16];
			member.sum_interval=vecLine[17];
			member.first_level=Convert.ToInt32(vecLine[18]);
			member.level_limit=Convert.ToInt32(vecLine[19]);
			member.item_cost=Convert.ToInt32(vecLine[20]);
			member.num=Convert.ToInt32(vecLine[21]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
