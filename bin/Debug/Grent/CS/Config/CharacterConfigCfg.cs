using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//模型配置配置数据类
public class CharacterConfigElement
{
	public int id;               	//配置ID	ID段划分： 0-1000特殊； 1000-9999角色； 10000-29999怪物； 30000-39999静物； 40000-49999npc； 50000-59999宠物
	public string filename;      	//模型文件名	模型文件名
	public string  material;     	//材质	需要更换的材质文件 （时装染色）
	public lf camera_point;      	//	镜头位置特殊xyz
	public lf zoom;              	//缩放比例	X|Y|Z坐标
	public lf bound_center;      	//包围盒中心点	X|Y|Z坐标 别全拉公式！！ 有不是公式导的！
	public lf bound_size;        	//包围盒大小	X|Y|Z坐标 实测结果：影响OBJ交互范围
	public lf near_effect_scale; 	//特效大小	X|Y|Z坐标 实测结果：影响OBJ靠近时播放的特效大小
	public int projection;       	//界面投影类型	0 透视 1 正交
	public lf render_position;   	//界面投影坐标	关联Unity中Myrender下父级Model中的Position X|Y|Z
	public lf render_rotation;   	//界面投影角度	关联Unity中Myrender下子级Model中的Rotation X|Y|Z
	public lf render_scale;      	//界面投影比例	关联Unity中Myrender下子级Model中的Scale X|Y|Z
	public int standup_time;     	//起身时间	模型被击倒后起身的动作时间(单位:ms)
	public int hurt_time;        	//受击时长	模型受击动作时长(单位:ms)
	public float hp_height;      	//模型头顶信息基础高度	该值和模型中的H_World_03点Y轴值匹配 该高度以npc脚的位置为起点计算

	public bool IsValidate = false;
	public CharacterConfigElement()
	{
		id = -1;
	}
};

//模型配置配置封装类
public class CharacterConfigTable
{

	private CharacterConfigTable()
	{
		m_mapElements = new Dictionary<int, CharacterConfigElement>();
		m_emptyItem = new CharacterConfigElement();
		m_vecAllElements = new List<CharacterConfigElement>();
	}
	private Dictionary<int, CharacterConfigElement> m_mapElements = null;
	private List<CharacterConfigElement>	m_vecAllElements = null;
	private CharacterConfigElement m_emptyItem = null;
	private static CharacterConfigTable sInstance = null;

	public static CharacterConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CharacterConfigTable();
			return sInstance;
		}
	}

	public CharacterConfigElement GetElement(int key)
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

  public List<CharacterConfigElement> GetAllElement(Predicate<CharacterConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CharacterConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CharacterConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CharacterConfig.bin]未找到");
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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("CharacterConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CharacterConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="filename"){Ex.Logger.Log("CharacterConfig.csv中字段[filename]位置不对应"); return false; }
		if(vecLine[2]!=" material"){Ex.Logger.Log("CharacterConfig.csv中字段[ material]位置不对应"); return false; }
		if(vecLine[3]!="camera_point"){Ex.Logger.Log("CharacterConfig.csv中字段[camera_point]位置不对应"); return false; }
		if(vecLine[4]!="zoom"){Ex.Logger.Log("CharacterConfig.csv中字段[zoom]位置不对应"); return false; }
		if(vecLine[5]!="bound_center"){Ex.Logger.Log("CharacterConfig.csv中字段[bound_center]位置不对应"); return false; }
		if(vecLine[6]!="bound_size"){Ex.Logger.Log("CharacterConfig.csv中字段[bound_size]位置不对应"); return false; }
		if(vecLine[7]!="near_effect_scale"){Ex.Logger.Log("CharacterConfig.csv中字段[near_effect_scale]位置不对应"); return false; }
		if(vecLine[8]!="projection"){Ex.Logger.Log("CharacterConfig.csv中字段[projection]位置不对应"); return false; }
		if(vecLine[9]!="render_position"){Ex.Logger.Log("CharacterConfig.csv中字段[render_position]位置不对应"); return false; }
		if(vecLine[10]!="render_rotation"){Ex.Logger.Log("CharacterConfig.csv中字段[render_rotation]位置不对应"); return false; }
		if(vecLine[11]!="render_scale"){Ex.Logger.Log("CharacterConfig.csv中字段[render_scale]位置不对应"); return false; }
		if(vecLine[12]!="standup_time"){Ex.Logger.Log("CharacterConfig.csv中字段[standup_time]位置不对应"); return false; }
		if(vecLine[13]!="hurt_time"){Ex.Logger.Log("CharacterConfig.csv中字段[hurt_time]位置不对应"); return false; }
		if(vecLine[14]!="hp_height"){Ex.Logger.Log("CharacterConfig.csv中字段[hp_height]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CharacterConfigElement member = new CharacterConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.filename);
			readPos += GameAssist.ReadString( binContent, readPos, out member. material);
			readPos += GameAssist.ReadString( binContent, readPos, out member.camera_point);
			readPos += GameAssist.ReadString( binContent, readPos, out member.zoom);
			readPos += GameAssist.ReadString( binContent, readPos, out member.bound_center);
			readPos += GameAssist.ReadString( binContent, readPos, out member.bound_size);
			readPos += GameAssist.ReadString( binContent, readPos, out member.near_effect_scale);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.projection );
			readPos += GameAssist.ReadString( binContent, readPos, out member.render_position);
			readPos += GameAssist.ReadString( binContent, readPos, out member.render_rotation);
			readPos += GameAssist.ReadString( binContent, readPos, out member.render_scale);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.standup_time );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.hurt_time );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.hp_height);

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
		if(vecLine.Count != 15)
		{
			Ex.Logger.Log("CharacterConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CharacterConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="filename"){Ex.Logger.Log("CharacterConfig.csv中字段[filename]位置不对应"); return false; }
		if(vecLine[2]!=" material"){Ex.Logger.Log("CharacterConfig.csv中字段[ material]位置不对应"); return false; }
		if(vecLine[3]!="camera_point"){Ex.Logger.Log("CharacterConfig.csv中字段[camera_point]位置不对应"); return false; }
		if(vecLine[4]!="zoom"){Ex.Logger.Log("CharacterConfig.csv中字段[zoom]位置不对应"); return false; }
		if(vecLine[5]!="bound_center"){Ex.Logger.Log("CharacterConfig.csv中字段[bound_center]位置不对应"); return false; }
		if(vecLine[6]!="bound_size"){Ex.Logger.Log("CharacterConfig.csv中字段[bound_size]位置不对应"); return false; }
		if(vecLine[7]!="near_effect_scale"){Ex.Logger.Log("CharacterConfig.csv中字段[near_effect_scale]位置不对应"); return false; }
		if(vecLine[8]!="projection"){Ex.Logger.Log("CharacterConfig.csv中字段[projection]位置不对应"); return false; }
		if(vecLine[9]!="render_position"){Ex.Logger.Log("CharacterConfig.csv中字段[render_position]位置不对应"); return false; }
		if(vecLine[10]!="render_rotation"){Ex.Logger.Log("CharacterConfig.csv中字段[render_rotation]位置不对应"); return false; }
		if(vecLine[11]!="render_scale"){Ex.Logger.Log("CharacterConfig.csv中字段[render_scale]位置不对应"); return false; }
		if(vecLine[12]!="standup_time"){Ex.Logger.Log("CharacterConfig.csv中字段[standup_time]位置不对应"); return false; }
		if(vecLine[13]!="hurt_time"){Ex.Logger.Log("CharacterConfig.csv中字段[hurt_time]位置不对应"); return false; }
		if(vecLine[14]!="hp_height"){Ex.Logger.Log("CharacterConfig.csv中字段[hp_height]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)15)
			{
				return false;
			}
			CharacterConfigElement member = new CharacterConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.filename=vecLine[1];
			member. material=vecLine[2];
			member.camera_point=vecLine[3];
			member.zoom=vecLine[4];
			member.bound_center=vecLine[5];
			member.bound_size=vecLine[6];
			member.near_effect_scale=vecLine[7];
			member.projection=Convert.ToInt32(vecLine[8]);
			member.render_position=vecLine[9];
			member.render_rotation=vecLine[10];
			member.render_scale=vecLine[11];
			member.standup_time=Convert.ToInt32(vecLine[12]);
			member.hurt_time=Convert.ToInt32(vecLine[13]);
			member.hp_height=Convert.ToSingle(vecLine[14]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
