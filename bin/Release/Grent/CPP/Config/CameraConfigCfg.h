#ifndef __CAMERACONFIG_CONFIG_H
#define __CAMERACONFIG_CONFIG_H

#include "ConfigUtil.h"
#define printf_message(_argg) printf(_argg)

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
	CameraConfigElement()
	{
		id = -1;
		m_bIsValidate=false;
	}
};

//摄像机配置配置封装类
class CameraConfigTable
{
	friend class TableData;
private:
	CameraConfigTable(){}
	~CameraConfigTable(){}
	map<int, CameraConfigElement>	m_mapElements;
	vector<CameraConfigElement>	m_vecAllElements;
	CameraConfigElement m_emptyItem;
public:
	static CameraConfigTable& Instance()
	{
		static CameraConfigTable sInstance;
		return sInstance;
	}

	CameraConfigElement GetElement(int key)
	{
		if( m_mapElements.count(key)>0 )
			return m_mapElements[key];
		return m_emptyItem;
	}

	bool HasElement(int key)
	{
		return m_mapElements.find(key) != m_mapElements.end();
	}

	vector<CameraConfigElement>&	GetAllElement()
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
		if( LoadConfigContent("CameraConfig.csv", strTableContent ) )
			return LoadCsv( strTableContent );
		if( !LoadConfigContent("CameraConfig.bin", strTableContent ) )
		{
			printf_message("配置文件[CameraConfig.bin]未找到");
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
		if(vecLine.size() != 21)
		{
			printf_message("CameraConfig.csv中列数量与生成的代码不匹配!");
			assert(false);
			return false;
		}
		if(vecLine[0]!="id"){printf_message("CameraConfig.csv中字段[id]位置不对应 ");assert(false); return false; }
		if(vecLine[1]!="comment"){printf_message("CameraConfig.csv中字段[comment]位置不对应 ");assert(false); return false; }
		if(vecLine[2]!="clipping"){printf_message("CameraConfig.csv中字段[clipping]位置不对应 ");assert(false); return false; }
		if(vecLine[3]!="field_of_view"){printf_message("CameraConfig.csv中字段[field_of_view]位置不对应 ");assert(false); return false; }
		if(vecLine[4]!="fog_alpha"){printf_message("CameraConfig.csv中字段[fog_alpha]位置不对应 ");assert(false); return false; }
		if(vecLine[5]!="fog_noise"){printf_message("CameraConfig.csv中字段[fog_noise]位置不对应 ");assert(false); return false; }
		if(vecLine[6]!="fog_distance"){printf_message("CameraConfig.csv中字段[fog_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[7]!="fog_distance_fall_off"){printf_message("CameraConfig.csv中字段[fog_distance_fall_off]位置不对应 ");assert(false); return false; }
		if(vecLine[8]!="fog_max_distance"){printf_message("CameraConfig.csv中字段[fog_max_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[9]!="fog_height"){printf_message("CameraConfig.csv中字段[fog_height]位置不对应 ");assert(false); return false; }
		if(vecLine[10]!="fog_height_fall_off"){printf_message("CameraConfig.csv中字段[fog_height_fall_off]位置不对应 ");assert(false); return false; }
		if(vecLine[11]!="fog_baseline_height"){printf_message("CameraConfig.csv中字段[fog_baseline_height]位置不对应 ");assert(false); return false; }
		if(vecLine[12]!="fog_color"){printf_message("CameraConfig.csv中字段[fog_color]位置不对应 ");assert(false); return false; }
		if(vecLine[13]!="fog_color_2"){printf_message("CameraConfig.csv中字段[fog_color_2]位置不对应 ");assert(false); return false; }
		if(vecLine[14]!="bloom_threshold"){printf_message("CameraConfig.csv中字段[bloom_threshold]位置不对应 ");assert(false); return false; }
		if(vecLine[15]!="bloom_intensity"){printf_message("CameraConfig.csv中字段[bloom_intensity]位置不对应 ");assert(false); return false; }
		if(vecLine[16]!="bloom_blur_size"){printf_message("CameraConfig.csv中字段[bloom_blur_size]位置不对应 ");assert(false); return false; }
		if(vecLine[17]!="bloom_iteration"){printf_message("CameraConfig.csv中字段[bloom_iteration]位置不对应 ");assert(false); return false; }
		if(vecLine[18]!="camera_distance"){printf_message("CameraConfig.csv中字段[camera_distance]位置不对应 ");assert(false); return false; }
		if(vecLine[19]!="camera_angle_vertical"){printf_message("CameraConfig.csv中字段[camera_angle_vertical]位置不对应 ");assert(false); return false; }
		if(vecLine[20]!="camera_angle_horizontal"){printf_message("CameraConfig.csv中字段[camera_angle_horizontal]位置不对应 ");assert(false); return false; }

		while(true)
		{
			vecLine = ReadCsvLine( strContent, contentOffset );
			if((int)vecLine.size() == 0 )
				break;
			if((int)vecLine.size() != (int)21)
			{
				assert(false);
				return false;
			}
			CameraConfigElement	member;
			member.id=(int)atoi(vecLine[0].c_str());
			member.comment=vecLine[1];
			member.field_of_view=(float)atof(vecLine[3].c_str());
			member.fog_alpha=(float)atof(vecLine[4].c_str());
			member.fog_noise=(float)atof(vecLine[5].c_str());
			member.fog_distance=(float)atof(vecLine[6].c_str());
			member.fog_distance_fall_off=(float)atof(vecLine[7].c_str());
			member.fog_max_distance=(float)atof(vecLine[8].c_str());
			member.fog_height=(float)atof(vecLine[9].c_str());
			member.fog_height_fall_off=(float)atof(vecLine[10].c_str());
			member.fog_baseline_height=(float)atof(vecLine[11].c_str());
			member.bloom_threshold=(float)atof(vecLine[14].c_str());
			member.bloom_intensity=(float)atof(vecLine[15].c_str());
			member.bloom_blur_size=(float)atof(vecLine[16].c_str());
			member.bloom_iteration=(int)atoi(vecLine[17].c_str());
			member.camera_distance=(float)atof(vecLine[18].c_str());
			member.camera_angle_vertical=(float)atof(vecLine[19].c_str());
			member.camera_angle_horizontal=(float)atof(vecLine[20].c_str());

			member.SetIsValidate(true);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};

#endif
