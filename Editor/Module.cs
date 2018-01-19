namespace Editor
{
    using System;
    using System.Collections;
    using System.Collections.Generic;
    using System.ComponentModel;
    using System.Drawing.Design;
    using System.Windows.Forms;

    public class Module
    {
        private string cnName = "";
        private string comment = "";
        public ArrayList configFiles = new ArrayList();
        public static Dictionary<int, List<Error>> errorDic = new Dictionary<int, List<Error>>();
        public static int key = 0;
        public ArrayList moduleDataStruct = new ArrayList();
        public static Dictionary<string, Module> ModuleDic = new Dictionary<string, Module>();
        private string moduleName = "";
        public static Dictionary<int, ErrorModuleName> moduleNameDic = new Dictionary<int, ErrorModuleName>();
        public ArrayList operateItem = new ArrayList();
        public TreeNode rpcProtoNode;
        private int startIdNum;
        private int syncDataVersion = 1;

        public static bool ContainsKey(string name)
        {
            foreach (KeyValuePair<string, Module> pair in ModuleDic)
            {
                foreach (DataStruct struct2 in pair.Value.moduleDataStruct)
                {
                    if (struct2.StructName == name)
                    {
                        return true;
                    }
                }
            }
            return false;
        }

        public DataStruct getModuleStruct(string name)
        {
            foreach (DataStruct struct2 in this.moduleDataStruct)
            {
                if (struct2.StructName == name)
                {
                    return struct2;
                }
            }
            foreach (object obj2 in DataStructConverter.CommDataStruct)
            {
                DataStruct struct3 = (DataStruct) obj2;
                if (struct3.StructName == name)
                {
                    return struct3;
                }
            }
            return null;
        }

        public OperaterItem.SubOperaterItem GetSubOperaterItem(string structName, string name)
        {
            foreach (OperaterItem item in this.operateItem)
            {
                foreach (OperaterItem.SubOperaterItem item2 in item.subOperateItem)
                {
                    if (item2.DataStructName == structName)
                    {
                        return item2;
                    }
                }
            }
            return null;
        }

        public void Remove(OperaterItem op)
        {
            this.operateItem.Remove(op);
        }

        public override string ToString() => 
            this.moduleName;

        public string CNName
        {
            get => 
                this.cnName;
            set
            {
                this.cnName = value;
            }
        }

        [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
        public string Comment
        {
            get => 
                this.comment;
            set
            {
                this.comment = value;
            }
        }

        public string ModuleName
        {
            get => 
                this.moduleName;
            set
            {
                if (value == "")
                {
                    MessageBox.Show("Module Name is empty!!!");
                }
                else if ((this.moduleName != value) && ModuleDic.ContainsKey(value))
                {
                    MessageBox.Show("Module :" + value + " Already Exist!!!");
                }
                else
                {
                    Module module = null;
                    bool flag = ModuleDic.TryGetValue(this.ModuleName, out module);
                    if (flag)
                    {
                        ModuleDic.Remove(this.ModuleName);
                    }
                    this.moduleName = value;
                    if (flag)
                    {
                        ModuleDic.Add(this.ModuleName, module);
                    }
                }
            }
        }

        public int StartIdNum
        {
            get => 
                this.startIdNum;
            set
            {
                foreach (Module module in ModuleDic.Values)
                {
                    if (module.StartIdNum == value)
                    {
                        MessageBox.Show("StartNum is already exists in Module :" + module.ModuleName);
                        return;
                    }
                }
                this.startIdNum = value;
            }
        }

        public int SyncDataVersion
        {
            get => 
                this.syncDataVersion;
            set
            {
                this.syncDataVersion = value;
            }
        }

        public class Error
        {
            public string id;
            public string name;
        }

        public class ErrorModuleName
        {
            public string cn;
            public string en;
        }

        public class OperaterItem
        {
            private string cnName = "";
            private string comment = "";
            public Module module;
            private string name = "";
            public ArrayList subOperateItem = new ArrayList();

            public string getFullName() => 
                ("Rpc" + this.name);

            public void Remove()
            {
                this.module.Remove(this);
            }

            public void Remove(SubOperaterItem sub)
            {
                this.subOperateItem.Remove(sub);
            }

            public override string ToString() => 
                this.name;

            public string CNName
            {
                get => 
                    this.cnName;
                set
                {
                    this.cnName = value;
                }
            }

            [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
            public string Comment
            {
                get => 
                    this.comment;
                set
                {
                    this.comment = value;
                }
            }

            public string Name
            {
                get => 
                    this.name;
                set
                {
                    if (value == "")
                    {
                        MessageBox.Show("Operate Name is empty!!!");
                    }
                    else
                    {
                        foreach (Module.OperaterItem item in this.module.operateItem)
                        {
                            if (item.getFullName() == value)
                            {
                                MessageBox.Show("Operate :" + value + " Already Exist!!!");
                                return;
                            }
                        }
                        this.name = value;
                    }
                }
            }

            public class SubOperaterItem
            {
                private string cnName = "";
                private string comment = "";
                private string dataStructName = "";
                private string name = "";
                public Module.OperaterItem operaterItem;
                private string opType = "OP_NONE";
                public Module.OperateType Type;

                public string getDataStructName() => 
                    (this.operaterItem.module.ModuleName + "_" + this.dataStructName);

                public Module.OperateType getOperateType(string value)
                {
                    switch (value)
                    {
                        case "OP_ASK":
                            return Module.OperateType.OP_ASK;

                        case "OP_REPLY":
                            return Module.OperateType.OP_REPLY;

                        case "OP_CLIENT_NOTIFY":
                            return Module.OperateType.OP_CLIENT_NOTIFY;

                        case "OP_SERVER_NOTIFY":
                            return Module.OperateType.OP_SERVER_NOTIFY;

                        case "OP_DUPLEX_NOTIFY":
                            return Module.OperateType.OP_DUPLEX_NOTIFY;
                    }
                    return Module.OperateType.OP_NONE;
                }

                public void Remove()
                {
                    this.operaterItem.Remove(this);
                }

                public void toSetCnName(string value)
                {
                    this.cnName = value;
                }

                public void toSetDataStructName(string value)
                {
                    this.dataStructName = value;
                }

                public void toSetName(string value)
                {
                    this.name = value;
                }

                public void toSetOpType(string value)
                {
                    this.opType = value;
                }

                public override string ToString() => 
                    this.name;

                public string CNName
                {
                    get => 
                        this.cnName;
                    set
                    {
                    }
                }

                [Editor(typeof(MultilineTextEditor), typeof(UITypeEditor))]
                public string Comment
                {
                    get => 
                        this.comment;
                    set
                    {
                        this.comment = value;
                    }
                }

                [TypeConverter(typeof(ModuleDataStructConverter))]
                public string DataStructName
                {
                    get => 
                        this.dataStructName;
                    set
                    {
                    }
                }

                public string Name
                {
                    get => 
                        this.name;
                    set
                    {
                    }
                }

                [TypeConverter(typeof(SubOperaterTypeConverter))]
                public string OpType
                {
                    get => 
                        this.opType;
                    set
                    {
                        Module.OperateType type = this.getOperateType(value);
                        foreach (Module.OperaterItem.SubOperaterItem item in this.operaterItem.subOperateItem)
                        {
                            if (item.Type == type)
                            {
                                MessageBox.Show("Operate already contain [" + value + "]");
                                return;
                            }
                        }
                        string key = this.operaterItem.module.ModuleName + "_" + this.operaterItem.Name + this.Name;
                        if (DataStruct.DataStructDic.ContainsKey(key))
                        {
                            DataStruct struct2 = DataStruct.DataStructDic[key];
                            struct2.selfTreeNode.Remove();
                            DataStruct.DataStructDic.Remove(key);
                            this.operaterItem.module.moduleDataStruct.Remove(struct2);
                        }
                        this.opType = value;
                        string str2 = "";
                        string str3 = "";
                        string str6 = value;
                        if (str6 != null)
                        {
                            if (str6 == "OP_ASK")
                            {
                                str2 = "Ask";
                                str3 = "请求";
                            }
                            else if (str6 == "OP_REPLY")
                            {
                                str2 = "Reply";
                                str3 = "回应";
                            }
                            else if (((str6 == "OP_NOTIFY") || (str6 == "OP_CLIENT_NOTIFY")) || ((str6 == "OP_SERVER_NOTIFY") || (str6 == "OP_DUPLEX_NOTIFY")))
                            {
                                str2 = "Notify";
                                str3 = "通知";
                            }
                        }
                        this.Type = type;
                        this.toSetName(str2);
                        this.toSetCnName(str3);
                        if (this.Type != Module.OperateType.OP_NONE)
                        {
                            this.toSetDataStructName("Rpc" + this.operaterItem.Name + str2);
                            Module module = this.operaterItem.module;
                            if (!DataStruct.DataStructDic.ContainsKey(module.moduleName + this.DataStructName))
                            {
                                TreeNode node = module.rpcProtoNode.Nodes.Add(this.DataStructName);
                                module.rpcProtoNode.Expand();
                                DataStruct struct3 = new DataStruct();
                                module.moduleDataStruct.Add(struct3);
                                struct3.module = module;
                                struct3.selfTreeNode = node;
                                struct3.StructName = this.DataStructName;
                                struct3.CNName = this.operaterItem.CNName + this.CNName;
                                struct3.ProtoType = DataStruct.protoTypeE.RpcProto;
                                struct3.ToSetDataType(DataStruct.SyncType.RPCData);
                                struct3.SubOperate = this;
                                node.Name = "NewDataStruct";
                                node.ImageIndex = 2;
                                node.Tag = struct3;
                                if (DataStruct.DataStructDic.ContainsKey(struct3.getFullName()))
                                {
                                    DataStruct.DataStructDic.Remove(struct3.getFullName());
                                }
                                DataStruct.DataStructDic.Add(struct3.getFullName(), struct3);
                                if (type == Module.OperateType.OP_REPLY)
                                {
                                    DataStruct.FieldDescriptor descriptor = new DataStruct.FieldDescriptor();
                                    string text = "Result";
                                    TreeNode node2 = node.Nodes.Add(text);
                                    node.Expand();
                                    descriptor.FieldId = struct3.GetMaxFieldId();
                                    descriptor.dataStruct = struct3;
                                    descriptor.FieldName = text;
                                    descriptor.CNName = "返回结果";
                                    descriptor.Comment = "-9999 模块未启动\r\n-9998 请求字段值范围出错";
                                    descriptor.DefaultValue = "-9999";
                                    descriptor.FieldType = "sint32";
                                    struct3.fieldItem.Add(descriptor);
                                    node2.Name = "NewField";
                                    node2.ImageIndex = 3;
                                    node2.Tag = descriptor;
                                }
                            }
                        }
                    }
                }
            }
        }

        public enum OperateType
        {
            OP_NONE,
            OP_ASK,
            OP_REPLY,
            OP_NOTIFY,
            OP_CLIENT_NOTIFY,
            OP_SERVER_NOTIFY,
            OP_DUPLEX_NOTIFY
        }
    }
}

