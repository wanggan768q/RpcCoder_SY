#include "ModuleName.h"
map<int, string> ModuleValue;
void InitModuleValue()
{
	ModuleValue[3]="场景模块";

}
string GetModuleValue(int id)
{
	map<int, string>::iterator iter = ModuleValue.find(id);
	if (iter != ModuleValue.end())
	{
		return iter->second;
	}
	return "未知";
}
