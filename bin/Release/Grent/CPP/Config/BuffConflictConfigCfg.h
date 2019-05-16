#ifndef __BUFFCONFLICTCONFIG_CONFIG_H
#define __BUFFCONFLICTCONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//Buff组关系配置数据结构
struct BuffConflictConfigElement
{
	friend class BuffConflictConfigTable;
	int id;                      	//组id	组id 必须保证ID 是顺序的
	string desc;                 	//组名	仅策划用 矩阵行表示已存在buff 矩阵列表示新加buff
	string group;                	//组标识	1=冲抵, 2=免疫, 3=共存
	int g1;                      	//驱散	驱散
	int g2;                      	//净化	净化
	int g3;                      	//可驱散晕眩	可驱散晕眩
	int g4;                      	//可驱散冰冻	可驱散冰冻
	int g5;                      	//可驱散沉默	可驱散沉默
	int g6;                      	//可驱散加速	可驱散加速
	int g7;                      	//可驱散减速	可驱散减速
	int g8;                      	//可驱散定身	可驱散定身
	int g9;                      	//可驱散吸血	可驱散吸血
	int g10;                     	//可驱散增加属性Buff	可驱散增加属性Buff
	int g11;                     	//可驱散回血	可驱散回血
	int g12;                     	//可驱散流血	可驱散扣血
	int g13;                     	//可驱散中毒	可驱散中毒
	int g14;                     	//可驱散灼烧	可驱散灼烧
	int g15;                     	//可驱散禁疗	可驱散禁疗
	int g16;                     	//Boss霸体	Boss霸体
	int g17;                     	//免疫	免疫
	int g18;                     	//无敌	无敌
	int g19;                     	//专精Buff1	专精Buff1
	int g20;                     	//专精Buff2	专精Buff2
	int g21;                     	//弓手雷电祝福	弓手雷电祝福
	int g22;                     	//弓手自然祝福	弓手自然祝福
	int g23;                     	//弓手寒冰祝福	弓手寒冰祝福
	int g24;                     	//弓手飓风祝福	弓手飓风祝福
	int g25;                     	//光辉剑雨	光辉剑雨
	int g26;                     	//临时霸体	临时霸体
	int g27;                     	//临时击飞、击退、拉拽	临时击飞、击退、拉拽
	int g28;                     	//不可驱散晕眩	不可驱散晕眩
	int g29;                     	//不可驱散冰冻	不可驱散冰冻
	int g30;                     	//不可驱散沉默	不可驱散沉默
	int g31;                     	//不可驱散加速	不可驱散加速
	int g32;                     	//不可驱散减速	不可驱散减速
	int g33;                     	//不可驱散定身	不可驱散定身
	int g34;                     	//不可驱散吸血	不可驱散吸血
	int g35;                     	//坐骑Buff	坐骑Buff
	int g36;                     	//宠物Buff	宠物Buff
	int g37;                     	//光环触发_生命值	光环触发_生命值
	int g38;                     	//光环触发_物理攻击	光环触发_物理攻击
	int g39;                     	//光环触发_物理防御	光环触发_物理防御
	int g40;                     	//光环触发_魔法攻击	光环触发_魔法攻击
	int g41;                     	//光环触发_魔法防御	光环触发_魔法防御
	int g42;                     	//光环触发_暴击值	光环触发_暴击值
	int g43;                     	//光环触发_韧性值	光环触发_韧性值
	int g44;                     	//光环触发_穿透值	光环触发_穿透值
	int g45;                     	//光环触发_格挡值	光环触发_格挡值
	int g46;                     	//攻击事件触发_几率增加物理攻击	攻击事件触发_几率增加物理攻击
	int g47;                     	//攻击事件触发_几率增加魔法攻击	攻击事件触发_几率增加魔法攻击
	int g48;                     	//攻击事件触发_几率增加暴击	攻击事件触发_几率增加暴击
	int g49;                     	//攻击事件触发_几率增加穿透	攻击事件触发_几率增加穿透
	int g50;                     	//防御事件触发_几率增加生命	防御事件触发_几率增加生命
	int g51;                     	//防御事件触发_几率增加物理防御	防御事件触发_几率增加物理防御
	int g52;                     	//防御事件触发_几率增加魔法防御	防御事件触发_几率增加魔法防御
	int g53;                     	//防御事件触发_几率韧性	防御事件触发_几率韧性
	int g54;                     	//防御事件触发_几率格挡	防御事件触发_几率格挡
	vector<int> allgroup;        	//合并	公式不要手填！！！

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
	BuffConflictConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//Buff组关系配置封装类
class BuffConflictConfigTable
{
	friend class TableData;
private:
	BuffConflictConfigTable(){}
	~BuffConflictConfigTable(){}
	map<int, BuffConflictConfigElement>	m_mapElements;
	vector<BuffConflictConfigElement>	m_vecAllElements;
	BuffConflictConfigElement m_emptyItem;
public:
	static BuffConflictConfigTable& Instance()
	{
		static BuffConflictConfigTable sInstance;
		return sInstance;
	}

	BuffConflictConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<BuffConflictConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("BuffConflictConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("BuffConflictConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[BuffConflictConfig.bin]未找到");
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
		if(vecLine.size() != 58)
		{
			printf_message("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("BuffConflictConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="desc"){printf_message("BuffConflictConfig.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="group"){printf_message("BuffConflictConfig.csv中字段[group]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="g1"){printf_message("BuffConflictConfig.csv中字段[g1]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="g2"){printf_message("BuffConflictConfig.csv中字段[g2]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="g3"){printf_message("BuffConflictConfig.csv中字段[g3]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="g4"){printf_message("BuffConflictConfig.csv中字段[g4]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="g5"){printf_message("BuffConflictConfig.csv中字段[g5]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="g6"){printf_message("BuffConflictConfig.csv中字段[g6]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="g7"){printf_message("BuffConflictConfig.csv中字段[g7]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="g8"){printf_message("BuffConflictConfig.csv中字段[g8]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="g9"){printf_message("BuffConflictConfig.csv中字段[g9]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="g10"){printf_message("BuffConflictConfig.csv中字段[g10]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="g11"){printf_message("BuffConflictConfig.csv中字段[g11]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="g12"){printf_message("BuffConflictConfig.csv中字段[g12]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="g13"){printf_message("BuffConflictConfig.csv中字段[g13]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="g14"){printf_message("BuffConflictConfig.csv中字段[g14]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="g15"){printf_message("BuffConflictConfig.csv中字段[g15]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="g16"){printf_message("BuffConflictConfig.csv中字段[g16]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="g17"){printf_message("BuffConflictConfig.csv中字段[g17]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="g18"){printf_message("BuffConflictConfig.csv中字段[g18]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="g19"){printf_message("BuffConflictConfig.csv中字段[g19]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="g20"){printf_message("BuffConflictConfig.csv中字段[g20]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="g21"){printf_message("BuffConflictConfig.csv中字段[g21]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="g22"){printf_message("BuffConflictConfig.csv中字段[g22]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="g23"){printf_message("BuffConflictConfig.csv中字段[g23]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="g24"){printf_message("BuffConflictConfig.csv中字段[g24]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="g25"){printf_message("BuffConflictConfig.csv中字段[g25]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="g26"){printf_message("BuffConflictConfig.csv中字段[g26]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="g27"){printf_message("BuffConflictConfig.csv中字段[g27]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="g28"){printf_message("BuffConflictConfig.csv中字段[g28]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="g29"){printf_message("BuffConflictConfig.csv中字段[g29]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="g30"){printf_message("BuffConflictConfig.csv中字段[g30]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="g31"){printf_message("BuffConflictConfig.csv中字段[g31]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="g32"){printf_message("BuffConflictConfig.csv中字段[g32]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="g33"){printf_message("BuffConflictConfig.csv中字段[g33]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="g34"){printf_message("BuffConflictConfig.csv中字段[g34]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="g35"){printf_message("BuffConflictConfig.csv中字段[g35]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="g36"){printf_message("BuffConflictConfig.csv中字段[g36]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="g37"){printf_message("BuffConflictConfig.csv中字段[g37]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="g38"){printf_message("BuffConflictConfig.csv中字段[g38]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="g39"){printf_message("BuffConflictConfig.csv中字段[g39]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="g40"){printf_message("BuffConflictConfig.csv中字段[g40]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="g41"){printf_message("BuffConflictConfig.csv中字段[g41]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="g42"){printf_message("BuffConflictConfig.csv中字段[g42]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="g43"){printf_message("BuffConflictConfig.csv中字段[g43]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="g44"){printf_message("BuffConflictConfig.csv中字段[g44]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="g45"){printf_message("BuffConflictConfig.csv中字段[g45]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="g46"){printf_message("BuffConflictConfig.csv中字段[g46]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="g47"){printf_message("BuffConflictConfig.csv中字段[g47]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="g48"){printf_message("BuffConflictConfig.csv中字段[g48]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="g49"){printf_message("BuffConflictConfig.csv中字段[g49]位置不对应 ");assert(false); return false; }
		if(vecLine[52]!="g50"){printf_message("BuffConflictConfig.csv中字段[g50]位置不对应 ");assert(false); return false; }
		if(vecLine[53]!="g51"){printf_message("BuffConflictConfig.csv中字段[g51]位置不对应 ");assert(false); return false; }
		if(vecLine[54]!="g52"){printf_message("BuffConflictConfig.csv中字段[g52]位置不对应 ");assert(false); return false; }
		if(vecLine[55]!="g53"){printf_message("BuffConflictConfig.csv中字段[g53]位置不对应 ");assert(false); return false; }
		if(vecLine[56]!="g54"){printf_message("BuffConflictConfig.csv中字段[g54]位置不对应 ");assert(false); return false; }
		if(vecLine[57]!="allgroup"){printf_message("BuffConflictConfig.csv中字段[allgroup]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)58)
			{
				assert(false);
				return false;
			}
			BuffConflictConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.desc=vecLine[1];
			member.group=vecLine[2];
			member.g1=(int)atoi(vecLine[3].c_str());
			member.g2=(int)atoi(vecLine[4].c_str());
			member.g3=(int)atoi(vecLine[5].c_str());
			member.g4=(int)atoi(vecLine[6].c_str());
			member.g5=(int)atoi(vecLine[7].c_str());
			member.g6=(int)atoi(vecLine[8].c_str());
			member.g7=(int)atoi(vecLine[9].c_str());
			member.g8=(int)atoi(vecLine[10].c_str());
			member.g9=(int)atoi(vecLine[11].c_str());
			member.g10=(int)atoi(vecLine[12].c_str());
			member.g11=(int)atoi(vecLine[13].c_str());
			member.g12=(int)atoi(vecLine[14].c_str());
			member.g13=(int)atoi(vecLine[15].c_str());
			member.g14=(int)atoi(vecLine[16].c_str());
			member.g15=(int)atoi(vecLine[17].c_str());
			member.g16=(int)atoi(vecLine[18].c_str());
			member.g17=(int)atoi(vecLine[19].c_str());
			member.g18=(int)atoi(vecLine[20].c_str());
			member.g19=(int)atoi(vecLine[21].c_str());
			member.g20=(int)atoi(vecLine[22].c_str());
			member.g21=(int)atoi(vecLine[23].c_str());
			member.g22=(int)atoi(vecLine[24].c_str());
			member.g23=(int)atoi(vecLine[25].c_str());
			member.g24=(int)atoi(vecLine[26].c_str());
			member.g25=(int)atoi(vecLine[27].c_str());
			member.g26=(int)atoi(vecLine[28].c_str());
			member.g27=(int)atoi(vecLine[29].c_str());
			member.g28=(int)atoi(vecLine[30].c_str());
			member.g29=(int)atoi(vecLine[31].c_str());
			member.g30=(int)atoi(vecLine[32].c_str());
			member.g31=(int)atoi(vecLine[33].c_str());
			member.g32=(int)atoi(vecLine[34].c_str());
			member.g33=(int)atoi(vecLine[35].c_str());
			member.g34=(int)atoi(vecLine[36].c_str());
			member.g35=(int)atoi(vecLine[37].c_str());
			member.g36=(int)atoi(vecLine[38].c_str());
			member.g37=(int)atoi(vecLine[39].c_str());
			member.g38=(int)atoi(vecLine[40].c_str());
			member.g39=(int)atoi(vecLine[41].c_str());
			member.g40=(int)atoi(vecLine[42].c_str());
			member.g41=(int)atoi(vecLine[43].c_str());
			member.g42=(int)atoi(vecLine[44].c_str());
			member.g43=(int)atoi(vecLine[45].c_str());
			member.g44=(int)atoi(vecLine[46].c_str());
			member.g45=(int)atoi(vecLine[47].c_str());
			member.g46=(int)atoi(vecLine[48].c_str());
			member.g47=(int)atoi(vecLine[49].c_str());
			member.g48=(int)atoi(vecLine[50].c_str());
			member.g49=(int)atoi(vecLine[51].c_str());
			member.g50=(int)atoi(vecLine[52].c_str());
			member.g51=(int)atoi(vecLine[53].c_str());
			member.g52=(int)atoi(vecLine[54].c_str());
			member.g53=(int)atoi(vecLine[55].c_str());
			member.g54=(int)atoi(vecLine[56].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
