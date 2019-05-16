using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//NPC或OBJ显示隐藏表配置数据类
public class CreatureHideElement
{
	public int id;               	//序号	唯一值
	public string comment;       	//任务备注	仅策划用
	public int quest_id;         	//任务id	任务状态为0时，该列为0任务表中对应ID
	public int quest_status;     	//任务状态	0=接取前 1=进行中 2=任务结束
	public int quest_step_1;     	//任务步骤1	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标1是否完成 0=未完成 1=完成
	public int quest_step_2;     	//任务步骤2	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标2是否完成 0=未完成 1=完成
	public int quest_step_3;     	//任务步骤3	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标3是否完成 0=未完成 1=完成
	public int quest_step_4;     	//任务步骤4	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标4是否完成 0=未完成 1=完成
	public int quest_step_5;     	//任务步骤5	当任务处于1状态时填写 任务处于其他状态时填写-1 任务目标5是否完成 0=未完成 1=完成
	public int creature_status;  	//NPC状态	0=显示 1=隐藏

	public bool IsValidate = false;
	public CreatureHideElement()
	{
		id = -1;
	}
};

//NPC或OBJ显示隐藏表配置封装类
public class CreatureHideTable
{

	private CreatureHideTable()
	{
		m_mapElements = new Dictionary<int, CreatureHideElement>();
		m_emptyItem = new CreatureHideElement();
		m_vecAllElements = new List<CreatureHideElement>();
	}
	private Dictionary<int, CreatureHideElement> m_mapElements = null;
	private List<CreatureHideElement>	m_vecAllElements = null;
	private CreatureHideElement m_emptyItem = null;
	private static CreatureHideTable sInstance = null;

	public static CreatureHideTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new CreatureHideTable();
			return sInstance;
		}
	}

	public CreatureHideElement GetElement(int key)
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

  public List<CreatureHideElement> GetAllElement(Predicate<CreatureHideElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("CreatureHide.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("CreatureHide.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[CreatureHide.bin]未找到");
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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("CreatureHide.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureHide.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CreatureHide.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("CreatureHide.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_status"){Ex.Logger.Log("CreatureHide.csv中字段[quest_status]位置不对应"); return false; }
		if(vecLine[4]!="quest_step_1"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_1]位置不对应"); return false; }
		if(vecLine[5]!="quest_step_2"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_2]位置不对应"); return false; }
		if(vecLine[6]!="quest_step_3"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_3]位置不对应"); return false; }
		if(vecLine[7]!="quest_step_4"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_4]位置不对应"); return false; }
		if(vecLine[8]!="quest_step_5"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_5]位置不对应"); return false; }
		if(vecLine[9]!="creature_status"){Ex.Logger.Log("CreatureHide.csv中字段[creature_status]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			CreatureHideElement member = new CreatureHideElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_status );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step_1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step_2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step_3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step_4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quest_step_5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.creature_status );

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
		if(vecLine.Count != 10)
		{
			Ex.Logger.Log("CreatureHide.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("CreatureHide.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("CreatureHide.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="quest_id"){Ex.Logger.Log("CreatureHide.csv中字段[quest_id]位置不对应"); return false; }
		if(vecLine[3]!="quest_status"){Ex.Logger.Log("CreatureHide.csv中字段[quest_status]位置不对应"); return false; }
		if(vecLine[4]!="quest_step_1"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_1]位置不对应"); return false; }
		if(vecLine[5]!="quest_step_2"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_2]位置不对应"); return false; }
		if(vecLine[6]!="quest_step_3"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_3]位置不对应"); return false; }
		if(vecLine[7]!="quest_step_4"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_4]位置不对应"); return false; }
		if(vecLine[8]!="quest_step_5"){Ex.Logger.Log("CreatureHide.csv中字段[quest_step_5]位置不对应"); return false; }
		if(vecLine[9]!="creature_status"){Ex.Logger.Log("CreatureHide.csv中字段[creature_status]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)10)
			{
				return false;
			}
			CreatureHideElement member = new CreatureHideElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.quest_id=Convert.ToInt32(vecLine[2]);
			member.quest_status=Convert.ToInt32(vecLine[3]);
			member.quest_step_1=Convert.ToInt32(vecLine[4]);
			member.quest_step_2=Convert.ToInt32(vecLine[5]);
			member.quest_step_3=Convert.ToInt32(vecLine[6]);
			member.quest_step_4=Convert.ToInt32(vecLine[7]);
			member.quest_step_5=Convert.ToInt32(vecLine[8]);
			member.creature_status=Convert.ToInt32(vecLine[9]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
