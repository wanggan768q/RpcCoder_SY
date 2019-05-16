#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class PetCaptureRpcCaptureAskWraperHelper
{
	public int BallType;
}
[System.Serializable]
public class PetCaptureRpcCapturePetNotifyWraperHelper
{
	public int PetId;
	public string NickName;
	public int RoleId;
	public int CreatureId;
}
[System.Serializable]
public class PetCaptureRpcLoginNotifyWraperHelper
{
	public int WayPoint;
	public int SceneId;
	public Vector3Wraper Pos;
}
[System.Serializable]
public class PetCaptureRpcPetLocationAskWraperHelper
{
	public int LineId;
}



public class PetCaptureTestHelper : MonoBehaviour
{
	public PetCaptureRpcCaptureAskWraperHelper PetCaptureRpcCaptureAskWraperVar;
	public PetCaptureRpcCapturePetNotifyWraperHelper PetCaptureRpcCapturePetNotifyWraperVar;
	public PetCaptureRpcLoginNotifyWraperHelper PetCaptureRpcLoginNotifyWraperVar;
	public PetCaptureRpcPetLocationAskWraperHelper PetCaptureRpcPetLocationAskWraperVar;


	public void TestCapture()
	{
		PetCaptureRPC.Instance.Capture(PetCaptureRpcCaptureAskWraperVar.BallType,delegate(object obj){});
	}
	public void TestPetLocation()
	{
		PetCaptureRPC.Instance.PetLocation(PetCaptureRpcPetLocationAskWraperVar.LineId,delegate(object obj){});
	}


}

[CustomEditor(typeof(PetCaptureTestHelper))]
public class PetCaptureTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
		if (GUILayout.Button("Capture"))
		{
			PetCaptureTestHelper rpc = target as PetCaptureTestHelper;
			if( rpc ) rpc.TestCapture();
		}
		if (GUILayout.Button("PetLocation"))
		{
			PetCaptureTestHelper rpc = target as PetCaptureTestHelper;
			if( rpc ) rpc.TestPetLocation();
		}


    }

}
#endif