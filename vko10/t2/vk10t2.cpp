#include <iostream>
#include <string>

using namespace std;

bool laillinenValinta(string, char);

int main()
{
	string sallitut = "1234L";
	char valinta;

	cout << "Anna valinta: ";
	cin >> valinta;

	if (laillinenValinta(sallitut, toupper(valinta)))
	{
		cout << "Laillinen valinta" << endl;
	}
	else
		cout << "Laiton valinta" << endl;

	system("pause");
	return 0;
}

bool laillinenValinta(string sallitut, char valinta)
{
	if (sallitut.find(valinta) != string::npos)
	{
		return true;
	}

	return false;
}