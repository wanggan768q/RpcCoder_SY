#ifndef __SYSTEMPREVIEW_CONFIG_H
#define __SYSTEMPREVIEW_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//系统预览配置数据结构
struct SystemPreviewElement
{
	friend class SystemPreviewTable;
	int id;                      	//条目id	该系统的索引id
	string comment;              	//注释	该预览的内容
	int unlock_lv;               	//解锁等级	该系统解锁的等级
	int system_name;             	//预告功能名称	系统的名称文本
	int system_desc;             	//预告功能描述	系统的描述文本
	string system_icon;          	//系统图标	显示在HUD上的预告图标
	string preview_pic;          	//预告功能图片	显示在系统预告面板的图片

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
	SystemPreviewElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//系统预览配置封装类
class SystemPreviewTable
{
	friend class TableData;
private:
	SystemPreviewTable(){}
	~SystemPreviewTable(){}
	map<int, SystemPreviewElement>	m_mapElements;
	vector<SystemPreviewElement>	m_vecAllElements;
	SystemPreviewElement m_emptyItem;
public:
	static SystemPreviewTable& Instance()
	{
		static SystemPreviewTable sInstance;
		return sInstance;
	}

	SystemPreviewElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SystemPreviewElement>&	GetAllElement()
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
		if( LoadConfigContent("SystemPreview.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("SystemPreview.bin", strTableContent ) )
		{
			printf_message("配置文件[SystemPreview.bin]未找到");
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
		if(vecLine.size() != 7)
		{
			printf_message("SystemPreview.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("SystemPreview.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("SystemPreview.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="unlock_lv"){printf_message("SystemPreview.csv中字段[unlock_lv]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="system_name"){printf_message("SystemPreview.csv中字段[system_name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="system_desc"){printf_message("SystemPreview.csv中字段[system_desc]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="system_icon"){printf_message("SystemPreview.csv中字段[system_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="preview_pic"){printf_message("SystemPreview.csv中字段[preview_pic]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)7)
			{
				assert(false);
				return false;
			}
			SystemPreviewElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.unlock_lv=(int)atoi(vecLine[2].c_str());
			member.system_name=(int)atoi(vecLine[3].c_str());
			member.system_desc=(int)atoi(vecLine[4].c_str());
			member.system_icon=vecLine[5];
			member.preview_pic=vecLine[6];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
