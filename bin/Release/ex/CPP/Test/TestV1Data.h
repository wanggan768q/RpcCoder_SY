#ifndef __SYNC_DATA_TEST_V1_H
#define __SYNC_DATA_TEST_V1_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "TestV1DataWraper.h"


//同步数据相关枚举量定义
enum TestSyncDataItemIdE
{
 	SYNCID_TEST_HP                              = 101,  //hp

};


//主同步数据操作类
class SyncDataTestV1 : public ModuleDataInterface , public ModuleDataRegister<SyncDataTestV1>
{
public:
			SyncDataTestV1();
	virtual	~SyncDataTestV1();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncDataUser.ToHtml(); }
	string  HtmlDescHeader() { return m_syncDataUser.HtmlDescHeader(); }
public:
	//hp
	void SetHp( const INT32& v );
	INT32 GetHp();
	void SendHp(bool OnlyToClient=true);


private:
	TestUserWraperV1 m_syncDataUser;

};



#endif
