using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宠物索引表配置数据类
public class PetIndexElement
{
	public int id;               	//宠物索引id	填写ID即可
	public string comment;       	//注释	策划用
	public int proto_id;         	//原型ID	宠物原型  对应宠物原型表的id
	public int rank;             	//宠物星级id	宠物当前的星级  对应宠物品质表的id
	public int next_rank_item;   	//宠物下级道具	宠物升星后需要对应的道具
	public int talent_id;        	//系数id	PetTalent_宠物资质id
	public int npc_id;           	//掉落显示的id	掉落显示的id

	public bool IsValidate = false;
	public PetIndexElement()
	{
		id = -1;
	}
};

//宠物索引表配置封装类
public class PetIndexTable
{

	private PetIndexTable()
	{
		m_mapElements = new Dictionary<int, PetIndexElement>();
		m_emptyItem = new PetIndexElement();
		m_vecAllElements = new List<PetIndexElement>();
	}
	private Dictionary<int, PetIndexElement> m_mapElements = null;
	private List<PetIndexElement>	m_vecAllElements = null;
	private PetIndexElement m_emptyItem = null;
	private static PetIndexTable sInstance = null;

	public static PetIndexTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new PetIndexTable();
			return sInstance;
		}
	}

	public PetIndexElement GetElement(int key)
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

  public List<PetIndexElement> GetAllElement(Predicate<PetIndexElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("PetIndex.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("PetIndex.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[PetIndex.bin]未找到");
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
			Ex.Logger.Log("PetIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetIndex.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="proto_id"){Ex.Logger.Log("PetIndex.csv中字段[proto_id]位置不对应"); return false; }
		if(vecLine[3]!="rank"){Ex.Logger.Log("PetIndex.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[4]!="next_rank_item"){Ex.Logger.Log("PetIndex.csv中字段[next_rank_item]位置不对应"); return false; }
		if(vecLine[5]!="talent_id"){Ex.Logger.Log("PetIndex.csv中字段[talent_id]位置不对应"); return false; }
		if(vecLine[6]!="npc_id"){Ex.Logger.Log("PetIndex.csv中字段[npc_id]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			PetIndexElement member = new PetIndexElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.proto_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.rank );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.next_rank_item );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.talent_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.npc_id );

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
			Ex.Logger.Log("PetIndex.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("PetIndex.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("PetIndex.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="proto_id"){Ex.Logger.Log("PetIndex.csv中字段[proto_id]位置不对应"); return false; }
		if(vecLine[3]!="rank"){Ex.Logger.Log("PetIndex.csv中字段[rank]位置不对应"); return false; }
		if(vecLine[4]!="next_rank_item"){Ex.Logger.Log("PetIndex.csv中字段[next_rank_item]位置不对应"); return false; }
		if(vecLine[5]!="talent_id"){Ex.Logger.Log("PetIndex.csv中字段[talent_id]位置不对应"); return false; }
		if(vecLine[6]!="npc_id"){Ex.Logger.Log("PetIndex.csv中字段[npc_id]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)7)
			{
				return false;
			}
			PetIndexElement member = new PetIndexElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.proto_id=Convert.ToInt32(vecLine[2]);
			member.rank=Convert.ToInt32(vecLine[3]);
			member.next_rank_item=Convert.ToInt32(vecLine[4]);
			member.talent_id=Convert.ToInt32(vecLine[5]);
			member.npc_id=Convert.ToInt32(vecLine[6]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
