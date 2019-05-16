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
	public string descPars;      	//参数说明	仅说明
	public string desc_type;     	//Buff效果	仅程序用
	public string comment;       	//备注	仅策划用
	public int oper;             	//Buff关系	0=叠加 1=冲抵 2=免疫 3=共存
	public int operPars;         	//关系参数	若叠加类=最大叠加次数（最小层数是1）
	public int overTimed;        	//是否持续Buff	0=不走buff组关系，直接上 1=需要先判断buff组关系
	public int continuance;      	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算 持续：-1，永久
	public int interval;         	//间隔时间ms	间隔时间
	public int mutexID;          	//Buff组ID	-1表示跟谁都不是一组的
	public string buffEffect;    	//buff特效	buff特效名称
	public int buffMount;        	//buff特效挂载点	所有部位数字0-20
	public string buffendEffect; 	//buff消失特效	buff消失特效名称
	public int buffendMount;     	//buff消失特效挂载点	所有部位数字0-20
	public int groupPriority;    	//组中优先级	0为最低
	public lf pars;              	//参数	具体参数说明见文档《BUFF系统》
	public li pars_2;            	//参数_2	可触发Buff的Buff类型ID
	public int isDebuff;         	//是否减益	1：减益debuff 0：增益buff
	public int buff_delete;      	//buff删除时机	0：不删除 1：下线删除 2：场景删除 3=下线或切场景删除 4：死亡删除 7=下线、场景和死亡均删除
	public int displayPriority;  	//buff显示优先级	填写>=0整数，用于图标、特效等显示优先级，数字越大优先级越高
	public int buffNameId;       	//buff名称ID	对应stringBuff表中的文本ID
	public int specialBuffNameId;	//计时buff简述特殊名称ID	对应stringBuff表中的文本ID
	public int descId;           	//buff描述ID	对应stringBuff表中的文本ID
	public string iconName;      	//图标名称	图标名称
	public int is_tell_client;   	//是否告知客户端	0：否 1：是
	public int buff_show_rule;   	//buff显示规则	0：全部不显示 1：闲置 2：显示图标 4：显示计时条 8：自然使专用BUFF 16：显示冒字 如：14=图标、计时条、自然使专用buff均显示
	public string script;        	//脚本路径	脚本路径
	public int is_show_icon;     	//是否显示buff图标	0：不显示 1：显示 默认为不显示
	public int isShowSpecialBuff;	//特殊buff计时条显示与否	1：显示 0：不显示
	public int jump_delete;      	//跳场景时是否删除	0=不是 1=是

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
		if(vecLine.Count != 31)
		{
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="descPars"){Ex.Logger.Log("Buff.csv中字段[descPars]位置不对应"); return false; }
		if(vecLine[3]!="desc_type"){Ex.Logger.Log("Buff.csv中字段[desc_type]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("Buff.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[5]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[6]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[7]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[8]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[9]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[10]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[11]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[12]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[13]!="buffendEffect"){Ex.Logger.Log("Buff.csv中字段[buffendEffect]位置不对应"); return false; }
		if(vecLine[14]!="buffendMount"){Ex.Logger.Log("Buff.csv中字段[buffendMount]位置不对应"); return false; }
		if(vecLine[15]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[16]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[17]!="pars_2"){Ex.Logger.Log("Buff.csv中字段[pars_2]位置不对应"); return false; }
		if(vecLine[18]!="isDebuff"){Ex.Logger.Log("Buff.csv中字段[isDebuff]位置不对应"); return false; }
		if(vecLine[19]!="buff_delete"){Ex.Logger.Log("Buff.csv中字段[buff_delete]位置不对应"); return false; }
		if(vecLine[20]!="displayPriority"){Ex.Logger.Log("Buff.csv中字段[displayPriority]位置不对应"); return false; }
		if(vecLine[21]!="buffNameId"){Ex.Logger.Log("Buff.csv中字段[buffNameId]位置不对应"); return false; }
		if(vecLine[22]!="specialBuffNameId"){Ex.Logger.Log("Buff.csv中字段[specialBuffNameId]位置不对应"); return false; }
		if(vecLine[23]!="descId"){Ex.Logger.Log("Buff.csv中字段[descId]位置不对应"); return false; }
		if(vecLine[24]!="iconName"){Ex.Logger.Log("Buff.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[25]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }
		if(vecLine[26]!="buff_show_rule"){Ex.Logger.Log("Buff.csv中字段[buff_show_rule]位置不对应"); return false; }
		if(vecLine[27]!="script"){Ex.Logger.Log("Buff.csv中字段[script]位置不对应"); return false; }
		if(vecLine[28]!="is_show_icon"){Ex.Logger.Log("Buff.csv中字段[is_show_icon]位置不对应"); return false; }
		if(vecLine[29]!="isShowSpecialBuff"){Ex.Logger.Log("Buff.csv中字段[isShowSpecialBuff]位置不对应"); return false; }
		if(vecLine[30]!="jump_delete"){Ex.Logger.Log("Buff.csv中字段[jump_delete]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffElement member = new BuffElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.descPars);
			readPos += GameAssist.ReadString( binContent, readPos, out member.desc_type);
			readPos += GameAssist.ReadString( binContent, readPos, out member.comment);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.oper );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.operPars );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.overTimed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mutexID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffMount );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffendEffect);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffendMount );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.groupPriority );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars_2);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.isDebuff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_delete );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.displayPriority );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffNameId );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.specialBuffNameId );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.descId );
			readPos += GameAssist.ReadString( binContent, readPos, out member.iconName);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_tell_client );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_show_rule );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_show_icon );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.isShowSpecialBuff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.jump_delete );

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
		if(vecLine.Count != 31)
		{
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="descPars"){Ex.Logger.Log("Buff.csv中字段[descPars]位置不对应"); return false; }
		if(vecLine[3]!="desc_type"){Ex.Logger.Log("Buff.csv中字段[desc_type]位置不对应"); return false; }
		if(vecLine[4]!="comment"){Ex.Logger.Log("Buff.csv中字段[comment]位置不对应"); return false; }
		if(vecLine[5]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[6]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[7]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[8]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[9]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[10]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[11]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[12]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[13]!="buffendEffect"){Ex.Logger.Log("Buff.csv中字段[buffendEffect]位置不对应"); return false; }
		if(vecLine[14]!="buffendMount"){Ex.Logger.Log("Buff.csv中字段[buffendMount]位置不对应"); return false; }
		if(vecLine[15]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[16]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[17]!="pars_2"){Ex.Logger.Log("Buff.csv中字段[pars_2]位置不对应"); return false; }
		if(vecLine[18]!="isDebuff"){Ex.Logger.Log("Buff.csv中字段[isDebuff]位置不对应"); return false; }
		if(vecLine[19]!="buff_delete"){Ex.Logger.Log("Buff.csv中字段[buff_delete]位置不对应"); return false; }
		if(vecLine[20]!="displayPriority"){Ex.Logger.Log("Buff.csv中字段[displayPriority]位置不对应"); return false; }
		if(vecLine[21]!="buffNameId"){Ex.Logger.Log("Buff.csv中字段[buffNameId]位置不对应"); return false; }
		if(vecLine[22]!="specialBuffNameId"){Ex.Logger.Log("Buff.csv中字段[specialBuffNameId]位置不对应"); return false; }
		if(vecLine[23]!="descId"){Ex.Logger.Log("Buff.csv中字段[descId]位置不对应"); return false; }
		if(vecLine[24]!="iconName"){Ex.Logger.Log("Buff.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[25]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }
		if(vecLine[26]!="buff_show_rule"){Ex.Logger.Log("Buff.csv中字段[buff_show_rule]位置不对应"); return false; }
		if(vecLine[27]!="script"){Ex.Logger.Log("Buff.csv中字段[script]位置不对应"); return false; }
		if(vecLine[28]!="is_show_icon"){Ex.Logger.Log("Buff.csv中字段[is_show_icon]位置不对应"); return false; }
		if(vecLine[29]!="isShowSpecialBuff"){Ex.Logger.Log("Buff.csv中字段[isShowSpecialBuff]位置不对应"); return false; }
		if(vecLine[30]!="jump_delete"){Ex.Logger.Log("Buff.csv中字段[jump_delete]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)31)
			{
				return false;
			}
			BuffElement member = new BuffElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.buffID=Convert.ToInt32(vecLine[1]);
			member.descPars=vecLine[2];
			member.desc_type=vecLine[3];
			member.comment=vecLine[4];
			member.oper=Convert.ToInt32(vecLine[5]);
			member.operPars=Convert.ToInt32(vecLine[6]);
			member.overTimed=Convert.ToInt32(vecLine[7]);
			member.continuance=Convert.ToInt32(vecLine[8]);
			member.interval=Convert.ToInt32(vecLine[9]);
			member.mutexID=Convert.ToInt32(vecLine[10]);
			member.buffEffect=vecLine[11];
			member.buffMount=Convert.ToInt32(vecLine[12]);
			member.buffendEffect=vecLine[13];
			member.buffendMount=Convert.ToInt32(vecLine[14]);
			member.groupPriority=Convert.ToInt32(vecLine[15]);
			member.pars=vecLine[16];
			member.pars_2=vecLine[17];
			member.isDebuff=Convert.ToInt32(vecLine[18]);
			member.buff_delete=Convert.ToInt32(vecLine[19]);
			member.displayPriority=Convert.ToInt32(vecLine[20]);
			member.buffNameId=Convert.ToInt32(vecLine[21]);
			member.specialBuffNameId=Convert.ToInt32(vecLine[22]);
			member.descId=Convert.ToInt32(vecLine[23]);
			member.iconName=vecLine[24];
			member.is_tell_client=Convert.ToInt32(vecLine[25]);
			member.buff_show_rule=Convert.ToInt32(vecLine[26]);
			member.script=vecLine[27];
			member.is_show_icon=Convert.ToInt32(vecLine[28]);
			member.isShowSpecialBuff=Convert.ToInt32(vecLine[29]);
			member.jump_delete=Convert.ToInt32(vecLine[30]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
