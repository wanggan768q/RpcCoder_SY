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
	public int on_phase;         	//生效阶段	指buff对应阶段逻辑是否生效，二进制标志位，可拓展，无特殊需求需填全部生效:7 1：buff开始时生效 2：buff每次在间隔时间生效 4：buff结束时生效 如：7 = 1 + 2 + 4，buff从开始到每跳到结束全上一次，
	public int oper;             	//Buff关系	0=叠加 1=冲抵 2=免疫 3=不同caster共存,相同caster叠加 4=不同caster免疫,相同caster叠加
	public int operPars;         	//关系参数	若叠加类=最大叠加次数（最小层数是1）
	public int overTimed;        	//是否持续Buff	0-非持续（BUFF会直接上身，1-持续（会走mutexID字段进行判断），若不需要判断BUFF组关系，在mutexID字段配置-1即可
	public int continuance;      	//持续时间ms	非持续；无效：立即结算 持续；0：公式结算 持续；时间：时间结算 持续：-1，永久
	public int interval;         	//间隔时间ms	间隔时间
	public int mutexID;          	//Buff组ID	-1表示跟谁都不是一组的
	public int subMutexID;       	//副Buff组ID	当buff组ID一致，且组间关系是共存时，新旧buff判断该列的ID一致时，会按照该副buff组ID进行分组，按照优先级决定是否顶替，新buff优先级大于等于旧buff优先级时，才会顶替 平时无特殊需求的buff，该列填写-1
	public ls buffEffect;        	//buff特效	buff特效名称，多个数据用“|”连接，无数据保持空值
	public li follow_rotation;   	//跟随旋转	数据对应buff特效的个数，特效是否跟随玩家旋转，若有多个特效资源，则用“|”连接 -1旋转 0不旋转
	public li buffMount;         	//buff特效挂载点	无数据保持空值，数据数量需要和buff特效个数一致，多个数据用“|”连接 所有部位数字0-20 0：左脚 1：右脚 2：左手 3：右手 4：头 5：胸部受击点 18：世界脚 19：世界胸 20：世界头 99:UI特效专用
	public ls buffEndEffect;     	//buff消失特效	buff消失特效名称，若有多个小时特效，则用“|”串联填写，无数据保持空值
	public li buffEndMount;      	//buff消失特效挂载点	所有部位数字0-20，99位UI特效专用，消失特效的挂点个数需要和buff消失特效数量一致，无数据保持空值
	public li buffEndEffectDuring;	//buff消失特效持续时间	buff消失时播放的特效持续的时间，单位：ms 数据个数需要和消失特效数量一致，无数据保持空值
	public int groupPriority;    	//组中优先级	0为最低
	public lf pars;              	//参数	具体参数说明见文档《BUFF系统》
	public li pars_2;            	//参数_2	特殊buff所需参数，可触发Buff的Buff类型ID
	public ls pars_3;            	//参数_3	特殊buff所需字符串类型参数，具体填写规则见《BUFF系统》
	public int isDebuff;         	//是否减益	1：减益debuff 0：增益buff
	public int buff_delete;      	//buff删除时机	0：不删除 1：下线删除 2：场景删除 4：死亡删除 8：怪回归删除（仅对怪有效）
	public int displayPriority;  	//buff显示优先级	填写>=0整数，用于图标、特效等显示优先级，数字越大优先级越高
	public int buffNameId;       	//buff名称ID	对应stringBuff表中的文本ID
	public int specialBuffNameId;	//计时buff简述特殊名称ID	对应stringBuff表中的文本ID
	public int descId;           	//buff描述ID	对应stringBuff表中的文本ID
	public string iconName;      	//图标名称	图标名称
	public int is_broadcast;     	//是否广播消息	0：否 1：是 是否需要将buff消息进行广播。 有特效需要让所有人看见的话，则填1，否则填0
	public int is_tell_client;   	//是否告知客户端	0：否 1：是 需要显示受到图标、连击点、计时条等客户端需处理内容，则填1，否则填0（只修改属性，可填0）
	public int buff_show_rule;   	//buff显示规则	0：全部不显示 1：闲置 2：显示图标 4：显示计时条（前提是显示图标） 8：自然使专用BUFF 16：显示冒字 32：隐藏图标处时间 如：14=图标、计时条、自然使专用buff均显示
	public string script;        	//脚本路径	脚本路径
	public int performance_buff_id;	//链接技能表现	连接技能表现表，给buff宿主加效果
	public int skill_slot_mod_id;	//技能槽修改技能效果id	填写《SkillValueMod_技能数值成长表》中的ID
	public int is_ignore_res;    	//是否忽略抗性属性计算	1：上buff时，忽略抗性属性计算 0：上buff时，先计算抗性属性 默认填0，当前已有抗性属性：眩晕、冰冻、击飞、定身、净化、驱散、沉默、打断、禁疗
	public int is_visible;       	//是否可以忽略特效数量限制	0=不能 1=忽略数量限制，有就显示
	public int quality;          	//buff品质	爬塔buff选择时用，客户端显示，对应stringui表

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
		if(vecLine.Count != 36)
		{
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="on_phase"){Ex.Logger.Log("Buff.csv中字段[on_phase]位置不对应"); return false; }
		if(vecLine[3]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[4]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[5]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[6]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[7]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[8]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[9]!="subMutexID"){Ex.Logger.Log("Buff.csv中字段[subMutexID]位置不对应"); return false; }
		if(vecLine[10]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[11]!="follow_rotation"){Ex.Logger.Log("Buff.csv中字段[follow_rotation]位置不对应"); return false; }
		if(vecLine[12]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[13]!="buffEndEffect"){Ex.Logger.Log("Buff.csv中字段[buffEndEffect]位置不对应"); return false; }
		if(vecLine[14]!="buffEndMount"){Ex.Logger.Log("Buff.csv中字段[buffEndMount]位置不对应"); return false; }
		if(vecLine[15]!="buffEndEffectDuring"){Ex.Logger.Log("Buff.csv中字段[buffEndEffectDuring]位置不对应"); return false; }
		if(vecLine[16]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[17]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[18]!="pars_2"){Ex.Logger.Log("Buff.csv中字段[pars_2]位置不对应"); return false; }
		if(vecLine[19]!="pars_3"){Ex.Logger.Log("Buff.csv中字段[pars_3]位置不对应"); return false; }
		if(vecLine[20]!="isDebuff"){Ex.Logger.Log("Buff.csv中字段[isDebuff]位置不对应"); return false; }
		if(vecLine[21]!="buff_delete"){Ex.Logger.Log("Buff.csv中字段[buff_delete]位置不对应"); return false; }
		if(vecLine[22]!="displayPriority"){Ex.Logger.Log("Buff.csv中字段[displayPriority]位置不对应"); return false; }
		if(vecLine[23]!="buffNameId"){Ex.Logger.Log("Buff.csv中字段[buffNameId]位置不对应"); return false; }
		if(vecLine[24]!="specialBuffNameId"){Ex.Logger.Log("Buff.csv中字段[specialBuffNameId]位置不对应"); return false; }
		if(vecLine[25]!="descId"){Ex.Logger.Log("Buff.csv中字段[descId]位置不对应"); return false; }
		if(vecLine[26]!="iconName"){Ex.Logger.Log("Buff.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[27]!="is_broadcast"){Ex.Logger.Log("Buff.csv中字段[is_broadcast]位置不对应"); return false; }
		if(vecLine[28]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }
		if(vecLine[29]!="buff_show_rule"){Ex.Logger.Log("Buff.csv中字段[buff_show_rule]位置不对应"); return false; }
		if(vecLine[30]!="script"){Ex.Logger.Log("Buff.csv中字段[script]位置不对应"); return false; }
		if(vecLine[31]!="performance_buff_id"){Ex.Logger.Log("Buff.csv中字段[performance_buff_id]位置不对应"); return false; }
		if(vecLine[32]!="skill_slot_mod_id"){Ex.Logger.Log("Buff.csv中字段[skill_slot_mod_id]位置不对应"); return false; }
		if(vecLine[33]!="is_ignore_res"){Ex.Logger.Log("Buff.csv中字段[is_ignore_res]位置不对应"); return false; }
		if(vecLine[34]!="is_visible"){Ex.Logger.Log("Buff.csv中字段[is_visible]位置不对应"); return false; }
		if(vecLine[35]!="quality"){Ex.Logger.Log("Buff.csv中字段[quality]位置不对应"); return false; }

		for(int i=0; i<nRow; i++)
		{
			BuffElement member = new BuffElement();
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.on_phase );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.oper );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.operPars );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.overTimed );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.continuance );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.interval );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.mutexID );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.subMutexID );
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEffect);
			readPos += GameAssist.ReadString( binContent, readPos, out member.follow_rotation);
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffMount);
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEndEffect);
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEndMount);
			readPos += GameAssist.ReadString( binContent, readPos, out member.buffEndEffectDuring);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.groupPriority );
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars);
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars_2);
			readPos += GameAssist.ReadString( binContent, readPos, out member.pars_3);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.isDebuff );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_delete );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.displayPriority );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buffNameId );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.specialBuffNameId );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.descId );
			readPos += GameAssist.ReadString( binContent, readPos, out member.iconName);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_broadcast );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_tell_client );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.buff_show_rule );
			readPos += GameAssist.ReadString( binContent, readPos, out member.script);
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.performance_buff_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.skill_slot_mod_id );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_ignore_res );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.is_visible );
			readPos += GameAssist.ReadInt32Variant(binContent, readPos, out member.quality );

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
		if(vecLine.Count != 36)
		{
			Ex.Logger.Log("Buff.csv中列数量与生成的代码不匹配!");
			return false;
		}
		if(vecLine[0]!="id"){Ex.Logger.Log("Buff.csv中字段[id]位置不对应"); return false; }
		if(vecLine[1]!="buffID"){Ex.Logger.Log("Buff.csv中字段[buffID]位置不对应"); return false; }
		if(vecLine[2]!="on_phase"){Ex.Logger.Log("Buff.csv中字段[on_phase]位置不对应"); return false; }
		if(vecLine[3]!="oper"){Ex.Logger.Log("Buff.csv中字段[oper]位置不对应"); return false; }
		if(vecLine[4]!="operPars"){Ex.Logger.Log("Buff.csv中字段[operPars]位置不对应"); return false; }
		if(vecLine[5]!="overTimed"){Ex.Logger.Log("Buff.csv中字段[overTimed]位置不对应"); return false; }
		if(vecLine[6]!="continuance"){Ex.Logger.Log("Buff.csv中字段[continuance]位置不对应"); return false; }
		if(vecLine[7]!="interval"){Ex.Logger.Log("Buff.csv中字段[interval]位置不对应"); return false; }
		if(vecLine[8]!="mutexID"){Ex.Logger.Log("Buff.csv中字段[mutexID]位置不对应"); return false; }
		if(vecLine[9]!="subMutexID"){Ex.Logger.Log("Buff.csv中字段[subMutexID]位置不对应"); return false; }
		if(vecLine[10]!="buffEffect"){Ex.Logger.Log("Buff.csv中字段[buffEffect]位置不对应"); return false; }
		if(vecLine[11]!="follow_rotation"){Ex.Logger.Log("Buff.csv中字段[follow_rotation]位置不对应"); return false; }
		if(vecLine[12]!="buffMount"){Ex.Logger.Log("Buff.csv中字段[buffMount]位置不对应"); return false; }
		if(vecLine[13]!="buffEndEffect"){Ex.Logger.Log("Buff.csv中字段[buffEndEffect]位置不对应"); return false; }
		if(vecLine[14]!="buffEndMount"){Ex.Logger.Log("Buff.csv中字段[buffEndMount]位置不对应"); return false; }
		if(vecLine[15]!="buffEndEffectDuring"){Ex.Logger.Log("Buff.csv中字段[buffEndEffectDuring]位置不对应"); return false; }
		if(vecLine[16]!="groupPriority"){Ex.Logger.Log("Buff.csv中字段[groupPriority]位置不对应"); return false; }
		if(vecLine[17]!="pars"){Ex.Logger.Log("Buff.csv中字段[pars]位置不对应"); return false; }
		if(vecLine[18]!="pars_2"){Ex.Logger.Log("Buff.csv中字段[pars_2]位置不对应"); return false; }
		if(vecLine[19]!="pars_3"){Ex.Logger.Log("Buff.csv中字段[pars_3]位置不对应"); return false; }
		if(vecLine[20]!="isDebuff"){Ex.Logger.Log("Buff.csv中字段[isDebuff]位置不对应"); return false; }
		if(vecLine[21]!="buff_delete"){Ex.Logger.Log("Buff.csv中字段[buff_delete]位置不对应"); return false; }
		if(vecLine[22]!="displayPriority"){Ex.Logger.Log("Buff.csv中字段[displayPriority]位置不对应"); return false; }
		if(vecLine[23]!="buffNameId"){Ex.Logger.Log("Buff.csv中字段[buffNameId]位置不对应"); return false; }
		if(vecLine[24]!="specialBuffNameId"){Ex.Logger.Log("Buff.csv中字段[specialBuffNameId]位置不对应"); return false; }
		if(vecLine[25]!="descId"){Ex.Logger.Log("Buff.csv中字段[descId]位置不对应"); return false; }
		if(vecLine[26]!="iconName"){Ex.Logger.Log("Buff.csv中字段[iconName]位置不对应"); return false; }
		if(vecLine[27]!="is_broadcast"){Ex.Logger.Log("Buff.csv中字段[is_broadcast]位置不对应"); return false; }
		if(vecLine[28]!="is_tell_client"){Ex.Logger.Log("Buff.csv中字段[is_tell_client]位置不对应"); return false; }
		if(vecLine[29]!="buff_show_rule"){Ex.Logger.Log("Buff.csv中字段[buff_show_rule]位置不对应"); return false; }
		if(vecLine[30]!="script"){Ex.Logger.Log("Buff.csv中字段[script]位置不对应"); return false; }
		if(vecLine[31]!="performance_buff_id"){Ex.Logger.Log("Buff.csv中字段[performance_buff_id]位置不对应"); return false; }
		if(vecLine[32]!="skill_slot_mod_id"){Ex.Logger.Log("Buff.csv中字段[skill_slot_mod_id]位置不对应"); return false; }
		if(vecLine[33]!="is_ignore_res"){Ex.Logger.Log("Buff.csv中字段[is_ignore_res]位置不对应"); return false; }
		if(vecLine[34]!="is_visible"){Ex.Logger.Log("Buff.csv中字段[is_visible]位置不对应"); return false; }
		if(vecLine[35]!="quality"){Ex.Logger.Log("Buff.csv中字段[quality]位置不对应"); return false; }

		while(true)
		{
			vecLine = GameAssist.readCsvLine( strContent, ref contentOffset );
			if((int)vecLine.Count == 0 )
				break;
			if((int)vecLine.Count != (int)36)
			{
				return false;
			}
			BuffElement member = new BuffElement();
			member.id=Convert.ToInt32(vecLine[0]);
			member.buffID=Convert.ToInt32(vecLine[1]);
			member.on_phase=Convert.ToInt32(vecLine[2]);
			member.oper=Convert.ToInt32(vecLine[3]);
			member.operPars=Convert.ToInt32(vecLine[4]);
			member.overTimed=Convert.ToInt32(vecLine[5]);
			member.continuance=Convert.ToInt32(vecLine[6]);
			member.interval=Convert.ToInt32(vecLine[7]);
			member.mutexID=Convert.ToInt32(vecLine[8]);
			member.subMutexID=Convert.ToInt32(vecLine[9]);
			member.buffEffect=vecLine[10];
			member.follow_rotation=vecLine[11];
			member.buffMount=vecLine[12];
			member.buffEndEffect=vecLine[13];
			member.buffEndMount=vecLine[14];
			member.buffEndEffectDuring=vecLine[15];
			member.groupPriority=Convert.ToInt32(vecLine[16]);
			member.pars=vecLine[17];
			member.pars_2=vecLine[18];
			member.pars_3=vecLine[19];
			member.isDebuff=Convert.ToInt32(vecLine[20]);
			member.buff_delete=Convert.ToInt32(vecLine[21]);
			member.displayPriority=Convert.ToInt32(vecLine[22]);
			member.buffNameId=Convert.ToInt32(vecLine[23]);
			member.specialBuffNameId=Convert.ToInt32(vecLine[24]);
			member.descId=Convert.ToInt32(vecLine[25]);
			member.iconName=vecLine[26];
			member.is_broadcast=Convert.ToInt32(vecLine[27]);
			member.is_tell_client=Convert.ToInt32(vecLine[28]);
			member.buff_show_rule=Convert.ToInt32(vecLine[29]);
			member.script=vecLine[30];
			member.performance_buff_id=Convert.ToInt32(vecLine[31]);
			member.skill_slot_mod_id=Convert.ToInt32(vecLine[32]);
			member.is_ignore_res=Convert.ToInt32(vecLine[33]);
			member.is_visible=Convert.ToInt32(vecLine[34]);
			member.quality=Convert.ToInt32(vecLine[35]);

			member.IsValidate = true;
			m_vecAllElements.Add(member);
			m_mapElements[member.id] = member;
		}
		return true;
	}
};
