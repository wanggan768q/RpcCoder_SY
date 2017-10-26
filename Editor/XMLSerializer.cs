namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.IO;
    using System.Windows.Forms;
    using System.Xml;

    internal class XMLSerializer
    {
        public static void Deserialize(TreeView tree, string dir)
        {
            DirectoryInfo info = new DirectoryInfo(dir + "/XML");
            if (info.Exists)
            {
                foreach (FileInfo info2 in info.GetFiles())
                {
                    if (((info2.Extension == ".xml") && (info2.Name != "Module.xml")) && (info2.Name != "ProtocolConfig.xml"))
                    {
                        XmlDocument document = new XmlDocument();
                        document.Load(info2.FullName);
                        TreeNode node = tree.Nodes[0];
                        TreeNode node2 = tree.Nodes[1];
                        if (info2.Name == "PublicStruct.xml")
                        {
                            foreach (XmlNode node3 in document.SelectSingleNode("Root").ChildNodes)
                            {
                                DataStruct struct2 = new DataStruct();
                                XmlElement element = (XmlElement) node3;
                                struct2.StructName = element.GetAttribute("Name");
                                struct2.CNName = element.GetAttribute("CName");
                                struct2.ProtoType = struct2.getProtoTypeValue(element.GetAttribute("ProtoType"));
                                struct2.Comment = element.GetAttribute("Comment");
                                struct2.MaxFieldId = Convert.ToInt32(element.GetAttribute("MaxFieldId"));
                                TreeNode node4 = node.Nodes.Add(struct2.StructName);
                                node4.Name = "NewDataStruct";
                                node4.ImageIndex = 2;
                                node4.Tag = struct2;
                                foreach (XmlNode node5 in node3)
                                {
                                    XmlElement element2 = (XmlElement) node5;
                                    DataStruct.FieldDescriptor descriptor = new DataStruct.FieldDescriptor {
                                        dataStruct = struct2
                                    };
                                    struct2.fieldItem.Add(descriptor);
                                    descriptor.FieldName = element2.GetAttribute("Name");
                                    descriptor.CNName = element2.GetAttribute("CName");
                                    descriptor.FieldType = element2.GetAttribute("FieldType");
                                    descriptor.Comment = element2.GetAttribute("Comment");
                                    descriptor.FieldId = Convert.ToInt32(element2.GetAttribute("FieldId"));
                                    descriptor.ValueSet = element2.GetAttribute("ValueSet");
                                    descriptor.MaxValue = Convert.ToInt32(element2.GetAttribute("MaxValue"));
                                    descriptor.MinValue = Convert.ToInt32(element2.GetAttribute("MinValue"));
                                    string attribute = element2.GetAttribute("PreDefine");
                                    descriptor.PreDefine = (attribute == "optional") ? DataStruct.FieldDescriptor.PreDefineType.optional : DataStruct.FieldDescriptor.PreDefineType.repeated;
                                    if (DataStruct.IsBaseType(descriptor.FieldType))
                                    {
                                        descriptor.DefaultValue = element2.GetAttribute("DefaultValue");
                                    }
                                    TreeNode node6 = node4.Nodes.Add(descriptor.FieldName);
                                    node6.Name = "NewField";
                                    node6.ImageIndex = 3;
                                    node6.Tag = descriptor;
                                }
                                DataStructConverter.CommDataStruct.Add(struct2);
                                DataStruct.DataStructDic.Add(struct2.getFullName(), struct2);
                            }
                        }
                        else
                        {
                            Module module = new Module();
                            XmlElement element3 = (XmlElement) document.SelectSingleNode("Root");
                            module.ModuleName = element3.GetAttribute("Module");
                            module.CNName = element3.GetAttribute("CName");
                            module.Comment = element3.GetAttribute("Comment");
                            module.StartIdNum = Convert.ToInt32(element3.GetAttribute("MsgNumStart"));
                            module.SyncDataVersion = Convert.ToInt32(element3.GetAttribute("SyncDataVersion"));
                            Module.ModuleDic.Add(module.ModuleName, module);
                            TreeNode node7 = node2.Nodes.Add(module.ModuleName);
                            int startIdNum = module.StartIdNum;
                            if (startIdNum == 0)
                            {
                                startIdNum = new Random().Next(0x3e8, 0x270f);
                            }
                            ArrayList list2 = new ArrayList();
                            Module.errorDic.Add(startIdNum, list2);
                            Module.ErrorModuleName name = new Module.ErrorModuleName {
                                en = module.ModuleName,
                                cn = module.CNName
                            };
                            Module.moduleNameDic.Add(startIdNum, name);
                            node7.Name = "NewModule";
                            node7.ImageIndex = 4;
                            node7.Tag = module;
                            TreeNode node8 = node7.Nodes.Add("Client RPC");
                            node8.Name = "clientRpc";
                            TreeNode node9 = node7.Nodes.Add("RPC Parameters");
                            node9.Name = "rpcProto";
                            TreeNode node10 = node7.Nodes.Add("Module Data");
                            node10.Name = "syncData";
                            TreeNode node11 = node7.Nodes.Add("Configuration Files");
                            node11.Name = "configFile";
                            module.rpcProtoNode = node9;
                            foreach (XmlNode node12 in document.SelectSingleNode("Root").ChildNodes)
                            {
                                if (node12.Name == "Operate")
                                {
                                    XmlElement element4 = (XmlElement) node12;
                                    Module.OperaterItem item = new Module.OperaterItem {
                                        module = module
                                    };
                                    module.operateItem.Add(item);
                                    item.Name = element4.GetAttribute("Name");
                                    item.CNName = element4.GetAttribute("CName");
                                    item.Comment = element4.GetAttribute("Comment");
                                    TreeNode node13 = node8.Nodes.Add(item.Name);
                                    node13.Name = "NewOperate";
                                    node13.ImageIndex = 5;
                                    node13.Tag = item;
                                    foreach (XmlNode node14 in node12)
                                    {
                                        XmlElement element5 = (XmlElement) node14;
                                        Module.OperaterItem.SubOperaterItem item2 = new Module.OperaterItem.SubOperaterItem();
                                        item.subOperateItem.Add(item2);
                                        item2.operaterItem = item;
                                        item2.Type = item2.getOperateType(element5.Name);
                                        item2.toSetOpType(element5.Name);
                                        item2.toSetName(element5.GetAttribute("Name"));
                                        item2.toSetCnName(element5.GetAttribute("CName"));
                                        item2.Comment = element5.GetAttribute("Comment");
                                        item2.toSetDataStructName(element5.GetAttribute("DataStruct"));
                                        TreeNode node15 = node13.Nodes.Add(element5.GetAttribute("Name"));
                                        node15.Name = "NewSubOperate";
                                        node15.ImageIndex = 6;
                                        node15.Tag = item2;
                                    }
                                }
                                else if (node12.Name == "Struct")
                                {
                                    TreeNode node16;
                                    XmlElement element6 = (XmlElement) node12;
                                    DataStruct struct3 = new DataStruct {
                                        module = module
                                    };
                                    module.moduleDataStruct.Add(struct3);
                                    struct3.StructName = element6.GetAttribute("Name");
                                    struct3.CNName = element6.GetAttribute("CName");
                                    struct3.Comment = element6.GetAttribute("Comment");
                                    struct3.MaxFieldId = Convert.ToInt32(element6.GetAttribute("MaxFieldId"));
                                    struct3.ProtoType = struct3.getProtoTypeValue(element6.GetAttribute("ProtoType"));
                                    struct3.ToSetDataType(struct3.ConvertDataType(element6.GetAttribute("DataType")));
                                    struct3.saveToDB = element6.GetAttribute("SaveToDB").ToLower() == "true";
                                    struct3.SyncToClient = element6.GetAttribute("SyncToClient").ToLower() == "true";
                                    if (struct3.ProtoType == DataStruct.protoTypeE.RpcProto)
                                    {
                                        node16 = node9.Nodes.Add(struct3.StructName);
                                    }
                                    else
                                    {
                                        node16 = node10.Nodes.Add(struct3.StructName);
                                    }
                                    node16.Name = "NewDataStruct";
                                    node16.ImageIndex = 2;
                                    node16.Tag = struct3;
                                    struct3.selfTreeNode = node16;
                                    foreach (XmlNode node17 in node12)
                                    {
                                        XmlElement element7 = (XmlElement) node17;
                                        DataStruct.FieldDescriptor descriptor2 = new DataStruct.FieldDescriptor {
                                            dataStruct = struct3
                                        };
                                        struct3.fieldItem.Add(descriptor2);
                                        descriptor2.FieldName = element7.GetAttribute("Name");
                                        descriptor2.CNName = element7.GetAttribute("CName");
                                        descriptor2.Comment = element7.GetAttribute("Comment");
                                        descriptor2.FieldType = element7.GetAttribute("FieldType");
                                        descriptor2.FieldId = Convert.ToInt32(element7.GetAttribute("FieldId"));
                                        string str2 = element7.GetAttribute("PreDefine");
                                        descriptor2.PreDefine = (str2 == "optional") ? DataStruct.FieldDescriptor.PreDefineType.optional : DataStruct.FieldDescriptor.PreDefineType.repeated;
                                        descriptor2.ValueSet = element7.GetAttribute("ValueSet");
                                        descriptor2.MaxValue = Convert.ToInt32(element7.GetAttribute("MaxValue"));
                                        descriptor2.MinValue = Convert.ToInt32(element7.GetAttribute("MinValue"));
                                        if (DataStruct.IsBaseType(descriptor2.FieldType))
                                        {
                                            descriptor2.DefaultValue = element7.GetAttribute("DefaultValue");
                                        }
                                        TreeNode node18 = node16.Nodes.Add(descriptor2.FieldName);
                                        node18.Name = "NewField";
                                        node18.ImageIndex = 3;
                                        node18.Tag = descriptor2;
                                    }
                                    DataStruct.DataStructDic.Add(struct3.getFullName(), struct3);
                                }
                                else if (node12.Name == "ConfigFile")
                                {
                                    XmlElement element8 = (XmlElement) node12;
                                    ConfigFile file = new ConfigFile {
                                        module = module
                                    };
                                    module.configFiles.Add(file);
                                    file.toSetConfigName(element8.GetAttribute("Name"));
                                    file.CNName = element8.GetAttribute("CName");
                                    file.Comment = element8.GetAttribute("Comment");
                                    TreeNode node19 = node11.Nodes.Add(file.ConfigName);
                                    node19.Name = "NewConfigFile";
                                    node19.ImageIndex = 2;
                                    node19.Tag = file;
                                    foreach (XmlNode node20 in node12)
                                    {
                                        XmlElement element9 = (XmlElement) node20;
                                        ConfigFile.ConfigField field = new ConfigFile.ConfigField {
                                            configFile = file
                                        };
                                        file.fieldItem.Add(field);
                                        field.toSetFieldName(element9.GetAttribute("Name"));
                                        field.toSetCnName(element9.GetAttribute("CName"));
                                        field.toSetComment(element9.GetAttribute("Comment"));
                                        field.toSetFieldType(element9.GetAttribute("FieldType"));
                                        field.toSetDefaultValue(element9.GetAttribute("DefaultValue"));
                                        field.toSetCheckIndex(element9.GetAttribute("CheckIndex"));
                                        field.toSetValueSet(element9.GetAttribute("ValueSet"));
                                        field.toSetIsPri(element9.GetAttribute("IsPri").ToLower() == "true");
                                        field.toSetIsSvr(element9.GetAttribute("IsSvr").ToLower() == "true");
                                        field.toSetIsDes(element9.GetAttribute("IsDes").ToLower() == "true");
                                        field.toSetMaxValue(Convert.ToInt32(element9.GetAttribute("MaxValue")));
                                        field.toSetMinValue(Convert.ToInt32(element9.GetAttribute("MinValue")));
                                        TreeNode node21 = node19.Nodes.Add(field.FieldName);
                                        node21.Name = "NewConfigField";
                                        node21.ImageIndex = 3;
                                        node21.Tag = field;
                                    }
                                    ConfigFile.ConfigFileDic[file.ConfigName] = file;
                                }
                            }
                        }
                    }
                }
            }
        }

        private static void getDataStructName(ArrayList arr, DataStruct ds)
        {
            if (!arr.Contains(ds))
            {
                arr.Add(ds);
                foreach (DataStruct.FieldDescriptor descriptor in ds.fieldItem)
                {
                    if (!DataStruct.IsBaseType(descriptor.FieldType) && !arr.Contains(descriptor.FieldType))
                    {
                        DataStruct dataStruct = DataStruct.GetDataStruct(descriptor.FieldType, (ds.module == null) ? "" : ds.module.ModuleName);
                        if (dataStruct != null)
                        {
                            getDataStructName(arr, dataStruct);
                        }
                    }
                }
            }
        }

        public static ArrayList OrderDataStruct(ArrayList srcList)
        {
            ArrayList list = new ArrayList();
            Dictionary<string, DataStruct> dictionary = new Dictionary<string, DataStruct>();
            foreach (DataStruct struct2 in srcList)
            {
                dictionary.Add(struct2.getFullName() + "Wraper", struct2);
                list.Add(struct2);
            }
            foreach (KeyValuePair<string, DataStruct> pair in dictionary)
            {
                foreach (DataStruct.FieldDescriptor descriptor in pair.Value.fieldItem)
                {
                    string key = descriptor.ToGetFieldType();
                    if (dictionary.ContainsKey(key) && (dictionary[key].GenOrder <= pair.Value.GenOrder))
                    {
                        dictionary[key].GenOrder = pair.Value.GenOrder + 1;
                    }
                }
            }
            foreach (KeyValuePair<string, DataStruct> pair2 in dictionary)
            {
                foreach (DataStruct.FieldDescriptor descriptor2 in pair2.Value.fieldItem)
                {
                    string str2 = descriptor2.ToGetFieldType();
                    if (dictionary.ContainsKey(str2) && (dictionary[str2].GenOrder <= pair2.Value.GenOrder))
                    {
                        dictionary[str2].GenOrder = pair2.Value.GenOrder + 1;
                    }
                }
            }
            list.Sort(new DataStructComparer());
            return list;
        }

        public static ArrayList OrderDataStruct(Module m, DataStruct.protoTypeE protoType)
        {
            ArrayList list = new ArrayList();
            Dictionary<string, DataStruct> dictionary = new Dictionary<string, DataStruct>();
            foreach (DataStruct struct2 in m.moduleDataStruct)
            {
                if (((struct2.DataType != DataStruct.SyncType.CacheData) && (struct2.DataType != DataStruct.SyncType.ModuleData)) && ((struct2.DataType != DataStruct.SyncType.UserData) && (struct2.StructName.ToLower().IndexOf("rpc") <= -1)))
                {
                    if (protoType == DataStruct.protoTypeE.RpcProto)
                    {
                        if (struct2.ProtoType == DataStruct.protoTypeE.RpcProto)
                        {
                            dictionary.Add(struct2.getFullName() + "Wraper", struct2);
                            list.Add(struct2);
                        }
                    }
                    else if (struct2.ProtoType != DataStruct.protoTypeE.RpcProto)
                    {
                        dictionary.Add(struct2.getFullName() + "WraperV" + m.SyncDataVersion, struct2);
                        list.Add(struct2);
                    }
                }
            }
            foreach (KeyValuePair<string, DataStruct> pair in dictionary)
            {
                foreach (DataStruct.FieldDescriptor descriptor in pair.Value.fieldItem)
                {
                    string key = descriptor.ToGetFieldType();
                    if (dictionary.ContainsKey(key) && (dictionary[key].GenOrder <= pair.Value.GenOrder))
                    {
                        dictionary[key].GenOrder = pair.Value.GenOrder + 1;
                    }
                }
            }
            foreach (KeyValuePair<string, DataStruct> pair2 in dictionary)
            {
                foreach (DataStruct.FieldDescriptor descriptor2 in pair2.Value.fieldItem)
                {
                    string str2 = descriptor2.ToGetFieldType();
                    if (dictionary.ContainsKey(str2) && (dictionary[str2].GenOrder <= pair2.Value.GenOrder))
                    {
                        dictionary[str2].GenOrder = pair2.Value.GenOrder + 1;
                    }
                }
            }
            list.Sort(new DataStructComparer());
            return list;
        }

        public static void Serialize(Module m, string dir, Label label1)
        {
            DrawPic.Draw(m);
            string path = dir + @"\XML\";
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            string filename = path + m.ModuleName + ".xml";
            label1.Text = "正在生成文件: " + filename;
            label1.Refresh();
            XmlTextWriter writer = new XmlTextWriter(filename, null) {
                Formatting = Formatting.Indented,
                Indentation = 4
            };
            writer.WriteStartDocument();
            writer.WriteStartElement("Root");
            writer.WriteAttributeString("Module", m.ModuleName);
            writer.WriteAttributeString("CName", m.CNName);
            writer.WriteAttributeString("MsgNumStart", m.StartIdNum.ToString());
            writer.WriteAttributeString("SyncDataVersion", m.SyncDataVersion.ToString());
            writer.WriteAttributeString("Comment", m.Comment);
            int num = 0;
            foreach (Module.OperaterItem item in m.operateItem)
            {
                writer.WriteStartElement("Operate");
                writer.WriteAttributeString("Name", item.Name);
                writer.WriteAttributeString("CName", item.CNName);
                writer.WriteAttributeString("Comment", item.Comment);
                foreach (Module.OperaterItem.SubOperaterItem item2 in item.subOperateItem)
                {
                    writer.WriteStartElement(item2.Type.ToString());
                    writer.WriteAttributeString("Name", item2.Name);
                    writer.WriteAttributeString("CName", item2.CNName);
                    writer.WriteAttributeString("MsgID", (m.StartIdNum + num++).ToString());
                    writer.WriteAttributeString("DataStruct", item2.DataStructName);
                    writer.WriteAttributeString("Comment", item2.Comment);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            foreach (DataStruct struct2 in m.moduleDataStruct)
            {
                writer.WriteStartElement("Struct");
                writer.WriteAttributeString("Name", struct2.StructName);
                writer.WriteAttributeString("CName", struct2.CNName);
                writer.WriteAttributeString("ProtoType", struct2.getProtoTypeName(struct2.ProtoType));
                writer.WriteAttributeString("Comment", struct2.Comment);
                writer.WriteAttributeString("DataType", struct2.DataType.ToString());
                writer.WriteAttributeString("SaveToDB", struct2.SaveToDB.ToString());
                writer.WriteAttributeString("SyncToClient", struct2.SyncToClient.ToString());
                writer.WriteAttributeString("MaxFieldId", struct2.MaxFieldId.ToString());
                foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                {
                    writer.WriteStartElement("Field");
                    writer.WriteAttributeString("PreDefine", descriptor.PreDefine.ToString());
                    writer.WriteAttributeString("FieldType", descriptor.FieldType ?? "");
                    writer.WriteAttributeString("FieldId", descriptor.FieldId.ToString());
                    writer.WriteAttributeString("Name", descriptor.FieldName);
                    writer.WriteAttributeString("CName", descriptor.CNName);
                    writer.WriteAttributeString("ValueSet", descriptor.ValueSet);
                    writer.WriteAttributeString("MinValue", descriptor.MinValue.ToString());
                    writer.WriteAttributeString("MaxValue", descriptor.MaxValue.ToString());
                    if (DataStruct.IsBaseType(descriptor.FieldType))
                    {
                        writer.WriteAttributeString("DefaultValue", descriptor.DefaultValue);
                    }
                    writer.WriteAttributeString("Comment", descriptor.Comment);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            foreach (ConfigFile file in m.configFiles)
            {
                writer.WriteStartElement("ConfigFile");
                writer.WriteAttributeString("Name", file.ConfigName);
                writer.WriteAttributeString("CName", file.CNName);
                writer.WriteAttributeString("Comment", file.Comment);
                foreach (ConfigFile.ConfigField field in file.fieldItem)
                {
                    writer.WriteStartElement("Field");
                    writer.WriteAttributeString("IsDes", field.IsDescribe.ToString());
                    writer.WriteAttributeString("IsSvr", field.IsServer.ToString());
                    writer.WriteAttributeString("IsPri", field.IsPrimary.ToString());
                    writer.WriteAttributeString("CheckIndex", field.CheckIndex ?? "");
                    writer.WriteAttributeString("MaxValue", field.MaxValue.ToString());
                    writer.WriteAttributeString("MinValue", field.MinValue.ToString());
                    writer.WriteAttributeString("DefaultValue", field.DefaultValue ?? "");
                    writer.WriteAttributeString("ValueSet", field.ValueSet ?? "");
                    writer.WriteAttributeString("FieldType", field.FieldType ?? "");
                    writer.WriteAttributeString("Name", field.FieldName);
                    writer.WriteAttributeString("CName", field.CNName);
                    writer.WriteAttributeString("Comment", field.Comment);
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
            }
            writer.WriteEndElement();
            writer.WriteEndDocument();
            writer.Flush();
            writer.Close();
        }

        public static void Serialize(ArrayList CommDataStruct, string dir, Label label1)
        {
            if (CommDataStruct.Count != 0)
            {
                string path = dir + @"\XML\";
                if (!Directory.Exists(path))
                {
                    Directory.CreateDirectory(path);
                }
                string str2 = path + "PublicStruct.xml";
                label1.Text = "正在生成文件: " + str2;
                label1.Refresh();
                File.Delete(str2);
                XmlTextWriter writer = new XmlTextWriter(str2, null) {
                    Formatting = Formatting.Indented,
                    Indentation = 4
                };
                writer.WriteStartDocument();
                writer.WriteStartElement("Root");
                foreach (DataStruct struct2 in CommDataStruct)
                {
                    writer.WriteStartElement("Struct");
                    writer.WriteAttributeString("Name", struct2.StructName);
                    writer.WriteAttributeString("CName", struct2.CNName);
                    writer.WriteAttributeString("ProtoType", struct2.getProtoTypeName(struct2.ProtoType));
                    writer.WriteAttributeString("Comment", struct2.Comment);
                    writer.WriteAttributeString("MaxFieldId", struct2.MaxFieldId.ToString());
                    foreach (DataStruct.FieldDescriptor descriptor in struct2.fieldItem)
                    {
                        writer.WriteStartElement("Field");
                        writer.WriteAttributeString("PreDefine", descriptor.PreDefine.ToString());
                        writer.WriteAttributeString("FieldType", descriptor.FieldType ?? "");
                        writer.WriteAttributeString("Name", descriptor.FieldName);
                        writer.WriteAttributeString("CName", descriptor.CNName);
                        writer.WriteAttributeString("Comment", descriptor.Comment);
                        writer.WriteAttributeString("FieldId", descriptor.FieldId.ToString());
                        writer.WriteAttributeString("ValueSet", descriptor.ValueSet);
                        writer.WriteAttributeString("MinValue", descriptor.MinValue.ToString());
                        writer.WriteAttributeString("MaxValue", descriptor.MaxValue.ToString());
                        if (DataStruct.IsBaseType(descriptor.FieldType))
                        {
                            writer.WriteAttributeString("DefaultValue", descriptor.DefaultValue);
                        }
                        writer.WriteEndElement();
                    }
                    writer.WriteEndElement();
                }
                writer.WriteEndElement();
                writer.WriteEndDocument();
                writer.Flush();
                writer.Close();
            }
        }

        public static void SerializeXML(Dictionary<string, Module> moduleDic, string dir, Label label1)
        {
            string path = dir + @"\XML\";
            if (!Directory.Exists(path))
            {
                Directory.CreateDirectory(path);
            }
            string filename = path + "Module.xml";
            label1.Text = "正在生成文件: " + filename;
            label1.Refresh();
            XmlTextWriter writer = new XmlTextWriter(filename, null) {
                Formatting = Formatting.Indented,
                Indentation = 4
            };
            writer.WriteStartDocument();
            writer.WriteStartElement("xml");
            writer.WriteStartElement("module");
            foreach (KeyValuePair<string, Module> pair in moduleDic)
            {
                writer.WriteStartElement("sub_module");
                writer.WriteAttributeString("name", pair.Value.ModuleName);
                writer.WriteAttributeString("cname", pair.Value.CNName);
                writer.WriteAttributeString("fileName", pair.Value.ModuleName + ".xml");
                writer.WriteEndElement();
            }
            writer.WriteEndElement();
            writer.WriteEndDocument();
            writer.Flush();
            writer.Close();
        }

        public class DataStructComparer : IComparer
        {
            public int Compare(object x, object y) => 
                (((DataStruct) y).GenOrder - ((DataStruct) x).GenOrder);
        }
    }
}

