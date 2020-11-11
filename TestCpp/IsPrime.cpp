#include <iostream>

using namespace std;

bool IsPrime(int number)
{
	if (number < 2)
	{
		return false;
	}

	for (int i = 2; i * i <= number; i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

void ProgramIsPrime()
{
	int number = 0;

	cout << "Give number" << endl;
	cin >> number;

	if (IsPrime(number) == true)
	{
		cout << "Number is prime" << endl;
	}
	else
	{
		cout << "Number is not prime" << endl;
	}
}