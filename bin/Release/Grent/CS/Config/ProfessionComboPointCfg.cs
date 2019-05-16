using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//职业连击点配置表配置数据类
public class ProfessionComboPointElement
{
	public int id;               	//专精ID	1-防战2-狂战，3-敏锐贼4-战斗贼，5-射击猎6-生存猎，7-火法8-冰法，9-防骑10-奶骑，11-鸟德12-奶德，13-火法男14-冰法男，15-射击猎女16生存猎女。
	public string comment;       	//备注	备注
	public int has_point;        	//是否适用增强/连击点机制	是否有专精点/连击点 1：该专精有此机制 0：改专精没此机制
	public ls dim_resource_name; 	//暗点儿资源名称	暗淡的连击点/的图片资源名称，每个资源图片名称用连接符“|”串联，无数据时保持空
	public ls bright_resource_name;	//亮点儿资源名称	亮起时的连击点/的图片资源名称，每个资源图片名称用连接符“|”串联，无数据时保持空
	public string full_point_effect_name;	//满点儿特效名称	满连击点/的特效资源名称无数据时保持空
	public int max_count;        	//最大点儿数值	最大点儿数值

	public bool IsValidate = false;
	public ProfessionComboPointElement()
	{
		id = -1;
	}
};

//职业连击点配置表配置封装类
public class ProfessionComboPointTable
{

	private ProfessionComboPointTable()
	{
		m_mapElements = new Dictionary<int, ProfessionComboPointElement>();
		m_emptyItem = new ProfessionComboPointElement();
		m_vecAllElements = new List<ProfessionComboPointElement>();
	}
	private Dictionary<int, ProfessionComboPointElement> m_mapElements = null;
	private List<ProfessionComboPointElement>	m_vecAllElements = null;
	private ProfessionComboPointElement m_emptyItem = null;
	private static ProfessionComboPointTable sInstance = null;

	public static ProfessionComboPointTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ProfessionComboPointTable();
			return sInstance;
		}
	}

	public ProfessionComboPointElement GetElement(int key)
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

  public List<ProfessionComboPointElement> GetAllElement(Predicate<ProfessionComboPointElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ProfessionComboPoint.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ProfessionComboPoint.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ProfessionComboPoint.bin]未找到");
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
			Ex.Logger.Log("ProfessionComboPoint.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="has_point"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[has_point]位置不对应"); return false; }
		if(vecLine[3]!="dim_resource_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[dim_resource_name]位置不对应"); return false; }
		if(vecLine[4]!="bright_resource_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[bright_resource_name]位置不对应"); return false; }
		if(vecLine[5]!="full_point_effect_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[full_point_effect_name]位置不对应"); return false; }
		if(vecLine[6]!="max_count"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[max_count]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ProfessionComboPointElement member = new ProfessionComboPointElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.has_point );
			readPos += GameAssist.ReadString( binContent, readPos, out member.dim_resource_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.bright_resource_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.full_point_effect_name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_count );

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
			Ex.Logger.Log("ProfessionComboPoint.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="has_point"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[has_point]位置不对应"); return false; }
		if(vecLine[3]!="dim_resource_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[dim_resource_name]位置不对应"); return false; }
		if(vecLine[4]!="bright_resource_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[bright_resource_name]位置不对应"); return false; }
		if(vecLine[5]!="full_point_effect_name"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[full_point_effect_name]位置不对应"); return false; }
		if(vecLine[6]!="max_count"){Ex.Logger.Log("ProfessionComboPoint.csv中字段[max_count]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			ProfessionComboPointElement member = new ProfessionComboPointElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.has_point=Convert.ToInt32(vecLine[2]);
			member.dim_resource_name=vecLine[3];
			member.bright_resource_name=vecLine[4];
			member.full_point_effect_name=vecLine[5];
			member.max_count=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
