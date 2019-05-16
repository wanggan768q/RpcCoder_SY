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
	public CustomSkiDataWraper CustomSkiData;
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
	public BuffInfoWraper Info;
}
[System.Serializable]
public class FightRpcStateActionNotifyWraperHelper
{
	public int ObjId;
	public int Type;
	public Vector3Wraper Pos;
	public int TargetPos;
	public int State;
}
[System.Serializable]
public class FightRpcReviveActionNotifyWraperHelper
{
	public int ObjId;
	public Vector3Wraper Pos;
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
	public int IncrementHp;
}
[System.Serializable]
public class FightRpcUseSkillAskWraperHelper
{
	public List<int> ObjTargetId;
	public int SkillId;
	public float CastingDir;
	public float X;
	public float Y;
	public float Z;
	public int MomentIndex;
	public CustomSkiDataWraper CustomSkiData;
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
	public bool IsDodge;
	public bool IsMiss;
	public bool IsHurtState;
}
[System.Serializable]
public class FightRpcRepelActionNotifyWraperHelper
{
	public int ObjId;
	public int SegmentIndex;
	public int SkillId;
	public int TargetObjId;
	public Vector3Wraper SkiTargetPos;
	public bool IsPlayerDiaup;
}
[System.Serializable]
public class FightRpcObjDeadActionNotifyWraperHelper
{
	public int ObjId;
}
[System.Serializable]
public class FightRpcFightTipsNotifyWraperHelper
{
	public int TipsID;
	public int Durtion;
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
	public int ObjId;
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


	public void TestUseSkill()
	{
		FightRPC.Instance.UseSkill(FightRpcUseSkillAskWraperVar.ObjTargetId,FightRpcUseSkillAskWraperVar.SkillId,FightRpcUseSkillAskWraperVar.CastingDir,FightRpcUseSkillAskWraperVar.X,FightRpcUseSkillAskWraperVar.Y,FightRpcUseSkillAskWraperVar.Z,FightRpcUseSkillAskWraperVar.MomentIndex,FightRpcUseSkillAskWraperVar.CustomSkiData,delegate(object obj){});
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