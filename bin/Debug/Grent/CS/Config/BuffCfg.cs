using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//效果配置数据类
public class BuffElement
{
	public int id;               	//数据索引	数据索引
	public int buffID;           	//对应的BuffID	仅程序用
	public string desc_type;     	//Buff效果	仅程序用
	public string desc;          	//Buff名称	仅策划用
	public int oper;             	//Buff关系	0=叠加 1=冲抵 2=免疫
	public int operPars;         	//关系参数	若叠加类=最大叠加次数
	public int overTimed;        	//是否持续Buff	0=非持续 1=持续
	public int continuance;      	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算
	public int interval;         	//间隔时间ms	间隔时间
	public int mutexID;          	//Buff组ID	-1表示跟谁都不是一组的
	public string buffEffect;    	//buff特效	buff特效名称
	public int buffMount;        	//buff特效挂载点	所有部位数字0-19
	public int groupPriority;    	//组中优先级	0为最低
	public li pars;              	//参数	参数1
	public int is_tell_client;   	//是否告知客户端	0：否 1：是

	public bool IsValidate = false;
	public BuffElement()
	{
		id = -1;
	}
};

//效果配置封装类
public class BuffTable
{

	private BuffTable()
	{
		m_mapElements = new Dictionary<int, BuffElement>();
		m_emptyItem = new BuffElement();
		m_vecAllElements = new List<BuffElement>();
	}
	private Dictionary<int, BuffElement> m_mapElements = null;
	private List<BuffElement>	m_vecAllElements = null;
	private BuffElement m_emptyItem = null;
	private static BuffTable sInstance = null;

	public static BuffTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffTable();
			return sInstance;
		}
	}

	public BuffElement GetElement(int key)
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

  public List<BuffElement> GetAllElement(Predicate<BuffElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Buff.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Buff.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Buff.bin]未找到");
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
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="desc_type"){Ex.Logger.Log("Buff.csv中字段[desc_type]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("Buff.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[5]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[6]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[7]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[8]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[9]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[10]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[11]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[12]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[13]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[14]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffElement member = new BuffElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc_type);
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.oper );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.operPars );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.overTimed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mutexID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffMount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.groupPriority );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_tell_client );

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
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="desc_type"){Ex.Logger.Log("Buff.csv中字段[desc_type]位置不对应"); return false; }
		if(vecLine[3]!="desc"){Ex.Logger.Log("Buff.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[4]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[5]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[6]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[7]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[8]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[9]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[10]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[11]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[12]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[13]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[14]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)15)
			{
				return false;
			}
			BuffElement member = new BuffElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.buffID=Convert.ToInt32(vecLine[1]);
			member.desc_type=vecLine[2];
			member.desc=vecLine[3];
			member.oper=Convert.ToInt32(vecLine[4]);
			member.operPars=Convert.ToInt32(vecLine[5]);
			member.overTimed=Convert.ToInt32(vecLine[6]);
			member.continuance=Convert.ToInt32(vecLine[7]);
			member.interval=Convert.ToInt32(vecLine[8]);
			member.mutexID=Convert.ToInt32(vecLine[9]);
			member.buffEffect=vecLine[10];
			member.buffMount=Convert.ToInt32(vecLine[11]);
			member.groupPriority=Convert.ToInt32(vecLine[12]);
			member.pars=vecLine[13];
			member.is_tell_client=Convert.ToInt32(vecLine[14]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
