using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//系统预览配置数据类
public class SystemPreviewElement
{
	public int id;               	//条目id	该系统的索引id
	public string comment;       	//注释	该预览的内容
	public int unlock_lv;        	//解锁等级	该系统解锁的等级
	public int system_name;      	//预告功能名称	系统的名称文本
	public int system_desc;      	//预告功能描述	系统的描述文本
	public string system_icon;   	//系统图标	显示在HUD上的预告图标
	public string preview_pic;   	//预告功能图片	显示在系统预告面板的图片

	public bool IsValidate = false;
	public SystemPreviewElement()
	{
		id = -1;
	}
};

//系统预览配置封装类
public class SystemPreviewTable
{

	private SystemPreviewTable()
	{
		m_mapElements = new Dictionary<int, SystemPreviewElement>();
		m_emptyItem = new SystemPreviewElement();
		m_vecAllElements = new List<SystemPreviewElement>();
	}
	private Dictionary<int, SystemPreviewElement> m_mapElements = null;
	private List<SystemPreviewElement>	m_vecAllElements = null;
	private SystemPreviewElement m_emptyItem = null;
	private static SystemPreviewTable sInstance = null;

	public static SystemPreviewTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SystemPreviewTable();
			return sInstance;
		}
	}

	public SystemPreviewElement GetElement(int key)
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

  public List<SystemPreviewElement> GetAllElement(Predicate<SystemPreviewElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("SystemPreview.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("SystemPreview.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[SystemPreview.bin]未找到");
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
			Ex.Logger.Log("SystemPreview.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SystemPreview.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("SystemPreview.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="unlock_lv"){Ex.Logger.Log("SystemPreview.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[3]!="system_name"){Ex.Logger.Log("SystemPreview.csv中字段[system_name]位置不对应"); return false; }
		if(vecLine[4]!="system_desc"){Ex.Logger.Log("SystemPreview.csv中字段[system_desc]位置不对应"); return false; }
		if(vecLine[5]!="system_icon"){Ex.Logger.Log("SystemPreview.csv中字段[system_icon]位置不对应"); return false; }
		if(vecLine[6]!="preview_pic"){Ex.Logger.Log("SystemPreview.csv中字段[preview_pic]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SystemPreviewElement member = new SystemPreviewElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.system_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.system_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.system_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.preview_pic);

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
			Ex.Logger.Log("SystemPreview.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("SystemPreview.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("SystemPreview.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="unlock_lv"){Ex.Logger.Log("SystemPreview.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[3]!="system_name"){Ex.Logger.Log("SystemPreview.csv中字段[system_name]位置不对应"); return false; }
		if(vecLine[4]!="system_desc"){Ex.Logger.Log("SystemPreview.csv中字段[system_desc]位置不对应"); return false; }
		if(vecLine[5]!="system_icon"){Ex.Logger.Log("SystemPreview.csv中字段[system_icon]位置不对应"); return false; }
		if(vecLine[6]!="preview_pic"){Ex.Logger.Log("SystemPreview.csv中字段[preview_pic]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			SystemPreviewElement member = new SystemPreviewElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.unlock_lv=Convert.ToInt32(vecLine[2]);
			member.system_name=Convert.ToInt32(vecLine[3]);
			member.system_desc=Convert.ToInt32(vecLine[4]);
			member.system_icon=vecLine[5];
			member.preview_pic=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
