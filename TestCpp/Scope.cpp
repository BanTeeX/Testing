#include <iostream>

using namespace std;

bool TryAdd(long long int a, long long int b, long long int& result)
{
    long long int pom = LLONG_MAX - a;
    if (b > pom)
    {
        return false;
    }
    else
    {
        result = a + b;
        return true;
    }
}

void ScopeProgram()
{
    long long int a;
    long long int b;
    long long int result;
    cout << "Podaj pierwszy skladnik" << endl;
    cin >> a;
    cout << "Podaj drugi skladnik" << endl;
    cin >> b;
    if (TryAdd(a, b, result) == true)
    {
        cout << "Wynik: " << result << endl;
    }
    else
    {
        cout << "Dane s¹ za du¿e" << endl;
    }
}