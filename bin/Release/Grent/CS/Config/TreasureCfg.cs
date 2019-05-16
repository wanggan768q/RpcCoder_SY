using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//宝物库表配置数据类
public class TreasureElement
{
	public int id;               	//ID	
	public string comment;       	//道具注释	策划用  附加信息说明： A、B、C代表外显使用时限 1、2、3、4代表外显不同配色
	public string icon_resources;	//图标资源	外显图标资源路径
	public int explicit_sort;    	//外显分类	外显对应的分类 1：头部 2：时装 3：武器 4：翅膀 5：坐骑 6：脚印 7.技能特效
	public int name;             	//名字	外显名称 文本表ID
	public int description;      	//描述	外显对应的描述文本 
	public int site;             	//所属部位	如果外显分类为1，该字段才生效 1：头部时装 2：衣服时装
	public li occupation;        	//所属职业	该时装所属的职业ID 1=战士 2=刺客 3=游侠 4=法师 5=圣骑士 6=神秘使 
	public int quality;          	//品质	1=绿色 2=蓝色 3=紫色
	public int effect_judge;     	//是否具有特效	该外显是否有特殊效果 0：没有 1：有
	public string effect_info;   	//特效信息	特效分类|特效名称|特效描述|特效ID 特效分类： 1：技能特效 2：嘲讽动作 3：脚印效果
	public li extra_infoa1;      	//附加信息A1	 颜色（如：red、blue、green） 附加信息脚本（解锁时间）
	public li resource_patha1;   	//资源路径A1	该外显的资源路径
	public int treasure_pointsa1;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditiona11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditiona12;	//解锁条件2	
	public li unlock_conditiona13;	//解锁条件3	
	public li unlock_conditiona14;	//解锁条件4	
	public li unlock_conditiona15;	//解锁条件5	
	public li extra_infoa2;      	//附加信息A2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_patha2;   	//资源路径	该外显的资源路径
	public int treasure_pointsa2;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditiona21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditiona22;	//解锁条件2	
	public li unlock_conditiona23;	//解锁条件3	
	public li unlock_conditiona24;	//解锁条件4	
	public li unlock_conditiona25;	//解锁条件5	
	public li extra_infoa3;      	//附加信息A3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_patha3;   	//资源路径	该外显的资源路径
	public int treasure_pointsa3;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditiona31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditiona32;	//解锁条件2	
	public li unlock_conditiona33;	//解锁条件3	
	public li unlock_conditiona34;	//解锁条件4	
	public li unlock_conditiona35;	//解锁条件5	
	public li extra_infoa4;      	//附加信息A4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_patha4;   	//资源路径	该外显的资源路径
	public int treasure_pointsa4;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditiona41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditiona42;	//解锁条件2	
	public li unlock_conditiona43;	//解锁条件3	
	public li unlock_conditiona44;	//解锁条件4	
	public li unlock_conditiona45;	//解锁条件5	
	public li extra_infob1;      	//附加信息B1	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathb1;   	//资源路径	该外显的资源路径
	public int treasure_pointsb1;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionb11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionb12;	//解锁条件2	
	public li unlock_conditionb13;	//解锁条件3	
	public li unlock_conditionb14;	//解锁条件4	
	public li unlock_conditionb15;	//解锁条件5	
	public li extra_infob2;      	//附加信息B2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathb2;   	//资源路径	该外显的资源路径
	public int treasure_pointsb2;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionb21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionb22;	//解锁条件2	
	public li unlock_conditionb23;	//解锁条件3	
	public li unlock_conditionb24;	//解锁条件4	
	public li unlock_conditionb25;	//解锁条件5	
	public li extra_infob3;      	//附加信息B3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathb3;   	//资源路径	该外显的资源路径
	public int treasure_pointsb3;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionb31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionb32;	//解锁条件2	
	public li unlock_conditionb33;	//解锁条件3	
	public li unlock_conditionb34;	//解锁条件4	
	public li unlock_conditionb35;	//解锁条件5	
	public li extra_infob4;      	//附加信息B4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathb4;   	//资源路径	该外显的资源路径
	public int treasure_pointsb4;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionb41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionb42;	//解锁条件2	
	public li unlock_conditionb43;	//解锁条件3	
	public li unlock_conditionb44;	//解锁条件4	
	public li unlock_conditionb45;	//解锁条件5	
	public li extra_infoc1;      	//附加信息C1	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathc1;   	//资源路径	该外显的资源路径
	public int treasure_pointsc1;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionc11;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionc12;	//解锁条件2	
	public li unlock_conditionc13;	//解锁条件3	
	public li unlock_conditionc14;	//解锁条件4	
	public li unlock_conditionc15;	//解锁条件5	
	public li extra_infoc2;      	//附加信息C2	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathc2;   	//资源路径	该外显的资源路径
	public int treasure_pointsc2;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionc21;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionc22;	//解锁条件2	
	public li unlock_conditionc23;	//解锁条件3	
	public li unlock_conditionc24;	//解锁条件4	
	public li unlock_conditionc25;	//解锁条件5	
	public li extra_infoc3;      	//附加信息C3	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathc3;   	//资源路径	该外显的资源路径
	public int treasure_pointsc3;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionc31;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionc32;	//解锁条件2	
	public li unlock_conditionc33;	//解锁条件3	
	public li unlock_conditionc34;	//解锁条件4	
	public li unlock_conditionc35;	//解锁条件5	
	public li extra_infoc4;      	//附加信息C4	附加信息脚本|解锁时间 颜色（如：red、blue、green） 单双人坐骑（如：single、double)
	public li resource_pathc4;   	//资源路径	该外显的资源路径
	public int treasure_pointsc4;	//宝物点数	该外显提供的宝物点数
	public li unlock_conditionc41;	//解锁条件1	该外显所具有的解锁条件1 解锁条件脚本|参数 消耗道具（如：1|物品id|数量) 成就类（如：2|达成进度)
	public li unlock_conditionc42;	//解锁条件2	
	public li unlock_conditionc43;	//解锁条件3	
	public li unlock_conditionc44;	//解锁条件4	
	public li unlock_conditionc45;	//解锁条件5	

	public bool IsValidate = false;
	public TreasureElement()
	{
		id = -1;
	}
};

//宝物库表配置封装类
public class TreasureTable
{

	private TreasureTable()
	{
		m_mapElements = new Dictionary<int, TreasureElement>();
		m_emptyItem = new TreasureElement();
		m_vecAllElements = new List<TreasureElement>();
	}
	private Dictionary<int, TreasureElement> m_mapElements = null;
	private List<TreasureElement>	m_vecAllElements = null;
	private TreasureElement m_emptyItem = null;
	private static TreasureTable sInstance = null;

	public static TreasureTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new TreasureTable();
			return sInstance;
		}
	}

	public TreasureElement GetElement(int key)
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

  public List<TreasureElement> GetAllElement(Predicate<TreasureElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("Treasure.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("Treasure.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[Treasure.bin]未找到");
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
		if(vecLine.Count != 107)
		{
			Ex.Logger.Log("Treasure.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Treasure.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Treasure.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="icon_resources"){Ex.Logger.Log("Treasure.csv中字段[icon_resources]位置不对应"); return false; }
		if(vecLine[3]!="explicit_sort"){Ex.Logger.Log("Treasure.csv中字段[explicit_sort]位置不对应"); return false; }
		if(vecLine[4]!="name"){Ex.Logger.Log("Treasure.csv中字段[name]位置不对应"); return false; }
		if(vecLine[5]!="description"){Ex.Logger.Log("Treasure.csv中字段[description]位置不对应"); return false; }
		if(vecLine[6]!="site"){Ex.Logger.Log("Treasure.csv中字段[site]位置不对应"); return false; }
		if(vecLine[7]!="occupation"){Ex.Logger.Log("Treasure.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[8]!="quality"){Ex.Logger.Log("Treasure.csv中字段[quality]位置不对应"); return false; }
		if(vecLine[9]!="effect_judge"){Ex.Logger.Log("Treasure.csv中字段[effect_judge]位置不对应"); return false; }
		if(vecLine[10]!="effect_info"){Ex.Logger.Log("Treasure.csv中字段[effect_info]位置不对应"); return false; }
		if(vecLine[11]!="extra_infoa1"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa1]位置不对应"); return false; }
		if(vecLine[12]!="resource_patha1"){Ex.Logger.Log("Treasure.csv中字段[resource_patha1]位置不对应"); return false; }
		if(vecLine[13]!="treasure_pointsa1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa1]位置不对应"); return false; }
		if(vecLine[14]!="unlock_conditiona11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona11]位置不对应"); return false; }
		if(vecLine[15]!="unlock_conditiona12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona12]位置不对应"); return false; }
		if(vecLine[16]!="unlock_conditiona13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona13]位置不对应"); return false; }
		if(vecLine[17]!="unlock_conditiona14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona14]位置不对应"); return false; }
		if(vecLine[18]!="unlock_conditiona15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona15]位置不对应"); return false; }
		if(vecLine[19]!="extra_infoa2"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa2]位置不对应"); return false; }
		if(vecLine[20]!="resource_patha2"){Ex.Logger.Log("Treasure.csv中字段[resource_patha2]位置不对应"); return false; }
		if(vecLine[21]!="treasure_pointsa2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa2]位置不对应"); return false; }
		if(vecLine[22]!="unlock_conditiona21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona21]位置不对应"); return false; }
		if(vecLine[23]!="unlock_conditiona22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona22]位置不对应"); return false; }
		if(vecLine[24]!="unlock_conditiona23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona23]位置不对应"); return false; }
		if(vecLine[25]!="unlock_conditiona24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona24]位置不对应"); return false; }
		if(vecLine[26]!="unlock_conditiona25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona25]位置不对应"); return false; }
		if(vecLine[27]!="extra_infoa3"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa3]位置不对应"); return false; }
		if(vecLine[28]!="resource_patha3"){Ex.Logger.Log("Treasure.csv中字段[resource_patha3]位置不对应"); return false; }
		if(vecLine[29]!="treasure_pointsa3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa3]位置不对应"); return false; }
		if(vecLine[30]!="unlock_conditiona31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona31]位置不对应"); return false; }
		if(vecLine[31]!="unlock_conditiona32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona32]位置不对应"); return false; }
		if(vecLine[32]!="unlock_conditiona33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona33]位置不对应"); return false; }
		if(vecLine[33]!="unlock_conditiona34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona34]位置不对应"); return false; }
		if(vecLine[34]!="unlock_conditiona35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona35]位置不对应"); return false; }
		if(vecLine[35]!="extra_infoa4"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa4]位置不对应"); return false; }
		if(vecLine[36]!="resource_patha4"){Ex.Logger.Log("Treasure.csv中字段[resource_patha4]位置不对应"); return false; }
		if(vecLine[37]!="treasure_pointsa4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa4]位置不对应"); return false; }
		if(vecLine[38]!="unlock_conditiona41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona41]位置不对应"); return false; }
		if(vecLine[39]!="unlock_conditiona42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona42]位置不对应"); return false; }
		if(vecLine[40]!="unlock_conditiona43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona43]位置不对应"); return false; }
		if(vecLine[41]!="unlock_conditiona44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona44]位置不对应"); return false; }
		if(vecLine[42]!="unlock_conditiona45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona45]位置不对应"); return false; }
		if(vecLine[43]!="extra_infob1"){Ex.Logger.Log("Treasure.csv中字段[extra_infob1]位置不对应"); return false; }
		if(vecLine[44]!="resource_pathb1"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb1]位置不对应"); return false; }
		if(vecLine[45]!="treasure_pointsb1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb1]位置不对应"); return false; }
		if(vecLine[46]!="unlock_conditionb11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb11]位置不对应"); return false; }
		if(vecLine[47]!="unlock_conditionb12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb12]位置不对应"); return false; }
		if(vecLine[48]!="unlock_conditionb13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb13]位置不对应"); return false; }
		if(vecLine[49]!="unlock_conditionb14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb14]位置不对应"); return false; }
		if(vecLine[50]!="unlock_conditionb15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb15]位置不对应"); return false; }
		if(vecLine[51]!="extra_infob2"){Ex.Logger.Log("Treasure.csv中字段[extra_infob2]位置不对应"); return false; }
		if(vecLine[52]!="resource_pathb2"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb2]位置不对应"); return false; }
		if(vecLine[53]!="treasure_pointsb2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb2]位置不对应"); return false; }
		if(vecLine[54]!="unlock_conditionb21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb21]位置不对应"); return false; }
		if(vecLine[55]!="unlock_conditionb22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb22]位置不对应"); return false; }
		if(vecLine[56]!="unlock_conditionb23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb23]位置不对应"); return false; }
		if(vecLine[57]!="unlock_conditionb24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb24]位置不对应"); return false; }
		if(vecLine[58]!="unlock_conditionb25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb25]位置不对应"); return false; }
		if(vecLine[59]!="extra_infob3"){Ex.Logger.Log("Treasure.csv中字段[extra_infob3]位置不对应"); return false; }
		if(vecLine[60]!="resource_pathb3"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb3]位置不对应"); return false; }
		if(vecLine[61]!="treasure_pointsb3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb3]位置不对应"); return false; }
		if(vecLine[62]!="unlock_conditionb31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb31]位置不对应"); return false; }
		if(vecLine[63]!="unlock_conditionb32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb32]位置不对应"); return false; }
		if(vecLine[64]!="unlock_conditionb33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb33]位置不对应"); return false; }
		if(vecLine[65]!="unlock_conditionb34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb34]位置不对应"); return false; }
		if(vecLine[66]!="unlock_conditionb35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb35]位置不对应"); return false; }
		if(vecLine[67]!="extra_infob4"){Ex.Logger.Log("Treasure.csv中字段[extra_infob4]位置不对应"); return false; }
		if(vecLine[68]!="resource_pathb4"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb4]位置不对应"); return false; }
		if(vecLine[69]!="treasure_pointsb4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb4]位置不对应"); return false; }
		if(vecLine[70]!="unlock_conditionb41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb41]位置不对应"); return false; }
		if(vecLine[71]!="unlock_conditionb42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb42]位置不对应"); return false; }
		if(vecLine[72]!="unlock_conditionb43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb43]位置不对应"); return false; }
		if(vecLine[73]!="unlock_conditionb44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb44]位置不对应"); return false; }
		if(vecLine[74]!="unlock_conditionb45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb45]位置不对应"); return false; }
		if(vecLine[75]!="extra_infoc1"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc1]位置不对应"); return false; }
		if(vecLine[76]!="resource_pathc1"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc1]位置不对应"); return false; }
		if(vecLine[77]!="treasure_pointsc1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc1]位置不对应"); return false; }
		if(vecLine[78]!="unlock_conditionc11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc11]位置不对应"); return false; }
		if(vecLine[79]!="unlock_conditionc12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc12]位置不对应"); return false; }
		if(vecLine[80]!="unlock_conditionc13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc13]位置不对应"); return false; }
		if(vecLine[81]!="unlock_conditionc14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc14]位置不对应"); return false; }
		if(vecLine[82]!="unlock_conditionc15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc15]位置不对应"); return false; }
		if(vecLine[83]!="extra_infoc2"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc2]位置不对应"); return false; }
		if(vecLine[84]!="resource_pathc2"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc2]位置不对应"); return false; }
		if(vecLine[85]!="treasure_pointsc2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc2]位置不对应"); return false; }
		if(vecLine[86]!="unlock_conditionc21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc21]位置不对应"); return false; }
		if(vecLine[87]!="unlock_conditionc22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc22]位置不对应"); return false; }
		if(vecLine[88]!="unlock_conditionc23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc23]位置不对应"); return false; }
		if(vecLine[89]!="unlock_conditionc24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc24]位置不对应"); return false; }
		if(vecLine[90]!="unlock_conditionc25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc25]位置不对应"); return false; }
		if(vecLine[91]!="extra_infoc3"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc3]位置不对应"); return false; }
		if(vecLine[92]!="resource_pathc3"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc3]位置不对应"); return false; }
		if(vecLine[93]!="treasure_pointsc3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc3]位置不对应"); return false; }
		if(vecLine[94]!="unlock_conditionc31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc31]位置不对应"); return false; }
		if(vecLine[95]!="unlock_conditionc32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc32]位置不对应"); return false; }
		if(vecLine[96]!="unlock_conditionc33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc33]位置不对应"); return false; }
		if(vecLine[97]!="unlock_conditionc34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc34]位置不对应"); return false; }
		if(vecLine[98]!="unlock_conditionc35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc35]位置不对应"); return false; }
		if(vecLine[99]!="extra_infoc4"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc4]位置不对应"); return false; }
		if(vecLine[100]!="resource_pathc4"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc4]位置不对应"); return false; }
		if(vecLine[101]!="treasure_pointsc4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc4]位置不对应"); return false; }
		if(vecLine[102]!="unlock_conditionc41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc41]位置不对应"); return false; }
		if(vecLine[103]!="unlock_conditionc42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc42]位置不对应"); return false; }
		if(vecLine[104]!="unlock_conditionc43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc43]位置不对应"); return false; }
		if(vecLine[105]!="unlock_conditionc44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc44]位置不对应"); return false; }
		if(vecLine[106]!="unlock_conditionc45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc45]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			TreasureElement member = new TreasureElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadString( binContent, readPos, out member.icon_resources);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.explicit_sort );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.name );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.description );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.site );
			readPos += GameAssist.ReadString( binContent, readPos, out member.occupation);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quality );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.effect_judge );
			readPos += GameAssist.ReadString( binContent, readPos, out member.effect_info);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoa1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_patha1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsa1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona12);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona13);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona14);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona15);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoa2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_patha2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsa2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona21);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona22);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona23);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona24);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona25);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoa3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_patha3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsa3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona31);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona32);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona33);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona34);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona35);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoa4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_patha4);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsa4 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona41);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona42);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona43);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona44);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditiona45);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infob1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathb1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsb1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb12);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb13);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb14);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb15);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infob2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathb2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsb2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb21);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb22);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb23);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb24);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb25);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infob3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathb3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsb3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb31);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb32);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb33);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb34);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb35);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infob4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathb4);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsb4 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb41);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb42);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb43);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb44);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionb45);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoc1);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathc1);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsc1 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc11);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc12);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc13);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc14);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc15);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoc2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathc2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsc2 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc21);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc22);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc23);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc24);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc25);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoc3);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathc3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsc3 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc31);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc32);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc33);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc34);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc35);
			readPos += GameAssist.ReadString( binContent, readPos, out member.extra_infoc4);
			readPos += GameAssist.ReadString( binContent, readPos, out member.resource_pathc4);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.treasure_pointsc4 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc41);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc42);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc43);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc44);
			readPos += GameAssist.ReadString( binContent, readPos, out member.unlock_conditionc45);

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
		if(vecLine.Count != 107)
		{
			Ex.Logger.Log("Treasure.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Treasure.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="comment"){Ex.Logger.Log("Treasure.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[2]!="icon_resources"){Ex.Logger.Log("Treasure.csv中字段[icon_resources]位置不对应"); return false; }
		if(vecLine[3]!="explicit_sort"){Ex.Logger.Log("Treasure.csv中字段[explicit_sort]位置不对应"); return false; }
		if(vecLine[4]!="name"){Ex.Logger.Log("Treasure.csv中字段[name]位置不对应"); return false; }
		if(vecLine[5]!="description"){Ex.Logger.Log("Treasure.csv中字段[description]位置不对应"); return false; }
		if(vecLine[6]!="site"){Ex.Logger.Log("Treasure.csv中字段[site]位置不对应"); return false; }
		if(vecLine[7]!="occupation"){Ex.Logger.Log("Treasure.csv中字段[occupation]位置不对应"); return false; }
		if(vecLine[8]!="quality"){Ex.Logger.Log("Treasure.csv中字段[quality]位置不对应"); return false; }
		if(vecLine[9]!="effect_judge"){Ex.Logger.Log("Treasure.csv中字段[effect_judge]位置不对应"); return false; }
		if(vecLine[10]!="effect_info"){Ex.Logger.Log("Treasure.csv中字段[effect_info]位置不对应"); return false; }
		if(vecLine[11]!="extra_infoa1"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa1]位置不对应"); return false; }
		if(vecLine[12]!="resource_patha1"){Ex.Logger.Log("Treasure.csv中字段[resource_patha1]位置不对应"); return false; }
		if(vecLine[13]!="treasure_pointsa1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa1]位置不对应"); return false; }
		if(vecLine[14]!="unlock_conditiona11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona11]位置不对应"); return false; }
		if(vecLine[15]!="unlock_conditiona12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona12]位置不对应"); return false; }
		if(vecLine[16]!="unlock_conditiona13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona13]位置不对应"); return false; }
		if(vecLine[17]!="unlock_conditiona14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona14]位置不对应"); return false; }
		if(vecLine[18]!="unlock_conditiona15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona15]位置不对应"); return false; }
		if(vecLine[19]!="extra_infoa2"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa2]位置不对应"); return false; }
		if(vecLine[20]!="resource_patha2"){Ex.Logger.Log("Treasure.csv中字段[resource_patha2]位置不对应"); return false; }
		if(vecLine[21]!="treasure_pointsa2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa2]位置不对应"); return false; }
		if(vecLine[22]!="unlock_conditiona21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona21]位置不对应"); return false; }
		if(vecLine[23]!="unlock_conditiona22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona22]位置不对应"); return false; }
		if(vecLine[24]!="unlock_conditiona23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona23]位置不对应"); return false; }
		if(vecLine[25]!="unlock_conditiona24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona24]位置不对应"); return false; }
		if(vecLine[26]!="unlock_conditiona25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona25]位置不对应"); return false; }
		if(vecLine[27]!="extra_infoa3"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa3]位置不对应"); return false; }
		if(vecLine[28]!="resource_patha3"){Ex.Logger.Log("Treasure.csv中字段[resource_patha3]位置不对应"); return false; }
		if(vecLine[29]!="treasure_pointsa3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa3]位置不对应"); return false; }
		if(vecLine[30]!="unlock_conditiona31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona31]位置不对应"); return false; }
		if(vecLine[31]!="unlock_conditiona32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona32]位置不对应"); return false; }
		if(vecLine[32]!="unlock_conditiona33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona33]位置不对应"); return false; }
		if(vecLine[33]!="unlock_conditiona34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona34]位置不对应"); return false; }
		if(vecLine[34]!="unlock_conditiona35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona35]位置不对应"); return false; }
		if(vecLine[35]!="extra_infoa4"){Ex.Logger.Log("Treasure.csv中字段[extra_infoa4]位置不对应"); return false; }
		if(vecLine[36]!="resource_patha4"){Ex.Logger.Log("Treasure.csv中字段[resource_patha4]位置不对应"); return false; }
		if(vecLine[37]!="treasure_pointsa4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsa4]位置不对应"); return false; }
		if(vecLine[38]!="unlock_conditiona41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona41]位置不对应"); return false; }
		if(vecLine[39]!="unlock_conditiona42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona42]位置不对应"); return false; }
		if(vecLine[40]!="unlock_conditiona43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona43]位置不对应"); return false; }
		if(vecLine[41]!="unlock_conditiona44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona44]位置不对应"); return false; }
		if(vecLine[42]!="unlock_conditiona45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditiona45]位置不对应"); return false; }
		if(vecLine[43]!="extra_infob1"){Ex.Logger.Log("Treasure.csv中字段[extra_infob1]位置不对应"); return false; }
		if(vecLine[44]!="resource_pathb1"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb1]位置不对应"); return false; }
		if(vecLine[45]!="treasure_pointsb1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb1]位置不对应"); return false; }
		if(vecLine[46]!="unlock_conditionb11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb11]位置不对应"); return false; }
		if(vecLine[47]!="unlock_conditionb12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb12]位置不对应"); return false; }
		if(vecLine[48]!="unlock_conditionb13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb13]位置不对应"); return false; }
		if(vecLine[49]!="unlock_conditionb14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb14]位置不对应"); return false; }
		if(vecLine[50]!="unlock_conditionb15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb15]位置不对应"); return false; }
		if(vecLine[51]!="extra_infob2"){Ex.Logger.Log("Treasure.csv中字段[extra_infob2]位置不对应"); return false; }
		if(vecLine[52]!="resource_pathb2"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb2]位置不对应"); return false; }
		if(vecLine[53]!="treasure_pointsb2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb2]位置不对应"); return false; }
		if(vecLine[54]!="unlock_conditionb21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb21]位置不对应"); return false; }
		if(vecLine[55]!="unlock_conditionb22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb22]位置不对应"); return false; }
		if(vecLine[56]!="unlock_conditionb23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb23]位置不对应"); return false; }
		if(vecLine[57]!="unlock_conditionb24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb24]位置不对应"); return false; }
		if(vecLine[58]!="unlock_conditionb25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb25]位置不对应"); return false; }
		if(vecLine[59]!="extra_infob3"){Ex.Logger.Log("Treasure.csv中字段[extra_infob3]位置不对应"); return false; }
		if(vecLine[60]!="resource_pathb3"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb3]位置不对应"); return false; }
		if(vecLine[61]!="treasure_pointsb3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb3]位置不对应"); return false; }
		if(vecLine[62]!="unlock_conditionb31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb31]位置不对应"); return false; }
		if(vecLine[63]!="unlock_conditionb32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb32]位置不对应"); return false; }
		if(vecLine[64]!="unlock_conditionb33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb33]位置不对应"); return false; }
		if(vecLine[65]!="unlock_conditionb34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb34]位置不对应"); return false; }
		if(vecLine[66]!="unlock_conditionb35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb35]位置不对应"); return false; }
		if(vecLine[67]!="extra_infob4"){Ex.Logger.Log("Treasure.csv中字段[extra_infob4]位置不对应"); return false; }
		if(vecLine[68]!="resource_pathb4"){Ex.Logger.Log("Treasure.csv中字段[resource_pathb4]位置不对应"); return false; }
		if(vecLine[69]!="treasure_pointsb4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsb4]位置不对应"); return false; }
		if(vecLine[70]!="unlock_conditionb41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb41]位置不对应"); return false; }
		if(vecLine[71]!="unlock_conditionb42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb42]位置不对应"); return false; }
		if(vecLine[72]!="unlock_conditionb43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb43]位置不对应"); return false; }
		if(vecLine[73]!="unlock_conditionb44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb44]位置不对应"); return false; }
		if(vecLine[74]!="unlock_conditionb45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionb45]位置不对应"); return false; }
		if(vecLine[75]!="extra_infoc1"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc1]位置不对应"); return false; }
		if(vecLine[76]!="resource_pathc1"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc1]位置不对应"); return false; }
		if(vecLine[77]!="treasure_pointsc1"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc1]位置不对应"); return false; }
		if(vecLine[78]!="unlock_conditionc11"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc11]位置不对应"); return false; }
		if(vecLine[79]!="unlock_conditionc12"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc12]位置不对应"); return false; }
		if(vecLine[80]!="unlock_conditionc13"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc13]位置不对应"); return false; }
		if(vecLine[81]!="unlock_conditionc14"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc14]位置不对应"); return false; }
		if(vecLine[82]!="unlock_conditionc15"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc15]位置不对应"); return false; }
		if(vecLine[83]!="extra_infoc2"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc2]位置不对应"); return false; }
		if(vecLine[84]!="resource_pathc2"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc2]位置不对应"); return false; }
		if(vecLine[85]!="treasure_pointsc2"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc2]位置不对应"); return false; }
		if(vecLine[86]!="unlock_conditionc21"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc21]位置不对应"); return false; }
		if(vecLine[87]!="unlock_conditionc22"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc22]位置不对应"); return false; }
		if(vecLine[88]!="unlock_conditionc23"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc23]位置不对应"); return false; }
		if(vecLine[89]!="unlock_conditionc24"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc24]位置不对应"); return false; }
		if(vecLine[90]!="unlock_conditionc25"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc25]位置不对应"); return false; }
		if(vecLine[91]!="extra_infoc3"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc3]位置不对应"); return false; }
		if(vecLine[92]!="resource_pathc3"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc3]位置不对应"); return false; }
		if(vecLine[93]!="treasure_pointsc3"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc3]位置不对应"); return false; }
		if(vecLine[94]!="unlock_conditionc31"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc31]位置不对应"); return false; }
		if(vecLine[95]!="unlock_conditionc32"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc32]位置不对应"); return false; }
		if(vecLine[96]!="unlock_conditionc33"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc33]位置不对应"); return false; }
		if(vecLine[97]!="unlock_conditionc34"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc34]位置不对应"); return false; }
		if(vecLine[98]!="unlock_conditionc35"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc35]位置不对应"); return false; }
		if(vecLine[99]!="extra_infoc4"){Ex.Logger.Log("Treasure.csv中字段[extra_infoc4]位置不对应"); return false; }
		if(vecLine[100]!="resource_pathc4"){Ex.Logger.Log("Treasure.csv中字段[resource_pathc4]位置不对应"); return false; }
		if(vecLine[101]!="treasure_pointsc4"){Ex.Logger.Log("Treasure.csv中字段[treasure_pointsc4]位置不对应"); return false; }
		if(vecLine[102]!="unlock_conditionc41"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc41]位置不对应"); return false; }
		if(vecLine[103]!="unlock_conditionc42"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc42]位置不对应"); return false; }
		if(vecLine[104]!="unlock_conditionc43"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc43]位置不对应"); return false; }
		if(vecLine[105]!="unlock_conditionc44"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc44]位置不对应"); return false; }
		if(vecLine[106]!="unlock_conditionc45"){Ex.Logger.Log("Treasure.csv中字段[unlock_conditionc45]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)107)
			{
				return false;
			}
			TreasureElement member = new TreasureElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.comment=vecLine[1];
			member.icon_resources=vecLine[2];
			member.explicit_sort=Convert.ToInt32(vecLine[3]);
			member.name=Convert.ToInt32(vecLine[4]);
			member.description=Convert.ToInt32(vecLine[5]);
			member.site=Convert.ToInt32(vecLine[6]);
			member.occupation=vecLine[7];
			member.quality=Convert.ToInt32(vecLine[8]);
			member.effect_judge=Convert.ToInt32(vecLine[9]);
			member.effect_info=vecLine[10];
			member.extra_infoa1=vecLine[11];
			member.resource_patha1=vecLine[12];
			member.treasure_pointsa1=Convert.ToInt32(vecLine[13]);
			member.unlock_conditiona11=vecLine[14];
			member.unlock_conditiona12=vecLine[15];
			member.unlock_conditiona13=vecLine[16];
			member.unlock_conditiona14=vecLine[17];
			member.unlock_conditiona15=vecLine[18];
			member.extra_infoa2=vecLine[19];
			member.resource_patha2=vecLine[20];
			member.treasure_pointsa2=Convert.ToInt32(vecLine[21]);
			member.unlock_conditiona21=vecLine[22];
			member.unlock_conditiona22=vecLine[23];
			member.unlock_conditiona23=vecLine[24];
			member.unlock_conditiona24=vecLine[25];
			member.unlock_conditiona25=vecLine[26];
			member.extra_infoa3=vecLine[27];
			member.resource_patha3=vecLine[28];
			member.treasure_pointsa3=Convert.ToInt32(vecLine[29]);
			member.unlock_conditiona31=vecLine[30];
			member.unlock_conditiona32=vecLine[31];
			member.unlock_conditiona33=vecLine[32];
			member.unlock_conditiona34=vecLine[33];
			member.unlock_conditiona35=vecLine[34];
			member.extra_infoa4=vecLine[35];
			member.resource_patha4=vecLine[36];
			member.treasure_pointsa4=Convert.ToInt32(vecLine[37]);
			member.unlock_conditiona41=vecLine[38];
			member.unlock_conditiona42=vecLine[39];
			member.unlock_conditiona43=vecLine[40];
			member.unlock_conditiona44=vecLine[41];
			member.unlock_conditiona45=vecLine[42];
			member.extra_infob1=vecLine[43];
			member.resource_pathb1=vecLine[44];
			member.treasure_pointsb1=Convert.ToInt32(vecLine[45]);
			member.unlock_conditionb11=vecLine[46];
			member.unlock_conditionb12=vecLine[47];
			member.unlock_conditionb13=vecLine[48];
			member.unlock_conditionb14=vecLine[49];
			member.unlock_conditionb15=vecLine[50];
			member.extra_infob2=vecLine[51];
			member.resource_pathb2=vecLine[52];
			member.treasure_pointsb2=Convert.ToInt32(vecLine[53]);
			member.unlock_conditionb21=vecLine[54];
			member.unlock_conditionb22=vecLine[55];
			member.unlock_conditionb23=vecLine[56];
			member.unlock_conditionb24=vecLine[57];
			member.unlock_conditionb25=vecLine[58];
			member.extra_infob3=vecLine[59];
			member.resource_pathb3=vecLine[60];
			member.treasure_pointsb3=Convert.ToInt32(vecLine[61]);
			member.unlock_conditionb31=vecLine[62];
			member.unlock_conditionb32=vecLine[63];
			member.unlock_conditionb33=vecLine[64];
			member.unlock_conditionb34=vecLine[65];
			member.unlock_conditionb35=vecLine[66];
			member.extra_infob4=vecLine[67];
			member.resource_pathb4=vecLine[68];
			member.treasure_pointsb4=Convert.ToInt32(vecLine[69]);
			member.unlock_conditionb41=vecLine[70];
			member.unlock_conditionb42=vecLine[71];
			member.unlock_conditionb43=vecLine[72];
			member.unlock_conditionb44=vecLine[73];
			member.unlock_conditionb45=vecLine[74];
			member.extra_infoc1=vecLine[75];
			member.resource_pathc1=vecLine[76];
			member.treasure_pointsc1=Convert.ToInt32(vecLine[77]);
			member.unlock_conditionc11=vecLine[78];
			member.unlock_conditionc12=vecLine[79];
			member.unlock_conditionc13=vecLine[80];
			member.unlock_conditionc14=vecLine[81];
			member.unlock_conditionc15=vecLine[82];
			member.extra_infoc2=vecLine[83];
			member.resource_pathc2=vecLine[84];
			member.treasure_pointsc2=Convert.ToInt32(vecLine[85]);
			member.unlock_conditionc21=vecLine[86];
			member.unlock_conditionc22=vecLine[87];
			member.unlock_conditionc23=vecLine[88];
			member.unlock_conditionc24=vecLine[89];
			member.unlock_conditionc25=vecLine[90];
			member.extra_infoc3=vecLine[91];
			member.resource_pathc3=vecLine[92];
			member.treasure_pointsc3=Convert.ToInt32(vecLine[93]);
			member.unlock_conditionc31=vecLine[94];
			member.unlock_conditionc32=vecLine[95];
			member.unlock_conditionc33=vecLine[96];
			member.unlock_conditionc34=vecLine[97];
			member.unlock_conditionc35=vecLine[98];
			member.extra_infoc4=vecLine[99];
			member.resource_pathc4=vecLine[100];
			member.treasure_pointsc4=Convert.ToInt32(vecLine[101]);
			member.unlock_conditionc41=vecLine[102];
			member.unlock_conditionc42=vecLine[103];
			member.unlock_conditionc43=vecLine[104];
			member.unlock_conditionc44=vecLine[105];
			member.unlock_conditionc45=vecLine[106];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
