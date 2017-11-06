using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//角色属性配置数据类
public class RoleElement
{
	public int id;               	//id	种族*100000+职业*10+性别
	public string comment;       	//注释	注释
	public int race;             	//种族	1：人类 2：精灵 3：兽人 4：萝莉
	public int occupation;       	//职业	1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士 6：神秘使
	public int gender;           	//性别	1:男性 2:女性
	public string race_icon;     	//种族图标	种族图标
	public int race_name;        	//种族名称	种族名称
	public int race_desc;        	//种族介绍	种族介绍
	public string occu_icon;     	//职业图标	职业图标
	public ls create_occu_icon;  	//创选界面图标	专门用在创选界面的职业图标 对应未选中和选中两个状态
	public int occu_name;        	//职业名称	职业名称
	public int occu_desc;        	//职业介绍	职业介绍
	public li occu_evaluate;     	//职业评估	输出|生存|治疗|操作难度 0~10对应0到5格
	public int model_id;         	//初始模型id	初始模型id
	public int strength;         	//力量	力量
	public int speed ;           	//敏捷	敏捷
	public int agile;            	//智力	智力
	public int stamina;          	//耐力	耐力
	public int spirit;           	//精神	精神
	public int maxhp;            	//最大基础血量	最大基础血量
	public int maxmp;            	//最大魔法量	最大魔法量
	public int physic_attack;    	//物理攻击	物理攻击
	public int physic_defense;   	//物理防御	物理防御
	public int magic_attack;     	//魔法攻击	魔法攻击
	public int magic_defense;    	//魔法防御	魔法防御
	public int hit_value;        	//命中值	命中值
	public int hit_rate;         	//命中率	命中率
	public int miss_value;       	//闪避值	闪避值
	public int miss_rate;        	//闪避率	闪避率
	public int critical_value;   	//暴击值	暴击值
	public int critical_rate;    	//暴击率	暴击率
	public int tenacity_value;   	//韧性值	韧性值
	public int tenacity_rate;    	//韧性率	韧性率
	public int dodge_value;      	//格挡值	格挡值
	public int dodge_rate;       	//格挡率	格挡率
	public int penetrate_value;  	//穿透值	穿透值
	public int penetrate_rate;   	//穿透率	穿透率
	public int miss_level;       	//闪避等级	闪避等级
	public int critical_level;   	//暴击等级	暴击等级
	public int dodge_level;      	//格挡等级	格挡等级
	public int move_speed;       	//移动速度	移动速度
	public int physic_oppose;    	//物理抗性	物理抗性
	public int magic_oppose;     	//魔法抗性	魔法抗性
	public int physic_add;       	//物理追加	物理追加
	public int magic_add;        	//魔法追加	魔法追加
	public int scene_id;         	//初始场景id	初始场景id
	public float posx;           	//初始x坐标	初始x坐标
	public float posz;           	//初始z坐标	初始z坐标
	public float direct;         	//角色朝向	角色朝向

	public bool IsValidate = false;
	public RoleElement()
	{
		id = -1;
	}
};

//角色属性配置封装类
public class RoleTable
{

	private RoleTable()
	{
		m_mapElements = new Dictionary<int, RoleElement>();
		m_emptyItem = new RoleElement();
		m_vecAllElements = new List<RoleElement>();
	}
	private Dictionary<int, RoleElement> m_mapElements = null;
	private List<RoleElement>	m_vecAllElements = null;
	private RoleElement m_emptyItem = null;
	private static RoleTable sInstance = null;

	public static RoleTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new RoleTable();
			return sInstance;
		}
	}

	public RoleElement GetElement(int key)
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

  public List<RoleElement> GetAllElement(Predicate<RoleElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Role.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Role.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Role.bin]未找到");
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
		if(vecLine.Count != 49)
		{
			Ex.Logger.Log("Role.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Role.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Role.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="race"){Ex.Logger.Log("Role.csv中字段[race]位置不对应"); return false; }
		if(vecLine[3]!="occupation"){Ex.Logger.Log("Role.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[4]!="gender"){Ex.Logger.Log("Role.csv中字段[gender]位置不对应"); return false; }
		if(vecLine[5]!="race_icon"){Ex.Logger.Log("Role.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[6]!="race_name"){Ex.Logger.Log("Role.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[7]!="race_desc"){Ex.Logger.Log("Role.csv中字段[race_desc]位置不对应"); return false; }
		if(vecLine[8]!="occu_icon"){Ex.Logger.Log("Role.csv中字段[occu_icon]位置不对应"); return false; }
		if(vecLine[9]!="create_occu_icon"){Ex.Logger.Log("Role.csv中字段[create_occu_icon]位置不对应"); return false; }
		if(vecLine[10]!="occu_name"){Ex.Logger.Log("Role.csv中字段[occu_name]位置不对应"); return false; }
		if(vecLine[11]!="occu_desc"){Ex.Logger.Log("Role.csv中字段[occu_desc]位置不对应"); return false; }
		if(vecLine[12]!="occu_evaluate"){Ex.Logger.Log("Role.csv中字段[occu_evaluate]位置不对应"); return false; }
		if(vecLine[13]!="model_id"){Ex.Logger.Log("Role.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[14]!="strength"){Ex.Logger.Log("Role.csv中字段[strength]位置不对应"); return false; }
		if(vecLine[15]!="speed "){Ex.Logger.Log("Role.csv中字段[speed ]位置不对应"); return false; }
		if(vecLine[16]!="agile"){Ex.Logger.Log("Role.csv中字段[agile]位置不对应"); return false; }
		if(vecLine[17]!="stamina"){Ex.Logger.Log("Role.csv中字段[stamina]位置不对应"); return false; }
		if(vecLine[18]!="spirit"){Ex.Logger.Log("Role.csv中字段[spirit]位置不对应"); return false; }
		if(vecLine[19]!="maxhp"){Ex.Logger.Log("Role.csv中字段[maxhp]位置不对应"); return false; }
		if(vecLine[20]!="maxmp"){Ex.Logger.Log("Role.csv中字段[maxmp]位置不对应"); return false; }
		if(vecLine[21]!="physic_attack"){Ex.Logger.Log("Role.csv中字段[physic_attack]位置不对应"); return false; }
		if(vecLine[22]!="physic_defense"){Ex.Logger.Log("Role.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[23]!="magic_attack"){Ex.Logger.Log("Role.csv中字段[magic_attack]位置不对应"); return false; }
		if(vecLine[24]!="magic_defense"){Ex.Logger.Log("Role.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[25]!="hit_value"){Ex.Logger.Log("Role.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[26]!="hit_rate"){Ex.Logger.Log("Role.csv中字段[hit_rate]位置不对应"); return false; }
		if(vecLine[27]!="miss_value"){Ex.Logger.Log("Role.csv中字段[miss_value]位置不对应"); return false; }
		if(vecLine[28]!="miss_rate"){Ex.Logger.Log("Role.csv中字段[miss_rate]位置不对应"); return false; }
		if(vecLine[29]!="critical_value"){Ex.Logger.Log("Role.csv中字段[critical_value]位置不对应"); return false; }
		if(vecLine[30]!="critical_rate"){Ex.Logger.Log("Role.csv中字段[critical_rate]位置不对应"); return false; }
		if(vecLine[31]!="tenacity_value"){Ex.Logger.Log("Role.csv中字段[tenacity_value]位置不对应"); return false; }
		if(vecLine[32]!="tenacity_rate"){Ex.Logger.Log("Role.csv中字段[tenacity_rate]位置不对应"); return false; }
		if(vecLine[33]!="dodge_value"){Ex.Logger.Log("Role.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[34]!="dodge_rate"){Ex.Logger.Log("Role.csv中字段[dodge_rate]位置不对应"); return false; }
		if(vecLine[35]!="penetrate_value"){Ex.Logger.Log("Role.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[36]!="penetrate_rate"){Ex.Logger.Log("Role.csv中字段[penetrate_rate]位置不对应"); return false; }
		if(vecLine[37]!="miss_level"){Ex.Logger.Log("Role.csv中字段[miss_level]位置不对应"); return false; }
		if(vecLine[38]!="critical_level"){Ex.Logger.Log("Role.csv中字段[critical_level]位置不对应"); return false; }
		if(vecLine[39]!="dodge_level"){Ex.Logger.Log("Role.csv中字段[dodge_level]位置不对应"); return false; }
		if(vecLine[40]!="move_speed"){Ex.Logger.Log("Role.csv中字段[move_speed]位置不对应"); return false; }
		if(vecLine[41]!="physic_oppose"){Ex.Logger.Log("Role.csv中字段[physic_oppose]位置不对应"); return false; }
		if(vecLine[42]!="magic_oppose"){Ex.Logger.Log("Role.csv中字段[magic_oppose]位置不对应"); return false; }
		if(vecLine[43]!="physic_add"){Ex.Logger.Log("Role.csv中字段[physic_add]位置不对应"); return false; }
		if(vecLine[44]!="magic_add"){Ex.Logger.Log("Role.csv中字段[magic_add]位置不对应"); return false; }
		if(vecLine[45]!="scene_id"){Ex.Logger.Log("Role.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[46]!="posx"){Ex.Logger.Log("Role.csv中字段[posx]位置不对应"); return false; }
		if(vecLine[47]!="posz"){Ex.Logger.Log("Role.csv中字段[posz]位置不对应"); return false; }
		if(vecLine[48]!="direct"){Ex.Logger.Log("Role.csv中字段[direct]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			RoleElement member = new RoleElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occupation );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.gender );
			readPos += GameAssist.ReadString( binContent, readPos, out member.race_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.race_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occu_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.create_occu_icon);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occu_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.occu_desc );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occu_evaluate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.model_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.strength );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.speed  );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.agile );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.stamina );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.spirit );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.maxhp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.maxmp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_attack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_defense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_attack );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_defense );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hit_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hit_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.miss_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.miss_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.critical_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.critical_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tenacity_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.tenacity_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dodge_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dodge_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.penetrate_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.penetrate_rate );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.miss_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.critical_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dodge_level );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.move_speed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_oppose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_oppose );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.physic_add );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.magic_add );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.posx);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.posz);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.direct);

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
		if(vecLine.Count != 49)
		{
			Ex.Logger.Log("Role.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Role.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Role.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="race"){Ex.Logger.Log("Role.csv中字段[race]位置不对应"); return false; }
		if(vecLine[3]!="occupation"){Ex.Logger.Log("Role.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[4]!="gender"){Ex.Logger.Log("Role.csv中字段[gender]位置不对应"); return false; }
		if(vecLine[5]!="race_icon"){Ex.Logger.Log("Role.csv中字段[race_icon]位置不对应"); return false; }
		if(vecLine[6]!="race_name"){Ex.Logger.Log("Role.csv中字段[race_name]位置不对应"); return false; }
		if(vecLine[7]!="race_desc"){Ex.Logger.Log("Role.csv中字段[race_desc]位置不对应"); return false; }
		if(vecLine[8]!="occu_icon"){Ex.Logger.Log("Role.csv中字段[occu_icon]位置不对应"); return false; }
		if(vecLine[9]!="create_occu_icon"){Ex.Logger.Log("Role.csv中字段[create_occu_icon]位置不对应"); return false; }
		if(vecLine[10]!="occu_name"){Ex.Logger.Log("Role.csv中字段[occu_name]位置不对应"); return false; }
		if(vecLine[11]!="occu_desc"){Ex.Logger.Log("Role.csv中字段[occu_desc]位置不对应"); return false; }
		if(vecLine[12]!="occu_evaluate"){Ex.Logger.Log("Role.csv中字段[occu_evaluate]位置不对应"); return false; }
		if(vecLine[13]!="model_id"){Ex.Logger.Log("Role.csv中字段[model_id]位置不对应"); return false; }
		if(vecLine[14]!="strength"){Ex.Logger.Log("Role.csv中字段[strength]位置不对应"); return false; }
		if(vecLine[15]!="speed "){Ex.Logger.Log("Role.csv中字段[speed ]位置不对应"); return false; }
		if(vecLine[16]!="agile"){Ex.Logger.Log("Role.csv中字段[agile]位置不对应"); return false; }
		if(vecLine[17]!="stamina"){Ex.Logger.Log("Role.csv中字段[stamina]位置不对应"); return false; }
		if(vecLine[18]!="spirit"){Ex.Logger.Log("Role.csv中字段[spirit]位置不对应"); return false; }
		if(vecLine[19]!="maxhp"){Ex.Logger.Log("Role.csv中字段[maxhp]位置不对应"); return false; }
		if(vecLine[20]!="maxmp"){Ex.Logger.Log("Role.csv中字段[maxmp]位置不对应"); return false; }
		if(vecLine[21]!="physic_attack"){Ex.Logger.Log("Role.csv中字段[physic_attack]位置不对应"); return false; }
		if(vecLine[22]!="physic_defense"){Ex.Logger.Log("Role.csv中字段[physic_defense]位置不对应"); return false; }
		if(vecLine[23]!="magic_attack"){Ex.Logger.Log("Role.csv中字段[magic_attack]位置不对应"); return false; }
		if(vecLine[24]!="magic_defense"){Ex.Logger.Log("Role.csv中字段[magic_defense]位置不对应"); return false; }
		if(vecLine[25]!="hit_value"){Ex.Logger.Log("Role.csv中字段[hit_value]位置不对应"); return false; }
		if(vecLine[26]!="hit_rate"){Ex.Logger.Log("Role.csv中字段[hit_rate]位置不对应"); return false; }
		if(vecLine[27]!="miss_value"){Ex.Logger.Log("Role.csv中字段[miss_value]位置不对应"); return false; }
		if(vecLine[28]!="miss_rate"){Ex.Logger.Log("Role.csv中字段[miss_rate]位置不对应"); return false; }
		if(vecLine[29]!="critical_value"){Ex.Logger.Log("Role.csv中字段[critical_value]位置不对应"); return false; }
		if(vecLine[30]!="critical_rate"){Ex.Logger.Log("Role.csv中字段[critical_rate]位置不对应"); return false; }
		if(vecLine[31]!="tenacity_value"){Ex.Logger.Log("Role.csv中字段[tenacity_value]位置不对应"); return false; }
		if(vecLine[32]!="tenacity_rate"){Ex.Logger.Log("Role.csv中字段[tenacity_rate]位置不对应"); return false; }
		if(vecLine[33]!="dodge_value"){Ex.Logger.Log("Role.csv中字段[dodge_value]位置不对应"); return false; }
		if(vecLine[34]!="dodge_rate"){Ex.Logger.Log("Role.csv中字段[dodge_rate]位置不对应"); return false; }
		if(vecLine[35]!="penetrate_value"){Ex.Logger.Log("Role.csv中字段[penetrate_value]位置不对应"); return false; }
		if(vecLine[36]!="penetrate_rate"){Ex.Logger.Log("Role.csv中字段[penetrate_rate]位置不对应"); return false; }
		if(vecLine[37]!="miss_level"){Ex.Logger.Log("Role.csv中字段[miss_level]位置不对应"); return false; }
		if(vecLine[38]!="critical_level"){Ex.Logger.Log("Role.csv中字段[critical_level]位置不对应"); return false; }
		if(vecLine[39]!="dodge_level"){Ex.Logger.Log("Role.csv中字段[dodge_level]位置不对应"); return false; }
		if(vecLine[40]!="move_speed"){Ex.Logger.Log("Role.csv中字段[move_speed]位置不对应"); return false; }
		if(vecLine[41]!="physic_oppose"){Ex.Logger.Log("Role.csv中字段[physic_oppose]位置不对应"); return false; }
		if(vecLine[42]!="magic_oppose"){Ex.Logger.Log("Role.csv中字段[magic_oppose]位置不对应"); return false; }
		if(vecLine[43]!="physic_add"){Ex.Logger.Log("Role.csv中字段[physic_add]位置不对应"); return false; }
		if(vecLine[44]!="magic_add"){Ex.Logger.Log("Role.csv中字段[magic_add]位置不对应"); return false; }
		if(vecLine[45]!="scene_id"){Ex.Logger.Log("Role.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[46]!="posx"){Ex.Logger.Log("Role.csv中字段[posx]位置不对应"); return false; }
		if(vecLine[47]!="posz"){Ex.Logger.Log("Role.csv中字段[posz]位置不对应"); return false; }
		if(vecLine[48]!="direct"){Ex.Logger.Log("Role.csv中字段[direct]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)49)
			{
				return false;
			}
			RoleElement member = new RoleElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.race=Convert.ToInt32(vecLine[2]);
			member.occupation=Convert.ToInt32(vecLine[3]);
			member.gender=Convert.ToInt32(vecLine[4]);
			member.race_icon=vecLine[5];
			member.race_name=Convert.ToInt32(vecLine[6]);
			member.race_desc=Convert.ToInt32(vecLine[7]);
			member.occu_icon=vecLine[8];
			member.create_occu_icon=vecLine[9];
			member.occu_name=Convert.ToInt32(vecLine[10]);
			member.occu_desc=Convert.ToInt32(vecLine[11]);
			member.occu_evaluate=vecLine[12];
			member.model_id=Convert.ToInt32(vecLine[13]);
			member.strength=Convert.ToInt32(vecLine[14]);
			member.speed =Convert.ToInt32(vecLine[15]);
			member.agile=Convert.ToInt32(vecLine[16]);
			member.stamina=Convert.ToInt32(vecLine[17]);
			member.spirit=Convert.ToInt32(vecLine[18]);
			member.maxhp=Convert.ToInt32(vecLine[19]);
			member.maxmp=Convert.ToInt32(vecLine[20]);
			member.physic_attack=Convert.ToInt32(vecLine[21]);
			member.physic_defense=Convert.ToInt32(vecLine[22]);
			member.magic_attack=Convert.ToInt32(vecLine[23]);
			member.magic_defense=Convert.ToInt32(vecLine[24]);
			member.hit_value=Convert.ToInt32(vecLine[25]);
			member.hit_rate=Convert.ToInt32(vecLine[26]);
			member.miss_value=Convert.ToInt32(vecLine[27]);
			member.miss_rate=Convert.ToInt32(vecLine[28]);
			member.critical_value=Convert.ToInt32(vecLine[29]);
			member.critical_rate=Convert.ToInt32(vecLine[30]);
			member.tenacity_value=Convert.ToInt32(vecLine[31]);
			member.tenacity_rate=Convert.ToInt32(vecLine[32]);
			member.dodge_value=Convert.ToInt32(vecLine[33]);
			member.dodge_rate=Convert.ToInt32(vecLine[34]);
			member.penetrate_value=Convert.ToInt32(vecLine[35]);
			member.penetrate_rate=Convert.ToInt32(vecLine[36]);
			member.miss_level=Convert.ToInt32(vecLine[37]);
			member.critical_level=Convert.ToInt32(vecLine[38]);
			member.dodge_level=Convert.ToInt32(vecLine[39]);
			member.move_speed=Convert.ToInt32(vecLine[40]);
			member.physic_oppose=Convert.ToInt32(vecLine[41]);
			member.magic_oppose=Convert.ToInt32(vecLine[42]);
			member.physic_add=Convert.ToInt32(vecLine[43]);
			member.magic_add=Convert.ToInt32(vecLine[44]);
			member.scene_id=Convert.ToInt32(vecLine[45]);
			member.posx=Convert.ToSingle(vecLine[46]);
			member.posz=Convert.ToSingle(vecLine[47]);
			member.direct=Convert.ToSingle(vecLine[48]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
