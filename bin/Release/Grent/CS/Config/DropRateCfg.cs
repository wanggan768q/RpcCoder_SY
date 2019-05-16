using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//概率掉落表配置数据类
public class DropRateElement
{
	public int id;               	//掉落id	掉落id
	public string comment;       	//掉落注释	策划用
	public int experience;       	//经验值	掉落的经验值
	public int transit_tag;      	//中转标签	0表示不需要中转 1表示需要中转
	public float gold_rate;      	//银币掉率	掉落银币的概率
	public li gold_range;        	//银币区间	区间下限|区间上限
	public li heap_range;        	//银币堆数区间	堆数区间1|堆数区间2
	public int Binding;          	//是否绑定	该掉落包中的绑定状态 0：不绑定 1：拾取绑定 2：装备绑定 
	public li drop_info1;        	//掉落信息1	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和2时，掉落数量无效
	public li drop_info2;        	//掉落信息2	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和3时，掉落数量无效
	public li drop_info3;        	//掉落信息3	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和4时，掉落数量无效
	public li drop_info4;        	//掉落信息4	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和5时，掉落数量无效
	public li drop_info5;        	//掉落信息5	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和6时，掉落数量无效
	public li drop_info6;        	//掉落信息6	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和7时，掉落数量无效
	public li drop_info7;        	//掉落信息7	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和8时，掉落数量无效
	public li drop_info8;        	//掉落信息8	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和9时，掉落数量无效
	public li drop_info9;        	//掉落信息9	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和10时，掉落数量无效
	public li drop_info10;       	//掉落信息10	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和11时，掉落数量无效
	public li drop_info11;       	//掉落信息11	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和12时，掉落数量无效
	public li drop_info12;       	//掉落信息12	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和13时，掉落数量无效
	public li drop_info13;       	//掉落信息13	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和14时，掉落数量无效
	public li drop_info14;       	//掉落信息14	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和15时，掉落数量无效
	public li drop_info15;       	//掉落信息15	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和16时，掉落数量无效
	public li drop_info16;       	//掉落信息16	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和17时，掉落数量无效
	public li drop_info17;       	//掉落信息17	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和18时，掉落数量无效
	public li drop_info18;       	//掉落信息18	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和19时，掉落数量无效
	public li drop_info19;       	//掉落信息19	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和20时，掉落数量无效
	public li drop_info20;       	//掉落信息20	掉落类型|掉落ID|掉落数量|掉落概率 掉落类型：     0：物品ID     1：单独掉落包ID     2：权值掉落包ID     如果掉落类型为1和21时，掉落数量无效

	public bool IsValidate = false;
	public DropRateElement()
	{
		id = -1;
	}
};

//概率掉落表配置封装类
public class DropRateTable
{

	private DropRateTable()
	{
		m_mapElements = new Dictionary<int, DropRateElement>();
		m_emptyItem = new DropRateElement();
		m_vecAllElements = new List<DropRateElement>();
	}
	private Dictionary<int, DropRateElement> m_mapElements = null;
	private List<DropRateElement>	m_vecAllElements = null;
	private DropRateElement m_emptyItem = null;
	private static DropRateTable sInstance = null;

	public static DropRateTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new DropRateTable();
			return sInstance;
		}
	}

	public DropRateElement GetElement(int key)
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

  public List<DropRateElement> GetAllElement(Predicate<DropRateElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("DropRate.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("DropRate.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[DropRate.bin]未找到");
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
		if(vecLine.Count != 28)
		{
			Ex.Logger.Log("DropRate.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DropRate.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("DropRate.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="experience"){Ex.Logger.Log("DropRate.csv中字段[experience]位置不对应"); return false; }
		if(vecLine[3]!="transit_tag"){Ex.Logger.Log("DropRate.csv中字段[transit_tag]位置不对应"); return false; }
		if(vecLine[4]!="gold_rate"){Ex.Logger.Log("DropRate.csv中字段[gold_rate]位置不对应"); return false; }
		if(vecLine[5]!="gold_range"){Ex.Logger.Log("DropRate.csv中字段[gold_range]位置不对应"); return false; }
		if(vecLine[6]!="heap_range"){Ex.Logger.Log("DropRate.csv中字段[heap_range]位置不对应"); return false; }
		if(vecLine[7]!="Binding"){Ex.Logger.Log("DropRate.csv中字段[Binding]位置不对应"); return false; }
		if(vecLine[8]!="drop_info1"){Ex.Logger.Log("DropRate.csv中字段[drop_info1]位置不对应"); return false; }
		if(vecLine[9]!="drop_info2"){Ex.Logger.Log("DropRate.csv中字段[drop_info2]位置不对应"); return false; }
		if(vecLine[10]!="drop_info3"){Ex.Logger.Log("DropRate.csv中字段[drop_info3]位置不对应"); return false; }
		if(vecLine[11]!="drop_info4"){Ex.Logger.Log("DropRate.csv中字段[drop_info4]位置不对应"); return false; }
		if(vecLine[12]!="drop_info5"){Ex.Logger.Log("DropRate.csv中字段[drop_info5]位置不对应"); return false; }
		if(vecLine[13]!="drop_info6"){Ex.Logger.Log("DropRate.csv中字段[drop_info6]位置不对应"); return false; }
		if(vecLine[14]!="drop_info7"){Ex.Logger.Log("DropRate.csv中字段[drop_info7]位置不对应"); return false; }
		if(vecLine[15]!="drop_info8"){Ex.Logger.Log("DropRate.csv中字段[drop_info8]位置不对应"); return false; }
		if(vecLine[16]!="drop_info9"){Ex.Logger.Log("DropRate.csv中字段[drop_info9]位置不对应"); return false; }
		if(vecLine[17]!="drop_info10"){Ex.Logger.Log("DropRate.csv中字段[drop_info10]位置不对应"); return false; }
		if(vecLine[18]!="drop_info11"){Ex.Logger.Log("DropRate.csv中字段[drop_info11]位置不对应"); return false; }
		if(vecLine[19]!="drop_info12"){Ex.Logger.Log("DropRate.csv中字段[drop_info12]位置不对应"); return false; }
		if(vecLine[20]!="drop_info13"){Ex.Logger.Log("DropRate.csv中字段[drop_info13]位置不对应"); return false; }
		if(vecLine[21]!="drop_info14"){Ex.Logger.Log("DropRate.csv中字段[drop_info14]位置不对应"); return false; }
		if(vecLine[22]!="drop_info15"){Ex.Logger.Log("DropRate.csv中字段[drop_info15]位置不对应"); return false; }
		if(vecLine[23]!="drop_info16"){Ex.Logger.Log("DropRate.csv中字段[drop_info16]位置不对应"); return false; }
		if(vecLine[24]!="drop_info17"){Ex.Logger.Log("DropRate.csv中字段[drop_info17]位置不对应"); return false; }
		if(vecLine[25]!="drop_info18"){Ex.Logger.Log("DropRate.csv中字段[drop_info18]位置不对应"); return false; }
		if(vecLine[26]!="drop_info19"){Ex.Logger.Log("DropRate.csv中字段[drop_info19]位置不对应"); return false; }
		if(vecLine[27]!="drop_info20"){Ex.Logger.Log("DropRate.csv中字段[drop_info20]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			DropRateElement member = new DropRateElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.experience );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.transit_tag );
			readPos += GameAssist.ReadFloat( binContent, readPos, out member.gold_rate);
			readPos += GameAssist.ReadString( binContent, readPos, out member.gold_range);
			readPos += GameAssist.ReadString( binContent, readPos, out member.heap_range);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.Binding );
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info5);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info6);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info7);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info8);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info9);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info10);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info12);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info13);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info14);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info15);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info16);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info17);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info18);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info19);
			readPos += GameAssist.ReadString( binContent, readPos, out member.drop_info20);

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
		if(vecLine.Count != 28)
		{
			Ex.Logger.Log("DropRate.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("DropRate.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("DropRate.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="experience"){Ex.Logger.Log("DropRate.csv中字段[experience]位置不对应"); return false; }
		if(vecLine[3]!="transit_tag"){Ex.Logger.Log("DropRate.csv中字段[transit_tag]位置不对应"); return false; }
		if(vecLine[4]!="gold_rate"){Ex.Logger.Log("DropRate.csv中字段[gold_rate]位置不对应"); return false; }
		if(vecLine[5]!="gold_range"){Ex.Logger.Log("DropRate.csv中字段[gold_range]位置不对应"); return false; }
		if(vecLine[6]!="heap_range"){Ex.Logger.Log("DropRate.csv中字段[heap_range]位置不对应"); return false; }
		if(vecLine[7]!="Binding"){Ex.Logger.Log("DropRate.csv中字段[Binding]位置不对应"); return false; }
		if(vecLine[8]!="drop_info1"){Ex.Logger.Log("DropRate.csv中字段[drop_info1]位置不对应"); return false; }
		if(vecLine[9]!="drop_info2"){Ex.Logger.Log("DropRate.csv中字段[drop_info2]位置不对应"); return false; }
		if(vecLine[10]!="drop_info3"){Ex.Logger.Log("DropRate.csv中字段[drop_info3]位置不对应"); return false; }
		if(vecLine[11]!="drop_info4"){Ex.Logger.Log("DropRate.csv中字段[drop_info4]位置不对应"); return false; }
		if(vecLine[12]!="drop_info5"){Ex.Logger.Log("DropRate.csv中字段[drop_info5]位置不对应"); return false; }
		if(vecLine[13]!="drop_info6"){Ex.Logger.Log("DropRate.csv中字段[drop_info6]位置不对应"); return false; }
		if(vecLine[14]!="drop_info7"){Ex.Logger.Log("DropRate.csv中字段[drop_info7]位置不对应"); return false; }
		if(vecLine[15]!="drop_info8"){Ex.Logger.Log("DropRate.csv中字段[drop_info8]位置不对应"); return false; }
		if(vecLine[16]!="drop_info9"){Ex.Logger.Log("DropRate.csv中字段[drop_info9]位置不对应"); return false; }
		if(vecLine[17]!="drop_info10"){Ex.Logger.Log("DropRate.csv中字段[drop_info10]位置不对应"); return false; }
		if(vecLine[18]!="drop_info11"){Ex.Logger.Log("DropRate.csv中字段[drop_info11]位置不对应"); return false; }
		if(vecLine[19]!="drop_info12"){Ex.Logger.Log("DropRate.csv中字段[drop_info12]位置不对应"); return false; }
		if(vecLine[20]!="drop_info13"){Ex.Logger.Log("DropRate.csv中字段[drop_info13]位置不对应"); return false; }
		if(vecLine[21]!="drop_info14"){Ex.Logger.Log("DropRate.csv中字段[drop_info14]位置不对应"); return false; }
		if(vecLine[22]!="drop_info15"){Ex.Logger.Log("DropRate.csv中字段[drop_info15]位置不对应"); return false; }
		if(vecLine[23]!="drop_info16"){Ex.Logger.Log("DropRate.csv中字段[drop_info16]位置不对应"); return false; }
		if(vecLine[24]!="drop_info17"){Ex.Logger.Log("DropRate.csv中字段[drop_info17]位置不对应"); return false; }
		if(vecLine[25]!="drop_info18"){Ex.Logger.Log("DropRate.csv中字段[drop_info18]位置不对应"); return false; }
		if(vecLine[26]!="drop_info19"){Ex.Logger.Log("DropRate.csv中字段[drop_info19]位置不对应"); return false; }
		if(vecLine[27]!="drop_info20"){Ex.Logger.Log("DropRate.csv中字段[drop_info20]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)28)
			{
				return false;
			}
			DropRateElement member = new DropRateElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.experience=Convert.ToInt32(vecLine[2]);
			member.transit_tag=Convert.ToInt32(vecLine[3]);
			member.gold_rate=Convert.ToSingle(vecLine[4]);
			member.gold_range=vecLine[5];
			member.heap_range=vecLine[6];
			member.Binding=Convert.ToInt32(vecLine[7]);
			member.drop_info1=vecLine[8];
			member.drop_info2=vecLine[9];
			member.drop_info3=vecLine[10];
			member.drop_info4=vecLine[11];
			member.drop_info5=vecLine[12];
			member.drop_info6=vecLine[13];
			member.drop_info7=vecLine[14];
			member.drop_info8=vecLine[15];
			member.drop_info9=vecLine[16];
			member.drop_info10=vecLine[17];
			member.drop_info11=vecLine[18];
			member.drop_info12=vecLine[19];
			member.drop_info13=vecLine[20];
			member.drop_info14=vecLine[21];
			member.drop_info15=vecLine[22];
			member.drop_info16=vecLine[23];
			member.drop_info17=vecLine[24];
			member.drop_info18=vecLine[25];
			member.drop_info19=vecLine[26];
			member.drop_info20=vecLine[27];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
