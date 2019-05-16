using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//聊天消耗配置表配置数据类
public class ChatConsumptionElement
{
	public int id;               	//id	数据的id
	public string comment;       	//注释	该数据的功能
	public int int_value1;       	//消耗类型(1道具2货币)	整型数据
	public int int_value2;       	//消耗ID
银币 0 
金币 1 
钻石 2
绑定钻石3	整型数据
	public int int_value3;       	//消耗数量	整型数据

	public bool IsValidate = false;
	public ChatConsumptionElement()
	{
		id = -1;
	}
};

//聊天消耗配置表配置封装类
public class ChatConsumptionTable
{

	private ChatConsumptionTable()
	{
		m_mapElements = new Dictionary<int, ChatConsumptionElement>();
		m_emptyItem = new ChatConsumptionElement();
		m_vecAllElements = new List<ChatConsumptionElement>();
	}
	private Dictionary<int, ChatConsumptionElement> m_mapElements = null;
	private List<ChatConsumptionElement>	m_vecAllElements = null;
	private ChatConsumptionElement m_emptyItem = null;
	private static ChatConsumptionTable sInstance = null;

	public static ChatConsumptionTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ChatConsumptionTable();
			return sInstance;
		}
	}

	public ChatConsumptionElement GetElement(int key)
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

  public List<ChatConsumptionElement> GetAllElement(Predicate<ChatConsumptionElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ChatConsumption.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ChatConsumption.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ChatConsumption.bin]未找到");
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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("ChatConsumption.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ChatConsumption.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ChatConsumption.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="int_value1"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value1]位置不对应"); return false; }
		if(vecLine[3]!="int_value2"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value2]位置不对应"); return false; }
		if(vecLine[4]!="int_value3"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value3]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ChatConsumptionElement member = new ChatConsumptionElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.int_value1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.int_value2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.int_value3 );

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
		if(vecLine.Count != 5)
		{
			Ex.Logger.Log("ChatConsumption.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ChatConsumption.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ChatConsumption.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="int_value1"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value1]位置不对应"); return false; }
		if(vecLine[3]!="int_value2"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value2]位置不对应"); return false; }
		if(vecLine[4]!="int_value3"){Ex.Logger.Log("ChatConsumption.csv中字段[int_value3]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)5)
			{
				return false;
			}
			ChatConsumptionElement member = new ChatConsumptionElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.int_value1=Convert.ToInt32(vecLine[2]);
			member.int_value2=Convert.ToInt32(vecLine[3]);
			member.int_value3=Convert.ToInt32(vecLine[4]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
