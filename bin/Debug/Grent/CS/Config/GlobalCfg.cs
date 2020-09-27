using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//全局配置配置数据类
public class GlobalElement
{
	public int id;               	//id	数据的id
	public int int_value;        	//整型数据	整型数据
	public float float_value;    	//浮点数据	浮点数据
	public string string_value;  	//字符串数据	特效：资源名称
	public li list_int_value;    	//数组整型数据	数组整型数据
	public lf list_float_value;  	//数组浮点数据	数组浮点数据
	public ls list_string_value; 	//数组字符串数据	数组字符串数据

	public bool IsValidate = false;
	public GlobalElement()
	{
		id = -1;
	}
};

//全局配置配置封装类
public class GlobalTable
{

	private GlobalTable()
	{
		m_mapElements = new Dictionary<int, GlobalElement>();
		m_emptyItem = new GlobalElement();
		m_vecAllElements = new List<GlobalElement>();
	}
	private Dictionary<int, GlobalElement> m_mapElements = null;
	private List<GlobalElement>	m_vecAllElements = null;
	private GlobalElement m_emptyItem = null;
	private static GlobalTable sInstance = null;

	public static GlobalTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GlobalTable();
			return sInstance;
		}
	}

	public GlobalElement GetElement(int key)
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

  public List<GlobalElement> GetAllElement(Predicate<GlobalElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Global.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Global.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Global.bin]未找到");
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
			Ex.Logger.Log("Global.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Global.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="int_value"){Ex.Logger.Log("Global.csv中字段[int_value]位置不对应"); return false; }
		if(vecLine[2]!="float_value"){Ex.Logger.Log("Global.csv中字段[float_value]位置不对应"); return false; }
		if(vecLine[3]!="string_value"){Ex.Logger.Log("Global.csv中字段[string_value]位置不对应"); return false; }
		if(vecLine[4]!="list_int_value"){Ex.Logger.Log("Global.csv中字段[list_int_value]位置不对应"); return false; }
		if(vecLine[5]!="list_float_value"){Ex.Logger.Log("Global.csv中字段[list_float_value]位置不对应"); return false; }
		if(vecLine[6]!="list_string_value"){Ex.Logger.Log("Global.csv中字段[list_string_value]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GlobalElement member = new GlobalElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.int_value );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.float_value);
			readPos += GameAssist.ReadString( binContent, readPos, out member.string_value);
			readPos += GameAssist.ReadString( binContent, readPos, out member.list_int_value);
			readPos += GameAssist.ReadString( binContent, readPos, out member.list_float_value);
			readPos += GameAssist.ReadString( binContent, readPos, out member.list_string_value);

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
			Ex.Logger.Log("Global.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Global.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="int_value"){Ex.Logger.Log("Global.csv中字段[int_value]位置不对应"); return false; }
		if(vecLine[2]!="float_value"){Ex.Logger.Log("Global.csv中字段[float_value]位置不对应"); return false; }
		if(vecLine[3]!="string_value"){Ex.Logger.Log("Global.csv中字段[string_value]位置不对应"); return false; }
		if(vecLine[4]!="list_int_value"){Ex.Logger.Log("Global.csv中字段[list_int_value]位置不对应"); return false; }
		if(vecLine[5]!="list_float_value"){Ex.Logger.Log("Global.csv中字段[list_float_value]位置不对应"); return false; }
		if(vecLine[6]!="list_string_value"){Ex.Logger.Log("Global.csv中字段[list_string_value]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			GlobalElement member = new GlobalElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.int_value=Convert.ToInt32(vecLine[1]);
			member.float_value=Convert.ToSingle(vecLine[2]);
			member.string_value=vecLine[3];
			member.list_int_value=vecLine[4];
			member.list_float_value=vecLine[5];
			member.list_string_value=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
