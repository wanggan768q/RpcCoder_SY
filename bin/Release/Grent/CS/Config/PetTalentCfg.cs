using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物资质表配置数据类
public class PetTalentElement
{
	public int id;               	//宠物资质id	宠物资质区间id
	public string comment;       	//注释	策划用
	public int talent_1;         	//宠物资质1	对应资质表中的id 生命
	public li talent_1_value;    	//宠物资质1值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	public int talent_2;         	//宠物资质2	对应资质表中的id 攻击
	public li talent_2_value;    	//宠物资质2值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	public int talent_3;         	//宠物资质3	对应资质表中的id 防御
	public li talent_3_value;    	//宠物资质3值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	public int talent_4;         	//宠物资质4	对应资质表中的id 爆发
	public li talent_4_value;    	//宠物资质4值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限
	public int talent_5;         	//宠物资质5	对应资质表中的id 忍耐
	public li talent_5_value;    	//宠物资质5值	数组，分别对应 随机最小值| 随机最大值| 宠物资质底线| 宠物资质上限

	public bool IsValidate = false;
	public PetTalentElement()
	{
		id = -1;
	}
};

//宠物资质表配置封装类
public class PetTalentTable
{

	private PetTalentTable()
	{
		m_mapElements = new Dictionary<int, PetTalentElement>();
		m_emptyItem = new PetTalentElement();
		m_vecAllElements = new List<PetTalentElement>();
	}
	private Dictionary<int, PetTalentElement> m_mapElements = null;
	private List<PetTalentElement>	m_vecAllElements = null;
	private PetTalentElement m_emptyItem = null;
	private static PetTalentTable sInstance = null;

	public static PetTalentTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetTalentTable();
			return sInstance;
		}
	}

	public PetTalentElement GetElement(int key)
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

  public List<PetTalentElement> GetAllElement(Predicate<PetTalentElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetTalent.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetTalent.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetTalent.bin]未找到");
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
			Ex.Logger.Log("PetTalent.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetTalent.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetTalent.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="talent_1"){Ex.Logger.Log("PetTalent.csv中字段[talent_1]位置不对应"); return false; }
		if(vecLine[3]!="talent_1_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_1_value]位置不对应"); return false; }
		if(vecLine[4]!="talent_2"){Ex.Logger.Log("PetTalent.csv中字段[talent_2]位置不对应"); return false; }
		if(vecLine[5]!="talent_2_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_2_value]位置不对应"); return false; }
		if(vecLine[6]!="talent_3"){Ex.Logger.Log("PetTalent.csv中字段[talent_3]位置不对应"); return false; }
		if(vecLine[7]!="talent_3_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_3_value]位置不对应"); return false; }
		if(vecLine[8]!="talent_4"){Ex.Logger.Log("PetTalent.csv中字段[talent_4]位置不对应"); return false; }
		if(vecLine[9]!="talent_4_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_4_value]位置不对应"); return false; }
		if(vecLine[10]!="talent_5"){Ex.Logger.Log("PetTalent.csv中字段[talent_5]位置不对应"); return false; }
		if(vecLine[11]!="talent_5_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_5_value]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetTalentElement member = new PetTalentElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_1_value);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_2_value);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_3_value);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_4 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_4_value);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_5 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_5_value);

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
			Ex.Logger.Log("PetTalent.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetTalent.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetTalent.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="talent_1"){Ex.Logger.Log("PetTalent.csv中字段[talent_1]位置不对应"); return false; }
		if(vecLine[3]!="talent_1_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_1_value]位置不对应"); return false; }
		if(vecLine[4]!="talent_2"){Ex.Logger.Log("PetTalent.csv中字段[talent_2]位置不对应"); return false; }
		if(vecLine[5]!="talent_2_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_2_value]位置不对应"); return false; }
		if(vecLine[6]!="talent_3"){Ex.Logger.Log("PetTalent.csv中字段[talent_3]位置不对应"); return false; }
		if(vecLine[7]!="talent_3_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_3_value]位置不对应"); return false; }
		if(vecLine[8]!="talent_4"){Ex.Logger.Log("PetTalent.csv中字段[talent_4]位置不对应"); return false; }
		if(vecLine[9]!="talent_4_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_4_value]位置不对应"); return false; }
		if(vecLine[10]!="talent_5"){Ex.Logger.Log("PetTalent.csv中字段[talent_5]位置不对应"); return false; }
		if(vecLine[11]!="talent_5_value"){Ex.Logger.Log("PetTalent.csv中字段[talent_5_value]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			PetTalentElement member = new PetTalentElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.talent_1=Convert.ToInt32(vecLine[2]);
			member.talent_1_value=vecLine[3];
			member.talent_2=Convert.ToInt32(vecLine[4]);
			member.talent_2_value=vecLine[5];
			member.talent_3=Convert.ToInt32(vecLine[6]);
			member.talent_3_value=vecLine[7];
			member.talent_4=Convert.ToInt32(vecLine[8]);
			member.talent_4_value=vecLine[9];
			member.talent_5=Convert.ToInt32(vecLine[10]);
			member.talent_5_value=vecLine[11];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
