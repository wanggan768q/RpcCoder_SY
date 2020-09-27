using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//摄像机配置配置数据类
public class CameraConfigElement
{
	public int id;               	//序号	摄像机配置序号
	public lf clipping;          	//摄像机剪裁	视野相关 摄像机剪裁相关 最小值|最大值
	public float field_of_view;  	//摄像机视野	视野相关 影响摄像机内视野的大小，默认70
	public float fog_alpha;      	//雾alpha值	决定雾的透明度
	public float fog_noise;      	//雾噪点强度	影响雾的不规则性
	public float fog_distance;   	//雾距	雾的距离摄像机的距离 起始距离
	public float fog_distance_fall_off;	//雾距衰减	雾的距离摄像机的距离 衰减过度
	public float fog_max_distance;	//雾距最大距离	雾的距离摄像机的距离 最大距离
	public float fog_height;     	//雾高度	雾距离摄像机的高度
	public float fog_height_fall_off;	//雾高度衰减	雾距离摄像
	public float fog_baseline_height;	//雾基准高度	默认值为0
	public li fog_color;         	//雾颜色1	雾底层的颜色 0~255 R|G|B|A
	public li fog_color_2;       	//雾颜色2	雾高层的颜色 0~255 R|G|B|A
	public float bloom_threshold;	//泛光起点	泛光离摄像机的距离 0~1.5
	public float bloom_intensity;	//泛光密度	影响泛光的强度 0~2.5
	public float bloom_blur_size;	//泛光模糊大小	像素大小 0.25~5.5
	public int bloom_iteration;  	//泛光迭代次数	迭代次数影响效果和效率 1~4
	public float camera_distance;	//摄像机距离	2.5D状态下的摄像机距角色的距离
	public float camera_angle_vertical;	//摄像机俯角	2.5D状态下摄像机的默认俯角
	public float camera_angle_horizontal;	//摄像机横向角度	2.5D状态下摄像机的朝向

	public bool IsValidate = false;
	public CameraConfigElement()
	{
		id = -1;
	}
};

//摄像机配置配置封装类
public class CameraConfigTable
{

	private CameraConfigTable()
	{
		m_mapElements = new Dictionary<int, CameraConfigElement>();
		m_emptyItem = new CameraConfigElement();
		m_vecAllElements = new List<CameraConfigElement>();
	}
	private Dictionary<int, CameraConfigElement> m_mapElements = null;
	private List<CameraConfigElement>	m_vecAllElements = null;
	private CameraConfigElement m_emptyItem = null;
	private static CameraConfigTable sInstance = null;

	public static CameraConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CameraConfigTable();
			return sInstance;
		}
	}

	public CameraConfigElement GetElement(int key)
	{
		if( m_mapElements.ContainsKey(key) )
			return m_mapElements[key];
		return null;
	}

	public int GetElementCount()
	{
		return m_mapElements.Count;
	}
	public bool HasElement(int key)
	{
		return m_mapElements.ContainsKey(key);
	}

  public List<CameraConfigElement> GetAllElement(Predicate<CameraConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CameraConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CameraConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CameraConfig.bin]未找到");
			return false;
		}
		return LoadBin(binTableContent);
	}


	public bool LoadBin(byte[] binContent)
	{
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int nCol, nRow;
		int readPos = 0;
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nCol );
		readPos += GameAssist.ReadInt32Variant( binContent, readPos, out nRow );
		List<string> vecLine = new List<string>(nCol);
		List<int> vecHeadType = new List<int>(nCol);
        string tmpStr;
        int tmpInt;
		for( int i=0; i<nCol; i++ )
		{
            readPos += GameAssist.ReadString(binContent, readPos, out tmpStr);
            readPos += GameAssist.ReadInt32Variant(binContent, readPos, out tmpInt);
            vecLine.Add(tmpStr);
            vecHeadType.Add(tmpInt);
		}
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("CameraConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CameraConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="clipping"){Ex.Logger.Log("CameraConfig.csv中字段[clipping]位置不对应"); return false; }
		if(vecLine[2]!="field_of_view"){Ex.Logger.Log("CameraConfig.csv中字段[field_of_view]位置不对应"); return false; }
		if(vecLine[3]!="fog_alpha"){Ex.Logger.Log("CameraConfig.csv中字段[fog_alpha]位置不对应"); return false; }
		if(vecLine[4]!="fog_noise"){Ex.Logger.Log("CameraConfig.csv中字段[fog_noise]位置不对应"); return false; }
		if(vecLine[5]!="fog_distance"){Ex.Logger.Log("CameraConfig.csv中字段[fog_distance]位置不对应"); return false; }
		if(vecLine[6]!="fog_distance_fall_off"){Ex.Logger.Log("CameraConfig.csv中字段[fog_distance_fall_off]位置不对应"); return false; }
		if(vecLine[7]!="fog_max_distance"){Ex.Logger.Log("CameraConfig.csv中字段[fog_max_distance]位置不对应"); return false; }
		if(vecLine[8]!="fog_height"){Ex.Logger.Log("CameraConfig.csv中字段[fog_height]位置不对应"); return false; }
		if(vecLine[9]!="fog_height_fall_off"){Ex.Logger.Log("CameraConfig.csv中字段[fog_height_fall_off]位置不对应"); return false; }
		if(vecLine[10]!="fog_baseline_height"){Ex.Logger.Log("CameraConfig.csv中字段[fog_baseline_height]位置不对应"); return false; }
		if(vecLine[11]!="fog_color"){Ex.Logger.Log("CameraConfig.csv中字段[fog_color]位置不对应"); return false; }
		if(vecLine[12]!="fog_color_2"){Ex.Logger.Log("CameraConfig.csv中字段[fog_color_2]位置不对应"); return false; }
		if(vecLine[13]!="bloom_threshold"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_threshold]位置不对应"); return false; }
		if(vecLine[14]!="bloom_intensity"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_intensity]位置不对应"); return false; }
		if(vecLine[15]!="bloom_blur_size"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_blur_size]位置不对应"); return false; }
		if(vecLine[16]!="bloom_iteration"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_iteration]位置不对应"); return false; }
		if(vecLine[17]!="camera_distance"){Ex.Logger.Log("CameraConfig.csv中字段[camera_distance]位置不对应"); return false; }
		if(vecLine[18]!="camera_angle_vertical"){Ex.Logger.Log("CameraConfig.csv中字段[camera_angle_vertical]位置不对应"); return false; }
		if(vecLine[19]!="camera_angle_horizontal"){Ex.Logger.Log("CameraConfig.csv中字段[camera_angle_horizontal]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CameraConfigElement member = new CameraConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.clipping);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.field_of_view);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_alpha);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_noise);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_distance_fall_off);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_max_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_height);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_height_fall_off);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.fog_baseline_height);
			readPos += GameAssist.ReadString( binContent, readPos, out member.fog_color);
			readPos += GameAssist.ReadString( binContent, readPos, out member.fog_color_2);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.bloom_threshold);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.bloom_intensity);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.bloom_blur_size);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.bloom_iteration );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.camera_distance);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.camera_angle_vertical);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.camera_angle_horizontal);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
	public bool LoadCsv(string strContent)
	{
		if( strContent.Length == 0 )
			return false;
		m_mapElements.Clear();
		m_vecAllElements.Clear();
		int contentOffset = 0;
		List<string> vecLine;
		vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("CameraConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CameraConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="clipping"){Ex.Logger.Log("CameraConfig.csv中字段[clipping]位置不对应"); return false; }
		if(vecLine[2]!="field_of_view"){Ex.Logger.Log("CameraConfig.csv中字段[field_of_view]位置不对应"); return false; }
		if(vecLine[3]!="fog_alpha"){Ex.Logger.Log("CameraConfig.csv中字段[fog_alpha]位置不对应"); return false; }
		if(vecLine[4]!="fog_noise"){Ex.Logger.Log("CameraConfig.csv中字段[fog_noise]位置不对应"); return false; }
		if(vecLine[5]!="fog_distance"){Ex.Logger.Log("CameraConfig.csv中字段[fog_distance]位置不对应"); return false; }
		if(vecLine[6]!="fog_distance_fall_off"){Ex.Logger.Log("CameraConfig.csv中字段[fog_distance_fall_off]位置不对应"); return false; }
		if(vecLine[7]!="fog_max_distance"){Ex.Logger.Log("CameraConfig.csv中字段[fog_max_distance]位置不对应"); return false; }
		if(vecLine[8]!="fog_height"){Ex.Logger.Log("CameraConfig.csv中字段[fog_height]位置不对应"); return false; }
		if(vecLine[9]!="fog_height_fall_off"){Ex.Logger.Log("CameraConfig.csv中字段[fog_height_fall_off]位置不对应"); return false; }
		if(vecLine[10]!="fog_baseline_height"){Ex.Logger.Log("CameraConfig.csv中字段[fog_baseline_height]位置不对应"); return false; }
		if(vecLine[11]!="fog_color"){Ex.Logger.Log("CameraConfig.csv中字段[fog_color]位置不对应"); return false; }
		if(vecLine[12]!="fog_color_2"){Ex.Logger.Log("CameraConfig.csv中字段[fog_color_2]位置不对应"); return false; }
		if(vecLine[13]!="bloom_threshold"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_threshold]位置不对应"); return false; }
		if(vecLine[14]!="bloom_intensity"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_intensity]位置不对应"); return false; }
		if(vecLine[15]!="bloom_blur_size"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_blur_size]位置不对应"); return false; }
		if(vecLine[16]!="bloom_iteration"){Ex.Logger.Log("CameraConfig.csv中字段[bloom_iteration]位置不对应"); return false; }
		if(vecLine[17]!="camera_distance"){Ex.Logger.Log("CameraConfig.csv中字段[camera_distance]位置不对应"); return false; }
		if(vecLine[18]!="camera_angle_vertical"){Ex.Logger.Log("CameraConfig.csv中字段[camera_angle_vertical]位置不对应"); return false; }
		if(vecLine[19]!="camera_angle_horizontal"){Ex.Logger.Log("CameraConfig.csv中字段[camera_angle_horizontal]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)20)
			{
				return false;
			}
			CameraConfigElement member = new CameraConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.clipping=vecLine[1];
			member.field_of_view=Convert.ToSingle(vecLine[2]);
			member.fog_alpha=Convert.ToSingle(vecLine[3]);
			member.fog_noise=Convert.ToSingle(vecLine[4]);
			member.fog_distance=Convert.ToSingle(vecLine[5]);
			member.fog_distance_fall_off=Convert.ToSingle(vecLine[6]);
			member.fog_max_distance=Convert.ToSingle(vecLine[7]);
			member.fog_height=Convert.ToSingle(vecLine[8]);
			member.fog_height_fall_off=Convert.ToSingle(vecLine[9]);
			member.fog_baseline_height=Convert.ToSingle(vecLine[10]);
			member.fog_color=vecLine[11];
			member.fog_color_2=vecLine[12];
			member.bloom_threshold=Convert.ToSingle(vecLine[13]);
			member.bloom_intensity=Convert.ToSingle(vecLine[14]);
			member.bloom_blur_size=Convert.ToSingle(vecLine[15]);
			member.bloom_iteration=Convert.ToInt32(vecLine[16]);
			member.camera_distance=Convert.ToSingle(vecLine[17]);
			member.camera_angle_vertical=Convert.ToSingle(vecLine[18]);
			member.camera_angle_horizontal=Convert.ToSingle(vecLine[19]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
