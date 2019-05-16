#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class GameGateRpcGameGateChangeSceneNotifyWraperHelper
{
	public UInt64 RoleID;
	public int ServerID;
}



public class GameGateTestHelper : MonoBehaviour
{
	public GameGateRpcGameGateChangeSceneNotifyWraperHelper GameGateRpcGameGateChangeSceneNotifyWraperVar;




}

[CustomEditor(typeof(GameGateTestHelper))]
public class GameGateTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif