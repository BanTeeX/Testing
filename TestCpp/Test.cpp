#include <iostream>

using namespace std;

struct samochod
{
	string marka;
	string model;
	int rok = 0;

	samochod(string marka, string model, int rok) : marka(marka), model(model), rok(rok) { }

	void Print()
	{
		cout << "Marka: " << marka << ", model: " << model << ", rok: " << rok << ";" << endl;
	}
};

//int main()
//{
//	samochod moj("Audi", "A7", 2015);
//	samochod anny("BMW", "M5", 2017);
//
//	samochod moj = samochod("Audi", "A7", 2015);
//	samochod anny = samochod("BMW", "M5", 2017);
//
//	moj.Print();
//	anny.Print();
//}