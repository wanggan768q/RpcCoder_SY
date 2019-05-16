using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//冒字显示配置数据类
public class DamageFloatElement
{
	public int id;               	//冒字顺序	冒字顺序
	public string desc;          	//参数说明	仅说明
	public int faction;          	//阵营	1：通用 2：玩家 3 : 敌人
	public int type;             	//冒字类型	1 - 普通伤害 2 - 暴击 3 - 格挡 4 - 暴击加格挡 5 - 恢复 6 - 闪避 7 - 眩晕 8 - 减速 9 - 定身 10 - 冰冻 11 - 沉默 12 - 无敌
	public int subtype;          	//对应的BuffID	对应的BuffID
	public int desc_id;          	//文本	StringBuff_buff_id
	public string icon;          	//要显示的图标	图标显示在文字的前面,图标要添加需要找程序从新打图集
	public string res_colour;    	//颜色	资源名称
	public string res_frame;     	//边框	资源名称
	public string res_animation; 	//动画	资源名称

	public bool IsValidate = false;
	public DamageFloatElement()
	{
		id = -1;
	}
};

//冒字显示配置封装类
public class DamageFloatTable
{

	private DamageFloatTable()
	{
		m_mapElements = new Dictionary<int, DamageFloatElement>();
		m_emptyItem = new DamageFloatElement();
		m_vecAllElements = new List<DamageFloatElement>();
	}
	private Dictionary<int, DamageFloatElement> m_mapElements = null;
	private List<DamageFloatElement>	m_vecAllElements = null;
	private DamageFloatElement m_emptyItem = null;
	private static DamageFloatTable sInstance = null;

	public static DamageFloatTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new DamageFloatTable();
			return sInstance;
		}
	}

	public DamageFloatElement GetElement(int key)
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

  public List<DamageFloatElement> GetAllElement(Predicate<DamageFloatElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("DamageFloat.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("DamageFloat.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[DamageFloat.bin]未找到");
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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("DamageFloat.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DamageFloat.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("DamageFloat.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="faction"){Ex.Logger.Log("DamageFloat.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("DamageFloat.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="subtype"){Ex.Logger.Log("DamageFloat.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[5]!="desc_id"){Ex.Logger.Log("DamageFloat.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("DamageFloat.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="res_colour"){Ex.Logger.Log("DamageFloat.csv中字段[res_colour]位置不对应"); return false; }
		if(vecLine[8]!="res_frame"){Ex.Logger.Log("DamageFloat.csv中字段[res_frame]位置不对应"); return false; }
		if(vecLine[9]!="res_animation"){Ex.Logger.Log("DamageFloat.csv中字段[res_animation]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DamageFloatElement member = new DamageFloatElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.faction );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subtype );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.res_colour);
			readPos += GameAssist.ReadString( binContent, readPos, out member.res_frame);
			readPos += GameAssist.ReadString( binContent, readPos, out member.res_animation);

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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("DamageFloat.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DamageFloat.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("DamageFloat.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="faction"){Ex.Logger.Log("DamageFloat.csv中字段[faction]位置不对应"); return false; }
		if(vecLine[3]!="type"){Ex.Logger.Log("DamageFloat.csv中字段[type]位置不对应"); return false; }
		if(vecLine[4]!="subtype"){Ex.Logger.Log("DamageFloat.csv中字段[subtype]位置不对应"); return false; }
		if(vecLine[5]!="desc_id"){Ex.Logger.Log("DamageFloat.csv中字段[desc_id]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("DamageFloat.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="res_colour"){Ex.Logger.Log("DamageFloat.csv中字段[res_colour]位置不对应"); return false; }
		if(vecLine[8]!="res_frame"){Ex.Logger.Log("DamageFloat.csv中字段[res_frame]位置不对应"); return false; }
		if(vecLine[9]!="res_animation"){Ex.Logger.Log("DamageFloat.csv中字段[res_animation]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)10)
			{
				return false;
			}
			DamageFloatElement member = new DamageFloatElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.desc=vecLine[1];
			member.faction=Convert.ToInt32(vecLine[2]);
			member.type=Convert.ToInt32(vecLine[3]);
			member.subtype=Convert.ToInt32(vecLine[4]);
			member.desc_id=Convert.ToInt32(vecLine[5]);
			member.icon=vecLine[6];
			member.res_colour=vecLine[7];
			member.res_frame=vecLine[8];
			member.res_animation=vecLine[9];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
