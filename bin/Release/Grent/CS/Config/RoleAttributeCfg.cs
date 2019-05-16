using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色属性值配置数据类
public class RoleAttributeElement
{
	public int id;               	//id	无意义
	public int config_id;        	//配置id	对应role表中的id
	public string comment;       	//注释	注释
	public int attr_type;        	//属性类型	属性类型
	public int attr_value;       	//初始属性值	初始属性值
	public int attr_add;         	//成长属性值	成长属性值

	public bool IsValidate = false;
	public RoleAttributeElement()
	{
		id = -1;
	}
};

//角色属性值配置封装类
public class RoleAttributeTable
{

	private RoleAttributeTable()
	{
		m_mapElements = new Dictionary<int, RoleAttributeElement>();
		m_emptyItem = new RoleAttributeElement();
		m_vecAllElements = new List<RoleAttributeElement>();
	}
	private Dictionary<int, RoleAttributeElement> m_mapElements = null;
	private List<RoleAttributeElement>	m_vecAllElements = null;
	private RoleAttributeElement m_emptyItem = null;
	private static RoleAttributeTable sInstance = null;

	public static RoleAttributeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RoleAttributeTable();
			return sInstance;
		}
	}

	public RoleAttributeElement GetElement(int key)
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

  public List<RoleAttributeElement> GetAllElement(Predicate<RoleAttributeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("RoleAttribute.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("RoleAttribute.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[RoleAttribute.bin]未找到");
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
			Ex.Logger.Log("RoleAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("RoleAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="config_id"){Ex.Logger.Log("RoleAttribute.csv中字段[config_id]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("RoleAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="attr_type"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_type]位置不对应"); return false; }
		if(vecLine[4]!="attr_value"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_value]位置不对应"); return false; }
		if(vecLine[5]!="attr_add"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_add]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RoleAttributeElement member = new RoleAttributeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.config_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attr_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attr_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attr_add );

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
			Ex.Logger.Log("RoleAttribute.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("RoleAttribute.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="config_id"){Ex.Logger.Log("RoleAttribute.csv中字段[config_id]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("RoleAttribute.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="attr_type"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_type]位置不对应"); return false; }
		if(vecLine[4]!="attr_value"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_value]位置不对应"); return false; }
		if(vecLine[5]!="attr_add"){Ex.Logger.Log("RoleAttribute.csv中字段[attr_add]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)6)
			{
				return false;
			}
			RoleAttributeElement member = new RoleAttributeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.config_id=Convert.ToInt32(vecLine[1]);
			member.comment=vecLine[2];
			member.attr_type=Convert.ToInt32(vecLine[3]);
			member.attr_value=Convert.ToInt32(vecLine[4]);
			member.attr_add=Convert.ToInt32(vecLine[5]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
