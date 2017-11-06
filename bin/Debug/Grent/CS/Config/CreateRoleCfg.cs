using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色配置数据类
public class CreateRoleElement
{
	public int id;               	//id	id
	public int race;             	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	public li sex;               	//可选性别	1:男性 2:女性
	public int race_name;        	//种族名称	对应的名字的文本id
	public int race_description; 	//种族介绍	对应介绍的文本id
	public string race_icon;     	//种族图标	对应种族图标路径
	public int desc_occupations; 	//可用职业介绍	对应可选职业介绍的文本id
	public int default_gender;   	//默认性别	在玩家未选择性别时用于显示模型的字段
	public int default_male_model;	//默认显示男性模型	选择种族后显示的男性模型 萝莉族没有男性
	public int default_female_model;	//默认显示女性模型	选择种族后显示的女性模型 兽人族没有女性
	public int default_male_id;  	//默认男性角色id	确定种族后默认选择的男性职业
	public int default_female_id;	//默认女性角色id	确定种族后默认选择的女性职业
	public li male_role_id;      	//男性角色id1	如果没有男性则无用  对应该种族男性角色职业
	public li female_role_id;    	//女性角色id1	如果没有女性则无用  对应该种族女性角色职业

	public bool IsValidate = false;
	public CreateRoleElement()
	{
		id = -1;
	}
};

//角色配置封装类
public class CreateRoleTable
{

	private CreateRoleTable()
	{
		m_mapElements = new Dictionary<int, CreateRoleElement>();
		m_emptyItem = new CreateRoleElement();
		m_vecAllElements = new List<CreateRoleElement>();
	}
	private Dictionary<int, CreateRoleElement> m_mapElements = null;
	private List<CreateRoleElement>	m_vecAllElements = null;
	private CreateRoleElement m_emptyItem = null;
	private static CreateRoleTable sInstance = null;

	public static CreateRoleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreateRoleTable();
			return sInstance;
		}
	}

	public CreateRoleElement GetElement(int key)
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

  public List<CreateRoleElement> GetAllElement(Predicate<CreateRoleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreateRole.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreateRole.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreateRole.bin]未找到");
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
			Ex.Logger.Log("CreateRole.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreateRole.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="race"){Ex.Logger.Log("CreateRole.csv中字段[race]位置不对应"); return false; }
		if(vecLine[2]!="sex"){Ex.Logger.Log("CreateRole.csv中字段[sex]位置不对应"); return false; }
		if(vecLine[3]!="race_name"){Ex.Logger.Log("CreateRole.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[4]!="race_description"){Ex.Logger.Log("CreateRole.csv中字段[race_description]位置不对应"); return false; }
		if(vecLine[5]!="race_icon"){Ex.Logger.Log("CreateRole.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[6]!="desc_occupations"){Ex.Logger.Log("CreateRole.csv中字段[desc_occupations]位置不对应"); return false; }
		if(vecLine[7]!="default_gender"){Ex.Logger.Log("CreateRole.csv中字段[default_gender]位置不对应"); return false; }
		if(vecLine[8]!="default_male_model"){Ex.Logger.Log("CreateRole.csv中字段[default_male_model]位置不对应"); return false; }
		if(vecLine[9]!="default_female_model"){Ex.Logger.Log("CreateRole.csv中字段[default_female_model]位置不对应"); return false; }
		if(vecLine[10]!="default_male_id"){Ex.Logger.Log("CreateRole.csv中字段[default_male_id]位置不对应"); return false; }
		if(vecLine[11]!="default_female_id"){Ex.Logger.Log("CreateRole.csv中字段[default_female_id]位置不对应"); return false; }
		if(vecLine[12]!="male_role_id"){Ex.Logger.Log("CreateRole.csv中字段[male_role_id]位置不对应"); return false; }
		if(vecLine[13]!="female_role_id"){Ex.Logger.Log("CreateRole.csv中字段[female_role_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreateRoleElement member = new CreateRoleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadString( binContent, readPos, out member.sex);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.race_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc_occupations );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.default_gender );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.default_male_model );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.default_female_model );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.default_male_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.default_female_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.male_role_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.female_role_id);

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
			Ex.Logger.Log("CreateRole.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreateRole.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="race"){Ex.Logger.Log("CreateRole.csv中字段[race]位置不对应"); return false; }
		if(vecLine[2]!="sex"){Ex.Logger.Log("CreateRole.csv中字段[sex]位置不对应"); return false; }
		if(vecLine[3]!="race_name"){Ex.Logger.Log("CreateRole.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[4]!="race_description"){Ex.Logger.Log("CreateRole.csv中字段[race_description]位置不对应"); return false; }
		if(vecLine[5]!="race_icon"){Ex.Logger.Log("CreateRole.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[6]!="desc_occupations"){Ex.Logger.Log("CreateRole.csv中字段[desc_occupations]位置不对应"); return false; }
		if(vecLine[7]!="default_gender"){Ex.Logger.Log("CreateRole.csv中字段[default_gender]位置不对应"); return false; }
		if(vecLine[8]!="default_male_model"){Ex.Logger.Log("CreateRole.csv中字段[default_male_model]位置不对应"); return false; }
		if(vecLine[9]!="default_female_model"){Ex.Logger.Log("CreateRole.csv中字段[default_female_model]位置不对应"); return false; }
		if(vecLine[10]!="default_male_id"){Ex.Logger.Log("CreateRole.csv中字段[default_male_id]位置不对应"); return false; }
		if(vecLine[11]!="default_female_id"){Ex.Logger.Log("CreateRole.csv中字段[default_female_id]位置不对应"); return false; }
		if(vecLine[12]!="male_role_id"){Ex.Logger.Log("CreateRole.csv中字段[male_role_id]位置不对应"); return false; }
		if(vecLine[13]!="female_role_id"){Ex.Logger.Log("CreateRole.csv中字段[female_role_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			CreateRoleElement member = new CreateRoleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.race=Convert.ToInt32(vecLine[1]);
			member.sex=vecLine[2];
			member.race_name=Convert.ToInt32(vecLine[3]);
			member.race_description=Convert.ToInt32(vecLine[4]);
			member.race_icon=vecLine[5];
			member.desc_occupations=Convert.ToInt32(vecLine[6]);
			member.default_gender=Convert.ToInt32(vecLine[7]);
			member.default_male_model=Convert.ToInt32(vecLine[8]);
			member.default_female_model=Convert.ToInt32(vecLine[9]);
			member.default_male_id=Convert.ToInt32(vecLine[10]);
			member.default_female_id=Convert.ToInt32(vecLine[11]);
			member.male_role_id=vecLine[12];
			member.female_role_id=vecLine[13];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
