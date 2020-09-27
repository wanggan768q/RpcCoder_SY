#ifndef __SCENE_CONFIG_H
#define __SCENE_CONFIG_H

#include "BaseDef.h"



using namespace std;

//场景配置数据结构
struct SceneElement
{
	friend class SceneTable;
	int id;                      	//序号	序号（不可以超过2000）
	int build_setting_index;     	//场景unity标识	0：game 1：Game 2：SY_CS_NG_Final 3：SY_FB_SR2_Story_Dungeon_Final 4：SY_FB_YongYeHuiLang_Final 5：SY_CS_WerwolfCity 6：SY_YW_ASTW 8：SY_MaZongFB 7：SY_YW_MZCY_Final 9：SY_HD_JJC_Final 10：SY_CS_JLLD 12：SY_FB_JLZS_Final 13：SY_YW_JLZS_Final 15：SY_FB_KENS_5M_Final 19：SY_CS_SPQY_Final 20：SY_YW_FLXG_Final 22:SY_YW_ASTW_02_Final 24:SY_FB_XS_Final
	string comment;              	//	绿色：主城/种族领地 白色：普通 黄色：副本 蓝色：PVP
	int name;                    	//场景名称	文本id
	int scene_type_id;           	//场景类型名称	界面文本id
	int teleport_target_id;      	//传送点 TeleportTarget_传送目标表的ID	关联teleport_target中的id 传送位置只需改这个关联ID的坐标就可以
	int description;             	//场景描述	文本相关id
	string background_pic;       	//场景介绍图片	场景介绍图片
	string loading_pic;          	//场景读取图片	如果不填则显示默认图
	int thread_id;               	//线程ID	线程ID
	int scene_type;              	//副本类型	0：场景 1：副本 2 : 阵营战场 3：竞技场 4：公会领地
	float valid_pos_x;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	float valid_pos_z;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	string scene_resource;       	//场景资源	场景资源名称，服务器scene文件夹名字需要跟这个一样
	string server_script_id;     	//场景脚本	该场景配置脚本的名称，必填
	string behaviac;             	//副本行为树	Config/behaviac/下的目录
	int required_level;          	//所需等级	解锁该场景需要的等级
	float required_score;        	//所需战力	解锁该场景需要的战力
	int pre_quest;               	//前置任务	解锁该场景需要的任务
	int teleport_id;             	//默认生成点ID（对应waypoint)	如果没有指定生成的位置，玩家会默认出现在该点
	float toward_to;             	//传送点朝向(临时)	点地图床送到对应场景时，角色的朝向角度
	int camera_type;             	//摄像机类型	0：不限制 1：强制2.5D
	string pre_music;            	//前奏音乐	进入场景时播放的音乐前奏
	string loop_music;           	//循环音乐	在该场景循环播放的音乐
	float music_volume;          	//音乐音量	0~1
	string special_icon;         	//世界地图标识	特殊场景在世界地图上的特殊图标
	string mini_map;             	//小地图资源	调用的小地图的资源
	vector<int> recount;         	//战斗统计显示	是否显示按钮|是否默认显示
	int allow_mini_map;          	//开启小地图	是否允许玩家打开小地图 0：不允许 1：允许
	string radar_map;            	//雷达图资源	调用的雷达图的资源
	vector<int> map_anchor;      	//地图锚点	对应地图0.0点在UI界面上的位置 X|Y分别表示起始点坐标
	vector<int> map_init_point;  	//地图起始点	对应场景0.0点在地图资源上的位置 0.0点为资源左下角 X|Y分别表示起始点坐标
	vector<int> map_resource_size;	//地图大小	对应场景在图片上的大小 X|Y分别表示长宽
	vector<int> map_border;      	//地图边缘大小	地图纵向有效范围与地图上下边缘的误差 X|Y分别表示上边缘和下边缘的高度
	vector<int> map_size;        	//场景规模	场景的长度和宽度 X|Y分别标示长宽
	vector<int> map_effect_area; 	//地图有效区	对于地图文件中希望被显示部分的大小 X|Y分别标示长宽
	vector<float> map_offset;    	//地图偏移	和有效区域配合使用 X|Y分别标示横向和纵向 以中心为0|0点
	float map_ratio;             	//地图比例	用来控制地图显示的缩放。默认为1
	float radar_ratio;           	//雷达比例	HUD雷达上显示的地图的缩放值
	vector<float> scene_shadow;  	//场景阴影	X|Y|Z代表场景中光照的方向
	vector<int> buff;            	//buffID	进场景时触发的buff
	int is_revive;               	//是否支持复活	1为是 0为否
	vector<int> revive_waypoint_id;	//复活点id	
	int revive_time;             	//就近复活时间	该场景内的就近复活cd时间 单位毫秒
	vector<int> elite_id;        	//精英怪任务id	场景内所有精英怪id
	vector<int> treasure_map_1_id;	//低级藏宝图路点id	场景内所有低级藏宝图id
	vector<int> treasure_map_2_id;	//高级藏宝图路点id	场景内所有高级藏宝图id
	int mount_prohibited;        	//禁用坐骑	场景内是否禁止上坐骑 0：禁止上坐骑 1：允许上坐骑
	int treasure_prohibited;     	//禁用宝物库	场景内是否禁止打开宝物库 0：禁止打开宝物库 1：允许打开宝物库
	int duel_prohibited;         	//禁用决斗	场景内是否禁用决斗 0：禁止决斗 1：允许决斗
	int pet_display;             	//显示宠物	该场景是否允许显示宠物 0：不允许 1：允许
	int auto_move_wp;            	//自动寻路起点	如果填写了值且开启了自动功能，则会自动启用自动寻路 关联路点表
	int auto_search_type;        	//自动战斗是否全地图索敌	0：全地图索敌 1：固定距离索敌（Global_id=20） -1：场景不能挂机
	vector<int> area_id;         	//区域id	
	vector<int> item_type_prohibited;	//禁止使用的道具大类型（道具类型表）	举例填法：6|7|6   数量要和右边字段数量一致
	vector<int> item_subtype_prohibited;	//禁止使用的道具小类型（道具类型表）	1|0|0|   禁止6大类的1、0和7大类的0
	int leave_team_prohibited;   	//禁止离开队伍	1该场景可以离队 0该场景不能离队
	int match_prohibited;        	//禁止所有匹配功能，会中断当前匹配状态	1该场景禁止 0该场景不禁止
	int teamfollow_prohibited;   	//禁止组队跟随传送入此场景	1禁止
	int is_change_daytime;       	//昼夜变化	该场景是否有昼夜变化
	vector<int> weather_type;    	//天气组	天气组
	vector<int> weather_weight;  	//天气权重	对应上一列
	int trusteeship;             	//离线托管开关	0关闭，1打开
	int robotcreate;             	//机器人是否可创建	0关闭，1打开
	int Plants_limit;            	//植物采集点上限	
	vector<int> Plants_refresh;  	//植物采集点刷新时间（慢度|快度）	
	int Mine_limit;              	//矿脉采集点上限	
	vector<int> Mine_refresh;    	//矿脉采集点刷新时间（慢度|快度）	
	vector<int> Plants_group;    	//采药点集合	
	vector<int> Mine_group;      	//采矿点集合	
	vector<int> Fish_group;      	//钓点集合	
	int Treasure_box_num_limit;  	//宝箱采集点上限	
	vector<int> Treasure_box_refresh;	//宝箱采集点刷新时间（慢度|快度）	
	vector<int> Treasure_box_group;	//宝箱采集点集合	

private:

public:

	SceneElement()
	{
		id = -1;

	}
};

//场景配置封装类
class SceneTable
{
	public:
	typedef std::unique_ptr<SceneElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	SceneTable();
	~SceneTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static SceneTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const SceneElement* GetElement(int key);

	bool HasElement(int key);

	const vec_type& GetAllID() const;

	const MapElementMap& GetAllElement() const;
	bool Load();

	void NotifyCb();

	bool LoadJson(const std::string& jsonFile);


	bool ReLoad();
	

  int32_t min_table_id()const;
  int32_t max_table_id()const;
 private:
   int32_t min_table_id_{INT32_MAX};
   int32_t max_table_id_{INT32_MIN};
   bool m_bLoad{false};

};

#endif
