using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物技能表配置数据类
public class PetSkillElement
{
	public int id;               	//宠物技能id	填写ID即可
	public string comment;       	//注释	策划用
	public int name;             	//技能名称	对应显示在界面升的名称  StringSkill_技能文本表
	public int desc;             	//技能描述	对应显示在界面上的表述文本 StringSkill_技能文本表
	public string icon;          	//技能图标	对应显示在界面上的图标  可以和道具的图标一致
	public int power;            	//技能战力	该技能书所提供的战力加成
	public int skill_id;         	//技能id	该技能对应的buffid
	public int skill_group;      	//技能组	用来区分哪些技能是属于同一个类型
	public int skill_level;      	//技能等级	技能的等级
	public int attr_id;          	//属性id	该技能添加的属性id 对应AttributeFormatConfig表的id 不填则表示没有该效果
	public lf attr_value;        	//属性值	该技能为宠物添加的属性具体值 百分比|值 如果attr_id字段不填则没有效果
	public int attack_id;        	//技能效果id	该技能会给角色添加的光环，对应attack表的id 不填则表示没有该效果
	public int buff_id;          	//添加buff	该技能添加的buff 对应buff标的id 不填则表示没有该效果
	public int item_proto;       	//对应道具	用来区分哪些技能是属于同一个类型

	public bool IsValidate = false;
	public PetSkillElement()
	{
		id = -1;
	}
};

//宠物技能表配置封装类
public class PetSkillTable
{

	private PetSkillTable()
	{
		m_mapElements = new Dictionary<int, PetSkillElement>();
		m_emptyItem = new PetSkillElement();
		m_vecAllElements = new List<PetSkillElement>();
	}
	private Dictionary<int, PetSkillElement> m_mapElements = null;
	private List<PetSkillElement>	m_vecAllElements = null;
	private PetSkillElement m_emptyItem = null;
	private static PetSkillTable sInstance = null;

	public static PetSkillTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetSkillTable();
			return sInstance;
		}
	}

	public PetSkillElement GetElement(int key)
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

  public List<PetSkillElement> GetAllElement(Predicate<PetSkillElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetSkill.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetSkill.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetSkill.bin]未找到");
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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("PetSkill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetSkill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetSkill.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetSkill.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("PetSkill.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("PetSkill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="power"){Ex.Logger.Log("PetSkill.csv中字段[power]位置不对应"); return false; }
		if(vecLine[6]!="skill_id"){Ex.Logger.Log("PetSkill.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[7]!="skill_group"){Ex.Logger.Log("PetSkill.csv中字段[skill_group]位置不对应"); return false; }
		if(vecLine[8]!="skill_level"){Ex.Logger.Log("PetSkill.csv中字段[skill_level]位置不对应"); return false; }
		if(vecLine[9]!="attr_id"){Ex.Logger.Log("PetSkill.csv中字段[attr_id]位置不对应"); return false; }
		if(vecLine[10]!="attr_value"){Ex.Logger.Log("PetSkill.csv中字段[attr_value]位置不对应"); return false; }
		if(vecLine[11]!="attack_id"){Ex.Logger.Log("PetSkill.csv中字段[attack_id]位置不对应"); return false; }
		if(vecLine[12]!="buff_id"){Ex.Logger.Log("PetSkill.csv中字段[buff_id]位置不对应"); return false; }
		if(vecLine[13]!="item_proto"){Ex.Logger.Log("PetSkill.csv中字段[item_proto]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetSkillElement member = new PetSkillElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.power );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_group );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attr_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.attr_value);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.item_proto );

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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("PetSkill.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetSkill.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetSkill.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetSkill.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("PetSkill.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="icon"){Ex.Logger.Log("PetSkill.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[5]!="power"){Ex.Logger.Log("PetSkill.csv中字段[power]位置不对应"); return false; }
		if(vecLine[6]!="skill_id"){Ex.Logger.Log("PetSkill.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[7]!="skill_group"){Ex.Logger.Log("PetSkill.csv中字段[skill_group]位置不对应"); return false; }
		if(vecLine[8]!="skill_level"){Ex.Logger.Log("PetSkill.csv中字段[skill_level]位置不对应"); return false; }
		if(vecLine[9]!="attr_id"){Ex.Logger.Log("PetSkill.csv中字段[attr_id]位置不对应"); return false; }
		if(vecLine[10]!="attr_value"){Ex.Logger.Log("PetSkill.csv中字段[attr_value]位置不对应"); return false; }
		if(vecLine[11]!="attack_id"){Ex.Logger.Log("PetSkill.csv中字段[attack_id]位置不对应"); return false; }
		if(vecLine[12]!="buff_id"){Ex.Logger.Log("PetSkill.csv中字段[buff_id]位置不对应"); return false; }
		if(vecLine[13]!="item_proto"){Ex.Logger.Log("PetSkill.csv中字段[item_proto]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			PetSkillElement member = new PetSkillElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.desc=Convert.ToInt32(vecLine[3]);
			member.icon=vecLine[4];
			member.power=Convert.ToInt32(vecLine[5]);
			member.skill_id=Convert.ToInt32(vecLine[6]);
			member.skill_group=Convert.ToInt32(vecLine[7]);
			member.skill_level=Convert.ToInt32(vecLine[8]);
			member.attr_id=Convert.ToInt32(vecLine[9]);
			member.attr_value=vecLine[10];
			member.attack_id=Convert.ToInt32(vecLine[11]);
			member.buff_id=Convert.ToInt32(vecLine[12]);
			member.item_proto=Convert.ToInt32(vecLine[13]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
