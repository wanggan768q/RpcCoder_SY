#ifndef __SYNC_DATA_$TEMPLATE$_V$SyncDataVersion$_H
#define __SYNC_DATA_$TEMPLATE$_V$SyncDataVersion$_H

#include "BASE.h"

#include "ModuleDataInterface.h"
#include "ModuleDataClassFactory.h"
#include "MsgStreamMgr.h"
#include "$Template$V$SyncDataVersion$DataWraper.h"


//同步数据相关枚举量定义
enum $Template$SyncDataItemIdE
{
$syncIds$
};


//主同步数据操作类
class SyncData$Template$V$SyncDataVersion$ : public ModuleDataInterface , public ModuleDataRegister<SyncData$Template$V$SyncDataVersion$>
{
public:
			SyncData$Template$V$SyncDataVersion$();
	virtual	~SyncData$Template$V$SyncDataVersion$();
	void	SendAllMembers(bool OnlyToClient=true);
	string  ToHtml(){ return m_syncData$SyncDataName$.ToHtml(); }
	string  HtmlDescHeader() { return m_syncData$SyncDataName$.HtmlDescHeader(); }
$SyncOpDefine$

private:
	$SyncDataDefine$

};



#endif
