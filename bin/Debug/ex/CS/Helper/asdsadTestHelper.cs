﻿#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class asdsadTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(asdsadTestHelper))]
public class asdsadTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif