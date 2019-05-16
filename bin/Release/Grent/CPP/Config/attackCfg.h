#ifndef __ATTACK_CONFIG_H
#define __ATTACK_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//攻击效果配置数据结构
struct AttackElement
{
	friend class AttackTable;
	int id;                      	//技能ID	
	string comment;              	//技能名称	仅策划用
	int effect_target;           	//技能生效目标 	1=自己 2=敌方单位 4=友方单位 如：5=自己+友方
	int cast_target;             	//技能施法目标	AOE类型attack生效区域基准点位置，单体技能无效，填0 0=对自己释放（无效） 1=对敌人施放（无效） 2=对自己&友方释放（无效） 3=以目标点为基准点释放 4=以自己为基准点释放
	int target_alive_status;     	//技能目标存活类型	0：技能只能对死亡目标释放 1：技能只能对活着的目标释放 2：会对死亡、存活的目标同时生效
	int max_target_count;        	//最大生效目标数	单体攻击填1，AOE填写区域内最大作用目标人数
	int ligic_id;                	//释放的逻辑	0=暂时无效 1=释放Buff 2=召唤小怪 3=释放子弹 4=释放陷阱
	vector<int> pars;            	//buff参数	buffID 释放逻辑-1，无效 释放逻辑1，伤害 释放逻辑2，延迟伤害 释放逻辑3，治疗 其他ID查看buff文档
	int attack_type;             	//攻击的类型	0:物理攻击, 1:法术攻击, 2:物理&法术攻击
	float attack_rate;           	//技能伤害系数	0=不计算伤害 1=100
	int attack_value;            	//技能伤害附加	技能伤害附加
	int rang_type;               	//攻击范围类型	0=目标 1=圆形 2=扇形 3=矩形 4=环形 5=反弹技能专用圆形 6=连环圆
	float rang_par1;             	//范围参数1	类型=0，无效 类型=1，半径 类型=2，半径 类型=3，长 类型=4，里圈半径 类型=5，半径 类型=6，半径
	float rang_par2;             	//范围参数2	类型=0，无效 类型=1，无效 类型=2，角度 类型=3，宽 类型=4，外圈半径 类型=5，无效 类型=6，无效
	float attackRange;           	//attack距离	attack距离子弹生成点的距离
	int summon_monster_amount;   	//召唤的小怪数量	
	vector<int> summon_monster_list1;	//召唤的小怪组1	召唤小怪1，从N个当中随机选取一个，用|分割
	vector<int> summon_monster_list2;	//召唤的小怪组2	召唤小怪2，从N个当中随机选取一个，用|分割
	vector<int> summon_monster_list3;	//召唤的小怪组3	召唤小怪3，从N个当中随机选取一个，用|分割
	vector<int> bullet_id;       	//子弹id	子弹ID或陷阱ID

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	AttackElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//攻击效果配置封装类
class AttackTable
{
	friend class TableData;
private:
	AttackTable(){}
	~AttackTable(){}
	map<int, AttackElement>	m_mapElements;
	vector<AttackElement>	m_vecAllElements;
	AttackElement m_emptyItem;
public:
	static AttackTable& Instance()
	{
		static AttackTable sInstance;
		return sInstance;
	}

	AttackElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<AttackElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("Attack.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Attack.bin", strTableContent ) )
		{
			printf_message("配置文件[Attack.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 20)
		{
			printf_message("Attack.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Attack.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Attack.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="effect_target"){printf_message("Attack.csv中字段[effect_target]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="cast_target"){printf_message("Attack.csv中字段[cast_target]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="target_alive_status"){printf_message("Attack.csv中字段[target_alive_status]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="max_target_count"){printf_message("Attack.csv中字段[max_target_count]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="ligic_id"){printf_message("Attack.csv中字段[ligic_id]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="pars"){printf_message("Attack.csv中字段[pars]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="attack_type"){printf_message("Attack.csv中字段[attack_type]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="attack_rate"){printf_message("Attack.csv中字段[attack_rate]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="attack_value"){printf_message("Attack.csv中字段[attack_value]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="rang_type"){printf_message("Attack.csv中字段[rang_type]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="rang_par1"){printf_message("Attack.csv中字段[rang_par1]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="rang_par2"){printf_message("Attack.csv中字段[rang_par2]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="attackRange"){printf_message("Attack.csv中字段[attackRange]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="summon_monster_amount"){printf_message("Attack.csv中字段[summon_monster_amount]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="summon_monster_list1"){printf_message("Attack.csv中字段[summon_monster_list1]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="summon_monster_list2"){printf_message("Attack.csv中字段[summon_monster_list2]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="summon_monster_list3"){printf_message("Attack.csv中字段[summon_monster_list3]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="bullet_id"){printf_message("Attack.csv中字段[bullet_id]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)20)
			{
				assert(false);
				return false;
			}
			AttackElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.effect_target=(int)atoi(vecLine[2].c_str());
			member.cast_target=(int)atoi(vecLine[3].c_str());
			member.target_alive_status=(int)atoi(vecLine[4].c_str());
			member.max_target_count=(int)atoi(vecLine[5].c_str());
			member.ligic_id=(int)atoi(vecLine[6].c_str());
			member.attack_type=(int)atoi(vecLine[8].c_str());
			member.attack_rate=(float)atof(vecLine[9].c_str());
			member.attack_value=(int)atoi(vecLine[10].c_str());
			member.rang_type=(int)atoi(vecLine[11].c_str());
			member.rang_par1=(float)atof(vecLine[12].c_str());
			member.rang_par2=(float)atof(vecLine[13].c_str());
			member.attackRange=(float)atof(vecLine[14].c_str());
			member.summon_monster_amount=(int)atoi(vecLine[15].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
