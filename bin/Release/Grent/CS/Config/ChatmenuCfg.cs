using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//字幕框配置数据类
public class ChatmenuElement
{
	public int id;               	//对话id	地图*10000 + 区域 * 1000 + 对话序号
	public string comment;       	//注释	对话备注
	public int chat_content_id;  	//字幕内容	关联string_chatmenu表
	public int chat_next_id;     	//下一字幕框id	下一块chatmenu的id
	public int chat_title_id;    	//分支选项标题id	分支选项标题id，对应任务文本表
	public li branch_option;     	//对应字幕框的分支选项文本	无分支为，为数组型，格式为chat_id|chat_id
	public li unlock_branch_option;	//解锁需求分支	默认为，格式为chat_id|chat_id
	public int avatar_npc_id;    	//NPC影像id	0为玩家影像 否则为npcID影像
	public int required_quest_id;	//所需任务id	
	public li event_list;        	//字幕结束后所触发的事件	格式为event_type|id event_type为1，代表传送 id为所需传送的路点id
	public int vo_path;          	//VO路径	
	public int is_can_skip;      	//是否可以跳过剧情	1代表可以跳过 0代表不可跳过
	public int animation_path;   	//播放的NPC或玩家动画	为-1表示循环播放idel动画
	public int animation_type;   	//播放的动画是否循环	1代表循环 0代表只播放一次

	public bool IsValidate = false;
	public ChatmenuElement()
	{
		id = -1;
	}
};

//字幕框配置封装类
public class ChatmenuTable
{

	private ChatmenuTable()
	{
		m_mapElements = new Dictionary<int, ChatmenuElement>();
		m_emptyItem = new ChatmenuElement();
		m_vecAllElements = new List<ChatmenuElement>();
	}
	private Dictionary<int, ChatmenuElement> m_mapElements = null;
	private List<ChatmenuElement>	m_vecAllElements = null;
	private ChatmenuElement m_emptyItem = null;
	private static ChatmenuTable sInstance = null;

	public static ChatmenuTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new ChatmenuTable();
			return sInstance;
		}
	}

	public ChatmenuElement GetElement(int key)
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

  public List<ChatmenuElement> GetAllElement(Predicate<ChatmenuElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Chatmenu.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Chatmenu.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Chatmenu.bin]未找到");
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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("Chatmenu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Chatmenu.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Chatmenu.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="chat_content_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_content_id]位置不对应"); return false; }
		if(vecLine[3]!="chat_next_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_next_id]位置不对应"); return false; }
		if(vecLine[4]!="chat_title_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_title_id]位置不对应"); return false; }
		if(vecLine[5]!="branch_option"){Ex.Logger.Log("Chatmenu.csv中字段[branch_option]位置不对应"); return false; }
		if(vecLine[6]!="unlock_branch_option"){Ex.Logger.Log("Chatmenu.csv中字段[unlock_branch_option]位置不对应"); return false; }
		if(vecLine[7]!="avatar_npc_id"){Ex.Logger.Log("Chatmenu.csv中字段[avatar_npc_id]位置不对应"); return false; }
		if(vecLine[8]!="required_quest_id"){Ex.Logger.Log("Chatmenu.csv中字段[required_quest_id]位置不对应"); return false; }
		if(vecLine[9]!="event_list"){Ex.Logger.Log("Chatmenu.csv中字段[event_list]位置不对应"); return false; }
		if(vecLine[10]!="vo_path"){Ex.Logger.Log("Chatmenu.csv中字段[vo_path]位置不对应"); return false; }
		if(vecLine[11]!="is_can_skip"){Ex.Logger.Log("Chatmenu.csv中字段[is_can_skip]位置不对应"); return false; }
		if(vecLine[12]!="animation_path"){Ex.Logger.Log("Chatmenu.csv中字段[animation_path]位置不对应"); return false; }
		if(vecLine[13]!="animation_type"){Ex.Logger.Log("Chatmenu.csv中字段[animation_type]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			ChatmenuElement member = new ChatmenuElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chat_content_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chat_next_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.chat_title_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.branch_option);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_branch_option);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.avatar_npc_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_quest_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.event_list);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.vo_path );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_can_skip );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.animation_path );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.animation_type );

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
		if(vecLine.Count != 14)
		{
			Ex.Logger.Log("Chatmenu.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Chatmenu.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Chatmenu.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="chat_content_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_content_id]位置不对应"); return false; }
		if(vecLine[3]!="chat_next_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_next_id]位置不对应"); return false; }
		if(vecLine[4]!="chat_title_id"){Ex.Logger.Log("Chatmenu.csv中字段[chat_title_id]位置不对应"); return false; }
		if(vecLine[5]!="branch_option"){Ex.Logger.Log("Chatmenu.csv中字段[branch_option]位置不对应"); return false; }
		if(vecLine[6]!="unlock_branch_option"){Ex.Logger.Log("Chatmenu.csv中字段[unlock_branch_option]位置不对应"); return false; }
		if(vecLine[7]!="avatar_npc_id"){Ex.Logger.Log("Chatmenu.csv中字段[avatar_npc_id]位置不对应"); return false; }
		if(vecLine[8]!="required_quest_id"){Ex.Logger.Log("Chatmenu.csv中字段[required_quest_id]位置不对应"); return false; }
		if(vecLine[9]!="event_list"){Ex.Logger.Log("Chatmenu.csv中字段[event_list]位置不对应"); return false; }
		if(vecLine[10]!="vo_path"){Ex.Logger.Log("Chatmenu.csv中字段[vo_path]位置不对应"); return false; }
		if(vecLine[11]!="is_can_skip"){Ex.Logger.Log("Chatmenu.csv中字段[is_can_skip]位置不对应"); return false; }
		if(vecLine[12]!="animation_path"){Ex.Logger.Log("Chatmenu.csv中字段[animation_path]位置不对应"); return false; }
		if(vecLine[13]!="animation_type"){Ex.Logger.Log("Chatmenu.csv中字段[animation_type]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			ChatmenuElement member = new ChatmenuElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.chat_content_id=Convert.ToInt32(vecLine[2]);
			member.chat_next_id=Convert.ToInt32(vecLine[3]);
			member.chat_title_id=Convert.ToInt32(vecLine[4]);
			member.branch_option=vecLine[5];
			member.unlock_branch_option=vecLine[6];
			member.avatar_npc_id=Convert.ToInt32(vecLine[7]);
			member.required_quest_id=Convert.ToInt32(vecLine[8]);
			member.event_list=vecLine[9];
			member.vo_path=Convert.ToInt32(vecLine[10]);
			member.is_can_skip=Convert.ToInt32(vecLine[11]);
			member.animation_path=Convert.ToInt32(vecLine[12]);
			member.animation_type=Convert.ToInt32(vecLine[13]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
