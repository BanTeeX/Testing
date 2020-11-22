#include <iostream>

using namespace std;

void MaxProgram()
{
	int numbers[100];
	int amountOfNumber = 0;
	cout << "Give amount of numbers you want to enter:" << endl;
	cin >> amountOfNumber;
	if (amountOfNumber > 0)
	{
		cout << "Enter the numbers in separate lines:" << endl;
		for (int i = 0; i < amountOfNumber; i++)
		{
			cin >> numbers[i];
		}
		int max = numbers[0];
		for (int i = 1; i < amountOfNumber; i++)
		{
			if (max < numbers[i])
			{
				max = numbers[i];
			}
		}
		cout << "The largest number is: " << max << endl;
	}
	else
	{
		cout << "No numbers entered" << endl;
	}
}