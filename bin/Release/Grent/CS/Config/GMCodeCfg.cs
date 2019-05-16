using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//GM指令配置数据类
public class GMCodeElement
{
	public int id;               	//指令id	序号
	public string  code;         	//指令名称	值 需要服务器处理的前缀为. 只需要客户端处理的前缀为/
	public string name;          	//中文名称	描述
	public string desc;          	//功能说明	策划使用
	public int param1;           	//指令参数1	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	public int param2;           	//指令参数2	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	public int param3;           	//指令参数3	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	public int param4;           	//指令参数4	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	public int code_catalog;     	//指令分类	0.未分类 1.角色 2.移动 3.战斗 4.其它
	public string param_example; 	//参数解释	
	public string param_desc;    	//参数说明	
	public string comment;       	//其他信息	

	public bool IsValidate = false;
	public GMCodeElement()
	{
		id = -1;
	}
};

//GM指令配置封装类
public class GMCodeTable
{

	private GMCodeTable()
	{
		m_mapElements = new Dictionary<int, GMCodeElement>();
		m_emptyItem = new GMCodeElement();
		m_vecAllElements = new List<GMCodeElement>();
	}
	private Dictionary<int, GMCodeElement> m_mapElements = null;
	private List<GMCodeElement>	m_vecAllElements = null;
	private GMCodeElement m_emptyItem = null;
	private static GMCodeTable sInstance = null;

	public static GMCodeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GMCodeTable();
			return sInstance;
		}
	}

	public GMCodeElement GetElement(int key)
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

  public List<GMCodeElement> GetAllElement(Predicate<GMCodeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("GMCode.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("GMCode.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[GMCode.bin]未找到");
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
			Ex.Logger.Log("GMCode.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("GMCode.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!=" code"){Ex.Logger.Log("GMCode.csv中字段[ code]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("GMCode.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("GMCode.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="param1"){Ex.Logger.Log("GMCode.csv中字段[param1]位置不对应"); return false; }
		if(vecLine[5]!="param2"){Ex.Logger.Log("GMCode.csv中字段[param2]位置不对应"); return false; }
		if(vecLine[6]!="param3"){Ex.Logger.Log("GMCode.csv中字段[param3]位置不对应"); return false; }
		if(vecLine[7]!="param4"){Ex.Logger.Log("GMCode.csv中字段[param4]位置不对应"); return false; }
		if(vecLine[8]!="code_catalog"){Ex.Logger.Log("GMCode.csv中字段[code_catalog]位置不对应"); return false; }
		if(vecLine[9]!="param_example"){Ex.Logger.Log("GMCode.csv中字段[param_example]位置不对应"); return false; }
		if(vecLine[10]!="param_desc"){Ex.Logger.Log("GMCode.csv中字段[param_desc]位置不对应"); return false; }
		if(vecLine[11]!="comment"){Ex.Logger.Log("GMCode.csv中字段[comment]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GMCodeElement member = new GMCodeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member. code);
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.param1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.param2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.param3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.param4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.code_catalog );
			readPos += GameAssist.ReadString( binContent, readPos, out member.param_example);
			readPos += GameAssist.ReadString( binContent, readPos, out member.param_desc);
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);

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
			Ex.Logger.Log("GMCode.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("GMCode.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!=" code"){Ex.Logger.Log("GMCode.csv中字段[ code]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("GMCode.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("GMCode.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="param1"){Ex.Logger.Log("GMCode.csv中字段[param1]位置不对应"); return false; }
		if(vecLine[5]!="param2"){Ex.Logger.Log("GMCode.csv中字段[param2]位置不对应"); return false; }
		if(vecLine[6]!="param3"){Ex.Logger.Log("GMCode.csv中字段[param3]位置不对应"); return false; }
		if(vecLine[7]!="param4"){Ex.Logger.Log("GMCode.csv中字段[param4]位置不对应"); return false; }
		if(vecLine[8]!="code_catalog"){Ex.Logger.Log("GMCode.csv中字段[code_catalog]位置不对应"); return false; }
		if(vecLine[9]!="param_example"){Ex.Logger.Log("GMCode.csv中字段[param_example]位置不对应"); return false; }
		if(vecLine[10]!="param_desc"){Ex.Logger.Log("GMCode.csv中字段[param_desc]位置不对应"); return false; }
		if(vecLine[11]!="comment"){Ex.Logger.Log("GMCode.csv中字段[comment]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			GMCodeElement member = new GMCodeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member. code=vecLine[1];
			member.name=vecLine[2];
			member.desc=vecLine[3];
			member.param1=Convert.ToInt32(vecLine[4]);
			member.param2=Convert.ToInt32(vecLine[5]);
			member.param3=Convert.ToInt32(vecLine[6]);
			member.param4=Convert.ToInt32(vecLine[7]);
			member.code_catalog=Convert.ToInt32(vecLine[8]);
			member.param_example=vecLine[9];
			member.param_desc=vecLine[10];
			member.comment=vecLine[11];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
