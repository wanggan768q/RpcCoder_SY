using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//攻击效果配置数据类
public class AttackElement
{
	public int id;               	//技能ID	
	public string comment;       	//技能名称	仅策划用
	public int effect_target;    	//技能生效目标 	1=自己 2=敌方单位 4=友方单位 如：5=自己+友方
	public int cast_target;      	//技能施法目标	AOE类型attack生效区域基准点位置，单体技能无效，填0 0=对自己释放（无效） 1=对敌人施放（无效） 2=对自己&友方释放（无效） 3=以目标点为基准点释放 4=以自己为基准点释放
	public int target_alive_status;	//技能目标存活类型	0：技能只能对死亡目标释放 1：技能只能对活着的目标释放 2：会对死亡、存活的目标同时生效
	public int max_target_count; 	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	public int ligic_id;         	//释放的逻辑	0=暂时无效 1=释放Buff 2=召唤小怪 3=释放子弹 4=释放陷阱
	public li pars;              	//buff参数	buffID 释放逻辑-1，无效 释放逻辑1，伤害 释放逻辑2，延迟伤害 释放逻辑3，治疗 其他ID查看buff文档
	public int attack_type;      	//攻击的类型	0:物理攻击, 1:法术攻击, 2:物理&法术攻击
	public float attack_rate;    	//技能伤害系数	0=不计算伤害 1=100
	public int attack_value;     	//技能伤害附加	技能伤害附加
	public int rang_type;        	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	public float rang_par1;      	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	public float rang_par2;      	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	public float attackRange;    	//attack距离	attack距离子弹生成点的距离
	public int summon_monster_amount;	//召唤的小怪数量	
	public li summon_monster_list1;	//召唤的小怪组1	召唤小怪1，从N个当中随机选取一个，用|分割
	public li summon_monster_list2;	//召唤的小怪组2	召唤小怪2，从N个当中随机选取一个，用|分割
	public li summon_monster_list3;	//召唤的小怪组3	召唤小怪3，从N个当中随机选取一个，用|分割
	public li bullet_id;         	//子弹id	子弹ID或陷阱ID

	public bool IsValidate = false;
	public AttackElement()
	{
		id = -1;
	}
};

//攻击效果配置封装类
public class AttackTable
{

	private AttackTable()
	{
		m_mapElements = new Dictionary<int, AttackElement>();
		m_emptyItem = new AttackElement();
		m_vecAllElements = new List<AttackElement>();
	}
	private Dictionary<int, AttackElement> m_mapElements = null;
	private List<AttackElement>	m_vecAllElements = null;
	private AttackElement m_emptyItem = null;
	private static AttackTable sInstance = null;

	public static AttackTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AttackTable();
			return sInstance;
		}
	}

	public AttackElement GetElement(int key)
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

  public List<AttackElement> GetAllElement(Predicate<AttackElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Attack.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Attack.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Attack.bin]未找到");
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
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("Attack.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Attack.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Attack.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="effect_target"){Ex.Logger.Log("Attack.csv中字段[effect_target]位置不对应"); return false; }
		if(vecLine[3]!="cast_target"){Ex.Logger.Log("Attack.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[4]!="target_alive_status"){Ex.Logger.Log("Attack.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[5]!="max_target_count"){Ex.Logger.Log("Attack.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[6]!="ligic_id"){Ex.Logger.Log("Attack.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[7]!="pars"){Ex.Logger.Log("Attack.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("Attack.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="attack_rate"){Ex.Logger.Log("Attack.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[10]!="attack_value"){Ex.Logger.Log("Attack.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[11]!="rang_type"){Ex.Logger.Log("Attack.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[12]!="rang_par1"){Ex.Logger.Log("Attack.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[13]!="rang_par2"){Ex.Logger.Log("Attack.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[14]!="attackRange"){Ex.Logger.Log("Attack.csv中字段[attackRange]位置不对应"); return false; }
		if(vecLine[15]!="summon_monster_amount"){Ex.Logger.Log("Attack.csv中字段[summon_monster_amount]位置不对应"); return false; }
		if(vecLine[16]!="summon_monster_list1"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list1]位置不对应"); return false; }
		if(vecLine[17]!="summon_monster_list2"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list2]位置不对应"); return false; }
		if(vecLine[18]!="summon_monster_list3"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list3]位置不对应"); return false; }
		if(vecLine[19]!="bullet_id"){Ex.Logger.Log("Attack.csv中字段[bullet_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AttackElement member = new AttackElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.cast_target );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.target_alive_status );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.max_target_count );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.ligic_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attack_rate);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.attack_value );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rang_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par1);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.rang_par2);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.attackRange);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.summon_monster_amount );
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.summon_monster_list3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.bullet_id);

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
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("Attack.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Attack.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Attack.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="effect_target"){Ex.Logger.Log("Attack.csv中字段[effect_target]位置不对应"); return false; }
		if(vecLine[3]!="cast_target"){Ex.Logger.Log("Attack.csv中字段[cast_target]位置不对应"); return false; }
		if(vecLine[4]!="target_alive_status"){Ex.Logger.Log("Attack.csv中字段[target_alive_status]位置不对应"); return false; }
		if(vecLine[5]!="max_target_count"){Ex.Logger.Log("Attack.csv中字段[max_target_count]位置不对应"); return false; }
		if(vecLine[6]!="ligic_id"){Ex.Logger.Log("Attack.csv中字段[ligic_id]位置不对应"); return false; }
		if(vecLine[7]!="pars"){Ex.Logger.Log("Attack.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[8]!="attack_type"){Ex.Logger.Log("Attack.csv中字段[attack_type]位置不对应"); return false; }
		if(vecLine[9]!="attack_rate"){Ex.Logger.Log("Attack.csv中字段[attack_rate]位置不对应"); return false; }
		if(vecLine[10]!="attack_value"){Ex.Logger.Log("Attack.csv中字段[attack_value]位置不对应"); return false; }
		if(vecLine[11]!="rang_type"){Ex.Logger.Log("Attack.csv中字段[rang_type]位置不对应"); return false; }
		if(vecLine[12]!="rang_par1"){Ex.Logger.Log("Attack.csv中字段[rang_par1]位置不对应"); return false; }
		if(vecLine[13]!="rang_par2"){Ex.Logger.Log("Attack.csv中字段[rang_par2]位置不对应"); return false; }
		if(vecLine[14]!="attackRange"){Ex.Logger.Log("Attack.csv中字段[attackRange]位置不对应"); return false; }
		if(vecLine[15]!="summon_monster_amount"){Ex.Logger.Log("Attack.csv中字段[summon_monster_amount]位置不对应"); return false; }
		if(vecLine[16]!="summon_monster_list1"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list1]位置不对应"); return false; }
		if(vecLine[17]!="summon_monster_list2"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list2]位置不对应"); return false; }
		if(vecLine[18]!="summon_monster_list3"){Ex.Logger.Log("Attack.csv中字段[summon_monster_list3]位置不对应"); return false; }
		if(vecLine[19]!="bullet_id"){Ex.Logger.Log("Attack.csv中字段[bullet_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)20)
			{
				return false;
			}
			AttackElement member = new AttackElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.effect_target=Convert.ToInt32(vecLine[2]);
			member.cast_target=Convert.ToInt32(vecLine[3]);
			member.target_alive_status=Convert.ToInt32(vecLine[4]);
			member.max_target_count=Convert.ToInt32(vecLine[5]);
			member.ligic_id=Convert.ToInt32(vecLine[6]);
			member.pars=vecLine[7];
			member.attack_type=Convert.ToInt32(vecLine[8]);
			member.attack_rate=Convert.ToSingle(vecLine[9]);
			member.attack_value=Convert.ToInt32(vecLine[10]);
			member.rang_type=Convert.ToInt32(vecLine[11]);
			member.rang_par1=Convert.ToSingle(vecLine[12]);
			member.rang_par2=Convert.ToSingle(vecLine[13]);
			member.attackRange=Convert.ToSingle(vecLine[14]);
			member.summon_monster_amount=Convert.ToInt32(vecLine[15]);
			member.summon_monster_list1=vecLine[16];
			member.summon_monster_list2=vecLine[17];
			member.summon_monster_list3=vecLine[18];
			member.bullet_id=vecLine[19];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
