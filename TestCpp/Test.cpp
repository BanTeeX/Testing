#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "Polish");
	string polskie = "¹êæ¿Ÿó";
	cout << polskie << endl;

	fstream file;
	file.open("plik.txt", ios::in);
	string polskie2;
	getline(file, polskie2);
	cout << polskie2 << endl;
	file.close();
}