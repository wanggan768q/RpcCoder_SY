using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//专精表配置数据类
public class ProfessionElement
{
	public int id;               	//专精ID	1-防战2-狂战，3-敏锐贼4-战斗贼，5-射击猎6-生存猎，7-火法8-冰法，9-防骑10-奶骑，11-鸟德12-奶德，13-火法男14-冰法男，15-射击猎女16生存猎女。
	public int name;             	//显示名称	关联文本表ID
	public int des;              	//专精描述	关联文本表ID
	public int profession_config;	//专精职能	枚举 1.坦克 2.治疗 3.输出人数
	public int role_id;          	//角色ID	关联角色ID
	public ls icon;              	//图标资源	
	public int skill_normal;     	//普攻技能ID	关联技能表
	public li skill_id;          	//默认技能ID	
	public int roll_skill_id;    	//翻滚技能ID	
	public int order;            	//显示位置	0：左（同时会被设置为职业默认专精） 1：右
	public int lv;               	//解锁级别	
	public li add_buff;          	//添加buff	关联Buff表

	public bool IsValidate = false;
	public ProfessionElement()
	{
		id = -1;
	}
};

//专精表配置封装类
public class ProfessionTable
{

	private ProfessionTable()
	{
		m_mapElements = new Dictionary<int, ProfessionElement>();
		m_emptyItem = new ProfessionElement();
		m_vecAllElements = new List<ProfessionElement>();
	}
	private Dictionary<int, ProfessionElement> m_mapElements = null;
	private List<ProfessionElement>	m_vecAllElements = null;
	private ProfessionElement m_emptyItem = null;
	private static ProfessionTable sInstance = null;

	public static ProfessionTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ProfessionTable();
			return sInstance;
		}
	}

	public ProfessionElement GetElement(int key)
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

  public List<ProfessionElement> GetAllElement(Predicate<ProfessionElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Profession.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Profession.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Profession.bin]未找到");
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
			Ex.Logger.Log("Profession.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Profession.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Profession.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="des"){Ex.Logger.Log("Profession.csv中字段[des]位置不对应"); return false; }
		if(vecLine[3]!="profession_config"){Ex.Logger.Log("Profession.csv中字段[profession_config]位置不对应"); return false; }
		if(vecLine[4]!="role_id"){Ex.Logger.Log("Profession.csv中字段[role_id]位置不对应"); return false; }
		if(vecLine[5]!="icon"){Ex.Logger.Log("Profession.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[6]!="skill_normal"){Ex.Logger.Log("Profession.csv中字段[skill_normal]位置不对应"); return false; }
		if(vecLine[7]!="skill_id"){Ex.Logger.Log("Profession.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[8]!="roll_skill_id"){Ex.Logger.Log("Profession.csv中字段[roll_skill_id]位置不对应"); return false; }
		if(vecLine[9]!="order"){Ex.Logger.Log("Profession.csv中字段[order]位置不对应"); return false; }
		if(vecLine[10]!="lv"){Ex.Logger.Log("Profession.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[11]!="add_buff"){Ex.Logger.Log("Profession.csv中字段[add_buff]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ProfessionElement member = new ProfessionElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.des );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.profession_config );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.role_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_normal );
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.roll_skill_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.lv );
			readPos += GameAssist.ReadString( binContent, readPos, out member.add_buff);

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
			Ex.Logger.Log("Profession.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Profession.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Profession.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="des"){Ex.Logger.Log("Profession.csv中字段[des]位置不对应"); return false; }
		if(vecLine[3]!="profession_config"){Ex.Logger.Log("Profession.csv中字段[profession_config]位置不对应"); return false; }
		if(vecLine[4]!="role_id"){Ex.Logger.Log("Profession.csv中字段[role_id]位置不对应"); return false; }
		if(vecLine[5]!="icon"){Ex.Logger.Log("Profession.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[6]!="skill_normal"){Ex.Logger.Log("Profession.csv中字段[skill_normal]位置不对应"); return false; }
		if(vecLine[7]!="skill_id"){Ex.Logger.Log("Profession.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[8]!="roll_skill_id"){Ex.Logger.Log("Profession.csv中字段[roll_skill_id]位置不对应"); return false; }
		if(vecLine[9]!="order"){Ex.Logger.Log("Profession.csv中字段[order]位置不对应"); return false; }
		if(vecLine[10]!="lv"){Ex.Logger.Log("Profession.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[11]!="add_buff"){Ex.Logger.Log("Profession.csv中字段[add_buff]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			ProfessionElement member = new ProfessionElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=Convert.ToInt32(vecLine[1]);
			member.des=Convert.ToInt32(vecLine[2]);
			member.profession_config=Convert.ToInt32(vecLine[3]);
			member.role_id=Convert.ToInt32(vecLine[4]);
			member.icon=vecLine[5];
			member.skill_normal=Convert.ToInt32(vecLine[6]);
			member.skill_id=vecLine[7];
			member.roll_skill_id=Convert.ToInt32(vecLine[8]);
			member.order=Convert.ToInt32(vecLine[9]);
			member.lv=Convert.ToInt32(vecLine[10]);
			member.add_buff=vecLine[11];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
