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
	public int ObjTargetId;
	public int SkillId;
	public int X;
	public int Y;
	public int Dir;
}



public class FightTestHelper : MonoBehaviour
{
	public FightRpcUseSkillActionNotifyWraperHelper FightRpcUseSkillActionNotifyWraperVar;


	public void TestUseSkillAction()
	{
		FightRPC.Instance.UseSkillAction(FightRpcUseSkillActionNotifyWraperVar.ObjTargetId,FightRpcUseSkillActionNotifyWraperVar.SkillId,FightRpcUseSkillActionNotifyWraperVar.X,FightRpcUseSkillActionNotifyWraperVar.Y,FightRpcUseSkillActionNotifyWraperVar.Dir);
	}


}

[CustomEditor(typeof(FightTestHelper))]
public class FightTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("UseSkillAction"))
		{
			FightTestHelper rpc = target as FightTestHelper;
			if( rpc ) rpc.TestUseSkillAction();
		}


    }

}
#endif