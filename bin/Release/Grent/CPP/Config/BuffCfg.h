#ifndef __BUFF_CONFIG_H
#define __BUFF_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//效果配置数据结构
struct BuffElement
{
	friend class BuffTable;
	int id;                      	//数据索引	数据索引
	int buffID;                  	//对应的BuffID	仅程序用
	string descPars;             	//参数说明	仅说明
	string desc_type;            	//Buff效果	仅程序用
	string comment;              	//备注	仅策划用
	int oper;                    	//Buff关系	0=叠加 1=冲抵 2=免疫 3=共存
	int operPars;                	//关系参数	若叠加类=最大叠加次数（最小层数是1）
	int overTimed;               	//是否持续Buff	0=不走buff组关系，直接上 1=需要先判断buff组关系
	int continuance;             	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算 持续：-1，永久
	int interval;                	//间隔时间ms	间隔时间
	int mutexID;                 	//Buff组ID	-1表示跟谁都不是一组的
	string buffEffect;           	//buff特效	buff特效名称
	int buffMount;               	//buff特效挂载点	所有部位数字0-20
	string buffendEffect;        	//buff消失特效	buff消失特效名称
	int buffendMount;            	//buff消失特效挂载点	所有部位数字0-20
	int groupPriority;           	//组中优先级	0为最低
	vector<float> pars;          	//参数	具体参数说明见文档《BUFF系统》
	vector<int> pars_2;          	//参数_2	可触发Buff的Buff类型ID
	int isDebuff;                	//是否减益	1：减益debuff 0：增益buff
	int buff_delete;             	//buff删除时机	0：不删除 1：下线删除 2：场景删除 3=下线或切场景删除 4：死亡删除 7=下线、场景和死亡均删除
	int displayPriority;         	//buff显示优先级	填写>=0整数，用于图标、特效等显示优先级，数字越大优先级越高
	int buffNameId;              	//buff名称ID	对应stringBuff表中的文本ID
	int specialBuffNameId;       	//计时buff简述特殊名称ID	对应stringBuff表中的文本ID
	int descId;                  	//buff描述ID	对应stringBuff表中的文本ID
	string iconName;             	//图标名称	图标名称
	int is_tell_client;          	//是否告知客户端	0：否 1：是
	int buff_show_rule;          	//buff显示规则	0：全部不显示 1：闲置 2：显示图标 4：显示计时条 8：自然使专用BUFF 16：显示冒字 如：14=图标、计时条、自然使专用buff均显示
	string script;               	//脚本路径	脚本路径
	int is_show_icon;            	//是否显示buff图标	0：不显示 1：显示 默认为不显示
	int isShowSpecialBuff;       	//特殊buff计时条显示与否	1：显示 0：不显示
	int jump_delete;             	//跳场景时是否删除	0=不是 1=是

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
	BuffElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//效果配置封装类
class BuffTable
{
	friend class TableData;
private:
	BuffTable(){}
	~BuffTable(){}
	map<int, BuffElement>	m_mapElements;
	vector<BuffElement>	m_vecAllElements;
	BuffElement m_emptyItem;
public:
	static BuffTable& Instance()
	{
		static BuffTable sInstance;
		return sInstance;
	}

	BuffElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffElement>&	GetAllElement()
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
		if( LoadConfigContent("Buff.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Buff.bin", strTableContent ) )
		{
			printf_message("配置文件[Buff.bin]未找到");
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
		if(vecLine.size() != 31)
		{
			printf_message("Buff.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Buff.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="buffID"){printf_message("Buff.csv中字段[buffID]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="descPars"){printf_message("Buff.csv中字段[descPars]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc_type"){printf_message("Buff.csv中字段[desc_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="comment"){printf_message("Buff.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="oper"){printf_message("Buff.csv中字段[oper]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="operPars"){printf_message("Buff.csv中字段[operPars]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="overTimed"){printf_message("Buff.csv中字段[overTimed]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="continuance"){printf_message("Buff.csv中字段[continuance]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="interval"){printf_message("Buff.csv中字段[interval]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="mutexID"){printf_message("Buff.csv中字段[mutexID]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="buffEffect"){printf_message("Buff.csv中字段[buffEffect]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="buffMount"){printf_message("Buff.csv中字段[buffMount]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="buffendEffect"){printf_message("Buff.csv中字段[buffendEffect]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="buffendMount"){printf_message("Buff.csv中字段[buffendMount]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="groupPriority"){printf_message("Buff.csv中字段[groupPriority]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="pars"){printf_message("Buff.csv中字段[pars]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="pars_2"){printf_message("Buff.csv中字段[pars_2]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="isDebuff"){printf_message("Buff.csv中字段[isDebuff]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="buff_delete"){printf_message("Buff.csv中字段[buff_delete]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="displayPriority"){printf_message("Buff.csv中字段[displayPriority]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="buffNameId"){printf_message("Buff.csv中字段[buffNameId]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="specialBuffNameId"){printf_message("Buff.csv中字段[specialBuffNameId]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="descId"){printf_message("Buff.csv中字段[descId]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="iconName"){printf_message("Buff.csv中字段[iconName]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="is_tell_client"){printf_message("Buff.csv中字段[is_tell_client]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="buff_show_rule"){printf_message("Buff.csv中字段[buff_show_rule]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="script"){printf_message("Buff.csv中字段[script]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="is_show_icon"){printf_message("Buff.csv中字段[is_show_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="isShowSpecialBuff"){printf_message("Buff.csv中字段[isShowSpecialBuff]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="jump_delete"){printf_message("Buff.csv中字段[jump_delete]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)31)
			{
				assert(false);
				return false;
			}
			BuffElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.buffID=(int)atoi(vecLine[1].c_str());
			member.descPars=vecLine[2];
			member.desc_type=vecLine[3];
			member.comment=vecLine[4];
			member.oper=(int)atoi(vecLine[5].c_str());
			member.operPars=(int)atoi(vecLine[6].c_str());
			member.overTimed=(int)atoi(vecLine[7].c_str());
			member.continuance=(int)atoi(vecLine[8].c_str());
			member.interval=(int)atoi(vecLine[9].c_str());
			member.mutexID=(int)atoi(vecLine[10].c_str());
			member.buffEffect=vecLine[11];
			member.buffMount=(int)atoi(vecLine[12].c_str());
			member.buffendEffect=vecLine[13];
			member.buffendMount=(int)atoi(vecLine[14].c_str());
			member.groupPriority=(int)atoi(vecLine[15].c_str());
			member.isDebuff=(int)atoi(vecLine[18].c_str());
			member.buff_delete=(int)atoi(vecLine[19].c_str());
			member.displayPriority=(int)atoi(vecLine[20].c_str());
			member.buffNameId=(int)atoi(vecLine[21].c_str());
			member.specialBuffNameId=(int)atoi(vecLine[22].c_str());
			member.descId=(int)atoi(vecLine[23].c_str());
			member.iconName=vecLine[24];
			member.is_tell_client=(int)atoi(vecLine[25].c_str());
			member.buff_show_rule=(int)atoi(vecLine[26].c_str());
			member.script=vecLine[27];
			member.is_show_icon=(int)atoi(vecLine[28].c_str());
			member.isShowSpecialBuff=(int)atoi(vecLine[29].c_str());
			member.jump_delete=(int)atoi(vecLine[30].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
