using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//场景配置数据类
public class SceneElement
{
	public int id;               	//序号	序号
	public string name;          	//名字	名字
	public int thread_id;        	//线程ID	线程ID
	public int is_dungeon;       	//是否是副本	是否是副本
	public float valid_pos_x;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public float valid_pos_z;    	//初始位置	如果进入一个不可进入的区域，默认给玩家一个进入位置
	public int dungeon_type;     	//副本类型	
	public int difficult;        	//难度	
	public int required_level;   	//所需等级	
	public float required_score; 	//所需战力	
	public int required_num;     	//所需玩家数量	
	public int required_last_dungeon_id;	//所需前置副本ID	
	public int reset_type;       	//重置类型	
	public int finish_amount;    	//允许玩家完成次数	
	public int name_id;          	//副本名字ID	
	public int describle_id;     	//副本描述ID	
	public string picture_path;  	//副本图片路径	
	public int teleport_id;      	//传送路点ID	
	public string reward_boss_ui;	//boss掉落数组	
	public int First_reward_ui;  	//首通奖励礼包ID	
	public int general_reward__ui;	//非首通奖励礼包ID	
	public int is_transfer;      	//是否需要装备中转表	
	public string start_music;   	//开启音乐	
	public string loop_music;    	//循环音乐	
	public int endingboss_id;    	//最后boss ID	
	public int duration_time;    	//副本存活时间	
	public int end_time;         	//副本结算时间	

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
		if(vecLine.Count != 27)
		{
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[3]!="is_dungeon"){Ex.Logger.Log("Scene.csv中字段[is_dungeon]位置不对应"); return false; }
		if(vecLine[4]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[5]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[6]!="dungeon_type"){Ex.Logger.Log("Scene.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[7]!="difficult"){Ex.Logger.Log("Scene.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[8]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[9]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[10]!="required_num"){Ex.Logger.Log("Scene.csv中字段[required_num]位置不对应"); return false; }
		if(vecLine[11]!="required_last_dungeon_id"){Ex.Logger.Log("Scene.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[12]!="reset_type"){Ex.Logger.Log("Scene.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[13]!="finish_amount"){Ex.Logger.Log("Scene.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[14]!="name_id"){Ex.Logger.Log("Scene.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[15]!="describle_id"){Ex.Logger.Log("Scene.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[16]!="picture_path"){Ex.Logger.Log("Scene.csv中字段[picture_path]位置不对应"); return false; }
		if(vecLine[17]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[18]!="reward_boss_ui"){Ex.Logger.Log("Scene.csv中字段[reward_boss_ui]位置不对应"); return false; }
		if(vecLine[19]!="First_reward_ui"){Ex.Logger.Log("Scene.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[20]!="general_reward__ui"){Ex.Logger.Log("Scene.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[21]!="is_transfer"){Ex.Logger.Log("Scene.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[22]!="start_music"){Ex.Logger.Log("Scene.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[23]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[24]!="endingboss_id"){Ex.Logger.Log("Scene.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[25]!="duration_time"){Ex.Logger.Log("Scene.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[26]!="end_time"){Ex.Logger.Log("Scene.csv中字段[end_time]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			SceneElement member = new SceneElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.name);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.thread_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_dungeon );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_x);
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.valid_pos_z);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.dungeon_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.difficult );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_level );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.required_score);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_num );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_last_dungeon_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reset_type );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.finish_amount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.describle_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.picture_path);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.teleport_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_boss_ui);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.First_reward_ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.general_reward__ui );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_transfer );
			readPos += GameAssist.ReadString( binContent, readPos, out member.start_music);
			readPos += GameAssist.ReadString( binContent, readPos, out member.loop_music);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.endingboss_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.duration_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.end_time );

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
		if(vecLine.Count != 27)
		{
			Ex.Logger.Log("Scene.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Scene.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="name"){Ex.Logger.Log("Scene.csv中字段[name]位置不对应"); return false; }
		if(vecLine[2]!="thread_id"){Ex.Logger.Log("Scene.csv中字段[thread_id]位置不对应"); return false; }
		if(vecLine[3]!="is_dungeon"){Ex.Logger.Log("Scene.csv中字段[is_dungeon]位置不对应"); return false; }
		if(vecLine[4]!="valid_pos_x"){Ex.Logger.Log("Scene.csv中字段[valid_pos_x]位置不对应"); return false; }
		if(vecLine[5]!="valid_pos_z"){Ex.Logger.Log("Scene.csv中字段[valid_pos_z]位置不对应"); return false; }
		if(vecLine[6]!="dungeon_type"){Ex.Logger.Log("Scene.csv中字段[dungeon_type]位置不对应"); return false; }
		if(vecLine[7]!="difficult"){Ex.Logger.Log("Scene.csv中字段[difficult]位置不对应"); return false; }
		if(vecLine[8]!="required_level"){Ex.Logger.Log("Scene.csv中字段[required_level]位置不对应"); return false; }
		if(vecLine[9]!="required_score"){Ex.Logger.Log("Scene.csv中字段[required_score]位置不对应"); return false; }
		if(vecLine[10]!="required_num"){Ex.Logger.Log("Scene.csv中字段[required_num]位置不对应"); return false; }
		if(vecLine[11]!="required_last_dungeon_id"){Ex.Logger.Log("Scene.csv中字段[required_last_dungeon_id]位置不对应"); return false; }
		if(vecLine[12]!="reset_type"){Ex.Logger.Log("Scene.csv中字段[reset_type]位置不对应"); return false; }
		if(vecLine[13]!="finish_amount"){Ex.Logger.Log("Scene.csv中字段[finish_amount]位置不对应"); return false; }
		if(vecLine[14]!="name_id"){Ex.Logger.Log("Scene.csv中字段[name_id]位置不对应"); return false; }
		if(vecLine[15]!="describle_id"){Ex.Logger.Log("Scene.csv中字段[describle_id]位置不对应"); return false; }
		if(vecLine[16]!="picture_path"){Ex.Logger.Log("Scene.csv中字段[picture_path]位置不对应"); return false; }
		if(vecLine[17]!="teleport_id"){Ex.Logger.Log("Scene.csv中字段[teleport_id]位置不对应"); return false; }
		if(vecLine[18]!="reward_boss_ui"){Ex.Logger.Log("Scene.csv中字段[reward_boss_ui]位置不对应"); return false; }
		if(vecLine[19]!="First_reward_ui"){Ex.Logger.Log("Scene.csv中字段[First_reward_ui]位置不对应"); return false; }
		if(vecLine[20]!="general_reward__ui"){Ex.Logger.Log("Scene.csv中字段[general_reward__ui]位置不对应"); return false; }
		if(vecLine[21]!="is_transfer"){Ex.Logger.Log("Scene.csv中字段[is_transfer]位置不对应"); return false; }
		if(vecLine[22]!="start_music"){Ex.Logger.Log("Scene.csv中字段[start_music]位置不对应"); return false; }
		if(vecLine[23]!="loop_music"){Ex.Logger.Log("Scene.csv中字段[loop_music]位置不对应"); return false; }
		if(vecLine[24]!="endingboss_id"){Ex.Logger.Log("Scene.csv中字段[endingboss_id]位置不对应"); return false; }
		if(vecLine[25]!="duration_time"){Ex.Logger.Log("Scene.csv中字段[duration_time]位置不对应"); return false; }
		if(vecLine[26]!="end_time"){Ex.Logger.Log("Scene.csv中字段[end_time]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)27)
			{
				return false;
			}
			SceneElement member = new SceneElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.name=vecLine[1];
			member.thread_id=Convert.ToInt32(vecLine[2]);
			member.is_dungeon=Convert.ToInt32(vecLine[3]);
			member.valid_pos_x=Convert.ToSingle(vecLine[4]);
			member.valid_pos_z=Convert.ToSingle(vecLine[5]);
			member.dungeon_type=Convert.ToInt32(vecLine[6]);
			member.difficult=Convert.ToInt32(vecLine[7]);
			member.required_level=Convert.ToInt32(vecLine[8]);
			member.required_score=Convert.ToSingle(vecLine[9]);
			member.required_num=Convert.ToInt32(vecLine[10]);
			member.required_last_dungeon_id=Convert.ToInt32(vecLine[11]);
			member.reset_type=Convert.ToInt32(vecLine[12]);
			member.finish_amount=Convert.ToInt32(vecLine[13]);
			member.name_id=Convert.ToInt32(vecLine[14]);
			member.describle_id=Convert.ToInt32(vecLine[15]);
			member.picture_path=vecLine[16];
			member.teleport_id=Convert.ToInt32(vecLine[17]);
			member.reward_boss_ui=vecLine[18];
			member.First_reward_ui=Convert.ToInt32(vecLine[19]);
			member.general_reward__ui=Convert.ToInt32(vecLine[20]);
			member.is_transfer=Convert.ToInt32(vecLine[21]);
			member.start_music=vecLine[22];
			member.loop_music=vecLine[23];
			member.endingboss_id=Convert.ToInt32(vecLine[24]);
			member.duration_time=Convert.ToInt32(vecLine[25]);
			member.end_time=Convert.ToInt32(vecLine[26]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
