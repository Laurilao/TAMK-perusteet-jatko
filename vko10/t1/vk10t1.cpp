#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int E_KOORD_VAARIN = 1;
const int E_SUCCESS = 0;

int muunnaAmpumiskoordinaatti(string, int*, int*);

int main()
{
	string koords;
	int x, y;

	cout << "Syota ampumiskoordinaatit: ";
	getline(cin, koords);

	// Poista whitespace
	koords.erase(remove_if(koords.begin(), koords.end(), isspace), koords.end());

	if (muunnaAmpumiskoordinaatti(koords, &x, &y) == 0)
	{
		cout << "Ammuit: " << x << " " << y << endl;
	}
	else
		cout << "Laiton laukaus" << endl;


	system("pause");
	return 0;
}

int muunnaAmpumiskoordinaatti(string koords, int* x, int* y)
{
	if (koords.length() > 2 || koords.length() <= 0)
	{
		return E_KOORD_VAARIN;
	}

	int tempx = (int)toupper(koords[0]) - 65;
	int tempy = koords[1] - '0' - 1;

	if (tempx > 6 || tempx < 0)
	{
		return E_KOORD_VAARIN;
	}
	else if (tempy > 6 || tempy < 0)
	{
		return E_KOORD_VAARIN;
	}
	else
	{
		*x = tempx;
		*y = tempy;
		return E_SUCCESS;
	}
}
