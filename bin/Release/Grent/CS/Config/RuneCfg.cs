using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//铭文表配置数据类
public class RuneElement
{
	public int id;               	//铭文ID	
	public int name;             	//显示名称	关联stringskill文本表的ID
	public int zj_id;            	//专精ID1	关联专精ID-1
	public int zj_id_2;          	//专精ID2	关联专精ID-2
	public int skill_id;         	//技能ID	关联技能D
	public int desc;             	//文本表ID	StringSkill_技能文本表
	public string icon;          	//图标资源	铭文图标，以后主界面技能图标用此列数据
	public string rune_icon;     	//图标资源	铭文图标，以后铭文界面显示的图标用此列的配置
	public string skill_frame;   	//技能图标边框	主界面技能图标的边框
	public int leftOrder;        	//左侧技能位置	
	public int rightOrder;       	//铭文位置	
	public int lv;               	//解锁级别	
	public int unlock_animation; 	//是否显示技能解锁动画	0不显示，1显示
	public string showResources; 	//表现动作资源	
	public string targetModel;   	//被击模型	
	public float targetDistance; 	//被击者距离	

	public bool IsValidate = false;
	public RuneElement()
	{
		id = -1;
	}
};

//铭文表配置封装类
public class RuneTable
{

	private RuneTable()
	{
		m_mapElements = new Dictionary<int, RuneElement>();
		m_emptyItem = new RuneElement();
		m_vecAllElements = new List<RuneElement>();
	}
	private Dictionary<int, RuneElement> m_mapElements = null;
	private List<RuneElement>	m_vecAllElements = null;
	private RuneElement m_emptyItem = null;
	private static RuneTable sInstance = null;

	public static RuneTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RuneTable();
			return sInstance;
		}
	}

	public RuneElement GetElement(int key)
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

  public List<RuneElement> GetAllElement(Predicate<RuneElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Rune.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Rune.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Rune.bin]未找到");
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
			Ex.Logger.Log("Rune.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Rune.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Rune.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="zj_id"){Ex.Logger.Log("Rune.csv中字段[zj_id]位置不对应"); return false; }
		if(vecLine[3]!="zj_id_2"){Ex.Logger.Log("Rune.csv中字段[zj_id_2]位置不对应"); return false; }
		if(vecLine[4]!="skill_id"){Ex.Logger.Log("Rune.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[5]!="desc"){Ex.Logger.Log("Rune.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("Rune.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="rune_icon"){Ex.Logger.Log("Rune.csv中字段[rune_icon]位置不对应"); return false; }
		if(vecLine[8]!="skill_frame"){Ex.Logger.Log("Rune.csv中字段[skill_frame]位置不对应"); return false; }
		if(vecLine[9]!="leftOrder"){Ex.Logger.Log("Rune.csv中字段[leftOrder]位置不对应"); return false; }
		if(vecLine[10]!="rightOrder"){Ex.Logger.Log("Rune.csv中字段[rightOrder]位置不对应"); return false; }
		if(vecLine[11]!="lv"){Ex.Logger.Log("Rune.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[12]!="unlock_animation"){Ex.Logger.Log("Rune.csv中字段[unlock_animation]位置不对应"); return false; }
		if(vecLine[13]!="showResources"){Ex.Logger.Log("Rune.csv中字段[showResources]位置不对应"); return false; }
		if(vecLine[14]!="targetModel"){Ex.Logger.Log("Rune.csv中字段[targetModel]位置不对应"); return false; }
		if(vecLine[15]!="targetDistance"){Ex.Logger.Log("Rune.csv中字段[targetDistance]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RuneElement member = new RuneElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.zj_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.zj_id_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rune_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.skill_frame);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leftOrder );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rightOrder );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_animation );
			readPos += GameAssist.ReadString( binContent, readPos, out member.showResources);
			readPos += GameAssist.ReadString( binContent, readPos, out member.targetModel);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.targetDistance);

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
			Ex.Logger.Log("Rune.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Rune.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Rune.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="zj_id"){Ex.Logger.Log("Rune.csv中字段[zj_id]位置不对应"); return false; }
		if(vecLine[3]!="zj_id_2"){Ex.Logger.Log("Rune.csv中字段[zj_id_2]位置不对应"); return false; }
		if(vecLine[4]!="skill_id"){Ex.Logger.Log("Rune.csv中字段[skill_id]位置不对应"); return false; }
		if(vecLine[5]!="desc"){Ex.Logger.Log("Rune.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("Rune.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="rune_icon"){Ex.Logger.Log("Rune.csv中字段[rune_icon]位置不对应"); return false; }
		if(vecLine[8]!="skill_frame"){Ex.Logger.Log("Rune.csv中字段[skill_frame]位置不对应"); return false; }
		if(vecLine[9]!="leftOrder"){Ex.Logger.Log("Rune.csv中字段[leftOrder]位置不对应"); return false; }
		if(vecLine[10]!="rightOrder"){Ex.Logger.Log("Rune.csv中字段[rightOrder]位置不对应"); return false; }
		if(vecLine[11]!="lv"){Ex.Logger.Log("Rune.csv中字段[lv]位置不对应"); return false; }
		if(vecLine[12]!="unlock_animation"){Ex.Logger.Log("Rune.csv中字段[unlock_animation]位置不对应"); return false; }
		if(vecLine[13]!="showResources"){Ex.Logger.Log("Rune.csv中字段[showResources]位置不对应"); return false; }
		if(vecLine[14]!="targetModel"){Ex.Logger.Log("Rune.csv中字段[targetModel]位置不对应"); return false; }
		if(vecLine[15]!="targetDistance"){Ex.Logger.Log("Rune.csv中字段[targetDistance]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			RuneElement member = new RuneElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=Convert.ToInt32(vecLine[1]);
			member.zj_id=Convert.ToInt32(vecLine[2]);
			member.zj_id_2=Convert.ToInt32(vecLine[3]);
			member.skill_id=Convert.ToInt32(vecLine[4]);
			member.desc=Convert.ToInt32(vecLine[5]);
			member.icon=vecLine[6];
			member.rune_icon=vecLine[7];
			member.skill_frame=vecLine[8];
			member.leftOrder=Convert.ToInt32(vecLine[9]);
			member.rightOrder=Convert.ToInt32(vecLine[10]);
			member.lv=Convert.ToInt32(vecLine[11]);
			member.unlock_animation=Convert.ToInt32(vecLine[12]);
			member.showResources=vecLine[13];
			member.targetModel=vecLine[14];
			member.targetDistance=Convert.ToSingle(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
