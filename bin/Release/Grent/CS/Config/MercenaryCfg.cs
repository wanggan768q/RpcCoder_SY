using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//佣兵配置配置数据类
public class MercenaryElement
{
	public int id;               	//佣兵id	主键
	public string comment;       	//注释	策划用
	public int name;             	//佣兵名称	显示用的名称
	public int desc;             	//佣兵描述	佣兵的功能和背景描述
	public string portrait;      	//佣兵立绘	界面内显示的图片
	public string prefab;        	//佣兵模型	调用的模型prefab
	public string class_icon;    	//佣兵职业	显示的职业图标
	public int profession;       	//佣兵职能	枚举，用来对应佣兵的能力 1.坦克 2.治疗 3.输出
	public int normal_skill_1;   	//普攻技能1	对应的技能ID
	public int normal_skill_2;   	//普攻技能2	对应的技能ID
	public int normal_skill_3;   	//普攻技能3	对应的技能ID
	public int profession_skill_1;	//职业技能1	对应的技能ID
	public int profession_skill_2;	//职业技能2	对应的技能ID
	public int profession_skill_3;	//职业技能3	对应的技能ID
	public int profession_skill_4;	//职业技能4	对应的技能ID
	public int combat_coe_id;    	//战斗属性id	对应了CreatureCombatCoe表内的条目 属性计算方式和怪物保持一致

	public bool IsValidate = false;
	public MercenaryElement()
	{
		id = -1;
	}
};

//佣兵配置配置封装类
public class MercenaryTable
{

	private MercenaryTable()
	{
		m_mapElements = new Dictionary<int, MercenaryElement>();
		m_emptyItem = new MercenaryElement();
		m_vecAllElements = new List<MercenaryElement>();
	}
	private Dictionary<int, MercenaryElement> m_mapElements = null;
	private List<MercenaryElement>	m_vecAllElements = null;
	private MercenaryElement m_emptyItem = null;
	private static MercenaryTable sInstance = null;

	public static MercenaryTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MercenaryTable();
			return sInstance;
		}
	}

	public MercenaryElement GetElement(int key)
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

  public List<MercenaryElement> GetAllElement(Predicate<MercenaryElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Mercenary.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Mercenary.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Mercenary.bin]未找到");
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
		if(vecLine.Count != 16)
		{
			Ex.Logger.Log("Mercenary.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mercenary.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mercenary.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Mercenary.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("Mercenary.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="portrait"){Ex.Logger.Log("Mercenary.csv中字段[portrait]位置不对应"); return false; }
		if(vecLine[5]!="prefab"){Ex.Logger.Log("Mercenary.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[6]!="class_icon"){Ex.Logger.Log("Mercenary.csv中字段[class_icon]位置不对应"); return false; }
		if(vecLine[7]!="profession"){Ex.Logger.Log("Mercenary.csv中字段[profession]位置不对应"); return false; }
		if(vecLine[8]!="normal_skill_1"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_1]位置不对应"); return false; }
		if(vecLine[9]!="normal_skill_2"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_2]位置不对应"); return false; }
		if(vecLine[10]!="normal_skill_3"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_3]位置不对应"); return false; }
		if(vecLine[11]!="profession_skill_1"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_1]位置不对应"); return false; }
		if(vecLine[12]!="profession_skill_2"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_2]位置不对应"); return false; }
		if(vecLine[13]!="profession_skill_3"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_3]位置不对应"); return false; }
		if(vecLine[14]!="profession_skill_4"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_4]位置不对应"); return false; }
		if(vecLine[15]!="combat_coe_id"){Ex.Logger.Log("Mercenary.csv中字段[combat_coe_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MercenaryElement member = new MercenaryElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.portrait);
			readPos += GameAssist.ReadString( binContent, readPos, out member.prefab);
			readPos += GameAssist.ReadString( binContent, readPos, out member.class_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.normal_skill_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.normal_skill_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.normal_skill_3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_skill_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_skill_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_skill_3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_skill_4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.combat_coe_id );

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
		if(vecLine.Count != 16)
		{
			Ex.Logger.Log("Mercenary.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Mercenary.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Mercenary.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("Mercenary.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("Mercenary.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="portrait"){Ex.Logger.Log("Mercenary.csv中字段[portrait]位置不对应"); return false; }
		if(vecLine[5]!="prefab"){Ex.Logger.Log("Mercenary.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[6]!="class_icon"){Ex.Logger.Log("Mercenary.csv中字段[class_icon]位置不对应"); return false; }
		if(vecLine[7]!="profession"){Ex.Logger.Log("Mercenary.csv中字段[profession]位置不对应"); return false; }
		if(vecLine[8]!="normal_skill_1"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_1]位置不对应"); return false; }
		if(vecLine[9]!="normal_skill_2"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_2]位置不对应"); return false; }
		if(vecLine[10]!="normal_skill_3"){Ex.Logger.Log("Mercenary.csv中字段[normal_skill_3]位置不对应"); return false; }
		if(vecLine[11]!="profession_skill_1"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_1]位置不对应"); return false; }
		if(vecLine[12]!="profession_skill_2"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_2]位置不对应"); return false; }
		if(vecLine[13]!="profession_skill_3"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_3]位置不对应"); return false; }
		if(vecLine[14]!="profession_skill_4"){Ex.Logger.Log("Mercenary.csv中字段[profession_skill_4]位置不对应"); return false; }
		if(vecLine[15]!="combat_coe_id"){Ex.Logger.Log("Mercenary.csv中字段[combat_coe_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			MercenaryElement member = new MercenaryElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.desc=Convert.ToInt32(vecLine[3]);
			member.portrait=vecLine[4];
			member.prefab=vecLine[5];
			member.class_icon=vecLine[6];
			member.profession=Convert.ToInt32(vecLine[7]);
			member.normal_skill_1=Convert.ToInt32(vecLine[8]);
			member.normal_skill_2=Convert.ToInt32(vecLine[9]);
			member.normal_skill_3=Convert.ToInt32(vecLine[10]);
			member.profession_skill_1=Convert.ToInt32(vecLine[11]);
			member.profession_skill_2=Convert.ToInt32(vecLine[12]);
			member.profession_skill_3=Convert.ToInt32(vecLine[13]);
			member.profession_skill_4=Convert.ToInt32(vecLine[14]);
			member.combat_coe_id=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
