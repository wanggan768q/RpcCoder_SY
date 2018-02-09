#ifndef __CAMERACONFIG_CONFIG_H
#define __CAMERACONFIG_CONFIG_H

#include "CommonDefine.h"
#include "DK_Assertx.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/typeof/typeof.hpp>

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


//摄像机配置配置数据结构
struct CameraConfigElement
{
	friend class CameraConfigTable;
	int entry_id;                	//序号	摄像机配置序号
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
		entry_id = -1;
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
	typedef unordered_map<int, CameraConfigElement> MapElementMap;
	MapElementMap	m_mapElements;
	vector<CameraConfigElement>	m_vecAllElements;
	CameraConfigElement m_emptyItem;
public:
	static CameraConfigTable& Instance()
	{
		static CameraConfigTable sInstance;
		return sInstance;
	}

	const CameraConfigElement* GetElement(int key)
	{
		MapElementMap::iterator it = m_mapElements.find(key);
		if (it == m_mapElements.end())
		{
			AssertEx(false, std::string(std::string("CameraConfigTable: ") + std::to_string(key)).c_str());
			return NULL;
		}
		return &it->second;
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
		#ifdef CONFIG_JSON
		return LoadJson("CameraConfig.json");
		#else
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
		#endif

		
	}

	bool LoadJson(const std::string& jsonFile)
	{
		boost::property_tree::ptree sms_array;
		boost::property_tree::json_parser::read_json(std::string(CONFIG_PATH) + jsonFile, sms_array);
		//boost::property_tree::ptree sms_array = parse.get_child("data");

		vector<string> vecLine;

		

		BOOST_FOREACH(boost::property_tree::ptree::value_type& v, sms_array)
		{
			boost::property_tree::ptree p = v.second;

			CameraConfigElement	member;

						member.entry_id=p.get<int>("entry_id");
			member.comment=p.get<string>("comment");
			boost::property_tree::ptree sms_array_childclipping = p.get_child("clipping");
			for (BOOST_AUTO(pos, sms_array_childclipping.begin()); pos != sms_array_childclipping.end(); ++pos)
			{
				float n = pos->second.get_value<float>(); 
				member.clipping.push_back(n);
			}
			member.field_of_view=p.get<float>("field_of_view");
			member.fog_alpha=p.get<float>("fog_alpha");
			member.fog_noise=p.get<float>("fog_noise");
			member.fog_distance=p.get<float>("fog_distance");
			member.fog_distance_fall_off=p.get<float>("fog_distance_fall_off");
			member.fog_max_distance=p.get<float>("fog_max_distance");
			member.fog_height=p.get<float>("fog_height");
			member.fog_height_fall_off=p.get<float>("fog_height_fall_off");
			member.fog_baseline_height=p.get<float>("fog_baseline_height");
			boost::property_tree::ptree sms_array_childfog_color = p.get_child("fog_color");
			for (BOOST_AUTO(pos, sms_array_childfog_color.begin()); pos != sms_array_childfog_color.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.fog_color.push_back(n);
			}
			boost::property_tree::ptree sms_array_childfog_color_2 = p.get_child("fog_color_2");
			for (BOOST_AUTO(pos, sms_array_childfog_color_2.begin()); pos != sms_array_childfog_color_2.end(); ++pos)
			{
				int n = pos->second.get_value<int>(); 
				member.fog_color_2.push_back(n);
			}
			member.bloom_threshold=p.get<float>("bloom_threshold");
			member.bloom_intensity=p.get<float>("bloom_intensity");
			member.bloom_blur_size=p.get<float>("bloom_blur_size");
			member.bloom_iteration=p.get<int>("bloom_iteration");
			member.camera_distance=p.get<float>("camera_distance");
			member.camera_angle_vertical=p.get<float>("camera_angle_vertical");
			member.camera_angle_horizontal=p.get<float>("camera_angle_horizontal");


			member.SetIsValidate(true);
			m_mapElements[member.entry_id] = member;
		}

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
		if(vecLine[0]!="entry_id"){printf_message("CameraConfig.csv中字段[entry_id]位置不对应 ");assert(false); return false; }
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
			member.entry_id=(int)atoi(vecLine[0].c_str());
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
			m_mapElements[member.entry_id] = member;
		}
		return true;
	}

	vector<string> ReadCsvLine(string strContent,int contentOffset)
	{
		vector<string> temp;
		return temp;

	}
};

#endif
