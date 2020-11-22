#include <iostream>

using namespace std;

void fibo(int numberOfElements)
{
	int a = 0;
	int b = 1;
	for (int i = 0; i < numberOfElements; i++)
	{
		cout << a << endl;
		b += a;
		a = b - a;
	}
}