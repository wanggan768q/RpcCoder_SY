namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class CoffeeSerializer
    {
        private static Dictionary<string, int> map;

        private static void DiGui(ref Module m, ref string RpcValues, string name, bool isSave)
        {
            bool flag = false;
            DataStruct struct2 = m.getModuleStruct(name);
            if ((struct2 != null) && !map.ContainsKey(name))
            {
                if (((struct2.DataType == DataStruct.SyncType.UserData) || (struct2.DataType == DataStruct.SyncType.CacheData)) || (struct2.DataType == DataStruct.SyncType.ModuleData))
                {
                    flag = true;
                }
                map.Add(name, 1);
                string str = "";
                str = ((str + "      message  " + name) + (flag ? ("V" + m.SyncDataVersion) : "") + "\r\n") + "      {\r\n";
                foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                {
                    str = str + "        " + ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "repeated" : "optional");
                    str = str + " " + descriptor.FieldType;
                    if (("sint32" != descriptor.FieldType) && ("sint64" != descriptor.FieldType))
                    {
                        bool flag1 = "string" == descriptor.FieldType;
                    }
                    object obj2 = str;
                    str = string.Concat(new object[] { obj2, " ", descriptor.FieldName, " = ", descriptor.FieldId });
                    if ((("sint32" == descriptor.FieldType) || ("sint64" == descriptor.FieldType)) && (descriptor.PreDefine != DataStruct.FieldDescriptor.PreDefineType.repeated))
                    {
                        str = str + "[default=" + descriptor.defaultValue + "]";
                    }
                    str = str + ";\r\n";
                    if ((("sint32" != descriptor.FieldType) && ("sint64" != descriptor.FieldType)) && ("string" != descriptor.FieldType))
                    {
                        DiGui(ref m, ref RpcValues, descriptor.FieldType, isSave);
                    }
                }
                str = str + "      }\r\n";
                RpcValues = RpcValues + str;
            }
        }

        public static void GenClassWraperCode(Module m, DataStruct ds, ref string strWraper)
        {
            string str = "";
            StreamReader reader = new StreamReader("./Template/WraperTemplate.cpp", Encoding.GetEncoding("GBK"));
            str = reader.ReadToEnd();
            reader.Close();
            string str2 = "";
            if (ds.ProtoType == DataStruct.protoTypeE.SyncProto)
            {
                str2 = "V" + m.SyncDataVersion;
            }
            string newValue = ds.getFullName() + "Wraper" + str2;
            string str4 = ds.getFullName() + str2;
            string str5 = "";
            string str6 = "";
            string str7 = "";
            string str8 = "";
            string str9 = "";
            string str10 = "";
            if (((ds.DataType == DataStruct.SyncType.ModuleData) || (ds.DataType == DataStruct.SyncType.CacheData)) || ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient)))
            {
                str9 = ", public ModuleDataInterface , public ModuleDataRegister<" + newValue + ">";
                str10 = "SetDataWraper( this );\r\n";
            }
            foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
            {
                string str11;
                if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional)
                {
                    str11 = str7;
                    str7 = str11 + "\t\tm_" + descriptor.FieldName + " = v." + descriptor.FieldName.ToLower() + "();\r\n";
                    str8 = str8 + "private:\r\n\t//" + descriptor.CNName + "\r\n";
                    string str12 = str8;
                    str8 = str12 + "\t" + descriptor.ToGetFieldType() + " m_" + descriptor.FieldName + ";\r\npublic:\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        string str13 = str6;
                        str6 = str13 + "\t\tv.set_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + " );\r\n";
                        string str14 = str8;
                        str8 = str14 + "\tvoid Set" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str15 = str8;
                        str8 = str15 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str16 = str5;
                        str5 = str16 + "\t\tm_" + descriptor.FieldName + " = " + descriptor.DefaultValue + ";\r\n";
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        string str17 = str6;
                        str6 = str17 + "\t\tv.set_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + " );\r\n";
                        string str18 = str8;
                        str8 = str18 + "\tvoid Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str19 = str8;
                        str8 = str19 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        str5 = str5 + "\t\tm_" + descriptor.FieldName + " = \"\";\r\n";
                    }
                    else
                    {
                        string str20 = str6;
                        str6 = str20 + "\t\t*v.mutable_" + descriptor.FieldName.ToLower() + "()= m_" + descriptor.FieldName + ".ToPB();\r\n";
                        string str21 = str8;
                        str8 = str21 + "\tvoid Set" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v)\r\n\t{\r\n\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                        string str22 = str8;
                        str8 = str22 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                        string str23 = str5;
                        str5 = str23 + "\t\tm_" + descriptor.FieldName + " = " + descriptor.ToGetFieldType() + "();\r\n";
                    }
                }
                else
                {
                    str7 = str7 + "\t\tm_" + descriptor.FieldName + ".clear();\r\n";
                    string str24 = str7;
                    str7 = str24 + "\t\tm_" + descriptor.FieldName + ".reserve(v." + descriptor.FieldName.ToLower() + "_size());\r\n";
                    str7 = str7 + "\t\tfor( int i=0; i<v." + descriptor.FieldName.ToLower() + "_size(); i++)\r\n";
                    string str25 = str7;
                    str7 = str25 + "\t\t\tm_" + descriptor.FieldName + ".push_back(v." + descriptor.FieldName.ToLower() + "(i));\r\n";
                    str8 = str8 + "private:\r\n\t//" + descriptor.CNName + "\r\n";
                    string str26 = str8;
                    str8 = str26 + "\tvector<" + descriptor.ToGetFieldType() + "> m_" + descriptor.FieldName + ";\r\npublic:\r\n";
                    string str27 = str8;
                    str8 = str27 + "\tint Size" + descriptor.FieldName + "()\r\n\t{\r\n\t\treturn m_" + descriptor.FieldName + ".size();\r\n\t}\r\n";
                    string str28 = str8;
                    str8 = str28 + "\tconst vector<" + descriptor.ToGetFieldType() + ">& Get" + descriptor.FieldName + "() const\r\n\t{\r\n";
                    str8 = str8 + "\t\treturn m_" + descriptor.FieldName + ";\r\n\t}\r\n";
                    string str29 = str8;
                    str8 = str29 + "\t" + descriptor.ToGetFieldType() + " Get" + descriptor.FieldName + "(int Index) const\r\n\t{\r\n";
                    string str30 = str8;
                    str8 = str30 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn " + descriptor.ToGetFieldType() + "();\r\n\t\t}\r\n";
                    str8 = str8 + "\t\treturn m_" + descriptor.FieldName + "[Index];\r\n\t}\r\n";
                    string str31 = str8;
                    str8 = str31 + "\tvoid Set" + descriptor.FieldName + "( const vector<" + descriptor.ToGetFieldType() + ">& v )\r\n\t{\r\n";
                    str8 = str8 + "\t\tm_" + descriptor.FieldName + "=v;\r\n\t}\r\n";
                    str8 = str8 + "\tvoid Clear" + descriptor.FieldName + "( )\r\n\t{\r\n";
                    str8 = str8 + "\t\tm_" + descriptor.FieldName + ".clear();\r\n\t}\r\n";
                    string str32 = str6;
                    str6 = str32 + "\t\tv.mutable_" + descriptor.FieldName.ToLower() + "()->Reserve(m_" + descriptor.FieldName + ".size());\r\n";
                    if (descriptor.GetTypeEnum() == 1)
                    {
                        string str33 = str8;
                        str8 = str33 + "\tvoid Set" + descriptor.FieldName + "( int Index, " + descriptor.ToGetFieldType() + " v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        string str34 = str8;
                        str8 = str34 + "\tvoid Add" + descriptor.FieldName + "( " + descriptor.ToGetFieldType() + " v = " + descriptor.DefaultValue + " )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str11 = str6;
                        str6 = str11 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\tv.add_" + descriptor.FieldName.ToLower() + "(m_" + descriptor.FieldName + "[i]);\r\n\t\t}\r\n";
                    }
                    else if (descriptor.GetTypeEnum() == 2)
                    {
                        str11 = str8;
                        str8 = str11 + "\tvoid Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        str11 = str8;
                        str8 = str11 + "\tvoid Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str11 = str6;
                        str6 = str11 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\tv.add_" + descriptor.FieldName.ToLower() + "( m_" + descriptor.FieldName + "[i]);\r\n\t\t}\r\n";
                    }
                    else
                    {
                        str11 = str8;
                        str8 = str11 + "\tvoid Set" + descriptor.FieldName + "( int Index, const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tif(Index<0 || Index>=(int)m_" + descriptor.FieldName + ".size())\r\n\t\t{\r\n\t\t\tassert(false);\r\n\t\t\treturn;\r\n\t\t}\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + "[Index] = v;\r\n\t}\r\n";
                        str11 = str8;
                        str8 = str11 + "\tvoid Add" + descriptor.FieldName + "( const " + descriptor.ToGetFieldType() + "& v )\r\n\t{\r\n";
                        str8 = str8 + "\t\tm_" + descriptor.FieldName + ".push_back(v);\r\n\t}\r\n";
                        str11 = str6;
                        str6 = str11 + "\t\tfor (int i=0; i<(int)m_" + descriptor.FieldName + ".size(); i++)\r\n\t\t{\r\n\t\t\t*v.add_" + descriptor.FieldName.ToLower() + "() = m_" + descriptor.FieldName + "[i].ToPB();\r\n\t\t}\r\n";
                    }
                }
            }
            str = str.Replace("$CNName$", ds.CNName).Replace("$WraperName$", newValue).Replace("$PBName$", str4).Replace("$ConstructField$", str5).Replace("$ToPBField$", str6).Replace("$InitFuncField$", str7).Replace("$GetSetSizeField$", str8).Replace("$ModuleDataWraperDef$", str9).Replace("$ModuleDataSetWraper$", str10);
            strWraper = strWraper + str;
        }

        private static void GenRpcCode(Module m, Module.OperaterItem operate, ref string OperationDeclare, ref string OperationImpl, ref string OperationImplement, ref int num, ref int num2, ref string RpcValues, ref string CallBack, ref string InitController, ref string ContCallBacks, ref string Layer, ref string LayerCtor, ref string LayerCtoF, ref string EnterLayer, ref string EnterFunctions, ref string EnterFunctionsF, ref string CallBackARGS, ref string TestProtocol, ref string TestArgs, ref string Test2, ref string Test3, ref string Test4)
        {
            DataStruct struct2 = null;
            DataStruct struct3 = null;
            DataStruct struct4 = null;
            foreach (Module.OperaterItem.SubOperaterItem item in operate.subOperateItem)
            {
                string text1 = operate.Name + item.Name;
                if (item.Type == Module.OperateType.OP_ASK)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct2))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct2);
                    }
                    struct2.getFullName();
                    if ("      'AskName': [" != TestArgs)
                    {
                        TestArgs = TestArgs + ",\r\n";
                        TestArgs = TestArgs + "                   \"" + operate.Name + "\"";
                    }
                    else
                    {
                        TestArgs = TestArgs + "\"" + operate.Name + "\"";
                    }
                    if ("      'AskList':[" != Test3)
                    {
                        Test3 = Test3 + ",\r\n";
                        Test3 = Test3 + "                 @" + operate.Name;
                    }
                    else
                    {
                        Test3 = Test3 + "@" + operate.Name;
                    }
                    object obj2 = OperationImpl;
                    OperationImpl = string.Concat(new object[] { obj2, "RPC_CODE_", operate.Name.ToUpper(), "_REQUEST = ", (int) num, "\r\n" });
                    num++;
                    OperationImplement = OperationImplement + operate.Name + "AskPB = null\r\n";
                    DiGui(ref m, ref RpcValues, "Rpc" + operate.Name + "Ask", false);
                    string str = "    " + operate.Name + "Ask = " + operate.Name + "AskPB.prototype\r\n";
                    CallBack = CallBack + "  " + operate.Name + " : (";
                    int num3 = 0;
                    if ("      'ParamterTypelist': [" != Test4)
                    {
                        Test4 = Test4 + ",\r\n";
                        Test4 = Test4 + "                       [";
                    }
                    else
                    {
                        Test4 = Test4 + "[";
                    }
                    if ("      'ParamterList': [" != Test2)
                    {
                        Test2 = Test2 + ",\r\n";
                        Test2 = Test2 + "                       [";
                    }
                    else
                    {
                        Test2 = Test2 + "[";
                    }
                    foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                    {
                        Test2 = Test2 + ((num3 == 0) ? "" : ",");
                        Test2 = Test2 + "\"" + descriptor.FieldName + "\"";
                        Test4 = Test4 + ((num3 == 0) ? "" : ",");
                        Test4 = Test4 + "\"" + descriptor.FieldType + "\"";
                        CallBack = CallBack + ((num3 == 0) ? "" : ",");
                        CallBack = CallBack + descriptor.FieldName;
                        string str3 = str;
                        str = str3 + "    " + operate.Name + "Ask.set" + descriptor.FieldName + " " + descriptor.FieldName + "\r\n";
                        num3++;
                    }
                    Test2 = Test2 + "]";
                    Test4 = Test4 + "]";
                    string str4 = InitController;
                    InitController = str4 + "    " + operate.Name + "AskPB = Proto.build(\"Rpc" + operate.Name + "Ask\")\r\n";
                    string str5 = str;
                    str = str5 + "    mLayerMgr.sendAsk(RPC_CODE_" + operate.Name.ToUpper() + "_REQUEST," + operate.Name + "Ask, (data)->\r\n";
                    if (operate.Name.ToLower().IndexOf("syncdata") == -1)
                    {
                        str = str + "      NetTipController.hideNetTip()\r\n";
                    }
                    str = (str + "      replyCB( " + operate.Name + "ReplyPB.decode(data)) if typeof(replyCB) is \"function\"\r\n") + "    )\r\n";
                    if (operate.Name.ToLower().IndexOf("syncdata") == -1)
                    {
                        str = str + "    NetTipController.showNetTip()\r\n";
                    }
                    CallBack = CallBack + ((num3 == 0) ? "" : ",");
                    CallBack = CallBack + "replyCB) ->\r\n";
                    CallBack = CallBack + str;
                }
                if (item.Type == Module.OperateType.OP_REPLY)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct3))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct3);
                    }
                    struct3.getFullName();
                    DiGui(ref m, ref RpcValues, "Rpc" + operate.Name + "Reply", false);
                    OperationImplement = OperationImplement + operate.Name + "ReplyPB = null\r\n";
                    string str6 = InitController;
                    InitController = str6 + "    " + operate.Name + "ReplyPB = Proto.build(\"Rpc" + operate.Name + "Reply\")\r\n";
                }
                if (((item.Type == Module.OperateType.OP_NOTIFY) || (item.Type == Module.OperateType.OP_SERVER_NOTIFY)) || ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY)))
                {
                    Module.OperateType type = item.Type;
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct4))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct4);
                    }
                    struct4.getFullName();
                    object obj3 = OperationImpl;
                    OperationImpl = string.Concat(new object[] { obj3, "RPC_CODE_", operate.Name.ToUpper(), "_NOTIFY = ", (int) num, "\r\n" });
                    string str7 = LayerCtoF;
                    LayerCtoF = str7 + "        _model.Set" + operate.Name + "NotifyCB(@" + operate.Name + "CBNotify)\r\n";
                    LayerCtor = LayerCtor + "    " + operate.Name + "CBNotify:(ret_msg)->\r\n";
                    LayerCtor = LayerCtor + "        cc.log \"" + operate.Name + "CBNotify Respond \"\r\n";
                    OperationImplement = OperationImplement + operate.Name + "NotifyPB = null\r\n";
                    DiGui(ref m, ref RpcValues, "Rpc" + operate.Name + "Notify", false);
                    string str8 = InitController;
                    InitController = str8 + "    " + operate.Name + "NotifyPB = Proto.build(\"Rpc" + operate.Name + "Notify\")\r\n";
                    OperationDeclare = OperationDeclare + item.DataStructName + "CB = null\r\n";
                    if ((item.Type == Module.OperateType.OP_SERVER_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        string str9 = InitController;
                        InitController = str9 + "    mLayerMgr.registerNotify(RPC_CODE_" + operate.Name.ToUpper() + "_NOTIFY,@" + operate.Name + "CB)\r\n";
                        string str10 = ContCallBacks;
                        ContCallBacks = str10 + "  Set" + operate.Name + "NotifyCB : (cb) -> " + item.DataStructName + "CB = cb\r\n";
                        ContCallBacks = ContCallBacks + "  " + operate.Name + "CB : (data)->\r\n";
                        string str11 = ContCallBacks;
                        ContCallBacks = str11 + "    " + item.DataStructName + "CB( " + operate.Name + "NotifyPB.decode(data)) if typeof(" + item.DataStructName + "CB) is \"function\"\r\n";
                    }
                    if ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        if ("      'AskName': [" != TestArgs)
                        {
                            TestArgs = TestArgs + ",\r\n";
                            TestArgs = TestArgs + "                   \"" + operate.Name + "\"";
                        }
                        else
                        {
                            TestArgs = TestArgs + "\"" + operate.Name + "\"";
                        }
                        if ("      'AskList':[" != Test3)
                        {
                            Test3 = Test3 + ",\r\n";
                            Test3 = Test3 + "                 @" + operate.Name;
                        }
                        else
                        {
                            Test3 = Test3 + operate.Name;
                        }
                        string str2 = "    " + operate.Name + "Notify = " + operate.Name + "NotifyPB.prototype\r\n";
                        CallBack = CallBack + "  " + operate.Name + " : (";
                        int num4 = 0;
                        if ("      'ParamterTypelist': [" != Test4)
                        {
                            Test4 = Test4 + ",\r\n";
                            Test4 = Test4 + "                       [";
                        }
                        else
                        {
                            Test4 = Test4 + "[";
                        }
                        if ("      'ParamterList': [" != Test2)
                        {
                            Test2 = Test2 + ",\r\n";
                            Test2 = Test2 + "                       [";
                        }
                        else
                        {
                            Test2 = Test2 + "[";
                        }
                        foreach (DataStruct.FieldDescriptor descriptor2 in struct4.fieldItem)
                        {
                            Test2 = Test2 + ((num4 == 0) ? "" : ",");
                            Test2 = Test2 + "\"" + descriptor2.FieldName + "\"";
                            Test4 = Test4 + ((num4 == 0) ? "" : ",");
                            Test4 = Test4 + "\"" + descriptor2.FieldType + "\"";
                            CallBack = CallBack + ((num4 == 0) ? "" : ",");
                            CallBack = CallBack + descriptor2.FieldName;
                            string str12 = str2;
                            str2 = str12 + "    " + operate.Name + "Notify.set" + descriptor2.FieldName + " " + descriptor2.FieldName + "\r\n";
                            num4++;
                        }
                        Test2 = Test2 + "]";
                        Test4 = Test4 + "]";
                        CallBack = CallBack + ") ->\r\n";
                        string str13 = str2;
                        str2 = str13 + "    mLayerMgr.sendNotify(RPC_CODE_" + operate.Name.ToUpper() + "_NOTIFY," + operate.Name + "Notify)\r\n";
                        CallBack = CallBack + str2;
                    }
                    num++;
                    num2++;
                }
            }
        }

        private static void GenSyncDataCode(Module m, DataStruct ds, ref string syncIds, ref string SyncOpDefine, ref string SyncOpImp, ref string SendAllFields, ref string DBCacheField, ref string FromMemoryStream, ref string UpdataValue, ref string ToMemoryStream, ref string TestArgs, ref string GetValue, ref string RpcValues, ref string CliOperationImplement, ref string InitController)
        {
            string str = "V" + m.SyncDataVersion;
            string text1 = ds.StructName + "Wraper" + str;
            string text2 = "SyncData" + m.ModuleName + str;
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
                {
                    object obj2 = SyncOpDefine;
                    SyncOpDefine = string.Concat(new object[] { obj2, "SYNCID_", descriptor.FieldName.ToUpper(), " = ", (m.StartIdNum * 100) + descriptor.FieldId, "  #", descriptor.CNName, "\r\n" });
                    string str2 = DBCacheField;
                    DBCacheField = str2 + "  SyncID_" + descriptor.FieldName + " : () -> return SYNCID_" + descriptor.FieldName.ToUpper() + "\r\n";
                }
            }
            if (((ds.DataType == DataStruct.SyncType.UserData) || (ds.DataType == DataStruct.SyncType.ItemData)) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                object obj3 = SyncOpImp;
                SyncOpImp = string.Concat(new object[] { obj3, ds.StructName, "V", m.SyncDataVersion, "PB = null\r\n" });
                object obj4 = CliOperationImplement;
                CliOperationImplement = string.Concat(new object[] { obj4, ds.StructName, "V", m.SyncDataVersion, "PB = null\r\n" });
                object obj5 = InitController;
                InitController = string.Concat(new object[] { obj5, "    ", ds.StructName, "V", m.SyncDataVersion, "PB = Proto.build(\"Rpc", ds.StructName, "V", m.SyncDataVersion, "\")\r\n" });
                DiGui(ref m, ref RpcValues, ds.StructName, true);
            }
            UpdataValue = "";
            foreach (DataStruct.FieldDescriptor descriptor2 in ds.fieldItem)
            {
                if (descriptor2.FieldType == "string")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str3 = DBCacheField;
                        DBCacheField = str3 + "  " + descriptor2.FieldName + " : () -> return m_" + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "      when SYNCID_" + descriptor2.FieldName.ToUpper() + "\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "        if Index is -1\r\n";
                            UpdataValue = UpdataValue + "          m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "          return\r\n";
                            UpdataValue = UpdataValue + "        if dataLen is 0\r\n";
                            UpdataValue = UpdataValue + "          return\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + "[Index] = Data.readUTF8StringBySelf(dataLen)\r\n";
                        }
                        else
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = \"\"\r\n";
                            UpdataValue = UpdataValue + "        if dataLen is 0\r\n";
                            UpdataValue = UpdataValue + "          return\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + " = Data.readUTF8StringBySelf(dataLen)\r\n";
                        }
                    }
                }
                else if (descriptor2.FieldType == "sint32")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str4 = DBCacheField;
                        DBCacheField = str4 + "  " + descriptor2.FieldName + " : () -> return m_" + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "      when SYNCID_" + descriptor2.FieldName.ToUpper() + "\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "        if Index is -1\r\n";
                            UpdataValue = UpdataValue + "          m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "          return\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + "[Index] = Data.readVarint32ZigZag()\r\n";
                        }
                        else
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = 0\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + " = Data.readVarint32ZigZag()\r\n";
                        }
                    }
                }
                else if (descriptor2.FieldType == "sint64")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str5 = DBCacheField;
                        DBCacheField = str5 + "  " + descriptor2.FieldName + " : () -> return m_" + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "      when SYNCID_" + descriptor2.FieldName.ToUpper() + "\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "        if Index is -1\r\n";
                            UpdataValue = UpdataValue + "          m_" + descriptor2.FieldName + " = []\r\n";
                            UpdataValue = UpdataValue + "          return\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + "[Index] = Data.readVarint64ZigZag().toNumber()\r\n";
                        }
                        else
                        {
                            SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = 0\r\n";
                            UpdataValue = UpdataValue + "        m_" + descriptor2.FieldName + " = Data.readVarint64ZigZag().toNumber()\r\n";
                        }
                    }
                }
                else if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                {
                    string str6 = DBCacheField;
                    DBCacheField = str6 + "  " + descriptor2.FieldName + " : () -> return m_" + descriptor2.FieldName + "\r\n";
                    SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = []\r\n";
                    UpdataValue = UpdataValue + "      when SYNCID_" + descriptor2.FieldName.ToUpper() + "\r\n";
                    UpdataValue = UpdataValue + "        if Index is -1\r\n";
                    UpdataValue = UpdataValue + "          m_" + descriptor2.FieldName + " = []\r\n";
                    UpdataValue = UpdataValue + "          return\r\n";
                    if (ds.DataType == DataStruct.SyncType.RPCData)
                    {
                        object obj6 = UpdataValue;
                        UpdataValue = string.Concat(new object[] { obj6, "        m_", descriptor2.FieldName, "[Index] = Proto.build(\"Rpc", descriptor2.FieldType, "V", m.SyncDataVersion, "\").decode(Data.toBuffer())\r\n" });
                    }
                    else if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str7 = UpdataValue;
                        UpdataValue = str7 + "        m_" + descriptor2.FieldName + "[Index] = Proto.build(\"" + descriptor2.FieldType + "\").decode(Data.toBuffer())\r\n";
                    }
                }
                else
                {
                    string str8 = DBCacheField;
                    DBCacheField = str8 + "  " + descriptor2.FieldName + " : () -> return m_" + descriptor2.FieldName + "\r\n";
                    SendAllFields = SendAllFields + "m_" + descriptor2.FieldName + " = null\r\n";
                    UpdataValue = UpdataValue + "      when SYNCID_" + descriptor2.FieldName.ToUpper() + "\r\n";
                    if (ds.DataType == DataStruct.SyncType.RPCData)
                    {
                        object obj7 = UpdataValue;
                        UpdataValue = string.Concat(new object[] { obj7, "        m_", descriptor2.FieldName, " = Proto.build(\"Rpc", descriptor2.FieldType, "V", m.SyncDataVersion, "\").decode(Data.toBuffer())\r\n" });
                    }
                    else if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str9 = UpdataValue;
                        UpdataValue = str9 + "        m_" + descriptor2.FieldName + " = Proto.build(\"" + descriptor2.FieldType + "\").decode(Data.toBuffer())\r\n";
                    }
                }
            }
            if ((ds.DataType != DataStruct.SyncType.UserData) && (ds.DataType == DataStruct.SyncType.CacheData))
            {
                bool syncToClient = ds.syncToClient;
            }
            if (UpdataValue.Length > 0)
            {
                UpdataValue = "    switch SyncId\r\n" + UpdataValue;
            }
        }

        public static void Serialize(Module m, string dir, Label label1)
        {
            if (GenLangFlags.Coffee)
            {
                string path = dir + @"\COFFEE\" + m.ModuleName + @"\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string str2 = dir + @"\COFFEE\Config\";
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                StreamReader reader = new StreamReader("./Template/Model.coffee", Encoding.GetEncoding("GBK"));
                reader.ReadToEnd();
                reader.Close();
                ArrayList list = new ArrayList { 
                    "./Template/Model.coffee",
                    "./Template/Controller.coffee"
                };
                ArrayList list2 = new ArrayList {
                    path + m.ModuleName + "Model.coffee",
                    path + m.ModuleName + "Controller.coffee"
                };
                ArrayList list3 = new ArrayList();
                for (int i = 0; i < list.Count; i++)
                {
                    try
                    {
                        StreamReader reader2 = null;
                        reader2 = new StreamReader((string) list[i], Encoding.UTF8);
                        string str3 = reader2.ReadToEnd();
                        list3.Add(str3);
                        reader2.Close();
                    }
                    catch (DirectoryNotFoundException)
                    {
                        return;
                    }
                }
                label1.Text = "正在生成文件: " + path + m.ModuleName + ".coffee";
                label1.Refresh();
                string operationDeclare = "";
                string operationImpl = "";
                string operationImplement = "";
                string text1 = m.SyncDataVersion.ToString();
                string syncIds = "";
                string syncOpDefine = "";
                string syncOpImp = "";
                string sendAllFields = "";
                string dBCacheField = "";
                string fromMemoryStream = "";
                string updataValue = "";
                string rpcValues = "";
                string toMemoryStream = "";
                string callBack = "";
                string callBackARGS = "";
                string initController = "";
                string contCallBacks = "";
                string layer = "";
                string layerCtor = "";
                string layerCtoF = "";
                string enterLayer = "";
                string enterFunctions = "";
                string enterFunctionsF = "";
                string testProtocol = "";
                string testArgs = "";
                string getValue = "";
                bool flag = false;
                int num = 0;
                int num3 = 0;
                string str29 = "\tMODULE_ID_" + m.ModuleName.ToUpper();
                int num4 = 0x2e - str29.Length;
                while (num4-- > 0)
                {
                    str29 = str29 + " ";
                }
                object obj2 = str29;
                str29 = string.Concat(new object[] { obj2, "= ", m.StartIdNum, ",\t//", m.CNName, "模块ID\r\n" });
                num = (m.StartIdNum * 100) + 0x33;
                enterLayer = "\tlocal btnChat = nil\r\n";
                num3 = 1;
                layerCtor = "";
                testProtocol = testProtocol + "askList." + m.ModuleName + " = {}\r\n";
                object obj3 = operationImpl;
                operationImpl = string.Concat(new object[] { obj3, "ModuleId = ", m.StartIdNum, "\r\n" });
                testArgs = testArgs + "      'AskName': [";
                string str30 = "      'ParamterList': [";
                string str31 = "      'AskList':[";
                string str32 = "      'ParamterTypelist': [";
                map = new Dictionary<string, int>();
                foreach (Module.OperaterItem item in m.operateItem)
                {
                    GenRpcCode(m, item, ref operationDeclare, ref operationImpl, ref operationImplement, ref num, ref num3, ref rpcValues, ref callBack, ref initController, ref contCallBacks, ref layer, ref layerCtor, ref layerCtoF, ref enterLayer, ref enterFunctions, ref enterFunctionsF, ref callBackARGS, ref testProtocol, ref testArgs, ref str30, ref str31, ref str32);
                }
                testArgs = testArgs + "]\r\n";
                str30 = str30 + "]\r\n";
                str31 = str31 + "]\r\n";
                str32 = str32 + "]\r\n";
                testArgs = testArgs + str30 + str31 + str32;
                num3 = 0;
                foreach (DataStruct struct2 in m.moduleDataStruct)
                {
                    if (((struct2.DataType != DataStruct.SyncType.CacheData) && (struct2.DataType != DataStruct.SyncType.ModuleData)) && (struct2.DataType != DataStruct.SyncType.UserData))
                    {
                        struct2.StructName.ToLower().IndexOf("rpc");
                    }
                }
                updataValue = "";
                foreach (DataStruct struct3 in m.moduleDataStruct)
                {
                    if (((struct3.DataType == DataStruct.SyncType.CacheData) || (struct3.DataType == DataStruct.SyncType.ModuleData)) || (struct3.DataType == DataStruct.SyncType.UserData))
                    {
                        flag = true;
                        string text2 = struct3.SaveToDB.ToString();
                        string structName = struct3.StructName;
                        DataStruct.SyncType dataType = struct3.DataType;
                        DataStruct.SyncType type2 = struct3.DataType;
                        DataStruct.SyncType type3 = struct3.DataType;
                        string text4 = string.Concat(new object[] { "#include \"", m.ModuleName, "V", m.SyncDataVersion, "Data.h\"\r\n#include \"", m.ModuleName, "V", m.SyncDataVersion, "DataWraper.h\"\r\n" });
                        string text5 = string.Concat(new object[] { "#include \"", m.ModuleName, "V", m.SyncDataVersion, "DataWraper.h\"\r\n" });
                        string text6 = struct3.StructName;
                        GenSyncDataCode(m, struct3, ref syncIds, ref syncOpDefine, ref syncOpImp, ref sendAllFields, ref dBCacheField, ref fromMemoryStream, ref updataValue, ref toMemoryStream, ref testArgs, ref getValue, ref rpcValues, ref operationImplement, ref initController);
                        string text7 = string.Concat(new object[] { m.ModuleName, struct3.StructName, "WraperV", m.SyncDataVersion, " m_syncData", struct3.StructName, ";" });
                        string text8 = "SetDataWraper( &m_syncData" + struct3.StructName + " );";
                    }
                }
                syncOpDefine = syncOpDefine + sendAllFields + syncOpImp;
                IEnumerator enumerator = DataStructConverter.CommDataStruct.GetEnumerator();
                //using (IEnumerator enumerator = DataStructConverter.CommDataStruct.GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        DataStruct current = (DataStruct) enumerator.Current;
                    }
                }
                for (int j = 0; j < list3.Count; j++)
                {
                    string str33 = (string) list3[j];
                    str33 = str33.Replace("$TEMPLATE$", m.ModuleName).Replace("$PBArgs$", rpcValues).Replace("$TempVar$", operationDeclare).Replace("$MoudleVar$", operationImpl).Replace("$PBVar$", operationImplement).Replace("$PBConfig$ ", initController).Replace("$PBVarInit$", fromMemoryStream).Replace("$PBFun$", callBack).Replace("$TempVar2$", syncOpDefine).Replace("$updateWhen$", updataValue).Replace("$SDNotifyF$", contCallBacks).Replace("$CONNOTIFY$", layerCtoF).Replace("$CONNOTIFYFUNCTION$", layerCtor).Replace("$TEST$", testArgs).Replace("$DBCacheField$", dBCacheField);
                    list3[j] = str33;
                }
                for (int k = 0; k < list2.Count; k++)
                {
                    string str34 = (string) list2[k];
                    if ((((str34.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data" })) <= -1) || flag) && ((str34.IndexOf(m.ModuleName + "DBCache") <= -1) || flag)) && ((str34.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "DataWraper" })) <= -1) || flag))
                    {
                        StreamWriter writer = null;
                        UTF8Encoding encoding = new UTF8Encoding(false);
                        writer = new StreamWriter((string) list2[k], false, encoding);
                        writer.Write((string) list3[k]);
                        writer.Close();
                    }
                }
            }
        }
    }
}

