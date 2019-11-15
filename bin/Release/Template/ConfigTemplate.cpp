#include "$Template$Cfg.h"

#include<algorithm>

#include "CommonDefine.h"

#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "rapidjson/error/en.h"

#include "Game/Logger.h"




$Template$Table::$Template$Table(){}
$Template$Table::~$Template$Table()
{

}
$Template$Table& $Template$Table::Instance()
{
	static $Template$Table sInstance;
	return sInstance;
}

void $Template$Table::RegisterReLoadCb(const ReloadCallback &cb)
{
	m_vReLoadCb.push_back(cb);
}

const $Template$Element* $Template$Table::GetElement($PrimaryType$ key)
{
	MapElementMap::iterator it = m_mapElements.find(key);
	if (it == m_mapElements.end())
	{
		return NULL;
	}
	return it->second.get();
}

bool $Template$Table::HasElement($PrimaryType$ key)
{
	return m_mapElements.find(key) != m_mapElements.end();
}

const $Template$Table::vec_type& $Template$Table::GetAllID() const
{
	return m_vElementID;
}

const $Template$Table::MapElementMap& $Template$Table::GetAllElement() const
{
	return m_mapElements;
}
bool $Template$Table::Load()
{
	return LoadJson("$Template$.json");
}

void $Template$Table::NotifyCb()
{
	for (auto it : m_vReLoadCb)
	{
		it();
	}
}

bool $Template$Table::LoadJson(const std::string& jsonFile)
{
	rapidjson::Document doc;
	std::string filename = std::string(CONFIG_PATH) + jsonFile;
	FILE* pFile = fopen(filename.c_str(),"rb");
    if (pFile) {
		fseek(pFile,0,SEEK_END);
		long length = ftell(pFile);
		fseek(pFile,0,SEEK_SET);
		char* pBuff = new char[length + 1];
		pBuff[length] = '\0';
		rapidjson::FileReadStream oFileStream(pFile,pBuff,length);
		doc.ParseStream(oFileStream);
		fclose(pFile);
		delete[] pBuff;
		if (doc.HasParseError())
		{
			int offset = doc.GetErrorOffset();
			rapidjson::ParseErrorCode code = doc.GetParseError();
			ELOG("%s parse error:%s offset:%d", jsonFile.c_str(), GetParseError_En(code), offset);
			return false;
		}
    }
	else
	{
		ELOG("Load File Error %s", jsonFile.c_str());
		return false;
	}
    for (rapidjson::size_t i = 0; i < doc.Size(); ++i)
    {
		const rapidjson::Value & p = doc[i];
		try
		{
			int mid = p["id"].GetInt();
			max_table_id_ = std::max(max_table_id_, mid);
			min_table_id_ = std::min(min_table_id_, mid);
			ele_ptr_type pMember(new $Template$Element);
            $Template$Element	& member = *pMember;
			$ReadJsonValue$
			m_mapElements.emplace(member.$PrimaryKey$, std::move(pMember));
			m_vElementID.emplace_back(member.$PrimaryKey$);
        }
        catch (...)
        {
            ELOG("%s error config id : %d", jsonFile.c_str(), p["id"].GetInt());
            Assert(false);
        }
	}
	NotifyCb();
	ILOG("%s load Ok !!", jsonFile.c_str());
	return true;
}



bool $Template$Table::ReLoad()
{
	rapidjson::Document doc;
	std::string filename = std::string(CONFIG_PATH) + "$Template$.json";
	FILE* pFile = fopen(filename.c_str(),"rb");
    if (pFile) {
		fseek(pFile,0,SEEK_END);
		long length = ftell(pFile);
		fseek(pFile,0,SEEK_SET);
		char* pBuff = new char[length + 1];
		pBuff[length] = '\0';
		rapidjson::FileReadStream oFileStream(pFile, pBuff, length);
		doc.ParseStream(oFileStream);
		fclose(pFile);
		delete[] pBuff;
		if (doc.HasParseError())
		{
			int offset = doc.GetErrorOffset();
			rapidjson::ParseErrorCode code = doc.GetParseError();
			ELOG("%s parse error:%s offset:%d", "$Template$.json", GetParseError_En(code), offset);
			return false;
		}
    }
	else
	{
		ELOG("Load File Error %s", "$Template$.json");
		return false;
	}


    for (rapidjson::size_t i = 0; i < doc.Size(); ++i)
    {
      	const rapidjson::Value & p = doc[i];
        try
        {
			int mid = p["id"].GetInt();
			max_table_id_ = std::max(max_table_id_, mid);
            min_table_id_ = std::min(min_table_id_, mid);
			if (!HasElement(mid))
			{
				ele_ptr_type pMember(new $Template$Element);
				m_mapElements.emplace(mid, std::move(pMember));
				m_vElementID.emplace_back(mid);
			}
            $Template$Element	 & member = *m_mapElements[mid];
			$ReadJsonValue$
        }
        catch (...)
        {
            ELOG("%s error config id : %d", "$Template$.json", p["id"].GetInt());
            Assert(false);
        }
    }
	NotifyCb();
	ILOG("%s load Ok !!", "$Template$.json");
	return true;
}

 int32_t $Template$Table::min_table_id()const { return min_table_id_; }
 int32_t $Template$Table::max_table_id()const { return max_table_id_; }

