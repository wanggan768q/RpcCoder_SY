using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色自定义配置数据类
public class CharacterCustomizeElement
{
	public int id;               	//配置ID	ID段划分： 前3位-职业 4、5位-套装 6位-部位
	public string comment;       	//描述	仅策划用
	public string filename;      	//模型文件名	模型文件名
	public string  material;     	//材质	需要更换的材质文件 （时装染色）
	public float zoom;           	//缩放比例	缩放比例
	public float interface_zoom; 	//界面缩放	控制界面内的缩放比例 （缩放人物与坐骑整体）
	public int part;             	//模型对应的自定义部位	枚举定义 1.头部 2.面部 3.身体 4.武器 5.翅膀 6.坐骑
	public float height;         	//高度	仅对坐骑生效 只针对飞行类坐骑
	public float camera_height;  	//摄像机高度	仅对坐骑生效 提高坐骑相机高度

	public bool IsValidate = false;
	public CharacterCustomizeElement()
	{
		id = -1;
	}
};

//角色自定义配置封装类
public class CharacterCustomizeTable
{

	private CharacterCustomizeTable()
	{
		m_mapElements = new Dictionary<int, CharacterCustomizeElement>();
		m_emptyItem = new CharacterCustomizeElement();
		m_vecAllElements = new List<CharacterCustomizeElement>();
	}
	private Dictionary<int, CharacterCustomizeElement> m_mapElements = null;
	private List<CharacterCustomizeElement>	m_vecAllElements = null;
	private CharacterCustomizeElement m_emptyItem = null;
	private static CharacterCustomizeTable sInstance = null;

	public static CharacterCustomizeTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CharacterCustomizeTable();
			return sInstance;
		}
	}

	public CharacterCustomizeElement GetElement(int key)
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

  public List<CharacterCustomizeElement> GetAllElement(Predicate<CharacterCustomizeElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CharacterCustomize.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CharacterCustomize.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CharacterCustomize.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("CharacterCustomize.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CharacterCustomize.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CharacterCustomize.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="filename"){Ex.Logger.Log("CharacterCustomize.csv中字段[filename]位置不对应"); return false; }
		if(vecLine[3]!=" material"){Ex.Logger.Log("CharacterCustomize.csv中字段[ material]位置不对应"); return false; }
		if(vecLine[4]!="zoom"){Ex.Logger.Log("CharacterCustomize.csv中字段[zoom]位置不对应"); return false; }
		if(vecLine[5]!="interface_zoom"){Ex.Logger.Log("CharacterCustomize.csv中字段[interface_zoom]位置不对应"); return false; }
		if(vecLine[6]!="part"){Ex.Logger.Log("CharacterCustomize.csv中字段[part]位置不对应"); return false; }
		if(vecLine[7]!="height"){Ex.Logger.Log("CharacterCustomize.csv中字段[height]位置不对应"); return false; }
		if(vecLine[8]!="camera_height"){Ex.Logger.Log("CharacterCustomize.csv中字段[camera_height]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CharacterCustomizeElement member = new CharacterCustomizeElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.filename);
			readPos += GameAssist.ReadString( binContent, readPos, out member. material);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.zoom);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.interface_zoom);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.height);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.camera_height);

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("CharacterCustomize.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CharacterCustomize.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CharacterCustomize.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="filename"){Ex.Logger.Log("CharacterCustomize.csv中字段[filename]位置不对应"); return false; }
		if(vecLine[3]!=" material"){Ex.Logger.Log("CharacterCustomize.csv中字段[ material]位置不对应"); return false; }
		if(vecLine[4]!="zoom"){Ex.Logger.Log("CharacterCustomize.csv中字段[zoom]位置不对应"); return false; }
		if(vecLine[5]!="interface_zoom"){Ex.Logger.Log("CharacterCustomize.csv中字段[interface_zoom]位置不对应"); return false; }
		if(vecLine[6]!="part"){Ex.Logger.Log("CharacterCustomize.csv中字段[part]位置不对应"); return false; }
		if(vecLine[7]!="height"){Ex.Logger.Log("CharacterCustomize.csv中字段[height]位置不对应"); return false; }
		if(vecLine[8]!="camera_height"){Ex.Logger.Log("CharacterCustomize.csv中字段[camera_height]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			CharacterCustomizeElement member = new CharacterCustomizeElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.filename=vecLine[2];
			member. material=vecLine[3];
			member.zoom=Convert.ToSingle(vecLine[4]);
			member.interface_zoom=Convert.ToSingle(vecLine[5]);
			member.part=Convert.ToInt32(vecLine[6]);
			member.height=Convert.ToSingle(vecLine[7]);
			member.camera_height=Convert.ToSingle(vecLine[8]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
