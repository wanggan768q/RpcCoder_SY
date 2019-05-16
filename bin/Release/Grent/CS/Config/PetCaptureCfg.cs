using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物捕获表配置数据类
public class PetCaptureElement
{
	public int id;               	//宠物npcid	填写ID即可
	public string comment;       	//注释	策划用
	public int name;             	//宠物名称	显示的宠物原型ID StringItem_道具文本表
	public int npcid;            	//宠物NPCID	显示的宠物NPCID 已经无用，从场景内随机
	public li rate_up;           	//精灵球增益值	用普通球|大师球捕获时的增益值
	public li rate;              	//掉落包阈值	增益值达到这个值使用下个掉落包
	public li reward_id;         	//宠物掉落包	低级球每一个区间使用的掉落包
	public li highreword_id;     	//宠物掉落包高级球	高级球每一个区间使用的掉落包
	public int equip_id;         	//宠物原型ID	获得此类宠物道具后，该宠物npc刷新
	public li scene_id;          	//刷新场景ID	宠物npc在刷新的场景顺序
	public string refresh;       	//刷新时间	宠物npc在第一个场景刷新的时间
	public int time;             	//掉落生命周期	显示的宠物掉落存在时间 

	public bool IsValidate = false;
	public PetCaptureElement()
	{
		id = -1;
	}
};

//宠物捕获表配置封装类
public class PetCaptureTable
{

	private PetCaptureTable()
	{
		m_mapElements = new Dictionary<int, PetCaptureElement>();
		m_emptyItem = new PetCaptureElement();
		m_vecAllElements = new List<PetCaptureElement>();
	}
	private Dictionary<int, PetCaptureElement> m_mapElements = null;
	private List<PetCaptureElement>	m_vecAllElements = null;
	private PetCaptureElement m_emptyItem = null;
	private static PetCaptureTable sInstance = null;

	public static PetCaptureTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetCaptureTable();
			return sInstance;
		}
	}

	public PetCaptureElement GetElement(int key)
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

  public List<PetCaptureElement> GetAllElement(Predicate<PetCaptureElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetCapture.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetCapture.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetCapture.bin]未找到");
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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("PetCapture.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetCapture.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetCapture.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetCapture.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="npcid"){Ex.Logger.Log("PetCapture.csv中字段[npcid]位置不对应"); return false; }
		if(vecLine[4]!="rate_up"){Ex.Logger.Log("PetCapture.csv中字段[rate_up]位置不对应"); return false; }
		if(vecLine[5]!="rate"){Ex.Logger.Log("PetCapture.csv中字段[rate]位置不对应"); return false; }
		if(vecLine[6]!="reward_id"){Ex.Logger.Log("PetCapture.csv中字段[reward_id]位置不对应"); return false; }
		if(vecLine[7]!="highreword_id"){Ex.Logger.Log("PetCapture.csv中字段[highreword_id]位置不对应"); return false; }
		if(vecLine[8]!="equip_id"){Ex.Logger.Log("PetCapture.csv中字段[equip_id]位置不对应"); return false; }
		if(vecLine[9]!="scene_id"){Ex.Logger.Log("PetCapture.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[10]!="refresh"){Ex.Logger.Log("PetCapture.csv中字段[refresh]位置不对应"); return false; }
		if(vecLine[11]!="time"){Ex.Logger.Log("PetCapture.csv中字段[time]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetCaptureElement member = new PetCaptureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npcid );
			readPos += GameAssist.ReadString( binContent, readPos, out member.rate_up);
			readPos += GameAssist.ReadString( binContent, readPos, out member.rate);
			readPos += GameAssist.ReadString( binContent, readPos, out member.reward_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.highreword_id);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.equip_id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.scene_id);
			readPos += GameAssist.ReadString( binContent, readPos, out member.refresh);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.time );

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
		if(vecLine.Count != 12)
		{
			Ex.Logger.Log("PetCapture.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetCapture.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetCapture.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="name"){Ex.Logger.Log("PetCapture.csv中字段[name]位置不对应"); return false; }
		if(vecLine[3]!="npcid"){Ex.Logger.Log("PetCapture.csv中字段[npcid]位置不对应"); return false; }
		if(vecLine[4]!="rate_up"){Ex.Logger.Log("PetCapture.csv中字段[rate_up]位置不对应"); return false; }
		if(vecLine[5]!="rate"){Ex.Logger.Log("PetCapture.csv中字段[rate]位置不对应"); return false; }
		if(vecLine[6]!="reward_id"){Ex.Logger.Log("PetCapture.csv中字段[reward_id]位置不对应"); return false; }
		if(vecLine[7]!="highreword_id"){Ex.Logger.Log("PetCapture.csv中字段[highreword_id]位置不对应"); return false; }
		if(vecLine[8]!="equip_id"){Ex.Logger.Log("PetCapture.csv中字段[equip_id]位置不对应"); return false; }
		if(vecLine[9]!="scene_id"){Ex.Logger.Log("PetCapture.csv中字段[scene_id]位置不对应"); return false; }
		if(vecLine[10]!="refresh"){Ex.Logger.Log("PetCapture.csv中字段[refresh]位置不对应"); return false; }
		if(vecLine[11]!="time"){Ex.Logger.Log("PetCapture.csv中字段[time]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)12)
			{
				return false;
			}
			PetCaptureElement member = new PetCaptureElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.name=Convert.ToInt32(vecLine[2]);
			member.npcid=Convert.ToInt32(vecLine[3]);
			member.rate_up=vecLine[4];
			member.rate=vecLine[5];
			member.reward_id=vecLine[6];
			member.highreword_id=vecLine[7];
			member.equip_id=Convert.ToInt32(vecLine[8]);
			member.scene_id=vecLine[9];
			member.refresh=vecLine[10];
			member.time=Convert.ToInt32(vecLine[11]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
