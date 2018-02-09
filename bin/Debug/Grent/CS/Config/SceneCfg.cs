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
	public int build_setting_index;	//场景unity标识	0：game 1：Game 2：SY_CS_NG_Final 3：SY_FB_SR2_Story_Dungeon_Final 4：SY_FB_YongYeHuiLang_Final
	public string comment;       	//	
	public int name;             	//场景名称	文本id
	public int description;      	//场景描述	文本相关id
	public string background_pic;	//场景介绍图片	场景介绍图片
	public string loading_pic;   	//场景读取图片	如果不填则显示默认图
	public int thread_id;        	//线程ID	线程ID
	public int scene_type;       	//副本类型	0：场景 1：副本 
	public float valid_pos_x;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public float valid_pos_z;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public string scene_resource;	//场景资源	场景资源名称
	public int required_level;   	//所需等级	解锁该场景需要的等级
	public float required_score; 	//所需战力	解锁该场景需要的战力
	public int pre_quest;        	//前置任务	解锁该场景需要的任务
	public int teleport_id;      	//默认生成点ID	如果没有指定生成的位置，玩家会默认出现在该点
	public int camera_type;      	//摄像机类型	0：不限制 1：强制2.5D
	public string pre_music;     	//前奏音乐	进入场景时播放的音乐前奏
	public string loop_music;    	//循环音乐	在该场景循环播放的音乐
	public float music_volume;   	//音乐音量	0~1

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
		if(vecLine.Count != 20)
		{
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="build_setting_index"){Ex.Logger.Log("Scene.csv中字段[build_setting_index]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Scene.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="description"){Ex.Logger.Log("Scene.csv中字段[description]位置不对应"); return false; }
		if(vecLine[5]!="background_pic"){Ex.Logger.Log("Scene.csv中字段[background_pic]位置不对应"); return false; }
		if(vecLine[6]!="loading_pic"){Ex.Logger.Log("Scene.csv中字段[loading_pic]位置不对应"); return false; }
		if(vecLine[7]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[8]!="scene_type"){Ex.Logger.Log("Scene.csv中字段[scene_type]位置不对应"); return false; }
		if(vecLine[9]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[10]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[11]!="scene_resource"){Ex.Logger.Log("Scene.csv中字段[scene_resource]位置不对应"); return false; }
		if(vecLine[12]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[13]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[14]!="pre_quest"){Ex.Logger.Log("Scene.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[15]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[16]!="camera_type"){Ex.Logger.Log("Scene.csv中字段[camera_type]位置不对应"); return false; }
		if(vecLine[17]!="pre_music"){Ex.Logger.Log("Scene.csv中字段[pre_music]位置不对应"); return false; }
		if(vecLine[18]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[19]!="music_volume"){Ex.Logger.Log("Scene.csv中字段[music_volume]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SceneElement member = new SceneElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.build_setting_index );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadString( binContent, readPos, out member.background_pic);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loading_pic);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.thread_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.scene_type );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_z);
			readPos += GameAssist.ReadString( binContent, readPos, out member.scene_resource);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_level );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.required_score);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.pre_quest );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.camera_type );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pre_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.music_volume);

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
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="build_setting_index"){Ex.Logger.Log("Scene.csv中字段[build_setting_index]位置不对应"); return false; }
		if(vecLine[2]!="comment"){Ex.Logger.Log("Scene.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[3]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[4]!="description"){Ex.Logger.Log("Scene.csv中字段[description]位置不对应"); return false; }
		if(vecLine[5]!="background_pic"){Ex.Logger.Log("Scene.csv中字段[background_pic]位置不对应"); return false; }
		if(vecLine[6]!="loading_pic"){Ex.Logger.Log("Scene.csv中字段[loading_pic]位置不对应"); return false; }
		if(vecLine[7]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[8]!="scene_type"){Ex.Logger.Log("Scene.csv中字段[scene_type]位置不对应"); return false; }
		if(vecLine[9]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[10]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[11]!="scene_resource"){Ex.Logger.Log("Scene.csv中字段[scene_resource]位置不对应"); return false; }
		if(vecLine[12]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[13]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[14]!="pre_quest"){Ex.Logger.Log("Scene.csv中字段[pre_quest]位置不对应"); return false; }
		if(vecLine[15]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[16]!="camera_type"){Ex.Logger.Log("Scene.csv中字段[camera_type]位置不对应"); return false; }
		if(vecLine[17]!="pre_music"){Ex.Logger.Log("Scene.csv中字段[pre_music]位置不对应"); return false; }
		if(vecLine[18]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[19]!="music_volume"){Ex.Logger.Log("Scene.csv中字段[music_volume]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)20)
			{
				return false;
			}
			SceneElement member = new SceneElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.build_setting_index=Convert.ToInt32(vecLine[1]);
			member.comment=vecLine[2];
			member.name=Convert.ToInt32(vecLine[3]);
			member.description=Convert.ToInt32(vecLine[4]);
			member.background_pic=vecLine[5];
			member.loading_pic=vecLine[6];
			member.thread_id=Convert.ToInt32(vecLine[7]);
			member.scene_type=Convert.ToInt32(vecLine[8]);
			member.valid_pos_x=Convert.ToSingle(vecLine[9]);
			member.valid_pos_z=Convert.ToSingle(vecLine[10]);
			member.scene_resource=vecLine[11];
			member.required_level=Convert.ToInt32(vecLine[12]);
			member.required_score=Convert.ToSingle(vecLine[13]);
			member.pre_quest=Convert.ToInt32(vecLine[14]);
			member.teleport_id=Convert.ToInt32(vecLine[15]);
			member.camera_type=Convert.ToInt32(vecLine[16]);
			member.pre_music=vecLine[17];
			member.loop_music=vecLine[18];
			member.music_volume=Convert.ToSingle(vecLine[19]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
