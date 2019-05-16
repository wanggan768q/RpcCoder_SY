using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝物库等级表配置数据类
public class TreasureLevelElement
{
	public int id;               	//ID	
	public string comment;       	//道具注释	策划用
	public int up_points;        	//宝物库升级点数	宝库库升级到 下一级所需的点数
	public int up_consume;       	//升级消耗银币数量	升级消耗的银币数值
	public li attribute_info1;   	//属性信息1	属性ID|属性数值
	public li attribute_info2;   	//属性信息2	属性ID|属性数值
	public li attribute_info3;   	//属性信息3	属性ID|属性数值
	public li attribute_info4;   	//属性信息4	属性ID|属性数值
	public li attribute_info5;   	//属性信息5	属性ID|属性数值
	public li attribute_info6;   	//属性信息6	属性ID|属性数值
	public li attribute_info7;   	//属性信息7	属性ID|属性数值
	public li attribute_info8_physical;	//属性信息8_物理攻击	属性ID|属性数值
	public li attribute_info8_magic;	//属性信息8_魔法攻击	属性ID|属性数值

	public bool IsValidate = false;
	public TreasureLevelElement()
	{
		id = -1;
	}
};

//宝物库等级表配置封装类
public class TreasureLevelTable
{

	private TreasureLevelTable()
	{
		m_mapElements = new Dictionary<int, TreasureLevelElement>();
		m_emptyItem = new TreasureLevelElement();
		m_vecAllElements = new List<TreasureLevelElement>();
	}
	private Dictionary<int, TreasureLevelElement> m_mapElements = null;
	private List<TreasureLevelElement>	m_vecAllElements = null;
	private TreasureLevelElement m_emptyItem = null;
	private static TreasureLevelTable sInstance = null;

	public static TreasureLevelTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TreasureLevelTable();
			return sInstance;
		}
	}

	public TreasureLevelElement GetElement(int key)
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

  public List<TreasureLevelElement> GetAllElement(Predicate<TreasureLevelElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("TreasureLevel.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("TreasureLevel.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[TreasureLevel.bin]未找到");
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
			Ex.Logger.Log("TreasureLevel.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureLevel.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureLevel.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="up_points"){Ex.Logger.Log("TreasureLevel.csv中字段[up_points]位置不对应"); return false; }
		if(vecLine[3]!="up_consume"){Ex.Logger.Log("TreasureLevel.csv中字段[up_consume]位置不对应"); return false; }
		if(vecLine[4]!="attribute_info1"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info1]位置不对应"); return false; }
		if(vecLine[5]!="attribute_info2"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info2]位置不对应"); return false; }
		if(vecLine[6]!="attribute_info3"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info3]位置不对应"); return false; }
		if(vecLine[7]!="attribute_info4"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info4]位置不对应"); return false; }
		if(vecLine[8]!="attribute_info5"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info5]位置不对应"); return false; }
		if(vecLine[9]!="attribute_info6"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info6]位置不对应"); return false; }
		if(vecLine[10]!="attribute_info7"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info7]位置不对应"); return false; }
		if(vecLine[11]!="attribute_info8_physical"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info8_physical]位置不对应"); return false; }
		if(vecLine[12]!="attribute_info8_magic"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info8_magic]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TreasureLevelElement member = new TreasureLevelElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_points );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.up_consume );
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info8_physical);
			readPos += GameAssist.ReadString( binContent, readPos, out member.attribute_info8_magic);

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
			Ex.Logger.Log("TreasureLevel.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("TreasureLevel.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("TreasureLevel.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="up_points"){Ex.Logger.Log("TreasureLevel.csv中字段[up_points]位置不对应"); return false; }
		if(vecLine[3]!="up_consume"){Ex.Logger.Log("TreasureLevel.csv中字段[up_consume]位置不对应"); return false; }
		if(vecLine[4]!="attribute_info1"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info1]位置不对应"); return false; }
		if(vecLine[5]!="attribute_info2"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info2]位置不对应"); return false; }
		if(vecLine[6]!="attribute_info3"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info3]位置不对应"); return false; }
		if(vecLine[7]!="attribute_info4"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info4]位置不对应"); return false; }
		if(vecLine[8]!="attribute_info5"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info5]位置不对应"); return false; }
		if(vecLine[9]!="attribute_info6"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info6]位置不对应"); return false; }
		if(vecLine[10]!="attribute_info7"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info7]位置不对应"); return false; }
		if(vecLine[11]!="attribute_info8_physical"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info8_physical]位置不对应"); return false; }
		if(vecLine[12]!="attribute_info8_magic"){Ex.Logger.Log("TreasureLevel.csv中字段[attribute_info8_magic]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)13)
			{
				return false;
			}
			TreasureLevelElement member = new TreasureLevelElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.up_points=Convert.ToInt32(vecLine[2]);
			member.up_consume=Convert.ToInt32(vecLine[3]);
			member.attribute_info1=vecLine[4];
			member.attribute_info2=vecLine[5];
			member.attribute_info3=vecLine[6];
			member.attribute_info4=vecLine[7];
			member.attribute_info5=vecLine[8];
			member.attribute_info6=vecLine[9];
			member.attribute_info7=vecLine[10];
			member.attribute_info8_physical=vecLine[11];
			member.attribute_info8_magic=vecLine[12];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
