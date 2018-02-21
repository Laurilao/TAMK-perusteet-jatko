#include <iostream>

using namespace std;

// Funktio saa viiteparametrina a-muuttujan kopion osoitteen
void fun2(int *a)
{
	// Asetetaan a-muuttujan kopion arvoksi 3
	*a = 3;
}

// Funktio saa arvoparametrina kopion a-muuttujasta
void fun1(int a)
{
	// a-muuttujan kopio viiteparametrina funktiolle fun2
	fun2(&a);
}

int main()
{
	// Muuttuja a saa arvon 1
	int a = 1;

	// Muuttuja a arvoparametrina funktiolle fun1
	fun1(a);

	// fun2 funktiossa muutettu vain kopion arvoa, eli tulostetaan 1
	cout << a << endl;
	
	system("pause");
	return 0;
}