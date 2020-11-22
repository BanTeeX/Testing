using System;

namespace Test
{
	class IdiotaExe
	{
		static void Execute()
		{
			Wuda wuda = new Wuda();
			wuda.NazwaTrunku = "Śliwufka";
			wuda.Procenty = 70;
			Debil pawel = new Debil();
			pawel.ImieKurwy = "tłustyszmaciarzjebanywpizdezjebpierdolonytepakurwaiwglchujmunamatule";
			pawel.StaryKurwy = new Stary();
			pawel.StaryKurwy.Imie = "Pawła stary";
			pawel.StaryKurwy.Pije(wuda);
			Console.WriteLine();
			if (pawel.StaryKurwy.CzySpanie())
			{
				Console.WriteLine($"{pawel.ImieKurwy} kładzie {pawel.StaryKurwy.Imie} najebanego({pawel.StaryKurwy.Naeabany}) do spania");
			}
			else
			{
				Console.WriteLine($"{pawel.ImieKurwy} nie kładzie {pawel.StaryKurwy.Imie} najebanego({pawel.StaryKurwy.Naeabany}) do spania");
			}
			pawel.Odjebuje("@everyone +10", TwojaStaraSize.Big);
		}
	}

	enum TwojaStaraSize
	{
		Medium = 1,
		Big = 100,
		Large = 10000,
		Giga = 1000000,
		Chung = 100000000,
		Tłustyszmaciarzjebanywpizdezjebpierdolonytepakurwaiwglchujmunamatule = Int32.MaxValue
	}

	class Debil
	{
		public string ImieKurwy { get; set; }
		public Stary StaryKurwy { get; set; }

		public void Odjebuje(string tekst, TwojaStaraSize jakBardzoOdjebuje)
		{
			for (int i = 0; i < (int)jakBardzoOdjebuje; i++)
			{
				Console.WriteLine(tekst);
			}
		}
	}

	class Stary
	{
		public string Imie { get; set; }
		public bool Naeabany { get; set; }

		public void Pije(Wuda wuda)
		{
			Naeabany = true;
			Console.WriteLine($"STARY:\nasienaebaem, wyjebaem calom: {wuda.NazwaTrunku}, miala: {wuda.Procenty} koni");
		}

		public bool CzySpanie()
		{
			if (Naeabany)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	public class Wuda
	{
		public string NazwaTrunku { get; set; }
		public int Procenty { get; set; }
	}
}
