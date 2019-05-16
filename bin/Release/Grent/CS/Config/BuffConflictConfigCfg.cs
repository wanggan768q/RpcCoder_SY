using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


//Buff组关系配置数据类
public class BuffConflictConfigElement
{
	public int id;               	//组id	组id 必须保证ID 是顺序的
	public string desc;          	//组名	仅策划用 矩阵行表示已存在buff 矩阵列表示新加buff
	public string group;         	//组标识	1=冲抵, 2=免疫, 3=共存
	public int g1;               	//驱散	驱散
	public int g2;               	//净化	净化
	public int g3;               	//可驱散晕眩	可驱散晕眩
	public int g4;               	//可驱散冰冻	可驱散冰冻
	public int g5;               	//可驱散沉默	可驱散沉默
	public int g6;               	//可驱散加速	可驱散加速
	public int g7;               	//可驱散减速	可驱散减速
	public int g8;               	//可驱散定身	可驱散定身
	public int g9;               	//可驱散吸血	可驱散吸血
	public int g10;              	//可驱散增加属性Buff	可驱散增加属性Buff
	public int g11;              	//可驱散回血	可驱散回血
	public int g12;              	//可驱散流血	可驱散扣血
	public int g13;              	//可驱散中毒	可驱散中毒
	public int g14;              	//可驱散灼烧	可驱散灼烧
	public int g15;              	//可驱散禁疗	可驱散禁疗
	public int g16;              	//Boss霸体	Boss霸体
	public int g17;              	//免疫	免疫
	public int g18;              	//无敌	无敌
	public int g19;              	//专精Buff1	专精Buff1
	public int g20;              	//专精Buff2	专精Buff2
	public int g21;              	//弓手雷电祝福	弓手雷电祝福
	public int g22;              	//弓手自然祝福	弓手自然祝福
	public int g23;              	//弓手寒冰祝福	弓手寒冰祝福
	public int g24;              	//弓手飓风祝福	弓手飓风祝福
	public int g25;              	//光辉剑雨	光辉剑雨
	public int g26;              	//临时霸体	临时霸体
	public int g27;              	//临时击飞、击退、拉拽	临时击飞、击退、拉拽
	public int g28;              	//不可驱散晕眩	不可驱散晕眩
	public int g29;              	//不可驱散冰冻	不可驱散冰冻
	public int g30;              	//不可驱散沉默	不可驱散沉默
	public int g31;              	//不可驱散加速	不可驱散加速
	public int g32;              	//不可驱散减速	不可驱散减速
	public int g33;              	//不可驱散定身	不可驱散定身
	public int g34;              	//不可驱散吸血	不可驱散吸血
	public int g35;              	//坐骑Buff	坐骑Buff
	public int g36;              	//宠物Buff	宠物Buff
	public int g37;              	//光环触发_生命值	光环触发_生命值
	public int g38;              	//光环触发_物理攻击	光环触发_物理攻击
	public int g39;              	//光环触发_物理防御	光环触发_物理防御
	public int g40;              	//光环触发_魔法攻击	光环触发_魔法攻击
	public int g41;              	//光环触发_魔法防御	光环触发_魔法防御
	public int g42;              	//光环触发_暴击值	光环触发_暴击值
	public int g43;              	//光环触发_韧性值	光环触发_韧性值
	public int g44;              	//光环触发_穿透值	光环触发_穿透值
	public int g45;              	//光环触发_格挡值	光环触发_格挡值
	public int g46;              	//攻击事件触发_几率增加物理攻击	攻击事件触发_几率增加物理攻击
	public int g47;              	//攻击事件触发_几率增加魔法攻击	攻击事件触发_几率增加魔法攻击
	public int g48;              	//攻击事件触发_几率增加暴击	攻击事件触发_几率增加暴击
	public int g49;              	//攻击事件触发_几率增加穿透	攻击事件触发_几率增加穿透
	public int g50;              	//防御事件触发_几率增加生命	防御事件触发_几率增加生命
	public int g51;              	//防御事件触发_几率增加物理防御	防御事件触发_几率增加物理防御
	public int g52;              	//防御事件触发_几率增加魔法防御	防御事件触发_几率增加魔法防御
	public int g53;              	//防御事件触发_几率韧性	防御事件触发_几率韧性
	public int g54;              	//防御事件触发_几率格挡	防御事件触发_几率格挡
	public li allgroup;          	//合并	公式不要手填！！！

	public bool IsValidate = false;
	public BuffConflictConfigElement()
	{
		id = -1;
	}
};

//Buff组关系配置封装类
public class BuffConflictConfigTable
{

	private BuffConflictConfigTable()
	{
		m_mapElements = new Dictionary<int, BuffConflictConfigElement>();
		m_emptyItem = new BuffConflictConfigElement();
		m_vecAllElements = new List<BuffConflictConfigElement>();
	}
	private Dictionary<int, BuffConflictConfigElement> m_mapElements = null;
	private List<BuffConflictConfigElement>	m_vecAllElements = null;
	private BuffConflictConfigElement m_emptyItem = null;
	private static BuffConflictConfigTable sInstance = null;

	public static BuffConflictConfigTable Instance
	{
		get
		{
			if( sInstance != null )
				return sInstance;	
			sInstance = new BuffConflictConfigTable();
			return sInstance;
		}
	}

	public BuffConflictConfigElement GetElement(int key)
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

  public List<BuffConflictConfigElement> GetAllElement(Predicate<BuffConflictConfigElement> matchCB = null)
	{
        if( matchCB==null || m_vecAllElements.Count == 0)
            return m_vecAllElements;
        return m_vecAllElements.FindAll(matchCB);
	}

	public bool Load()
	{
		
		string strTableContent = "";
		if( GameAssist.ReadCsvFile("BuffConflictConfig.csv", out strTableContent ) )
			return LoadCsv( strTableContent );
		byte[] binTableContent = null;
		if( !GameAssist.ReadBinFile("BuffConflictConfig.bin", out binTableContent ) )
		{
			Ex.Logger.Log("配置文件[BuffConflictConfig.bin]未找到");
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
		if(vecLine.Count != 58)
		{
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffConflictConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[4]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[5]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[6]!="g4"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[7]!="g5"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[8]!="g6"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[9]!="g7"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g7]位置不对应"); return false; }
		if(vecLine[10]!="g8"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g8]位置不对应"); return false; }
		if(vecLine[11]!="g9"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g9]位置不对应"); return false; }
		if(vecLine[12]!="g10"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g10]位置不对应"); return false; }
		if(vecLine[13]!="g11"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g11]位置不对应"); return false; }
		if(vecLine[14]!="g12"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g12]位置不对应"); return false; }
		if(vecLine[15]!="g13"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g13]位置不对应"); return false; }
		if(vecLine[16]!="g14"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g14]位置不对应"); return false; }
		if(vecLine[17]!="g15"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g15]位置不对应"); return false; }
		if(vecLine[18]!="g16"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g16]位置不对应"); return false; }
		if(vecLine[19]!="g17"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g17]位置不对应"); return false; }
		if(vecLine[20]!="g18"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g18]位置不对应"); return false; }
		if(vecLine[21]!="g19"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g19]位置不对应"); return false; }
		if(vecLine[22]!="g20"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g20]位置不对应"); return false; }
		if(vecLine[23]!="g21"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g21]位置不对应"); return false; }
		if(vecLine[24]!="g22"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g22]位置不对应"); return false; }
		if(vecLine[25]!="g23"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g23]位置不对应"); return false; }
		if(vecLine[26]!="g24"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g24]位置不对应"); return false; }
		if(vecLine[27]!="g25"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g25]位置不对应"); return false; }
		if(vecLine[28]!="g26"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g26]位置不对应"); return false; }
		if(vecLine[29]!="g27"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g27]位置不对应"); return false; }
		if(vecLine[30]!="g28"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g28]位置不对应"); return false; }
		if(vecLine[31]!="g29"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g29]位置不对应"); return false; }
		if(vecLine[32]!="g30"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g30]位置不对应"); return false; }
		if(vecLine[33]!="g31"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g31]位置不对应"); return false; }
		if(vecLine[34]!="g32"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g32]位置不对应"); return false; }
		if(vecLine[35]!="g33"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g33]位置不对应"); return false; }
		if(vecLine[36]!="g34"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g34]位置不对应"); return false; }
		if(vecLine[37]!="g35"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g35]位置不对应"); return false; }
		if(vecLine[38]!="g36"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g36]位置不对应"); return false; }
		if(vecLine[39]!="g37"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g37]位置不对应"); return false; }
		if(vecLine[40]!="g38"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g38]位置不对应"); return false; }
		if(vecLine[41]!="g39"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g39]位置不对应"); return false; }
		if(vecLine[42]!="g40"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g40]位置不对应"); return false; }
		if(vecLine[43]!="g41"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g41]位置不对应"); return false; }
		if(vecLine[44]!="g42"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g42]位置不对应"); return false; }
		if(vecLine[45]!="g43"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g43]位置不对应"); return false; }
		if(vecLine[46]!="g44"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g44]位置不对应"); return false; }
		if(vecLine[47]!="g45"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g45]位置不对应"); return false; }
		if(vecLine[48]!="g46"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g46]位置不对应"); return false; }
		if(vecLine[49]!="g47"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g47]位置不对应"); return false; }
		if(vecLine[50]!="g48"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g48]位置不对应"); return false; }
		if(vecLine[51]!="g49"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g49]位置不对应"); return false; }
		if(vecLine[52]!="g50"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g50]位置不对应"); return false; }
		if(vecLine[53]!="g51"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g51]位置不对应"); return false; }
		if(vecLine[54]!="g52"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g52]位置不对应"); return false; }
		if(vecLine[55]!="g53"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g53]位置不对应"); return false; }
		if(vecLine[56]!="g54"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g54]位置不对应"); return false; }
		if(vecLine[57]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc);
			readPos += GameAssist.ReadString( binContent, readPos, out member.group);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g1 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g2 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g3 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g4 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g5 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g6 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g7 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g8 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g9 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g10 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g11 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g12 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g13 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g14 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g15 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g16 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g17 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g18 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g19 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g20 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g21 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g22 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g23 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g24 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g25 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g26 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g27 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g28 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g29 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g30 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g31 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g32 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g33 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g34 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g35 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g36 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g37 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g38 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g39 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g40 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g41 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g42 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g43 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g44 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g45 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g46 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g47 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g48 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g49 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g50 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g51 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g52 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g53 );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.g54 );
			readPos += GameAssist.ReadString( binContent, readPos, out member.allgroup);

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
		if(vecLine.Count != 58)
		{
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="desc"){Ex.Logger.Log("BuffConflictConfig.csv中字段[desc]位置不对应"); return false; }
		if(vecLine[2]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[3]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[4]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[5]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[6]!="g4"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[7]!="g5"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[8]!="g6"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[9]!="g7"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g7]位置不对应"); return false; }
		if(vecLine[10]!="g8"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g8]位置不对应"); return false; }
		if(vecLine[11]!="g9"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g9]位置不对应"); return false; }
		if(vecLine[12]!="g10"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g10]位置不对应"); return false; }
		if(vecLine[13]!="g11"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g11]位置不对应"); return false; }
		if(vecLine[14]!="g12"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g12]位置不对应"); return false; }
		if(vecLine[15]!="g13"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g13]位置不对应"); return false; }
		if(vecLine[16]!="g14"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g14]位置不对应"); return false; }
		if(vecLine[17]!="g15"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g15]位置不对应"); return false; }
		if(vecLine[18]!="g16"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g16]位置不对应"); return false; }
		if(vecLine[19]!="g17"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g17]位置不对应"); return false; }
		if(vecLine[20]!="g18"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g18]位置不对应"); return false; }
		if(vecLine[21]!="g19"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g19]位置不对应"); return false; }
		if(vecLine[22]!="g20"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g20]位置不对应"); return false; }
		if(vecLine[23]!="g21"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g21]位置不对应"); return false; }
		if(vecLine[24]!="g22"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g22]位置不对应"); return false; }
		if(vecLine[25]!="g23"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g23]位置不对应"); return false; }
		if(vecLine[26]!="g24"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g24]位置不对应"); return false; }
		if(vecLine[27]!="g25"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g25]位置不对应"); return false; }
		if(vecLine[28]!="g26"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g26]位置不对应"); return false; }
		if(vecLine[29]!="g27"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g27]位置不对应"); return false; }
		if(vecLine[30]!="g28"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g28]位置不对应"); return false; }
		if(vecLine[31]!="g29"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g29]位置不对应"); return false; }
		if(vecLine[32]!="g30"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g30]位置不对应"); return false; }
		if(vecLine[33]!="g31"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g31]位置不对应"); return false; }
		if(vecLine[34]!="g32"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g32]位置不对应"); return false; }
		if(vecLine[35]!="g33"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g33]位置不对应"); return false; }
		if(vecLine[36]!="g34"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g34]位置不对应"); return false; }
		if(vecLine[37]!="g35"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g35]位置不对应"); return false; }
		if(vecLine[38]!="g36"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g36]位置不对应"); return false; }
		if(vecLine[39]!="g37"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g37]位置不对应"); return false; }
		if(vecLine[40]!="g38"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g38]位置不对应"); return false; }
		if(vecLine[41]!="g39"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g39]位置不对应"); return false; }
		if(vecLine[42]!="g40"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g40]位置不对应"); return false; }
		if(vecLine[43]!="g41"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g41]位置不对应"); return false; }
		if(vecLine[44]!="g42"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g42]位置不对应"); return false; }
		if(vecLine[45]!="g43"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g43]位置不对应"); return false; }
		if(vecLine[46]!="g44"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g44]位置不对应"); return false; }
		if(vecLine[47]!="g45"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g45]位置不对应"); return false; }
		if(vecLine[48]!="g46"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g46]位置不对应"); return false; }
		if(vecLine[49]!="g47"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g47]位置不对应"); return false; }
		if(vecLine[50]!="g48"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g48]位置不对应"); return false; }
		if(vecLine[51]!="g49"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g49]位置不对应"); return false; }
		if(vecLine[52]!="g50"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g50]位置不对应"); return false; }
		if(vecLine[53]!="g51"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g51]位置不对应"); return false; }
		if(vecLine[54]!="g52"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g52]位置不对应"); return false; }
		if(vecLine[55]!="g53"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g53]位置不对应"); return false; }
		if(vecLine[56]!="g54"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g54]位置不对应"); return false; }
		if(vecLine[57]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)58)
			{
				return false;
			}
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.desc=vecLine[1];
			member.group=vecLine[2];
			member.g1=Convert.ToInt32(vecLine[3]);
			member.g2=Convert.ToInt32(vecLine[4]);
			member.g3=Convert.ToInt32(vecLine[5]);
			member.g4=Convert.ToInt32(vecLine[6]);
			member.g5=Convert.ToInt32(vecLine[7]);
			member.g6=Convert.ToInt32(vecLine[8]);
			member.g7=Convert.ToInt32(vecLine[9]);
			member.g8=Convert.ToInt32(vecLine[10]);
			member.g9=Convert.ToInt32(vecLine[11]);
			member.g10=Convert.ToInt32(vecLine[12]);
			member.g11=Convert.ToInt32(vecLine[13]);
			member.g12=Convert.ToInt32(vecLine[14]);
			member.g13=Convert.ToInt32(vecLine[15]);
			member.g14=Convert.ToInt32(vecLine[16]);
			member.g15=Convert.ToInt32(vecLine[17]);
			member.g16=Convert.ToInt32(vecLine[18]);
			member.g17=Convert.ToInt32(vecLine[19]);
			member.g18=Convert.ToInt32(vecLine[20]);
			member.g19=Convert.ToInt32(vecLine[21]);
			member.g20=Convert.ToInt32(vecLine[22]);
			member.g21=Convert.ToInt32(vecLine[23]);
			member.g22=Convert.ToInt32(vecLine[24]);
			member.g23=Convert.ToInt32(vecLine[25]);
			member.g24=Convert.ToInt32(vecLine[26]);
			member.g25=Convert.ToInt32(vecLine[27]);
			member.g26=Convert.ToInt32(vecLine[28]);
			member.g27=Convert.ToInt32(vecLine[29]);
			member.g28=Convert.ToInt32(vecLine[30]);
			member.g29=Convert.ToInt32(vecLine[31]);
			member.g30=Convert.ToInt32(vecLine[32]);
			member.g31=Convert.ToInt32(vecLine[33]);
			member.g32=Convert.ToInt32(vecLine[34]);
			member.g33=Convert.ToInt32(vecLine[35]);
			member.g34=Convert.ToInt32(vecLine[36]);
			member.g35=Convert.ToInt32(vecLine[37]);
			member.g36=Convert.ToInt32(vecLine[38]);
			member.g37=Convert.ToInt32(vecLine[39]);
			member.g38=Convert.ToInt32(vecLine[40]);
			member.g39=Convert.ToInt32(vecLine[41]);
			member.g40=Convert.ToInt32(vecLine[42]);
			member.g41=Convert.ToInt32(vecLine[43]);
			member.g42=Convert.ToInt32(vecLine[44]);
			member.g43=Convert.ToInt32(vecLine[45]);
			member.g44=Convert.ToInt32(vecLine[46]);
			member.g45=Convert.ToInt32(vecLine[47]);
			member.g46=Convert.ToInt32(vecLine[48]);
			member.g47=Convert.ToInt32(vecLine[49]);
			member.g48=Convert.ToInt32(vecLine[50]);
			member.g49=Convert.ToInt32(vecLine[51]);
			member.g50=Convert.ToInt32(vecLine[52]);
			member.g51=Convert.ToInt32(vecLine[53]);
			member.g52=Convert.ToInt32(vecLine[54]);
			member.g53=Convert.ToInt32(vecLine[55]);
			member.g54=Convert.ToInt32(vecLine[56]);
			member.allgroup=vecLine[57];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
