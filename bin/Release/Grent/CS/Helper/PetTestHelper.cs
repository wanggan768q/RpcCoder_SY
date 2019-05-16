#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class PetRpcPetSyncAskWraperHelper
{
}
[System.Serializable]
public class PetRpcUnSummonAskWraperHelper
{
}
[System.Serializable]
public class PetRpcLevelUpgradeAskWraperHelper
{
	public UInt64 Guid;
	public List<int> ItemCount;
}
[System.Serializable]
public class PetRpcStarUpgradeAskWraperHelper
{
	public UInt64 Guid;
	public UInt64 UseGuid;
}
[System.Serializable]
public class PetRpcChangeNameAskWraperHelper
{
	public UInt64 Guid;
	public string NewName;
}
[System.Serializable]
public class PetRpcInheritAskWraperHelper
{
	public UInt64 Guid;
	public UInt64 UseGuid;
}
[System.Serializable]
public class PetRpcSkillInheritAskWraperHelper
{
	public UInt64 Guid;
	public UInt64 UseGuid;
}
[System.Serializable]
public class PetRpcPassiveSkillsAskWraperHelper
{
	public UInt64 Guid;
}
[System.Serializable]
public class PetRpcStudySkillAskWraperHelper
{
	public UInt64 Guid;
	public int ItemId;
}
[System.Serializable]
public class PetRpcLockSkillAskWraperHelper
{
	public UInt64 Guid;
	public int SkillId;
}
[System.Serializable]
public class PetRpcUnLockSkillAskWraperHelper
{
	public UInt64 Guid;
	public int SkillId;
}



public class PetTestHelper : MonoBehaviour
{
	public PetRpcPetSyncAskWraperHelper PetRpcPetSyncAskWraperVar;
	public PetRpcUnSummonAskWraperHelper PetRpcUnSummonAskWraperVar;
	public PetRpcLevelUpgradeAskWraperHelper PetRpcLevelUpgradeAskWraperVar;
	public PetRpcStarUpgradeAskWraperHelper PetRpcStarUpgradeAskWraperVar;
	public PetRpcChangeNameAskWraperHelper PetRpcChangeNameAskWraperVar;
	public PetRpcInheritAskWraperHelper PetRpcInheritAskWraperVar;
	public PetRpcSkillInheritAskWraperHelper PetRpcSkillInheritAskWraperVar;
	public PetRpcPassiveSkillsAskWraperHelper PetRpcPassiveSkillsAskWraperVar;
	public PetRpcStudySkillAskWraperHelper PetRpcStudySkillAskWraperVar;
	public PetRpcLockSkillAskWraperHelper PetRpcLockSkillAskWraperVar;
	public PetRpcUnLockSkillAskWraperHelper PetRpcUnLockSkillAskWraperVar;


	public void TestPetSync()
	{
		PetRPC.Instance.PetSync(delegate(object obj){});
	}
	public void TestUnSummon()
	{
		PetRPC.Instance.UnSummon(delegate(object obj){});
	}
	public void TestLevelUpgrade()
	{
		PetRPC.Instance.LevelUpgrade(PetRpcLevelUpgradeAskWraperVar.Guid,PetRpcLevelUpgradeAskWraperVar.ItemCount,delegate(object obj){});
	}
	public void TestStarUpgrade()
	{
		PetRPC.Instance.StarUpgrade(PetRpcStarUpgradeAskWraperVar.Guid,PetRpcStarUpgradeAskWraperVar.UseGuid,delegate(object obj){});
	}
	public void TestChangeName()
	{
		PetRPC.Instance.ChangeName(PetRpcChangeNameAskWraperVar.Guid,PetRpcChangeNameAskWraperVar.NewName,delegate(object obj){});
	}
	public void TestInherit()
	{
		PetRPC.Instance.Inherit(PetRpcInheritAskWraperVar.Guid,PetRpcInheritAskWraperVar.UseGuid,delegate(object obj){});
	}
	public void TestSkillInherit()
	{
		PetRPC.Instance.SkillInherit(PetRpcSkillInheritAskWraperVar.Guid,PetRpcSkillInheritAskWraperVar.UseGuid,delegate(object obj){});
	}
	public void TestPassiveSkills()
	{
		PetRPC.Instance.PassiveSkills(PetRpcPassiveSkillsAskWraperVar.Guid,delegate(object obj){});
	}
	public void TestStudySkill()
	{
		PetRPC.Instance.StudySkill(PetRpcStudySkillAskWraperVar.Guid,PetRpcStudySkillAskWraperVar.ItemId,delegate(object obj){});
	}
	public void TestLockSkill()
	{
		PetRPC.Instance.LockSkill(PetRpcLockSkillAskWraperVar.Guid,PetRpcLockSkillAskWraperVar.SkillId,delegate(object obj){});
	}
	public void TestUnLockSkill()
	{
		PetRPC.Instance.UnLockSkill(PetRpcUnLockSkillAskWraperVar.Guid,PetRpcUnLockSkillAskWraperVar.SkillId,delegate(object obj){});
	}


}

[CustomEditor(typeof(PetTestHelper))]
public class PetTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("PetSync"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestPetSync();
		}
		if (GUILayout.Button("UnSummon"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestUnSummon();
		}
		if (GUILayout.Button("LevelUpgrade"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestLevelUpgrade();
		}
		if (GUILayout.Button("StarUpgrade"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestStarUpgrade();
		}
		if (GUILayout.Button("ChangeName"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestChangeName();
		}
		if (GUILayout.Button("Inherit"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestInherit();
		}
		if (GUILayout.Button("SkillInherit"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestSkillInherit();
		}
		if (GUILayout.Button("PassiveSkills"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestPassiveSkills();
		}
		if (GUILayout.Button("StudySkill"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestStudySkill();
		}
		if (GUILayout.Button("LockSkill"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestLockSkill();
		}
		if (GUILayout.Button("UnLockSkill"))
		{
			PetTestHelper rpc = target as PetTestHelper;
			if( rpc ) rpc.TestUnLockSkill();
		}


    }

}
#endif