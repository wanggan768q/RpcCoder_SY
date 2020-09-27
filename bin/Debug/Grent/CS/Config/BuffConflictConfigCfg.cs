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
	public string group;         	//组标识	1=冲抵, 2=免疫, 3=共存
	public int g1;               	//驱散	驱散
	public int g2;               	//净化	净化
	public int g3;               	//嘲讽	嘲讽
	public int g4;               	//嘲讽	嘲讽
	public int g5;               	//可驱散晕眩	可驱散晕眩
	public int g6;               	//可驱散冰冻	可驱散冰冻
	public int g7;               	//可驱散沉默	可驱散沉默
	public int g8;               	//可驱散加速	可驱散加速
	public int g9;               	//可驱散减速	可驱散减速
	public int g10;              	//可驱散定身	可驱散定身
	public int g11;              	//可驱散吸血	可驱散吸血
	public int g12;              	//可驱散增加属性Buff	可驱散增加属性Buff
	public int g13;              	//可驱散减少属性Buff	可驱散减少属性Buff
	public int g14;              	//可驱散回血	可驱散回血
	public int g15;              	//可驱散吸收盾	可驱散吸收盾
	public int g16;              	//可驱散流血	可驱散扣血
	public int g17;              	//可驱散中毒	可驱散中毒
	public int g18;              	//可驱散灼烧	可驱散灼烧
	public int g19;              	//可驱散禁疗	可驱散禁疗
	public int g20;              	//Boss霸体	Boss霸体
	public int g21;              	//精英霸体	精英霸体
	public int g22;              	//精英可被打断（免击退）	精英可被打断（免击退）
	public int g23;              	//免疫	免疫
	public int g24;              	//无敌	无敌
	public int g25;              	//诅咒	诅咒
	public int g26;              	//免疫嘲讽	免疫嘲讽
	public int g27;              	//主角职业被动Buff1	主角职业被动Buff1
	public int g28;              	//主角职业被动Buff2	主角职业被动Buff2
	public int g29;              	//主角职业被动Buff3	主角职业被动Buff3
	public int g30;              	//弓手雷电祝福	弓手雷电祝福
	public int g31;              	//弓手自然祝福	弓手自然祝福
	public int g32;              	//弓手寒冰祝福	弓手寒冰祝福
	public int g33;              	//弓手飓风祝福	弓手飓风祝福
	public int g34;              	//幽灵狼消耗祝福	幽灵狼消耗祝福
	public int g35;              	//临时霸体	临时霸体
	public int g36;              	//临时击飞、拉拽	临时击飞、拉拽
	public int g37;              	//击退	击退
	public int g38;              	//不可驱散晕眩	不可驱散晕眩
	public int g39;              	//不可驱散冰冻	不可驱散冰冻
	public int g40;              	//不可驱散沉默	不可驱散沉默
	public int g41;              	//不可驱散加速	不可驱散加速
	public int g42;              	//不可驱散减速	不可驱散减速
	public int g43;              	//不可驱散定身	不可驱散定身
	public int g44;              	//不可驱散吸血	不可驱散吸血
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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[2]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[3]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[4]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[5]!="g4"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[6]!="g5"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[7]!="g6"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[8]!="g7"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g7]位置不对应"); return false; }
		if(vecLine[9]!="g8"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g8]位置不对应"); return false; }
		if(vecLine[10]!="g9"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g9]位置不对应"); return false; }
		if(vecLine[11]!="g10"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g10]位置不对应"); return false; }
		if(vecLine[12]!="g11"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g11]位置不对应"); return false; }
		if(vecLine[13]!="g12"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g12]位置不对应"); return false; }
		if(vecLine[14]!="g13"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g13]位置不对应"); return false; }
		if(vecLine[15]!="g14"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g14]位置不对应"); return false; }
		if(vecLine[16]!="g15"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g15]位置不对应"); return false; }
		if(vecLine[17]!="g16"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g16]位置不对应"); return false; }
		if(vecLine[18]!="g17"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g17]位置不对应"); return false; }
		if(vecLine[19]!="g18"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g18]位置不对应"); return false; }
		if(vecLine[20]!="g19"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g19]位置不对应"); return false; }
		if(vecLine[21]!="g20"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g20]位置不对应"); return false; }
		if(vecLine[22]!="g21"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g21]位置不对应"); return false; }
		if(vecLine[23]!="g22"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g22]位置不对应"); return false; }
		if(vecLine[24]!="g23"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g23]位置不对应"); return false; }
		if(vecLine[25]!="g24"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g24]位置不对应"); return false; }
		if(vecLine[26]!="g25"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g25]位置不对应"); return false; }
		if(vecLine[27]!="g26"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g26]位置不对应"); return false; }
		if(vecLine[28]!="g27"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g27]位置不对应"); return false; }
		if(vecLine[29]!="g28"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g28]位置不对应"); return false; }
		if(vecLine[30]!="g29"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g29]位置不对应"); return false; }
		if(vecLine[31]!="g30"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g30]位置不对应"); return false; }
		if(vecLine[32]!="g31"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g31]位置不对应"); return false; }
		if(vecLine[33]!="g32"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g32]位置不对应"); return false; }
		if(vecLine[34]!="g33"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g33]位置不对应"); return false; }
		if(vecLine[35]!="g34"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g34]位置不对应"); return false; }
		if(vecLine[36]!="g35"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g35]位置不对应"); return false; }
		if(vecLine[37]!="g36"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g36]位置不对应"); return false; }
		if(vecLine[38]!="g37"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g37]位置不对应"); return false; }
		if(vecLine[39]!="g38"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g38]位置不对应"); return false; }
		if(vecLine[40]!="g39"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g39]位置不对应"); return false; }
		if(vecLine[41]!="g40"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g40]位置不对应"); return false; }
		if(vecLine[42]!="g41"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g41]位置不对应"); return false; }
		if(vecLine[43]!="g42"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g42]位置不对应"); return false; }
		if(vecLine[44]!="g43"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g43]位置不对应"); return false; }
		if(vecLine[45]!="g44"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g44]位置不对应"); return false; }
		if(vecLine[46]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
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
		if(vecLine.Count != 47)
		{
			Ex.Logger.Log("BuffConflictConfig.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("BuffConflictConfig.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="group"){Ex.Logger.Log("BuffConflictConfig.csv中字段[group]位置不对应"); return false; }
		if(vecLine[2]!="g1"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g1]位置不对应"); return false; }
		if(vecLine[3]!="g2"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g2]位置不对应"); return false; }
		if(vecLine[4]!="g3"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g3]位置不对应"); return false; }
		if(vecLine[5]!="g4"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g4]位置不对应"); return false; }
		if(vecLine[6]!="g5"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g5]位置不对应"); return false; }
		if(vecLine[7]!="g6"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g6]位置不对应"); return false; }
		if(vecLine[8]!="g7"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g7]位置不对应"); return false; }
		if(vecLine[9]!="g8"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g8]位置不对应"); return false; }
		if(vecLine[10]!="g9"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g9]位置不对应"); return false; }
		if(vecLine[11]!="g10"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g10]位置不对应"); return false; }
		if(vecLine[12]!="g11"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g11]位置不对应"); return false; }
		if(vecLine[13]!="g12"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g12]位置不对应"); return false; }
		if(vecLine[14]!="g13"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g13]位置不对应"); return false; }
		if(vecLine[15]!="g14"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g14]位置不对应"); return false; }
		if(vecLine[16]!="g15"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g15]位置不对应"); return false; }
		if(vecLine[17]!="g16"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g16]位置不对应"); return false; }
		if(vecLine[18]!="g17"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g17]位置不对应"); return false; }
		if(vecLine[19]!="g18"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g18]位置不对应"); return false; }
		if(vecLine[20]!="g19"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g19]位置不对应"); return false; }
		if(vecLine[21]!="g20"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g20]位置不对应"); return false; }
		if(vecLine[22]!="g21"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g21]位置不对应"); return false; }
		if(vecLine[23]!="g22"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g22]位置不对应"); return false; }
		if(vecLine[24]!="g23"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g23]位置不对应"); return false; }
		if(vecLine[25]!="g24"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g24]位置不对应"); return false; }
		if(vecLine[26]!="g25"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g25]位置不对应"); return false; }
		if(vecLine[27]!="g26"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g26]位置不对应"); return false; }
		if(vecLine[28]!="g27"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g27]位置不对应"); return false; }
		if(vecLine[29]!="g28"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g28]位置不对应"); return false; }
		if(vecLine[30]!="g29"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g29]位置不对应"); return false; }
		if(vecLine[31]!="g30"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g30]位置不对应"); return false; }
		if(vecLine[32]!="g31"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g31]位置不对应"); return false; }
		if(vecLine[33]!="g32"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g32]位置不对应"); return false; }
		if(vecLine[34]!="g33"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g33]位置不对应"); return false; }
		if(vecLine[35]!="g34"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g34]位置不对应"); return false; }
		if(vecLine[36]!="g35"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g35]位置不对应"); return false; }
		if(vecLine[37]!="g36"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g36]位置不对应"); return false; }
		if(vecLine[38]!="g37"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g37]位置不对应"); return false; }
		if(vecLine[39]!="g38"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g38]位置不对应"); return false; }
		if(vecLine[40]!="g39"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g39]位置不对应"); return false; }
		if(vecLine[41]!="g40"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g40]位置不对应"); return false; }
		if(vecLine[42]!="g41"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g41]位置不对应"); return false; }
		if(vecLine[43]!="g42"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g42]位置不对应"); return false; }
		if(vecLine[44]!="g43"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g43]位置不对应"); return false; }
		if(vecLine[45]!="g44"){Ex.Logger.Log("BuffConflictConfig.csv中字段[g44]位置不对应"); return false; }
		if(vecLine[46]!="allgroup"){Ex.Logger.Log("BuffConflictConfig.csv中字段[allgroup]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)47)
			{
				return false;
			}
			BuffConflictConfigElement member = new BuffConflictConfigElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.group=vecLine[1];
			member.g1=Convert.ToInt32(vecLine[2]);
			member.g2=Convert.ToInt32(vecLine[3]);
			member.g3=Convert.ToInt32(vecLine[4]);
			member.g4=Convert.ToInt32(vecLine[5]);
			member.g5=Convert.ToInt32(vecLine[6]);
			member.g6=Convert.ToInt32(vecLine[7]);
			member.g7=Convert.ToInt32(vecLine[8]);
			member.g8=Convert.ToInt32(vecLine[9]);
			member.g9=Convert.ToInt32(vecLine[10]);
			member.g10=Convert.ToInt32(vecLine[11]);
			member.g11=Convert.ToInt32(vecLine[12]);
			member.g12=Convert.ToInt32(vecLine[13]);
			member.g13=Convert.ToInt32(vecLine[14]);
			member.g14=Convert.ToInt32(vecLine[15]);
			member.g15=Convert.ToInt32(vecLine[16]);
			member.g16=Convert.ToInt32(vecLine[17]);
			member.g17=Convert.ToInt32(vecLine[18]);
			member.g18=Convert.ToInt32(vecLine[19]);
			member.g19=Convert.ToInt32(vecLine[20]);
			member.g20=Convert.ToInt32(vecLine[21]);
			member.g21=Convert.ToInt32(vecLine[22]);
			member.g22=Convert.ToInt32(vecLine[23]);
			member.g23=Convert.ToInt32(vecLine[24]);
			member.g24=Convert.ToInt32(vecLine[25]);
			member.g25=Convert.ToInt32(vecLine[26]);
			member.g26=Convert.ToInt32(vecLine[27]);
			member.g27=Convert.ToInt32(vecLine[28]);
			member.g28=Convert.ToInt32(vecLine[29]);
			member.g29=Convert.ToInt32(vecLine[30]);
			member.g30=Convert.ToInt32(vecLine[31]);
			member.g31=Convert.ToInt32(vecLine[32]);
			member.g32=Convert.ToInt32(vecLine[33]);
			member.g33=Convert.ToInt32(vecLine[34]);
			member.g34=Convert.ToInt32(vecLine[35]);
			member.g35=Convert.ToInt32(vecLine[36]);
			member.g36=Convert.ToInt32(vecLine[37]);
			member.g37=Convert.ToInt32(vecLine[38]);
			member.g38=Convert.ToInt32(vecLine[39]);
			member.g39=Convert.ToInt32(vecLine[40]);
			member.g40=Convert.ToInt32(vecLine[41]);
			member.g41=Convert.ToInt32(vecLine[42]);
			member.g42=Convert.ToInt32(vecLine[43]);
			member.g43=Convert.ToInt32(vecLine[44]);
			member.g44=Convert.ToInt32(vecLine[45]);
			member.allgroup=vecLine[46];

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
