#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


$RpcAskWraperHelper$


public class $Template$TestHelper : MonoBehaviour
{
$RpcAskWraperVar$

$CallRpcFunction$

}

[CustomEditor(typeof($Template$TestHelper))]
public class $Template$Tester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        
$CallRpcButton$

    }

}
#endif