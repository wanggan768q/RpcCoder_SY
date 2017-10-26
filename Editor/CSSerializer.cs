namespace Editor
{
    using System;
    using System.Collections;
    using System.Diagnostics;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class CSSerializer
    {
        public static void GenActionWraperCode(Module m, DataStruct ds, ref string ActionEnum, ref string DefineActionPool, ref string PoolCreateAction, ref string PoolStoreAction, ref string ActionDeserialize, ref string ActionClass, ref string NEW_ACTION, ref string DEFINE_ACTION)
        {
            bool flag = false;
            string newValue = "";
            if (ds.ProtoType == DataStruct.protoTypeE.RpcProto)
            {
                int index = ds.StructName.IndexOf("Action");
                if ((index + 6) == ds.StructName.Length)
                {
                    flag = true;
                    newValue = ds.StructName.Substring(0, index);
                }
            }
            if (flag)
            {
                bool flag2 = false;
                string str2 = "";
                if (((ds.ProtoType == DataStruct.protoTypeE.RpcProto) && (ds.StructName.IndexOf("Rpc") == 0)) && ((ds.StructName.IndexOf("Ask") > 0) || (ds.StructName.IndexOf("Notify") > 0)))
                {
                    flag2 = true;
                }
                if (!flag2)
                {
                    string str3 = "";
                    StreamReader reader = new StreamReader("./Template/ActionTmpt.cs", Encoding.GetEncoding("GBK"));
                    str3 = reader.ReadToEnd();
                    reader.Close();
                    string str4 = ds.getFullName() + "Wraper" + str2;
                    string str5 = "ACTION_" + newValue.ToUpper();
                    newValue = newValue + "Action";
                    str3 = str3.Replace("$CNName$", ds.CNName).Replace("$ActionName$", newValue).Replace("$WraperName$", str4).Replace("$ACTION_ENUM$", str5);
                    string str6 = ActionEnum;
                    ActionEnum = str6 + "        " + str5 + ", //" + ds.CNName + "\r\n";
                    string str7 = DefineActionPool;
                    DefineActionPool = str7 + "        private Ex.ObjectPool<" + newValue + "> " + newValue + "Pool = new Ex.ObjectPool<" + newValue + ">();\r\n";
                    string str8 = PoolCreateAction;
                    PoolCreateAction = str8 + "            if (actionType == KernelActionE." + str5 + ") return " + newValue + "Pool.New();\r\n";
                    string str9 = PoolStoreAction;
                    PoolStoreAction = str9 + "            if (action is " + newValue + ") " + newValue + "Pool.Store(action as " + newValue + ");\r\n";
                    ActionDeserialize = ActionDeserialize + "                    case KernelActionE." + str5 + ":\r\n";
                    string str10 = ActionDeserialize;
                    ActionDeserialize = str10 + "                        " + newValue + " obj" + newValue + " = ActionPoolManager.GetInstance().CreateAction(KernelActionE." + str5 + ") as " + newValue + ";\r\n";
                    ActionDeserialize = ActionDeserialize + "                        obj" + newValue + ".Create(buf);\r\n";
                    ActionDeserialize = ActionDeserialize + "                        return obj" + newValue + ";\r\n";
                    string str11 = DEFINE_ACTION;
                    DEFINE_ACTION = str11 + "DEFINE_ACTION(" + newValue + ", " + str4 + "," + str5 + ");\r\n";
                    string str12 = NEW_ACTION;
                    NEW_ACTION = str12 + "NEW_ACTION(" + str5 + ", " + newValue + ");\r\n";
                    ActionClass = ActionClass + str3;
                }
            }
        }

        public static void GenClassWraperCode(Module m, DataStruct ds, ref string strWraper, ref string masterDataWraper, ref string AskWraperHelper, ref string AskWraperVar)
        {
            string str10;
            string str = "//$CNName$封装类\r\n[System.Serializable]\r\npublic class $WraperName$\r\n{\r\n";
            if ((ds.ProtoType == DataStruct.protoTypeE.RpcProto) && ((ds.StructName.IndexOf("Action") + 6) == ds.StructName.Length))
            {
                str = "//$CNName$封装类\r\n[System.Serializable]\r\npublic class $WraperName$ : BattleKernel.Action\r\n{\r\n";
            }
            string str2 = "";
            StreamReader reader = new StreamReader("./Template/WraperTmpt.cs", Encoding.GetEncoding("GBK"));
            str2 = reader.ReadToEnd();
            reader.Close();
            str = str + str2 + "\r\n};\r\n";
            bool flag = false;
            string str3 = "";
            if (ds.ProtoType == DataStruct.protoTypeE.SyncProto)
            {
                str3 = "V" + m.SyncDataVersion;
            }
            if (((ds.ProtoType == DataStruct.protoTypeE.RpcProto) && (ds.StructName.IndexOf("Rpc") == 0)) && ((ds.StructName.IndexOf("Ask") > 0) || (ds.StructName.IndexOf("Notify") > 0)))
            {
                flag = true;
            }
            bool flag2 = false;
            string newValue = ds.getFullName() + "Wraper" + str3;
            string str5 = ds.getFullName() + str3;
            string str6 = "";
            string str7 = "";
            string str8 = "";
            string str9 = "";
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
            {
                flag2 = true;
                newValue = ds.getModuleName() + "Data";
            }
            if (flag)
            {
                AskWraperHelper = AskWraperHelper + "[System.Serializable]\r\npublic class " + newValue + "Helper\r\n{\r\n";
                str10 = AskWraperVar;
                AskWraperVar = str10 + "\tpublic " + newValue + "Helper " + newValue + "Var;\r\n";
            }
            foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
            {
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    if (descriptor.GetTypeEnum() == 3)
                    {
                        string str11 = str8;
                        str8 = str11 + "\t\tm_" + descriptor.FieldName + ".FromPB(v." + descriptor.FieldName + ");\r\n";
                        string str12 = str7;
                        str7 = str12 + "\t\tv." + descriptor.FieldName + " = m_" + descriptor.FieldName + ".ToPB();\r\n";
                    }
                    else
                    {
                        string str13 = str8;
                        str8 = str13 + "\t\tm_" + descriptor.FieldName + " = v." + descriptor.FieldName + ";\r\n";
                        string str14 = str7;
                        str7 = str14 + "\t\tv." + descriptor.FieldName + " = m_" + descriptor.FieldName + ";\r\n";
                    }
                    str9 = str9 + "\t//" + descriptor.CNName + "\r\n";
                    string str15 = str9;
                    str9 = str15 + "\tpublic " + descriptor.ToGetCSFieldType() + " m_" + descriptor.FieldName + ";\r\n";
                    if (flag)
                    {
                        string str16 = AskWraperHelper;
                        AskWraperHelper = str16 + "\tpublic " + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName + ";\r\n";
                    }
                    string str17 = str9;
                    str9 = str17 + "\tpublic " + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName + "\r\n\t{\r\n\t\tget { return m_" + descriptor.FieldName + ";}\r\n\t\tset { m_" + descriptor.FieldName + " = value; }\r\n\t}\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        if (descriptor.FieldType == "float")
                        {
                            string str18 = str6;
                            str6 = str18 + "\t\t m_" + descriptor.FieldName + " = (float)" + descriptor.DefaultValue + ";\r\n";
                        }
                        else
                        {
                            string str19 = str6;
                            str6 = str19 + "\t\t m_" + descriptor.FieldName + " = " + descriptor.DefaultValue + ";\r\n";
                        }
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        if (descriptor.FieldType == "bytes")
                        {
                            str6 = str6 + "\t\t m_" + descriptor.FieldName + " = new byte[0];\r\n";
                        }
                        else
                        {
                            str6 = str6 + "\t\t m_" + descriptor.FieldName + " = \"\";\r\n";
                        }
                    }
                    else
                    {
                        string str20 = str6;
                        str6 = str20 + "\t\t m_" + descriptor.FieldName + " = new " + descriptor.ToGetCSFieldType() + "();\r\n";
                    }
                }
                else
                {
                    str8 = str8 + "\t\tm_" + descriptor.FieldName + ".Clear();\r\n";
                    str8 = str8 + "\t\tfor( int i=0; i<v." + descriptor.FieldName + ".Count; i++)\r\n";
                    if (descriptor.GetTypeEnum() != 3)
                    {
                        string str21 = str8;
                        str8 = str21 + "\t\t\tm_" + descriptor.FieldName + ".Add(v." + descriptor.FieldName + "[i]);\r\n";
                    }
                    else
                    {
                        string str22 = str8;
                        str8 = str22 + "\t\t\tm_" + descriptor.FieldName + ".Add( new " + descriptor.ToGetCSFieldType() + "());\r\n";
                        str8 = str8 + "\t\tfor( int i=0; i<v." + descriptor.FieldName + ".Count; i++)\r\n";
                        string str23 = str8;
                        str8 = str23 + "\t\t\tm_" + descriptor.FieldName + "[i].FromPB(v." + descriptor.FieldName + "[i]);\r\n";
                    }
                    string str24 = str6;
                    str6 = str24 + "\t\tm_" + descriptor.FieldName + " = new List<" + descriptor.ToGetCSFieldType() + ">();\r\n";
                    str9 = str9 + "\t//" + descriptor.CNName + "\r\n";
                    string str25 = str9;
                    str9 = str25 + "\tpublic List<" + descriptor.ToGetCSFieldType() + "> m_" + descriptor.FieldName + ";\r\n";
                    if (flag)
                    {
                        string str26 = AskWraperHelper;
                        AskWraperHelper = str26 + "\tpublic List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName + ";\r\n";
                    }
                    string str27 = str9;
                    str9 = str27 + "\tpublic int Size" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ".Count;\r\n\t}\r\n";
                    string str28 = str9;
                    str9 = str28 + "\tpublic List<" + descriptor.ToGetCSFieldType() + "> Get" + descriptor.FieldName + "()\r\n\t{\r\n";
                    str9 = str9 + "\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                    string str29 = str9;
                    str9 = str29 + "\tpublic " + descriptor.ToGetCSFieldType() + " Get" + descriptor.FieldName + "(int Index)\r\n\t{\r\n";
                    str9 = str9 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".Count)\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        str9 = str9 + "\t\t\treturn " + descriptor.DefaultValue + ";\r\n";
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        if (descriptor.IsBytesField)
                        {
                            str9 = str9 + "\t\t\treturn new byte[0];\r\n";
                        }
                        else
                        {
                            str9 = str9 + "\t\t\treturn \"\";\r\n";
                        }
                    }
                    else
                    {
                        str9 = str9 + "\t\t\treturn new " + descriptor.ToGetCSFieldType() + "();\r\n";
                    }
                    str9 = str9 + "\t\treturn m_" + descriptor.FieldName + "[Index];\r\n\t}\r\n";
                    string str30 = str9;
                    str9 = str30 + "\tpublic void Set" + descriptor.FieldName + "( List<" + descriptor.ToGetCSFieldType() + "> v )\r\n\t{\r\n";
                    str9 = str9 + "\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                    string str31 = str9;
                    str9 = str31 + "\tpublic void Set" + descriptor.FieldName + "( int Index, " + descriptor.ToGetCSFieldType() + " v )\r\n\t{\r\n";
                    str9 = str9 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".Count)\r\n\t\t\treturn;\r\n";
                    str9 = str9 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        string str32 = str9;
                        str9 = str32 + "\tpublic void Add" + descriptor.FieldName + "( " + descriptor.ToGetCSFieldType() + " v=" + descriptor.DefaultValue + " )\r\n\t{\r\n";
                        str9 = str9 + "\t\tm_" + descriptor.FieldName + ".Add(v);\r\n\t}\r\n";
                    }
                    else
                    {
                        str10 = str9;
                        str9 = str10 + "\tpublic void Add" + descriptor.FieldName + "( " + descriptor.ToGetCSFieldType() + " v )\r\n\t{\r\n";
                        str9 = str9 + "\t\tm_" + descriptor.FieldName + ".Add(v);\r\n\t}\r\n";
                    }
                    str9 = str9 + "\tpublic void Clear" + descriptor.FieldName + "( )\r\n\t{\r\n";
                    str9 = str9 + "\t\tm_" + descriptor.FieldName + ".Clear();\r\n\t}\r\n";
                    if (descriptor.GetTypeEnum() != 3)
                    {
                        str10 = str7;
                        str7 = str10 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".Count; i++)\r\n\t\t\tv." + descriptor.FieldName + ".Add( m_" + descriptor.FieldName + "[i]);\r\n";
                    }
                    else
                    {
                        str10 = str7;
                        str7 = str10 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".Count; i++)\r\n\t\t\tv." + descriptor.FieldName + ".Add( m_" + descriptor.FieldName + "[i].ToPB());\r\n";
                    }
                }
            }
            if (flag)
            {
                AskWraperHelper = AskWraperHelper + "}\r\n";
            }
            str = str.Replace("$CNName$", ds.CNName).Replace("$WraperName$", newValue).Replace("$PBName$", str5).Replace("$ConstructField$", str6).Replace("$ToPBField$", str7).Replace("$InitFuncField$", str8).Replace("$GetSetSizeField$", str9);
            str2 = str2.Replace("$CNName$", ds.CNName).Replace("$WraperName$", newValue).Replace("$PBName$", str5).Replace("$ConstructField$", str6).Replace("$ToPBField$", str7).Replace("$InitFuncField$", str8).Replace("$GetSetSizeField$", str9);
            if (flag2)
            {
                masterDataWraper = masterDataWraper + str2;
            }
            else
            {
                strWraper = strWraper + str;
            }
        }

        public static void GenClassWraperCode2(Module m, DataStruct ds, ref string strWraper, ref string masterDataWraper, ref string AskWraperHelper, ref string AskWraperVar)
        {
            string str = "//$CNName$封装类\r\n[System.Serializable]\r\npublic class $WraperName$\r\n{\r\n";
            string str2 = "";
            StreamReader reader = new StreamReader("./Template/WraperTmpt.cs", Encoding.GetEncoding("GBK"));
            str2 = reader.ReadToEnd();
            reader.Close();
            str = str + str2 + "\r\n};\r\n";
            bool flag = false;
            string str3 = "";
            if (ds.ProtoType == DataStruct.protoTypeE.SyncProto)
            {
                str3 = "V" + m.SyncDataVersion;
            }
            if (((ds.ProtoType == DataStruct.protoTypeE.RpcProto) && (ds.StructName.IndexOf("Rpc") == 0)) && ((ds.StructName.IndexOf("Ask") > 0) || (ds.StructName.IndexOf("Notify") > 0)))
            {
                flag = true;
            }
            bool flag2 = false;
            string newValue = ds.getFullName() + "Wraper" + str3;
            string str5 = ds.getFullName() + str3;
            string str6 = "";
            string str7 = "";
            string str8 = "";
            string str9 = "";
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.SyncToClient))
            {
                flag2 = true;
                newValue = ds.getModuleName() + "Data";
            }
            if (flag)
            {
                AskWraperHelper = AskWraperHelper + "[System.Serializable]\r\npublic class " + newValue + "Helper\r\n{\r\n";
                string str10 = AskWraperVar;
                AskWraperVar = str10 + "\tpublic " + newValue + "Helper " + newValue + "Var;\r\n";
            }
            foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
            {
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    if (descriptor.GetTypeEnum() == 3)
                    {
                        string str11 = str8;
                        str8 = str11 + "\t\t" + descriptor.FieldName + ".FromPB(v." + descriptor.FieldName + ");\r\n";
                        string str12 = str7;
                        str7 = str12 + "\t\tv." + descriptor.FieldName + " = " + descriptor.FieldName + ".ToPB();\r\n";
                    }
                    else
                    {
                        string str13 = str8;
                        str8 = str13 + "\t\t" + descriptor.FieldName + " = v." + descriptor.FieldName + ";\r\n";
                        string str14 = str7;
                        str7 = str14 + "\t\tv." + descriptor.FieldName + " = " + descriptor.FieldName + ";\r\n";
                    }
                    str9 = str9 + "\t//" + descriptor.CNName + "\r\n";
                    string str15 = str9;
                    str9 = str15 + "\tpublic " + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName + ";\r\n";
                    if (flag)
                    {
                        string str16 = AskWraperHelper;
                        AskWraperHelper = str16 + "\tpublic " + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName + ";\r\n";
                    }
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        if (descriptor.FieldType == "float")
                        {
                            string str17 = str6;
                            str6 = str17 + "\t\t" + descriptor.FieldName + " = (float)" + descriptor.DefaultValue + ";\r\n";
                        }
                        else
                        {
                            string str18 = str6;
                            str6 = str18 + "\t\t" + descriptor.FieldName + " = " + descriptor.DefaultValue + ";\r\n";
                        }
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        if (descriptor.FieldType == "bytes")
                        {
                            str6 = str6 + "\t\t " + descriptor.FieldName + " = new byte[0];\r\n";
                        }
                        else
                        {
                            str6 = str6 + "\t\t " + descriptor.FieldName + " = \"\";\r\n";
                        }
                    }
                    else
                    {
                        string str19 = str6;
                        str6 = str19 + "\t\t " + descriptor.FieldName + " = new " + descriptor.ToGetCSFieldType() + "();\r\n";
                    }
                }
                else
                {
                    str8 = str8 + "\t\t" + descriptor.FieldName + ".Clear();\r\n";
                    str8 = str8 + "\t\tfor( int i=0; i<v." + descriptor.FieldName + ".Count; i++)\r\n";
                    if (descriptor.GetTypeEnum() != 3)
                    {
                        string str20 = str8;
                        str8 = str20 + "\t\t\t" + descriptor.FieldName + ".Add(v." + descriptor.FieldName + "[i]);\r\n";
                    }
                    else
                    {
                        string str21 = str8;
                        str8 = str21 + "\t\t\t" + descriptor.FieldName + ".Add( new " + descriptor.ToGetCSFieldType() + "());\r\n";
                        str8 = str8 + "\t\tfor( int i=0; i<v." + descriptor.FieldName + ".Count; i++)\r\n";
                        string str22 = str8;
                        str8 = str22 + "\t\t\t" + descriptor.FieldName + "[i].FromPB(v." + descriptor.FieldName + "[i]);\r\n";
                    }
                    string str23 = str6;
                    str6 = str23 + "\t\t" + descriptor.FieldName + " = new List<" + descriptor.ToGetCSFieldType() + ">();\r\n";
                    str9 = str9 + "\t//" + descriptor.CNName + "\r\n";
                    string str24 = str9;
                    str9 = str24 + "\tpublic List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName + ";\r\n";
                    if (flag)
                    {
                        string str25 = AskWraperHelper;
                        AskWraperHelper = str25 + "\tpublic List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName + ";\r\n";
                    }
                    if (descriptor.GetTypeEnum() != 3)
                    {
                        string str26 = str7;
                        str7 = str26 + "\t\tfor (int i=0; i<(int)" + descriptor.FieldName + ".Count; i++)\r\n\t\t\tv." + descriptor.FieldName + ".Add( " + descriptor.FieldName + "[i]);\r\n";
                    }
                    else
                    {
                        string str27 = str7;
                        str7 = str27 + "\t\tfor (int i=0; i<(int)" + descriptor.FieldName + ".Count; i++)\r\n\t\t\tv." + descriptor.FieldName + ".Add( " + descriptor.FieldName + "[i].ToPB());\r\n";
                    }
                }
            }
            if (flag)
            {
                AskWraperHelper = AskWraperHelper + "}\r\n";
            }
            str = str.Replace("$CNName$", ds.CNName).Replace("$WraperName$", newValue).Replace("$PBName$", str5).Replace("$ConstructField$", str6).Replace("$ToPBField$", str7).Replace("$InitFuncField$", str8).Replace("$GetSetSizeField$", str9);
            str2 = str2.Replace("$CNName$", ds.CNName).Replace("$WraperName$", newValue).Replace("$PBName$", str5).Replace("$ConstructField$", str6).Replace("$ToPBField$", str7).Replace("$InitFuncField$", str8).Replace("$GetSetSizeField$", str9);
            if (flag2)
            {
                masterDataWraper = masterDataWraper + str2;
            }
            else
            {
                strWraper = strWraper + str;
            }
        }

        public static void GenClientFrameCode(Module m, Module.OperaterItem operate, int hasCode, ref string NotifyCBDelegate, ref string Operations)
        {
            if ((hasCode == 2) || (hasCode == 4))
            {
                DataStruct struct2 = null;
                foreach (Module.OperaterItem.SubOperaterItem item in operate.subOperateItem)
                {
                    if ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct2);
                    }
                }
                Operations = Operations + "\t/**\r\n";
                string str = Operations;
                Operations = str + "\t*" + m.CNName + "-->" + operate.CNName + " RPC请求\r\n";
                Operations = Operations + "\t*/\r\n";
                Operations = Operations + "\tprivate IEnumerator RequestNet_" + operate.Name + "(";
                for (int i = 0; i < struct2.fieldItem.Count; i++)
                {
                    DataStruct.FieldDescriptor descriptor = (DataStruct.FieldDescriptor) struct2.fieldItem[i];
                    if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                    {
                        Operations = Operations + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName;
                    }
                    else
                    {
                        string str2 = Operations;
                        Operations = str2 + "List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName;
                    }
                    if (i < (struct2.fieldItem.Count - 1))
                    {
                        Operations = Operations + ",";
                    }
                }
                Operations = Operations + "){\r\n";
                Operations = Operations + "\t\tif (isRequestNet)\r\n\t\t\tyield break;\r\n\t\tisRequestNet = true;\r\n";
                string str3 = Operations;
                Operations = str3 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper notify = new " + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper();\r\n";
                for (int j = 0; j < struct2.fieldItem.Count; j++)
                {
                    DataStruct.FieldDescriptor descriptor2 = (DataStruct.FieldDescriptor) struct2.fieldItem[j];
                    string str4 = Operations;
                    Operations = str4 + "\t\tnotify." + descriptor2.FieldName + " = " + descriptor2.FieldName + ";\r\n";
                }
                Operations = Operations + "\t\tEx.Logger.Log (\"------------------------------------->\" + this.GetType()+\"->RequestNet_" + operate.Name + " notify\");\r\n";
                string str5 = Operations;
                Operations = str5 + "\t\tyield return StartCoroutine (" + m.ModuleName + "RPC.Instance." + operate.Name + "(notify));\r\n";
                Operations = Operations + "\t\tisRequestNet = false;\r\n\t}\r\n";
            }
            if ((hasCode == 3) || (hasCode == 4))
            {
                string str6 = NotifyCBDelegate;
                NotifyCBDelegate = str6 + "\t\t" + m.ModuleName + "RPC." + operate.Name + "CBDelegate = RequestNet_" + operate.Name + "_Notify;\r\n";
                DataStruct struct3 = null;
                foreach (Module.OperaterItem.SubOperaterItem item2 in operate.subOperateItem)
                {
                    if ((item2.Type == Module.OperateType.OP_SERVER_NOTIFY) || (item2.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item2.DataStructName, out struct3);
                    }
                }
                Operations = Operations + "\t/**\r\n";
                string str7 = Operations;
                Operations = str7 + "\t*" + m.CNName + "-->" + operate.CNName + " 提醒\r\n";
                Operations = Operations + "\t*/\r\n";
                Operations = Operations + "\tprivate void RequestNet_" + operate.Name + "_Notify(object notifyMsg){\r\n";
                string str8 = Operations;
                Operations = str8 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper notifyPBWraper = notifyMsg as " + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper;\r\n";
                Operations = Operations + "\t}\r\n";
            }
            if (hasCode == 1)
            {
                DataStruct struct4 = null;
                foreach (Module.OperaterItem.SubOperaterItem item3 in operate.subOperateItem)
                {
                    if (item3.Type == Module.OperateType.OP_ASK)
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item3.DataStructName, out struct4);
                    }
                }
                Operations = Operations + "\t/**\r\n";
                string str9 = Operations;
                Operations = str9 + "\t*" + m.CNName + "-->" + operate.CNName + " RPC请求\r\n";
                Operations = Operations + "\t*/\r\n";
                Operations = Operations + "\tprivate IEnumerator RequestNet_" + operate.Name + "(";
                for (int k = 0; k < struct4.fieldItem.Count; k++)
                {
                    DataStruct.FieldDescriptor descriptor3 = (DataStruct.FieldDescriptor) struct4.fieldItem[k];
                    if (descriptor3.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                    {
                        Operations = Operations + descriptor3.ToGetCSFieldType() + " " + descriptor3.FieldName;
                    }
                    else
                    {
                        string str10 = Operations;
                        Operations = str10 + "List<" + descriptor3.ToGetCSFieldType() + "> " + descriptor3.FieldName;
                    }
                    if (k < (struct4.fieldItem.Count - 1))
                    {
                        Operations = Operations + ",";
                    }
                }
                Operations = Operations + "){\r\n";
                Operations = Operations + "\t\tif (isRequestNet)\r\n\t\t\tyield break;\r\n\t\tisRequestNet = true;\r\n";
                string str11 = Operations;
                Operations = str11 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "AskWraper ask = new " + m.ModuleName + "Rpc" + operate.Name + "AskWraper();\r\n";
                string str12 = Operations;
                Operations = str12 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "ReplyWraper reply = new " + m.ModuleName + "Rpc" + operate.Name + "ReplyWraper();\r\n";
                for (int n = 0; n < struct4.fieldItem.Count; n++)
                {
                    DataStruct.FieldDescriptor descriptor4 = (DataStruct.FieldDescriptor) struct4.fieldItem[n];
                    string str13 = Operations;
                    Operations = str13 + "\t\task." + descriptor4.FieldName + " = " + descriptor4.FieldName + ";\r\n";
                }
                Operations = Operations + "\t\tEx.Logger.Log (\"------------------------------------->\" + this.GetType()+\"->RequestNet_" + operate.Name + " ask\");\r\n";
                string str14 = Operations;
                Operations = str14 + "\t\tyield return StartCoroutine (" + m.ModuleName + "RPC.Instance." + operate.Name + "(ask, reply));\r\n";
                Operations = Operations + "\t\tEx.Logger.Log (\"<-----------------------------------------\" + this.GetType() + \"->RequestNet_" + operate.Name + " reply.Result= \"+reply.Result);\r\n";
                Operations = Operations + "\t\tif (reply.Result == 0) {\r\n\t\t}\r\n\t\telse {\r\n\t\t\tErrorNotify(reply.Result);\r\n\t\t}\r\n\t\tisRequestNet = false;\r\n\t}\r\n";
            }
        }

        private static void GenInteractRpc(Module m, Module.OperaterItem operate, int hasCode, ref string interactRpc, ref string callFunction, ref string callButton)
        {
            Module.OperaterItem.SubOperaterItem item = null;
            DataStruct struct2 = null;
            DataStruct struct3 = null;
            foreach (Module.OperaterItem.SubOperaterItem item2 in operate.subOperateItem)
            {
                if (item2.Type == Module.OperateType.OP_ASK)
                {
                    item = item2;
                    DataStruct.DataStructDic.TryGetValue(m.ModuleName + item2.DataStructName, out struct2);
                }
                else if (item2.Type == Module.OperateType.OP_REPLY)
                {
                    DataStruct.DataStructDic.TryGetValue(m.ModuleName + item2.DataStructName, out struct3);
                }
            }
            string str = "RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_REQUEST";
            string dataStructName = item.DataStructName;
            interactRpc = interactRpc + "\t/**\r\n";
            string str2 = interactRpc;
            interactRpc = str2 + "\t*" + m.CNName + "-->" + operate.CNName + " RPC请求\r\n";
            interactRpc = interactRpc + "\t*/\r\n";
            interactRpc = interactRpc + "\tpublic void " + operate.Name + "(";
            for (int i = 0; i < struct2.fieldItem.Count; i++)
            {
                DataStruct.FieldDescriptor descriptor = (DataStruct.FieldDescriptor) struct2.fieldItem[i];
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    interactRpc = interactRpc + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName;
                }
                else
                {
                    string str3 = interactRpc;
                    interactRpc = str3 + "List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName;
                }
                interactRpc = interactRpc + ", ";
            }
            interactRpc = interactRpc + "ReplyHandler replyCB)\r\n\t{\r\n";
            string str4 = interactRpc;
            interactRpc = str4 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "AskWraper askPBWraper = new " + m.ModuleName + "Rpc" + operate.Name + "AskWraper();\r\n";
            for (int j = 0; j < struct2.fieldItem.Count; j++)
            {
                DataStruct.FieldDescriptor descriptor2 = (DataStruct.FieldDescriptor) struct2.fieldItem[j];
                if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                {
                    string str5 = interactRpc;
                    interactRpc = str5 + "\t\taskPBWraper.Set" + descriptor2.FieldName + "(" + descriptor2.FieldName + ");\r\n";
                }
                else
                {
                    string str6 = interactRpc;
                    interactRpc = str6 + "\t\taskPBWraper." + descriptor2.FieldName + " = " + descriptor2.FieldName + ";\r\n";
                }
            }
            interactRpc = interactRpc + "\t\tModMessage askMsg = new ModMessage();\r\n";
            interactRpc = interactRpc + "\t\taskMsg.MsgNum = " + str.ToUpper() + ";\r\n";
            interactRpc = interactRpc + "\t\taskMsg.protoMS = askPBWraper.ToMemoryStream();\r\n\r\n";
            interactRpc = interactRpc + "\t\tSingleton<GameSocket>.Instance.SendAsk(askMsg, delegate(ModMessage replyMsg){\r\n";
            string str7 = interactRpc;
            interactRpc = str7 + "\t\t\t" + m.ModuleName + "Rpc" + operate.Name + "ReplyWraper replyPBWraper = new " + m.ModuleName + "Rpc" + operate.Name + "ReplyWraper();\r\n";
            interactRpc = interactRpc + "\t\t\treplyPBWraper.FromMemoryStream(replyMsg.protoMS);\r\n";
            if (GenLangFlags.CSCat)
            {
                interactRpc = interactRpc + "\t\t\treplyCB(replyMsg.MsgNum==1?true:false,replyPBWraper);\r\n";
            }
            else
            {
                interactRpc = interactRpc + "\t\t\treplyCB(replyPBWraper);\r\n";
            }
            interactRpc = interactRpc + "\t\t});\r\n";
            interactRpc = interactRpc + "\t}\r\n\r\n";
            callFunction = callFunction + "\tpublic void Test" + operate.Name + "()\r\n\t{\r\n";
            string str8 = callFunction;
            callFunction = str8 + "\t\t" + m.ModuleName + "RPC.Instance." + operate.Name + "(";
            foreach (DataStruct.FieldDescriptor descriptor3 in struct2.fieldItem)
            {
                string str9 = callFunction;
                callFunction = str9 + struct2.getFullName() + "WraperVar." + descriptor3.FieldName + ",";
            }
            if (GenLangFlags.CSCat)
            {
                callFunction = callFunction + "delegate(bool connedServer,object obj){});\r\n\t}\r\n";
            }
            else
            {
                callFunction = callFunction + "delegate(object obj){});\r\n\t}\r\n";
            }
            callButton = callButton + "\t\tif (GUILayout.Button(\"" + operate.Name + "\"))\r\n\t\t{\r\n";
            string str10 = callButton;
            callButton = str10 + "\t\t\t" + m.ModuleName + "TestHelper rpc = target as " + m.ModuleName + "TestHelper;\r\n";
            callButton = callButton + "\t\t\tif( rpc ) rpc.Test" + operate.Name + "();\r\n\t\t}\r\n";
        }

        private static void GenNotifyCallback(Module m, Module.OperaterItem operate, int hasCode, ref string notifyCb)
        {
            Module.OperaterItem.SubOperaterItem item = null;
            DataStruct struct2 = null;
            foreach (Module.OperaterItem.SubOperaterItem item2 in operate.subOperateItem)
            {
                if ((item2.Type == Module.OperateType.OP_SERVER_NOTIFY) || (item2.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                {
                    item = item2;
                    DataStruct.DataStructDic.TryGetValue(m.ModuleName + item2.DataStructName, out struct2);
                }
            }
            string text1 = "RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_NOTIFY";
            string dataStructName = item.DataStructName;
            notifyCb = notifyCb + "\t/**\r\n";
            string str = notifyCb;
            notifyCb = str + "\t*" + m.CNName + "-->" + operate.CNName + " 服务器通知回调\r\n";
            notifyCb = notifyCb + "\t*/\r\n";
            notifyCb = notifyCb + "\tpublic static void " + operate.Name + "CB( ModMessage notifyMsg )\r\n\t{\r\n";
            string str2 = notifyCb;
            notifyCb = str2 + "\t\t" + m.ModuleName + item.DataStructName + "Wraper notifyPBWraper = new " + m.ModuleName + item.DataStructName + "Wraper();\r\n";
            notifyCb = notifyCb + "\t\tnotifyPBWraper.FromMemoryStream(notifyMsg.protoMS);\r\n";
            notifyCb = notifyCb + "\t\tif( " + operate.Name + "CBDelegate != null )\r\n";
            notifyCb = notifyCb + "\t\t\t" + operate.Name + "CBDelegate( notifyPBWraper );\r\n";
            notifyCb = notifyCb + "\t}\r\n\tpublic static ServerNotifyCallback " + operate.Name + "CBDelegate = null;\r\n";
        }

        private static void GenNotifyRpc(Module m, Module.OperaterItem operate, int hasCode, ref string notifyRpc, ref string callFunction, ref string callButton)
        {
            Module.OperaterItem.SubOperaterItem item = null;
            DataStruct struct2 = null;
            foreach (Module.OperaterItem.SubOperaterItem item2 in operate.subOperateItem)
            {
                if ((item2.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item2.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                {
                    item = item2;
                    DataStruct.DataStructDic.TryGetValue(m.ModuleName + item2.DataStructName, out struct2);
                }
            }
            string str = "RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_NOTIFY";
            string dataStructName = item.DataStructName;
            notifyRpc = notifyRpc + "\t/**\r\n";
            string str2 = notifyRpc;
            notifyRpc = str2 + "\t*" + m.CNName + "-->" + operate.CNName + " RPC通知\r\n";
            notifyRpc = notifyRpc + "\t*/\r\n";
            notifyRpc = notifyRpc + "\tpublic void " + operate.Name + "(";
            for (int i = 0; i < struct2.fieldItem.Count; i++)
            {
                DataStruct.FieldDescriptor descriptor = (DataStruct.FieldDescriptor) struct2.fieldItem[i];
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    notifyRpc = notifyRpc + descriptor.ToGetCSFieldType() + " " + descriptor.FieldName;
                }
                else
                {
                    string str3 = notifyRpc;
                    notifyRpc = str3 + "List<" + descriptor.ToGetCSFieldType() + "> " + descriptor.FieldName;
                }
                if (i < (struct2.fieldItem.Count - 1))
                {
                    notifyRpc = notifyRpc + ", ";
                }
            }
            notifyRpc = notifyRpc + ")\r\n\t{\r\n";
            string str4 = notifyRpc;
            notifyRpc = str4 + "\t\t" + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper notifyPBWraper = new " + m.ModuleName + "Rpc" + operate.Name + "NotifyWraper();\r\n";
            for (int j = 0; j < struct2.fieldItem.Count; j++)
            {
                DataStruct.FieldDescriptor descriptor2 = (DataStruct.FieldDescriptor) struct2.fieldItem[j];
                if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                {
                    string str5 = notifyRpc;
                    notifyRpc = str5 + "\t\tnotifyPBWraper.Set" + descriptor2.FieldName + "(" + descriptor2.FieldName + ");\r\n";
                }
                else
                {
                    string str6 = notifyRpc;
                    notifyRpc = str6 + "\t\tnotifyPBWraper." + descriptor2.FieldName + " = " + descriptor2.FieldName + ";\r\n";
                }
            }
            notifyRpc = notifyRpc + "\t\tModMessage notifyMsg = new ModMessage();\r\n";
            notifyRpc = notifyRpc + "\t\tnotifyMsg.MsgNum = " + str.ToUpper() + ";\r\n";
            notifyRpc = notifyRpc + "\t\tnotifyMsg.protoMS = notifyPBWraper.ToMemoryStream();\r\n\r\n";
            notifyRpc = notifyRpc + "\t\tSingleton<GameSocket>.Instance.SendNotify(notifyMsg);\r\n";
            notifyRpc = notifyRpc + "\t}\r\n\r\n";
            callFunction = callFunction + "\tpublic void Test" + operate.Name + "()\r\n\t{\r\n";
            string str7 = callFunction;
            callFunction = str7 + "\t\t" + m.ModuleName + "RPC.Instance." + operate.Name + "(";
            for (int k = 0; k < struct2.fieldItem.Count; k++)
            {
                DataStruct.FieldDescriptor descriptor3 = (DataStruct.FieldDescriptor) struct2.fieldItem[k];
                callFunction = callFunction + struct2.getFullName() + "WraperVar." + descriptor3.FieldName;
                if (k < (struct2.fieldItem.Count - 1))
                {
                    callFunction = callFunction + ",";
                }
            }
            callFunction = callFunction + ");\r\n\t}\r\n";
            callButton = callButton + "\t\tif (GUILayout.Button(\"" + operate.Name + "\"))\r\n\t\t{\r\n";
            string str8 = callButton;
            callButton = str8 + "\t\t\t" + m.ModuleName + "TestHelper rpc = target as " + m.ModuleName + "TestHelper;\r\n";
            callButton = callButton + "\t\t\tif( rpc ) rpc.Test" + operate.Name + "();\r\n\t\t}\r\n";
        }
        
        public static void Serialize(Module m, string dir, Label label1)
        {
            if (GenLangFlags.CS || GenLangFlags.CSCat)
            {
                string str54;
                object obj2;
                string path = dir + @"\CS\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string str2 = dir + @"\CPP\";
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                string str3 = dir + @"\CPP\" + m.ModuleName + @"\";
                if (!Directory.Exists(str3))
                {
                    Directory.CreateDirectory(str3);
                }
                string str4 = dir + @"\CS\PB\";
                if (!Directory.Exists(str4))
                {
                    Directory.CreateDirectory(str4);
                }
                string str5 = dir + @"\CS\Module\";
                if (!Directory.Exists(str5))
                {
                    Directory.CreateDirectory(str5);
                }
                string str6 = dir + @"\CS\Helper\";
                if (!Directory.Exists(str6))
                {
                    Directory.CreateDirectory(str6);
                }
                string str7 = dir + @"\CS\Config\";
                if (!Directory.Exists(str7))
                {
                    Directory.CreateDirectory(str7);
                }
                if (m.configFiles.Count > 0)
                {
                    File.Copy("./Template/GameAssist.cs", str7 + "GameAssist.cs", true);
                    File.Copy("./Template/buildDll.bat", dir + @"\buildDll.bat", true);
                    File.Copy("./Template/UnityEngine.dll", dir + @"\UnityEngine.dll", true);
                }
                string str8 = "";
                StreamReader reader = new StreamReader("./Template/ConfigTemplate.cs", Encoding.GetEncoding("GBK"));
                str8 = reader.ReadToEnd();
                reader.Close();
                string newValue = "";
                
                foreach (ConfigFile file in m.configFiles)
                {
                    newValue = newValue + "\t\tyield return StartCoroutine(LoadData(\"" + file.CfgName + ".csv\"));\r\n";
                    newValue = newValue + "\t\t" + file.CfgName + "Table.Instance.LoadCsv(textContent);\r\n\r\n";
                    string str10 = str8;
                    string fieldName = "";
                    string fieldType = "";
                    string defaultValue = "";
                    string str14 = "";
                    string str15 = "";
                    string str16 = "";
                    string str17 = "";
                    int num = 0;
                    foreach (ConfigFile.ConfigField field in file.fieldItem)
                    {
                        if (field.IsPrimary)
                        {
                            fieldName = field.FieldName;
                            fieldType = field.FieldType;
                            defaultValue = field.DefaultValue;
                            break;
                        }
                    }
                    string str18 = "";
                    if (fieldType == "int")
                    {
                        str18 = fieldName + " = " + defaultValue + ";";
                    }
                    int num2 = 0;
                    bool flag = false;
                    foreach (ConfigFile.ConfigField field2 in file.fieldItem)
                    {
                        if (!field2.IsServer && !field2.IsDescribe)
                        {
                            num++;
                            flag = true;
                            string str19 = "\tpublic " + field2.FieldType + " " + field2.FieldName + ";";
                            int num3 = 30 - str19.Length;
                            while (num3-- > 0)
                            {
                                str19 = str19 + " ";
                            }
                            string str20 = "";
                            if (field2.Comment != null)
                            {
                                str20 = field2.Comment.Replace("\r\n", " ");
                            }
                            str54 = str19;
                            str19 = str54 + "\t//" + field2.CNName + "\t" + str20.Replace("\n", " ") + "\r\n";
                            str14 = str14 + str19;
                            obj2 = str15;
                            str15 = string.Concat(new object[] { obj2, "\t\tif(vecLine[", num2, "]!=\"", field2.FieldName, "\"){Ex.Logger.Log(\"", file.CfgName, ".csv中字段[", field2.FieldName, "]位置不对应\"); return false; }\r\n" });
                            if (field2.FieldType == "int")
                            {
                                obj2 = str17;
                                str17 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=Convert.ToInt32(vecLine[", num2, "]);\r\n" });
                                str16 = str16 + "\t\t\treadPos += GameAssist.ReadInt32Variant(binContent, readPos, out member." + field2.FieldName + " );\r\n";
                            }
                            else if (field2.FieldType == "float")
                            {
                                obj2 = str17;
                                str17 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=Convert.ToSingle(vecLine[", num2, "]);\r\n" });
                                str16 = str16 + "\t\t\treadPos += GameAssist.ReadFloat( binContent, readPos, out member." + field2.FieldName + ");\r\n";
                            }
                            else
                            {
                                obj2 = str17;
                                str17 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=vecLine[", num2, "];\r\n" });
                                str16 = str16 + "\t\t\treadPos += GameAssist.ReadString( binContent, readPos, out member." + field2.FieldName + ");\r\n";
                            }
                            num2++;
                        }
                    }
                    str10 = str10.Replace("$TEMPLATE$", file.CfgName.ToUpper()).Replace("$CNName$", file.CNName).Replace("$Template$", file.CfgName).Replace("$PrimaryKey$", fieldName).Replace("$PrimaryType$", fieldType).Replace("$InitPrimaryField$", str18).Replace("$FieldDefine$", str14)
                        .Replace("$ColCount$", num.ToString()).Replace("$CheckColName$", str15).Replace("$ReadBinColValue$", str16).Replace("$ReadCsvColValue$", str17);
                    if (flag)
                    {
                        StreamWriter writer = new StreamWriter(str7 + file.CfgName + "Cfg.cs", false, Encoding.UTF8);
                        writer.Write(str10);
                        writer.Close();
                    }
                }
                if (m.configFiles.Count > 0)
                {
                    Process process = new Process {
                        StartInfo = { 
                            FileName = "buildDll.bat",
                            WindowStyle = ProcessWindowStyle.Hidden
                        }
                    };
                    string currentDirectory = Directory.GetCurrentDirectory();
                    Directory.SetCurrentDirectory(dir);
                    process.Start();
                    process.WaitForExit();
                    Directory.SetCurrentDirectory(currentDirectory);
                    process.Close();
                }
                StreamReader reader2 = null;
                if (newValue.Length > 0)
                {
                    try
                    {
                        reader2 = new StreamReader("./Template/ConfigLoad.cs");
                    }
                    catch (DirectoryNotFoundException)
                    {
                        return;
                    }
                    string str22 = reader2.ReadToEnd();
                    reader2.Close();
                    str22 = str22.Replace("$loadConfItem$", newValue);
                    StreamWriter writer2 = new StreamWriter(str7 + "ConfigLoad.cs", false, Encoding.UTF8);
                    writer2.Write(str22);
                    writer2.Close();
                }
                try
                {
                    reader2 = new StreamReader("./Template/ModuleTemplate.cs");
                }
                catch (DirectoryNotFoundException)
                {
                    return;
                }
                string str23 = str5 + m.ModuleName + "Module.cs";
                label1.Text = "正在生成文件: " + str23;
                label1.Refresh();
                StreamWriter writer3 = new StreamWriter(str23, false, Encoding.UTF8);
                string str24 = reader2.ReadToEnd();
                reader2.Close();
                string str25 = "";
                string str26 = "";
                string notifyRpc = "";
                string interactRpc = "";
                string notifyCb = "";
                int num4 = 0;
                string strWraper = "";
                string masterDataWraper = "";
                string structName = "";
                string str33 = "";
                string str34 = "";
                string str35 = "";
                string askWraperHelper = "";
                string askWraperVar = "";
                string callFunction = "";
                string callButton = "";
                foreach (DataStruct struct2 in DataStructConverter.CommDataStruct)
                {
                    GenClassWraperCode(null, struct2, ref strWraper, ref masterDataWraper, ref askWraperHelper, ref askWraperVar);
                }
                string str40 = "";
                StreamReader reader3 = new StreamReader("./Template/WraperTemplate.cs", Encoding.GetEncoding("GBK"));
                str40 = reader3.ReadToEnd();
                reader3.Close();
                string str41 = str40;
                str41 = str41.Replace("$strWraper$", strWraper).Replace("$Template$", "PubPBCommon").Replace("$Date$", DateTime.Now.ToShortDateString().ToString());
                StreamWriter writer4 = new StreamWriter(str4 + @"\PublicStructWraper.cs", false, Encoding.UTF8);
                writer4.Write(str41);
                writer4.Close();
                strWraper = "";
                masterDataWraper = "";
                bool flag2 = false;
                foreach (DataStruct struct3 in m.moduleDataStruct)
                {
                    if (struct3.ProtoType == DataStruct.protoTypeE.SyncProto)
                    {
                        if ((struct3.DataType == DataStruct.SyncType.UserData) || ((struct3.DataType == DataStruct.SyncType.CacheData) && struct3.SyncToClient))
                        {
                            flag2 = true;
                            str35 = string.Concat(new object[] { ": ", m.ModuleName, struct3.StructName, "WraperV", m.SyncDataVersion });
                            structName = struct3.StructName;
                            foreach (DataStruct.FieldDescriptor descriptor in struct3.fieldItem)
                            {
                                string str42 = " \t\t" + descriptor.FieldName.ToUpper();
                                int num5 = 0x2e - str42.Length;
                                while (num5-- > 0)
                                {
                                    str42 = str42 + " ";
                                }
                                obj2 = str42;
                                str42 = string.Concat(new object[] { obj2, "= ", (m.StartIdNum * 100) + descriptor.FieldId, ",  //", descriptor.CNName, "\r\n" });
                                str33 = str33 + str42;
                                str34 = str34 + "\t\t\tcase SyncIdE." + descriptor.FieldName.ToUpper() + ":\r\n";
                                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                                {
                                    if (descriptor.GetTypeEnum() == 1)
                                    {
                                        if (descriptor.FieldType == "bool")
                                        {
                                            str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + " = BitConverter.ToBoolean(updateBuffer,0);\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else if (descriptor.FieldType == "float")
                                        {
                                            str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + " = BitConverter.ToSingle(updateBuffer,0);\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else if (descriptor.FieldType == "sint32")
                                        {
                                            str34 = str34 + "\t\t\t\tGameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);\r\n";
                                            str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + " = iValue;\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else
                                        {
                                            str34 = str34 + "\t\t\t\tGameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);\r\n";
                                            str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + " = lValue;\r\n\t\t\t\tbreak;\r\n";
                                        }
                                    }
                                    else if (descriptor.GetTypeEnum() == 2)
                                    {
                                        str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + " = System.Text.Encoding.UTF8.GetString(updateBuffer);\r\n\t\t\t\tbreak;\r\n";
                                    }
                                    else
                                    {
                                        str34 = str34 + "\t\t\t\tm_Instance." + descriptor.FieldName + ".FromMemoryStream(new MemoryStream(updateBuffer));\r\n\t\t\t\tbreak;\r\n";
                                    }
                                }
                                else
                                {
                                    str34 = str34 + "\t\t\t\tif(Index < 0){ m_Instance.Clear" + descriptor.FieldName + "(); break; }\r\n";
                                    str34 = str34 + "\t\t\t\tif (Index >= m_Instance.Size" + descriptor.FieldName + "())\r\n\t\t\t\t{\r\n";
                                    str34 = str34 + "\t\t\t\t\tint Count = Index - m_Instance.Size" + descriptor.FieldName + "() + 1;\r\n";
                                    str34 = str34 + "\t\t\t\t\tfor (int i = 0; i < Count; i++)\r\n";
                                    if (descriptor.GetTypeEnum() == 1)
                                    {
                                        str54 = str34;
                                        str34 = str54 + "\t\t\t\t\t\tm_Instance.Add" + descriptor.FieldName + "(" + descriptor.DefaultValue + ");\r\n\t\t\t\t}\r\n";
                                        if (descriptor.FieldType == "bool")
                                        {
                                            str34 = str34 + "\t\t\t\tm_Instance.Set" + descriptor.FieldName + "(Index, BitConverter.ToBoolean(updateBuffer,0));\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else if (descriptor.FieldType == "float")
                                        {
                                            str34 = str34 + "\t\t\t\tGameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);\r\n";
                                            str34 = str34 + "\t\t\t\tm_Instance.Set" + descriptor.FieldName + "(Index, BitConverter.ToSingle(updateBuffer,0));\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else if (descriptor.FieldType == "sint32")
                                        {
                                            str34 = str34 + "\t\t\t\tGameAssist.ReadInt32Variant(updateBuffer, 0, out iValue);\r\n";
                                            str34 = str34 + "\t\t\t\tm_Instance.Set" + descriptor.FieldName + "(Index, iValue);\r\n\t\t\t\tbreak;\r\n";
                                        }
                                        else
                                        {
                                            str34 = str34 + "\t\t\t\tGameAssist.ReadInt64Variant(updateBuffer, 0, out lValue);\r\n";
                                            str34 = str34 + "\t\t\t\tm_Instance.Set" + descriptor.FieldName + "(Index, lValue);\r\n\t\t\t\tbreak;\r\n";
                                        }
                                    }
                                    else if (descriptor.GetTypeEnum() == 2)
                                    {
                                        str34 = str34 + "\t\t\t\t\t\tm_Instance.Add" + descriptor.FieldName + "(\"\");\r\n\t\t\t\t}\r\n";
                                        str34 = str34 + "\t\t\t\tm_Instance.Set" + descriptor.FieldName + "(Index, System.Text.Encoding.UTF8.GetString(updateBuffer));\r\n\t\t\t\tbreak;\r\n";
                                    }
                                    else
                                    {
                                        str54 = str34;
                                        str34 = str54 + "\t\t\t\t\t\tm_Instance.Add" + descriptor.FieldName + "(new " + descriptor.ToGetCSFieldType() + "());\r\n\t\t\t\t}\r\n";
                                        str34 = str34 + "\t\t\t\tm_Instance.Get" + descriptor.FieldName + "(Index).FromMemoryStream(new MemoryStream(updateBuffer));\r\n\t\t\t\tbreak;\r\n";
                                    }
                                }
                            }
                        }
                        if (GenLangFlags.ActEditor)
                        {
                            GenClassWraperCode2(m, struct3, ref strWraper, ref masterDataWraper, ref askWraperHelper, ref askWraperVar);
                        }
                        else
                        {
                            GenClassWraperCode(m, struct3, ref strWraper, ref masterDataWraper, ref askWraperHelper, ref askWraperVar);
                        }
                    }
                }
                str41 = str40;
                str41 = str41.Replace("$strWraper$", strWraper).Replace("$Template$", "SyncPB" + m.ModuleName).Replace("$Date$", DateTime.Now.ToShortDateString().ToString());
                if (flag2)
                {
                    writer4 = new StreamWriter(string.Concat(new object[] { str4, m.ModuleName, "V", m.SyncDataVersion, "DataWraper.cs" }), false, Encoding.UTF8);
                    writer4.Write(str41);
                    writer4.Close();
                }
                strWraper = "";
                string str43 = "";
                askWraperHelper = "";
                askWraperVar = "";
                callFunction = "";
                callButton = "";
                string notifyCBDelegate = "";
                string operations = "";
                foreach (Module.OperaterItem item in m.operateItem)
                {
                    num4++;
                    int hasCode = 0;
                    foreach (Module.OperaterItem.SubOperaterItem item2 in item.subOperateItem)
                    {
                        switch (item2.Type)
                        {
                            case Module.OperateType.OP_ASK:
                            case Module.OperateType.OP_REPLY:
                                hasCode = 1;
                                break;

                            case Module.OperateType.OP_CLIENT_NOTIFY:
                                hasCode = 2;
                                break;

                            case Module.OperateType.OP_SERVER_NOTIFY:
                                hasCode = 3;
                                break;

                            case Module.OperateType.OP_DUPLEX_NOTIFY:
                                hasCode = 4;
                                break;
                        }
                    }
                    if (hasCode == 1)
                    {
                        obj2 = str26;
                        str26 = string.Concat(new object[] { obj2, "\tpublic const int RPC_CODE_", m.ModuleName.ToUpper(), "_", item.Name.ToUpper(), "_REQUEST = ", ((m.StartIdNum * 100) + 50) + num4, ";\r\n" });
                        GenInteractRpc(m, item, hasCode, ref interactRpc, ref callFunction, ref callButton);
                    }
                    else
                    {
                        obj2 = str26;
                        str26 = string.Concat(new object[] { obj2, "\tpublic const int RPC_CODE_", m.ModuleName.ToUpper(), "_", item.Name.ToUpper(), "_NOTIFY = ", ((m.StartIdNum * 100) + 50) + num4, ";\r\n" });
                    }
                    if ((hasCode == 2) || (hasCode == 4))
                    {
                        GenNotifyRpc(m, item, hasCode, ref notifyRpc, ref callFunction, ref callButton);
                    }
                    if ((hasCode == 3) || (hasCode == 4))
                    {
                        str54 = str25;
                        str25 = str54 + "\t\tSingleton<GameSocket>.Instance.RegisterNotify(RPC_CODE_" + m.ModuleName.ToUpper() + "_" + item.Name.ToUpper() + "_NOTIFY, " + item.Name + "CB);\r\n";
                        GenNotifyCallback(m, item, hasCode, ref notifyCb);
                    }
                    GenClientFrameCode(m, item, hasCode, ref notifyCBDelegate, ref operations);
                    DataStruct struct4 = null;
                    DataStruct struct5 = null;
                    DataStruct struct6 = null;
                    foreach (Module.OperaterItem.SubOperaterItem item3 in item.subOperateItem)
                    {
                        if (item3.Type == Module.OperateType.OP_ASK)
                        {
                            DataStruct.DataStructDic.TryGetValue(m.ModuleName + item3.DataStructName, out struct4);
                        }
                        else if (item3.Type == Module.OperateType.OP_REPLY)
                        {
                            DataStruct.DataStructDic.TryGetValue(m.ModuleName + item3.DataStructName, out struct5);
                        }
                        else if (((item3.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item3.Type == Module.OperateType.OP_SERVER_NOTIFY)) || (item3.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                        {
                            DataStruct.DataStructDic.TryGetValue(m.ModuleName + item3.DataStructName, out struct6);
                        }
                    }
                }
                foreach (DataStruct struct7 in m.moduleDataStruct)
                {
                    if ((struct7.ProtoType != DataStruct.protoTypeE.SyncProto) && (struct7.StructName.ToLower().IndexOf("svrrpc") <= -1))
                    {
                        GenClassWraperCode(struct7.module, struct7, ref strWraper, ref str43, ref askWraperHelper, ref askWraperVar);
                    }
                }
                str24 = str24.Replace("$masterDataWraper$", masterDataWraper)
                    .Replace("$SyncVer$", m.SyncDataVersion.ToString())
                    .Replace("$ModId$", m.StartIdNum.ToString())
                    .Replace("$Template$", m.ModuleName)
                    .Replace("$Date$", DateTime.Now.ToShortDateString().ToString())
                    .Replace("$MsgIdList$", str26)
                    .Replace("$NotifyRpc$", notifyRpc)
                    .Replace("$InteractRpc$", interactRpc)
                    .Replace("$NotifyCallback$", notifyCb)
                    .Replace("$RegisterCB$", str25)
                    .Replace("$LoadConfig$", newValue)
                    .Replace("$SyncName$", structName)
                    .Replace("$SyncIdList$", str33)
                    .Replace("$updateSyncField$", str34)
                    .Replace("$WraperName$", str35);
                writer3.Write(str24);
                writer3.Flush();
                writer3.Close();
                str41 = str40;
                str41 = str41.Replace("$strWraper$", strWraper).Replace("$Template$", "RpcPB" + m.ModuleName).Replace("$Date$", DateTime.Now.ToShortDateString().ToString());
                writer4 = new StreamWriter(str4 + m.ModuleName + "RpcWraper.cs", false, Encoding.UTF8);
                writer4.Write(str41);
                writer4.Close();
                reader3 = new StreamReader("./Template/TestHelperTmpt.cs", Encoding.GetEncoding("GBK"));
                str24 = reader3.ReadToEnd();
                reader3.Close();
                str24 = str24.Replace("$Template$", m.ModuleName).Replace("$RpcAskWraperHelper$", askWraperHelper).Replace("$RpcAskWraperVar$", askWraperVar).Replace("$CallRpcFunction$", callFunction).Replace("$CallRpcButton$", callButton);
                writer4 = new StreamWriter(str6 + m.ModuleName + "TestHelper.cs", false, Encoding.UTF8);
                writer4.Write(str24);
                writer4.Close();
                bool flag3 = false;
                string actionEnum = "";
                string defineActionPool = "";
                string poolCreateAction = "";
                string poolStoreAction = "";
                string actionDeserialize = "";
                string actionClass = "";
                string str52 = "";
                string str53 = "";
                foreach (DataStruct struct8 in m.moduleDataStruct)
                {
                    if (((struct8.ProtoType != DataStruct.protoTypeE.SyncProto) && (struct8.StructName.ToLower().IndexOf("svrrpc") <= -1)) && (struct8.module.ModuleName == "Fight"))
                    {
                        GenActionWraperCode(struct8.module, struct8, ref actionEnum, ref defineActionPool, ref poolCreateAction, ref poolStoreAction, ref actionDeserialize, ref actionClass, ref str52, ref str53);
                        flag3 = true;
                    }
                }
                if (flag3)
                {
                    reader3 = new StreamReader("./Template/ActionTemplate.cs", Encoding.GetEncoding("GBK"));
                    str24 = reader3.ReadToEnd();
                    reader3.Close();
                    str24 = str24.Replace("$ActionEnum$", actionEnum).Replace("$DefineActionPool$", defineActionPool).Replace("$PoolCreateAction$", poolCreateAction).Replace("$PoolStoreAction$", poolStoreAction).Replace("$ActionDeserialize$", actionDeserialize).Replace("$ActionClass$", actionClass).Replace("$NEW_ACTION$", str52).Replace("$DEFINE_ACTION$", str53);
                    writer4 = new StreamWriter(str4 + "Action.cs", false, Encoding.UTF8);
                    writer4.Write(str24);
                    writer4.Close();
                    reader3 = new StreamReader("./Template/ActionTemplate.h", Encoding.GetEncoding("GBK"));
                    str24 = reader3.ReadToEnd();
                    reader3.Close();
                    str24 = str24.Replace("$ActionEnum$", actionEnum).Replace("$DefineActionPool$", defineActionPool).Replace("$PoolCreateAction$", poolCreateAction).Replace("$PoolStoreAction$", poolStoreAction).Replace("$ActionDeserialize$", actionDeserialize).Replace("$ActionClass$", actionClass).Replace("$NEW_ACTION$", str52).Replace("$DEFINE_ACTION$", str53);
                    writer4 = new StreamWriter(str3 + "Action.h", false, Encoding.UTF8);
                    writer4.Write(str24);
                    writer4.Close();
                    reader3 = new StreamReader("./Template/ActionTemplate.cpp", Encoding.GetEncoding("GBK"));
                    str24 = reader3.ReadToEnd();
                    reader3.Close();
                    str24 = str24.Replace("$ActionEnum$", actionEnum).Replace("$DefineActionPool$", defineActionPool).Replace("$PoolCreateAction$", poolCreateAction).Replace("$PoolStoreAction$", poolStoreAction).Replace("$ActionDeserialize$", actionDeserialize).Replace("$ActionClass$", actionClass).Replace("$NEW_ACTION$", str52).Replace("$DEFINE_ACTION$", str53);
                    writer4 = new StreamWriter(str3 + "Action.cpp", false, Encoding.UTF8);
                    writer4.Write(str24);
                    writer4.Close();
                }
            }
        }
    }
}

