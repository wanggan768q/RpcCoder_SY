#ifndef __GEMINSERT_CONFIG_H
#define __GEMINSERT_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//宝石镶嵌表配置数据结构
struct GeminsertElement
{
	friend class GeminsertTable;
	int id;                      	//可镶嵌部位	填写ID即可
	string comment;              	//注释	策划用
	int name;                    	//部位名	填写文本ID
	int part;                    	//对应装备部位	填写ID
	string part_icon;            	//装备部位图标	填写图标名
	vector<int> part_gem;        	//装备上可镶嵌的宝石	填写宝石ID
	int part1_needlv;            	//槽位解锁等级	填写等级即可
	int part1_type;              	//0自动解锁1手动解锁	填1或0
	vector<int> part1_unlock;    	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	int part2_needlv;            	//槽位解锁等级	填写等级即可
	int part2_type;              	//0自动解锁1手动解锁	填1或0
	vector<int> part2_unlock;    	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量
	int part3_needlv;            	//槽位解锁等级	填写等级即可
	int part3_type;              	//0自动解锁1手动解锁	填1或0
	vector<int> part3_unlock;    	//解锁是否需要货币	货币类型币类型（0银币1金币2钻3绑钻）|货币数量

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
	GeminsertElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//宝石镶嵌表配置封装类
class GeminsertTable
{
	friend class TableData;
private:
	GeminsertTable(){}
	~GeminsertTable(){}
	map<int, GeminsertElement>	m_mapElements;
	vector<GeminsertElement>	m_vecAllElements;
	GeminsertElement m_emptyItem;
public:
	static GeminsertTable& Instance()
	{
		static GeminsertTable sInstance;
		return sInstance;
	}

	GeminsertElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GeminsertElement>&	GetAllElement()
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
		if( LoadConfigContent("Geminsert.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Geminsert.bin", strTableContent ) )
		{
			printf_message("配置文件[Geminsert.bin]未找到");
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
		if(vecLine.size() != 15)
		{
			printf_message("Geminsert.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Geminsert.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Geminsert.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("Geminsert.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="part"){printf_message("Geminsert.csv中字段[part]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="part_icon"){printf_message("Geminsert.csv中字段[part_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="part_gem"){printf_message("Geminsert.csv中字段[part_gem]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="part1_needlv"){printf_message("Geminsert.csv中字段[part1_needlv]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="part1_type"){printf_message("Geminsert.csv中字段[part1_type]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="part1_unlock"){printf_message("Geminsert.csv中字段[part1_unlock]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="part2_needlv"){printf_message("Geminsert.csv中字段[part2_needlv]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="part2_type"){printf_message("Geminsert.csv中字段[part2_type]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="part2_unlock"){printf_message("Geminsert.csv中字段[part2_unlock]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="part3_needlv"){printf_message("Geminsert.csv中字段[part3_needlv]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="part3_type"){printf_message("Geminsert.csv中字段[part3_type]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="part3_unlock"){printf_message("Geminsert.csv中字段[part3_unlock]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)15)
			{
				assert(false);
				return false;
			}
			GeminsertElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.name=(int)atoi(vecLine[2].c_str());
			member.part=(int)atoi(vecLine[3].c_str());
			member.part_icon=vecLine[4];
			member.part1_needlv=(int)atoi(vecLine[6].c_str());
			member.part1_type=(int)atoi(vecLine[7].c_str());
			member.part2_needlv=(int)atoi(vecLine[9].c_str());
			member.part2_type=(int)atoi(vecLine[10].c_str());
			member.part3_needlv=(int)atoi(vecLine[12].c_str());
			member.part3_type=(int)atoi(vecLine[13].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
