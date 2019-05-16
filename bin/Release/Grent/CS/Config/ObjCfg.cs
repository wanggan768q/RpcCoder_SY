using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//场景obj配置数据类
public class ObjElement
{
	public int id;               	//序号	OBJ表主键序号
	public int belong_type;      	//OBJ归属情况	0为所有玩家，1为当前玩家，2为当前队伍，3为当前团队，4为当前公会，5为当前阵营
	public int model_id;         	//OBJ模型路径	OBJ模型路径
	public int state_type;       	//OBJ状态	0为出生状态，1为交互状态，2为交互完毕，3为消失时
	public string icon_path;     	//该OBJ在玩家到达位置后显示的可交互图标	2D资源路径
	public string script_path;   	//该OBJ需要运行的逻辑脚本	该OBJ需要运行的逻辑脚本
	public string head_icon_path;	//头标路径	头标路径
	public int quest_id;         	//该OBJ所依附的任务id	填写该id则该obj只在该任务所在镜像内出现
	public int quest_step;       	//该obj所在任务中的步骤	该obj所在任务中的步骤
	public int popup_id;         	//该OBJ交互时弹出的气泡框	该OBJ交互时弹出的气泡框
	public int minimap_display_icon;	//在雷达地图中显示的图标	在雷达地图中显示的图标
	public int allow_multi_player;	//是否允许多玩家交互	1为是，0为否。当该字段数值为0时若 有其他玩家在进行交互则当前玩家不能立即进行交互，并弹出string_script为2的内容 
	public int interact_skill_id;	//玩家在交互时需要播放的交互技能	包括技能动作、特效、持续时长等
	public ls loot_list;         	//该OBJ在交互后给玩家套上的buff id集合	该OBJ在交互后给玩家套上的buff id集合
	public int script_id;        	//obj脚本id	obj需要执行的脚本id
	public int is_need_collider; 	//该OBJ是否需要碰撞体	1为是，0为否

	public bool IsValidate = false;
	public ObjElement()
	{
		id = -1;
	}
};

//场景obj配置封装类
public class ObjTable
{

	private ObjTable()
	{
		m_mapElements = new Dictionary<int, ObjElement>();
		m_emptyItem = new ObjElement();
		m_vecAllElements = new List<ObjElement>();
	}
	private Dictionary<int, ObjElement> m_mapElements = null;
	private List<ObjElement>	m_vecAllElements = null;
	private ObjElement m_emptyItem = null;
	private static ObjTable sInstance = null;

	public static ObjTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ObjTable();
			return sInstance;
		}
	}

	public ObjElement GetElement(int key)
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

  public List<ObjElement> GetAllElement(Predicate<ObjElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Obj.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Obj.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Obj.bin]未找到");
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
			Ex.Logger.Log("Obj.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Obj.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="belong_type"){Ex.Logger.Log("Obj.csv中字段[belong_type]位置不对应"); return false; }
		if(vecLine[2]!="model_id"){Ex.Logger.Log("Obj.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[3]!="state_type"){Ex.Logger.Log("Obj.csv中字段[state_type]位置不对应"); return false; }
		if(vecLine[4]!="icon_path"){Ex.Logger.Log("Obj.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[5]!="script_path"){Ex.Logger.Log("Obj.csv中字段[script_path]位置不对应"); return false; }
		if(vecLine[6]!="head_icon_path"){Ex.Logger.Log("Obj.csv中字段[head_icon_path]位置不对应"); return false; }
		if(vecLine[7]!="quest_id"){Ex.Logger.Log("Obj.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[8]!="quest_step"){Ex.Logger.Log("Obj.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[9]!="popup_id"){Ex.Logger.Log("Obj.csv中字段[popup_id]位置不对应"); return false; }
		if(vecLine[10]!="minimap_display_icon"){Ex.Logger.Log("Obj.csv中字段[minimap_display_icon]位置不对应"); return false; }
		if(vecLine[11]!="allow_multi_player"){Ex.Logger.Log("Obj.csv中字段[allow_multi_player]位置不对应"); return false; }
		if(vecLine[12]!="interact_skill_id"){Ex.Logger.Log("Obj.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[13]!="loot_list"){Ex.Logger.Log("Obj.csv中字段[loot_list]位置不对应"); return false; }
		if(vecLine[14]!="script_id"){Ex.Logger.Log("Obj.csv中字段[script_id]位置不对应"); return false; }
		if(vecLine[15]!="is_need_collider"){Ex.Logger.Log("Obj.csv中字段[is_need_collider]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ObjElement member = new ObjElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.belong_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.state_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon_path);
			readPos += GameAssist.ReadString( binContent, readPos, out member.script_path);
			readPos += GameAssist.ReadString( binContent, readPos, out member.head_icon_path);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.popup_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.minimap_display_icon );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.allow_multi_player );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interact_skill_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.loot_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.script_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_need_collider );

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
			Ex.Logger.Log("Obj.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Obj.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="belong_type"){Ex.Logger.Log("Obj.csv中字段[belong_type]位置不对应"); return false; }
		if(vecLine[2]!="model_id"){Ex.Logger.Log("Obj.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[3]!="state_type"){Ex.Logger.Log("Obj.csv中字段[state_type]位置不对应"); return false; }
		if(vecLine[4]!="icon_path"){Ex.Logger.Log("Obj.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[5]!="script_path"){Ex.Logger.Log("Obj.csv中字段[script_path]位置不对应"); return false; }
		if(vecLine[6]!="head_icon_path"){Ex.Logger.Log("Obj.csv中字段[head_icon_path]位置不对应"); return false; }
		if(vecLine[7]!="quest_id"){Ex.Logger.Log("Obj.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[8]!="quest_step"){Ex.Logger.Log("Obj.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[9]!="popup_id"){Ex.Logger.Log("Obj.csv中字段[popup_id]位置不对应"); return false; }
		if(vecLine[10]!="minimap_display_icon"){Ex.Logger.Log("Obj.csv中字段[minimap_display_icon]位置不对应"); return false; }
		if(vecLine[11]!="allow_multi_player"){Ex.Logger.Log("Obj.csv中字段[allow_multi_player]位置不对应"); return false; }
		if(vecLine[12]!="interact_skill_id"){Ex.Logger.Log("Obj.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[13]!="loot_list"){Ex.Logger.Log("Obj.csv中字段[loot_list]位置不对应"); return false; }
		if(vecLine[14]!="script_id"){Ex.Logger.Log("Obj.csv中字段[script_id]位置不对应"); return false; }
		if(vecLine[15]!="is_need_collider"){Ex.Logger.Log("Obj.csv中字段[is_need_collider]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)16)
			{
				return false;
			}
			ObjElement member = new ObjElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.belong_type=Convert.ToInt32(vecLine[1]);
			member.model_id=Convert.ToInt32(vecLine[2]);
			member.state_type=Convert.ToInt32(vecLine[3]);
			member.icon_path=vecLine[4];
			member.script_path=vecLine[5];
			member.head_icon_path=vecLine[6];
			member.quest_id=Convert.ToInt32(vecLine[7]);
			member.quest_step=Convert.ToInt32(vecLine[8]);
			member.popup_id=Convert.ToInt32(vecLine[9]);
			member.minimap_display_icon=Convert.ToInt32(vecLine[10]);
			member.allow_multi_player=Convert.ToInt32(vecLine[11]);
			member.interact_skill_id=Convert.ToInt32(vecLine[12]);
			member.loot_list=vecLine[13];
			member.script_id=Convert.ToInt32(vecLine[14]);
			member.is_need_collider=Convert.ToInt32(vecLine[15]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
