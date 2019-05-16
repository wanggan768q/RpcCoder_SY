using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//累计登陆奖励表配置数据类
public class AccumulateSignInElement
{
	public int id;               	//序号	序号
	public string comment;       	//备注	备注
	public int required_signin;  	//需求累计登陆天数	
	public int required_lv;      	//需求角色等级	
	public string icon1;         	//奖励图	资源路径
	public string icon2;         	//美术字	
	public li signin_reward1_id; 	//等级奖励1	道具ID|数量|是否需要中转
	public li signin_reward2_id; 	//等级奖励2	道具ID|数量|是否需要中转
	public li signin_reward3_id; 	//等级奖励3	道具ID|数量|是否需要中转
	public li signin_reward4_id; 	//等级奖励4	道具ID|数量|是否需要中转
	public li resource_id;       	//3D模型展示	此处填模型配置表里的ID，时装只填不同职业的男性ID，女性ID=男性ID+100 从左往右的顺序为下方职业从上往下的顺序，刺客暂时没有就填0 1：战士 2：刺客 3：游侠 4：魔法师 5：圣骑士6：神秘使
	public lf scale;             	//3D模型缩放	X|Y|Z
	public lf position;          	//3D模型位置	X|Y|Z
	public lf rotation;          	//3D模型默认旋转	X|Y|Z

	public bool IsValidate = false;
	public AccumulateSignInElement()
	{
		id = -1;
	}
};

//累计登陆奖励表配置封装类
public class AccumulateSignInTable
{

	private AccumulateSignInTable()
	{
		m_mapElements = new Dictionary<int, AccumulateSignInElement>();
		m_emptyItem = new AccumulateSignInElement();
		m_vecAllElements = new List<AccumulateSignInElement>();
	}
	private Dictionary<int, AccumulateSignInElement> m_mapElements = null;
	private List<AccumulateSignInElement>	m_vecAllElements = null;
	private AccumulateSignInElement m_emptyItem = null;
	private static AccumulateSignInTable sInstance = null;

	public static AccumulateSignInTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new AccumulateSignInTable();
			return sInstance;
		}
	}

	public AccumulateSignInElement GetElement(int key)
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

  public List<AccumulateSignInElement> GetAllElement(Predicate<AccumulateSignInElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("AccumulateSignIn.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("AccumulateSignIn.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[AccumulateSignIn.bin]未找到");
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
			Ex.Logger.Log("AccumulateSignIn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AccumulateSignIn.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_signin"){Ex.Logger.Log("AccumulateSignIn.csv中字段[required_signin]位置不对应"); return false; }
		if(vecLine[3]!="required_lv"){Ex.Logger.Log("AccumulateSignIn.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[4]!="icon1"){Ex.Logger.Log("AccumulateSignIn.csv中字段[icon1]位置不对应"); return false; }
		if(vecLine[5]!="icon2"){Ex.Logger.Log("AccumulateSignIn.csv中字段[icon2]位置不对应"); return false; }
		if(vecLine[6]!="signin_reward1_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward1_id]位置不对应"); return false; }
		if(vecLine[7]!="signin_reward2_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward2_id]位置不对应"); return false; }
		if(vecLine[8]!="signin_reward3_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward3_id]位置不对应"); return false; }
		if(vecLine[9]!="signin_reward4_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward4_id]位置不对应"); return false; }
		if(vecLine[10]!="resource_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[resource_id]位置不对应"); return false; }
		if(vecLine[11]!="scale"){Ex.Logger.Log("AccumulateSignIn.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[12]!="position"){Ex.Logger.Log("AccumulateSignIn.csv中字段[position]位置不对应"); return false; }
		if(vecLine[13]!="rotation"){Ex.Logger.Log("AccumulateSignIn.csv中字段[rotation]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			AccumulateSignInElement member = new AccumulateSignInElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_signin );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.required_lv );
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward1_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward2_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward3_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.signin_reward4_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.scale);
			readPos += GameAssist.ReadString( binContent, readPos, out member.position);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rotation);

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
			Ex.Logger.Log("AccumulateSignIn.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("AccumulateSignIn.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="required_signin"){Ex.Logger.Log("AccumulateSignIn.csv中字段[required_signin]位置不对应"); return false; }
		if(vecLine[3]!="required_lv"){Ex.Logger.Log("AccumulateSignIn.csv中字段[required_lv]位置不对应"); return false; }
		if(vecLine[4]!="icon1"){Ex.Logger.Log("AccumulateSignIn.csv中字段[icon1]位置不对应"); return false; }
		if(vecLine[5]!="icon2"){Ex.Logger.Log("AccumulateSignIn.csv中字段[icon2]位置不对应"); return false; }
		if(vecLine[6]!="signin_reward1_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward1_id]位置不对应"); return false; }
		if(vecLine[7]!="signin_reward2_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward2_id]位置不对应"); return false; }
		if(vecLine[8]!="signin_reward3_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward3_id]位置不对应"); return false; }
		if(vecLine[9]!="signin_reward4_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[signin_reward4_id]位置不对应"); return false; }
		if(vecLine[10]!="resource_id"){Ex.Logger.Log("AccumulateSignIn.csv中字段[resource_id]位置不对应"); return false; }
		if(vecLine[11]!="scale"){Ex.Logger.Log("AccumulateSignIn.csv中字段[scale]位置不对应"); return false; }
		if(vecLine[12]!="position"){Ex.Logger.Log("AccumulateSignIn.csv中字段[position]位置不对应"); return false; }
		if(vecLine[13]!="rotation"){Ex.Logger.Log("AccumulateSignIn.csv中字段[rotation]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)14)
			{
				return false;
			}
			AccumulateSignInElement member = new AccumulateSignInElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.required_signin=Convert.ToInt32(vecLine[2]);
			member.required_lv=Convert.ToInt32(vecLine[3]);
			member.icon1=vecLine[4];
			member.icon2=vecLine[5];
			member.signin_reward1_id=vecLine[6];
			member.signin_reward2_id=vecLine[7];
			member.signin_reward3_id=vecLine[8];
			member.signin_reward4_id=vecLine[9];
			member.resource_id=vecLine[10];
			member.scale=vecLine[11];
			member.position=vecLine[12];
			member.rotation=vecLine[13];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
