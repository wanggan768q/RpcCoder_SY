using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//场景配置数据类
public class SceneElement
{
	public int id;               	//序号	序号（不可以超过2000）
	public int build_setting_index;	//场景unity标识	0：game 1：Game 2：SY_CS_NG_Final 3：SY_FB_SR2_Story_Dungeon_Final 4：SY_FB_YongYeHuiLang_Final 5：SY_CS_WerwolfCity 6：SY_YW_ASTW 8：SY_MaZongFB 7：SY_YW_MZCY_Final 9：SY_HD_JJC_Final 10：SY_CS_JLLD 12：SY_FB_JLZS_Final 13：SY_YW_JLZS_Final 15：SY_FB_KENS_5M_Final 19：SY_CS_SPQY_Final 20：SY_YW_FLXG_Final 22:SY_YW_ASTW_02_Final 24:SY_FB_XS_Final
	public string comment;       	//	绿色：主城/种族领地 白色：普通 黄色：副本 蓝色：PVP
	public int name;             	//场景名称	文本id
	public int scene_type_id;    	//场景类型	文本id
	public int teleport_target_id;	//小地图传送点	关联teleport_target中的id
	public int description;      	//场景描述	文本相关id
	public string background_pic;	//场景介绍图片	场景介绍图片
	public string loading_pic;   	//场景读取图片	如果不填则显示默认图
	public int thread_id;        	//线程ID	线程ID
	public int scene_type;       	//副本类型	0：场景 1：副本 2 : 阵营战场 3：竞技场
	public float valid_pos_x;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public float valid_pos_z;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public string scene_resource;	//场景资源	场景资源名称
	public string server_script_id;	//场景脚本	该场景配置脚本的名称，必填
	public int required_level;   	//所需等级	解锁该场景需要的等级
	public float required_score; 	//所需战力	解锁该场景需要的战力
	public int pre_quest;        	//前置任务	解锁该场景需要的任务
	public int teleport_id;      	//默认生成点ID	如果没有指定生成的位置，玩家会默认出现在该点
	public float toward_to;      	//传送点朝向(临时)	点地图床送到对应场景时，角色的朝向角度
	public int camera_type;      	//摄像机类型	0：不限制 1：强制2.5D
	public string pre_music;     	//前奏音乐	进入场景时播放的音乐前奏
	public string loop_music;    	//循环音乐	在该场景循环播放的音乐
	public float music_volume;   	//音乐音量	0~1
	public string special_icon;  	//世界地图标识	特殊场景在世界地图上的特殊图标
	public string mini_map;      	//小地图资源	调用的小地图的资源
	public string radar_map;     	//雷达图资源	调用的雷达图的资源
	public li map_anchor;        	//地图锚点	对应地图0.0点在UI界面上的位置 X|Y分别表示起始点坐标
	public li map_init_point;    	//地图起始点	对应场景0.0点在地图资源上的位置 0.0点为资源左下角 X|Y分别表示起始点坐标
	public li map_resource_size; 	//地图大小	对应场景在图片上的大小 X|Y分别表示长宽
	public li map_border;        	//地图边缘大小	地图纵向有效范围与地图上下边缘的误差 X|Y分别表示上边缘和下边缘的高度
	public li map_size;          	//场景规模	场景的长度和宽度 X|Y分别标示长宽
	public li map_effect_area;   	//地图有效区	对于地图文件中希望被显示部分的大小 X|Y分别标示长宽
	public lf map_offset;        	//地图偏移	和有效区域配合使用 X|Y分别标示横向和纵向 以中心为0|0点
	public float map_ratio;      	//地图比例	用来控制地图显示的缩放。默认为1
	public lf scene_shadow;      	//场景阴影	X|Y|Z代表场景中光照的方向
	public li buff;              	//buffID	进场景时触发的buff
	public int is_revive;        	//是否支持复活	1为是 0为否
	public li revive_waypoint_id;	//复活点id	
	public int revive_time;      	//就近复活时间	该场景内的就近复活cd时间 单位毫秒
	public li elite_id;          	//精英怪任务id	场景内所有精英怪id
	public li treasure_map_1_id; 	//低级藏宝图路点id	场景内所有低级藏宝图id
	public li treasure_map_2_id; 	//高级藏宝图路点id	场景内所有高级藏宝图id
	public int mount_prohibited; 	//禁用坐骑	场景内是否禁止上坐骑 0：禁止上坐骑 1：允许上坐骑
	public int treasure_prohibited;	//禁用宝物库	场景内是否禁止打开宝物库 0：禁止打开宝物库 1：允许打开宝物库
	public int auto_move_wp;     	//自动寻路起点	如果填写了值且开启了自动功能，则会自动启用自动寻路 关联路点表
	public int auto_search_type; 	//自动战斗是否全地图索敌	0：全地图索敌 1：固定距离索敌（Global_id=20） -1：场景不能挂机
	public li area_id;           	//区域id	
	public li item_type_prohibited;	//禁止使用的道具大类型（道具类型表）	举例填法：6|7|6   数量要和右边字段数量一致
	public li item_subtype_prohibited;	//禁止使用的道具小类型（道具类型表）	1|0|0|   禁止6大类的1、0和7大类的0
	public int leave_team_prohibited;	//禁止离开队伍	1该场景可以离队 0该场景不能离队
	public int match_prohibited; 	//禁止所有匹配功能，会中断当前匹配状态	1该场景禁止 0该场景不禁止

	public bool IsValidate = false;
	public SceneElement()
	{
		id = -1;
	}
};

//场景配置封装类
public class SceneTable
{

	private SceneTable()
	{
		m_mapElements = new Dictionary<int, SceneElement>();
		m_emptyItem = new SceneElement();
		m_vecAllElements = new List<SceneElement>();
	}
	private Dictionary<int, SceneElement> m_mapElements = null;
	private List<SceneElement>	m_vecAllElements = null;
	private SceneElement m_emptyItem = null;
	private static SceneTable sInstance = null;

	public static SceneTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new SceneTable();
			return sInstance;
		}
	}

	public SceneElement GetElement(int key)
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

  public List<SceneElement> GetAllElement(Predicate<SceneElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Scene.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Scene.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Scene.bin]未找到");
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
		if(vecLine.Count != 52)
		{
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="build_setting_index"){Ex.Logger.Log("Scene.csv中字段[build_setting_index]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Scene.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="scene_type_id"){Ex.Logger.Log("Scene.csv中字段[scene_type_id]位置不对应"); return false; }
		if(vecLine[5]!="teleport_target_id"){Ex.Logger.Log("Scene.csv中字段[teleport_target_id]位置不对应"); return false; }
		if(vecLine[6]!="description"){Ex.Logger.Log("Scene.csv中字段[description]位置不对应"); return false; }
		if(vecLine[7]!="background_pic"){Ex.Logger.Log("Scene.csv中字段[background_pic]位置不对应"); return false; }
		if(vecLine[8]!="loading_pic"){Ex.Logger.Log("Scene.csv中字段[loading_pic]位置不对应"); return false; }
		if(vecLine[9]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[10]!="scene_type"){Ex.Logger.Log("Scene.csv中字段[scene_type]位置不对应"); return false; }
		if(vecLine[11]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[12]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[13]!="scene_resource"){Ex.Logger.Log("Scene.csv中字段[scene_resource]位置不对应"); return false; }
		if(vecLine[14]!="server_script_id"){Ex.Logger.Log("Scene.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[15]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[16]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[17]!="pre_quest"){Ex.Logger.Log("Scene.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[18]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[19]!="toward_to"){Ex.Logger.Log("Scene.csv中字段[toward_to]位置不对应"); return false; }
		if(vecLine[20]!="camera_type"){Ex.Logger.Log("Scene.csv中字段[camera_type]位置不对应"); return false; }
		if(vecLine[21]!="pre_music"){Ex.Logger.Log("Scene.csv中字段[pre_music]位置不对应"); return false; }
		if(vecLine[22]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[23]!="music_volume"){Ex.Logger.Log("Scene.csv中字段[music_volume]位置不对应"); return false; }
		if(vecLine[24]!="special_icon"){Ex.Logger.Log("Scene.csv中字段[special_icon]位置不对应"); return false; }
		if(vecLine[25]!="mini_map"){Ex.Logger.Log("Scene.csv中字段[mini_map]位置不对应"); return false; }
		if(vecLine[26]!="radar_map"){Ex.Logger.Log("Scene.csv中字段[radar_map]位置不对应"); return false; }
		if(vecLine[27]!="map_anchor"){Ex.Logger.Log("Scene.csv中字段[map_anchor]位置不对应"); return false; }
		if(vecLine[28]!="map_init_point"){Ex.Logger.Log("Scene.csv中字段[map_init_point]位置不对应"); return false; }
		if(vecLine[29]!="map_resource_size"){Ex.Logger.Log("Scene.csv中字段[map_resource_size]位置不对应"); return false; }
		if(vecLine[30]!="map_border"){Ex.Logger.Log("Scene.csv中字段[map_border]位置不对应"); return false; }
		if(vecLine[31]!="map_size"){Ex.Logger.Log("Scene.csv中字段[map_size]位置不对应"); return false; }
		if(vecLine[32]!="map_effect_area"){Ex.Logger.Log("Scene.csv中字段[map_effect_area]位置不对应"); return false; }
		if(vecLine[33]!="map_offset"){Ex.Logger.Log("Scene.csv中字段[map_offset]位置不对应"); return false; }
		if(vecLine[34]!="map_ratio"){Ex.Logger.Log("Scene.csv中字段[map_ratio]位置不对应"); return false; }
		if(vecLine[35]!="scene_shadow"){Ex.Logger.Log("Scene.csv中字段[scene_shadow]位置不对应"); return false; }
		if(vecLine[36]!="buff"){Ex.Logger.Log("Scene.csv中字段[buff]位置不对应"); return false; }
		if(vecLine[37]!="is_revive"){Ex.Logger.Log("Scene.csv中字段[is_revive]位置不对应"); return false; }
		if(vecLine[38]!="revive_waypoint_id"){Ex.Logger.Log("Scene.csv中字段[revive_waypoint_id]位置不对应"); return false; }
		if(vecLine[39]!="revive_time"){Ex.Logger.Log("Scene.csv中字段[revive_time]位置不对应"); return false; }
		if(vecLine[40]!="elite_id"){Ex.Logger.Log("Scene.csv中字段[elite_id]位置不对应"); return false; }
		if(vecLine[41]!="treasure_map_1_id"){Ex.Logger.Log("Scene.csv中字段[treasure_map_1_id]位置不对应"); return false; }
		if(vecLine[42]!="treasure_map_2_id"){Ex.Logger.Log("Scene.csv中字段[treasure_map_2_id]位置不对应"); return false; }
		if(vecLine[43]!="mount_prohibited"){Ex.Logger.Log("Scene.csv中字段[mount_prohibited]位置不对应"); return false; }
		if(vecLine[44]!="treasure_prohibited"){Ex.Logger.Log("Scene.csv中字段[treasure_prohibited]位置不对应"); return false; }
		if(vecLine[45]!="auto_move_wp"){Ex.Logger.Log("Scene.csv中字段[auto_move_wp]位置不对应"); return false; }
		if(vecLine[46]!="auto_search_type"){Ex.Logger.Log("Scene.csv中字段[auto_search_type]位置不对应"); return false; }
		if(vecLine[47]!="area_id"){Ex.Logger.Log("Scene.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[48]!="item_type_prohibited"){Ex.Logger.Log("Scene.csv中字段[item_type_prohibited]位置不对应"); return false; }
		if(vecLine[49]!="item_subtype_prohibited"){Ex.Logger.Log("Scene.csv中字段[item_subtype_prohibited]位置不对应"); return false; }
		if(vecLine[50]!="leave_team_prohibited"){Ex.Logger.Log("Scene.csv中字段[leave_team_prohibited]位置不对应"); return false; }
		if(vecLine[51]!="match_prohibited"){Ex.Logger.Log("Scene.csv中字段[match_prohibited]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SceneElement member = new SceneElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.build_setting_index );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_type_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_target_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.background_pic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loading_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.thread_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_z);
			readPos += GameAssist.ReadString( binContent, readPos, out member.scene_resource);
			readPos += GameAssist.ReadString( binContent, readPos, out member.server_script_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_level );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.required_score);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pre_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_id );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.toward_to);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.camera_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pre_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.music_volume);
			readPos += GameAssist.ReadString( binContent, readPos, out member.special_icon);
			readPos += GameAssist.ReadString( binContent, readPos, out member.mini_map);
			readPos += GameAssist.ReadString( binContent, readPos, out member.radar_map);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_anchor);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_init_point);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_resource_size);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_border);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_size);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_effect_area);
			readPos += GameAssist.ReadString( binContent, readPos, out member.map_offset);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.map_ratio);
			readPos += GameAssist.ReadString( binContent, readPos, out member.scene_shadow);
			readPos += GameAssist.ReadString( binContent, readPos, out member.buff);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_revive );
			readPos += GameAssist.ReadString( binContent, readPos, out member.revive_waypoint_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.revive_time );
			readPos += GameAssist.ReadString( binContent, readPos, out member.elite_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_map_1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.treasure_map_2_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mount_prohibited );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_prohibited );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auto_move_wp );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.auto_search_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.area_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_type_prohibited);
			readPos += GameAssist.ReadString( binContent, readPos, out member.item_subtype_prohibited);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.leave_team_prohibited );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.match_prohibited );

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
		if(vecLine.Count != 52)
		{
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="build_setting_index"){Ex.Logger.Log("Scene.csv中字段[build_setting_index]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Scene.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="scene_type_id"){Ex.Logger.Log("Scene.csv中字段[scene_type_id]位置不对应"); return false; }
		if(vecLine[5]!="teleport_target_id"){Ex.Logger.Log("Scene.csv中字段[teleport_target_id]位置不对应"); return false; }
		if(vecLine[6]!="description"){Ex.Logger.Log("Scene.csv中字段[description]位置不对应"); return false; }
		if(vecLine[7]!="background_pic"){Ex.Logger.Log("Scene.csv中字段[background_pic]位置不对应"); return false; }
		if(vecLine[8]!="loading_pic"){Ex.Logger.Log("Scene.csv中字段[loading_pic]位置不对应"); return false; }
		if(vecLine[9]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[10]!="scene_type"){Ex.Logger.Log("Scene.csv中字段[scene_type]位置不对应"); return false; }
		if(vecLine[11]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[12]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[13]!="scene_resource"){Ex.Logger.Log("Scene.csv中字段[scene_resource]位置不对应"); return false; }
		if(vecLine[14]!="server_script_id"){Ex.Logger.Log("Scene.csv中字段[server_script_id]位置不对应"); return false; }
		if(vecLine[15]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[16]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[17]!="pre_quest"){Ex.Logger.Log("Scene.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[18]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[19]!="toward_to"){Ex.Logger.Log("Scene.csv中字段[toward_to]位置不对应"); return false; }
		if(vecLine[20]!="camera_type"){Ex.Logger.Log("Scene.csv中字段[camera_type]位置不对应"); return false; }
		if(vecLine[21]!="pre_music"){Ex.Logger.Log("Scene.csv中字段[pre_music]位置不对应"); return false; }
		if(vecLine[22]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[23]!="music_volume"){Ex.Logger.Log("Scene.csv中字段[music_volume]位置不对应"); return false; }
		if(vecLine[24]!="special_icon"){Ex.Logger.Log("Scene.csv中字段[special_icon]位置不对应"); return false; }
		if(vecLine[25]!="mini_map"){Ex.Logger.Log("Scene.csv中字段[mini_map]位置不对应"); return false; }
		if(vecLine[26]!="radar_map"){Ex.Logger.Log("Scene.csv中字段[radar_map]位置不对应"); return false; }
		if(vecLine[27]!="map_anchor"){Ex.Logger.Log("Scene.csv中字段[map_anchor]位置不对应"); return false; }
		if(vecLine[28]!="map_init_point"){Ex.Logger.Log("Scene.csv中字段[map_init_point]位置不对应"); return false; }
		if(vecLine[29]!="map_resource_size"){Ex.Logger.Log("Scene.csv中字段[map_resource_size]位置不对应"); return false; }
		if(vecLine[30]!="map_border"){Ex.Logger.Log("Scene.csv中字段[map_border]位置不对应"); return false; }
		if(vecLine[31]!="map_size"){Ex.Logger.Log("Scene.csv中字段[map_size]位置不对应"); return false; }
		if(vecLine[32]!="map_effect_area"){Ex.Logger.Log("Scene.csv中字段[map_effect_area]位置不对应"); return false; }
		if(vecLine[33]!="map_offset"){Ex.Logger.Log("Scene.csv中字段[map_offset]位置不对应"); return false; }
		if(vecLine[34]!="map_ratio"){Ex.Logger.Log("Scene.csv中字段[map_ratio]位置不对应"); return false; }
		if(vecLine[35]!="scene_shadow"){Ex.Logger.Log("Scene.csv中字段[scene_shadow]位置不对应"); return false; }
		if(vecLine[36]!="buff"){Ex.Logger.Log("Scene.csv中字段[buff]位置不对应"); return false; }
		if(vecLine[37]!="is_revive"){Ex.Logger.Log("Scene.csv中字段[is_revive]位置不对应"); return false; }
		if(vecLine[38]!="revive_waypoint_id"){Ex.Logger.Log("Scene.csv中字段[revive_waypoint_id]位置不对应"); return false; }
		if(vecLine[39]!="revive_time"){Ex.Logger.Log("Scene.csv中字段[revive_time]位置不对应"); return false; }
		if(vecLine[40]!="elite_id"){Ex.Logger.Log("Scene.csv中字段[elite_id]位置不对应"); return false; }
		if(vecLine[41]!="treasure_map_1_id"){Ex.Logger.Log("Scene.csv中字段[treasure_map_1_id]位置不对应"); return false; }
		if(vecLine[42]!="treasure_map_2_id"){Ex.Logger.Log("Scene.csv中字段[treasure_map_2_id]位置不对应"); return false; }
		if(vecLine[43]!="mount_prohibited"){Ex.Logger.Log("Scene.csv中字段[mount_prohibited]位置不对应"); return false; }
		if(vecLine[44]!="treasure_prohibited"){Ex.Logger.Log("Scene.csv中字段[treasure_prohibited]位置不对应"); return false; }
		if(vecLine[45]!="auto_move_wp"){Ex.Logger.Log("Scene.csv中字段[auto_move_wp]位置不对应"); return false; }
		if(vecLine[46]!="auto_search_type"){Ex.Logger.Log("Scene.csv中字段[auto_search_type]位置不对应"); return false; }
		if(vecLine[47]!="area_id"){Ex.Logger.Log("Scene.csv中字段[area_id]位置不对应"); return false; }
		if(vecLine[48]!="item_type_prohibited"){Ex.Logger.Log("Scene.csv中字段[item_type_prohibited]位置不对应"); return false; }
		if(vecLine[49]!="item_subtype_prohibited"){Ex.Logger.Log("Scene.csv中字段[item_subtype_prohibited]位置不对应"); return false; }
		if(vecLine[50]!="leave_team_prohibited"){Ex.Logger.Log("Scene.csv中字段[leave_team_prohibited]位置不对应"); return false; }
		if(vecLine[51]!="match_prohibited"){Ex.Logger.Log("Scene.csv中字段[match_prohibited]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)52)
			{
				return false;
			}
			SceneElement member = new SceneElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.build_setting_index=Convert.ToInt32(vecLine[1]);
			member.comment=vecLine[2];
			member.name=Convert.ToInt32(vecLine[3]);
			member.scene_type_id=Convert.ToInt32(vecLine[4]);
			member.teleport_target_id=Convert.ToInt32(vecLine[5]);
			member.description=Convert.ToInt32(vecLine[6]);
			member.background_pic=vecLine[7];
			member.loading_pic=vecLine[8];
			member.thread_id=Convert.ToInt32(vecLine[9]);
			member.scene_type=Convert.ToInt32(vecLine[10]);
			member.valid_pos_x=Convert.ToSingle(vecLine[11]);
			member.valid_pos_z=Convert.ToSingle(vecLine[12]);
			member.scene_resource=vecLine[13];
			member.server_script_id=vecLine[14];
			member.required_level=Convert.ToInt32(vecLine[15]);
			member.required_score=Convert.ToSingle(vecLine[16]);
			member.pre_quest=Convert.ToInt32(vecLine[17]);
			member.teleport_id=Convert.ToInt32(vecLine[18]);
			member.toward_to=Convert.ToSingle(vecLine[19]);
			member.camera_type=Convert.ToInt32(vecLine[20]);
			member.pre_music=vecLine[21];
			member.loop_music=vecLine[22];
			member.music_volume=Convert.ToSingle(vecLine[23]);
			member.special_icon=vecLine[24];
			member.mini_map=vecLine[25];
			member.radar_map=vecLine[26];
			member.map_anchor=vecLine[27];
			member.map_init_point=vecLine[28];
			member.map_resource_size=vecLine[29];
			member.map_border=vecLine[30];
			member.map_size=vecLine[31];
			member.map_effect_area=vecLine[32];
			member.map_offset=vecLine[33];
			member.map_ratio=Convert.ToSingle(vecLine[34]);
			member.scene_shadow=vecLine[35];
			member.buff=vecLine[36];
			member.is_revive=Convert.ToInt32(vecLine[37]);
			member.revive_waypoint_id=vecLine[38];
			member.revive_time=Convert.ToInt32(vecLine[39]);
			member.elite_id=vecLine[40];
			member.treasure_map_1_id=vecLine[41];
			member.treasure_map_2_id=vecLine[42];
			member.mount_prohibited=Convert.ToInt32(vecLine[43]);
			member.treasure_prohibited=Convert.ToInt32(vecLine[44]);
			member.auto_move_wp=Convert.ToInt32(vecLine[45]);
			member.auto_search_type=Convert.ToInt32(vecLine[46]);
			member.area_id=vecLine[47];
			member.item_type_prohibited=vecLine[48];
			member.item_subtype_prohibited=vecLine[49];
			member.leave_team_prohibited=Convert.ToInt32(vecLine[50]);
			member.match_prohibited=Convert.ToInt32(vecLine[51]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
