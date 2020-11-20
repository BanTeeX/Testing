using System;

namespace Test
{
	class Program
	{
		static void Main(string[] args)
		{
			Console.WriteLine("Hello World!");
			int[] array1;
			int[] array2;
			array1 = (int[])ReturnTab(5);
			array2 = (int[])ReturnTab(10);
			foreach (var item in array1)
			{
				Console.WriteLine($"Array1: {item}");
			}
			Console.WriteLine();
			foreach (var item in array2)
			{
				Console.WriteLine($"Array2: {item}");
			}
		}

		static Array ReturnTab(int length)
		{
			int[] tab = new int[length];
			for (int i = 0; i < length; i++)
			{
				tab[i] = i + 1;
			}
			return tab;
		}
	}
}
