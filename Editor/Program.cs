namespace Editor
{
    using System;
    using System.Runtime.InteropServices;
    using System.Windows.Forms;

    internal static class Program
    {
                [STAThread]
        private static void Main(string[] args)
        {
            if (args.Length > 0)
            {
                if (args[0] == "-g")
                {
                    Form1 f = new Form1();
                    f.Command_Open();
                }
            }
            else
            {
                Application.EnableVisualStyles();
                Application.SetCompatibleTextRenderingDefault(false);
                Application.Run(new Form1());
            }
        }
    }
}

