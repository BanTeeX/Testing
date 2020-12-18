#include <iostream>

using namespace std;

void ZmodyfikujZmienne(int& i, double& d)
{
	do
	{
		i++;
		d += 5;
	} while (d / 2 < i);
}

//int main()
//{
//	int liczba1 = 1;
//	double liczba2 = 1.0;
//	ZmodyfikujZmienne(liczba1, liczba2);
//	cout << liczba1 << " " << liczba2;
//}