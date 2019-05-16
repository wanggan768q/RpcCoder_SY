#ifndef __BUFFTYPE_CONFIG_H
#define __BUFFTYPE_CONFIG_H


#include "Logger.h"
#include "CommonDefine.h"
#include "DK_Assertx.h"



#include <vector>
#include <string>
#include <unordered_map>

#include "jsoncpp/json.h"
#include <functional>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//Buff冒字显示配置数据结构
struct BuffTypeElement
{
	friend class BuffTypeTable;
	int id;                      	//对应的BuffID	对应的BuffID
	string desc;                 	//参数说明	仅说明
	int desc_id;                 	//StringBuff_buff_id	StringBuff_buff_id
	string res;                  	//资源名称	资源名称

private:

public:

	BuffTypeElement()
	{
		id = -1;
		
	}
};

//Buff冒字显示配置封装类
class BuffTypeTable
{
	public:
	typedef unordered_map<int, BuffTypeElement*> MapElementMap;
	typedef vector<BuffTypeElement> vec_type;
	typedef std::function<void()> ReloadCallback;
	typedef vector<ReloadCallback> reload_vec_type;
private:
	BuffTypeTable(){}
	~BuffTypeTable(){}
	
	MapElementMap	m_mapElements;
	vector<BuffTypeElement>	m_vecAllElements;
	reload_vec_type m_vReLoadCb;

public:
	friend class TableData;
	static BuffTypeTable& Instance()
	{
		static BuffTypeTable sInstance;
		return sInstance;
	}

	void RegisterReLoadCb(const ReloadCallback &cb)
	{
		m_vReLoadCb.push_back(cb);
	}
	
	const BuffTypeElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			return NULL;
		}
		return it->second;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vec_type&	GetAllElement()
	{
		return m_vecAllElements;
	}
	bool Load()
	{

		return LoadJson("BuffType.json");		
	}

	void NotifyCb()
	{
		for (auto it : m_vReLoadCb)
		{
			it();
		}
	}
	
	bool LoadJson(const std::string& jsonFile)
	{
		Json::Reader filereader;
        Json::Value root;
        std::ifstream is(std::string(CONFIG_PATH) + jsonFile);

        if (is) {
            // get length of file:
            is.seekg(0, is.end);
            int length = (int)is.tellg();
            length = length + 1;
            is.seekg(0, is.beg);
            char * buffer = new char[length];
            memset(buffer, 0, length);
            // read data as a block:
            is.read(buffer, length);
            is.close();
            filereader.parse(buffer, buffer + length, root);
            delete[] buffer;
        }

		
		m_vecAllElements.resize(root.size());
		int32_t m_nIndex = 0;
        for (Json::ValueIterator it = root.begin(); it != root.end(); ++it, ++m_nIndex)
        {
            try
            {
                auto p = (*it);
                BuffTypeElement	& member = m_vecAllElements[m_nIndex];
			member.id=p["id"].asInt();
			member.desc=p["desc"].asString();
			member.desc_id=p["desc_id"].asInt();
			member.res=p["res"].asString();
           
               
              
				m_mapElements.emplace(member.id, &member);
            }
            catch (std::exception const & e)
            {
                ELOG("%s error config id : %d", e.what(), (*it)["id"].asInt());
                Assert(false);
            }
        }
		
		NotifyCb();
        return true;
	}



	bool ReLoad()
	{
		Json::Reader filereader;
        Json::Value root;
        std::ifstream is(std::string(CONFIG_PATH) + "BuffType.json");

        if (is) {
            // get length of file:
            is.seekg(0, is.end);
            int length = (int)is.tellg();
            length = length + 1;
            is.seekg(0, is.beg);
            char * buffer = new char[length];
            memset(buffer, 0, length);
            // read data as a block:
            is.read(buffer, length);
            is.close();
            filereader.parse(buffer, buffer + length, root);
            delete[] buffer;
        }

		
        for (Json::ValueIterator it = root.begin(); it != root.end(); ++it )
        {
            try
            {
				
                auto p = (*it);
                BuffTypeElement	 member;
			member.id=p["id"].asInt();
			member.desc=p["desc"].asString();
			member.desc_id=p["desc_id"].asInt();
			member.res=p["res"].asString();
           
              
              
				*m_mapElements[member.id] = member;
            }
            catch (std::exception const & e)
            {
                ELOG("%s error config id : %d", e.what(), (*it)["id"].asInt());
                Assert(false);
            }
        }
		NotifyCb();
		return true;
	}
	

};

#endif
