#include <iostream>
#include <string>
#include <vector>

using namespace std;

string PrintMenu();

int main()
{
	string valinta = PrintMenu();


	system("pause");
	return 0;
}

string PrintMenu()
{
	vector<string> sallitut{ "1", "2", "3", "L", "l" };
	string valinta;

	do
	{
		cout << "Laivanupotuspeli" << endl;
		cout << "================" << endl << endl;
		cout << "Valinnat: " << endl;
		cout << "1) Syota laivat" << endl;
		cout << "2) Pelaa" << endl;
		cout << "3) Arvo laivojen sijainnit" << endl;
		cout << "L) Lopeta" << endl << endl;
		cout << "Valintasi: ";
		getline(cin, valinta);

		if (valinta.length() > 1 || find(sallitut.begin(), sallitut.end(), valinta) == sallitut.end())
		{
			cout << "Virheellinen valinta, yrita uudelleen!" << endl << endl;
		}
		else if (find(sallitut.begin(), sallitut.end(), valinta) != sallitut.end())
		{
			cout << "Valitsit: " << valinta << endl << endl;
		}

	} while (valinta != "L" && valinta != "l");


	return valinta;
}