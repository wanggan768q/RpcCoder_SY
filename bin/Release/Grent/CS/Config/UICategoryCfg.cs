using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//界面类型配置数据类
public class UICategoryElement
{
	public int id;               	//数据id	界面或者按钮的id (来源表引用， 一旦定下， 最好不要再修改)
	public string comment;       	//注释	该界面的功能
	public int is_on;            	//功能开关	表示该功能在版本中是否启用  0.未启用 1.启用
	public int order;            	//序列	无意义 用来对id进行生成
	public int type;             	//分类	用来区分枚举 0.HUD 1.背包 2.培养 3.打造 4.宠物 5.宠物提升 6.宝石合成 7.活动 8.积分商店 9.珍宝阁 10.生活技能 11.赠送礼物 12.拍卖行
	public int category;         	//	0.UI 1.button
	public int unlock_lv;        	//解锁等级	当玩家达到这个等级时解锁这个功能 等级默认为1
	public int unlock_quest;     	//解锁任务	当玩家完成该任务后，会解锁这个功能 和等级共同生效 可不填
	public int name;             	//界面名称	该界面对应StringUI表的id
	public string icon;          	//界面标示	该界面对应的图标名称
	public string btn_name;      	//按钮名称	如果是按钮类型，则需要填写该字段，以识别按钮对象
	public string prefab;        	//界面资源	该界面对应的prefab名称
	public int tab;              	//界面标签页	界面标签页对应的枚举 需要按照功能进行分配  另外用来定义每个页面中各个页签的上下顺序

	public bool IsValidate = false;
	public UICategoryElement()
	{
		id = -1;
	}
};

//界面类型配置封装类
public class UICategoryTable
{

	private UICategoryTable()
	{
		m_mapElements = new Dictionary<int, UICategoryElement>();
		m_emptyItem = new UICategoryElement();
		m_vecAllElements = new List<UICategoryElement>();
	}
	private Dictionary<int, UICategoryElement> m_mapElements = null;
	private List<UICategoryElement>	m_vecAllElements = null;
	private UICategoryElement m_emptyItem = null;
	private static UICategoryTable sInstance = null;

	public static UICategoryTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new UICategoryTable();
			return sInstance;
		}
	}

	public UICategoryElement GetElement(int key)
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

  public List<UICategoryElement> GetAllElement(Predicate<UICategoryElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("UICategory.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("UICategory.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[UICategory.bin]未找到");
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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("UICategory.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("UICategory.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("UICategory.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_on"){Ex.Logger.Log("UICategory.csv中字段[is_on]位置不对应"); return false; }
		if(vecLine[3]!="order"){Ex.Logger.Log("UICategory.csv中字段[order]位置不对应"); return false; }
		if(vecLine[4]!="type"){Ex.Logger.Log("UICategory.csv中字段[type]位置不对应"); return false; }
		if(vecLine[5]!="category"){Ex.Logger.Log("UICategory.csv中字段[category]位置不对应"); return false; }
		if(vecLine[6]!="unlock_lv"){Ex.Logger.Log("UICategory.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[7]!="unlock_quest"){Ex.Logger.Log("UICategory.csv中字段[unlock_quest]位置不对应"); return false; }
		if(vecLine[8]!="name"){Ex.Logger.Log("UICategory.csv中字段[name]位置不对应"); return false; }
		if(vecLine[9]!="icon"){Ex.Logger.Log("UICategory.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[10]!="btn_name"){Ex.Logger.Log("UICategory.csv中字段[btn_name]位置不对应"); return false; }
		if(vecLine[11]!="prefab"){Ex.Logger.Log("UICategory.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[12]!="tab"){Ex.Logger.Log("UICategory.csv中字段[tab]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			UICategoryElement member = new UICategoryElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_on );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.order );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.category );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_lv );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.unlock_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.btn_name);
			readPos += GameAssist.ReadString( binContent, readPos, out member.prefab);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tab );

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
		if(vecLine.Count != 13)
		{
			Ex.Logger.Log("UICategory.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("UICategory.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("UICategory.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="is_on"){Ex.Logger.Log("UICategory.csv中字段[is_on]位置不对应"); return false; }
		if(vecLine[3]!="order"){Ex.Logger.Log("UICategory.csv中字段[order]位置不对应"); return false; }
		if(vecLine[4]!="type"){Ex.Logger.Log("UICategory.csv中字段[type]位置不对应"); return false; }
		if(vecLine[5]!="category"){Ex.Logger.Log("UICategory.csv中字段[category]位置不对应"); return false; }
		if(vecLine[6]!="unlock_lv"){Ex.Logger.Log("UICategory.csv中字段[unlock_lv]位置不对应"); return false; }
		if(vecLine[7]!="unlock_quest"){Ex.Logger.Log("UICategory.csv中字段[unlock_quest]位置不对应"); return false; }
		if(vecLine[8]!="name"){Ex.Logger.Log("UICategory.csv中字段[name]位置不对应"); return false; }
		if(vecLine[9]!="icon"){Ex.Logger.Log("UICategory.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[10]!="btn_name"){Ex.Logger.Log("UICategory.csv中字段[btn_name]位置不对应"); return false; }
		if(vecLine[11]!="prefab"){Ex.Logger.Log("UICategory.csv中字段[prefab]位置不对应"); return false; }
		if(vecLine[12]!="tab"){Ex.Logger.Log("UICategory.csv中字段[tab]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)13)
			{
				return false;
			}
			UICategoryElement member = new UICategoryElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.is_on=Convert.ToInt32(vecLine[2]);
			member.order=Convert.ToInt32(vecLine[3]);
			member.type=Convert.ToInt32(vecLine[4]);
			member.category=Convert.ToInt32(vecLine[5]);
			member.unlock_lv=Convert.ToInt32(vecLine[6]);
			member.unlock_quest=Convert.ToInt32(vecLine[7]);
			member.name=Convert.ToInt32(vecLine[8]);
			member.icon=vecLine[9];
			member.btn_name=vecLine[10];
			member.prefab=vecLine[11];
			member.tab=Convert.ToInt32(vecLine[12]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
