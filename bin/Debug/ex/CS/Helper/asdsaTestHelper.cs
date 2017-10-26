#if UNITY_EDITOR
using UnityEngine;
using UnityEditor;
using GenPB;
using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;





public class asdsaTestHelper : MonoBehaviour
{




}

[CustomEditor(typeof(asdsaTestHelper))]
public class asdsaTester : Editor
{

    public override void OnInspectorGUI()
    {
        base.OnInspectorGUI();
        


    }

}
#endif