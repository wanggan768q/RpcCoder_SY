using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//公会权限表配置数据类
public class AllianceLimitsElement
{
	public int id;               	//ID	同gloal表
	public string comment;       	//注释	策划用
	public int stringid;         	//权限名	填写stringid
	public int president;        	//会长	有该权限写1没有写-1会长可更改为2
	public int vice_president;   	//副会长	有该权限写1没有写-1
	public int officer;          	//官员	有该权限写1没有写-1
	public int member;           	//会员	有该权限写1没有写-1
	public int location;         	//权限位置	1为上2为下

	public bool IsValidate = false;
	public AllianceLimitsElement()
	{
		id = -1;
	}
};

//公会权限表配置封装类
public class AllianceLimitsTable
{

	private AllianceLimitsTable()
	{
		m_mapElements = new Dictionary<int, AllianceLimitsElement>();
		m_emptyItem = new AllianceLimitsElement();
		m_vecAllElements = new List<AllianceLimitsElement>();
	}
	private Dictionary<int, AllianceLimitsElement> m_mapElements = null;
	private List<AllianceLimitsElement>	m_vecAllElements = null;
	private AllianceLimitsElement m_emptyItem = null;
	private static AllianceLimitsTable sInstance = null;

	public static AllianceLimitsTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AllianceLimitsTable();
			return sInstance;
		}
	}

	public AllianceLimitsElement GetElement(int key)
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

  public List<AllianceLimitsElement> GetAllElement(Predicate<AllianceLimitsElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AllianceLimits.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AllianceLimits.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AllianceLimits.bin]未找到");
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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("AllianceLimits.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceLimits.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceLimits.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="stringid"){Ex.Logger.Log("AllianceLimits.csv中字段[stringid]位置不对应"); return false; }
		if(vecLine[3]!="president"){Ex.Logger.Log("AllianceLimits.csv中字段[president]位置不对应"); return false; }
		if(vecLine[4]!="vice_president"){Ex.Logger.Log("AllianceLimits.csv中字段[vice_president]位置不对应"); return false; }
		if(vecLine[5]!="officer"){Ex.Logger.Log("AllianceLimits.csv中字段[officer]位置不对应"); return false; }
		if(vecLine[6]!="member"){Ex.Logger.Log("AllianceLimits.csv中字段[member]位置不对应"); return false; }
		if(vecLine[7]!="location"){Ex.Logger.Log("AllianceLimits.csv中字段[location]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AllianceLimitsElement member = new AllianceLimitsElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stringid );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.president );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.vice_president );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.officer );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.member );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.location );

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
		if(vecLine.Count != 8)
		{
			Ex.Logger.Log("AllianceLimits.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AllianceLimits.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AllianceLimits.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="stringid"){Ex.Logger.Log("AllianceLimits.csv中字段[stringid]位置不对应"); return false; }
		if(vecLine[3]!="president"){Ex.Logger.Log("AllianceLimits.csv中字段[president]位置不对应"); return false; }
		if(vecLine[4]!="vice_president"){Ex.Logger.Log("AllianceLimits.csv中字段[vice_president]位置不对应"); return false; }
		if(vecLine[5]!="officer"){Ex.Logger.Log("AllianceLimits.csv中字段[officer]位置不对应"); return false; }
		if(vecLine[6]!="member"){Ex.Logger.Log("AllianceLimits.csv中字段[member]位置不对应"); return false; }
		if(vecLine[7]!="location"){Ex.Logger.Log("AllianceLimits.csv中字段[location]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)8)
			{
				return false;
			}
			AllianceLimitsElement member = new AllianceLimitsElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.stringid=Convert.ToInt32(vecLine[2]);
			member.president=Convert.ToInt32(vecLine[3]);
			member.vice_president=Convert.ToInt32(vecLine[4]);
			member.officer=Convert.ToInt32(vecLine[5]);
			member.member=Convert.ToInt32(vecLine[6]);
			member.location=Convert.ToInt32(vecLine[7]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
