using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//限定表配置数据类
public class LimitElement
{
	public int id;               	//主键id	
	public string comment;       	//数据说明	判断说明
	public int string_detail_description;	//任务的详细描述	在任务UI显示 StringQuest_任务文本表ID
	public int type;             	//数据类型	数据来源区分
	public int sub_type;         	//条件	数值 1=eq 等于某个数值 2=gt 大于某个数值 3=lt 小于某个数值 4=le 小于等于某个数值 5=ge 大于等于某个数值 6=ne 不等于某个数值
	public int value;            	//条件值	数值

	public bool IsValidate = false;
	public LimitElement()
	{
		id = -1;
	}
};

//限定表配置封装类
public class LimitTable
{

	private LimitTable()
	{
		m_mapElements = new Dictionary<int, LimitElement>();
		m_emptyItem = new LimitElement();
		m_vecAllElements = new List<LimitElement>();
	}
	private Dictionary<int, LimitElement> m_mapElements = null;
	private List<LimitElement>	m_vecAllElements = null;
	private LimitElement m_emptyItem = null;
	private static LimitTable sInstance = null;

	public static LimitTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LimitTable();
			return sInstance;
		}
	}

	public LimitElement GetElement(int key)
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

  public List<LimitElement> GetAllElement(Predicate<LimitElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Limit.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Limit.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Limit.bin]未找到");
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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("Limit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Limit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Limit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="string_detail_description"){Ex.Logger.Log("Limit.csv中字段[string_detail_description]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Limit.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="sub_type"){Ex.Logger.Log("Limit.csv中字段[sub_type]位置不对应"); return false; }
		if(vecLine[5]!="value"){Ex.Logger.Log("Limit.csv中字段[value]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LimitElement member = new LimitElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.string_detail_description );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sub_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.value );

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
		if(vecLine.Count != 6)
		{
			Ex.Logger.Log("Limit.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Limit.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Limit.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="string_detail_description"){Ex.Logger.Log("Limit.csv中字段[string_detail_description]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("Limit.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="sub_type"){Ex.Logger.Log("Limit.csv中字段[sub_type]位置不对应"); return false; }
		if(vecLine[5]!="value"){Ex.Logger.Log("Limit.csv中字段[value]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			LimitElement member = new LimitElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.string_detail_description=Convert.ToInt32(vecLine[2]);
			member.type=Convert.ToInt32(vecLine[3]);
			member.sub_type=Convert.ToInt32(vecLine[4]);
			member.value=Convert.ToInt32(vecLine[5]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
