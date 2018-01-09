namespace Editor
{
    using System;
    using System.Collections;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class LuaSerializer
    {
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

        private static void GenRpcCode(Module m, Module.OperaterItem operate, ref string OperationDeclare, ref string OperationImpl, ref string OperationImplement, ref int num, ref int num2, ref string RpcValues, ref string CallBack, ref string InitController, ref string ContCallBacks, ref string Layer, ref string LayerCtor, ref string LayerCtoF, ref string EnterLayer, ref string EnterFunctions, ref string EnterFunctionsF, ref string CallBackARGS, ref string TestProtocol)
        {
            DataStruct struct2 = null;
            DataStruct struct3 = null;
            DataStruct struct4 = null;
            foreach (Module.OperaterItem.SubOperaterItem item in operate.subOperateItem)
            {
                object obj2;
                string str3;
                string text1 = operate.Name + item.Name;
                if (item.Type == Module.OperateType.OP_ASK)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct2))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct2);
                    }
                    struct2.getFullName();
                    obj2 = OperationDeclare;
                    OperationDeclare = string.Concat(new object[] { obj2, "local RPC_CODE_", m.ModuleName.ToUpper(), "_", operate.Name.ToUpper(), "_REQUEST = ", (int) num, "\r\n" });
                    str3 = Layer;
                    Layer = str3 + m.ModuleName + "Layer.BTN" + operate.Name.ToUpper() + " = \"Btn" + operate.Name + "\"\r\n";
                    string str4 = Layer;
                    Layer = str4 + m.ModuleName + "Layer." + operate.Name.ToUpper() + "PARA = " + m.ModuleName + "Rpc_pb." + m.ModuleName + item.DataStructName + "() \r\n";
                    string str5 = EnterLayer;
                    EnterLayer = str5 + "\tbtnChat =  self.resourceNode_:getChildByName(" + m.ModuleName + "Layer.BTN" + operate.Name.ToUpper() + ")\r\n";
                    EnterLayer = EnterLayer + "\tbtnChat:addTouchEventListener(handler(self, self.on" + operate.Name + "))\r\n";
                    string str6 = EnterFunctions;
                    EnterFunctions = str6 + "function " + m.ModuleName + "Layer:on" + operate.Name + "()\r\n";
                    EnterFunctions = EnterFunctions + "\tlocal callBack = handler(self, self." + operate.Name + "CallBack)\r\n";
                    string str7 = EnterFunctions;
                    EnterFunctions = str7 + "\tlocal _pbData = " + m.ModuleName + "Layer." + operate.Name.ToUpper() + "PARA:SerializeToString()\r\n";
                    string str8 = EnterFunctions;
                    EnterFunctions = str8 + "\t" + m.ModuleName + "ContController." + operate.Name + "(_pbData, callBack)\r\n";
                    EnterFunctions = EnterFunctions + "end\r\n";
                    string str9 = EnterFunctionsF;
                    EnterFunctionsF = str9 + "function " + m.ModuleName + "Layer:" + operate.Name + "CallBack(msg)\r\n";
                    EnterFunctionsF = EnterFunctionsF + "end\r\n";
                    num++;
                    TestProtocol = TestProtocol + "\r\nlocal t = {}\r\n";
                    TestProtocol = TestProtocol + "t.name = \"" + operate.Name + "\"\r\n";
                    TestProtocol = TestProtocol + "t.para = {";
                    int num3 = 0;
                    string str10 = OperationImplement;
                    OperationImplement = str10 + "function " + operate.Name + "(self,";
                    string str = "\tlocal PB = self.rpc_pb." + m.ModuleName + "Rpc" + operate.Name + "Ask()\r\n";
                    foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                    {
                        TestProtocol = TestProtocol + ((num3 == 0) ? "" : ",");
                        OperationImplement = OperationImplement + ((num3 == 0) ? "" : ",");
                        num3++;
                        OperationImplement = OperationImplement + descriptor.FieldName;
                        if (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
                            str = str + "\tfor i,v in ipairs(" + descriptor.FieldName + ") do\r\n";
                            str = str + "\t\ttable.insert(PB." + descriptor.FieldName + ",v)\r\n";
                            str = str + "\tend\r\n";
                        }
                        else
                        {
                            string str11 = str;
                            str = str11 + "\tPB." + descriptor.FieldName + " = " + descriptor.FieldName + "\r\n";
                        }
                        if (descriptor.FieldType == "string")
                        {
                            TestProtocol = TestProtocol + "{name=\"" + descriptor.FieldName + "\",t=2}";
                        }
                        else if ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64") || (descriptor.FieldType == "uint64"))
                        {
                            TestProtocol = TestProtocol + "{name=\"" + descriptor.FieldName + "\",t=1}";
                        }
                        else
                        {
                            TestProtocol = TestProtocol + "{name=\"" + descriptor.FieldName + "\",t=3}";
                        }
                    }
                    str = str + "\tlocal pb_data = PB:SerializeToString()\r\n";
                    OperationImplement = OperationImplement + ((num3 == 0) ? "" : ",") + "_hanlder)\r\n";
                    OperationImplement = OperationImplement + str;
                    OperationImplement = OperationImplement + "\tlocal function callback(_data)\r\n";
                    if (operate.Name.ToLower() != "syncdata")
                    {
                        OperationImplement = OperationImplement + "\t\thideNetTip(self)\r\n";
                    }
                    OperationImplement = OperationImplement + "\t\tif _hanlder then\r\n";
                    string str12 = OperationImplement;
                    OperationImplement = str12 + "\t\t\tlocal ret_msg = self.rpc_pb." + m.ModuleName + "Rpc" + operate.Name + "Reply()\r\n";
                    OperationImplement = OperationImplement + "\t\t\tret_msg:ParseFromString(_data)\r\n";
                    OperationImplement = OperationImplement + "\t\t\t _hanlder(ret_msg)\r\n";
                    OperationImplement = OperationImplement + "\t\tend\r\n";
                    OperationImplement = OperationImplement + "\tend\r\n";
                    string str13 = OperationImplement;
                    OperationImplement = str13 + "\tMLayerMgr.SendAsk(RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_REQUEST, pb_data, callback)\r\n";
                    if (operate.Name.ToLower() != "syncdata")
                    {
                        OperationImplement = OperationImplement + "\tshowNetTip(self)\r\n";
                    }
                    OperationImplement = OperationImplement + "end\r\n";
                    TestProtocol = TestProtocol + "}\r\n";
                    string str14 = TestProtocol;
                    TestProtocol = str14 + "t.hand = " + m.ModuleName + "Model." + operate.Name + "\r\n";
                    string str15 = TestProtocol;
                    TestProtocol = str15 + "t.pb = " + m.ModuleName + "Rpc_pb." + m.ModuleName + "Rpc" + operate.Name + "Ask()\r\n";
                    TestProtocol = TestProtocol + "table.insert(askList." + m.ModuleName + ",t)\r\n";
                }
                if (item.Type == Module.OperateType.OP_REPLY)
                {
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct3))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct3);
                    }
                    struct3.getFullName();
                    string str16 = RpcValues;
                    RpcValues = str16 + "function " + m.ModuleName + "Controller." + operate.Name + "(_pbData,_callBack)\r\n";
                    RpcValues = RpcValues + "\tlocal function ret(data)\r\n";
                    string str17 = RpcValues;
                    RpcValues = str17 + "\t\tlocal ret_msg = " + m.ModuleName + "Rpc_pb." + m.ModuleName + item.DataStructName + "() \r\n";
                    RpcValues = RpcValues + "\t\tret_msg:ParseFromString(data)\r\n";
                    RpcValues = RpcValues + "\t\tif _callBack then\r\n";
                    RpcValues = RpcValues + "\t\t\t_callBack(ret_msg)\r\n";
                    RpcValues = RpcValues + "\t\tend\r\n";
                    RpcValues = RpcValues + "\tend\r\n";
                    RpcValues = RpcValues + "\tlocal pb_data = _pbData:SerializeToString()\r\n";
                    string str18 = RpcValues;
                    RpcValues = str18 + "\t" + m.ModuleName + "RPC." + operate.Name + "(pb_data,ret)\r\n";
                    RpcValues = RpcValues + "end\r\n";
                }
                if (((item.Type == Module.OperateType.OP_NOTIFY) || (item.Type == Module.OperateType.OP_SERVER_NOTIFY)) || ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY)))
                {
                    Module.OperateType type = item.Type;
                    if (!DataStruct.DataStructDic.TryGetValue(item.DataStructName, out struct4))
                    {
                        DataStruct.DataStructDic.TryGetValue(m.ModuleName + item.DataStructName, out struct4);
                    }
                    struct4.getFullName();
                    object obj3 = OperationDeclare;
                    OperationDeclare = string.Concat(new object[] { obj3, "local RPC_CODE_", m.ModuleName.ToUpper(), "_", operate.Name.ToUpper(), "_NOTIFY = ", (int) num, ";\r\n" });
                    if ((item.Type == Module.OperateType.OP_SERVER_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        string str19 = OperationImpl;
                        OperationImpl = str19 + "\tMLayerMgr.RegNotifyHd(RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_NOTIFY,handler(self,self." + operate.Name + "CB))\r\n";
                        CallBack = CallBack + "-- 给c层 注册服务器通知回调\r\n";
                        string str20 = CallBack;
                        //CallBack = str20 + "function " + m.ModuleName + "Model:register" + operate.Name + "CBNotify(_hanlder)\r\n";
                        CallBack = str20 + "function register" + operate.Name + "CBNotify(self,_hanlder)\r\n";
                        CallBack = CallBack + "\tif not self." + operate.Name + "CBNotifyCallBack then\r\n";
                        CallBack = CallBack + "\t\tself." + operate.Name + "CBNotifyCallBack = {}\r\n";
                        CallBack = CallBack + "\tend\r\n";
                        CallBack = CallBack + "\ttable.insert(self." + operate.Name + "CBNotifyCallBack,_hanlder)\r\n";
                        CallBack = CallBack + "end\r\n";
                        CallBack = CallBack + "-- 收到服务器的通知，广播给c层注册的模块\r\n";
                        string str21 = CallBack;
                        //CallBack = str21 + "function " + m.ModuleName + "Model:" + operate.Name + "CB(notifyMsg)\r\n";
                        CallBack = str21 + "function " + operate.Name + "CB(self,notifyMsg)\r\n";
                        CallBack = CallBack + "\tif self." + operate.Name + "CBNotifyCallBack then\r\n";
                        string str22 = CallBack;
                        CallBack = str22 + "\t\tlocal ret_msg = self.rpc_pb." + m.ModuleName + item.DataStructName + "() \r\n";
                        CallBack = CallBack + "\t\t ret_msg:ParseFromString(notifyMsg)\r\n";
                        CallBack = CallBack + "\t\t for i,callback in ipairs(self." + operate.Name + "CBNotifyCallBack) do\r\n";
                        CallBack = CallBack + "\t\t\tcallback(ret_msg)\r\n";
                        CallBack = CallBack + "\t\tend\r\n";
                        CallBack = CallBack + "\tend\r\n";
                        CallBack = CallBack + "end\r\n";
                        string str23 = CallBack;
                        //CallBack = str23 + "function " + m.ModuleName + "Model:unregister" + operate.Name + "CBNotify(_hanlder)\r\n";
                        CallBack = str23 + "function unregister" + operate.Name + "CBNotify(self,_hanlder)\r\n";
                        CallBack = CallBack + "\tif nil ~= self." + operate.Name + "CBNotifyCallBack then\r\n";
                        CallBack = CallBack + "\t\tfor i,callback in ipairs(self." + operate.Name + "CBNotifyCallBack ) do\r\n";
                        CallBack = CallBack + "\t\t\tif callback == _hanlder then\r\n";
                        CallBack = CallBack + "\t\t\t\ttable.remove(self." + operate.Name + "CBNotifyCallBack, i )\r\n";
                        CallBack = CallBack + "\t\t\tend\r\n";
                        CallBack = CallBack + "\t\tend\r\n";
                        CallBack = CallBack + "\tend\r\n";
                        CallBack = CallBack + "end\r\n";
                    }
                    if ((item.Type == Module.OperateType.OP_CLIENT_NOTIFY) || (item.Type == Module.OperateType.OP_DUPLEX_NOTIFY))
                    {
                        CallBack = CallBack + "-- 给c层 注册服务器通知回调\r\n";
                        int num4 = 0;
                        string str24 = CallBack;
                        //CallBack = str24 + "function " + m.ModuleName + "Model:" + operate.Name + "Notify(";
                        CallBack = str24 + "function " + operate.Name + "Notify(self,";
                        string str2 = "\tlocal PB = self.rpc_pb." + m.ModuleName + "Rpc" + operate.Name + "Notify()\r\n";
                        foreach (DataStruct.FieldDescriptor descriptor2 in struct4.fieldItem)
                        {
                            CallBack = CallBack + ((num4 == 0) ? "" : ",");
                            CallBack = CallBack + descriptor2.FieldName;
                            str3 = str2;
                            str2 = str3 + "\tPB." + descriptor2.FieldName + " = " + descriptor2.FieldName + "\r\n";
                            if (num4 == 0)
                            {
                                num4 = struct4.fieldItem.Count;
                            }
                            num4--;
                        }
                        CallBack = CallBack + ")\r\n";
                        CallBack = CallBack + str2;
                        CallBack = CallBack + "\tlocal pb_data = PB:SerializeToString()\r\n";
                        str3 = CallBack;
                        CallBack = str3 + "\tMLayerMgr.SendNotify(RPC_CODE_" + m.ModuleName.ToUpper() + "_" + operate.Name.ToUpper() + "_NOTIFY, pb_data)\r\n";
                        CallBack = CallBack + "end\r\n";
                    }
                    obj2 = CallBackARGS;
                    CallBackARGS = string.Concat(new object[] { obj2, (num2 == 1) ? "" : ",", "_callback", (int) num2 });
                    str3 = InitController;
                    InitController = str3 + "\tself.model:register" + operate.Name + "CBNotify(handler(self,self." + operate.Name + "CBNotify))\r\n";
                    str3 = ContCallBacks;
                    ContCallBacks = str3 + "function " + m.ModuleName + "Controller:" + operate.Name + "CBNotify(ret_msg)\r\n";
                    ContCallBacks = ContCallBacks + "end\r\n";
                    obj2 = LayerCtor;
                    LayerCtor = string.Concat(new object[] { obj2, "\tlocal cb", (int) num2, " = handler(self,self.", operate.Name, "CallBack)\r\n" });
                    str3 = LayerCtoF;
                    LayerCtoF = str3 + "function " + m.ModuleName + "Layer:" + operate.Name + "CallBack(msg)\r\n";
                    LayerCtoF = LayerCtoF + "end\r\n";
                    num++;
                    num2++;
                }
            }
        }

        private static void GenSyncDataCode(Module m, DataStruct ds, ref string syncIds, ref string SyncOpDefine, ref string SyncOpImp, ref string SendAllFields, ref string DBCacheField, ref string FromMemoryStream, ref string UpdataValue, ref string ToMemoryStream, ref string TestArgs, ref string GetValue, ref string SyncOpDefine2, ref string Require)
        {
            string str = "V" + m.SyncDataVersion;
            string text1 = ds.StructName + "Wraper" + str;
            string text2 = "SyncData" + m.ModuleName + str;
            int num = 1;
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                if (SyncOpDefine2 == "")
                {
                    SyncOpDefine2 = string.Concat(new object[] { "\tself.data_pb=", m.ModuleName, "V", m.SyncDataVersion, "Data_pb\r\n" });
                }
                if (Require == "")
                {
                    //Require = string.Concat(new object[] { "require(\"app.", m.ModuleName, ".", m.ModuleName, "V", m.SyncDataVersion, "Data_pb\")" });
                    Require = string.Concat(new object[] { "require(\"3rd/pblua/",m.ModuleName, "V", m.SyncDataVersion, "Data_pb\")" });
                }
                foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
                {
                    object obj2 = SyncOpDefine;
                    SyncOpDefine = string.Concat(new object[] { obj2, m.ModuleName.ToUpper(), "_", descriptor.FieldName.ToUpper(), " = ", (m.StartIdNum * 100) + descriptor.FieldId, "\r\n" });
                    num++;
                }
            }
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                object obj3 = SyncOpImp;
                SyncOpImp = string.Concat(new object[] { obj3, "local v = ", m.ModuleName, "V", m.SyncDataVersion, "Data_pb.", m.ModuleName, ds.StructName, "V", m.SyncDataVersion, "()\r\n" });
            }
            else
            {
                SyncOpImp = SyncOpImp + "return nil\r\n";
            }
            SendAllFields = SendAllFields + "\r\n";
            DBCacheField = DBCacheField + "\r\n";
            FromMemoryStream = "function " + m.ModuleName + "Data.FromMemoryStream(data)\r\n";
            ToMemoryStream = "function " + m.ModuleName + "Data.ToMemoryStream()\r\n";
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                object obj4 = FromMemoryStream;
                FromMemoryStream = string.Concat(new object[] { obj4, "\tlocal pb = ", m.ModuleName, "V", m.SyncDataVersion, "Data_pb.", m.ModuleName, ds.StructName, "V", m.SyncDataVersion, "()\r\n" });
                FromMemoryStream = FromMemoryStream + "\tpb:ParseFromString(data)\r\n";
                FromMemoryStream = FromMemoryStream + "\t" + m.ModuleName + "Data.FromPB(pb)\r\n";
                ToMemoryStream = ToMemoryStream + "\tlocal v = " + m.ModuleName + "Data.ToPB()\r\n";
                ToMemoryStream = ToMemoryStream + "\tlocal pb_data = v:SerializeToString()\r\n";
                ToMemoryStream = ToMemoryStream + "\treturn pb_data\r\n";
            }
            else
            {
                ToMemoryStream = ToMemoryStream + "\treturn nil\r\n";
            }
            FromMemoryStream = FromMemoryStream + "end";
            ToMemoryStream = ToMemoryStream + "end";
            UpdataValue = "";
            UpdataValue = "\tlocal ret_msg = self.data_pb." + m.ModuleName + "V" + m.SyncDataVersion + "Data_pb\r\n";
            UpdataValue += "\tret_msg:ParseFromString(uf)\r\n";
            bool flag = true;
            foreach (DataStruct.FieldDescriptor descriptor2 in ds.fieldItem)
            {
                string str2;
                if (descriptor2.FieldType == "string")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {

                        //                         str2 = UpdataValue;
                        //                         UpdataValue = str2 + "\t" + (flag ? "if" : "elseif") + "  Id == " + m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper() + " then\r\n";
                        //                         string str3 = GetValue;
                        //                         GetValue = str3 + "\t" + (flag ? "if" : "elseif") + "  Id == " + descriptor2.FieldName.ToUpper() + " then\r\n";
                        //                         if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        //                         {
                        //                             UpdataValue = UpdataValue + "\t\tif Index<0 then\r\n";
                        //                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + " = {}\r\n";
                        //                             UpdataValue = UpdataValue + "\t\telse\r\n";
                        //                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + "[Index] = tostring(data)\r\n";
                        //                             UpdataValue = UpdataValue + "\t\tend\r\n";
                        //                             GetValue = GetValue + "\t\tif Index<0 then\r\n";
                        //                             GetValue = GetValue + "\t\t\treturn " + descriptor2.FieldName + "\r\n";
                        //                             GetValue = GetValue + "\t\telse\r\n";
                        //                             GetValue = GetValue + "\t\t\treturn " + descriptor2.FieldName + "[Index]\r\n";
                        //                             GetValue = GetValue + "\t\tend\n";
                        //                         }
                        //                         else
                        //                         {
                        //                             UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = tostring(data)\r\n";
                        //                             GetValue = GetValue + "\t\treturn " + descriptor2.FieldName + "\r\n";
                        //                         }
                        //                         string str4 = SyncOpDefine2;
                        //                         SyncOpDefine2 = str4 + "\tself.m_" + descriptor2.FieldName + " = " + ((descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "{}" : "\"\"") + "\r\n";
                        //                         string str5 = SyncOpImp;
                        //                         SyncOpImp = str5 + "\tv." + descriptor2.FieldName + " = " + m.ModuleName + "Data.m_" + descriptor2.FieldName + "\r\n";
                        //                         string str6 = SendAllFields;
                        //                         SendAllFields = str6 + "\t" + m.ModuleName + "Data.m_" + descriptor2.FieldName + " = v." + descriptor2.FieldName + "\r\n";
                        //                     }
                        str2 = UpdataValue;
                        //msg: HasField('Result')
                        string keyUpdateField = m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper();
                        string hasField = " ret_msg:HasField('" + descriptor2.FieldName + "')";
                        UpdataValue = str2 + "\t" + (flag ? "if" : "end\r\n\tif") + hasField + " then\r\n";
                        string str3 = GetValue;
                        //GetValue = str3 + "\t" + (flag ? "if" : "elseif") + "  Id == " + descriptor2.FieldName.ToUpper() + " then\r\n";
                        GetValue = str3 + "\t" + (flag ? "if" : "elseif") + "  Id == " + keyUpdateField + " then\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
                            //                             UpdataValue = UpdataValue + "\t\tif Index<0 then\r\n";
                            //                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + " = {}\r\n";
                            //                             UpdataValue = UpdataValue + "\t\telse\r\n";
                            //                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + "[Index] = tostring(data)\r\n";
                            //                             UpdataValue = UpdataValue + "\t\tend\r\n";
                            
                            GetValue = GetValue + "\t\tif Index<0 then\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                            GetValue = GetValue + "\t\telse\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "[Index]\r\n";
                            GetValue = GetValue + "\t\tend\n";
                        }
                        else
                        {
                            //UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                            GetValue = GetValue + "\t\treturn  self.m_" + descriptor2.FieldName + "\r\n";
                        }
                        UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "\t\tdataCallback(self," + keyUpdateField + ")\r\n";
                        string str4 = SyncOpDefine2;
                        SyncOpDefine2 = str4 + "\tself.m_" + descriptor2.FieldName + " = " + ((descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "{}" : "\"\"") + "\r\n";
                        string str5 = SyncOpImp;
                        SyncOpImp = str5 + "\tv." + descriptor2.FieldName + " = " + m.ModuleName + "Data.m_" + descriptor2.FieldName + "\r\n";
                        string str6 = SendAllFields;
                        SendAllFields = str6 + "\t" + m.ModuleName + "Data.m_" + descriptor2.FieldName + " = v." + descriptor2.FieldName + "\r\n";
                    }
                }
                else if (descriptor2.FieldType == "sint32")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str7 = UpdataValue;
                        string keyUpdateField = m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper();
                        string hasField = " ret_msg:HasField('" + descriptor2.FieldName + "')";
                        UpdataValue = str7 + "\t" + (flag ? "if" : "end\r\n\tif") + hasField + " then\r\n";
                        string str8 = GetValue;
                        GetValue = str8 + "\t" + (flag ? "if" : "elseif") + "  Id == " + keyUpdateField + " then\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
//                             UpdataValue = UpdataValue + "\t\tif Index<0 then\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + " = {}\r\n";
//                             UpdataValue = UpdataValue + "\t\telse\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tlocal num = ReadVarint32(data)\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + "[Index] = num\r\n";
//                             UpdataValue = UpdataValue + "\t\tend\r\n";
                            GetValue = GetValue + "\t\tif Index<0 then\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                            GetValue = GetValue + "\t\telse\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "[Index]\r\n";
                            GetValue = GetValue + "\t\tend\n";
                        }
                        else
                        {
                            //UpdataValue = UpdataValue + "\t\tlocal num = ReadVarint32(data)\r\n";
                            //UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                            GetValue = GetValue + "\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                        }
                        UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "\t\tdataCallback(self," + keyUpdateField + ")\r\n";
                        string str9 = SyncOpDefine2;
                        SyncOpDefine2 = str9 + "\tself.m_" + descriptor2.FieldName + " = " + ((descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "{}" : "0") + "\r\n";
                        string str10 = SyncOpImp;
                        SyncOpImp = str10 + "\tv." + descriptor2.FieldName + " = " + m.ModuleName + "Data.m_" + descriptor2.FieldName + "\r\n";
                        string str11 = SendAllFields;
                        SendAllFields = str11 + "\t" + m.ModuleName + "Data.m_" + descriptor2.FieldName + " = v." + descriptor2.FieldName + "\r\n";
                    }
                }
                else if (descriptor2.FieldType == "sint64" || descriptor2.FieldType == "uint64")
                {
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str12 = UpdataValue;
                        string keyUpdateField = m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper();
                        string hasField = " ret_msg:HasField('" + descriptor2.FieldName + "')";
                        UpdataValue = str12 + "\t" + (flag ? "if" : "end\r\n\tif") + hasField + " then\r\n";
                        string str13 = GetValue;
                        GetValue = str13 + "\t" + (flag ? "if" : "elseif") + "  Id == " + keyUpdateField + " then\r\n";
                        if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                        {
//                             UpdataValue = UpdataValue + "\t\tif Index<0 then\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + " = {}\r\n";
//                             UpdataValue = UpdataValue + "\t\telse\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tlocal num = ReadVarint64(data)\r\n";
//                             UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + "[Index] = num\r\n";
//                             UpdataValue = UpdataValue + "\t\tend\r\n";
                            GetValue = GetValue + "\t\tif Index<0 then\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                            GetValue = GetValue + "\t\telse\r\n";
                            GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "[Index]\r\n";
                            GetValue = GetValue + "\t\tend\n";
                        }
                        else
                        {
                            //UpdataValue = UpdataValue + "\t\tlocal num = ReadVarint64(data)\r\n";
                            UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = num\r\n";
                            GetValue = GetValue + "\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                        }
                        UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                        UpdataValue = UpdataValue + "\t\tdataCallback(self," + keyUpdateField + ")\r\n";
                        string str14 = SyncOpDefine2;
                        SyncOpDefine2 = str14 + "\tself.m_" + descriptor2.FieldName + " = " + ((descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated) ? "{}" : "0") + "\r\n";
                        string str15 = SyncOpImp;
                        SyncOpImp = str15 + "\tv." + descriptor2.FieldName + " = " + m.ModuleName + "Data.m_" + descriptor2.FieldName + "\r\n";
                        string str16 = SendAllFields;
                        SendAllFields = str16 + "\t" + m.ModuleName + "Data.m_" + descriptor2.FieldName + " = v." + descriptor2.FieldName + "\r\n";
                    }
                }
                else if (descriptor2.PreDefine == DataStruct.FieldDescriptor.PreDefineType.repeated)
                {
                    string keyUpdateField = m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper();
                    string hasField = " ret_msg:HasField('" + descriptor2.FieldName + "')";
                    if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                    {
                        string str17 = UpdataValue;
                        UpdataValue = str17 + "\t" + (flag ? "if" : "end\r\n\tif") + hasField + " then\r\n";
                        string str18 = GetValue;
                        GetValue = str18 + "\t" + (flag ? "if" : "elseif") + "  Id == " + keyUpdateField + " then\r\n";
                        //UpdataValue = UpdataValue + "\t\tif Index < 0 then\r\n";
                        //UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + " = {}\r\n";
                        //UpdataValue = UpdataValue + "\t\telse\r\n";
                        GetValue = GetValue + "\t\tif Index<0 then\r\n";
                        GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                        GetValue = GetValue + "\t\telse\r\n";
                        GetValue = GetValue + "\t\t\treturn self.m_" + descriptor2.FieldName + "[Index]\r\n";
                        GetValue = GetValue + "\t\tend\n";
                        UpdataValue = UpdataValue + "\t\t\tif self.m_" + descriptor2.FieldName + "[Index] == nil then\r\n";
                        object obj5 = UpdataValue;
                        //UpdataValue = string.Concat(new object[] { obj5, "\t\t\t\tself.m_", descriptor2.FieldName, "[Index] = ", m.ModuleName, "V", m.SyncDataVersion, "Data_pb.", m.ModuleName, descriptor2.FieldType, "V", m.SyncDataVersion, "()\r\n" });
                        //UpdataValue = UpdataValue + "\t\t\tend\r\n";
                        //UpdataValue = UpdataValue + "\t\t\tself.m_" + descriptor2.FieldName + "[Index]:ParseFromString(data)\r\n";
                        //UpdataValue = UpdataValue + "\t\tend\r\n";
                        SyncOpDefine2 = SyncOpDefine2 + "\tself.m_" + descriptor2.FieldName + " = {}\r\n";
                        SyncOpImp = SyncOpImp + "\tfor i,data in ipairs(self.m_" + descriptor2.FieldName + ") do \r\n";
                        SyncOpImp = SyncOpImp + "\t\ttable.insert(v." + descriptor2.FieldName + ",data.ToPB())\r\n";
                        SyncOpImp = SyncOpImp + "\tend\r\n";
                        SendAllFields = SendAllFields + "\tself.m_" + descriptor2.FieldName + " = {}\r\n";
                        SendAllFields = SendAllFields + "\tfor i,data in ipairs(v." + descriptor2.FieldName + ") do\r\n";
                        string str19 = SendAllFields;
                        SendAllFields = str19 + "\t\ttable.insert(self.m_" + descriptor2.FieldName + ",self.m_" + descriptor2.FieldName + "[i].FromPB(v." + descriptor2.FieldName + "[i]))\r\n";
                        SendAllFields = SendAllFields + "\tend\r\n";
                    }
                    UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                    UpdataValue = UpdataValue + "\t\tdataCallback(self," + keyUpdateField + ")\r\n";
                    DBCacheField = DBCacheField + "function self.Set" + descriptor2.FieldName + "(Index,v)\r\n";
                    DBCacheField = DBCacheField + "\tself.m_" + descriptor2.FieldName + "[Index] = v\r\n";
                    DBCacheField = DBCacheField + "end\r\n";
                }
                else if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
                {
                    string str20 = UpdataValue;
                    string keyUpdateField = m.ModuleName.ToUpper() + "_" + descriptor2.FieldName.ToUpper();
                    string hasField = " ret_msg:HasField('" + descriptor2.FieldName + "')";
                    UpdataValue = str20 + "\t" + (flag ? "if" : "end\r\n\tif") + hasField + " then\r\n";
                    string str21 = GetValue;
                    GetValue = str21 + "\t" + (flag ? "if" : "elseif") + "  Id == " + keyUpdateField + " then\r\n";
                    //UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + ":ParseFromString(data)\r\n";
                    UpdataValue = UpdataValue + "\t\tself.m_" + descriptor2.FieldName + " = ret_msg." + descriptor2.FieldName + "\r\n";
                    UpdataValue = UpdataValue + "\t\tdataCallback(self," + keyUpdateField + ")\r\n";
                    GetValue = GetValue + "\t\treturn self.m_" + descriptor2.FieldName + "\r\n";
                    object obj6 = SyncOpDefine2;
                    SyncOpDefine2 = string.Concat(new object[] { obj6, "\tself.m_", descriptor2.FieldName, " = ", m.ModuleName, "V", m.SyncDataVersion, "Data_pb.", m.ModuleName, descriptor2.FieldType, "V", m.SyncDataVersion, "()\r\n" });
                    string str22 = SyncOpImp;
                    SyncOpImp = str22 + "\tv." + descriptor2.FieldName + " = self.m_" + descriptor2.FieldName + "\r\n";
                    str2 = SendAllFields;
                    SendAllFields = str2 + "\tself.m_" + descriptor2.FieldName + " = self.m_" + descriptor2.FieldName + ".FromPB(v." + descriptor2.FieldName + ")\r\n";
                }
                flag = false;
            }
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
                SyncOpImp = SyncOpImp + "\treturn v\r\n";
            }
            if ((ds.DataType == DataStruct.SyncType.UserData) || ((ds.DataType == DataStruct.SyncType.CacheData) && ds.syncToClient))
            {
//                 UpdataValue = UpdataValue + "\t" + (flag ? "if" : "else") + "\r\n";
//                 UpdataValue = UpdataValue + "\t\t print(\"error Updata\")\r\n";
                UpdataValue = UpdataValue + "\tend\r\n";
                GetValue = GetValue + "\t" + (flag ? "if" : "else") + "\r\n";
                GetValue = GetValue + "\t\t print(\"error Get\")\r\n";
                GetValue = GetValue + "\tend\r\n";
            }
        }

        public static void Serialize(Module m, string dir, Label label1)
        {
            if (GenLangFlags.LUA)
            {
                IEnumerator enumerator;
                object obj2;
                string path = dir + @"\LUA\" + m.ModuleName + @"\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string str2 = dir + @"\LUA\PB\";
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                string str3 = dir + @"\LUA\Config\";
                if (!Directory.Exists(str3))
                {
                    Directory.CreateDirectory(str3);
                }
                string str4 = "";
                StreamReader reader = new StreamReader("./Template/Moudle.lua", Encoding.GetEncoding("GBK"));
                str4 = reader.ReadToEnd();
                reader.Close();
                string str5 = "";
                string str6 = "";
                foreach (ConfigFile file in m.configFiles)
                {
                    str5 = str5 + "\t" + file.CfgName + "Table::Instance().Load();\r\n";
                    str6 = str6 + "#include \"" + file.CfgName + "Cfg.h\"\r\n";
                    string str7 = str4;
                    string fieldName = "";
                    string fieldType = "";
                    string defaultValue = "";
                    string str11 = "";
                    string str12 = "";
                    string str13 = "";
                    string str14 = "";
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
                    string newValue = "";
                    if (fieldType == "int")
                    {
                        newValue = fieldName + " = " + defaultValue + ";";
                    }
                    int num2 = 0;
                    foreach (ConfigFile.ConfigField field2 in file.fieldItem)
                    {
                        if (!field2.IsDescribe)
                        {
                            num++;
                            string str16 = "\t" + field2.FieldType + " " + field2.FieldName + ";";
                            int num3 = 30 - str16.Length;
                            while (num3-- > 0)
                            {
                                str16 = str16 + " ";
                            }
                            string str17 = "";
                            if (field2.Comment != null)
                            {
                                str17 = field2.Comment.Replace("\r\n", " ");
                            }
                            string str49 = str16;
                            str16 = str49 + "\t//" + field2.CNName + "\t" + str17.Replace("\n", " ") + "\r\n";
                            str11 = str11 + str16;
                            obj2 = str12;
                            str12 = string.Concat(new object[] { obj2, "\t\tif(vecLine[", num2, "]!=\"", field2.FieldName, "\"){printf_message(\"", file.CfgName, ".csv中字段[", field2.FieldName, "]位置不对应\");assert(false); return false; }\r\n" });
                            if (field2.FieldType == "int")
                            {
                                obj2 = str14;
                                str14 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=atoi(vecLine[", num2, "].c_str());\r\n" });
                                str13 = str13 + "\t\t\tpContent = ReadBinInt(member." + field2.FieldName + ",pContent);\r\n";
                            }
                            else
                            {
                                obj2 = str14;
                                str14 = string.Concat(new object[] { obj2, "\t\t\tmember.", field2.FieldName, "=vecLine[", num2, "];\r\n" });
                                str13 = str13 + "\t\t\tpContent = ReadBinStr(member." + field2.FieldName + ",pContent);\r\n";
                            }
                            num2++;
                        }
                    }
                    str7 = str7.Replace("$TEMPLATE$", file.CfgName).Replace("$TempVar$", newValue);
                }
                ArrayList list = new ArrayList { 
                    "./Template/Moudle.lua",
                    //"./Template/Controller.lua"
                };
                ArrayList list2 = new ArrayList {
                    path + m.ModuleName + "Model.lua",
                    //path + m.ModuleName + "Controller.lua"
                };
                ArrayList list3 = new ArrayList();
                for (int i = 0; i < list.Count; i++)
                {
                    try
                    {
                        StreamReader reader2 = null;
                        reader2 = new StreamReader((string) list[i], Encoding.UTF8);
                        string str18 = reader2.ReadToEnd();
                        list3.Add(str18);
                        reader2.Close();
                    }
                    catch (DirectoryNotFoundException)
                    {
                        return;
                    }
                }
                label1.Text = "正在生成文件: " + path + m.ModuleName + ".lua";
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
                string str44 = "";
                string require = "";
                bool flag = false;
                int num5 = 0;
                int num6 = 0;
                string str46 = "\tMODULE_ID_" + m.ModuleName.ToUpper();
                int num7 = 0x2e - str46.Length;
                while (num7-- > 0)
                {
                    str46 = str46 + " ";
                }
                obj2 = str46;
                str46 = string.Concat(new object[] { obj2, "= ", m.StartIdNum, ",\t//", m.CNName, "模块ID\r\n" });
                enumerator = XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.RpcProto).GetEnumerator();
                //using (enumerator = XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.RpcProto).GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        DataStruct current = (DataStruct) enumerator.Current;
                    }
                }
                enumerator = XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.SyncProto).GetEnumerator();
                //using (enumerator = XMLSerializer.OrderDataStruct(m, DataStruct.protoTypeE.SyncProto).GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        DataStruct struct4 = (DataStruct) enumerator.Current;
                    }
                }
                operationDeclare = "local ModuleId = " + m.StartIdNum + ";\r\n";
                num5 = (m.StartIdNum * 100) + 0x33;
                enterLayer = "\tlocal btnChat = nil\r\n";
                num6 = 1;
                layerCtor = "";
                testProtocol = testProtocol + "askList." + m.ModuleName + " = {}\r\n";
                foreach (Module.OperaterItem item in m.operateItem)
                {
                    GenRpcCode(m, item, ref operationDeclare, ref operationImpl, ref operationImplement, ref num5, ref num6, ref rpcValues, ref callBack, ref initController, ref contCallBacks, ref layer, ref layerCtor, ref layerCtoF, ref enterLayer, ref enterFunctions, ref enterFunctionsF, ref callBackARGS, ref testProtocol);
                }
                layerCtor = layerCtor + "\t" + m.ModuleName + "Controller.InitModule(";
                for (int j = 1; j < num6; j++)
                {
                    obj2 = layerCtor;
                    layerCtor = string.Concat(new object[] { obj2, (j == 1) ? "" : ",", "cb", j });
                }
                layerCtor = layerCtor + ")\r\n";
                num6 = 0;
                foreach (DataStruct struct2 in m.moduleDataStruct)
                {
                    if (((struct2.DataType != DataStruct.SyncType.CacheData) && (struct2.DataType != DataStruct.SyncType.ModuleData)) && (struct2.DataType != DataStruct.SyncType.UserData))
                    {
                        struct2.StructName.ToLower().IndexOf("rpc");
                    }
                }
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
                        GenSyncDataCode(m, struct3, ref syncIds, ref syncOpDefine, ref syncOpImp, ref sendAllFields, ref dBCacheField, ref fromMemoryStream, ref updataValue, ref toMemoryStream, ref testArgs, ref getValue, ref str44, ref require);
                        string text7 = string.Concat(new object[] { m.ModuleName, struct3.StructName, "WraperV", m.SyncDataVersion, " m_syncData", struct3.StructName, ";" });
                        string text8 = "SetDataWraper( &m_syncData" + struct3.StructName + " );";
                    }
                }
                enumerator = DataStructConverter.CommDataStruct.GetEnumerator();
                //using (enumerator = DataStructConverter.CommDataStruct.GetEnumerator())
                {
                    while (enumerator.MoveNext())
                    {
                        DataStruct struct5 = (DataStruct) enumerator.Current;
                    }
                }
                for (int k = 0; k < list3.Count; k++)
                {
                    string str47 = (string) list3[k];
                    str47 = str47.Replace("$TEMPLATE$", m.ModuleName);
                    syncOpDefine = syncOpDefine.Replace("$TEMPLATE$", m.ModuleName);
                    str47 = str47.Replace("$TempVar$", syncOpDefine).Replace("$XULIEHUA$", syncOpImp).Replace("$FROMPBXULIEHUA$", sendAllFields)
                        .Replace("$SETFUNCTION$", dBCacheField)
                        .Replace("$FromMemoryStream$", fromMemoryStream)
                        .Replace("$UpdataValue$", updataValue)
                        .Replace("$RPCVALUES$", operationDeclare)
                        .Replace("$NOTIFYTD$", operationImpl)
                        .Replace("$ASKFUNCTION$", operationImplement)
                        .Replace("$RPCASKANDREPLY$", rpcValues)
                        .Replace("$ToMemoryStream$", toMemoryStream)
                        .Replace("$CALLBACK$", callBack)
                        .Replace("$INITCONTROLLER$", initController)
                        .Replace("$CONTROLLERCALLBACKFUNCTION$", contCallBacks)
                        .Replace("$BUTTONTHING$", layer)
                        .Replace("$TempVar2$", str44)
                        .Replace("$Require$", require)
                        .Replace("$CTORLAYER$", layerCtor)
                        .Replace("$FUNCTORLAYER$", layerCtoF)
                        .Replace("$ENTERLAYER$", enterLayer)
                        .Replace("$ONENTERFUNCTIONS$", enterFunctions)
                        .Replace("$ONENTERFUNCTIONSFUNCTION$", enterFunctionsF)
                        .Replace("$CallBackARGS$", callBackARGS)
                        .Replace("$TESTS$", testProtocol)
                        .Replace("$GetValue$", getValue);
                    list3[k] = str47;
                }
                for (int n = 0; n < list2.Count; n++)
                {
                    string str48 = (string) list2[n];
                    if ((((str48.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data" })) <= -1) || flag) && ((str48.IndexOf(m.ModuleName + "DBCache") <= -1) || flag)) && ((str48.IndexOf(string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "DataWraper" })) <= -1) || flag))
                    {
                        StreamWriter writer = null;
                        UTF8Encoding encoding = new UTF8Encoding(false);
                        writer = new StreamWriter((string) list2[n], false, encoding);
                        writer.Write((string) list3[n]);
                        writer.Close();
                    }
                }
            }
        }
    }
}

