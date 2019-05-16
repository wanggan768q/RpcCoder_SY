using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//道具来源配置数据类
public class ItemSourceElement
{
	public int id;               	//道具ID	最好和itemProto保持一致
	public string comment;       	//道具注释	策划用
	public int count;            	//来源数量	该道具来源条目数量
	public li source_1;          	//来源1	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_2;          	//来源2	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_3;          	//来源3	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_4;          	//来源4	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_5;          	//来源5	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_6;          	//来源6	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_7;          	//来源7	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_8;          	//来源8	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_9;          	//来源9	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_10;         	//来源10	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_11;         	//来源11	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_12;         	//来源12	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_13;         	//来源13	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_14;         	//来源14	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留
	public li source_15;         	//来源15	数组，按照以下格式填写  类型|主键值|参数 类型枚举 1 = 打开界面 2 = 预留

	public bool IsValidate = false;
	public ItemSourceElement()
	{
		id = -1;
	}
};

//道具来源配置封装类
public class ItemSourceTable
{

	private ItemSourceTable()
	{
		m_mapElements = new Dictionary<int, ItemSourceElement>();
		m_emptyItem = new ItemSourceElement();
		m_vecAllElements = new List<ItemSourceElement>();
	}
	private Dictionary<int, ItemSourceElement> m_mapElements = null;
	private List<ItemSourceElement>	m_vecAllElements = null;
	private ItemSourceElement m_emptyItem = null;
	private static ItemSourceTable sInstance = null;

	public static ItemSourceTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ItemSourceTable();
			return sInstance;
		}
	}

	public ItemSourceElement GetElement(int key)
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

  public List<ItemSourceElement> GetAllElement(Predicate<ItemSourceElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ItemSource.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ItemSource.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ItemSource.bin]未找到");
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
			Ex.Logger.Log("ItemSource.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemSource.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ItemSource.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="count"){Ex.Logger.Log("ItemSource.csv中字段[count]位置不对应"); return false; }
		if(vecLine[3]!="source_1"){Ex.Logger.Log("ItemSource.csv中字段[source_1]位置不对应"); return false; }
		if(vecLine[4]!="source_2"){Ex.Logger.Log("ItemSource.csv中字段[source_2]位置不对应"); return false; }
		if(vecLine[5]!="source_3"){Ex.Logger.Log("ItemSource.csv中字段[source_3]位置不对应"); return false; }
		if(vecLine[6]!="source_4"){Ex.Logger.Log("ItemSource.csv中字段[source_4]位置不对应"); return false; }
		if(vecLine[7]!="source_5"){Ex.Logger.Log("ItemSource.csv中字段[source_5]位置不对应"); return false; }
		if(vecLine[8]!="source_6"){Ex.Logger.Log("ItemSource.csv中字段[source_6]位置不对应"); return false; }
		if(vecLine[9]!="source_7"){Ex.Logger.Log("ItemSource.csv中字段[source_7]位置不对应"); return false; }
		if(vecLine[10]!="source_8"){Ex.Logger.Log("ItemSource.csv中字段[source_8]位置不对应"); return false; }
		if(vecLine[11]!="source_9"){Ex.Logger.Log("ItemSource.csv中字段[source_9]位置不对应"); return false; }
		if(vecLine[12]!="source_10"){Ex.Logger.Log("ItemSource.csv中字段[source_10]位置不对应"); return false; }
		if(vecLine[13]!="source_11"){Ex.Logger.Log("ItemSource.csv中字段[source_11]位置不对应"); return false; }
		if(vecLine[14]!="source_12"){Ex.Logger.Log("ItemSource.csv中字段[source_12]位置不对应"); return false; }
		if(vecLine[15]!="source_13"){Ex.Logger.Log("ItemSource.csv中字段[source_13]位置不对应"); return false; }
		if(vecLine[16]!="source_14"){Ex.Logger.Log("ItemSource.csv中字段[source_14]位置不对应"); return false; }
		if(vecLine[17]!="source_15"){Ex.Logger.Log("ItemSource.csv中字段[source_15]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ItemSourceElement member = new ItemSourceElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.count );
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_8);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_9);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_10);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_12);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_13);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_14);
			readPos += GameAssist.ReadString( binContent, readPos, out member.source_15);

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
			Ex.Logger.Log("ItemSource.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ItemSource.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ItemSource.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="count"){Ex.Logger.Log("ItemSource.csv中字段[count]位置不对应"); return false; }
		if(vecLine[3]!="source_1"){Ex.Logger.Log("ItemSource.csv中字段[source_1]位置不对应"); return false; }
		if(vecLine[4]!="source_2"){Ex.Logger.Log("ItemSource.csv中字段[source_2]位置不对应"); return false; }
		if(vecLine[5]!="source_3"){Ex.Logger.Log("ItemSource.csv中字段[source_3]位置不对应"); return false; }
		if(vecLine[6]!="source_4"){Ex.Logger.Log("ItemSource.csv中字段[source_4]位置不对应"); return false; }
		if(vecLine[7]!="source_5"){Ex.Logger.Log("ItemSource.csv中字段[source_5]位置不对应"); return false; }
		if(vecLine[8]!="source_6"){Ex.Logger.Log("ItemSource.csv中字段[source_6]位置不对应"); return false; }
		if(vecLine[9]!="source_7"){Ex.Logger.Log("ItemSource.csv中字段[source_7]位置不对应"); return false; }
		if(vecLine[10]!="source_8"){Ex.Logger.Log("ItemSource.csv中字段[source_8]位置不对应"); return false; }
		if(vecLine[11]!="source_9"){Ex.Logger.Log("ItemSource.csv中字段[source_9]位置不对应"); return false; }
		if(vecLine[12]!="source_10"){Ex.Logger.Log("ItemSource.csv中字段[source_10]位置不对应"); return false; }
		if(vecLine[13]!="source_11"){Ex.Logger.Log("ItemSource.csv中字段[source_11]位置不对应"); return false; }
		if(vecLine[14]!="source_12"){Ex.Logger.Log("ItemSource.csv中字段[source_12]位置不对应"); return false; }
		if(vecLine[15]!="source_13"){Ex.Logger.Log("ItemSource.csv中字段[source_13]位置不对应"); return false; }
		if(vecLine[16]!="source_14"){Ex.Logger.Log("ItemSource.csv中字段[source_14]位置不对应"); return false; }
		if(vecLine[17]!="source_15"){Ex.Logger.Log("ItemSource.csv中字段[source_15]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)18)
			{
				return false;
			}
			ItemSourceElement member = new ItemSourceElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.count=Convert.ToInt32(vecLine[2]);
			member.source_1=vecLine[3];
			member.source_2=vecLine[4];
			member.source_3=vecLine[5];
			member.source_4=vecLine[6];
			member.source_5=vecLine[7];
			member.source_6=vecLine[8];
			member.source_7=vecLine[9];
			member.source_8=vecLine[10];
			member.source_9=vecLine[11];
			member.source_10=vecLine[12];
			member.source_11=vecLine[13];
			member.source_12=vecLine[14];
			member.source_13=vecLine[15];
			member.source_14=vecLine[16];
			member.source_15=vecLine[17];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
