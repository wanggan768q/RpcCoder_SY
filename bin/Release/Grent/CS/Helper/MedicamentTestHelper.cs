#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class MedicamentRpcFillHpAskWraperHelper
{
	public ItemSimpleDataWraper ItemData;
}
[System.Serializable]
public class MedicamentRpcOneStepFillHpAskWraperHelper
{
	public List<ItemSimpleDataWraper> ItemData;
}
[System.Serializable]
public class MedicamentRpcClientRefreshMedicamentAskWraperHelper
{
	public RecoverMedicamentWraper Medicament;
}
[System.Serializable]
public class MedicamentRpcServerRefreshMedicamentNotifyWraperHelper
{
	public RecoverMedicamentWraper Medicament;
}
[System.Serializable]
public class MedicamentRpcSyncMedicamentDataAskWraperHelper
{
}
[System.Serializable]
public class MedicamentRpcMedicamentCDAskWraperHelper
{
}
[System.Serializable]
public class MedicamentRpcMedicamentCDNotifyNotifyWraperHelper
{
	public int LeftTime;
}



public class MedicamentTestHelper : MonoBehaviour
{
	public MedicamentRpcFillHpAskWraperHelper MedicamentRpcFillHpAskWraperVar;
	public MedicamentRpcOneStepFillHpAskWraperHelper MedicamentRpcOneStepFillHpAskWraperVar;
	public MedicamentRpcClientRefreshMedicamentAskWraperHelper MedicamentRpcClientRefreshMedicamentAskWraperVar;
	public MedicamentRpcServerRefreshMedicamentNotifyWraperHelper MedicamentRpcServerRefreshMedicamentNotifyWraperVar;
	public MedicamentRpcSyncMedicamentDataAskWraperHelper MedicamentRpcSyncMedicamentDataAskWraperVar;
	public MedicamentRpcMedicamentCDAskWraperHelper MedicamentRpcMedicamentCDAskWraperVar;
	public MedicamentRpcMedicamentCDNotifyNotifyWraperHelper MedicamentRpcMedicamentCDNotifyNotifyWraperVar;


	public void TestFillHp()
	{
		MedicamentRPC.Instance.FillHp(MedicamentRpcFillHpAskWraperVar.ItemData,delegate(object obj){});
	}
	public void TestOneStepFillHp()
	{
		MedicamentRPC.Instance.OneStepFillHp(MedicamentRpcOneStepFillHpAskWraperVar.ItemData,delegate(object obj){});
	}
	public void TestClientRefreshMedicament()
	{
		MedicamentRPC.Instance.ClientRefreshMedicament(MedicamentRpcClientRefreshMedicamentAskWraperVar.Medicament,delegate(object obj){});
	}
	public void TestSyncMedicamentData()
	{
		MedicamentRPC.Instance.SyncMedicamentData(delegate(object obj){});
	}
	public void TestMedicamentCD()
	{
		MedicamentRPC.Instance.MedicamentCD(delegate(object obj){});
	}


}

[CustomEditor(typeof(MedicamentTestHelper))]
public class MedicamentTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("FillHp"))
		{
			MedicamentTestHelper rpc = target as MedicamentTestHelper;
			if( rpc ) rpc.TestFillHp();
		}
		if (GUILayout.Button("OneStepFillHp"))
		{
			MedicamentTestHelper rpc = target as MedicamentTestHelper;
			if( rpc ) rpc.TestOneStepFillHp();
		}
		if (GUILayout.Button("ClientRefreshMedicament"))
		{
			MedicamentTestHelper rpc = target as MedicamentTestHelper;
			if( rpc ) rpc.TestClientRefreshMedicament();
		}
		if (GUILayout.Button("SyncMedicamentData"))
		{
			MedicamentTestHelper rpc = target as MedicamentTestHelper;
			if( rpc ) rpc.TestSyncMedicamentData();
		}
		if (GUILayout.Button("MedicamentCD"))
		{
			MedicamentTestHelper rpc = target as MedicamentTestHelper;
			if( rpc ) rpc.TestMedicamentCD();
		}


    }

}
#endif