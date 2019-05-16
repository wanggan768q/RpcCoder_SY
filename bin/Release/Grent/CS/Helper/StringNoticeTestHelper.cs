#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;


[System.Serializable]
public class StringNoticeRpcNoticeNotifyWraperHelper
{
	public int ConfigId;
	public List<string> Param;
}



public class StringNoticeTestHelper : MonoBehaviour
{
	public StringNoticeRpcNoticeNotifyWraperHelper StringNoticeRpcNoticeNotifyWraperVar;




}

[CustomEditor(typeof(StringNoticeTestHelper))]
public class StringNoticeTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif