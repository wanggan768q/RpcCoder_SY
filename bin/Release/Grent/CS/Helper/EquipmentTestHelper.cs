#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class EquipmentRpcEquipAskWraperHelper
{
	public int Pos;
}
[System.Serializable]
public class EquipmentRpcUnEquipAskWraperHelper
{
	public int SlotType;
}
[System.Serializable]
public class EquipmentRpcSwitchEquipSetAskWraperHelper
{
	public int To_index;
}
[System.Serializable]
public class EquipmentRpcSyncEquipAskWraperHelper
{
}
[System.Serializable]
public class EquipmentRpcResonanceUnlockAskWraperHelper
{
	public int ConfId;
}
[System.Serializable]
public class EquipmentRpcEquipDoResonanceAskWraperHelper
{
	public int ConfId;
}
[System.Serializable]
public class EquipmentRpcEquipResonanceSaveAskWraperHelper
{
	public int ConfId;
}
[System.Serializable]
public class EquipmentRpcEquipResonanceSyncAskWraperHelper
{
}
[System.Serializable]
public class EquipmentRpcEquipWashSyncAskWraperHelper
{
}
[System.Serializable]
public class EquipmentRpcEquipWashAskWraperHelper
{
	public UInt64 Guid;
	public List<int> LockedIndex;
}
[System.Serializable]
public class EquipmentRpcEquipWashSaveAskWraperHelper
{
	public UInt64 Guid;
}
[System.Serializable]
public class EquipmentRpcEquipBuildSyncAskWraperHelper
{
}
[System.Serializable]
public class EquipmentRpcEquipBuildAskWraperHelper
{
	public int Level;
	public int Occupation;
	public int Slot_type;
}
[System.Serializable]
public class EquipmentRpcGetPlayerInfoAskWraperHelper
{
	public UInt64 Player_guid;
}
[System.Serializable]
public class EquipmentRpcEquipInheritAskWraperHelper
{
	public UInt64 ToGuid;
	public UInt64 FromGuid;
}



public class EquipmentTestHelper : MonoBehaviour
{
	public EquipmentRpcEquipAskWraperHelper EquipmentRpcEquipAskWraperVar;
	public EquipmentRpcUnEquipAskWraperHelper EquipmentRpcUnEquipAskWraperVar;
	public EquipmentRpcSwitchEquipSetAskWraperHelper EquipmentRpcSwitchEquipSetAskWraperVar;
	public EquipmentRpcSyncEquipAskWraperHelper EquipmentRpcSyncEquipAskWraperVar;
	public EquipmentRpcResonanceUnlockAskWraperHelper EquipmentRpcResonanceUnlockAskWraperVar;
	public EquipmentRpcEquipDoResonanceAskWraperHelper EquipmentRpcEquipDoResonanceAskWraperVar;
	public EquipmentRpcEquipResonanceSaveAskWraperHelper EquipmentRpcEquipResonanceSaveAskWraperVar;
	public EquipmentRpcEquipResonanceSyncAskWraperHelper EquipmentRpcEquipResonanceSyncAskWraperVar;
	public EquipmentRpcEquipWashSyncAskWraperHelper EquipmentRpcEquipWashSyncAskWraperVar;
	public EquipmentRpcEquipWashAskWraperHelper EquipmentRpcEquipWashAskWraperVar;
	public EquipmentRpcEquipWashSaveAskWraperHelper EquipmentRpcEquipWashSaveAskWraperVar;
	public EquipmentRpcEquipBuildSyncAskWraperHelper EquipmentRpcEquipBuildSyncAskWraperVar;
	public EquipmentRpcEquipBuildAskWraperHelper EquipmentRpcEquipBuildAskWraperVar;
	public EquipmentRpcGetPlayerInfoAskWraperHelper EquipmentRpcGetPlayerInfoAskWraperVar;
	public EquipmentRpcEquipInheritAskWraperHelper EquipmentRpcEquipInheritAskWraperVar;


	public void TestEquip()
	{
		EquipmentRPC.Instance.Equip(EquipmentRpcEquipAskWraperVar.Pos,delegate(object obj){});
	}
	public void TestUnEquip()
	{
		EquipmentRPC.Instance.UnEquip(EquipmentRpcUnEquipAskWraperVar.SlotType,delegate(object obj){});
	}
	public void TestSwitchEquipSet()
	{
		EquipmentRPC.Instance.SwitchEquipSet(EquipmentRpcSwitchEquipSetAskWraperVar.To_index,delegate(object obj){});
	}
	public void TestSyncEquip()
	{
		EquipmentRPC.Instance.SyncEquip(delegate(object obj){});
	}
	public void TestResonanceUnlock()
	{
		EquipmentRPC.Instance.ResonanceUnlock(EquipmentRpcResonanceUnlockAskWraperVar.ConfId,delegate(object obj){});
	}
	public void TestEquipDoResonance()
	{
		EquipmentRPC.Instance.EquipDoResonance(EquipmentRpcEquipDoResonanceAskWraperVar.ConfId,delegate(object obj){});
	}
	public void TestEquipResonanceSave()
	{
		EquipmentRPC.Instance.EquipResonanceSave(EquipmentRpcEquipResonanceSaveAskWraperVar.ConfId,delegate(object obj){});
	}
	public void TestEquipResonanceSync()
	{
		EquipmentRPC.Instance.EquipResonanceSync(delegate(object obj){});
	}
	public void TestEquipWashSync()
	{
		EquipmentRPC.Instance.EquipWashSync(delegate(object obj){});
	}
	public void TestEquipWash()
	{
		EquipmentRPC.Instance.EquipWash(EquipmentRpcEquipWashAskWraperVar.Guid,EquipmentRpcEquipWashAskWraperVar.LockedIndex,delegate(object obj){});
	}
	public void TestEquipWashSave()
	{
		EquipmentRPC.Instance.EquipWashSave(EquipmentRpcEquipWashSaveAskWraperVar.Guid,delegate(object obj){});
	}
	public void TestEquipBuildSync()
	{
		EquipmentRPC.Instance.EquipBuildSync(delegate(object obj){});
	}
	public void TestEquipBuild()
	{
		EquipmentRPC.Instance.EquipBuild(EquipmentRpcEquipBuildAskWraperVar.Level,EquipmentRpcEquipBuildAskWraperVar.Occupation,EquipmentRpcEquipBuildAskWraperVar.Slot_type,delegate(object obj){});
	}
	public void TestGetPlayerInfo()
	{
		EquipmentRPC.Instance.GetPlayerInfo(EquipmentRpcGetPlayerInfoAskWraperVar.Player_guid,delegate(object obj){});
	}
	public void TestEquipInherit()
	{
		EquipmentRPC.Instance.EquipInherit(EquipmentRpcEquipInheritAskWraperVar.ToGuid,EquipmentRpcEquipInheritAskWraperVar.FromGuid,delegate(object obj){});
	}


}

[CustomEditor(typeof(EquipmentTestHelper))]
public class EquipmentTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Equip"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquip();
		}
		if (GUILayout.Button("UnEquip"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestUnEquip();
		}
		if (GUILayout.Button("SwitchEquipSet"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestSwitchEquipSet();
		}
		if (GUILayout.Button("SyncEquip"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestSyncEquip();
		}
		if (GUILayout.Button("ResonanceUnlock"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestResonanceUnlock();
		}
		if (GUILayout.Button("EquipDoResonance"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipDoResonance();
		}
		if (GUILayout.Button("EquipResonanceSave"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipResonanceSave();
		}
		if (GUILayout.Button("EquipResonanceSync"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipResonanceSync();
		}
		if (GUILayout.Button("EquipWashSync"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipWashSync();
		}
		if (GUILayout.Button("EquipWash"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipWash();
		}
		if (GUILayout.Button("EquipWashSave"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipWashSave();
		}
		if (GUILayout.Button("EquipBuildSync"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipBuildSync();
		}
		if (GUILayout.Button("EquipBuild"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipBuild();
		}
		if (GUILayout.Button("GetPlayerInfo"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestGetPlayerInfo();
		}
		if (GUILayout.Button("EquipInherit"))
		{
			EquipmentTestHelper rpc = target as EquipmentTestHelper;
			if( rpc ) rpc.TestEquipInherit();
		}


    }

}
#endif