/************************************************************
Copyright (C), 2011-2015, AGAN Tech. Co., Ltd.
FileName:	 ModuleBaseAttr.cs
Author:
Description:
Version:	  1.0
History:
  <author>  <time>   <version >   <desc>

***********************************************************/
using UnityEngine;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


public class BaseAttrRPC
{
	public const int ModuleId = 7;
	
	public const int RPC_CODE_BASEATTR_SYNCDATA_REQUEST = 751;
	public const int RPC_CODE_BASEATTR_SYNC_NOTIFY = 752;

	
	private static BaseAttrRPC m_Instance = null;
	public static BaseAttrRPC Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrRPC();
			}
			return m_Instance;
		}
	}
	
	/**
	 *模块初始化 
	 */ 
	public bool initialize()
	{
		Singleton<GameSocket>.Instance.RegisterSyncUpdate( ModuleId, BaseAttrData.Instance.UpdateField );
		
		Singleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_BASEATTR_SYNC_NOTIFY, SyncCB);


		return true;
	}


	/**
	*基础数据-->同步玩家数据 RPC请求
	*/
	public void SyncData(ReplyHandler replyCB)
	{
		BaseAttrRpcSyncDataAskWraper askPBWraper = new BaseAttrRpcSyncDataAskWraper();
		ModMessage askMsg = new ModMessage();
		askMsg.MsgNum = RPC_CODE_BASEATTR_SYNCDATA_REQUEST;
		askMsg.protoMS = askPBWraper.ToMemoryStream();

		Singleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){
			BaseAttrRpcSyncDataReplyWraper replyPBWraper = new BaseAttrRpcSyncDataReplyWraper();
			replyPBWraper.FromMemoryStream(replyMsg.protoMS);
			replyCB(replyPBWraper);
		});
	}


	/**
	*基础数据-->数据推送 服务器通知回调
	*/
	public static void SyncCB( ModMessage notifyMsg )
	{
		BaseAttrRpcSyncNotifyWraper notifyPBWraper = new BaseAttrRpcSyncNotifyWraper();
		notifyPBWraper.FromMemoryStream(notifyMsg.protoMS);
		if( SyncCBDelegate != null )
			SyncCBDelegate( notifyPBWraper );
	}
	public static ServerNotifyCallback SyncCBDelegate = null;



}

public class BaseAttrData
{
	public enum SyncIdE
	{
 		EXP                                        = 701,  //经验
 		LEVEL                                      = 703,  //玩家等级
 		SERVERTIME                                 = 704,  //服务器时间
 		ROLEID                                     = 705,  //人物唯一ID
 		STRENGTH                                   = 707,  //力量
 		AGILITY                                    = 708,  //敏捷
 		INTELLECTUAL                               = 709,  //智力
 		ENDURANCE                                  = 710,  //耐力
 		HP                                         = 712,  //生命值
 		MAXHP                                      = 714,  //生命值
 		PHYSICATTACK                               = 715,  //物理攻击
 		PHYSICDEFENSE                              = 716,  //物理防御
 		MAGICATTACK                                = 719,  //魔法攻击
 		MAGICDEFENSE                               = 720,  //魔法防御
 		HIT                                        = 721,  //命中值
 		HITRATE                                    = 722,  //命中率
 		MISS                                       = 723,  //闪避值
 		MISSRATE                                   = 724,  //闪避率
 		CRITICAL                                   = 725,  //暴击值
 		CRITICALRATE                               = 726,  //暴击率
 		TENACITY                                   = 727,  //韧性值
 		TENACITYRATE                               = 728,  //韧性率
 		PENET                                      = 729,  //穿透值
 		PENETRATE                                  = 730,  //穿透率
 		DODG                                       = 731,  //格挡值
 		DODGRATE                                   = 732,  //格挡率
 		CRITICALADDITION                           = 733,  //暴击加伤值
 		CRITICALADDITIONRATE                       = 734,  //暴击加伤率
 		CRITICALIMMUNE                             = 735,  //暴击免伤
 		CRITICALIMMUNERATE                         = 736,  //暴击免伤率
 		MISSLEVEL                                  = 737,  //闪避等级
 		CRITICALLEVEL                              = 738,  //暴击等级
 		DODGLEVEL                                  = 739,  //格挡等级
 		MOVESPEED                                  = 740,  //移动速度
 		DIZZYSTATE                                 = 741,  //眩晕状态
 		GODSTATE                                   = 742,  //霸体状态
 		CANTMOVESTATE                              = 743,  //不能移动状态
 		PHYSICADDITION                             = 745,  //物理加伤值
 		MAGICADDITION                              = 746,  //魔法加伤值
 		PHYSICOPPOSE                               = 747,  //物理抗性
 		MAGICOPPOSE                                = 748,  //魔法抗性
 		ACCUMULATESKIENERGY                        = 750,  //技能积攒能量使用 目前只有应激技能用
 		NICKNAME                                   = 751,  //名字昵称
 		CONFIGID                                   = 752,  //config id
 		OBJTYPE                                    = 753,  //类型
 		STATE                                      = 754,  //EventObjStatu
 		OWNEROBJID                                 = 755,  //归属obj ID
 		CAMP                                       = 756,  //阵营
 		SILVERMONEY                                = 757,  //银币
 		GOLDMONEY                                  = 758,  //金币
 		DIAMONDMONEY                               = 759,  //钻石
 		BINDINGDIAMONDMONEY                        = 760,  //绑定钻石
 		BATTLESCORE                                = 761,  //战力
 		ENERGY                                     = 762,  //精力
 		GUILDMONEY                                 = 763,  //公会资金
 		SKILLLIST                                  = 764,  //技能列表
 		HONORMONEY                                 = 765,  //HonorMoney
 		RESOURCEPOOLHP                             = 766,  //资源池
 		ATTACKADD                                  = 767,  //伤害增加
 		INJURYADD                                  = 768,  //伤害减免
 		FROZENSTATE                                = 769,  //冰冻状态
 		SILENTSTATE                                = 770,  //沉默状态
 		GUILDCONTRIBUTEHISTORYMAX                  = 772,  //GuildContributeHistoryMax
 		TEAMID                                     = 774,  //队伍id
 		TREASUREHAIR                               = 775,  //头发时装ID
 		TREASUREHEAD                               = 776,  //头部时装ID
 		TREASUREBODY                               = 777,  //身体时装
 		TREASUREWEAPON                             = 778,  //武器时装
 		TREASUREWING                               = 779,  //翅膀时装
 		GUILDGUID                                  = 780,  //公会ID
 		TREASURERIDING                             = 781,  //坐骑
 		VECHICLEID                                 = 782,  //载具Id
 		ANIMATIONSTATE                             = 783,  //动画状态
 		REFIXDMGRATE                               = 784,  //修正攻击者最终伤害比率
 		REFIXDMGVALUE                              = 785,  //修正攻击者最终伤害值
 		REFIXHURTRATE                              = 786,  //修正被攻击者最终伤害比率
 		REFIXHURTVALUE                             = 787,  //修正被攻击者最终伤害值
 		REFIXHEALRATE                              = 788,  //修正治疗者最终比例
 		REFIXHEALVALUE                             = 789,  //修正治疗者最终值
 		REFIXCUREDRATE                             = 790,  //修正被治疗者最终比例
 		REFIXCUREDVALUE                            = 791,  //修正被治疗者最终值
 		GUILDCONTRIBUTE                            = 792,  //公会帮贡
 		PVPMONEY                                   = 793,  //竞技场点数
 		GUILDRESOURCE                              = 794,  //公会资源
 		CREATEROLETIME                             = 795,  //创建角色时间戳
 		UPDATEROLETIME                             = 796,  //更新角色等级时间戳
 		FIGHTSTATE                                 = 797,  //战斗状态
 		ATTACKSKILLLIST                            = 798,  //普攻技能列表
 		GUILDNAME                                  = 799,  //公会名称
 		ISALLOWSELECT                              = 800,  //是否可选中
 		GOHOMESTATE                                = 801,  //怪物回归中
 		CANFIGHT                                   = 802,  //怪物是否可攻击
 		DOUBLEEXP                                  = 803,  //双倍经验
 		FRIENDPOINT                                = 804,  //友情点
 		HISMAXHONOR                                = 805,  //历史最大荣誉点
 		HURTSTATE                                  = 806,  //受击状态
 		HURTFLYSTATE                               = 807,  //击飞状态
 		HURTDOWNSTATE                              = 808,  //击倒状态
 		HURTREPELSTATE                             = 809,  //击退
 		TODAYHORNOR                                = 811,  //今日获得的荣誉值
 		CURPROFESSION                              = 813,  //当前专精
 		PETCREATEDELCOND                           = 814,  //宠物创建删除条件枚举
 		PETDISPLAY                                 = 815,  //宠物是否需要隐藏1显示0隐藏
 		PETMONEY                                   = 816,  //宠物货币
 		DUELSTATUS                                 = 817,  //决斗状态
 		EXPPOOL                                    = 818,  //经验池
 		RUSHSTATE                                  = 819,  //疾跑状态
 		STARESTATE                                 = 820,  //盯防状态
 		WORLDLEVEL                                 = 821,  //世界等级
 		DIZZYHITRATE                               = 822,  //眩晕命中率
 		DIZZYRESISTRATE                            = 823,  //眩晕抵抗率
 		IMMOVABLEHITRATE                           = 824,  //定身命中率
 		IMMOVABLERESISTRATE                        = 825,  //定身抵抗率
 		HURTFLYHITRATE                             = 826,  //击飞命中率
 		HURTFLYRESISTRATE                          = 827,  //击飞抵抗率
 		FROZENHITRATE                              = 828,  //冰冻命中率
 		FROZENRESISTRATE                           = 829,  //冰冻抵抗率
 		CLEANHITRATE                               = 830,  //净化命中率
 		CLEANRESISTRATE                            = 831,  //净化抵抗率
 		DISPELHITRATE                              = 832,  //驱散命中率
 		DISPELRESISTRATE                           = 833,  //驱散抵抗率
 		SILENCEHITRATE                             = 834,  //沉默命中率
 		SILENCERESISTRATE                          = 835,  //沉默抵抗率
 		INTERRUPTHITRATE                           = 836,  //打断命中率
 		INTERRUPTRESISTRATE                        = 837,  //打断抵抗率
 		UNCURABLEHITRATE                           = 838,  //禁疗命中率
 		UNCURABLERESISTRATE                        = 839,  //禁疗抵抗率
 		TRANSFORM                                  = 840,  //变身
 		HUMANHURTRATE                              = 841,  //受到玩家目标伤害比
 		HUMANSUFFERRATE                            = 842,  //针对玩家目标伤害比
 		MONSTERHURTRATE                            = 843,  //受到怪物目标伤害比
 		MONSTERSUFFERRATE                          = 844,  //针对怪物目标伤害比
 		BOSSHURTRATE                               = 845,  //受到Boss目标伤害比
 		BOSSSUFFERRATE                             = 846,  //针对Boss目标伤害比
 		DODGREDUCEVALUE                            = 847,  //格挡减伤值
 		DODGREDUCERATE                             = 848,  //格挡减伤率
 		DODGADDVALUE                               = 849,  //格挡破伤值
 		DODGADDRATE                                = 850,  //格挡破伤率
 		TREASUREFOOTPRINT                          = 851,  //步尘
 		EQUIPTITLE                                 = 852,  //装备称号
 		OBJANIMEVENT                               = 853,  //当前所在动画事件
 		PINCHDATA                                  = 854,  //捏脸数据
 		SKILLCDRATE                                = 855,  //技能冷缩比例
 		ASPDRATE                                   = 856,  //攻速
 		SHIELD                                     = 857,  //护盾值
 		EVENTLEFTCOUNT                             = 858,  //obj剩余采集次数
 		CANNOTRUSH                                 = 859,  //不能疾跑状态
 		HUNTPOINT                                  = 860,  //猎魔点数
 		HUNTHIGHTIMES                              = 861,  //猎魔高倍
 		HUNTFIREPOINT                              = 862,  //猎魔引燃次数
 		STARBATTLESTATE                            = 863,  //星耀NPC状态(1可进入 2不可进入)
 		IGNOREMOTIONBLOCK                          = 864,  //是否忽略地图阻挡
 		ENABLEINTERACT                             = 865,  //EnableInteract
 		WORLDMEDAL                                 = 866,  //世界奖章
 		CURECEILING                                = 868,  //治疗上限
 		RELATIONUNIONCURRENCY                      = 869,  //圣乐之力
 		GUILDSHORTNAME                             = 870,  //公会简称
 		GUILDSHORTCOLORID                          = 871,  //公会简称颜色ID

	}
	
	private static BaseAttrData m_Instance = null;
	public static BaseAttrData Instance
	{
		get
		{
			if (m_Instance == null) 
			{
				m_Instance = new BaseAttrData();
			}
			return m_Instance;

		}
	}
	

	public void UpdateField(int Id, int Index, byte[] buff, int start, int len )
	{
		SyncIdE SyncId = (SyncIdE)Id;
		byte[]  updateBuffer = new byte[len];
		Array.Copy(buff, start, updateBuffer, 0, len);
		int  iValue = 0;
		long lValue = 0;

		switch (SyncId)
		{
			case SyncIdE.EXP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Exp = lValue;
				break;
			case SyncIdE.LEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Level = lValue;
				break;
			case SyncIdE.SERVERTIME:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ServerTime = lValue;
				break;
			case SyncIdE.ROLEID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RoleId = lValue;
				break;
			case SyncIdE.STRENGTH:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Strength = lValue;
				break;
			case SyncIdE.AGILITY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Agility = lValue;
				break;
			case SyncIdE.INTELLECTUAL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Intellectual = lValue;
				break;
			case SyncIdE.ENDURANCE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Endurance = lValue;
				break;
			case SyncIdE.HP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Hp = lValue;
				break;
			case SyncIdE.MAXHP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MaxHp = lValue;
				break;
			case SyncIdE.PHYSICATTACK:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PhysicAttack = lValue;
				break;
			case SyncIdE.PHYSICDEFENSE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PhysicDefense = lValue;
				break;
			case SyncIdE.MAGICATTACK:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MagicAttack = lValue;
				break;
			case SyncIdE.MAGICDEFENSE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MagicDefense = lValue;
				break;
			case SyncIdE.HIT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Hit = lValue;
				break;
			case SyncIdE.HITRATE:
				m_Instance.HitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MISS:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Miss = lValue;
				break;
			case SyncIdE.MISSRATE:
				m_Instance.MissRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICAL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Critical = lValue;
				break;
			case SyncIdE.CRITICALRATE:
				m_Instance.CriticalRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.TENACITY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Tenacity = lValue;
				break;
			case SyncIdE.TENACITYRATE:
				m_Instance.TenacityRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.PENET:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Penet = lValue;
				break;
			case SyncIdE.PENETRATE:
				m_Instance.PenetRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DODG:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Dodg = lValue;
				break;
			case SyncIdE.DODGRATE:
				m_Instance.DodgRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICALADDITION:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalAddition = lValue;
				break;
			case SyncIdE.CRITICALADDITIONRATE:
				m_Instance.CriticalAdditionRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CRITICALIMMUNE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalImmune = lValue;
				break;
			case SyncIdE.CRITICALIMMUNERATE:
				m_Instance.CriticalImmuneRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MISSLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.MissLevel = lValue;
				break;
			case SyncIdE.CRITICALLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CriticalLevel = lValue;
				break;
			case SyncIdE.DODGLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DodgLevel = lValue;
				break;
			case SyncIdE.MOVESPEED:
				m_Instance.MoveSpeed = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DIZZYSTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DizzyState = lValue;
				break;
			case SyncIdE.GODSTATE:
				m_Instance.GodState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.CANTMOVESTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CantMoveState = lValue;
				break;
			case SyncIdE.PHYSICADDITION:
				m_Instance.PhysicAddition = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MAGICADDITION:
				m_Instance.MagicAddition = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.PHYSICOPPOSE:
				m_Instance.PhysicOppose = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MAGICOPPOSE:
				m_Instance.MagicOppose = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.ACCUMULATESKIENERGY:
				m_Instance.AccumulateSkiEnergy = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.NICKNAME:
				m_Instance.NickName = System.Text.Encoding.UTF8.GetString(updateBuffer);
				break;
			case SyncIdE.CONFIGID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ConfigId = lValue;
				break;
			case SyncIdE.OBJTYPE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ObjType = lValue;
				break;
			case SyncIdE.STATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.State = lValue;
				break;
			case SyncIdE.OWNEROBJID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.OwnerObjId = lValue;
				break;
			case SyncIdE.CAMP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Camp = lValue;
				break;
			case SyncIdE.SILVERMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.SilverMoney = lValue;
				break;
			case SyncIdE.GOLDMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GoldMoney = lValue;
				break;
			case SyncIdE.DIAMONDMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DiamondMoney = lValue;
				break;
			case SyncIdE.BINDINGDIAMONDMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.BindingDiamondMoney = lValue;
				break;
			case SyncIdE.BATTLESCORE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.BattleScore = lValue;
				break;
			case SyncIdE.ENERGY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Energy = lValue;
				break;
			case SyncIdE.GUILDMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildMoney = lValue;
				break;
			case SyncIdE.SKILLLIST:
				if(Index < 0){ m_Instance.ClearSkillList(); break; }
				if (Index >= m_Instance.SizeSkillList())
				{
					int Count = Index - m_Instance.SizeSkillList() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddSkillList(-1);
				}
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.SetSkillList(Index, lValue);
				break;
			case SyncIdE.HONORMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.HonorMoney = lValue;
				break;
			case SyncIdE.RESOURCEPOOLHP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ResourcePoolHp = lValue;
				break;
			case SyncIdE.ATTACKADD:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.AttackAdd = lValue;
				break;
			case SyncIdE.INJURYADD:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.InjuryAdd = lValue;
				break;
			case SyncIdE.FROZENSTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.FrozenState = lValue;
				break;
			case SyncIdE.SILENTSTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.SilentState = lValue;
				break;
			case SyncIdE.GUILDCONTRIBUTEHISTORYMAX:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildContributeHistoryMax = lValue;
				break;
			case SyncIdE.TEAMID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TeamId = lValue;
				break;
			case SyncIdE.TREASUREHAIR:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureHair = lValue;
				break;
			case SyncIdE.TREASUREHEAD:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureHead = lValue;
				break;
			case SyncIdE.TREASUREBODY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureBody = lValue;
				break;
			case SyncIdE.TREASUREWEAPON:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureWeapon = lValue;
				break;
			case SyncIdE.TREASUREWING:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureWing = lValue;
				break;
			case SyncIdE.GUILDGUID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildGuid = lValue;
				break;
			case SyncIdE.TREASURERIDING:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureRiding = lValue;
				break;
			case SyncIdE.VECHICLEID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.VechicleId = lValue;
				break;
			case SyncIdE.ANIMATIONSTATE:
				m_Instance.AnimationState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.REFIXDMGRATE:
				m_Instance.RefixDmgRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.REFIXDMGVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RefixDmgValue = lValue;
				break;
			case SyncIdE.REFIXHURTRATE:
				m_Instance.RefixHurtRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.REFIXHURTVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RefixHurtValue = lValue;
				break;
			case SyncIdE.REFIXHEALRATE:
				m_Instance.RefixHealRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.REFIXHEALVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RefixHealValue = lValue;
				break;
			case SyncIdE.REFIXCUREDRATE:
				m_Instance.RefixCuredRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.REFIXCUREDVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RefixCuredValue = lValue;
				break;
			case SyncIdE.GUILDCONTRIBUTE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildContribute = lValue;
				break;
			case SyncIdE.PVPMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PvpMoney = lValue;
				break;
			case SyncIdE.GUILDRESOURCE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildResource = lValue;
				break;
			case SyncIdE.CREATEROLETIME:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CreateRoleTime = lValue;
				break;
			case SyncIdE.UPDATEROLETIME:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.UpdateRoleTime = lValue;
				break;
			case SyncIdE.FIGHTSTATE:
				m_Instance.FightState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.ATTACKSKILLLIST:
				if(Index < 0){ m_Instance.ClearAttackSkillList(); break; }
				if (Index >= m_Instance.SizeAttackSkillList())
				{
					int Count = Index - m_Instance.SizeAttackSkillList() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddAttackSkillList(-1);
				}
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.SetAttackSkillList(Index, lValue);
				break;
			case SyncIdE.GUILDNAME:
				m_Instance.GuildName = System.Text.Encoding.UTF8.GetString(updateBuffer);
				break;
			case SyncIdE.ISALLOWSELECT:
				m_Instance.IsAllowSelect = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.GOHOMESTATE:
				m_Instance.GoHomeState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.CANFIGHT:
				m_Instance.CanFight = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.DOUBLEEXP:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DoubleExp = lValue;
				break;
			case SyncIdE.FRIENDPOINT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.FriendPoint = lValue;
				break;
			case SyncIdE.HISMAXHONOR:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.HisMaxHonor = lValue;
				break;
			case SyncIdE.HURTSTATE:
				m_Instance.HurtState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.HURTFLYSTATE:
				m_Instance.HurtFlyState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.HURTDOWNSTATE:
				m_Instance.HurtDownState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.HURTREPELSTATE:
				m_Instance.HurtRepelState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.TODAYHORNOR:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TodayHornor = lValue;
				break;
			case SyncIdE.CURPROFESSION:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CurProfession = lValue;
				break;
			case SyncIdE.PETCREATEDELCOND:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PetCreateDelCond = lValue;
				break;
			case SyncIdE.PETDISPLAY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PetDisplay = lValue;
				break;
			case SyncIdE.PETMONEY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.PetMoney = lValue;
				break;
			case SyncIdE.DUELSTATUS:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DuelStatus = lValue;
				break;
			case SyncIdE.EXPPOOL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.ExpPool = lValue;
				break;
			case SyncIdE.RUSHSTATE:
				m_Instance.RushState = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.STARESTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.StareState = lValue;
				break;
			case SyncIdE.WORLDLEVEL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.WorldLevel = lValue;
				break;
			case SyncIdE.DIZZYHITRATE:
				m_Instance.DizzyHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DIZZYRESISTRATE:
				m_Instance.DizzyResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.IMMOVABLEHITRATE:
				m_Instance.ImmovableHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.IMMOVABLERESISTRATE:
				m_Instance.ImmovableResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.HURTFLYHITRATE:
				m_Instance.HurtFlyHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.HURTFLYRESISTRATE:
				m_Instance.HurtFlyResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.FROZENHITRATE:
				m_Instance.FrozenHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.FROZENRESISTRATE:
				m_Instance.FrozenResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CLEANHITRATE:
				m_Instance.CleanHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.CLEANRESISTRATE:
				m_Instance.CleanResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DISPELHITRATE:
				m_Instance.DispelHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DISPELRESISTRATE:
				m_Instance.DispelResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.SILENCEHITRATE:
				m_Instance.SilenceHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.SILENCERESISTRATE:
				m_Instance.SilenceResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.INTERRUPTHITRATE:
				m_Instance.InterruptHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.INTERRUPTRESISTRATE:
				m_Instance.InterruptResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.UNCURABLEHITRATE:
				m_Instance.UncurableHitRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.UNCURABLERESISTRATE:
				m_Instance.UncurableResistRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.TRANSFORM:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Transform = lValue;
				break;
			case SyncIdE.HUMANHURTRATE:
				m_Instance.HumanHurtRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.HUMANSUFFERRATE:
				m_Instance.HumanSufferRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MONSTERHURTRATE:
				m_Instance.MonsterHurtRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.MONSTERSUFFERRATE:
				m_Instance.MonsterSufferRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.BOSSHURTRATE:
				m_Instance.BossHurtRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.BOSSSUFFERRATE:
				m_Instance.BossSufferRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DODGREDUCEVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DodgReduceValue = lValue;
				break;
			case SyncIdE.DODGREDUCERATE:
				m_Instance.DodgReduceRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.DODGADDVALUE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.DodgAddValue = lValue;
				break;
			case SyncIdE.DODGADDRATE:
				m_Instance.DodgAddRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.TREASUREFOOTPRINT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.TreasureFootPrint = lValue;
				break;
			case SyncIdE.EQUIPTITLE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.EquipTitle = lValue;
				break;
			case SyncIdE.OBJANIMEVENT:
				if(Index < 0){ m_Instance.ClearObjAnimEvent(); break; }
				if (Index >= m_Instance.SizeObjAnimEvent())
				{
					int Count = Index - m_Instance.SizeObjAnimEvent() + 1;
					for (int i = 0; i < Count; i++)
						m_Instance.AddObjAnimEvent(-1);
				}
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.SetObjAnimEvent(Index, lValue);
				break;
			case SyncIdE.PINCHDATA:
				m_Instance.PinchData = System.Text.Encoding.UTF8.GetString(updateBuffer);
				break;
			case SyncIdE.SKILLCDRATE:
				m_Instance.SkillCDRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.ASPDRATE:
				m_Instance.AspdRate = BitConverter.ToSingle(updateBuffer,0);
				break;
			case SyncIdE.SHIELD:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Shield = lValue;
				break;
			case SyncIdE.EVENTLEFTCOUNT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.EventLeftCount = lValue;
				break;
			case SyncIdE.CANNOTRUSH:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CanNotRush = lValue;
				break;
			case SyncIdE.HUNTPOINT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.HuntPoint = lValue;
				break;
			case SyncIdE.HUNTHIGHTIMES:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.HuntHighTimes = lValue;
				break;
			case SyncIdE.HUNTFIREPOINT:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.HuntFirePoint = lValue;
				break;
			case SyncIdE.STARBATTLESTATE:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.Starbattlestate = lValue;
				break;
			case SyncIdE.IGNOREMOTIONBLOCK:
				m_Instance.IgnoreMotionBlock = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.ENABLEINTERACT:
				m_Instance.EnableInteract = BitConverter.ToBoolean(updateBuffer,0);
				break;
			case SyncIdE.WORLDMEDAL:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.WorldMedal = lValue;
				break;
			case SyncIdE.CURECEILING:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.CureCeiling = lValue;
				break;
			case SyncIdE.RELATIONUNIONCURRENCY:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.RelationUnionCurrency = lValue;
				break;
			case SyncIdE.GUILDSHORTNAME:
				m_Instance.GuildShortName = System.Text.Encoding.UTF8.GetString(updateBuffer);
				break;
			case SyncIdE.GUILDSHORTCOLORID:
				GameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);
				m_Instance.GuildShortColorID = lValue;
				break;

			default:
				break;
		}

		try
		{
			if (NotifySyncValueChanged!=null)
				NotifySyncValueChanged(Id, Index);
		}
		catch
		{
			Ex.Logger.Log("BaseAttrData.NotifySyncValueChanged catch exception");
		}
		updateBuffer.GetType();
		iValue ++;
		lValue ++;
	}

	public NotifySyncValueChangedCB NotifySyncValueChanged = null;
  

	//构造函数
	public BaseAttrData()
	{
		 m_Exp = 0;
		 m_Level = 0;
		 m_ServerTime = -1;
		 m_RoleId = 0;
		 m_Strength = 0;
		 m_Agility = 0;
		 m_Intellectual = 0;
		 m_Endurance = 0;
		 m_Hp = 0;
		 m_MaxHp = 0;
		 m_PhysicAttack = 0;
		 m_PhysicDefense = 0;
		 m_MagicAttack = 0;
		 m_MagicDefense = 0;
		 m_Hit = 0;
		 m_HitRate = (float)0;
		 m_Miss = 0;
		 m_MissRate = (float)0;
		 m_Critical = 0;
		 m_CriticalRate = (float)0;
		 m_Tenacity = 0;
		 m_TenacityRate = (float)0;
		 m_Penet = 0;
		 m_PenetRate = (float)0;
		 m_Dodg = 0;
		 m_DodgRate = (float)0;
		 m_CriticalAddition = 0;
		 m_CriticalAdditionRate = (float)0;
		 m_CriticalImmune = 0;
		 m_CriticalImmuneRate = (float)0;
		 m_MissLevel = 0;
		 m_CriticalLevel = 0;
		 m_DodgLevel = 0;
		 m_MoveSpeed = (float)0;
		 m_DizzyState = 0;
		 m_GodState = false;
		 m_CantMoveState = 0;
		 m_PhysicAddition = (float)0;
		 m_MagicAddition = (float)0;
		 m_PhysicOppose = (float)0;
		 m_MagicOppose = (float)0;
		 m_AccumulateSkiEnergy = (float)0;
		 m_NickName = "";
		 m_ConfigId = -1;
		 m_ObjType = -1;
		 m_State = -1;
		 m_OwnerObjId = 0;
		 m_Camp = -1;
		 m_SilverMoney = 0;
		 m_GoldMoney = 0;
		 m_DiamondMoney = 0;
		 m_BindingDiamondMoney = 0;
		 m_BattleScore = -1;
		 m_Energy = -1;
		 m_GuildMoney = -1;
		m_SkillList = new List<int>();
		 m_HonorMoney = -1;
		 m_ResourcePoolHp = -1;
		 m_AttackAdd = 0;
		 m_InjuryAdd = 0;
		 m_FrozenState = -1;
		 m_SilentState = -1;
		 m_GuildContributeHistoryMax = -1;
		 m_TeamId = 0;
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_GuildGuid = 0;
		 m_TreasureRiding = -1;
		 m_VechicleId = -1;
		 m_AnimationState = false;
		 m_RefixDmgRate = (float)0;
		 m_RefixDmgValue = 0;
		 m_RefixHurtRate = (float)0;
		 m_RefixHurtValue = 0;
		 m_RefixHealRate = (float)0;
		 m_RefixHealValue = 0;
		 m_RefixCuredRate = (float)0;
		 m_RefixCuredValue = 0;
		 m_GuildContribute = -1;
		 m_PvpMoney = -1;
		 m_GuildResource = -1;
		 m_CreateRoleTime = 0;
		 m_UpdateRoleTime = 0;
		 m_FightState = false;
		m_AttackSkillList = new List<int>();
		 m_GuildName = "";
		 m_IsAllowSelect = true;
		 m_GoHomeState = false;
		 m_CanFight = true;
		 m_DoubleExp = -1;
		 m_FriendPoint = -1;
		 m_HisMaxHonor = -1;
		 m_HurtState = false;
		 m_HurtFlyState = false;
		 m_HurtDownState = false;
		 m_HurtRepelState = false;
		 m_TodayHornor = -1;
		 m_CurProfession = -1;
		 m_PetCreateDelCond = -1;
		 m_PetDisplay = 0;
		 m_PetMoney = -1;
		 m_DuelStatus = 0;
		 m_ExpPool = -1;
		 m_RushState = false;
		 m_StareState = 0;
		 m_WorldLevel = 0;
		 m_DizzyHitRate = (float)0;
		 m_DizzyResistRate = (float)0;
		 m_ImmovableHitRate = (float)0;
		 m_ImmovableResistRate = (float)0;
		 m_HurtFlyHitRate = (float)0;
		 m_HurtFlyResistRate = (float)0;
		 m_FrozenHitRate = (float)0;
		 m_FrozenResistRate = (float)0;
		 m_CleanHitRate = (float)0;
		 m_CleanResistRate = (float)0;
		 m_DispelHitRate = (float)0;
		 m_DispelResistRate = (float)0;
		 m_SilenceHitRate = (float)0;
		 m_SilenceResistRate = (float)0;
		 m_InterruptHitRate = (float)0;
		 m_InterruptResistRate = (float)0;
		 m_UncurableHitRate = (float)0;
		 m_UncurableResistRate = (float)0;
		 m_Transform = -1;
		 m_HumanHurtRate = (float)0;
		 m_HumanSufferRate = (float)0;
		 m_MonsterHurtRate = (float)0;
		 m_MonsterSufferRate = (float)0;
		 m_BossHurtRate = (float)0;
		 m_BossSufferRate = (float)0;
		 m_DodgReduceValue = 0;
		 m_DodgReduceRate = (float)0;
		 m_DodgAddValue = 0;
		 m_DodgAddRate = (float)0;
		 m_TreasureFootPrint = -1;
		 m_EquipTitle = -1;
		m_ObjAnimEvent = new List<int>();
		 m_PinchData = "";
		 m_SkillCDRate = (float)1;
		 m_AspdRate = (float)1;
		 m_Shield = 0;
		 m_EventLeftCount = -1;
		 m_CanNotRush = 0;
		 m_HuntPoint = 0;
		 m_HuntHighTimes = 0;
		 m_HuntFirePoint = 0;
		 m_Starbattlestate = 1;
		 m_IgnoreMotionBlock = false;
		 m_EnableInteract = false;
		 m_WorldMedal = 0;
		 m_CureCeiling = -1;
		 m_RelationUnionCurrency = 0;
		 m_GuildShortName = "";
		 m_GuildShortColorID = -1;

	}

	//重置函数
	public void ResetWraper()
	{
		 m_Exp = 0;
		 m_Level = 0;
		 m_ServerTime = -1;
		 m_RoleId = 0;
		 m_Strength = 0;
		 m_Agility = 0;
		 m_Intellectual = 0;
		 m_Endurance = 0;
		 m_Hp = 0;
		 m_MaxHp = 0;
		 m_PhysicAttack = 0;
		 m_PhysicDefense = 0;
		 m_MagicAttack = 0;
		 m_MagicDefense = 0;
		 m_Hit = 0;
		 m_HitRate = (float)0;
		 m_Miss = 0;
		 m_MissRate = (float)0;
		 m_Critical = 0;
		 m_CriticalRate = (float)0;
		 m_Tenacity = 0;
		 m_TenacityRate = (float)0;
		 m_Penet = 0;
		 m_PenetRate = (float)0;
		 m_Dodg = 0;
		 m_DodgRate = (float)0;
		 m_CriticalAddition = 0;
		 m_CriticalAdditionRate = (float)0;
		 m_CriticalImmune = 0;
		 m_CriticalImmuneRate = (float)0;
		 m_MissLevel = 0;
		 m_CriticalLevel = 0;
		 m_DodgLevel = 0;
		 m_MoveSpeed = (float)0;
		 m_DizzyState = 0;
		 m_GodState = false;
		 m_CantMoveState = 0;
		 m_PhysicAddition = (float)0;
		 m_MagicAddition = (float)0;
		 m_PhysicOppose = (float)0;
		 m_MagicOppose = (float)0;
		 m_AccumulateSkiEnergy = (float)0;
		 m_NickName = "";
		 m_ConfigId = -1;
		 m_ObjType = -1;
		 m_State = -1;
		 m_OwnerObjId = 0;
		 m_Camp = -1;
		 m_SilverMoney = 0;
		 m_GoldMoney = 0;
		 m_DiamondMoney = 0;
		 m_BindingDiamondMoney = 0;
		 m_BattleScore = -1;
		 m_Energy = -1;
		 m_GuildMoney = -1;
		m_SkillList = new List<int>();
		 m_HonorMoney = -1;
		 m_ResourcePoolHp = -1;
		 m_AttackAdd = 0;
		 m_InjuryAdd = 0;
		 m_FrozenState = -1;
		 m_SilentState = -1;
		 m_GuildContributeHistoryMax = -1;
		 m_TeamId = 0;
		 m_TreasureHair = -1;
		 m_TreasureHead = -1;
		 m_TreasureBody = -1;
		 m_TreasureWeapon = -1;
		 m_TreasureWing = -1;
		 m_GuildGuid = 0;
		 m_TreasureRiding = -1;
		 m_VechicleId = -1;
		 m_AnimationState = false;
		 m_RefixDmgRate = (float)0;
		 m_RefixDmgValue = 0;
		 m_RefixHurtRate = (float)0;
		 m_RefixHurtValue = 0;
		 m_RefixHealRate = (float)0;
		 m_RefixHealValue = 0;
		 m_RefixCuredRate = (float)0;
		 m_RefixCuredValue = 0;
		 m_GuildContribute = -1;
		 m_PvpMoney = -1;
		 m_GuildResource = -1;
		 m_CreateRoleTime = 0;
		 m_UpdateRoleTime = 0;
		 m_FightState = false;
		m_AttackSkillList = new List<int>();
		 m_GuildName = "";
		 m_IsAllowSelect = true;
		 m_GoHomeState = false;
		 m_CanFight = true;
		 m_DoubleExp = -1;
		 m_FriendPoint = -1;
		 m_HisMaxHonor = -1;
		 m_HurtState = false;
		 m_HurtFlyState = false;
		 m_HurtDownState = false;
		 m_HurtRepelState = false;
		 m_TodayHornor = -1;
		 m_CurProfession = -1;
		 m_PetCreateDelCond = -1;
		 m_PetDisplay = 0;
		 m_PetMoney = -1;
		 m_DuelStatus = 0;
		 m_ExpPool = -1;
		 m_RushState = false;
		 m_StareState = 0;
		 m_WorldLevel = 0;
		 m_DizzyHitRate = (float)0;
		 m_DizzyResistRate = (float)0;
		 m_ImmovableHitRate = (float)0;
		 m_ImmovableResistRate = (float)0;
		 m_HurtFlyHitRate = (float)0;
		 m_HurtFlyResistRate = (float)0;
		 m_FrozenHitRate = (float)0;
		 m_FrozenResistRate = (float)0;
		 m_CleanHitRate = (float)0;
		 m_CleanResistRate = (float)0;
		 m_DispelHitRate = (float)0;
		 m_DispelResistRate = (float)0;
		 m_SilenceHitRate = (float)0;
		 m_SilenceResistRate = (float)0;
		 m_InterruptHitRate = (float)0;
		 m_InterruptResistRate = (float)0;
		 m_UncurableHitRate = (float)0;
		 m_UncurableResistRate = (float)0;
		 m_Transform = -1;
		 m_HumanHurtRate = (float)0;
		 m_HumanSufferRate = (float)0;
		 m_MonsterHurtRate = (float)0;
		 m_MonsterSufferRate = (float)0;
		 m_BossHurtRate = (float)0;
		 m_BossSufferRate = (float)0;
		 m_DodgReduceValue = 0;
		 m_DodgReduceRate = (float)0;
		 m_DodgAddValue = 0;
		 m_DodgAddRate = (float)0;
		 m_TreasureFootPrint = -1;
		 m_EquipTitle = -1;
		m_ObjAnimEvent = new List<int>();
		 m_PinchData = "";
		 m_SkillCDRate = (float)1;
		 m_AspdRate = (float)1;
		 m_Shield = 0;
		 m_EventLeftCount = -1;
		 m_CanNotRush = 0;
		 m_HuntPoint = 0;
		 m_HuntHighTimes = 0;
		 m_HuntFirePoint = 0;
		 m_Starbattlestate = 1;
		 m_IgnoreMotionBlock = false;
		 m_EnableInteract = false;
		 m_WorldMedal = 0;
		 m_CureCeiling = -1;
		 m_RelationUnionCurrency = 0;
		 m_GuildShortName = "";
		 m_GuildShortColorID = -1;

	}

 	//转化成Protobuffer类型函数
	public BaseAttrUserDataV1 ToPB()
	{
		BaseAttrUserDataV1 v = new BaseAttrUserDataV1();
		v.Exp = m_Exp;
		v.Level = m_Level;
		v.ServerTime = m_ServerTime;
		v.RoleId = m_RoleId;
		v.Strength = m_Strength;
		v.Agility = m_Agility;
		v.Intellectual = m_Intellectual;
		v.Endurance = m_Endurance;
		v.Hp = m_Hp;
		v.MaxHp = m_MaxHp;
		v.PhysicAttack = m_PhysicAttack;
		v.PhysicDefense = m_PhysicDefense;
		v.MagicAttack = m_MagicAttack;
		v.MagicDefense = m_MagicDefense;
		v.Hit = m_Hit;
		v.HitRate = m_HitRate;
		v.Miss = m_Miss;
		v.MissRate = m_MissRate;
		v.Critical = m_Critical;
		v.CriticalRate = m_CriticalRate;
		v.Tenacity = m_Tenacity;
		v.TenacityRate = m_TenacityRate;
		v.Penet = m_Penet;
		v.PenetRate = m_PenetRate;
		v.Dodg = m_Dodg;
		v.DodgRate = m_DodgRate;
		v.CriticalAddition = m_CriticalAddition;
		v.CriticalAdditionRate = m_CriticalAdditionRate;
		v.CriticalImmune = m_CriticalImmune;
		v.CriticalImmuneRate = m_CriticalImmuneRate;
		v.MissLevel = m_MissLevel;
		v.CriticalLevel = m_CriticalLevel;
		v.DodgLevel = m_DodgLevel;
		v.MoveSpeed = m_MoveSpeed;
		v.DizzyState = m_DizzyState;
		v.GodState = m_GodState;
		v.CantMoveState = m_CantMoveState;
		v.PhysicAddition = m_PhysicAddition;
		v.MagicAddition = m_MagicAddition;
		v.PhysicOppose = m_PhysicOppose;
		v.MagicOppose = m_MagicOppose;
		v.AccumulateSkiEnergy = m_AccumulateSkiEnergy;
		v.NickName = m_NickName;
		v.ConfigId = m_ConfigId;
		v.ObjType = m_ObjType;
		v.State = m_State;
		v.OwnerObjId = m_OwnerObjId;
		v.Camp = m_Camp;
		v.SilverMoney = m_SilverMoney;
		v.GoldMoney = m_GoldMoney;
		v.DiamondMoney = m_DiamondMoney;
		v.BindingDiamondMoney = m_BindingDiamondMoney;
		v.BattleScore = m_BattleScore;
		v.Energy = m_Energy;
		v.GuildMoney = m_GuildMoney;
		for (int i=0; i<(int)m_SkillList.Count; i++)
			v.SkillList.Add( m_SkillList[i]);
		v.HonorMoney = m_HonorMoney;
		v.ResourcePoolHp = m_ResourcePoolHp;
		v.AttackAdd = m_AttackAdd;
		v.InjuryAdd = m_InjuryAdd;
		v.FrozenState = m_FrozenState;
		v.SilentState = m_SilentState;
		v.GuildContributeHistoryMax = m_GuildContributeHistoryMax;
		v.TeamId = m_TeamId;
		v.TreasureHair = m_TreasureHair;
		v.TreasureHead = m_TreasureHead;
		v.TreasureBody = m_TreasureBody;
		v.TreasureWeapon = m_TreasureWeapon;
		v.TreasureWing = m_TreasureWing;
		v.GuildGuid = m_GuildGuid;
		v.TreasureRiding = m_TreasureRiding;
		v.VechicleId = m_VechicleId;
		v.AnimationState = m_AnimationState;
		v.RefixDmgRate = m_RefixDmgRate;
		v.RefixDmgValue = m_RefixDmgValue;
		v.RefixHurtRate = m_RefixHurtRate;
		v.RefixHurtValue = m_RefixHurtValue;
		v.RefixHealRate = m_RefixHealRate;
		v.RefixHealValue = m_RefixHealValue;
		v.RefixCuredRate = m_RefixCuredRate;
		v.RefixCuredValue = m_RefixCuredValue;
		v.GuildContribute = m_GuildContribute;
		v.PvpMoney = m_PvpMoney;
		v.GuildResource = m_GuildResource;
		v.CreateRoleTime = m_CreateRoleTime;
		v.UpdateRoleTime = m_UpdateRoleTime;
		v.FightState = m_FightState;
		for (int i=0; i<(int)m_AttackSkillList.Count; i++)
			v.AttackSkillList.Add( m_AttackSkillList[i]);
		v.GuildName = m_GuildName;
		v.IsAllowSelect = m_IsAllowSelect;
		v.GoHomeState = m_GoHomeState;
		v.CanFight = m_CanFight;
		v.DoubleExp = m_DoubleExp;
		v.FriendPoint = m_FriendPoint;
		v.HisMaxHonor = m_HisMaxHonor;
		v.HurtState = m_HurtState;
		v.HurtFlyState = m_HurtFlyState;
		v.HurtDownState = m_HurtDownState;
		v.HurtRepelState = m_HurtRepelState;
		v.TodayHornor = m_TodayHornor;
		v.CurProfession = m_CurProfession;
		v.PetCreateDelCond = m_PetCreateDelCond;
		v.PetDisplay = m_PetDisplay;
		v.PetMoney = m_PetMoney;
		v.DuelStatus = m_DuelStatus;
		v.ExpPool = m_ExpPool;
		v.RushState = m_RushState;
		v.StareState = m_StareState;
		v.WorldLevel = m_WorldLevel;
		v.DizzyHitRate = m_DizzyHitRate;
		v.DizzyResistRate = m_DizzyResistRate;
		v.ImmovableHitRate = m_ImmovableHitRate;
		v.ImmovableResistRate = m_ImmovableResistRate;
		v.HurtFlyHitRate = m_HurtFlyHitRate;
		v.HurtFlyResistRate = m_HurtFlyResistRate;
		v.FrozenHitRate = m_FrozenHitRate;
		v.FrozenResistRate = m_FrozenResistRate;
		v.CleanHitRate = m_CleanHitRate;
		v.CleanResistRate = m_CleanResistRate;
		v.DispelHitRate = m_DispelHitRate;
		v.DispelResistRate = m_DispelResistRate;
		v.SilenceHitRate = m_SilenceHitRate;
		v.SilenceResistRate = m_SilenceResistRate;
		v.InterruptHitRate = m_InterruptHitRate;
		v.InterruptResistRate = m_InterruptResistRate;
		v.UncurableHitRate = m_UncurableHitRate;
		v.UncurableResistRate = m_UncurableResistRate;
		v.Transform = m_Transform;
		v.HumanHurtRate = m_HumanHurtRate;
		v.HumanSufferRate = m_HumanSufferRate;
		v.MonsterHurtRate = m_MonsterHurtRate;
		v.MonsterSufferRate = m_MonsterSufferRate;
		v.BossHurtRate = m_BossHurtRate;
		v.BossSufferRate = m_BossSufferRate;
		v.DodgReduceValue = m_DodgReduceValue;
		v.DodgReduceRate = m_DodgReduceRate;
		v.DodgAddValue = m_DodgAddValue;
		v.DodgAddRate = m_DodgAddRate;
		v.TreasureFootPrint = m_TreasureFootPrint;
		v.EquipTitle = m_EquipTitle;
		for (int i=0; i<(int)m_ObjAnimEvent.Count; i++)
			v.ObjAnimEvent.Add( m_ObjAnimEvent[i]);
		v.PinchData = m_PinchData;
		v.SkillCDRate = m_SkillCDRate;
		v.AspdRate = m_AspdRate;
		v.Shield = m_Shield;
		v.EventLeftCount = m_EventLeftCount;
		v.CanNotRush = m_CanNotRush;
		v.HuntPoint = m_HuntPoint;
		v.HuntHighTimes = m_HuntHighTimes;
		v.HuntFirePoint = m_HuntFirePoint;
		v.Starbattlestate = m_Starbattlestate;
		v.IgnoreMotionBlock = m_IgnoreMotionBlock;
		v.EnableInteract = m_EnableInteract;
		v.WorldMedal = m_WorldMedal;
		v.CureCeiling = m_CureCeiling;
		v.RelationUnionCurrency = m_RelationUnionCurrency;
		v.GuildShortName = m_GuildShortName;
		v.GuildShortColorID = m_GuildShortColorID;

		return v;
	}
	
	//从Protobuffer类型初始化
	public void FromPB(BaseAttrUserDataV1 v)
	{
        if (v == null)
            return;
		m_Exp = v.Exp;
		m_Level = v.Level;
		m_ServerTime = v.ServerTime;
		m_RoleId = v.RoleId;
		m_Strength = v.Strength;
		m_Agility = v.Agility;
		m_Intellectual = v.Intellectual;
		m_Endurance = v.Endurance;
		m_Hp = v.Hp;
		m_MaxHp = v.MaxHp;
		m_PhysicAttack = v.PhysicAttack;
		m_PhysicDefense = v.PhysicDefense;
		m_MagicAttack = v.MagicAttack;
		m_MagicDefense = v.MagicDefense;
		m_Hit = v.Hit;
		m_HitRate = v.HitRate;
		m_Miss = v.Miss;
		m_MissRate = v.MissRate;
		m_Critical = v.Critical;
		m_CriticalRate = v.CriticalRate;
		m_Tenacity = v.Tenacity;
		m_TenacityRate = v.TenacityRate;
		m_Penet = v.Penet;
		m_PenetRate = v.PenetRate;
		m_Dodg = v.Dodg;
		m_DodgRate = v.DodgRate;
		m_CriticalAddition = v.CriticalAddition;
		m_CriticalAdditionRate = v.CriticalAdditionRate;
		m_CriticalImmune = v.CriticalImmune;
		m_CriticalImmuneRate = v.CriticalImmuneRate;
		m_MissLevel = v.MissLevel;
		m_CriticalLevel = v.CriticalLevel;
		m_DodgLevel = v.DodgLevel;
		m_MoveSpeed = v.MoveSpeed;
		m_DizzyState = v.DizzyState;
		m_GodState = v.GodState;
		m_CantMoveState = v.CantMoveState;
		m_PhysicAddition = v.PhysicAddition;
		m_MagicAddition = v.MagicAddition;
		m_PhysicOppose = v.PhysicOppose;
		m_MagicOppose = v.MagicOppose;
		m_AccumulateSkiEnergy = v.AccumulateSkiEnergy;
		m_NickName = v.NickName;
		m_ConfigId = v.ConfigId;
		m_ObjType = v.ObjType;
		m_State = v.State;
		m_OwnerObjId = v.OwnerObjId;
		m_Camp = v.Camp;
		m_SilverMoney = v.SilverMoney;
		m_GoldMoney = v.GoldMoney;
		m_DiamondMoney = v.DiamondMoney;
		m_BindingDiamondMoney = v.BindingDiamondMoney;
		m_BattleScore = v.BattleScore;
		m_Energy = v.Energy;
		m_GuildMoney = v.GuildMoney;
		m_SkillList.Clear();
		for( int i=0; i<v.SkillList.Count; i++)
			m_SkillList.Add(v.SkillList[i]);
		m_HonorMoney = v.HonorMoney;
		m_ResourcePoolHp = v.ResourcePoolHp;
		m_AttackAdd = v.AttackAdd;
		m_InjuryAdd = v.InjuryAdd;
		m_FrozenState = v.FrozenState;
		m_SilentState = v.SilentState;
		m_GuildContributeHistoryMax = v.GuildContributeHistoryMax;
		m_TeamId = v.TeamId;
		m_TreasureHair = v.TreasureHair;
		m_TreasureHead = v.TreasureHead;
		m_TreasureBody = v.TreasureBody;
		m_TreasureWeapon = v.TreasureWeapon;
		m_TreasureWing = v.TreasureWing;
		m_GuildGuid = v.GuildGuid;
		m_TreasureRiding = v.TreasureRiding;
		m_VechicleId = v.VechicleId;
		m_AnimationState = v.AnimationState;
		m_RefixDmgRate = v.RefixDmgRate;
		m_RefixDmgValue = v.RefixDmgValue;
		m_RefixHurtRate = v.RefixHurtRate;
		m_RefixHurtValue = v.RefixHurtValue;
		m_RefixHealRate = v.RefixHealRate;
		m_RefixHealValue = v.RefixHealValue;
		m_RefixCuredRate = v.RefixCuredRate;
		m_RefixCuredValue = v.RefixCuredValue;
		m_GuildContribute = v.GuildContribute;
		m_PvpMoney = v.PvpMoney;
		m_GuildResource = v.GuildResource;
		m_CreateRoleTime = v.CreateRoleTime;
		m_UpdateRoleTime = v.UpdateRoleTime;
		m_FightState = v.FightState;
		m_AttackSkillList.Clear();
		for( int i=0; i<v.AttackSkillList.Count; i++)
			m_AttackSkillList.Add(v.AttackSkillList[i]);
		m_GuildName = v.GuildName;
		m_IsAllowSelect = v.IsAllowSelect;
		m_GoHomeState = v.GoHomeState;
		m_CanFight = v.CanFight;
		m_DoubleExp = v.DoubleExp;
		m_FriendPoint = v.FriendPoint;
		m_HisMaxHonor = v.HisMaxHonor;
		m_HurtState = v.HurtState;
		m_HurtFlyState = v.HurtFlyState;
		m_HurtDownState = v.HurtDownState;
		m_HurtRepelState = v.HurtRepelState;
		m_TodayHornor = v.TodayHornor;
		m_CurProfession = v.CurProfession;
		m_PetCreateDelCond = v.PetCreateDelCond;
		m_PetDisplay = v.PetDisplay;
		m_PetMoney = v.PetMoney;
		m_DuelStatus = v.DuelStatus;
		m_ExpPool = v.ExpPool;
		m_RushState = v.RushState;
		m_StareState = v.StareState;
		m_WorldLevel = v.WorldLevel;
		m_DizzyHitRate = v.DizzyHitRate;
		m_DizzyResistRate = v.DizzyResistRate;
		m_ImmovableHitRate = v.ImmovableHitRate;
		m_ImmovableResistRate = v.ImmovableResistRate;
		m_HurtFlyHitRate = v.HurtFlyHitRate;
		m_HurtFlyResistRate = v.HurtFlyResistRate;
		m_FrozenHitRate = v.FrozenHitRate;
		m_FrozenResistRate = v.FrozenResistRate;
		m_CleanHitRate = v.CleanHitRate;
		m_CleanResistRate = v.CleanResistRate;
		m_DispelHitRate = v.DispelHitRate;
		m_DispelResistRate = v.DispelResistRate;
		m_SilenceHitRate = v.SilenceHitRate;
		m_SilenceResistRate = v.SilenceResistRate;
		m_InterruptHitRate = v.InterruptHitRate;
		m_InterruptResistRate = v.InterruptResistRate;
		m_UncurableHitRate = v.UncurableHitRate;
		m_UncurableResistRate = v.UncurableResistRate;
		m_Transform = v.Transform;
		m_HumanHurtRate = v.HumanHurtRate;
		m_HumanSufferRate = v.HumanSufferRate;
		m_MonsterHurtRate = v.MonsterHurtRate;
		m_MonsterSufferRate = v.MonsterSufferRate;
		m_BossHurtRate = v.BossHurtRate;
		m_BossSufferRate = v.BossSufferRate;
		m_DodgReduceValue = v.DodgReduceValue;
		m_DodgReduceRate = v.DodgReduceRate;
		m_DodgAddValue = v.DodgAddValue;
		m_DodgAddRate = v.DodgAddRate;
		m_TreasureFootPrint = v.TreasureFootPrint;
		m_EquipTitle = v.EquipTitle;
		m_ObjAnimEvent.Clear();
		for( int i=0; i<v.ObjAnimEvent.Count; i++)
			m_ObjAnimEvent.Add(v.ObjAnimEvent[i]);
		m_PinchData = v.PinchData;
		m_SkillCDRate = v.SkillCDRate;
		m_AspdRate = v.AspdRate;
		m_Shield = v.Shield;
		m_EventLeftCount = v.EventLeftCount;
		m_CanNotRush = v.CanNotRush;
		m_HuntPoint = v.HuntPoint;
		m_HuntHighTimes = v.HuntHighTimes;
		m_HuntFirePoint = v.HuntFirePoint;
		m_Starbattlestate = v.Starbattlestate;
		m_IgnoreMotionBlock = v.IgnoreMotionBlock;
		m_EnableInteract = v.EnableInteract;
		m_WorldMedal = v.WorldMedal;
		m_CureCeiling = v.CureCeiling;
		m_RelationUnionCurrency = v.RelationUnionCurrency;
		m_GuildShortName = v.GuildShortName;
		m_GuildShortColorID = v.GuildShortColorID;

	}
	
	//Protobuffer序列化到MemoryStream
	public MemoryStream ToMemoryStream()
	{
		MemoryStream protoMS = new MemoryStream();
		ProtoBuf.Serializer.Serialize<BaseAttrUserDataV1>(protoMS, ToPB());
		return protoMS;
	}
	
	//Protobuffer从MemoryStream进行反序列化
	public bool FromMemoryStream(MemoryStream protoMS)
	{
		BaseAttrUserDataV1 pb = ProtoBuf.Serializer.Deserialize<BaseAttrUserDataV1>(protoMS);
		FromPB(pb);
		return true;
	}

	//经验
	public int m_Exp;
	public int Exp
	{
		get { return m_Exp;}
		set { m_Exp = value; }
	}
	//玩家等级
	public int m_Level;
	public int Level
	{
		get { return m_Level;}
		set { m_Level = value; }
	}
	//服务器时间
	public int m_ServerTime;
	public int ServerTime
	{
		get { return m_ServerTime;}
		set { m_ServerTime = value; }
	}
	//人物唯一ID
	public UInt64 m_RoleId;
	public UInt64 RoleId
	{
		get { return m_RoleId;}
		set { m_RoleId = value; }
	}
	//力量
	public int m_Strength;
	public int Strength
	{
		get { return m_Strength;}
		set { m_Strength = value; }
	}
	//敏捷
	public int m_Agility;
	public int Agility
	{
		get { return m_Agility;}
		set { m_Agility = value; }
	}
	//智力
	public int m_Intellectual;
	public int Intellectual
	{
		get { return m_Intellectual;}
		set { m_Intellectual = value; }
	}
	//耐力
	public int m_Endurance;
	public int Endurance
	{
		get { return m_Endurance;}
		set { m_Endurance = value; }
	}
	//生命值
	public int m_Hp;
	public int Hp
	{
		get { return m_Hp;}
		set { m_Hp = value; }
	}
	//生命值
	public int m_MaxHp;
	public int MaxHp
	{
		get { return m_MaxHp;}
		set { m_MaxHp = value; }
	}
	//物理攻击
	public int m_PhysicAttack;
	public int PhysicAttack
	{
		get { return m_PhysicAttack;}
		set { m_PhysicAttack = value; }
	}
	//物理防御
	public int m_PhysicDefense;
	public int PhysicDefense
	{
		get { return m_PhysicDefense;}
		set { m_PhysicDefense = value; }
	}
	//魔法攻击
	public int m_MagicAttack;
	public int MagicAttack
	{
		get { return m_MagicAttack;}
		set { m_MagicAttack = value; }
	}
	//魔法防御
	public int m_MagicDefense;
	public int MagicDefense
	{
		get { return m_MagicDefense;}
		set { m_MagicDefense = value; }
	}
	//命中值
	public int m_Hit;
	public int Hit
	{
		get { return m_Hit;}
		set { m_Hit = value; }
	}
	//命中率
	public float m_HitRate;
	public float HitRate
	{
		get { return m_HitRate;}
		set { m_HitRate = value; }
	}
	//闪避值
	public int m_Miss;
	public int Miss
	{
		get { return m_Miss;}
		set { m_Miss = value; }
	}
	//闪避率
	public float m_MissRate;
	public float MissRate
	{
		get { return m_MissRate;}
		set { m_MissRate = value; }
	}
	//暴击值
	public int m_Critical;
	public int Critical
	{
		get { return m_Critical;}
		set { m_Critical = value; }
	}
	//暴击率
	public float m_CriticalRate;
	public float CriticalRate
	{
		get { return m_CriticalRate;}
		set { m_CriticalRate = value; }
	}
	//韧性值
	public int m_Tenacity;
	public int Tenacity
	{
		get { return m_Tenacity;}
		set { m_Tenacity = value; }
	}
	//韧性率
	public float m_TenacityRate;
	public float TenacityRate
	{
		get { return m_TenacityRate;}
		set { m_TenacityRate = value; }
	}
	//穿透值
	public int m_Penet;
	public int Penet
	{
		get { return m_Penet;}
		set { m_Penet = value; }
	}
	//穿透率
	public float m_PenetRate;
	public float PenetRate
	{
		get { return m_PenetRate;}
		set { m_PenetRate = value; }
	}
	//格挡值
	public int m_Dodg;
	public int Dodg
	{
		get { return m_Dodg;}
		set { m_Dodg = value; }
	}
	//格挡率
	public float m_DodgRate;
	public float DodgRate
	{
		get { return m_DodgRate;}
		set { m_DodgRate = value; }
	}
	//暴击加伤值
	public int m_CriticalAddition;
	public int CriticalAddition
	{
		get { return m_CriticalAddition;}
		set { m_CriticalAddition = value; }
	}
	//暴击加伤率
	public float m_CriticalAdditionRate;
	public float CriticalAdditionRate
	{
		get { return m_CriticalAdditionRate;}
		set { m_CriticalAdditionRate = value; }
	}
	//暴击免伤
	public int m_CriticalImmune;
	public int CriticalImmune
	{
		get { return m_CriticalImmune;}
		set { m_CriticalImmune = value; }
	}
	//暴击免伤率
	public float m_CriticalImmuneRate;
	public float CriticalImmuneRate
	{
		get { return m_CriticalImmuneRate;}
		set { m_CriticalImmuneRate = value; }
	}
	//闪避等级
	public int m_MissLevel;
	public int MissLevel
	{
		get { return m_MissLevel;}
		set { m_MissLevel = value; }
	}
	//暴击等级
	public int m_CriticalLevel;
	public int CriticalLevel
	{
		get { return m_CriticalLevel;}
		set { m_CriticalLevel = value; }
	}
	//格挡等级
	public int m_DodgLevel;
	public int DodgLevel
	{
		get { return m_DodgLevel;}
		set { m_DodgLevel = value; }
	}
	//移动速度
	public float m_MoveSpeed;
	public float MoveSpeed
	{
		get { return m_MoveSpeed;}
		set { m_MoveSpeed = value; }
	}
	//眩晕状态
	public int m_DizzyState;
	public int DizzyState
	{
		get { return m_DizzyState;}
		set { m_DizzyState = value; }
	}
	//霸体状态
	public bool m_GodState;
	public bool GodState
	{
		get { return m_GodState;}
		set { m_GodState = value; }
	}
	//不能移动状态
	public int m_CantMoveState;
	public int CantMoveState
	{
		get { return m_CantMoveState;}
		set { m_CantMoveState = value; }
	}
	//物理加伤值
	public float m_PhysicAddition;
	public float PhysicAddition
	{
		get { return m_PhysicAddition;}
		set { m_PhysicAddition = value; }
	}
	//魔法加伤值
	public float m_MagicAddition;
	public float MagicAddition
	{
		get { return m_MagicAddition;}
		set { m_MagicAddition = value; }
	}
	//物理抗性
	public float m_PhysicOppose;
	public float PhysicOppose
	{
		get { return m_PhysicOppose;}
		set { m_PhysicOppose = value; }
	}
	//魔法抗性
	public float m_MagicOppose;
	public float MagicOppose
	{
		get { return m_MagicOppose;}
		set { m_MagicOppose = value; }
	}
	//技能积攒能量使用 目前只有应激技能用
	public float m_AccumulateSkiEnergy;
	public float AccumulateSkiEnergy
	{
		get { return m_AccumulateSkiEnergy;}
		set { m_AccumulateSkiEnergy = value; }
	}
	//名字昵称
	public string m_NickName;
	public string NickName
	{
		get { return m_NickName;}
		set { m_NickName = value; }
	}
	//config id
	public int m_ConfigId;
	public int ConfigId
	{
		get { return m_ConfigId;}
		set { m_ConfigId = value; }
	}
	//类型
	public int m_ObjType;
	public int ObjType
	{
		get { return m_ObjType;}
		set { m_ObjType = value; }
	}
	//EventObjStatu
	public int m_State;
	public int State
	{
		get { return m_State;}
		set { m_State = value; }
	}
	//归属obj ID
	public UInt64 m_OwnerObjId;
	public UInt64 OwnerObjId
	{
		get { return m_OwnerObjId;}
		set { m_OwnerObjId = value; }
	}
	//阵营
	public int m_Camp;
	public int Camp
	{
		get { return m_Camp;}
		set { m_Camp = value; }
	}
	//银币
	public Int64 m_SilverMoney;
	public Int64 SilverMoney
	{
		get { return m_SilverMoney;}
		set { m_SilverMoney = value; }
	}
	//金币
	public Int64 m_GoldMoney;
	public Int64 GoldMoney
	{
		get { return m_GoldMoney;}
		set { m_GoldMoney = value; }
	}
	//钻石
	public Int64 m_DiamondMoney;
	public Int64 DiamondMoney
	{
		get { return m_DiamondMoney;}
		set { m_DiamondMoney = value; }
	}
	//绑定钻石
	public Int64 m_BindingDiamondMoney;
	public Int64 BindingDiamondMoney
	{
		get { return m_BindingDiamondMoney;}
		set { m_BindingDiamondMoney = value; }
	}
	//战力
	public int m_BattleScore;
	public int BattleScore
	{
		get { return m_BattleScore;}
		set { m_BattleScore = value; }
	}
	//精力
	public Int64 m_Energy;
	public Int64 Energy
	{
		get { return m_Energy;}
		set { m_Energy = value; }
	}
	//公会资金
	public Int64 m_GuildMoney;
	public Int64 GuildMoney
	{
		get { return m_GuildMoney;}
		set { m_GuildMoney = value; }
	}
	//技能列表
	public List<int> m_SkillList;
	public int SizeSkillList()
	{
		return m_SkillList.Count;
	}
	public List<int> GetSkillList()
	{
		return m_SkillList;
	}
	public int GetSkillList(int Index)
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return -1;
		return m_SkillList[Index];
	}
	public void SetSkillList( List<int> v )
	{
		m_SkillList=v;
	}
	public void SetSkillList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_SkillList.Count)
			return;
		m_SkillList[Index] = v;
	}
	public void AddSkillList( int v=-1 )
	{
		m_SkillList.Add(v);
	}
	public void ClearSkillList( )
	{
		m_SkillList.Clear();
	}
	//HonorMoney
	public Int64 m_HonorMoney;
	public Int64 HonorMoney
	{
		get { return m_HonorMoney;}
		set { m_HonorMoney = value; }
	}
	//资源池
	public Int64 m_ResourcePoolHp;
	public Int64 ResourcePoolHp
	{
		get { return m_ResourcePoolHp;}
		set { m_ResourcePoolHp = value; }
	}
	//伤害增加
	public int m_AttackAdd;
	public int AttackAdd
	{
		get { return m_AttackAdd;}
		set { m_AttackAdd = value; }
	}
	//伤害减免
	public int m_InjuryAdd;
	public int InjuryAdd
	{
		get { return m_InjuryAdd;}
		set { m_InjuryAdd = value; }
	}
	//冰冻状态
	public int m_FrozenState;
	public int FrozenState
	{
		get { return m_FrozenState;}
		set { m_FrozenState = value; }
	}
	//沉默状态
	public int m_SilentState;
	public int SilentState
	{
		get { return m_SilentState;}
		set { m_SilentState = value; }
	}
	//GuildContributeHistoryMax
	public Int64 m_GuildContributeHistoryMax;
	public Int64 GuildContributeHistoryMax
	{
		get { return m_GuildContributeHistoryMax;}
		set { m_GuildContributeHistoryMax = value; }
	}
	//队伍id
	public UInt64 m_TeamId;
	public UInt64 TeamId
	{
		get { return m_TeamId;}
		set { m_TeamId = value; }
	}
	//头发时装ID
	public int m_TreasureHair;
	public int TreasureHair
	{
		get { return m_TreasureHair;}
		set { m_TreasureHair = value; }
	}
	//头部时装ID
	public int m_TreasureHead;
	public int TreasureHead
	{
		get { return m_TreasureHead;}
		set { m_TreasureHead = value; }
	}
	//身体时装
	public int m_TreasureBody;
	public int TreasureBody
	{
		get { return m_TreasureBody;}
		set { m_TreasureBody = value; }
	}
	//武器时装
	public int m_TreasureWeapon;
	public int TreasureWeapon
	{
		get { return m_TreasureWeapon;}
		set { m_TreasureWeapon = value; }
	}
	//翅膀时装
	public int m_TreasureWing;
	public int TreasureWing
	{
		get { return m_TreasureWing;}
		set { m_TreasureWing = value; }
	}
	//公会ID
	public UInt64 m_GuildGuid;
	public UInt64 GuildGuid
	{
		get { return m_GuildGuid;}
		set { m_GuildGuid = value; }
	}
	//坐骑
	public int m_TreasureRiding;
	public int TreasureRiding
	{
		get { return m_TreasureRiding;}
		set { m_TreasureRiding = value; }
	}
	//载具Id
	public int m_VechicleId;
	public int VechicleId
	{
		get { return m_VechicleId;}
		set { m_VechicleId = value; }
	}
	//动画状态
	public bool m_AnimationState;
	public bool AnimationState
	{
		get { return m_AnimationState;}
		set { m_AnimationState = value; }
	}
	//修正攻击者最终伤害比率
	public float m_RefixDmgRate;
	public float RefixDmgRate
	{
		get { return m_RefixDmgRate;}
		set { m_RefixDmgRate = value; }
	}
	//修正攻击者最终伤害值
	public int m_RefixDmgValue;
	public int RefixDmgValue
	{
		get { return m_RefixDmgValue;}
		set { m_RefixDmgValue = value; }
	}
	//修正被攻击者最终伤害比率
	public float m_RefixHurtRate;
	public float RefixHurtRate
	{
		get { return m_RefixHurtRate;}
		set { m_RefixHurtRate = value; }
	}
	//修正被攻击者最终伤害值
	public int m_RefixHurtValue;
	public int RefixHurtValue
	{
		get { return m_RefixHurtValue;}
		set { m_RefixHurtValue = value; }
	}
	//修正治疗者最终比例
	public float m_RefixHealRate;
	public float RefixHealRate
	{
		get { return m_RefixHealRate;}
		set { m_RefixHealRate = value; }
	}
	//修正治疗者最终值
	public int m_RefixHealValue;
	public int RefixHealValue
	{
		get { return m_RefixHealValue;}
		set { m_RefixHealValue = value; }
	}
	//修正被治疗者最终比例
	public float m_RefixCuredRate;
	public float RefixCuredRate
	{
		get { return m_RefixCuredRate;}
		set { m_RefixCuredRate = value; }
	}
	//修正被治疗者最终值
	public int m_RefixCuredValue;
	public int RefixCuredValue
	{
		get { return m_RefixCuredValue;}
		set { m_RefixCuredValue = value; }
	}
	//公会帮贡
	public Int64 m_GuildContribute;
	public Int64 GuildContribute
	{
		get { return m_GuildContribute;}
		set { m_GuildContribute = value; }
	}
	//竞技场点数
	public Int64 m_PvpMoney;
	public Int64 PvpMoney
	{
		get { return m_PvpMoney;}
		set { m_PvpMoney = value; }
	}
	//公会资源
	public Int64 m_GuildResource;
	public Int64 GuildResource
	{
		get { return m_GuildResource;}
		set { m_GuildResource = value; }
	}
	//创建角色时间戳
	public int m_CreateRoleTime;
	public int CreateRoleTime
	{
		get { return m_CreateRoleTime;}
		set { m_CreateRoleTime = value; }
	}
	//更新角色等级时间戳
	public int m_UpdateRoleTime;
	public int UpdateRoleTime
	{
		get { return m_UpdateRoleTime;}
		set { m_UpdateRoleTime = value; }
	}
	//战斗状态
	public bool m_FightState;
	public bool FightState
	{
		get { return m_FightState;}
		set { m_FightState = value; }
	}
	//普攻技能列表
	public List<int> m_AttackSkillList;
	public int SizeAttackSkillList()
	{
		return m_AttackSkillList.Count;
	}
	public List<int> GetAttackSkillList()
	{
		return m_AttackSkillList;
	}
	public int GetAttackSkillList(int Index)
	{
		if(Index<0 || Index>=(int)m_AttackSkillList.Count)
			return -1;
		return m_AttackSkillList[Index];
	}
	public void SetAttackSkillList( List<int> v )
	{
		m_AttackSkillList=v;
	}
	public void SetAttackSkillList( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_AttackSkillList.Count)
			return;
		m_AttackSkillList[Index] = v;
	}
	public void AddAttackSkillList( int v=-1 )
	{
		m_AttackSkillList.Add(v);
	}
	public void ClearAttackSkillList( )
	{
		m_AttackSkillList.Clear();
	}
	//公会名称
	public string m_GuildName;
	public string GuildName
	{
		get { return m_GuildName;}
		set { m_GuildName = value; }
	}
	//是否可选中
	public bool m_IsAllowSelect;
	public bool IsAllowSelect
	{
		get { return m_IsAllowSelect;}
		set { m_IsAllowSelect = value; }
	}
	//怪物回归中
	public bool m_GoHomeState;
	public bool GoHomeState
	{
		get { return m_GoHomeState;}
		set { m_GoHomeState = value; }
	}
	//怪物是否可攻击
	public bool m_CanFight;
	public bool CanFight
	{
		get { return m_CanFight;}
		set { m_CanFight = value; }
	}
	//双倍经验
	public Int64 m_DoubleExp;
	public Int64 DoubleExp
	{
		get { return m_DoubleExp;}
		set { m_DoubleExp = value; }
	}
	//友情点
	public Int64 m_FriendPoint;
	public Int64 FriendPoint
	{
		get { return m_FriendPoint;}
		set { m_FriendPoint = value; }
	}
	//历史最大荣誉点
	public Int64 m_HisMaxHonor;
	public Int64 HisMaxHonor
	{
		get { return m_HisMaxHonor;}
		set { m_HisMaxHonor = value; }
	}
	//受击状态
	public bool m_HurtState;
	public bool HurtState
	{
		get { return m_HurtState;}
		set { m_HurtState = value; }
	}
	//击飞状态
	public bool m_HurtFlyState;
	public bool HurtFlyState
	{
		get { return m_HurtFlyState;}
		set { m_HurtFlyState = value; }
	}
	//击倒状态
	public bool m_HurtDownState;
	public bool HurtDownState
	{
		get { return m_HurtDownState;}
		set { m_HurtDownState = value; }
	}
	//击退
	public bool m_HurtRepelState;
	public bool HurtRepelState
	{
		get { return m_HurtRepelState;}
		set { m_HurtRepelState = value; }
	}
	//今日获得的荣誉值
	public Int64 m_TodayHornor;
	public Int64 TodayHornor
	{
		get { return m_TodayHornor;}
		set { m_TodayHornor = value; }
	}
	//当前专精
	public int m_CurProfession;
	public int CurProfession
	{
		get { return m_CurProfession;}
		set { m_CurProfession = value; }
	}
	//宠物创建删除条件枚举
	public int m_PetCreateDelCond;
	public int PetCreateDelCond
	{
		get { return m_PetCreateDelCond;}
		set { m_PetCreateDelCond = value; }
	}
	//宠物是否需要隐藏1显示0隐藏
	public int m_PetDisplay;
	public int PetDisplay
	{
		get { return m_PetDisplay;}
		set { m_PetDisplay = value; }
	}
	//宠物货币
	public Int64 m_PetMoney;
	public Int64 PetMoney
	{
		get { return m_PetMoney;}
		set { m_PetMoney = value; }
	}
	//决斗状态
	public int m_DuelStatus;
	public int DuelStatus
	{
		get { return m_DuelStatus;}
		set { m_DuelStatus = value; }
	}
	//经验池
	public Int64 m_ExpPool;
	public Int64 ExpPool
	{
		get { return m_ExpPool;}
		set { m_ExpPool = value; }
	}
	//疾跑状态
	public bool m_RushState;
	public bool RushState
	{
		get { return m_RushState;}
		set { m_RushState = value; }
	}
	//盯防状态
	public UInt64 m_StareState;
	public UInt64 StareState
	{
		get { return m_StareState;}
		set { m_StareState = value; }
	}
	//世界等级
	public int m_WorldLevel;
	public int WorldLevel
	{
		get { return m_WorldLevel;}
		set { m_WorldLevel = value; }
	}
	//眩晕命中率
	public float m_DizzyHitRate;
	public float DizzyHitRate
	{
		get { return m_DizzyHitRate;}
		set { m_DizzyHitRate = value; }
	}
	//眩晕抵抗率
	public float m_DizzyResistRate;
	public float DizzyResistRate
	{
		get { return m_DizzyResistRate;}
		set { m_DizzyResistRate = value; }
	}
	//定身命中率
	public float m_ImmovableHitRate;
	public float ImmovableHitRate
	{
		get { return m_ImmovableHitRate;}
		set { m_ImmovableHitRate = value; }
	}
	//定身抵抗率
	public float m_ImmovableResistRate;
	public float ImmovableResistRate
	{
		get { return m_ImmovableResistRate;}
		set { m_ImmovableResistRate = value; }
	}
	//击飞命中率
	public float m_HurtFlyHitRate;
	public float HurtFlyHitRate
	{
		get { return m_HurtFlyHitRate;}
		set { m_HurtFlyHitRate = value; }
	}
	//击飞抵抗率
	public float m_HurtFlyResistRate;
	public float HurtFlyResistRate
	{
		get { return m_HurtFlyResistRate;}
		set { m_HurtFlyResistRate = value; }
	}
	//冰冻命中率
	public float m_FrozenHitRate;
	public float FrozenHitRate
	{
		get { return m_FrozenHitRate;}
		set { m_FrozenHitRate = value; }
	}
	//冰冻抵抗率
	public float m_FrozenResistRate;
	public float FrozenResistRate
	{
		get { return m_FrozenResistRate;}
		set { m_FrozenResistRate = value; }
	}
	//净化命中率
	public float m_CleanHitRate;
	public float CleanHitRate
	{
		get { return m_CleanHitRate;}
		set { m_CleanHitRate = value; }
	}
	//净化抵抗率
	public float m_CleanResistRate;
	public float CleanResistRate
	{
		get { return m_CleanResistRate;}
		set { m_CleanResistRate = value; }
	}
	//驱散命中率
	public float m_DispelHitRate;
	public float DispelHitRate
	{
		get { return m_DispelHitRate;}
		set { m_DispelHitRate = value; }
	}
	//驱散抵抗率
	public float m_DispelResistRate;
	public float DispelResistRate
	{
		get { return m_DispelResistRate;}
		set { m_DispelResistRate = value; }
	}
	//沉默命中率
	public float m_SilenceHitRate;
	public float SilenceHitRate
	{
		get { return m_SilenceHitRate;}
		set { m_SilenceHitRate = value; }
	}
	//沉默抵抗率
	public float m_SilenceResistRate;
	public float SilenceResistRate
	{
		get { return m_SilenceResistRate;}
		set { m_SilenceResistRate = value; }
	}
	//打断命中率
	public float m_InterruptHitRate;
	public float InterruptHitRate
	{
		get { return m_InterruptHitRate;}
		set { m_InterruptHitRate = value; }
	}
	//打断抵抗率
	public float m_InterruptResistRate;
	public float InterruptResistRate
	{
		get { return m_InterruptResistRate;}
		set { m_InterruptResistRate = value; }
	}
	//禁疗命中率
	public float m_UncurableHitRate;
	public float UncurableHitRate
	{
		get { return m_UncurableHitRate;}
		set { m_UncurableHitRate = value; }
	}
	//禁疗抵抗率
	public float m_UncurableResistRate;
	public float UncurableResistRate
	{
		get { return m_UncurableResistRate;}
		set { m_UncurableResistRate = value; }
	}
	//变身
	public int m_Transform;
	public int Transform
	{
		get { return m_Transform;}
		set { m_Transform = value; }
	}
	//受到玩家目标伤害比
	public float m_HumanHurtRate;
	public float HumanHurtRate
	{
		get { return m_HumanHurtRate;}
		set { m_HumanHurtRate = value; }
	}
	//针对玩家目标伤害比
	public float m_HumanSufferRate;
	public float HumanSufferRate
	{
		get { return m_HumanSufferRate;}
		set { m_HumanSufferRate = value; }
	}
	//受到怪物目标伤害比
	public float m_MonsterHurtRate;
	public float MonsterHurtRate
	{
		get { return m_MonsterHurtRate;}
		set { m_MonsterHurtRate = value; }
	}
	//针对怪物目标伤害比
	public float m_MonsterSufferRate;
	public float MonsterSufferRate
	{
		get { return m_MonsterSufferRate;}
		set { m_MonsterSufferRate = value; }
	}
	//受到Boss目标伤害比
	public float m_BossHurtRate;
	public float BossHurtRate
	{
		get { return m_BossHurtRate;}
		set { m_BossHurtRate = value; }
	}
	//针对Boss目标伤害比
	public float m_BossSufferRate;
	public float BossSufferRate
	{
		get { return m_BossSufferRate;}
		set { m_BossSufferRate = value; }
	}
	//格挡减伤值
	public int m_DodgReduceValue;
	public int DodgReduceValue
	{
		get { return m_DodgReduceValue;}
		set { m_DodgReduceValue = value; }
	}
	//格挡减伤率
	public float m_DodgReduceRate;
	public float DodgReduceRate
	{
		get { return m_DodgReduceRate;}
		set { m_DodgReduceRate = value; }
	}
	//格挡破伤值
	public int m_DodgAddValue;
	public int DodgAddValue
	{
		get { return m_DodgAddValue;}
		set { m_DodgAddValue = value; }
	}
	//格挡破伤率
	public float m_DodgAddRate;
	public float DodgAddRate
	{
		get { return m_DodgAddRate;}
		set { m_DodgAddRate = value; }
	}
	//步尘
	public int m_TreasureFootPrint;
	public int TreasureFootPrint
	{
		get { return m_TreasureFootPrint;}
		set { m_TreasureFootPrint = value; }
	}
	//装备称号
	public int m_EquipTitle;
	public int EquipTitle
	{
		get { return m_EquipTitle;}
		set { m_EquipTitle = value; }
	}
	//当前所在动画事件
	public List<int> m_ObjAnimEvent;
	public int SizeObjAnimEvent()
	{
		return m_ObjAnimEvent.Count;
	}
	public List<int> GetObjAnimEvent()
	{
		return m_ObjAnimEvent;
	}
	public int GetObjAnimEvent(int Index)
	{
		if(Index<0 || Index>=(int)m_ObjAnimEvent.Count)
			return -1;
		return m_ObjAnimEvent[Index];
	}
	public void SetObjAnimEvent( List<int> v )
	{
		m_ObjAnimEvent=v;
	}
	public void SetObjAnimEvent( int Index, int v )
	{
		if(Index<0 || Index>=(int)m_ObjAnimEvent.Count)
			return;
		m_ObjAnimEvent[Index] = v;
	}
	public void AddObjAnimEvent( int v=-1 )
	{
		m_ObjAnimEvent.Add(v);
	}
	public void ClearObjAnimEvent( )
	{
		m_ObjAnimEvent.Clear();
	}
	//捏脸数据
	public string m_PinchData;
	public string PinchData
	{
		get { return m_PinchData;}
		set { m_PinchData = value; }
	}
	//技能冷缩比例
	public float m_SkillCDRate;
	public float SkillCDRate
	{
		get { return m_SkillCDRate;}
		set { m_SkillCDRate = value; }
	}
	//攻速
	public float m_AspdRate;
	public float AspdRate
	{
		get { return m_AspdRate;}
		set { m_AspdRate = value; }
	}
	//护盾值
	public int m_Shield;
	public int Shield
	{
		get { return m_Shield;}
		set { m_Shield = value; }
	}
	//obj剩余采集次数
	public int m_EventLeftCount;
	public int EventLeftCount
	{
		get { return m_EventLeftCount;}
		set { m_EventLeftCount = value; }
	}
	//不能疾跑状态
	public int m_CanNotRush;
	public int CanNotRush
	{
		get { return m_CanNotRush;}
		set { m_CanNotRush = value; }
	}
	//猎魔点数
	public int m_HuntPoint;
	public int HuntPoint
	{
		get { return m_HuntPoint;}
		set { m_HuntPoint = value; }
	}
	//猎魔高倍
	public int m_HuntHighTimes;
	public int HuntHighTimes
	{
		get { return m_HuntHighTimes;}
		set { m_HuntHighTimes = value; }
	}
	//猎魔引燃次数
	public int m_HuntFirePoint;
	public int HuntFirePoint
	{
		get { return m_HuntFirePoint;}
		set { m_HuntFirePoint = value; }
	}
	//星耀NPC状态(1可进入 2不可进入)
	public int m_Starbattlestate;
	public int Starbattlestate
	{
		get { return m_Starbattlestate;}
		set { m_Starbattlestate = value; }
	}
	//是否忽略地图阻挡
	public bool m_IgnoreMotionBlock;
	public bool IgnoreMotionBlock
	{
		get { return m_IgnoreMotionBlock;}
		set { m_IgnoreMotionBlock = value; }
	}
	//EnableInteract
	public bool m_EnableInteract;
	public bool EnableInteract
	{
		get { return m_EnableInteract;}
		set { m_EnableInteract = value; }
	}
	//世界奖章
	public int m_WorldMedal;
	public int WorldMedal
	{
		get { return m_WorldMedal;}
		set { m_WorldMedal = value; }
	}
	//治疗上限
	public int m_CureCeiling;
	public int CureCeiling
	{
		get { return m_CureCeiling;}
		set { m_CureCeiling = value; }
	}
	//圣乐之力
	public int m_RelationUnionCurrency;
	public int RelationUnionCurrency
	{
		get { return m_RelationUnionCurrency;}
		set { m_RelationUnionCurrency = value; }
	}
	//公会简称
	public string m_GuildShortName;
	public string GuildShortName
	{
		get { return m_GuildShortName;}
		set { m_GuildShortName = value; }
	}
	//公会简称颜色ID
	public int m_GuildShortColorID;
	public int GuildShortColorID
	{
		get { return m_GuildShortColorID;}
		set { m_GuildShortColorID = value; }
	}



}
