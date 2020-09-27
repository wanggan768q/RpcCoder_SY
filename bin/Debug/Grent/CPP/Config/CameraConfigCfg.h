#ifndef __CAMERACONFIG_CONFIG_H
#define __CAMERACONFIG_CONFIG_H

#include "BaseDef.h"



using namespace std;

//摄像机配置配置数据结构
struct CameraConfigElement
{
	friend class CameraConfigTable;
	int id;                      	//序号	摄像机配置序号
	string comment;              	//备注	备注
	vector<float> clipping;      	//摄像机剪裁	视野相关 摄像机剪裁相关 最小值|最大值
	float field_of_view;         	//摄像机视野	视野相关 影响摄像机内视野的大小，默认70
	float fog_alpha;             	//雾alpha值	决定雾的透明度
	float fog_noise;             	//雾噪点强度	影响雾的不规则性
	float fog_distance;          	//雾距	雾的距离摄像机的距离 起始距离
	float fog_distance_fall_off; 	//雾距衰减	雾的距离摄像机的距离 衰减过度
	float fog_max_distance;      	//雾距最大距离	雾的距离摄像机的距离 最大距离
	float fog_height;            	//雾高度	雾距离摄像机的高度
	float fog_height_fall_off;   	//雾高度衰减	雾距离摄像
	float fog_baseline_height;   	//雾基准高度	默认值为0
	vector<int> fog_color;       	//雾颜色1	雾底层的颜色 0~255 R|G|B|A
	vector<int> fog_color_2;     	//雾颜色2	雾高层的颜色 0~255 R|G|B|A
	float bloom_threshold;       	//泛光起点	泛光离摄像机的距离 0~1.5
	float bloom_intensity;       	//泛光密度	影响泛光的强度 0~2.5
	float bloom_blur_size;       	//泛光模糊大小	像素大小 0.25~5.5
	int bloom_iteration;         	//泛光迭代次数	迭代次数影响效果和效率 1~4
	float camera_distance;       	//摄像机距离	2.5D状态下的摄像机距角色的距离
	float camera_angle_vertical; 	//摄像机俯角	2.5D状态下摄像机的默认俯角
	float camera_angle_horizontal;	//摄像机横向角度	2.5D状态下摄像机的朝向

private:

public:

	CameraConfigElement()
	{
		id = -1;

	}
};

//摄像机配置配置封装类
class CameraConfigTable
{
	public:
	typedef std::unique_ptr<CameraConfigElement> ele_ptr_type;
	typedef std::unordered_map<int, ele_ptr_type> MapElementMap;
	typedef vector<int> vec_type;
	//typedef std::set<int> set_type;
	typedef std::function<void()> ReloadCallback;
	typedef std::vector<ReloadCallback> reload_vec_type;
private:
	CameraConfigTable();
	~CameraConfigTable();

	vec_type m_vElementID;
	MapElementMap	m_mapElements;
	reload_vec_type m_vReLoadCb;

public:
	static CameraConfigTable& Instance();

	void RegisterReLoadCb(const ReloadCallback &cb);

	const CameraConfigElement* GetElement(int key);

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
