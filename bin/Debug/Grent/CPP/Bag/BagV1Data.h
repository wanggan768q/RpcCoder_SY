#ifndef __SYNC_DATA_BAG_V1_H
#define __SYNC_DATA_BAG_V1_H

//#include "BASE.h"

//#include "ModuleDataInterface.h"
//#include "ModuleDataClassFactory.h"
//#include "MsgStreamMgr.h"
//#include "BagV1DataWraper.h"

#include <cstdint>
#include <functional>
#include <unordered_set>
#include <unordered_map>
#include "BaseDef.h"
#include "BagV1DataWraper.h"
#include "PropertiesModule.h"


//同步数据相关枚举量定义
enum BagSyncDataItemIdE
{
 	SYNCID_BAG_GUID                             = 1201,  //Guid
 	SYNCID_BAG_LOCK                             = 1202,  //Lock
 	SYNCID_BAG_OVERLAYCOUNT                     = 1203,  //OverlayCount

};

class Obj_Character;
//主同步数据操作类
class SyncDataBagV1
{
public:
	typedef std::unordered_set<int32_t> id_type;
	typedef std::function<Property()> calc_callback_type;
	typedef std::unordered_map<int32_t, calc_callback_type> function_type;
	typedef std::function<void (BagUserDataV1&)> send_callback_type;

public:
			SyncDataBagV1(Obj_Character*);
	virtual	~SyncDataBagV1();

	void 	Init();
	void	SendAllMembers();
	void 	SetSendCallBack(const send_callback_type & cb);
	void 	CalcAllMembers();

	//string  ToHtml(){ return m_syncDataItemData.ToHtml(); }
	//string  HtmlDescHeader() { return m_syncDataItemData.HtmlDescHeader(); }

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

	string SerializeAsString()
	{
		CalcAllMembers();
		return m_syncDataUserData.SerializeAsString();
	}

	void SetChange(bool b)
	{
		m_bChange = b;
	}

public:
	//Guid
	void SetGuid( const INT32& v );
	INT32 GetGuid();
	void RefreshGuid();
	void SendGuid(bool OnlyToClient=true);
public:
	//Lock
	void SetLock( const bool& v );
	bool GetLock();
	void RefreshLock();
	void SendLock(bool OnlyToClient=true);
public:
	//OverlayCount
	void SetOverlayCount( const INT32& v );
	INT32 GetOverlayCount();
	void RefreshOverlayCount();
	void SendOverlayCount(bool OnlyToClient=true);


private:
	BagItemDataWraperV1 m_syncDataItemData;

	BagUserDataV1 m_ClientDataUserData;
	id_type m_vCalcPropertyIds;
	id_type m_vChangeIds;
	function_type m_oCaclPropertyCallbacks;
	send_callback_type m_oSendCallback;
	bool m_bChange;

};



#endif
