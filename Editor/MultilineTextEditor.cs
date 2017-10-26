namespace Editor
{
    using System;
    using System.ComponentModel;
    using System.Drawing.Design;
    using System.Windows.Forms;
    using System.Windows.Forms.Design;

    public class MultilineTextEditor : UITypeEditor
    {
        public override object EditValue(ITypeDescriptorContext context, IServiceProvider provider, object value)
        {
            try
            {
                IWindowsFormsEditorService service = (IWindowsFormsEditorService) provider.GetService(typeof(IWindowsFormsEditorService));
                if ((service != null) && (value is string))
                {
                    TextBox control = new TextBox {
                        AcceptsReturn = true,
                        Multiline = true,
                        Height = 120,
                        BorderStyle = BorderStyle.None,
                        Text = value as string
                    };
                    service.DropDownControl(control);
                    return control.Text;
                }
            }
            catch (Exception)
            {
                return value;
            }
            return value;
        }

        public override UITypeEditorEditStyle GetEditStyle(ITypeDescriptorContext context) => 
            UITypeEditorEditStyle.DropDown;
    }
}

