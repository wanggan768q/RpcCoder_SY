#include "ModuleName.h"
map<int, string> ModuleValue;
void InitModuleValue()
{
	ModuleValue[24]="活动";
	ModuleValue[12]="Bag";
	ModuleValue[7]="基础数据";
	ModuleValue[22]="生活技能";
	ModuleValue[26]="CampFigth";
	ModuleValue[29]="动画播放模块";
	ModuleValue[13]="Chat";
	ModuleValue[1]="Config";
	ModuleValue[19]="货币";
	ModuleValue[20]="掉落";
	ModuleValue[6]="副本";
	ModuleValue[18]="装备";
	ModuleValue[27]="装备槽";
	ModuleValue[5]="事件模块";
	ModuleValue[37]="可交互的怪 ";
	ModuleValue[16]="EventObj";
	ModuleValue[9]="战斗";
	ModuleValue[38]="公会";
	ModuleValue[4]="玩家模块";
	ModuleValue[17]="道具操作";
	ModuleValue[25]="宝石模块";
	ModuleValue[36]="大厅服务器";
	ModuleValue[2]="登录模块";
	ModuleValue[30]="邮件";
	ModuleValue[39]="匹配模块";
	ModuleValue[28]="药剂";
	ModuleValue[31]="宠物模块";
	ModuleValue[34]="Pvp";
	ModuleValue[15]="Quest";
	ModuleValue[40]="坐骑";
	ModuleValue[3]="场景模块";
	ModuleValue[33]="商店";
	ModuleValue[21]="技能模块";
	ModuleValue[14]="小地图相关";
	ModuleValue[10]="Team";
	ModuleValue[32]="珍宝阁";
	ModuleValue[35]="藏宝图";
	ModuleValue[41]="载具（变身）";
	ModuleValue[11]="WG";
	ModuleValue[23]="世界BOSS模块";
	ModuleValue[8]="世界服务器模块";

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
