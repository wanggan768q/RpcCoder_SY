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
#include "Obj/Obj_Module/CalcPropertiesModule.h"


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
	void	SendAllMembers();
	void 	SetSendCallBack(const send_callback_type & cb);
	//string  ToHtml(){ return m_syncData$SyncDataName$.ToHtml(); }
	//string  HtmlDescHeader() { return m_syncData$SyncDataName$.HtmlDescHeader(); }
	template <typename T>
	void CalcMethodCB(int32_t nType, T&cb)
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
$SyncOpDefine$

private:
	$SyncDataDefine$

	$Template$UserDataV1 m_ClientDataUserData;
	id_type m_vCalcPropertyIds;
	id_type m_vChangeIds;
	function_type m_oCaclPropertyCallbacks;
	send_callback_type m_oSendCallback;
	bool m_bChange;

};



#endif
