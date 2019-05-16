using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物捕获前端配置数据类
public class PetCaptureShowElement
{
	public int id;               	//宠物id	填写ID即可
	public string comment;       	//注释	策划用
	public int name;             	//宠物名称	显示的宠物名称 StringItem_道具文本表
	public int description;      	//宠物描述	用于在宠物召唤界面和宠物图鉴中显示
	public string rarity;        	//宠物稀有度	稀有度对应的图片资源路径
	public int type;             	//宠物分类	用于区分宠物功能方面的分类 1.防御 2.辅助 3.物理 4.法术
	public string icon;          	//宠物图标	宠物显示时的头像
	public string model;         	//宠物模型	宠物在游戏中调用的模型
	public string talent_pic;    	//资质雷达图	宠物对应的资质雷达图的资源名称
	public int speed;            	//移动速度	宠物默认移动速度
	public int spawn_action;     	//出生动画	宠物出生时的动画  对应技能表中不广播技能
	public int possesssed_action;	//附身动画	宠物进战时的动画  对应技能表中不广播技能
	public int possesssed_buff;  	//附身特效	宠物进战时播放的特效  对应buff表中配置
	public int leave_fight_action;	//脱战动画	宠物脱战时的动画  对应技能表中不广播技能
	public int interact_action;  	//交互动画	宠物交互时的动画  对应技能表中不广播技能
	public int level_up_action;  	//升级动画	宠物培养成功时的动画  对应技能表中不广播技能
	public int active_skill;     	//主动技能	宠物对应的主动技能的id
	public li passive_skill;     	//被动技能	宠物生成时自带被动技能的id 数组，最多8个

	public bool IsValidate = false;
	public PetCaptureShowElement()
	{
		id = -1;
	}
};

//宠物捕获前端配置封装类
public class PetCaptureShowTable
{

	private PetCaptureShowTable()
	{
		m_mapElements = new Dictionary<int, PetCaptureShowElement>();
		m_emptyItem = new PetCaptureShowElement();
		m_vecAllElements = new List<PetCaptureShowElement>();
	}
	private Dictionary<int, PetCaptureShowElement> m_mapElements = null;
	private List<PetCaptureShowElement>	m_vecAllElements = null;
	private PetCaptureShowElement m_emptyItem = null;
	private static PetCaptureShowTable sInstance = null;

	public static PetCaptureShowTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetCaptureShowTable();
			return sInstance;
		}
	}

	public PetCaptureShowElement GetElement(int key)
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

  public List<PetCaptureShowElement> GetAllElement(Predicate<PetCaptureShowElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetCaptureShow.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetCaptureShow.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetCaptureShow.bin]未找到");
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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("PetCaptureShow.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetCaptureShow.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetCaptureShow.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetCaptureShow.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="description"){Ex.Logger.Log("PetCaptureShow.csv中字段[description]位置不对应"); return false; }
		if(vecLine[4]!="rarity"){Ex.Logger.Log("PetCaptureShow.csv中字段[rarity]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("PetCaptureShow.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("PetCaptureShow.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="model"){Ex.Logger.Log("PetCaptureShow.csv中字段[model]位置不对应"); return false; }
		if(vecLine[8]!="talent_pic"){Ex.Logger.Log("PetCaptureShow.csv中字段[talent_pic]位置不对应"); return false; }
		if(vecLine[9]!="speed"){Ex.Logger.Log("PetCaptureShow.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[10]!="spawn_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[spawn_action]位置不对应"); return false; }
		if(vecLine[11]!="possesssed_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[possesssed_action]位置不对应"); return false; }
		if(vecLine[12]!="possesssed_buff"){Ex.Logger.Log("PetCaptureShow.csv中字段[possesssed_buff]位置不对应"); return false; }
		if(vecLine[13]!="leave_fight_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[leave_fight_action]位置不对应"); return false; }
		if(vecLine[14]!="interact_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[interact_action]位置不对应"); return false; }
		if(vecLine[15]!="level_up_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[level_up_action]位置不对应"); return false; }
		if(vecLine[16]!="active_skill"){Ex.Logger.Log("PetCaptureShow.csv中字段[active_skill]位置不对应"); return false; }
		if(vecLine[17]!="passive_skill"){Ex.Logger.Log("PetCaptureShow.csv中字段[passive_skill]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetCaptureShowElement member = new PetCaptureShowElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rarity);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.model);
			readPos += GameAssist.ReadString( binContent, readPos, out member.talent_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.speed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spawn_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.possesssed_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.possesssed_buff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_fight_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interact_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.level_up_action );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.active_skill );
			readPos += GameAssist.ReadString( binContent, readPos, out member.passive_skill);

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
		if(vecLine.Count != 18)
		{
			Ex.Logger.Log("PetCaptureShow.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetCaptureShow.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetCaptureShow.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetCaptureShow.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="description"){Ex.Logger.Log("PetCaptureShow.csv中字段[description]位置不对应"); return false; }
		if(vecLine[4]!="rarity"){Ex.Logger.Log("PetCaptureShow.csv中字段[rarity]位置不对应"); return false; }
		if(vecLine[5]!="type"){Ex.Logger.Log("PetCaptureShow.csv中字段[type]位置不对应"); return false; }
		if(vecLine[6]!="icon"){Ex.Logger.Log("PetCaptureShow.csv中字段[icon]位置不对应"); return false; }
		if(vecLine[7]!="model"){Ex.Logger.Log("PetCaptureShow.csv中字段[model]位置不对应"); return false; }
		if(vecLine[8]!="talent_pic"){Ex.Logger.Log("PetCaptureShow.csv中字段[talent_pic]位置不对应"); return false; }
		if(vecLine[9]!="speed"){Ex.Logger.Log("PetCaptureShow.csv中字段[speed]位置不对应"); return false; }
		if(vecLine[10]!="spawn_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[spawn_action]位置不对应"); return false; }
		if(vecLine[11]!="possesssed_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[possesssed_action]位置不对应"); return false; }
		if(vecLine[12]!="possesssed_buff"){Ex.Logger.Log("PetCaptureShow.csv中字段[possesssed_buff]位置不对应"); return false; }
		if(vecLine[13]!="leave_fight_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[leave_fight_action]位置不对应"); return false; }
		if(vecLine[14]!="interact_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[interact_action]位置不对应"); return false; }
		if(vecLine[15]!="level_up_action"){Ex.Logger.Log("PetCaptureShow.csv中字段[level_up_action]位置不对应"); return false; }
		if(vecLine[16]!="active_skill"){Ex.Logger.Log("PetCaptureShow.csv中字段[active_skill]位置不对应"); return false; }
		if(vecLine[17]!="passive_skill"){Ex.Logger.Log("PetCaptureShow.csv中字段[passive_skill]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)18)
			{
				return false;
			}
			PetCaptureShowElement member = new PetCaptureShowElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.description=Convert.ToInt32(vecLine[3]);
			member.rarity=vecLine[4];
			member.type=Convert.ToInt32(vecLine[5]);
			member.icon=vecLine[6];
			member.model=vecLine[7];
			member.talent_pic=vecLine[8];
			member.speed=Convert.ToInt32(vecLine[9]);
			member.spawn_action=Convert.ToInt32(vecLine[10]);
			member.possesssed_action=Convert.ToInt32(vecLine[11]);
			member.possesssed_buff=Convert.ToInt32(vecLine[12]);
			member.leave_fight_action=Convert.ToInt32(vecLine[13]);
			member.interact_action=Convert.ToInt32(vecLine[14]);
			member.level_up_action=Convert.ToInt32(vecLine[15]);
			member.active_skill=Convert.ToInt32(vecLine[16]);
			member.passive_skill=vecLine[17];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
