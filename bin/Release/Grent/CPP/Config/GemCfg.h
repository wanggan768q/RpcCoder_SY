#ifndef __GEM_CONFIG_H
#define __GEM_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝石表配置数据结构
struct GemElement
{
	friend class GemTable;
	int id;                      	//宝石ID	填写ID即可
	string comment;              	//注释	策划用
	int gem_type;                	//填写宝石大类名	填写文本ID
	int gem_level;               	//该宝石等级	填写宝石等级
	int gem_num;                 	//需要前1级多少个宝石	填写数量
	int gem_quick;               	//需要多少个1级宝石	填写数量
	int probability;             	//合成该宝石成功率	填写10即10%概率
	int gem_item_id;             	//保底道具ID	填写道具ID
	int gem_item_num;            	//是否需要保底道具	不需要写0，需要写数量
	int gem_loss;                	//不用保底道具合成失败扣除该宝石数量	填写0不扣除，填写1，失败扣1个
	string gem_mark;             	//宝石标示	在界面中显示的标示图案
	int part1;                   	//可镶嵌部位1	填写部位ID
	vector<int> property1;       	//属性1	填写属性ID
	vector<int> value1;          	//数值1	填写增加数值
	int part2;                   	//可镶嵌部位2	填写部位ID
	vector<int> property2;       	//属性2	填写属性ID
	vector<int> value2;          	//数值2	填写增加数值

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
	GemElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宝石表配置封装类
class GemTable
{
	friend class TableData;
private:
	GemTable(){}
	~GemTable(){}
	map<int, GemElement>	m_mapElements;
	vector<GemElement>	m_vecAllElements;
	GemElement m_emptyItem;
public:
	static GemTable& Instance()
	{
		static GemTable sInstance;
		return sInstance;
	}

	GemElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GemElement>&	GetAllElement()
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
		if( LoadConfigContent("Gem.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Gem.bin", strTableContent ) )
		{
			printf_message("配置文件[Gem.bin]未找到");
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
		if(vecLine.size() != 17)
		{
			printf_message("Gem.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Gem.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Gem.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="gem_type"){printf_message("Gem.csv中字段[gem_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="gem_level"){printf_message("Gem.csv中字段[gem_level]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="gem_num"){printf_message("Gem.csv中字段[gem_num]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="gem_quick"){printf_message("Gem.csv中字段[gem_quick]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="probability"){printf_message("Gem.csv中字段[probability]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="gem_item_id"){printf_message("Gem.csv中字段[gem_item_id]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="gem_item_num"){printf_message("Gem.csv中字段[gem_item_num]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="gem_loss"){printf_message("Gem.csv中字段[gem_loss]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="gem_mark"){printf_message("Gem.csv中字段[gem_mark]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="part1"){printf_message("Gem.csv中字段[part1]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="property1"){printf_message("Gem.csv中字段[property1]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="value1"){printf_message("Gem.csv中字段[value1]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="part2"){printf_message("Gem.csv中字段[part2]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="property2"){printf_message("Gem.csv中字段[property2]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="value2"){printf_message("Gem.csv中字段[value2]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)17)
			{
				assert(false);
				return false;
			}
			GemElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.gem_type=(int)atoi(vecLine[2].c_str());
			member.gem_level=(int)atoi(vecLine[3].c_str());
			member.gem_num=(int)atoi(vecLine[4].c_str());
			member.gem_quick=(int)atoi(vecLine[5].c_str());
			member.probability=(int)atoi(vecLine[6].c_str());
			member.gem_item_id=(int)atoi(vecLine[7].c_str());
			member.gem_item_num=(int)atoi(vecLine[8].c_str());
			member.gem_loss=(int)atoi(vecLine[9].c_str());
			member.gem_mark=vecLine[10];
			member.part1=(int)atoi(vecLine[11].c_str());
			member.part2=(int)atoi(vecLine[14].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
