#ifndef __ACTION_H
#define __ACTION_H
#include "BASE.h"
#include "FightRpcWraper.h"
#include "Position.h"
#include "EnumDefine.h"

//战斗核心动作枚举
enum KernelActionE
{
	ACTION_NOOP_TICK = 0,          //TICK驱动(服务器输入)
$ActionEnum$
};


//动作基类
class Action
{
public:
	//构造函数
	Action()
	{
		ActionType = ACTION_NOOP_TICK;
	}
	virtual ~Action()
	{

	}
	virtual Action* Clone()
	{
		return nullptr; 
	}
	//序列化
	virtual int Serialize(MemStream& ms)
	{

		ms.SetPos(0);
		MemStream tmpStream;
		INT16 Len = 0;
		tmpStream.Write(&Len, 2);
		tmpStream.Write(&ActionType, 1);
		tmpStream.Write(&OccurTime, 4);
		string dataArr = GetWraperString();
		tmpStream.Write(dataArr.c_str(), dataArr.length());
		Len = (INT16)tmpStream.GetSize();
		tmpStream.SetPos(0);
		tmpStream.Write(&Len, 2);
		ms.Write(tmpStream.GetBuffer(), tmpStream.GetSize());

		return Len;
	}

	virtual string GetWraperString() const
	{
		return string();
	}

	virtual void SetWraperString(const char* pBuf, int size)
	{
	}

	virtual string strSerialize()
	{
		MemStream tmpStream;
		INT16 Len = 0;
		tmpStream.Write(&Len, 2);
		tmpStream.Write(&ActionType, 1);
		tmpStream.Write(&OccurTime, 4);
		string dataArr = GetWraperString();
		tmpStream.Write(dataArr.c_str(), dataArr.length());
		Len = (INT16)tmpStream.GetSize();
		tmpStream.SetPos(0);
		tmpStream.Write(&Len, 2);
		return string(tmpStream.GetBuffer(), tmpStream.GetSize());
	}

	virtual void Create(const string& buf)
	{
		const char* pBuff = buf.c_str();
		OccurTime = *((int*)(pBuff + 1));
		SetWraperString(pBuff + 5, buf.length() - 5);
	}

	//反序列化
	static Action* Deserialize(const string& buf);

	//动作类型
	INT32 OccurTime = 0;
	KernelActionE ActionType = ACTION_NOOP_TICK;
	INT64 UId = 0;
	bool IsServerFeed = false;
	int SenderObjId = -1;

};


#define DEFINE_ACTION( _ActionName, _WraperName,_ACT ) \
class _ActionName : public Action, public _WraperName \
{\
public:\
	_ActionName(){ActionType = _ACT;}\
	virtual ~_ActionName(){}\
	virtual string GetWraperString()const { return SerializeAsString(); } \
	virtual void SetWraperString(const char* pBuf, int size){ ParseFromArray(pBuf, size); }\
	virtual Action* Clone(){\
		_ActionName* pNew = new _ActionName();\
		pNew->OccurTime = OccurTime;\
		pNew->ActionType = ActionType;\
		pNew->UId = UId;\
		pNew->SenderObjId=SenderObjId;\
		pNew->IsServerFeed = IsServerFeed;\
		string ss = GetWraperString();\
		pNew->SetWraperString(ss.c_str(), ss.length());\
		return pNew;\
	}\
};

$DEFINE_ACTION$


#endif // !__ACTION_H
