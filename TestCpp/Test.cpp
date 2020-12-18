#include <iostream>
#include <Windows.h>
#undef max(a,b)

using namespace std;

int main()
{
	int input;
	while (true)
	{
		cin >> input;
		switch (input)
		{
		case 1:
			cout << "case1" << endl;
			break;
		case 2:
			cout << "case2" << endl;
			break;
		default:
			cout << "default" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			break;
		}
	}
}