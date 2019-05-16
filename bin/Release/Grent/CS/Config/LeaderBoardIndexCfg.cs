using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//排行榜索引表配置数据类
public class LeaderBoardIndexElement
{
	public int id;               	//分类id	对应到指定的分类ID
	public string comment;       	//注释	策划用
	public int list_id;          	//所属榜单	该分类所属的榜单ID 排行榜id
	public int index;            	//服务器索引	对应的索引值
	public int sort_name;        	//分类名称	对应string_ui表的ID
	public int reward_judgment;  	//是否有奖励	0：没有奖励 1：有奖励
	public int point_information;	//提示信息	0：没有提示信息 或文本表id
	public li reward_information1;	//奖励信息1	奖励道具|数量
	public li reward_information2;	//奖励信息2	奖励道具|数量
	public li reward_information3;	//奖励信息3	奖励道具|数量
	public li reward_information4;	//奖励信息4	奖励道具|数量

	public bool IsValidate = false;
	public LeaderBoardIndexElement()
	{
		id = -1;
	}
};

//排行榜索引表配置封装类
public class LeaderBoardIndexTable
{

	private LeaderBoardIndexTable()
	{
		m_mapElements = new Dictionary<int, LeaderBoardIndexElement>();
		m_emptyItem = new LeaderBoardIndexElement();
		m_vecAllElements = new List<LeaderBoardIndexElement>();
	}
	private Dictionary<int, LeaderBoardIndexElement> m_mapElements = null;
	private List<LeaderBoardIndexElement>	m_vecAllElements = null;
	private LeaderBoardIndexElement m_emptyItem = null;
	private static LeaderBoardIndexTable sInstance = null;

	public static LeaderBoardIndexTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new LeaderBoardIndexTable();
			return sInstance;
		}
	}

	public LeaderBoardIndexElement GetElement(int key)
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

  public List<LeaderBoardIndexElement> GetAllElement(Predicate<LeaderBoardIndexElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("LeaderBoardIndex.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("LeaderBoardIndex.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[LeaderBoardIndex.bin]未找到");
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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("LeaderBoardIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="list_id"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[list_id]位置不对应"); return false; }
		if(vecLine[3]!="index"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[index]位置不对应"); return false; }
		if(vecLine[4]!="sort_name"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[sort_name]位置不对应"); return false; }
		if(vecLine[5]!="reward_judgment"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_judgment]位置不对应"); return false; }
		if(vecLine[6]!="point_information"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[point_information]位置不对应"); return false; }
		if(vecLine[7]!="reward_information1"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information1]位置不对应"); return false; }
		if(vecLine[8]!="reward_information2"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information2]位置不对应"); return false; }
		if(vecLine[9]!="reward_information3"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information3]位置不对应"); return false; }
		if(vecLine[10]!="reward_information4"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information4]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			LeaderBoardIndexElement member = new LeaderBoardIndexElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.list_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.index );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.sort_name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.reward_judgment );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.point_information );
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_information1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_information2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_information3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_information4);

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
		if(vecLine.Count != 11)
		{
			Ex.Logger.Log("LeaderBoardIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="list_id"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[list_id]位置不对应"); return false; }
		if(vecLine[3]!="index"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[index]位置不对应"); return false; }
		if(vecLine[4]!="sort_name"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[sort_name]位置不对应"); return false; }
		if(vecLine[5]!="reward_judgment"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_judgment]位置不对应"); return false; }
		if(vecLine[6]!="point_information"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[point_information]位置不对应"); return false; }
		if(vecLine[7]!="reward_information1"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information1]位置不对应"); return false; }
		if(vecLine[8]!="reward_information2"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information2]位置不对应"); return false; }
		if(vecLine[9]!="reward_information3"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information3]位置不对应"); return false; }
		if(vecLine[10]!="reward_information4"){Ex.Logger.Log("LeaderBoardIndex.csv中字段[reward_information4]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)11)
			{
				return false;
			}
			LeaderBoardIndexElement member = new LeaderBoardIndexElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.list_id=Convert.ToInt32(vecLine[2]);
			member.index=Convert.ToInt32(vecLine[3]);
			member.sort_name=Convert.ToInt32(vecLine[4]);
			member.reward_judgment=Convert.ToInt32(vecLine[5]);
			member.point_information=Convert.ToInt32(vecLine[6]);
			member.reward_information1=vecLine[7];
			member.reward_information2=vecLine[8];
			member.reward_information3=vecLine[9];
			member.reward_information4=vecLine[10];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
