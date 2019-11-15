#ifndef __SYNC_DATA_$TEMPLATE$_V$SyncDataVersion$_H
#define __SYNC_DATA_$TEMPLATE$_V$SyncDataVersion$_H

//#include "BASE.h"

//#include "ModuleDataInterface.h"
//#include "ModuleDataClassFactory.h"
//#include "MsgStreamMgr.h"
//#include "$Template$V$SyncDataVersion$DataWraper.h"

#include <cstdint>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include "BaseDef.h"
#include "$Template$V$SyncDataVersion$DataWraper.h"
#include "GameStruct/PropertiesModule.h"


//同步数据相关枚举量定义
enum $Template$SyncDataItemIdE
{
$syncIds$
};

class Obj_Character;
//主同步数据操作类
class SyncData$Template$V$SyncDataVersion$
{
public:
	typedef std::unordered_set<int32_t> id_type;
	typedef std::function<Property()> calc_callback_type;
	typedef std::unordered_map<int32_t, calc_callback_type> function_type;
	typedef std::function<void ($Template$UserDataV1&)> send_callback_type;

public:
			SyncData$Template$V$SyncDataVersion$(Obj_Character*);
	virtual	~SyncData$Template$V$SyncDataVersion$();

	void 	Init();
	//跨进程 切场景 用的
	void	InitEx();
	void	RefreshAll();
	void	SendAllMembers();
	void	SendToOthers();
	void 	SetSendCallBack(const send_callback_type & cb);
	void	SetSendOtherCallBack(const send_callback_type & cb);
	void 	CalcAllMembers();
	void 	GetCompletePlayerData($Template$UserDataV1& base);
	void 	SendToClient()
	{
		if (m_oSendCallback)
		{
			m_oSendCallback(m_ClientDataUserData);
			m_ClientDataUserData.Clear();
		}
		
	}
	void 	SendToOtherClient()
	{
		if (m_oSendOtherCallback)
		{
			m_oSendOtherCallback(m_OtherDataUserData);
			m_OtherDataUserData.Clear();
		}
	}
	
	Property GetAttrByType(int attrType);

	//string  ToHtml(){ return m_syncData$SyncDataName$.ToHtml(); }
	//string  HtmlDescHeader() { return m_syncData$SyncDataName$.HtmlDescHeader(); }

	template <typename T>
	void CalcMethodCB(int32_t nType, T cb)
	{
		id_type::iterator it = m_vCalcPropertyIds.find(nType);
		if (it != m_vCalcPropertyIds.end())
		{
			function_type::iterator fi = m_oCaclPropertyCallbacks.find(nType);
			if (fi != m_oCaclPropertyCallbacks.end())
			{
				cb(fi->second());
			}

			m_vCalcPropertyIds.erase(it);
		}
	}
	
	void CalcChangeMethodCB()
	{
		if (m_vCalcPropertyIds.empty())
 			return;
		m_vChangeIds = m_vCalcPropertyIds;
		for (auto it : m_vChangeIds)
		{
			GetAttrByType(it);
		}
        m_vChangeIds.clear();
	}
	

	string SerializeAsString()
	{
		CalcAllMembers();
		return m_syncDataUserData.SerializeAsString();
	}

	void SetChange(bool b)
	{
		m_bChange = b;
		if (!b)
		{
			m_ClientDataUserData.Clear();
		}
	}
	void SetOtherChange(bool b)
	{
		m_bOtherChange = b;
	}
	
	
	void RefreshByType(int attr_type)
	{
		m_vCalcPropertyIds.insert(attr_type);
	}
	
$SyncOpDefine$

private:
	$SyncDataDefine$

	$Template$UserDataV1 m_ClientDataUserData;
	$Template$UserDataV1 m_OtherDataUserData;
	id_type m_vCalcPropertyIds;
	id_type m_vChangeIds;
	function_type m_oCaclPropertyCallbacks;
	send_callback_type m_oSendCallback;
	send_callback_type m_oSendOtherCallback;
	bool m_bChange;
	bool m_bOtherChange;
	Obj_Character * m_pObj;
};



#endif
