using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//月签表配置数据类
public class MonthlySignInElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int required_days;    	//需求签到天数	
	public li signin_reward1_id; 	//签到奖励1	道具ID|数量|是否需要中转
	public li signin_reward2_id; 	//签到奖励2	道具ID|数量|是否需要中转
	public li signin_reward3_id; 	//签到奖励3	道具ID|数量|是否需要中转
	public li signin_reward4_id; 	//签到奖励4	道具ID|数量|是否需要中转

	public bool IsValidate = false;
	public MonthlySignInElement()
	{
		id = -1;
	}
};

//月签表配置封装类
public class MonthlySignInTable
{

	private MonthlySignInTable()
	{
		m_mapElements = new Dictionary<int, MonthlySignInElement>();
		m_emptyItem = new MonthlySignInElement();
		m_vecAllElements = new List<MonthlySignInElement>();
	}
	private Dictionary<int, MonthlySignInElement> m_mapElements = null;
	private List<MonthlySignInElement>	m_vecAllElements = null;
	private MonthlySignInElement m_emptyItem = null;
	private static MonthlySignInTable sInstance = null;

	public static MonthlySignInTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new MonthlySignInTable();
			return sInstance;
		}
	}

	public MonthlySignInElement GetElement(int key)
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

  public List<MonthlySignInElement> GetAllElement(Predicate<MonthlySignInElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("MonthlySignIn.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("MonthlySignIn.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[MonthlySignIn.bin]未找到");
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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("MonthlySignIn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("MonthlySignIn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("MonthlySignIn.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_days"){Ex.Logger.Log("MonthlySignIn.csv中字段[required_days]位置不对应"); return false; }
		if(vecLine[3]!="signin_reward1_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward1_id]位置不对应"); return false; }
		if(vecLine[4]!="signin_reward2_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward2_id]位置不对应"); return false; }
		if(vecLine[5]!="signin_reward3_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward3_id]位置不对应"); return false; }
		if(vecLine[6]!="signin_reward4_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward4_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			MonthlySignInElement member = new MonthlySignInElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_days );
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward4_id);

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
		if(vecLine.Count != 7)
		{
			Ex.Logger.Log("MonthlySignIn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("MonthlySignIn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("MonthlySignIn.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_days"){Ex.Logger.Log("MonthlySignIn.csv中字段[required_days]位置不对应"); return false; }
		if(vecLine[3]!="signin_reward1_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward1_id]位置不对应"); return false; }
		if(vecLine[4]!="signin_reward2_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward2_id]位置不对应"); return false; }
		if(vecLine[5]!="signin_reward3_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward3_id]位置不对应"); return false; }
		if(vecLine[6]!="signin_reward4_id"){Ex.Logger.Log("MonthlySignIn.csv中字段[signin_reward4_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			MonthlySignInElement member = new MonthlySignInElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.required_days=Convert.ToInt32(vecLine[2]);
			member.signin_reward1_id=vecLine[3];
			member.signin_reward2_id=vecLine[4];
			member.signin_reward3_id=vecLine[5];
			member.signin_reward4_id=vecLine[6];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
