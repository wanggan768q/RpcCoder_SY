#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class FightRpcUseSkillActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public UInt64 ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public float X;
	public float Y;
	public float Z;
	public int MomentIndex;
	public CustomSkiDataWraper CustomSkiData;
}
[System.Serializable]
public class FightRpcShowExpActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int Value;
}
[System.Serializable]
public class FightRpcBuffActionNotifyWraperHelper
{
	public BuffInfoWraper Info;
}
[System.Serializable]
public class FightRpcStateActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int Type;
	public Vector3Wraper Pos;
	public int TargetPos;
	public int State;
}
[System.Serializable]
public class FightRpcReviveActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public Vector3Wraper Pos;
	public int CurHp;
}
[System.Serializable]
public class FightRpcComboSkillActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int SkillId;
}
[System.Serializable]
public class FightRpcDropActionNotifyWraperHelper
{
}
[System.Serializable]
public class FightRpcUseItemActionNotifyWraperHelper
{
}
[System.Serializable]
public class FightRpcHpChangeActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int IncrementHp;
	public UInt64 CasterId;
}
[System.Serializable]
public class FightRpcUseSkillAskWraperHelper
{
	public List<UInt64> ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public float X;
	public float Y;
	public float Z;
	public int MomentIndex;
	public CustomSkiDataWraper CustomSkiData;
	public Vector3IntWraper CurrentPos;
}
[System.Serializable]
public class FightRpcHurtActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int SegmentIndex;
	public int SkillId;
	public UInt64 TargetObjId;
	public int HurtValue;
	public bool IsCritical;
	public bool IsDodge;
	public bool IsMiss;
	public bool IsHurtState;
	public int AttackId;
	public bool IsDead;
}
[System.Serializable]
public class FightRpcRepelActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public int SegmentIndex;
	public int SkillId;
	public UInt64 TargetObjId;
	public Vector3Wraper SkiTargetPos;
	public bool IsPlayerDiaup;
	public float Speed;
}
[System.Serializable]
public class FightRpcObjDeadActionNotifyWraperHelper
{
	public UInt64 ObjId;
}
[System.Serializable]
public class FightRpcFightTipsNotifyWraperHelper
{
	public int TipsID;
	public int Durtion;
	public int TypeID;
}
[System.Serializable]
public class FightRpcBuffListNotifyWraperHelper
{
	public List<BuffInfoWraper> BuffList;
}
[System.Serializable]
public class FightRpcReduceCDNotifyWraperHelper
{
	public int SkillId;
	public int ModTime;
}
[System.Serializable]
public class FightRpcReliveNotifyNotifyWraperHelper
{
	public UInt64 ObjId;
}
[System.Serializable]
public class FightRpcSkillCDNotifyWraperHelper
{
	public List<SkillCDInfoWraper> SkillCDInfo;
}
[System.Serializable]
public class FightRpcAutoCombatMonsterNotifyWraperHelper
{
	public UInt64 MonsterGuid;
}
[System.Serializable]
public class FightRpcTranslateActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public Vector3Wraper TargetPos;
	public float Dir;
	public int SkillId;
	public int CommandIndex;
	public bool IsEnd;
	public float Speed;
}
[System.Serializable]
public class FightRpcCantAddBuffTipNotifyWraperHelper
{
	public int BuffId;
	public UInt64 CasterId;
	public UInt64 ObjId;
	public int Sn;
}
[System.Serializable]
public class FightRpcAttackWarningNotifyWraperHelper
{
	public int AttackId;
	public UInt64 Caster;
	public List<UInt64> TargetList;
	public Vector3Wraper TargetPos;
	public int SkillId;
}
[System.Serializable]
public class FightRpcInterruptActionNotifyWraperHelper
{
	public UInt64 Caster;
	public UInt64 Interrupter;
	public List<int> Skill;
}
[System.Serializable]
public class FightRpcSkillPrepareAskWraperHelper
{
	public int SkillId;
	public int Type;
}
[System.Serializable]
public class FightRpcSkillPrepareActionNotifyWraperHelper
{
	public Int64 ObjId;
	public int SkillId;
	public int Type;
}
[System.Serializable]
public class FightRpcChainMagicJumpNotifyWraperHelper
{
	public Int64 ObjId;
	public int SkillId;
	public Int64 JumpFromObjId;
	public Int64 JumpToObjId;
	public int AttackId;
}
[System.Serializable]
public class FightRpcBlackHoleActionNotifyWraperHelper
{
	public Int64 ObjId;
	public float ToX;
	public float ToZ;
	public float Speed;
	public bool Apply;
	public int Type;
	public UInt64 TargetObjId;
}
[System.Serializable]
public class FightRpcLoopActionCancelAskWraperHelper
{
	public int SkillId;
}
[System.Serializable]
public class FightRpcLoopActionCancelOtherNotifyWraperHelper
{
	public UInt64 ObjId;
	public int SkillId;
}
[System.Serializable]
public class FightRpcSkillListNotifyWraperHelper
{
	public List<int> SkillList;
}
[System.Serializable]
public class FightRpcUsePetSkillAskWraperHelper
{
	public List<UInt64> ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public Vector3IntWraper CurrentPos;
	public Vector3IntWraper TargetPos;
}
[System.Serializable]
public class FightRpcRemoveModifySkillNotifyWraperHelper
{
}
[System.Serializable]
public class FightRpcLinkMagicActionNotifyWraperHelper
{
	public UInt64 ObjId;
	public UInt64 LinkerId;
	public int AttackId;
}
[System.Serializable]
public class FightRpcMonsterInteractAskWraperHelper
{
	public UInt64 TargetId;
}



public class FightTestHelper : MonoBehaviour
{
	public FightRpcUseSkillActionNotifyWraperHelper FightRpcUseSkillActionNotifyWraperVar;
	public FightRpcShowExpActionNotifyWraperHelper FightRpcShowExpActionNotifyWraperVar;
	public FightRpcBuffActionNotifyWraperHelper FightRpcBuffActionNotifyWraperVar;
	public FightRpcStateActionNotifyWraperHelper FightRpcStateActionNotifyWraperVar;
	public FightRpcReviveActionNotifyWraperHelper FightRpcReviveActionNotifyWraperVar;
	public FightRpcComboSkillActionNotifyWraperHelper FightRpcComboSkillActionNotifyWraperVar;
	public FightRpcDropActionNotifyWraperHelper FightRpcDropActionNotifyWraperVar;
	public FightRpcUseItemActionNotifyWraperHelper FightRpcUseItemActionNotifyWraperVar;
	public FightRpcHpChangeActionNotifyWraperHelper FightRpcHpChangeActionNotifyWraperVar;
	public FightRpcUseSkillAskWraperHelper FightRpcUseSkillAskWraperVar;
	public FightRpcHurtActionNotifyWraperHelper FightRpcHurtActionNotifyWraperVar;
	public FightRpcRepelActionNotifyWraperHelper FightRpcRepelActionNotifyWraperVar;
	public FightRpcObjDeadActionNotifyWraperHelper FightRpcObjDeadActionNotifyWraperVar;
	public FightRpcFightTipsNotifyWraperHelper FightRpcFightTipsNotifyWraperVar;
	public FightRpcBuffListNotifyWraperHelper FightRpcBuffListNotifyWraperVar;
	public FightRpcReduceCDNotifyWraperHelper FightRpcReduceCDNotifyWraperVar;
	public FightRpcReliveNotifyNotifyWraperHelper FightRpcReliveNotifyNotifyWraperVar;
	public FightRpcSkillCDNotifyWraperHelper FightRpcSkillCDNotifyWraperVar;
	public FightRpcAutoCombatMonsterNotifyWraperHelper FightRpcAutoCombatMonsterNotifyWraperVar;
	public FightRpcTranslateActionNotifyWraperHelper FightRpcTranslateActionNotifyWraperVar;
	public FightRpcCantAddBuffTipNotifyWraperHelper FightRpcCantAddBuffTipNotifyWraperVar;
	public FightRpcAttackWarningNotifyWraperHelper FightRpcAttackWarningNotifyWraperVar;
	public FightRpcInterruptActionNotifyWraperHelper FightRpcInterruptActionNotifyWraperVar;
	public FightRpcSkillPrepareAskWraperHelper FightRpcSkillPrepareAskWraperVar;
	public FightRpcSkillPrepareActionNotifyWraperHelper FightRpcSkillPrepareActionNotifyWraperVar;
	public FightRpcChainMagicJumpNotifyWraperHelper FightRpcChainMagicJumpNotifyWraperVar;
	public FightRpcBlackHoleActionNotifyWraperHelper FightRpcBlackHoleActionNotifyWraperVar;
	public FightRpcLoopActionCancelAskWraperHelper FightRpcLoopActionCancelAskWraperVar;
	public FightRpcLoopActionCancelOtherNotifyWraperHelper FightRpcLoopActionCancelOtherNotifyWraperVar;
	public FightRpcSkillListNotifyWraperHelper FightRpcSkillListNotifyWraperVar;
	public FightRpcUsePetSkillAskWraperHelper FightRpcUsePetSkillAskWraperVar;
	public FightRpcRemoveModifySkillNotifyWraperHelper FightRpcRemoveModifySkillNotifyWraperVar;
	public FightRpcLinkMagicActionNotifyWraperHelper FightRpcLinkMagicActionNotifyWraperVar;
	public FightRpcMonsterInteractAskWraperHelper FightRpcMonsterInteractAskWraperVar;


	public void TestUseSkill()
	{
		FightRPC.Instance.UseSkill(FightRpcUseSkillAskWraperVar.ObjTargetId,FightRpcUseSkillAskWraperVar.SkillId,FightRpcUseSkillAskWraperVar.CastingDir,FightRpcUseSkillAskWraperVar.X,FightRpcUseSkillAskWraperVar.Y,FightRpcUseSkillAskWraperVar.Z,FightRpcUseSkillAskWraperVar.MomentIndex,FightRpcUseSkillAskWraperVar.CustomSkiData,FightRpcUseSkillAskWraperVar.CurrentPos,delegate(object obj){});
	}
	public void TestSkillPrepare()
	{
		FightRPC.Instance.SkillPrepare(FightRpcSkillPrepareAskWraperVar.SkillId,FightRpcSkillPrepareAskWraperVar.Type,delegate(object obj){});
	}
	public void TestLoopActionCancel()
	{
		FightRPC.Instance.LoopActionCancel(FightRpcLoopActionCancelAskWraperVar.SkillId,delegate(object obj){});
	}
	public void TestUsePetSkill()
	{
		FightRPC.Instance.UsePetSkill(FightRpcUsePetSkillAskWraperVar.ObjTargetId,FightRpcUsePetSkillAskWraperVar.SkillId,FightRpcUsePetSkillAskWraperVar.CastingDir,FightRpcUsePetSkillAskWraperVar.CurrentPos,FightRpcUsePetSkillAskWraperVar.TargetPos,delegate(object obj){});
	}
	public void TestMonsterInteract()
	{
		FightRPC.Instance.MonsterInteract(FightRpcMonsterInteractAskWraperVar.TargetId,delegate(object obj){});
	}


}

[CustomEditor(typeof(FightTestHelper))]
public class FightTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("UseSkill"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestUseSkill();
		}
		if (GUILayout.Button("SkillPrepare"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestSkillPrepare();
		}
		if (GUILayout.Button("LoopActionCancel"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestLoopActionCancel();
		}
		if (GUILayout.Button("UsePetSkill"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestUsePetSkill();
		}
		if (GUILayout.Button("MonsterInteract"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestMonsterInteract();
		}


    }

}
#endif