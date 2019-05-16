using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//打造配置表配置数据类
public class EquipBuildElement
{
	public int id;               	//配方ID	每个配方所对应的ID值
	public string comment;       	//注释	策划用
	public string formula_picture;	//配方图片	配方图标的图片资源
	public int build_cost;       	//消耗货币	打造所消耗的货币数量
	public li material1;         	//消耗材料1	打造所消耗的材料道具ID|消耗数量
	public li material2;         	//消耗材料2	打造所消耗的材料道具ID|消耗数量
	public int add_artifact;     	//增加神器值	每次打造增加的神器值
	public int build_info;       	//打造装备信息	进行打造时的掉落包ID
	public int assign_info;      	//指定装备信息	神器值已满时打造必定出现的掉落包ID
	public li preview_infolist1; 	//预览信息1	打造可能出现的装备道具ID
	public int preview_infolist2;	//预览信息2	神器值满可能出现的装备ID

	public bool IsValidate = false;
	public EquipBuildElement()
	{
		id = -1;
	}
};

//打造配置表配置封装类
public class EquipBuildTable
{

	private EquipBuildTable()
	{
		m_mapElements = new Dictionary<int, EquipBuildElement>();
		m_emptyItem = new EquipBuildElement();
		m_vecAllElements = new List<EquipBuildElement>();
	}
	private Dictionary<int, EquipBuildElement> m_mapElements = null;
	private List<EquipBuildElement>	m_vecAllElements = null;
	private EquipBuildElement m_emptyItem = null;
	private static EquipBuildTable sInstance = null;

	public static EquipBuildTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EquipBuildTable();
			return sInstance;
		}
	}

	public EquipBuildElement GetElement(int key)
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

  public List<EquipBuildElement> GetAllElement(Predicate<EquipBuildElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EquipBuild.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EquipBuild.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EquipBuild.bin]未找到");
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
			Ex.Logger.Log("EquipBuild.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipBuild.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipBuild.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="formula_picture"){Ex.Logger.Log("EquipBuild.csv中字段[formula_picture]位置不对应"); return false; }
		if(vecLine[3]!="build_cost"){Ex.Logger.Log("EquipBuild.csv中字段[build_cost]位置不对应"); return false; }
		if(vecLine[4]!="material1"){Ex.Logger.Log("EquipBuild.csv中字段[material1]位置不对应"); return false; }
		if(vecLine[5]!="material2"){Ex.Logger.Log("EquipBuild.csv中字段[material2]位置不对应"); return false; }
		if(vecLine[6]!="add_artifact"){Ex.Logger.Log("EquipBuild.csv中字段[add_artifact]位置不对应"); return false; }
		if(vecLine[7]!="build_info"){Ex.Logger.Log("EquipBuild.csv中字段[build_info]位置不对应"); return false; }
		if(vecLine[8]!="assign_info"){Ex.Logger.Log("EquipBuild.csv中字段[assign_info]位置不对应"); return false; }
		if(vecLine[9]!="preview_infolist1"){Ex.Logger.Log("EquipBuild.csv中字段[preview_infolist1]位置不对应"); return false; }
		if(vecLine[10]!="preview_infolist2"){Ex.Logger.Log("EquipBuild.csv中字段[preview_infolist2]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EquipBuildElement member = new EquipBuildElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.formula_picture);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.build_cost );
			readPos += GameAssist.ReadString( binContent, readPos, out member.material1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.material2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.add_artifact );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.build_info );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.assign_info );
			readPos += GameAssist.ReadString( binContent, readPos, out member.preview_infolist1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.preview_infolist2 );

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
			Ex.Logger.Log("EquipBuild.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EquipBuild.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EquipBuild.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="formula_picture"){Ex.Logger.Log("EquipBuild.csv中字段[formula_picture]位置不对应"); return false; }
		if(vecLine[3]!="build_cost"){Ex.Logger.Log("EquipBuild.csv中字段[build_cost]位置不对应"); return false; }
		if(vecLine[4]!="material1"){Ex.Logger.Log("EquipBuild.csv中字段[material1]位置不对应"); return false; }
		if(vecLine[5]!="material2"){Ex.Logger.Log("EquipBuild.csv中字段[material2]位置不对应"); return false; }
		if(vecLine[6]!="add_artifact"){Ex.Logger.Log("EquipBuild.csv中字段[add_artifact]位置不对应"); return false; }
		if(vecLine[7]!="build_info"){Ex.Logger.Log("EquipBuild.csv中字段[build_info]位置不对应"); return false; }
		if(vecLine[8]!="assign_info"){Ex.Logger.Log("EquipBuild.csv中字段[assign_info]位置不对应"); return false; }
		if(vecLine[9]!="preview_infolist1"){Ex.Logger.Log("EquipBuild.csv中字段[preview_infolist1]位置不对应"); return false; }
		if(vecLine[10]!="preview_infolist2"){Ex.Logger.Log("EquipBuild.csv中字段[preview_infolist2]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			EquipBuildElement member = new EquipBuildElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.formula_picture=vecLine[2];
			member.build_cost=Convert.ToInt32(vecLine[3]);
			member.material1=vecLine[4];
			member.material2=vecLine[5];
			member.add_artifact=Convert.ToInt32(vecLine[6]);
			member.build_info=Convert.ToInt32(vecLine[7]);
			member.assign_info=Convert.ToInt32(vecLine[8]);
			member.preview_infolist1=vecLine[9];
			member.preview_infolist2=Convert.ToInt32(vecLine[10]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
