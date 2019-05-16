#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class SkillRpcSkillInfoAskWraperHelper
{
}
[System.Serializable]
public class SkillRpcUpdateSkillInfoAskWraperHelper
{
	public List<ProfessionInfoWraper> ProfessionInfos;
	public int CurUseMastery;
}
[System.Serializable]
public class SkillRpcLevelUpSkillPosAskWraperHelper
{
	public int SkillPos;
	public bool IsAuto;
}
[System.Serializable]
public class SkillRpcSkillLevelInfoAskWraperHelper
{
}



public class SkillTestHelper : MonoBehaviour
{
	public SkillRpcSkillInfoAskWraperHelper SkillRpcSkillInfoAskWraperVar;
	public SkillRpcUpdateSkillInfoAskWraperHelper SkillRpcUpdateSkillInfoAskWraperVar;
	public SkillRpcLevelUpSkillPosAskWraperHelper SkillRpcLevelUpSkillPosAskWraperVar;
	public SkillRpcSkillLevelInfoAskWraperHelper SkillRpcSkillLevelInfoAskWraperVar;


	public void TestSkillInfo()
	{
		SkillRPC.Instance.SkillInfo(delegate(object obj){});
	}
	public void TestUpdateSkillInfo()
	{
		SkillRPC.Instance.UpdateSkillInfo(SkillRpcUpdateSkillInfoAskWraperVar.ProfessionInfos,SkillRpcUpdateSkillInfoAskWraperVar.CurUseMastery,delegate(object obj){});
	}
	public void TestLevelUpSkillPos()
	{
		SkillRPC.Instance.LevelUpSkillPos(SkillRpcLevelUpSkillPosAskWraperVar.SkillPos,SkillRpcLevelUpSkillPosAskWraperVar.IsAuto,delegate(object obj){});
	}
	public void TestSkillLevelInfo()
	{
		SkillRPC.Instance.SkillLevelInfo(delegate(object obj){});
	}


}

[CustomEditor(typeof(SkillTestHelper))]
public class SkillTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("SkillInfo"))
		{
			SkillTestHelper rpc = target as SkillTestHelper;
			if( rpc ) rpc.TestSkillInfo();
		}
		if (GUILayout.Button("UpdateSkillInfo"))
		{
			SkillTestHelper rpc = target as SkillTestHelper;
			if( rpc ) rpc.TestUpdateSkillInfo();
		}
		if (GUILayout.Button("LevelUpSkillPos"))
		{
			SkillTestHelper rpc = target as SkillTestHelper;
			if( rpc ) rpc.TestLevelUpSkillPos();
		}
		if (GUILayout.Button("SkillLevelInfo"))
		{
			SkillTestHelper rpc = target as SkillTestHelper;
			if( rpc ) rpc.TestSkillLevelInfo();
		}


    }

}
#endif