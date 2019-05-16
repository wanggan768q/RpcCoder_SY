using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//表情动作表配置数据类
public class ExpressionActionElement
{
	public int id;               	//表情ID	表情所对应的ID
	public string comment;       	//备注	仅策划用
	public int role_sort;        	//角色分类	对应role表中的角色分类  该ID由种族、职业、性别组成
	public string action_resource;	//动作资源	表情对应动作资源的文件名
	public int skill_id;         	//技能id	表情对应技能的ID
	public int expression_sort;  	//表情分类	表情对应的分类 1：基础 2：嘲讽 3：特殊
	public int name_text;        	//名称文本	对应string_ui表中的ID
	public int description_text; 	//描述文本	对应string_ui表中的ID
	public li unlock_condition;  	//解锁条件	 条件类型|条件内容  条件类型 1：外显 2：成就

	public bool IsValidate = false;
	public ExpressionActionElement()
	{
		id = -1;
	}
};

//表情动作表配置封装类
public class ExpressionActionTable
{

	private ExpressionActionTable()
	{
		m_mapElements = new Dictionary<int, ExpressionActionElement>();
		m_emptyItem = new ExpressionActionElement();
		m_vecAllElements = new List<ExpressionActionElement>();
	}
	private Dictionary<int, ExpressionActionElement> m_mapElements = null;
	private List<ExpressionActionElement>	m_vecAllElements = null;
	private ExpressionActionElement m_emptyItem = null;
	private static ExpressionActionTable sInstance = null;

	public static ExpressionActionTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ExpressionActionTable();
			return sInstance;
		}
	}

	public ExpressionActionElement GetElement(int key)
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

  public List<ExpressionActionElement> GetAllElement(Predicate<ExpressionActionElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("ExpressionAction.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("ExpressionAction.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[ExpressionAction.bin]未找到");
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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("ExpressionAction.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ExpressionAction.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ExpressionAction.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="role_sort"){Ex.Logger.Log("ExpressionAction.csv中字段[role_sort]位置不对应"); return false; }
		if(vecLine[3]!="action_resource"){Ex.Logger.Log("ExpressionAction.csv中字段[action_resource]位置不对应"); return false; }
		if(vecLine[4]!="skill_id"){Ex.Logger.Log("ExpressionAction.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[5]!="expression_sort"){Ex.Logger.Log("ExpressionAction.csv中字段[expression_sort]位置不对应"); return false; }
		if(vecLine[6]!="name_text"){Ex.Logger.Log("ExpressionAction.csv中字段[name_text]位置不对应"); return false; }
		if(vecLine[7]!="description_text"){Ex.Logger.Log("ExpressionAction.csv中字段[description_text]位置不对应"); return false; }
		if(vecLine[8]!="unlock_condition"){Ex.Logger.Log("ExpressionAction.csv中字段[unlock_condition]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ExpressionActionElement member = new ExpressionActionElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.role_sort );
			readPos += GameAssist.ReadString( binContent, readPos, out member.action_resource);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.expression_sort );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_text );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description_text );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_condition);

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
		if(vecLine.Count != 9)
		{
			Ex.Logger.Log("ExpressionAction.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("ExpressionAction.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("ExpressionAction.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="role_sort"){Ex.Logger.Log("ExpressionAction.csv中字段[role_sort]位置不对应"); return false; }
		if(vecLine[3]!="action_resource"){Ex.Logger.Log("ExpressionAction.csv中字段[action_resource]位置不对应"); return false; }
		if(vecLine[4]!="skill_id"){Ex.Logger.Log("ExpressionAction.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[5]!="expression_sort"){Ex.Logger.Log("ExpressionAction.csv中字段[expression_sort]位置不对应"); return false; }
		if(vecLine[6]!="name_text"){Ex.Logger.Log("ExpressionAction.csv中字段[name_text]位置不对应"); return false; }
		if(vecLine[7]!="description_text"){Ex.Logger.Log("ExpressionAction.csv中字段[description_text]位置不对应"); return false; }
		if(vecLine[8]!="unlock_condition"){Ex.Logger.Log("ExpressionAction.csv中字段[unlock_condition]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)9)
			{
				return false;
			}
			ExpressionActionElement member = new ExpressionActionElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.role_sort=Convert.ToInt32(vecLine[2]);
			member.action_resource=vecLine[3];
			member.skill_id=Convert.ToInt32(vecLine[4]);
			member.expression_sort=Convert.ToInt32(vecLine[5]);
			member.name_text=Convert.ToInt32(vecLine[6]);
			member.description_text=Convert.ToInt32(vecLine[7]);
			member.unlock_condition=vecLine[8];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
