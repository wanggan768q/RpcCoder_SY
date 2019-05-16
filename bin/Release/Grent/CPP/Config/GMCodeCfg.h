#ifndef __GMCODE_CONFIG_H
#define __GMCODE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//GM指令配置数据结构
struct GMCodeElement
{
	friend class GMCodeTable;
	int id;                      	//指令id	序号
	string  code;                	//指令名称	值 需要服务器处理的前缀为. 只需要客户端处理的前缀为/
	string name;                 	//中文名称	描述
	string desc;                 	//功能说明	策划使用
	int param1;                  	//指令参数1	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param2;                  	//指令参数2	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param3;                  	//指令参数3	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int param4;                  	//指令参数4	0.INT 1.FLOAT 2.STRING 3.LI 4.LF 5.LS
	int code_catalog;            	//指令分类	0.未分类 1.角色 2.移动 3.战斗 4.其它
	string param_example;        	//参数解释	
	string param_desc;           	//参数说明	
	string comment;              	//其他信息	

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
	GMCodeElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//GM指令配置封装类
class GMCodeTable
{
	friend class TableData;
private:
	GMCodeTable(){}
	~GMCodeTable(){}
	map<int, GMCodeElement>	m_mapElements;
	vector<GMCodeElement>	m_vecAllElements;
	GMCodeElement m_emptyItem;
public:
	static GMCodeTable& Instance()
	{
		static GMCodeTable sInstance;
		return sInstance;
	}

	GMCodeElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<GMCodeElement>&	GetAllElement()
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
		if( LoadConfigContent("GMCode.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("GMCode.bin", strTableContent ) )
		{
			printf_message("配置文件[GMCode.bin]未找到");
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
		if(vecLine.size() != 12)
		{
			printf_message("GMCode.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("GMCode.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!=" code"){printf_message("GMCode.csv中字段[ code]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="name"){printf_message("GMCode.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="desc"){printf_message("GMCode.csv中字段[desc]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="param1"){printf_message("GMCode.csv中字段[param1]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="param2"){printf_message("GMCode.csv中字段[param2]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="param3"){printf_message("GMCode.csv中字段[param3]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="param4"){printf_message("GMCode.csv中字段[param4]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="code_catalog"){printf_message("GMCode.csv中字段[code_catalog]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="param_example"){printf_message("GMCode.csv中字段[param_example]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="param_desc"){printf_message("GMCode.csv中字段[param_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="comment"){printf_message("GMCode.csv中字段[comment]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)12)
			{
				assert(false);
				return false;
			}
			GMCodeElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member. code=vecLine[1];
			member.name=vecLine[2];
			member.desc=vecLine[3];
			member.param1=(int)atoi(vecLine[4].c_str());
			member.param2=(int)atoi(vecLine[5].c_str());
			member.param3=(int)atoi(vecLine[6].c_str());
			member.param4=(int)atoi(vecLine[7].c_str());
			member.code_catalog=(int)atoi(vecLine[8].c_str());
			member.param_example=vecLine[9];
			member.param_desc=vecLine[10];
			member.comment=vecLine[11];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
