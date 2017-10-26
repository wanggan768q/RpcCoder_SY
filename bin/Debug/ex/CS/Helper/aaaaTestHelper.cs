#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class aaaaTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(aaaaTestHelper))]
public class aaaaTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif