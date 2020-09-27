using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//服务器列表配置配置数据类
public class ServerListElement
{
	public int id;               	//id	服务器的id
	public int region;           	//区域	该服务器处于哪个大区
	public int name;             	//名称	对应文本表中的id
	public int status;           	//状态	对应服务器的状态 0.正常 1.爆满
	public int promo;            	//推荐	该服务器是否为推荐服 0.不推荐 1.推荐
	public string ip;            	//服务器ip	该服务器的ip
	public int port;             	//端口	该服务器的端口

	public bool IsValidate = false;
	public ServerListElement()
	{
		id = -1;
	}
};

//服务器列表配置配置封装类
public class ServerListTable
{

	private ServerListTable()
	{
		m_mapElements = new Dictionary<int, ServerListElement>();
		m_emptyItem = new ServerListElement();
		m_vecAllElements = new List<ServerListElement>();
	}
	private Dictionary<int, ServerListElement> m_mapElements = null;
	private List<ServerListElement>	m_vecAllElements = null;
	private ServerListElement m_emptyItem = null;
	private static ServerListTable sInstance = null;

	public static ServerListTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ServerListTable();
			return sInstance;
		}
	}

	public ServerListElement GetElement(int key)
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

  public List<ServerListElement> GetAllElement(Predicate<ServerListElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ServerList.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ServerList.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ServerList.bin]未找到");
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
			Ex.Logger.Log("ServerList.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ServerList.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="region"){Ex.Logger.Log("ServerList.csv中字段[region]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ServerList.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="status"){Ex.Logger.Log("ServerList.csv中字段[status]位置不对应"); return false; }
		if(vecLine[4]!="promo"){Ex.Logger.Log("ServerList.csv中字段[promo]位置不对应"); return false; }
		if(vecLine[5]!="ip"){Ex.Logger.Log("ServerList.csv中字段[ip]位置不对应"); return false; }
		if(vecLine[6]!="port"){Ex.Logger.Log("ServerList.csv中字段[port]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ServerListElement member = new ServerListElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.region );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.status );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.promo );
			readPos += GameAssist.ReadString( binContent, readPos, out member.ip);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.port );

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
			Ex.Logger.Log("ServerList.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ServerList.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="region"){Ex.Logger.Log("ServerList.csv中字段[region]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("ServerList.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="status"){Ex.Logger.Log("ServerList.csv中字段[status]位置不对应"); return false; }
		if(vecLine[4]!="promo"){Ex.Logger.Log("ServerList.csv中字段[promo]位置不对应"); return false; }
		if(vecLine[5]!="ip"){Ex.Logger.Log("ServerList.csv中字段[ip]位置不对应"); return false; }
		if(vecLine[6]!="port"){Ex.Logger.Log("ServerList.csv中字段[port]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			ServerListElement member = new ServerListElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.region=Convert.ToInt32(vecLine[1]);
			member.name=Convert.ToInt32(vecLine[2]);
			member.status=Convert.ToInt32(vecLine[3]);
			member.promo=Convert.ToInt32(vecLine[4]);
			member.ip=vecLine[5];
			member.port=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
