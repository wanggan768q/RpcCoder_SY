#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class asdTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(asdTestHelper))]
public class asdTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif