#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class eeeeTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(eeeeTestHelper))]
public class eeeeTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif