using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝石镶嵌表配置数据类
public class GeminsertElement
{
	public int id;               	//可镶嵌部位	填写ID即可
	public string comment;       	//注释	策划用
	public int name;             	//部位名	填写文本ID
	public int part;             	//对应装备部位	填写ID
	public string part_icon;     	//装备部位图标	填写图标名
	public li part_gem;          	//装备上可镶嵌的宝石	填写宝石ID
	public int part1_needlv;     	//槽位解锁等级	填写等级即可
	public int part1_type;       	//0自动解锁1手动解锁	填1或0
	public li part1_unlock;      	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	public int part2_needlv;     	//槽位解锁等级	填写等级即可
	public int part2_type;       	//0自动解锁1手动解锁	填1或0
	public li part2_unlock;      	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	public int part3_needlv;     	//槽位解锁等级	填写等级即可
	public int part3_type;       	//0自动解锁1手动解锁	填1或0
	public li part3_unlock;      	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量

	public bool IsValidate = false;
	public GeminsertElement()
	{
		id = -1;
	}
};

//宝石镶嵌表配置封装类
public class GeminsertTable
{

	private GeminsertTable()
	{
		m_mapElements = new Dictionary<int, GeminsertElement>();
		m_emptyItem = new GeminsertElement();
		m_vecAllElements = new List<GeminsertElement>();
	}
	private Dictionary<int, GeminsertElement> m_mapElements = null;
	private List<GeminsertElement>	m_vecAllElements = null;
	private GeminsertElement m_emptyItem = null;
	private static GeminsertTable sInstance = null;

	public static GeminsertTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GeminsertTable();
			return sInstance;
		}
	}

	public GeminsertElement GetElement(int key)
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

  public List<GeminsertElement> GetAllElement(Predicate<GeminsertElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Geminsert.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Geminsert.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Geminsert.bin]未找到");
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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Geminsert.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Geminsert.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Geminsert.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Geminsert.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="part"){Ex.Logger.Log("Geminsert.csv中字段[part]位置不对应"); return false; }
		if(vecLine[4]!="part_icon"){Ex.Logger.Log("Geminsert.csv中字段[part_icon]位置不对应"); return false; }
		if(vecLine[5]!="part_gem"){Ex.Logger.Log("Geminsert.csv中字段[part_gem]位置不对应"); return false; }
		if(vecLine[6]!="part1_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part1_needlv]位置不对应"); return false; }
		if(vecLine[7]!="part1_type"){Ex.Logger.Log("Geminsert.csv中字段[part1_type]位置不对应"); return false; }
		if(vecLine[8]!="part1_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part1_unlock]位置不对应"); return false; }
		if(vecLine[9]!="part2_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part2_needlv]位置不对应"); return false; }
		if(vecLine[10]!="part2_type"){Ex.Logger.Log("Geminsert.csv中字段[part2_type]位置不对应"); return false; }
		if(vecLine[11]!="part2_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part2_unlock]位置不对应"); return false; }
		if(vecLine[12]!="part3_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part3_needlv]位置不对应"); return false; }
		if(vecLine[13]!="part3_type"){Ex.Logger.Log("Geminsert.csv中字段[part3_type]位置不对应"); return false; }
		if(vecLine[14]!="part3_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part3_unlock]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GeminsertElement member = new GeminsertElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part );
			readPos += GameAssist.ReadString( binContent, readPos, out member.part_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.part_gem);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part1_needlv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part1_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.part1_unlock);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part2_needlv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part2_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.part2_unlock);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part3_needlv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part3_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.part3_unlock);

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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("Geminsert.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Geminsert.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Geminsert.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Geminsert.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="part"){Ex.Logger.Log("Geminsert.csv中字段[part]位置不对应"); return false; }
		if(vecLine[4]!="part_icon"){Ex.Logger.Log("Geminsert.csv中字段[part_icon]位置不对应"); return false; }
		if(vecLine[5]!="part_gem"){Ex.Logger.Log("Geminsert.csv中字段[part_gem]位置不对应"); return false; }
		if(vecLine[6]!="part1_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part1_needlv]位置不对应"); return false; }
		if(vecLine[7]!="part1_type"){Ex.Logger.Log("Geminsert.csv中字段[part1_type]位置不对应"); return false; }
		if(vecLine[8]!="part1_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part1_unlock]位置不对应"); return false; }
		if(vecLine[9]!="part2_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part2_needlv]位置不对应"); return false; }
		if(vecLine[10]!="part2_type"){Ex.Logger.Log("Geminsert.csv中字段[part2_type]位置不对应"); return false; }
		if(vecLine[11]!="part2_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part2_unlock]位置不对应"); return false; }
		if(vecLine[12]!="part3_needlv"){Ex.Logger.Log("Geminsert.csv中字段[part3_needlv]位置不对应"); return false; }
		if(vecLine[13]!="part3_type"){Ex.Logger.Log("Geminsert.csv中字段[part3_type]位置不对应"); return false; }
		if(vecLine[14]!="part3_unlock"){Ex.Logger.Log("Geminsert.csv中字段[part3_unlock]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)15)
			{
				return false;
			}
			GeminsertElement member = new GeminsertElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.part=Convert.ToInt32(vecLine[3]);
			member.part_icon=vecLine[4];
			member.part_gem=vecLine[5];
			member.part1_needlv=Convert.ToInt32(vecLine[6]);
			member.part1_type=Convert.ToInt32(vecLine[7]);
			member.part1_unlock=vecLine[8];
			member.part2_needlv=Convert.ToInt32(vecLine[9]);
			member.part2_type=Convert.ToInt32(vecLine[10]);
			member.part2_unlock=vecLine[11];
			member.part3_needlv=Convert.ToInt32(vecLine[12]);
			member.part3_type=Convert.ToInt32(vecLine[13]);
			member.part3_unlock=vecLine[14];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
