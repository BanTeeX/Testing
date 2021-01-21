#include <iostream>
#include <time.h>

using namespace std;

//int main()
//{
//	srand(time(NULL));
//	int tab[10];
//	int random;
//	bool powtorzenie;
//	for (size_t i = 0; i < 10; i++)
//	{
//		tab[i] = -1;
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		random = rand() % 10;
//		powtorzenie = false;
//		for (int j = 0; j < i; j++)
//		{
//			if (tab[j] == random)
//			{
//				powtorzenie = true;
//				break;
//			}
//		}
//		if (powtorzenie)
//		{
//			i--;
//		}
//		else
//		{
//			tab[i] = random;
//		}
//	}
//	for (size_t i = 0; i < 10; i++)
//	{
//		cout << tab[i] << endl;
//	}
//}