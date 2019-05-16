using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//场景obj配置数据类
public class EventObjElement
{
	public int id;               	//序号	OBJ表主键序号
	public string comment;       	//备注	备注（仅策划用）
	public int name;             	//名称	调用StringCreature表的对应数据
	public int quest_id;         	//任务id	有此任务才能交互
	public int quest_step;       	//任务步骤	所在任务中的步骤
	public int model_id;         	//模型路径	OBJ模型路径
	public float leisure_pro;    	//播放休闲动画几率	1=100%
	public int belong_type;      	//归属情况	0为所有玩家 1为当前玩家 2为当前队伍 3为当前团队 4为当前公会 5为当前阵营
	public int state_type;       	//OBJ状态	0为出生状态，1为交互状态，2为交互完毕，3为消失时
	public string icon_path;     	//交互图标路径	2D资源路径
	public int popup_id;         	//气泡框id	该OBJ交互时弹出的气泡框
	public string head_icon_path;	//头标路径	头标路径
	public string minimap_display_icon;	//雷达图标	在雷达地图中显示的图标路径
	public int allow_multi_player;	//多玩家交互	1为是，0为否
	public int interact_skill_id;	//技能	交互时播放的技能
	public li loot_list;         	//掉落物品id	互动后掉落物品id集合 0：掉落道具|道具ID|数量 1：概率计算|概率掉落包ID|数量 2：权值计算|权值掉落包ID|数量
	public int is_vanish;        	//自动消失	该交互后是否自动消失 1为是 0为否
	public int vanish_time;      	//消失时间	交互后消失时间 (单位s）
	public ls buff_id_list;      	//该OBJ在交互后给玩家套上的buff id集合	该OBJ在交互后给玩家套上的buff id集合
	public int obj_type;         	//OBJ类型	0 可交互非阻挡类 1 非交互可阻挡类 2 非交互非阻挡类      
	public li obj_size;          	//OBJ大小	如果该obj为阻挡型obj，则在此规定他的 长度|高度|宽度      
	public int qte_id;           	//qte的id	0为无qte，关联qte表      
	public string script_id;     	//obj脚本id	obj需要执行的脚本id
	public int cg_id;            	//交互后触发的cg	cg的id
	public li CreatureHide_id;   	//显示隐藏表ID	控制任务NPC的显示和隐藏关联CreatureHide_NPC或OBJ显示隐藏表 多个id以|隔开
	public int auto_interact;    	//是否自动交互	0为不自动交互 1为可自动交互

	public bool IsValidate = false;
	public EventObjElement()
	{
		id = -1;
	}
};

//场景obj配置封装类
public class EventObjTable
{

	private EventObjTable()
	{
		m_mapElements = new Dictionary<int, EventObjElement>();
		m_emptyItem = new EventObjElement();
		m_vecAllElements = new List<EventObjElement>();
	}
	private Dictionary<int, EventObjElement> m_mapElements = null;
	private List<EventObjElement>	m_vecAllElements = null;
	private EventObjElement m_emptyItem = null;
	private static EventObjTable sInstance = null;

	public static EventObjTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new EventObjTable();
			return sInstance;
		}
	}

	public EventObjElement GetElement(int key)
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

  public List<EventObjElement> GetAllElement(Predicate<EventObjElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("EventObj.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("EventObj.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[EventObj.bin]未找到");
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
		if(vecLine.Count != 26)
		{
			Ex.Logger.Log("EventObj.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EventObj.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EventObj.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("EventObj.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="quest_id"){Ex.Logger.Log("EventObj.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[4]!="quest_step"){Ex.Logger.Log("EventObj.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[5]!="model_id"){Ex.Logger.Log("EventObj.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[6]!="leisure_pro"){Ex.Logger.Log("EventObj.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[7]!="belong_type"){Ex.Logger.Log("EventObj.csv中字段[belong_type]位置不对应"); return false; }
		if(vecLine[8]!="state_type"){Ex.Logger.Log("EventObj.csv中字段[state_type]位置不对应"); return false; }
		if(vecLine[9]!="icon_path"){Ex.Logger.Log("EventObj.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[10]!="popup_id"){Ex.Logger.Log("EventObj.csv中字段[popup_id]位置不对应"); return false; }
		if(vecLine[11]!="head_icon_path"){Ex.Logger.Log("EventObj.csv中字段[head_icon_path]位置不对应"); return false; }
		if(vecLine[12]!="minimap_display_icon"){Ex.Logger.Log("EventObj.csv中字段[minimap_display_icon]位置不对应"); return false; }
		if(vecLine[13]!="allow_multi_player"){Ex.Logger.Log("EventObj.csv中字段[allow_multi_player]位置不对应"); return false; }
		if(vecLine[14]!="interact_skill_id"){Ex.Logger.Log("EventObj.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[15]!="loot_list"){Ex.Logger.Log("EventObj.csv中字段[loot_list]位置不对应"); return false; }
		if(vecLine[16]!="is_vanish"){Ex.Logger.Log("EventObj.csv中字段[is_vanish]位置不对应"); return false; }
		if(vecLine[17]!="vanish_time"){Ex.Logger.Log("EventObj.csv中字段[vanish_time]位置不对应"); return false; }
		if(vecLine[18]!="buff_id_list"){Ex.Logger.Log("EventObj.csv中字段[buff_id_list]位置不对应"); return false; }
		if(vecLine[19]!="obj_type"){Ex.Logger.Log("EventObj.csv中字段[obj_type]位置不对应"); return false; }
		if(vecLine[20]!="obj_size"){Ex.Logger.Log("EventObj.csv中字段[obj_size]位置不对应"); return false; }
		if(vecLine[21]!="qte_id"){Ex.Logger.Log("EventObj.csv中字段[qte_id]位置不对应"); return false; }
		if(vecLine[22]!="script_id"){Ex.Logger.Log("EventObj.csv中字段[script_id]位置不对应"); return false; }
		if(vecLine[23]!="cg_id"){Ex.Logger.Log("EventObj.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[24]!="CreatureHide_id"){Ex.Logger.Log("EventObj.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[25]!="auto_interact"){Ex.Logger.Log("EventObj.csv中字段[auto_interact]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			EventObjElement member = new EventObjElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.leisure_pro);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.belong_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.state_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon_path);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.popup_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.head_icon_path);
			readPos += GameAssist.ReadString( binContent, readPos, out member.minimap_display_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.allow_multi_player );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interact_skill_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.loot_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_vanish );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.vanish_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buff_id_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.obj_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.obj_size);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.qte_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cg_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.CreatureHide_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auto_interact );

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
		if(vecLine.Count != 26)
		{
			Ex.Logger.Log("EventObj.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("EventObj.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("EventObj.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("EventObj.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="quest_id"){Ex.Logger.Log("EventObj.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[4]!="quest_step"){Ex.Logger.Log("EventObj.csv中字段[quest_step]位置不对应"); return false; }
		if(vecLine[5]!="model_id"){Ex.Logger.Log("EventObj.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[6]!="leisure_pro"){Ex.Logger.Log("EventObj.csv中字段[leisure_pro]位置不对应"); return false; }
		if(vecLine[7]!="belong_type"){Ex.Logger.Log("EventObj.csv中字段[belong_type]位置不对应"); return false; }
		if(vecLine[8]!="state_type"){Ex.Logger.Log("EventObj.csv中字段[state_type]位置不对应"); return false; }
		if(vecLine[9]!="icon_path"){Ex.Logger.Log("EventObj.csv中字段[icon_path]位置不对应"); return false; }
		if(vecLine[10]!="popup_id"){Ex.Logger.Log("EventObj.csv中字段[popup_id]位置不对应"); return false; }
		if(vecLine[11]!="head_icon_path"){Ex.Logger.Log("EventObj.csv中字段[head_icon_path]位置不对应"); return false; }
		if(vecLine[12]!="minimap_display_icon"){Ex.Logger.Log("EventObj.csv中字段[minimap_display_icon]位置不对应"); return false; }
		if(vecLine[13]!="allow_multi_player"){Ex.Logger.Log("EventObj.csv中字段[allow_multi_player]位置不对应"); return false; }
		if(vecLine[14]!="interact_skill_id"){Ex.Logger.Log("EventObj.csv中字段[interact_skill_id]位置不对应"); return false; }
		if(vecLine[15]!="loot_list"){Ex.Logger.Log("EventObj.csv中字段[loot_list]位置不对应"); return false; }
		if(vecLine[16]!="is_vanish"){Ex.Logger.Log("EventObj.csv中字段[is_vanish]位置不对应"); return false; }
		if(vecLine[17]!="vanish_time"){Ex.Logger.Log("EventObj.csv中字段[vanish_time]位置不对应"); return false; }
		if(vecLine[18]!="buff_id_list"){Ex.Logger.Log("EventObj.csv中字段[buff_id_list]位置不对应"); return false; }
		if(vecLine[19]!="obj_type"){Ex.Logger.Log("EventObj.csv中字段[obj_type]位置不对应"); return false; }
		if(vecLine[20]!="obj_size"){Ex.Logger.Log("EventObj.csv中字段[obj_size]位置不对应"); return false; }
		if(vecLine[21]!="qte_id"){Ex.Logger.Log("EventObj.csv中字段[qte_id]位置不对应"); return false; }
		if(vecLine[22]!="script_id"){Ex.Logger.Log("EventObj.csv中字段[script_id]位置不对应"); return false; }
		if(vecLine[23]!="cg_id"){Ex.Logger.Log("EventObj.csv中字段[cg_id]位置不对应"); return false; }
		if(vecLine[24]!="CreatureHide_id"){Ex.Logger.Log("EventObj.csv中字段[CreatureHide_id]位置不对应"); return false; }
		if(vecLine[25]!="auto_interact"){Ex.Logger.Log("EventObj.csv中字段[auto_interact]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)26)
			{
				return false;
			}
			EventObjElement member = new EventObjElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.quest_id=Convert.ToInt32(vecLine[3]);
			member.quest_step=Convert.ToInt32(vecLine[4]);
			member.model_id=Convert.ToInt32(vecLine[5]);
			member.leisure_pro=Convert.ToSingle(vecLine[6]);
			member.belong_type=Convert.ToInt32(vecLine[7]);
			member.state_type=Convert.ToInt32(vecLine[8]);
			member.icon_path=vecLine[9];
			member.popup_id=Convert.ToInt32(vecLine[10]);
			member.head_icon_path=vecLine[11];
			member.minimap_display_icon=vecLine[12];
			member.allow_multi_player=Convert.ToInt32(vecLine[13]);
			member.interact_skill_id=Convert.ToInt32(vecLine[14]);
			member.loot_list=vecLine[15];
			member.is_vanish=Convert.ToInt32(vecLine[16]);
			member.vanish_time=Convert.ToInt32(vecLine[17]);
			member.buff_id_list=vecLine[18];
			member.obj_type=Convert.ToInt32(vecLine[19]);
			member.obj_size=vecLine[20];
			member.qte_id=Convert.ToInt32(vecLine[21]);
			member.script_id=vecLine[22];
			member.cg_id=Convert.ToInt32(vecLine[23]);
			member.CreatureHide_id=vecLine[24];
			member.auto_interact=Convert.ToInt32(vecLine[25]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
