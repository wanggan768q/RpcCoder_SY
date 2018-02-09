namespace Editor
{
    using System;
    using System.Collections;
    using System.ComponentModel;

    public class DataStructConverter : StringConverter
    {
        public static ArrayList CommDataStruct = new ArrayList();

        public static bool ContainsKey(string name, ref DataStruct ds)
        {
            foreach (DataStruct struct2 in CommDataStruct)
            {
                if (struct2.StructName == name)
                {
                    ds = struct2;
                    return true;
                }
            }
            return false;
        }

        public override TypeConverter.StandardValuesCollection GetStandardValues(ITypeDescriptorContext context)
        {
            DataStruct.FieldDescriptor instance = (DataStruct.FieldDescriptor) context.Instance;
            Module module = instance.dataStruct.module;
            ArrayList list = new ArrayList { 
                "bool",
                "int32",
                "sint32",
                "float",
                "sint64",
                "int64",
                "uint64",
                "string",
                "bytes"
            };
            foreach (DataStruct struct2 in CommDataStruct)
            {
                list.Add(struct2.StructName);
            }
            if (module != null)
            {
                foreach (DataStruct struct3 in module.moduleDataStruct)
                {
                    if ((struct3.ProtoType == instance.dataStruct.ProtoType) && (struct3.DataType == DataStruct.SyncType.ItemData))
                    {
                        list.Add(struct3.StructName);
                    }
                }
            }
            list.Remove(instance.dataStruct.StructName);
            return new TypeConverter.StandardValuesCollection(list.ToArray());
        }

        public override bool GetStandardValuesExclusive(ITypeDescriptorContext context) => 
            true;

        public override bool GetStandardValuesSupported(ITypeDescriptorContext context) => 
            true;
    }
}

