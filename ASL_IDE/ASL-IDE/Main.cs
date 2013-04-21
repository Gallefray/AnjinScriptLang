using System;
using Gtk;



namespace ASLIDE
{
	class MainClass
	{
		public static void Main (string[] args)
		{
			var textSize = 10;
			Application.Init ();
			MainWindow win = new MainWindow ();
			win.Show ();
			Application.Run ();
		}
	}
}
