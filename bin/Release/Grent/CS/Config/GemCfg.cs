using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝石表配置数据类
public class GemElement
{
	public int id;               	//宝石ID	填写ID即可
	public string comment;       	//注释	策划用
	public int gem_type;         	//填写宝石大类名	填写文本ID
	public int gem_level;        	//该宝石等级	填写宝石等级
	public int gem_num;          	//需要前1级多少个宝石	填写数量
	public int gem_quick;        	//需要多少个1级宝石	填写数量
	public int probability;      	//合成该宝石成功率	填写10即10%概率
	public int gem_item_id;      	//保底道具ID	填写道具ID
	public int gem_item_num;     	//是否需要保底道具	不需要写0，需要写数量
	public int gem_loss;         	//不用保底道具合成失败扣除该宝石数量	填写0不扣除，填写1，失败扣1个
	public string gem_mark;      	//宝石标示	在界面中显示的标示图案
	public int part1;            	//可镶嵌部位1	填写部位ID
	public li property1;         	//属性1	填写属性ID
	public li value1;            	//数值1	填写增加数值
	public int part2;            	//可镶嵌部位2	填写部位ID
	public li property2;         	//属性2	填写属性ID
	public li value2;            	//数值2	填写增加数值

	public bool IsValidate = false;
	public GemElement()
	{
		id = -1;
	}
};

//宝石表配置封装类
public class GemTable
{

	private GemTable()
	{
		m_mapElements = new Dictionary<int, GemElement>();
		m_emptyItem = new GemElement();
		m_vecAllElements = new List<GemElement>();
	}
	private Dictionary<int, GemElement> m_mapElements = null;
	private List<GemElement>	m_vecAllElements = null;
	private GemElement m_emptyItem = null;
	private static GemTable sInstance = null;

	public static GemTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new GemTable();
			return sInstance;
		}
	}

	public GemElement GetElement(int key)
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

  public List<GemElement> GetAllElement(Predicate<GemElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Gem.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Gem.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Gem.bin]未找到");
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
		if(vecLine.Count != 17)
		{
			Ex.Logger.Log("Gem.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Gem.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Gem.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="gem_type"){Ex.Logger.Log("Gem.csv中字段[gem_type]位置不对应"); return false; }
		if(vecLine[3]!="gem_level"){Ex.Logger.Log("Gem.csv中字段[gem_level]位置不对应"); return false; }
		if(vecLine[4]!="gem_num"){Ex.Logger.Log("Gem.csv中字段[gem_num]位置不对应"); return false; }
		if(vecLine[5]!="gem_quick"){Ex.Logger.Log("Gem.csv中字段[gem_quick]位置不对应"); return false; }
		if(vecLine[6]!="probability"){Ex.Logger.Log("Gem.csv中字段[probability]位置不对应"); return false; }
		if(vecLine[7]!="gem_item_id"){Ex.Logger.Log("Gem.csv中字段[gem_item_id]位置不对应"); return false; }
		if(vecLine[8]!="gem_item_num"){Ex.Logger.Log("Gem.csv中字段[gem_item_num]位置不对应"); return false; }
		if(vecLine[9]!="gem_loss"){Ex.Logger.Log("Gem.csv中字段[gem_loss]位置不对应"); return false; }
		if(vecLine[10]!="gem_mark"){Ex.Logger.Log("Gem.csv中字段[gem_mark]位置不对应"); return false; }
		if(vecLine[11]!="part1"){Ex.Logger.Log("Gem.csv中字段[part1]位置不对应"); return false; }
		if(vecLine[12]!="property1"){Ex.Logger.Log("Gem.csv中字段[property1]位置不对应"); return false; }
		if(vecLine[13]!="value1"){Ex.Logger.Log("Gem.csv中字段[value1]位置不对应"); return false; }
		if(vecLine[14]!="part2"){Ex.Logger.Log("Gem.csv中字段[part2]位置不对应"); return false; }
		if(vecLine[15]!="property2"){Ex.Logger.Log("Gem.csv中字段[property2]位置不对应"); return false; }
		if(vecLine[16]!="value2"){Ex.Logger.Log("Gem.csv中字段[value2]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			GemElement member = new GemElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_quick );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.probability );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_item_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_item_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gem_loss );
			readPos += GameAssist.ReadString( binContent, readPos, out member.gem_mark);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.property1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.value1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.part2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.property2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.value2);

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
		if(vecLine.Count != 17)
		{
			Ex.Logger.Log("Gem.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Gem.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Gem.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="gem_type"){Ex.Logger.Log("Gem.csv中字段[gem_type]位置不对应"); return false; }
		if(vecLine[3]!="gem_level"){Ex.Logger.Log("Gem.csv中字段[gem_level]位置不对应"); return false; }
		if(vecLine[4]!="gem_num"){Ex.Logger.Log("Gem.csv中字段[gem_num]位置不对应"); return false; }
		if(vecLine[5]!="gem_quick"){Ex.Logger.Log("Gem.csv中字段[gem_quick]位置不对应"); return false; }
		if(vecLine[6]!="probability"){Ex.Logger.Log("Gem.csv中字段[probability]位置不对应"); return false; }
		if(vecLine[7]!="gem_item_id"){Ex.Logger.Log("Gem.csv中字段[gem_item_id]位置不对应"); return false; }
		if(vecLine[8]!="gem_item_num"){Ex.Logger.Log("Gem.csv中字段[gem_item_num]位置不对应"); return false; }
		if(vecLine[9]!="gem_loss"){Ex.Logger.Log("Gem.csv中字段[gem_loss]位置不对应"); return false; }
		if(vecLine[10]!="gem_mark"){Ex.Logger.Log("Gem.csv中字段[gem_mark]位置不对应"); return false; }
		if(vecLine[11]!="part1"){Ex.Logger.Log("Gem.csv中字段[part1]位置不对应"); return false; }
		if(vecLine[12]!="property1"){Ex.Logger.Log("Gem.csv中字段[property1]位置不对应"); return false; }
		if(vecLine[13]!="value1"){Ex.Logger.Log("Gem.csv中字段[value1]位置不对应"); return false; }
		if(vecLine[14]!="part2"){Ex.Logger.Log("Gem.csv中字段[part2]位置不对应"); return false; }
		if(vecLine[15]!="property2"){Ex.Logger.Log("Gem.csv中字段[property2]位置不对应"); return false; }
		if(vecLine[16]!="value2"){Ex.Logger.Log("Gem.csv中字段[value2]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)17)
			{
				return false;
			}
			GemElement member = new GemElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.gem_type=Convert.ToInt32(vecLine[2]);
			member.gem_level=Convert.ToInt32(vecLine[3]);
			member.gem_num=Convert.ToInt32(vecLine[4]);
			member.gem_quick=Convert.ToInt32(vecLine[5]);
			member.probability=Convert.ToInt32(vecLine[6]);
			member.gem_item_id=Convert.ToInt32(vecLine[7]);
			member.gem_item_num=Convert.ToInt32(vecLine[8]);
			member.gem_loss=Convert.ToInt32(vecLine[9]);
			member.gem_mark=vecLine[10];
			member.part1=Convert.ToInt32(vecLine[11]);
			member.property1=vecLine[12];
			member.value1=vecLine[13];
			member.part2=Convert.ToInt32(vecLine[14]);
			member.property2=vecLine[15];
			member.value2=vecLine[16];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
