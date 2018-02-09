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
	public int ObjId;
	public int ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public float X;
	public float Y;
	public float Z;
	public int MomentIndex;
}
[System.Serializable]
public class FightRpcShowExpActionNotifyWraperHelper
{
	public int ObjId;
	public int Value;
}
[System.Serializable]
public class FightRpcBuffActionNotifyWraperHelper
{
	public int ObjId;
	public int TargetId;
	public int OpType;
	public int BufId;
	public int RemainTime;
	public int BuffLv;
	public int Sn;
}
[System.Serializable]
public class FightRpcStateActionNotifyWraperHelper
{
	public int ObjId;
	public int Type;
	public V3Wraper Pos;
	public int TargetPos;
}
[System.Serializable]
public class FightRpcReviveActionNotifyWraperHelper
{
	public int ObjId;
	public V3Wraper Pos;
	public int CurHp;
}
[System.Serializable]
public class FightRpcComboSkillActionNotifyWraperHelper
{
	public int ObjId;
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
	public int ObjId;
	public int CurHp;
	public int MaxHp;
}
[System.Serializable]
public class FightRpcUseSkillAskWraperHelper
{
	public int ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public float X;
	public float Y;
	public float Z;
	public int MomentIndex;
}
[System.Serializable]
public class FightRpcHurtActionNotifyWraperHelper
{
	public int ObjId;
	public int SegmentIndex;
	public int SkillId;
	public int TargetObjId;
	public int HurtValue;
	public bool IsCritical;
	public int Energy;
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


	public void TestUseSkill()
	{
		FightRPC.Instance.UseSkill(FightRpcUseSkillAskWraperVar.ObjTargetId,FightRpcUseSkillAskWraperVar.SkillId,FightRpcUseSkillAskWraperVar.CastingDir,FightRpcUseSkillAskWraperVar.X,FightRpcUseSkillAskWraperVar.Y,FightRpcUseSkillAskWraperVar.Z,FightRpcUseSkillAskWraperVar.MomentIndex,delegate(object obj){});
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


    }

}
#endif