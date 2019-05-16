using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//合成数据表配置数据类
public class MixInfoElement
{
	public int id;               	//合成道具id	该道具的id
	public string comment;       	//阶级注释	策划用
	public int type;             	//合成类型	道具所属的标签类型
	public int ytpe_name;        	//类型名称	道具所属的标签类型名称 对应string_ui
	public li demand1;           	//合成信息1	合成所需物品的id|数量|失败消耗数
	public li demand2;           	//合成信息2	合成所需物品的id|数量|失败消耗数
	public li demand3;           	//合成信息3	合成所需物品的id|数量|失败消耗数
	public int mix_cost;         	//合成花费	合成所需花费的银币数量
	public int mix_probability;  	//合成成功率	合成该道具的成功率（暂不使用）
	public int avoid_fail;       	//保护道具	可防止合成失败的道具id(暂不使用）
	public int avoid_num;        	//保护道具数量	防止合成失败的道具数量（暂不使用）

	public bool IsValidate = false;
	public MixInfoElement()
	{
		id = -1;
	}
};

//合成数据表配置封装类
public class MixInfoTable
{

	private MixInfoTable()
	{
		m_mapElements = new Dictionary<int, MixInfoElement>();
		m_emptyItem = new MixInfoElement();
		m_vecAllElements = new List<MixInfoElement>();
	}
	private Dictionary<int, MixInfoElement> m_mapElements = null;
	private List<MixInfoElement>	m_vecAllElements = null;
	private MixInfoElement m_emptyItem = null;
	private static MixInfoTable sInstance = null;

	public static MixInfoTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MixInfoTable();
			return sInstance;
		}
	}

	public MixInfoElement GetElement(int key)
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

  public List<MixInfoElement> GetAllElement(Predicate<MixInfoElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("MixInfo.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("MixInfo.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[MixInfo.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("MixInfo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("MixInfo.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("MixInfo.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("MixInfo.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="ytpe_name"){Ex.Logger.Log("MixInfo.csv中字段[ytpe_name]位置不对应"); return false; }
		if(vecLine[4]!="demand1"){Ex.Logger.Log("MixInfo.csv中字段[demand1]位置不对应"); return false; }
		if(vecLine[5]!="demand2"){Ex.Logger.Log("MixInfo.csv中字段[demand2]位置不对应"); return false; }
		if(vecLine[6]!="demand3"){Ex.Logger.Log("MixInfo.csv中字段[demand3]位置不对应"); return false; }
		if(vecLine[7]!="mix_cost"){Ex.Logger.Log("MixInfo.csv中字段[mix_cost]位置不对应"); return false; }
		if(vecLine[8]!="mix_probability"){Ex.Logger.Log("MixInfo.csv中字段[mix_probability]位置不对应"); return false; }
		if(vecLine[9]!="avoid_fail"){Ex.Logger.Log("MixInfo.csv中字段[avoid_fail]位置不对应"); return false; }
		if(vecLine[10]!="avoid_num"){Ex.Logger.Log("MixInfo.csv中字段[avoid_num]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MixInfoElement member = new MixInfoElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ytpe_name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.demand1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.demand2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.demand3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mix_cost );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mix_probability );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.avoid_fail );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.avoid_num );

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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("MixInfo.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("MixInfo.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("MixInfo.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="type"){Ex.Logger.Log("MixInfo.csv中字段[type]位置不对应"); return false; }
		if(vecLine[3]!="ytpe_name"){Ex.Logger.Log("MixInfo.csv中字段[ytpe_name]位置不对应"); return false; }
		if(vecLine[4]!="demand1"){Ex.Logger.Log("MixInfo.csv中字段[demand1]位置不对应"); return false; }
		if(vecLine[5]!="demand2"){Ex.Logger.Log("MixInfo.csv中字段[demand2]位置不对应"); return false; }
		if(vecLine[6]!="demand3"){Ex.Logger.Log("MixInfo.csv中字段[demand3]位置不对应"); return false; }
		if(vecLine[7]!="mix_cost"){Ex.Logger.Log("MixInfo.csv中字段[mix_cost]位置不对应"); return false; }
		if(vecLine[8]!="mix_probability"){Ex.Logger.Log("MixInfo.csv中字段[mix_probability]位置不对应"); return false; }
		if(vecLine[9]!="avoid_fail"){Ex.Logger.Log("MixInfo.csv中字段[avoid_fail]位置不对应"); return false; }
		if(vecLine[10]!="avoid_num"){Ex.Logger.Log("MixInfo.csv中字段[avoid_num]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			MixInfoElement member = new MixInfoElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.type=Convert.ToInt32(vecLine[2]);
			member.ytpe_name=Convert.ToInt32(vecLine[3]);
			member.demand1=vecLine[4];
			member.demand2=vecLine[5];
			member.demand3=vecLine[6];
			member.mix_cost=Convert.ToInt32(vecLine[7]);
			member.mix_probability=Convert.ToInt32(vecLine[8]);
			member.avoid_fail=Convert.ToInt32(vecLine[9]);
			member.avoid_num=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
