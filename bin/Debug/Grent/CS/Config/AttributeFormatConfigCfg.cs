using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//战斗属性配置数据类
public class AttributeFormatConfigElement
{
	public int id;               	//ID	添加需要 通知程序
	public int nameid;           	//属性名称ID	属性名称ID
	public int type;             	//属性显示	0：显示数字 1：显示百分比
	public string des;           	//属性说明	仅策划用
	public int desid;            	//属性说明ID	属性说明ID
	public lf weight;            	//战力权重	战力=[计算单位|战力权重]
	public string refine_name;   	//洗练名称	对应该属性在装备后缀表的字段名
	public int attr_type;        	//属性类型	0.一级属性 1.二级属性 2.其他
	public int attack_type;      	//属性的攻击类型	0.物理属性 1.魔法属性 2.通用
	public int basic_display;    	//基础界面显示	0.不显示 >0.显示，并表示其优先级（数字大优先高） （同优先级按id顺序显示）
	public int total_display;    	//完整界面显示	0.不显示 >0.显示，并表示其优先级（数字大优先高） （同优先级按id顺序显示）
	public int total_category;   	//完整界面分类	对应AttributeCatagory表的某一条

	public bool IsValidate = false;
	public AttributeFormatConfigElement()
	{
		id = -1;
	}
};

//战斗属性配置封装类
public class AttributeFormatConfigTable
{

	private AttributeFormatConfigTable()
	{
		m_mapElements = new Dictionary<int, AttributeFormatConfigElement>();
		m_emptyItem = new AttributeFormatConfigElement();
		m_vecAllElements = new List<AttributeFormatConfigElement>();
	}
	private Dictionary<int, AttributeFormatConfigElement> m_mapElements = null;
	private List<AttributeFormatConfigElement>	m_vecAllElements = null;
	private AttributeFormatConfigElement m_emptyItem = null;
	private static AttributeFormatConfigTable sInstance = null;

	public static AttributeFormatConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AttributeFormatConfigTable();
			return sInstance;
		}
	}

	public AttributeFormatConfigElement GetElement(int key)
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

  public List<AttributeFormatConfigElement> GetAllElement(Predicate<AttributeFormatConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AttributeFormatConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AttributeFormatConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AttributeFormatConfig.bin]未找到");
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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="nameid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[nameid]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="des"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[des]位置不对应"); return false; }
		if(vecLine[4]!="desid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[desid]位置不对应"); return false; }
		if(vecLine[5]!="weight"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[6]!="refine_name"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[refine_name]位置不对应"); return false; }
		if(vecLine[7]!="attr_type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[attr_type]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="basic_display"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[basic_display]位置不对应"); return false; }
		if(vecLine[10]!="total_display"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[total_display]位置不对应"); return false; }
		if(vecLine[11]!="total_category"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[total_category]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AttributeFormatConfigElement member = new AttributeFormatConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.nameid );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.des);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desid );
			readPos += GameAssist.ReadString( binContent, readPos, out member.weight);
			readPos += GameAssist.ReadString( binContent, readPos, out member.refine_name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attr_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.basic_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.total_display );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.total_category );

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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("AttributeFormatConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="nameid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[nameid]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="des"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[des]位置不对应"); return false; }
		if(vecLine[4]!="desid"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[desid]位置不对应"); return false; }
		if(vecLine[5]!="weight"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[weight]位置不对应"); return false; }
		if(vecLine[6]!="refine_name"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[refine_name]位置不对应"); return false; }
		if(vecLine[7]!="attr_type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[attr_type]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="basic_display"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[basic_display]位置不对应"); return false; }
		if(vecLine[10]!="total_display"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[total_display]位置不对应"); return false; }
		if(vecLine[11]!="total_category"){Ex.Logger.Log("AttributeFormatConfig.csv中字段[total_category]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			AttributeFormatConfigElement member = new AttributeFormatConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.nameid=Convert.ToInt32(vecLine[1]);
			member.type=Convert.ToInt32(vecLine[2]);
			member.des=vecLine[3];
			member.desid=Convert.ToInt32(vecLine[4]);
			member.weight=vecLine[5];
			member.refine_name=vecLine[6];
			member.attr_type=Convert.ToInt32(vecLine[7]);
			member.attack_type=Convert.ToInt32(vecLine[8]);
			member.basic_display=Convert.ToInt32(vecLine[9]);
			member.total_display=Convert.ToInt32(vecLine[10]);
			member.total_category=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
