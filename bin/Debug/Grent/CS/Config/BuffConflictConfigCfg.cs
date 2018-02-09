using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//Buff组关系配置数据类
public class BuffConflictConfigElement
{
	public int id;               	//组id	组id 必须保证ID 是顺序的
	public string desc;          	//组名	仅策划用
	public string group;         	//组标识	1=冲抵, 2=免疫, 3=共存
	public int g1;               	//眩晕	无法移动 无法使用技能 晕眩动作
	public int g2;               	//霸体	免疫负面效果
	public int g3;               	//减速	减少移动速度
	public li allgroup;          	//合并	公式不要手填！！！

	public bool IsValidate = false;
	public BuffConflictConfigElement()
	{
		id = -1;
	}
};

//Buff组关系配置封装类
public class BuffConflictConfigTable
{

	private BuffConflictConfigTable()
	{
		m_mapElements = new Dictionary<int, BuffConflictConfigElement>();
		m_emptyItem = new BuffConflictConfigElement();
		m_vecAllElements = new List<BuffConflictConfigElement>();
	}
	private Dictionary<int, BuffConflictConfigElement> m_mapElements = null;
	private List<BuffConflictConfigElement>	m_vecAllElements = null;
	private BuffConflictConfigElement m_emptyItem = null;
	private static BuffConflictConfigTable sInstance = null;

	public static BuffConflictConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffConflictConfigTable();
			return sInstance;
		}
	}

	public BuffConflictConfigElement GetElement(int key)
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

  public List<BuffConflictConfigElement> GetAllElement(Predicate<BuffConflictConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BuffConflictConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BuffConflictConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[BuffConflictConfig.bin]未找到");
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
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffConflictConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[4]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[5]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[6]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadString( binContent, readPos, out member.group);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.allgroup);

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
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffConflictConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[4]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[5]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[6]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.desc=vecLine[1];
			member.group=vecLine[2];
			member.g1=Convert.ToInt32(vecLine[3]);
			member.g2=Convert.ToInt32(vecLine[4]);
			member.g3=Convert.ToInt32(vecLine[5]);
			member.allgroup=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
