namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.Diagnostics;
    using System.IO;
    using System.Text;
    using System.Windows.Forms;

    internal class ProtoSerializer
    {
        public static void Protoc(string ns, string dir, string fullName, string mname, DataStruct.protoTypeE protoType)
        {
            if (GenLangFlags.CPP)
            {
                string str2;
                string str = dir + @"\Proto\";
                Process process = new Process();
                process.StartInfo = new ProcessStartInfo("protoc.exe");
                process.StartInfo.WindowStyle = ProcessWindowStyle.Hidden;
                if (protoType == DataStruct.protoTypeE.CommProto)
                {
                    str2 = dir + @"\CPP\PB\";
                    if (!Directory.Exists(str2))
                    {
                        Directory.CreateDirectory(str2);
                    }
                    process.StartInfo.Arguments = "--cpp_out=" + str2 + " --proto_path=" + str + " " + fullName;
                    process.Start();
                    process.WaitForExit();
                    str2 = dir + @"\CPPDBCache\PB\";
                    if (!Directory.Exists(str2))
                    {
                        Directory.CreateDirectory(str2);
                    }
                    process.StartInfo.Arguments = "--cpp_out=" + str2 + " --proto_path=" + str + " " + fullName;
                    process.Start();
                    process.WaitForExit();
                }
                else if (protoType == DataStruct.protoTypeE.SyncProto)
                {
                    str2 = dir + @"\CPPDBCache\" + mname + @"\";
                    if (!Directory.Exists(str2))
                    {
                        Directory.CreateDirectory(str2);
                    }
                    process.StartInfo.Arguments = "--cpp_out=" + str2 + " --proto_path=" + str + " " + fullName;
                    process.Start();
                    process.WaitForExit();
                    str2 = dir + @"\CPP\" + mname + @"\";
                    if (!Directory.Exists(str2))
                    {
                        Directory.CreateDirectory(str2);
                    }
                    process.StartInfo.Arguments = "--cpp_out=" + str2 + " --proto_path=" + str + " " + fullName;
                    process.Start();
                    process.WaitForExit();
                }
                else
                {
                    str2 = dir + @"\CPP\" + mname + @"\";
                    if (!Directory.Exists(str2))
                    {
                        Directory.CreateDirectory(str2);
                    }
                    process.StartInfo.Arguments = "--cpp_out=" + str2 + " --proto_path=" + str + " " + fullName;
                    process.Start();
                    process.WaitForExit();
                }
                process.Close();
            }
        }

        public static void ProtocCS(string ns, string dir, string fullName, string mname, string shortName)
        {
            if (GenLangFlags.CS || GenLangFlags.CSCat)
            {
                string path = dir + @"\Proto\";
                string str2 = "";
                Process process = new Process {
                    StartInfo = { 
                        FileName = "protogen.exe",
                        WindowStyle = ProcessWindowStyle.Hidden
                    }
                };
                if (!File.Exists(path + "protogen.exe"))
                {
                    File.Copy("protogen.exe", path + "protogen.exe", true);
                    File.Copy("common.xslt", path + "common.xslt", true);
                    File.Copy("csharp.xslt", path + "csharp.xslt", true);
                    File.Copy("protobuf-net.dll", path + "protobuf-net.dll", true);
                }
                string currentDirectory = Directory.GetCurrentDirectory();
                Directory.SetCurrentDirectory(path);
                if (ns == "PublicStruct")
                {
                    str2 = dir + @"\CS\PB\";
                }
                else
                {
                    str2 = dir + @"\CS\PB\";
                }
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                process.StartInfo.Arguments = "-i:\"" + fullName + "\" -o:\"" + str2 + shortName + "\" -ns:GenPB";
                process.Start();
                Directory.SetCurrentDirectory(currentDirectory);
                process.WaitForExit();
                process.Close();
            }
        }

        public static void ProtocLUA(string ns, string dir, string fullName, string mname, string shortName)
        {
            if (GenLangFlags.LUA)
            {
                string path = dir + @"\Proto\";
                string str2 = "";
                Process process = new Process {
                    StartInfo = {
                        FileName = "protoc.exe",
                        WindowStyle = ProcessWindowStyle.Hidden,
                    }
                };
                if (!File.Exists(path + "protoc.exe"))
                {
                    File.Copy("protoc.exe", path + "protoc.exe", true);
                }
                if (!File.Exists(path + "protoc-gen-lua.bat"))
                {
                    File.Copy("protoc-gen-lua.bat", path + "protoc-gen-lua.bat", true);
                }
                if (!File.Exists(path + "protoc-gen-lua"))
                {
                    File.Copy("protoc-gen-lua", path + "protoc-gen-lua", true);
                }
                if (!File.Exists(path + "plugin_pb2.pyc"))
                {
                    File.Copy("plugin_pb2.pyc", path + "plugin_pb2.pyc", true);
                }
                string currentDirectory = Directory.GetCurrentDirectory();
                Directory.SetCurrentDirectory(path);
                if (ns == "PublicStruct")
                {
                    str2 = dir + @"\LUA\PB\";
                }
                else
                {
                    str2 = dir + @"\LUA\" + mname + @"\";
                }
                if (!Directory.Exists(str2))
                {
                    Directory.CreateDirectory(str2);
                }
                string str4 = fullName;
                str4 = str4.Substring(str4.LastIndexOf(@"\") + 1);
                process.StartInfo.Arguments = " --lua_out=" + str2 + " --plugin=protoc-gen-lua=protoc-gen-lua.bat " + str4;
                //process.StartInfo.WorkingDirectory = path;
                process.Start();
                Directory.SetCurrentDirectory(currentDirectory);
                process.WaitForExit();
                process.Close();
            }
        }

        public static void Serialize(Module m, string dir, Label label1, DataStruct.protoTypeE protoType)
        {
            if (protoType == DataStruct.protoTypeE.RpcProto)
            {
                Serialize(DataStructConverter.CommDataStruct, dir, label1, m.ModuleName);
            }
            string path = dir + @"\Proto\";
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            string str2 = "";
            string ns = "";
            bool flag = false;
            if (protoType == DataStruct.protoTypeE.RpcProto)
            {
                str2 = path + m.ModuleName + "Rpc.proto";
                ns = m.ModuleName + "Rpc";
            }
            else
            {
                str2 = string.Concat(new object[] { path, m.ModuleName, "V", m.SyncDataVersion, "Data.proto" });
                ns = string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data" });
            }
            label1.Text = "正在生成文件: " + str2;
            label1.Refresh();
            string str4 = "";
            str4 = str4 + "import \"PublicStruct.proto\";\r\n\r\n";
            foreach (DataStruct struct2 in m.moduleDataStruct)
            {
                if (struct2.ProtoType == protoType)
                {
                    if (struct2.Comment != "")
                    {
                        string str6 = str4;
                        str4 = str6 + "/*\r\n" + ((struct2.CNName == "") ? "" : (struct2.CNName + "\r\n")) + struct2.Comment.Replace("\r\n", "\t\r\n") + "\r\n*/\r\n";
                    }
                    else if (struct2.CNName != "")
                    {
                        str4 = str4 + "//" + struct2.CNName + "\r\n";
                    }
                    if (protoType == DataStruct.protoTypeE.RpcProto)
                    {
                        str4 = str4 + "message  " + struct2.getFullName() + "\r\n{\r\n";
                    }
                    else
                    {
                        if (((struct2.DataType == DataStruct.SyncType.ModuleData) || (struct2.DataType == DataStruct.SyncType.UserData)) || (struct2.DataType == DataStruct.SyncType.CacheData))
                        {
                            flag = true;
                        }
                        object obj2 = str4;
                        str4 = string.Concat(new object[] { obj2, "message  ", struct2.getFullName(), "V", m.SyncDataVersion, "\r\n{\r\n" });
                    }
                    foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                    {
                        DataStruct struct3 = null;
                        bool flag2 = DataStruct.DataStructDic.TryGetValue(descriptor.FieldType, out struct3) || DataStruct.DataStructDic.TryGetValue(m.ModuleName + descriptor.FieldType, out struct3);
                        string fieldType = descriptor.FieldType;
                        if (flag2)
                        {
                            fieldType = struct3.getFullName();
                            DataStruct ds = null;
                            if (!DataStructConverter.ContainsKey(descriptor.FieldType, ref ds) && (protoType == DataStruct.protoTypeE.SyncProto))
                            {
                                fieldType = fieldType + "V" + m.SyncDataVersion;
                            }
                        }
                        if (descriptor.Comment != "")
                        {
                            string str7 = str4;
                            str4 = str7 + "\t/*\r\n" + ((descriptor.CNName == "") ? "" : ("\t" + descriptor.CNName + "\r\n")) + "\t" + descriptor.Comment.Replace("\r\n", "\r\n\t") + "\r\n\t*/\r\n";
                        }
                        if ((((descriptor.FieldType == "float") || (descriptor.FieldType == "bool")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64" || descriptor.FieldType == "uint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                        {
                            object obj3 = str4;
                            str4 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];" });
                        }
                        else
                        {
                            object obj4 = str4;
                            str4 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine , " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";" });
                        }
                        str4 = str4 + (((descriptor.Comment == "") && (descriptor.CNName != "")) ? ("\t//" + descriptor.CNName) : "") + "\r\n";
                    }
                    str4 = str4 + "}\r\n\r\n";
                }
            }
            if (flag || (protoType != DataStruct.protoTypeE.SyncProto))
            {
                StreamWriter writer = new StreamWriter(str2, false, Encoding.GetEncoding("GBK"));
                writer.Write(str4);
                writer.Flush();
                writer.Close();
                Protoc(ns, dir, str2, m.ModuleName, protoType);
            }
        }

        public static void Serialize(ArrayList dataStruct, string dir, Label label1, string mname)
        {
            string path = dir + @"\Proto\";
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            string str2 = path + "PublicStruct.proto";
            label1.Text = "正在生成文件: " + str2;
            label1.Refresh();
            StreamWriter writer = new StreamWriter(str2, false, Encoding.GetEncoding("GBK"));
            string str3 = "";
            foreach (DataStruct struct2 in dataStruct)
            {
                if (struct2.Comment != "")
                {
                    string str4 = str3;
                    str3 = str4 + "/*\r\n" + ((struct2.CNName == "") ? "" : (struct2.CNName + "\r\n")) + struct2.Comment.Replace("\r\n", "\t\r\n") + "\r\n*/\r\n";
                }
                str3 = str3 + "message  " + struct2.getFullName() + "\r\n{\r\n";
                foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                {
                    bool flag1 = descriptor.Comment != "";
                    if ((descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional) && (((descriptor.FieldType == "float") || (descriptor.FieldType == "bool")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64") || (descriptor.FieldType == "uint64"))))
                    {
                        object obj2 = str3;
                        str3 = string.Concat(new object[] { obj2, "\t", descriptor.PreDefine, " ", descriptor.FieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];\r\n" });
                    }
                    else
                    {
                        object obj3 = str3;
                        str3 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", descriptor.FieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";\r\n" });
                    }
                }
                str3 = str3 + "\r\n}\r\n\r\n";
            }
            writer.Write(str3);
            writer.Flush();
            writer.Close();
            label1.Text = "正在编译文件: " + str2;
            label1.Refresh();
            Protoc("PublicStruct", dir, str2, mname, DataStruct.protoTypeE.CommProto);
            ProtocCS("PublicStruct", dir, str2, mname, "PublicStruct.cs");
            ProtocLUA("PublicStruct", dir, str2, mname, "PublicStruct.lua");
        }

        public static void SerializeCS(Module m, string dir, Label label1, DataStruct.protoTypeE protoType)
        {
            if (GenLangFlags.CS || GenLangFlags.CSCat)
            {
                string path = dir + @"\Proto\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string ns = "";
                string str3 = "";
                string shortName = "";
                if (protoType == DataStruct.protoTypeE.RpcProto)
                {
                    ns = "RpcProtoBuf";
                    str3 = path + m.ModuleName + "Rpc.proto";
                    shortName = m.ModuleName + "Rpc.cs";
                }
                else
                {
                    ns = "SyncProtoBuf";
                    str3 = string.Concat(new object[] { path, m.ModuleName, "V", m.SyncDataVersion, "Data.proto" });
                    shortName = string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data.cs" });
                }
                label1.Text = "正在生成文件: " + str3;
                label1.Refresh();
                bool flag = false;
                string str5 = "";
                str5 = str5 + "\r\nimport \"PublicStruct.proto\";\r\n\r\n";
                foreach (DataStruct struct2 in m.moduleDataStruct)
                {
                    if ((struct2.ProtoType == protoType) && ((struct2.StructName.ToLower().IndexOf("svrrpc") <= -1) || (protoType != DataStruct.protoTypeE.RpcProto)))
                    {
                        if (struct2.Comment != "")
                        {
                            string str7 = str5;
                            str5 = str7 + "/*\r\n" + ((struct2.CNName == "") ? "" : (struct2.CNName + "\r\n")) + struct2.Comment.Replace("\r\n", "\t\r\n") + "\r\n*/\r\n";
                        }
                        else if (struct2.CNName != "")
                        {
                            str5 = str5 + "//" + struct2.CNName + "\r\n";
                        }
                        if (protoType == DataStruct.protoTypeE.RpcProto)
                        {
                            str5 = str5 + "message  " + struct2.getFullName() + "\r\n{\r\n";
                        }
                        else
                        {
                            object obj2 = str5;
                            str5 = string.Concat(new object[] { obj2, "message  ", struct2.getFullName(), "V", m.SyncDataVersion, "\r\n{\r\n" });
                            if ((struct2.DataType == DataStruct.SyncType.UserData) || ((struct2.DataType == DataStruct.SyncType.CacheData) && struct2.SyncToClient))
                            {
                                flag = true;
                            }
                        }
                        foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                        {
                            DataStruct struct3 = null;
                            bool flag2 = DataStruct.DataStructDic.TryGetValue(descriptor.FieldType, out struct3) || DataStruct.DataStructDic.TryGetValue(m.ModuleName + descriptor.FieldType, out struct3);
                            string fieldType = descriptor.FieldType;
                            if (flag2)
                            {
                                fieldType = struct3.getFullName();
                                DataStruct ds = null;
                                if (!DataStructConverter.ContainsKey(descriptor.FieldType, ref ds) && (protoType == DataStruct.protoTypeE.SyncProto))
                                {
                                    fieldType = fieldType + "V" + m.SyncDataVersion;
                                }
                            }
                            if (descriptor.Comment != "")
                            {
                                string str8 = str5;
                                str5 = str8 + "\t/*\r\n" + ((descriptor.CNName == "") ? "" : ("\t" + descriptor.CNName + "\r\n")) + "\t" + descriptor.Comment.Replace("\r\n", "\r\n\t") + "\r\n\t*/\r\n";
                            }
                            if ((((descriptor.FieldType == "float") || (descriptor.FieldType == "bool")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64") || (descriptor.FieldType == "uint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                            {
                                object obj3 = str5;
                                str5 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];" });
                            }
                            else
                            {
                                object obj4 = str5;
                                str5 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";" });
                            }
                            str5 = str5 + (((descriptor.Comment == "") && (descriptor.CNName != "")) ? ("\t//" + descriptor.CNName) : "") + "\r\n";
                        }
                        str5 = str5 + "}\r\n\r\n";
                    }
                }
                if (flag || (protoType != DataStruct.protoTypeE.SyncProto))
                {
                    StreamWriter writer = new StreamWriter(str3, false, Encoding.GetEncoding("GBK"));
                    writer.Write(str5);
                    writer.Flush();
                    writer.Close();
                    ProtocCS(ns, dir, str3, m.ModuleName, shortName);
                }
            }
        }

        private static ArrayList GenMessage(DataStruct struct2,ref string str5)
        {
            ArrayList referenceMssage = new ArrayList();
            str5 += "message  " + struct2.getFullName() + "\r\n{\r\n";
            foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
            {
                DataStruct struct3 = null;
                
                string fieldType = descriptor.FieldType;
                if ((((descriptor.FieldType == "float") || (descriptor.FieldType == "bool")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                {
                    object obj3 = str5;
                    str5 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];\r\n" });
                }
                else if ((((descriptor.FieldType == "uint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                {
                    UInt64 t = 0;
                    if (!UInt64.TryParse(descriptor.DefaultValue, out t))
                    {
                        descriptor.DefaultValue = "0";
                    }
                    object obj3 = str5;
                    str5 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];\r\n" });
                }
                else if (descriptor.FieldType == "string")
                {
                    object obj4 = str5;
                    str5 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";\r\n" });
                }
                else
                {
                    object obj4 = str5;
                    DataStruct refStruct = null;
                    if (DataStructConverter.ContainsKey(fieldType, ref refStruct))
                    {
                        referenceMssage.Add(refStruct);
                    }


                    str5 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";\r\n" });
                }
            }

            str5 = str5 + "\r\n}\r\n\r\n";

            return referenceMssage;
        }

        private static ArrayList GenMessage(DataStruct struct2, DataStruct.protoTypeE protoType, ref string str5, Module m, ref bool flag)
        {
            ArrayList referenceMssage = new ArrayList();
            if ((struct2.ProtoType == protoType) && ((struct2.StructName.ToLower().IndexOf("svrrpc") <= -1) || (protoType != DataStruct.protoTypeE.RpcProto)))
            {
                if (protoType == DataStruct.protoTypeE.RpcProto)
                {
                    str5 = str5 + "message  " + struct2.getFullName() + "\r\n{\r\n";
                }
                else
                {
                    object obj2 = str5;
                    str5 = string.Concat(new object[] { obj2, "message  ", struct2.getFullName(), "V", m.SyncDataVersion, "\r\n{\r\n" });
                    if ((struct2.DataType == DataStruct.SyncType.UserData) || ((struct2.DataType == DataStruct.SyncType.CacheData) && struct2.SyncToClient))
                    {
                        flag = true;
                    }
                }
                string temp = "";
                foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                {
                    DataStruct struct3 = null;
                    bool flag2 = DataStruct.DataStructDic.TryGetValue(descriptor.FieldType, out struct3) || DataStruct.DataStructDic.TryGetValue(m.ModuleName + descriptor.FieldType, out struct3);
                    string fieldType = descriptor.FieldType;
                    if (flag2)
                    {
                        fieldType = struct3.getFullName();
                        DataStruct ds = null;
                        if (!DataStructConverter.ContainsKey(descriptor.FieldType, ref ds) && (protoType == DataStruct.protoTypeE.SyncProto))
                        {
                            fieldType = fieldType + "V" + m.SyncDataVersion;
                        }
                    }
                    if ((((descriptor.FieldType == "float") || (descriptor.FieldType == "bool")) || ((descriptor.FieldType == "sint32") || (descriptor.FieldType == "sint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                    {
                        object obj3 = str5;
                        str5 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];\r\n" });
                    }
                    else if ((((descriptor.FieldType == "uint64"))) && (descriptor.PreDefine == DataStruct.FieldDescriptor.PreDefineType.optional))
                    {
                        UInt64 t = 0;
                        if (!UInt64.TryParse(descriptor.DefaultValue, out t))
                        {
                            descriptor.DefaultValue = "0";
                        }
                        object obj3 = str5;
                        str5 = string.Concat(new object[] { obj3, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, "[default=", descriptor.DefaultValue, "];\r\n" });
                    }
                    else if (descriptor.FieldType == "string")
                    {
                        object obj4 = str5;
                        str5 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";\r\n" });
                    }
                    else
                    {
                        object obj4 = str5;
                        DataStruct refStruct = null;
                        if (DataStructConverter.ContainsKey(fieldType, ref refStruct))
                        {
                            //temp += "," + fieldType;
                            //MessageBox.Show(fieldType + "__" + refStruct.getFullName());
                            referenceMssage.Add(refStruct);
                        }


                        str5 = string.Concat(new object[] { obj4, "\t", descriptor.PreDefine, " ", fieldType, " ", descriptor.FieldName, " = ", descriptor.FieldId, ";\r\n" });
                    }
                }

                str5 = str5 + "\r\n}\r\n\r\n";
            }
            return referenceMssage;
        }

        public static void SerializeLUA_SY(Module m, string dir, Label label1, DataStruct.protoTypeE protoType)
        {
            if (GenLangFlags.LUA)
            {
                string path = dir + @"\Proto\SY\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string ns = "";
                string str3 = "";
                string shortName = "";
                if (protoType == DataStruct.protoTypeE.RpcProto)
                {
                    ns = "RpcProtoBuf";
                    str3 = path + m.ModuleName + "Rpc.proto";
                    shortName = m.ModuleName + "Rpc.lua";
                }
                else
                {
                    ns = "SyncProtoBuf";
                    str3 = string.Concat(new object[] { path, m.ModuleName, "V", m.SyncDataVersion, "Data.proto" });
                    shortName = string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data.lua" });
                }
                label1.Text = "正在生成文件: " + str3;
                label1.Refresh();
                bool flag = false;
                string str5 = "";

                //////////////////////////////////////////////////////////
                List<DataStruct> publicTypeList = new List<DataStruct>();
                foreach (DataStruct ds in m.moduleDataStruct)
                {
                    ArrayList tempRefMsg = GenMessage(ds, protoType, ref str5, m, ref flag);
                    foreach (DataStruct item in tempRefMsg)
                    {
                        if (!publicTypeList.Contains(item))
                        {
                            //MessageBox.Show(item.getFullName());
                            publicTypeList.Add(item);
                        }
                    }
                }



               //////////////////////////////////////////////////////////
               //遍历其他类型字段

                //str5 = str5 + "\r\nimport \"PublicStruct.proto\";\r\n\r\n";
               /* foreach (DataStruct struct2 in m.moduleDataStruct)
                {
                    //ArrayList tempRefMsg = GenMessage(struct2, protoType, ref str5, m, ref flag);
//                     foreach (DataStruct item in tempRefMsg)
//                     {
//                         bool notExist = true;
//                         foreach (DataStruct r in refMsg)
//                         {
//                             if (r.getFullName() == item.getFullName())
//                             {
//                                 notExist = false;
//                                 break;
//                             }
//                         }
//                         if (notExist)
//                         {
//                             refMsg.Add(item);
//                         }
//                     }
                }*/

                foreach (DataStruct struct2 in publicTypeList)
                {
                    ArrayList tempRefMsg = GenMessage(struct2, ref str5);
                }
                if (flag || (protoType != DataStruct.protoTypeE.SyncProto))
                {
                    StreamWriter writer = new StreamWriter(str3, false, Encoding.GetEncoding("GBK"));
                    writer.Write(str5);
                    writer.Flush();
                    writer.Close();
                    ProtocLUA(ns, dir, str3, m.ModuleName, shortName);
                }
            }
        
        }

        public static void SerializeLUA(Module m, string dir, Label label1, DataStruct.protoTypeE protoType)
        {
            if (GenLangFlags.LUA)
            {
                string path = dir + @"\Proto\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string ns = "";
                string str3 = "";
                string shortName = "";
                if (protoType == DataStruct.protoTypeE.RpcProto)
                {
                    ns = "RpcProtoBuf";
                    str3 = path + m.ModuleName + "Rpc.proto";
                    shortName = m.ModuleName + "Rpc.lua";
                }
                else
                {
                    ns = "SyncProtoBuf";
                    str3 = string.Concat(new object[] { path, m.ModuleName, "V", m.SyncDataVersion, "Data.proto" });
                    shortName = string.Concat(new object[] { m.ModuleName, "V", m.SyncDataVersion, "Data.lua" });
                }
                label1.Text = "正在生成文件: " + str3;
                label1.Refresh();
                bool flag = false;
                string str5 = "";
                str5 = str5 + "\r\nimport \"PublicStruct.proto\";\r\n\r\n";
                foreach (DataStruct struct2 in m.moduleDataStruct)
                {
                    GenMessage(struct2, protoType, ref str5, m, ref flag);
                }
                if (flag || (protoType != DataStruct.protoTypeE.SyncProto))
                {
                    StreamWriter writer = new StreamWriter(str3, false, Encoding.GetEncoding("GBK"));
                    writer.Write(str5);
                    writer.Flush();
                    writer.Close();
                    ProtocLUA(ns, dir, str3, m.ModuleName, shortName);
                }
            }
        }
    }
}

