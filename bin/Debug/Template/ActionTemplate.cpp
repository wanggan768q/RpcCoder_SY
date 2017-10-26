#include "Action.h"


#define  NEW_ACTION(_ACT, _ActType) case _ACT: { _ActType* pAction = new _ActType();pAction->Create(buf);return pAction; }
//反序列化
Action* Action::Deserialize(const string& buf)
{
	//取得动作类型
	KernelActionE aType = (KernelActionE)buf[0];
	//根据动作类型创建动作实例
	switch (aType)
	{
$NEW_ACTION$
	}
	return nullptr;
}
