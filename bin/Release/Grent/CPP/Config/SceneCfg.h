#ifndef __SCENE_CONFIG_H
#define __SCENE_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

//场景配置数据结构
struct SceneElement
{
	friend class SceneTable;
	int id;                      	//序号	序号（不可以超过2000）
	int build_setting_index;     	//场景unity标识	0：game 1：Game 2：SY_CS_NG_Final 3：SY_FB_SR2_Story_Dungeon_Final 4：SY_FB_YongYeHuiLang_Final 5：SY_CS_WerwolfCity 6：SY_YW_ASTW 8：SY_MaZongFB 7：SY_YW_MZCY_Final 9：SY_HD_JJC_Final 10：SY_CS_JLLD 12：SY_FB_JLZS_Final 13：SY_YW_JLZS_Final 15：SY_FB_KENS_5M_Final 19：SY_CS_SPQY_Final 20：SY_YW_FLXG_Final 22:SY_YW_ASTW_02_Final 24:SY_FB_XS_Final
	string comment;              	//	绿色：主城/种族领地 白色：普通 黄色：副本 蓝色：PVP
	int name;                    	//场景名称	文本id
	int scene_type_id;           	//场景类型	文本id
	int teleport_target_id;      	//小地图传送点	关联teleport_target中的id
	int description;             	//场景描述	文本相关id
	string background_pic;       	//场景介绍图片	场景介绍图片
	string loading_pic;          	//场景读取图片	如果不填则显示默认图
	int thread_id;               	//线程ID	线程ID
	int scene_type;              	//副本类型	0：场景 1：副本 2 : 阵营战场 3：竞技场
	float valid_pos_x;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	float valid_pos_z;           	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	string scene_resource;       	//场景资源	场景资源名称
	string server_script_id;     	//场景脚本	该场景配置脚本的名称，必填
	int required_level;          	//所需等级	解锁该场景需要的等级
	float required_score;        	//所需战力	解锁该场景需要的战力
	int pre_quest;               	//前置任务	解锁该场景需要的任务
	int teleport_id;             	//默认生成点ID	如果没有指定生成的位置，玩家会默认出现在该点
	float toward_to;             	//传送点朝向(临时)	点地图床送到对应场景时，角色的朝向角度
	int camera_type;             	//摄像机类型	0：不限制 1：强制2.5D
	string pre_music;            	//前奏音乐	进入场景时播放的音乐前奏
	string loop_music;           	//循环音乐	在该场景循环播放的音乐
	float music_volume;          	//音乐音量	0~1
	string special_icon;         	//世界地图标识	特殊场景在世界地图上的特殊图标
	string mini_map;             	//小地图资源	调用的小地图的资源
	string radar_map;            	//雷达图资源	调用的雷达图的资源
	vector<int> map_anchor;      	//地图锚点	对应地图0.0点在UI界面上的位置 X|Y分别表示起始点坐标
	vector<int> map_init_point;  	//地图起始点	对应场景0.0点在地图资源上的位置 0.0点为资源左下角 X|Y分别表示起始点坐标
	vector<int> map_resource_size;	//地图大小	对应场景在图片上的大小 X|Y分别表示长宽
	vector<int> map_border;      	//地图边缘大小	地图纵向有效范围与地图上下边缘的误差 X|Y分别表示上边缘和下边缘的高度
	vector<int> map_size;        	//场景规模	场景的长度和宽度 X|Y分别标示长宽
	vector<int> map_effect_area; 	//地图有效区	对于地图文件中希望被显示部分的大小 X|Y分别标示长宽
	vector<float> map_offset;    	//地图偏移	和有效区域配合使用 X|Y分别标示横向和纵向 以中心为0|0点
	float map_ratio;             	//地图比例	用来控制地图显示的缩放。默认为1
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
	int auto_move_wp;            	//自动寻路起点	如果填写了值且开启了自动功能，则会自动启用自动寻路 关联路点表
	int auto_search_type;        	//自动战斗是否全地图索敌	0：全地图索敌 1：固定距离索敌（Global_id=20） -1：场景不能挂机
	vector<int> area_id;         	//区域id	
	vector<int> item_type_prohibited;	//禁止使用的道具大类型（道具类型表）	举例填法：6|7|6   数量要和右边字段数量一致
	vector<int> item_subtype_prohibited;	//禁止使用的道具小类型（道具类型表）	1|0|0|   禁止6大类的1、0和7大类的0
	int leave_team_prohibited;   	//禁止离开队伍	1该场景可以离队 0该场景不能离队
	int match_prohibited;        	//禁止所有匹配功能，会中断当前匹配状态	1该场景禁止 0该场景不禁止

private:
	bool m_bIsValidate;
	void SetIsValidate(bool isValid)
	{
		m_bIsValidate=isValid;
	}
public:
	bool IsValidate()
	{
		return m_bIsValidate;
	}
	SceneElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//场景配置封装类
class SceneTable
{
	friend class TableData;
private:
	SceneTable(){}
	~SceneTable(){}
	map<int, SceneElement>	m_mapElements;
	vector<SceneElement>	m_vecAllElements;
	SceneElement m_emptyItem;
public:
	static SceneTable& Instance()
	{
		static SceneTable sInstance;
		return sInstance;
	}

	SceneElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<SceneElement>&	GetAllElement()
	{
		if(!m_vecAllElements.empty()) 
			return m_vecAllElements;
		m_vecAllElements.reserve(m_mapElements.size());
		for(auto iter=m_mapElements.begin(); iter != m_mapElements.end(); ++iter)
		{
			if(iter->second.IsValidate()) 
				m_vecAllElements.push_back(iter->second);
		}
		return m_vecAllElements;
	}
	bool Load()
	{
		string strTableContent;
		if( LoadConfigContent("Scene.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("Scene.bin", strTableContent ) )
		{
			printf_message("配置文件[Scene.bin]未找到");
			assert(false);
			return false;
		}
		return LoadBin(strTableContent);
	}

	bool LoadBin(string strContent)
	{

		return true;
	}
	bool LoadCsv(string strContent)
	{
		m_vecAllElements.clear();
		m_mapElements.clear();
		int contentOffset = 0;
		vector<string> vecLine;
		vecLine = ReadCsvLine( strContent, contentOffset );
		if(vecLine.size() != 52)
		{
			printf_message("Scene.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("Scene.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="build_setting_index"){printf_message("Scene.csv中字段[build_setting_index]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="comment"){printf_message("Scene.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="name"){printf_message("Scene.csv中字段[name]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="scene_type_id"){printf_message("Scene.csv中字段[scene_type_id]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="teleport_target_id"){printf_message("Scene.csv中字段[teleport_target_id]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="description"){printf_message("Scene.csv中字段[description]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="background_pic"){printf_message("Scene.csv中字段[background_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="loading_pic"){printf_message("Scene.csv中字段[loading_pic]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="thread_id"){printf_message("Scene.csv中字段[thread_id]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="scene_type"){printf_message("Scene.csv中字段[scene_type]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="valid_pos_x"){printf_message("Scene.csv中字段[valid_pos_x]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="valid_pos_z"){printf_message("Scene.csv中字段[valid_pos_z]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="scene_resource"){printf_message("Scene.csv中字段[scene_resource]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="server_script_id"){printf_message("Scene.csv中字段[server_script_id]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="required_level"){printf_message("Scene.csv中字段[required_level]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="required_score"){printf_message("Scene.csv中字段[required_score]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="pre_quest"){printf_message("Scene.csv中字段[pre_quest]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="teleport_id"){printf_message("Scene.csv中字段[teleport_id]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="toward_to"){printf_message("Scene.csv中字段[toward_to]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="camera_type"){printf_message("Scene.csv中字段[camera_type]位置不对应 ");assert(false); return false; }
		if(vecLine[21]!="pre_music"){printf_message("Scene.csv中字段[pre_music]位置不对应 ");assert(false); return false; }
		if(vecLine[22]!="loop_music"){printf_message("Scene.csv中字段[loop_music]位置不对应 ");assert(false); return false; }
		if(vecLine[23]!="music_volume"){printf_message("Scene.csv中字段[music_volume]位置不对应 ");assert(false); return false; }
		if(vecLine[24]!="special_icon"){printf_message("Scene.csv中字段[special_icon]位置不对应 ");assert(false); return false; }
		if(vecLine[25]!="mini_map"){printf_message("Scene.csv中字段[mini_map]位置不对应 ");assert(false); return false; }
		if(vecLine[26]!="radar_map"){printf_message("Scene.csv中字段[radar_map]位置不对应 ");assert(false); return false; }
		if(vecLine[27]!="map_anchor"){printf_message("Scene.csv中字段[map_anchor]位置不对应 ");assert(false); return false; }
		if(vecLine[28]!="map_init_point"){printf_message("Scene.csv中字段[map_init_point]位置不对应 ");assert(false); return false; }
		if(vecLine[29]!="map_resource_size"){printf_message("Scene.csv中字段[map_resource_size]位置不对应 ");assert(false); return false; }
		if(vecLine[30]!="map_border"){printf_message("Scene.csv中字段[map_border]位置不对应 ");assert(false); return false; }
		if(vecLine[31]!="map_size"){printf_message("Scene.csv中字段[map_size]位置不对应 ");assert(false); return false; }
		if(vecLine[32]!="map_effect_area"){printf_message("Scene.csv中字段[map_effect_area]位置不对应 ");assert(false); return false; }
		if(vecLine[33]!="map_offset"){printf_message("Scene.csv中字段[map_offset]位置不对应 ");assert(false); return false; }
		if(vecLine[34]!="map_ratio"){printf_message("Scene.csv中字段[map_ratio]位置不对应 ");assert(false); return false; }
		if(vecLine[35]!="scene_shadow"){printf_message("Scene.csv中字段[scene_shadow]位置不对应 ");assert(false); return false; }
		if(vecLine[36]!="buff"){printf_message("Scene.csv中字段[buff]位置不对应 ");assert(false); return false; }
		if(vecLine[37]!="is_revive"){printf_message("Scene.csv中字段[is_revive]位置不对应 ");assert(false); return false; }
		if(vecLine[38]!="revive_waypoint_id"){printf_message("Scene.csv中字段[revive_waypoint_id]位置不对应 ");assert(false); return false; }
		if(vecLine[39]!="revive_time"){printf_message("Scene.csv中字段[revive_time]位置不对应 ");assert(false); return false; }
		if(vecLine[40]!="elite_id"){printf_message("Scene.csv中字段[elite_id]位置不对应 ");assert(false); return false; }
		if(vecLine[41]!="treasure_map_1_id"){printf_message("Scene.csv中字段[treasure_map_1_id]位置不对应 ");assert(false); return false; }
		if(vecLine[42]!="treasure_map_2_id"){printf_message("Scene.csv中字段[treasure_map_2_id]位置不对应 ");assert(false); return false; }
		if(vecLine[43]!="mount_prohibited"){printf_message("Scene.csv中字段[mount_prohibited]位置不对应 ");assert(false); return false; }
		if(vecLine[44]!="treasure_prohibited"){printf_message("Scene.csv中字段[treasure_prohibited]位置不对应 ");assert(false); return false; }
		if(vecLine[45]!="auto_move_wp"){printf_message("Scene.csv中字段[auto_move_wp]位置不对应 ");assert(false); return false; }
		if(vecLine[46]!="auto_search_type"){printf_message("Scene.csv中字段[auto_search_type]位置不对应 ");assert(false); return false; }
		if(vecLine[47]!="area_id"){printf_message("Scene.csv中字段[area_id]位置不对应 ");assert(false); return false; }
		if(vecLine[48]!="item_type_prohibited"){printf_message("Scene.csv中字段[item_type_prohibited]位置不对应 ");assert(false); return false; }
		if(vecLine[49]!="item_subtype_prohibited"){printf_message("Scene.csv中字段[item_subtype_prohibited]位置不对应 ");assert(false); return false; }
		if(vecLine[50]!="leave_team_prohibited"){printf_message("Scene.csv中字段[leave_team_prohibited]位置不对应 ");assert(false); return false; }
		if(vecLine[51]!="match_prohibited"){printf_message("Scene.csv中字段[match_prohibited]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)52)
			{
				assert(false);
				return false;
			}
			SceneElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.build_setting_index=(int)atoi(vecLine[1].c_str());
			member.comment=vecLine[2];
			member.name=(int)atoi(vecLine[3].c_str());
			member.scene_type_id=(int)atoi(vecLine[4].c_str());
			member.teleport_target_id=(int)atoi(vecLine[5].c_str());
			member.description=(int)atoi(vecLine[6].c_str());
			member.background_pic=vecLine[7];
			member.loading_pic=vecLine[8];
			member.thread_id=(int)atoi(vecLine[9].c_str());
			member.scene_type=(int)atoi(vecLine[10].c_str());
			member.valid_pos_x=(float)atof(vecLine[11].c_str());
			member.valid_pos_z=(float)atof(vecLine[12].c_str());
			member.scene_resource=vecLine[13];
			member.server_script_id=vecLine[14];
			member.required_level=(int)atoi(vecLine[15].c_str());
			member.required_score=(float)atof(vecLine[16].c_str());
			member.pre_quest=(int)atoi(vecLine[17].c_str());
			member.teleport_id=(int)atoi(vecLine[18].c_str());
			member.toward_to=(float)atof(vecLine[19].c_str());
			member.camera_type=(int)atoi(vecLine[20].c_str());
			member.pre_music=vecLine[21];
			member.loop_music=vecLine[22];
			member.music_volume=(float)atof(vecLine[23].c_str());
			member.special_icon=vecLine[24];
			member.mini_map=vecLine[25];
			member.radar_map=vecLine[26];
			member.map_ratio=(float)atof(vecLine[34].c_str());
			member.is_revive=(int)atoi(vecLine[37].c_str());
			member.revive_time=(int)atoi(vecLine[39].c_str());
			member.mount_prohibited=(int)atoi(vecLine[43].c_str());
			member.treasure_prohibited=(int)atoi(vecLine[44].c_str());
			member.auto_move_wp=(int)atoi(vecLine[45].c_str());
			member.auto_search_type=(int)atoi(vecLine[46].c_str());
			member.leave_team_prohibited=(int)atoi(vecLine[50].c_str());
			member.match_prohibited=(int)atoi(vecLine[51].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
