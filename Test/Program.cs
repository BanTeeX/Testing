using System;

namespace Test
{
	class Program
	{
		static void Main(string[] args)
		{
			Random random = new Random();
			int count = 0;
			for (int i = 0; i < 100; i++)
			{
				if (random.Next(2) == 0)
				{
					count++;
				}
			}
			Console.WriteLine(count);
		}
	}
}
