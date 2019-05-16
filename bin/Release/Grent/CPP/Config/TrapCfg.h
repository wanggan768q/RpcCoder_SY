#ifndef __TRAP_CONFIG_H
#define __TRAP_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//陷阱表配置数据结构
struct TrapElement
{
	friend class TrapTable;
	int id;                      	//陷阱ID	陷阱ID
	string comment;              	//备注	备注
	int location_type;           	//生成陷阱位置类型	陷阱生成位置类型 0：读表生成 1：技能选择位置 2：技能目标位置 3：固定坐标位置 4：陷阱触发的陷阱
	int trap_count;              	//陷阱数量	生成陷阱的数量
	int generate_type;           	//生成陷阱类型	生成方式 0=平行 1=扇形
	float trap_gap;              	//生成陷阱间隔参数	如果生成方式是0，则填入间隔距离（m）； 如果生成方式是1，则填入角度。
	float generate_distance;     	//生成陷阱距离	生成距离
	int delay_time;              	//生成陷阱后attack/触发检测延迟	释放陷阱一定时间后，开始生效attack触发机制，单位：ms
	int duration;                	//陷阱持续时间	陷阱持续时间，单位：ms
	int interval;                	//陷阱效果触发间隔时间	触发间隔时间，单位：ms
	int max_trigger_count;       	//陷阱最大触发次数	最大有效触发attack次数，未击中目标的attack不计入次数统计
	string trap_model_name;      	//陷阱模型名称	模型名称或者特效名称
	string end_effect;           	//陷阱消失时播放特效	陷阱消失时播放的特效，没有为空
	float trigger_range;         	//触发半径	陷阱检测触碰圆形区域的半径，若和attack触发相同可填0，则按照attack区域形状持续进行脉冲 单位：m
	vector<int> attack_id_list;  	//attack的ID列表	陷阱触发效果的attackIdList,多个attack用连接符“|”连接
	int auto_trigger;            	//自动触发	0:没人进入区域，不会自动触发下一个陷阱 1:时间到了，自动触发下一个陷阱
	int next_trap_id;            	//下一个陷阱ID	陷阱触发后生成的下一个陷阱ID，当前陷阱消失，在当前位置生成新陷阱，无触发时，填0
	int is_disappear;            	//是否消失	达到最大触发次数后是否立即消失， 1 = 立即消失， 0 = 达到最大触发次数后会等到持续时间结束后再消失
	int hitOnce;                 	//是否只受到一次伤害	同一人在陷阱持续时间内，是否只受到一次伤害 1= 只受一次伤害 0 = 可受到多次伤害

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
	TrapElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//陷阱表配置封装类
class TrapTable
{
	friend class TableData;
private:
	TrapTable(){}
	~TrapTable(){}
	map<int, TrapElement>	m_mapElements;
	vector<TrapElement>	m_vecAllElements;
	TrapElement m_emptyItem;
public:
	static TrapTable& Instance()
	{
		static TrapTable sInstance;
		return sInstance;
	}

	TrapElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<TrapElement>&	GetAllElement()
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
		if( LoadConfigContent("Trap.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Trap.bin", strTableContent ) )
		{
			printf_message("配置文件[Trap.bin]未找到");
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
		if(vecLine.size() != 19)
		{
			printf_message("Trap.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Trap.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Trap.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="location_type"){printf_message("Trap.csv中字段[location_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="trap_count"){printf_message("Trap.csv中字段[trap_count]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="generate_type"){printf_message("Trap.csv中字段[generate_type]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="trap_gap"){printf_message("Trap.csv中字段[trap_gap]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="generate_distance"){printf_message("Trap.csv中字段[generate_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="delay_time"){printf_message("Trap.csv中字段[delay_time]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="duration"){printf_message("Trap.csv中字段[duration]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="interval"){printf_message("Trap.csv中字段[interval]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="max_trigger_count"){printf_message("Trap.csv中字段[max_trigger_count]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="trap_model_name"){printf_message("Trap.csv中字段[trap_model_name]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="end_effect"){printf_message("Trap.csv中字段[end_effect]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="trigger_range"){printf_message("Trap.csv中字段[trigger_range]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="attack_id_list"){printf_message("Trap.csv中字段[attack_id_list]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="auto_trigger"){printf_message("Trap.csv中字段[auto_trigger]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="next_trap_id"){printf_message("Trap.csv中字段[next_trap_id]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="is_disappear"){printf_message("Trap.csv中字段[is_disappear]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="hitOnce"){printf_message("Trap.csv中字段[hitOnce]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)19)
			{
				assert(false);
				return false;
			}
			TrapElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.location_type=(int)atoi(vecLine[2].c_str());
			member.trap_count=(int)atoi(vecLine[3].c_str());
			member.generate_type=(int)atoi(vecLine[4].c_str());
			member.trap_gap=(float)atof(vecLine[5].c_str());
			member.generate_distance=(float)atof(vecLine[6].c_str());
			member.delay_time=(int)atoi(vecLine[7].c_str());
			member.duration=(int)atoi(vecLine[8].c_str());
			member.interval=(int)atoi(vecLine[9].c_str());
			member.max_trigger_count=(int)atoi(vecLine[10].c_str());
			member.trap_model_name=vecLine[11];
			member.end_effect=vecLine[12];
			member.trigger_range=(float)atof(vecLine[13].c_str());
			member.auto_trigger=(int)atoi(vecLine[15].c_str());
			member.next_trap_id=(int)atoi(vecLine[16].c_str());
			member.is_disappear=(int)atoi(vecLine[17].c_str());
			member.hitOnce=(int)atoi(vecLine[18].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
