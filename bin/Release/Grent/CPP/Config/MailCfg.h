#ifndef __MAIL_CONFIG_H
#define __MAIL_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//邮件配置表配置数据结构
struct MailElement
{
	friend class MailTable;
	int id;                      	//邮件ID	邮件所对应的ID
	string comment;              	//阶级注释	策划用
	int platform_type;           	//平台类型	0安卓 1IOS （暂无）
	int mail_type;               	//邮件类型	0纯文本邮件 1道具发放类 3物品找回类（暂无） 4系统消息
	string mail_title;           	//邮件标题	
	string mail_short_title;     	//邮件省略标题	
	string sender;               	//邮件发件人	
	string call;                 	//称呼	
	string mail_body;            	//邮件正文	

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
	MailElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//邮件配置表配置封装类
class MailTable
{
	friend class TableData;
private:
	MailTable(){}
	~MailTable(){}
	map<int, MailElement>	m_mapElements;
	vector<MailElement>	m_vecAllElements;
	MailElement m_emptyItem;
public:
	static MailTable& Instance()
	{
		static MailTable sInstance;
		return sInstance;
	}

	MailElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<MailElement>&	GetAllElement()
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
		if( LoadConfigContent("Mail.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Mail.bin", strTableContent ) )
		{
			printf_message("配置文件[Mail.bin]未找到");
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
		if(vecLine.size() != 9)
		{
			printf_message("Mail.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Mail.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("Mail.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="platform_type"){printf_message("Mail.csv中字段[platform_type]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="mail_type"){printf_message("Mail.csv中字段[mail_type]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="mail_title"){printf_message("Mail.csv中字段[mail_title]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="mail_short_title"){printf_message("Mail.csv中字段[mail_short_title]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="sender"){printf_message("Mail.csv中字段[sender]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="call"){printf_message("Mail.csv中字段[call]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="mail_body"){printf_message("Mail.csv中字段[mail_body]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)9)
			{
				assert(false);
				return false;
			}
			MailElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.platform_type=(int)atoi(vecLine[2].c_str());
			member.mail_type=(int)atoi(vecLine[3].c_str());
			member.mail_title=vecLine[4];
			member.mail_short_title=vecLine[5];
			member.sender=vecLine[6];
			member.call=vecLine[7];
			member.mail_body=vecLine[8];

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
