#include "Helpers.h"

using namespace std;

void TulostaLauta(char lauta[][LAUDAN_KOKO], int rows, int cols)
{
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << "   --------------- " << endl;

	for (int i = 0; i < rows; i++) {

		cout << static_cast<char>('A' + i) << " | ";

		for (int j = 0; j < cols; j++)
		{
			if (lauta[i][j] == '0')
				cout << ' ' << " ";
			else
				cout << lauta[i][j] << " ";

			if (j == cols - 1)
				cout << "| " << static_cast<char>('A' + i);
		}
		cout << endl;
	}
	cout << "   --------------- " << endl;
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << endl;
}

void PrintShots(char lauta[][LAUDAN_KOKO], int rows, int cols)
{

	cout << "Pelitilanne on seuraava:" << endl << endl;
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << "   --------------- " << endl;

	for (int i = 0; i < rows; i++) {

		cout << static_cast<char>('A' + i) << " | ";

		for (int j = 0; j < cols; j++)
		{
			if (lauta[i][j] == '0')
				cout << ' ' << " ";
			else if (lauta[i][j] == '#' || lauta[i][j] == 'x')
				cout << lauta[i][j] << " ";
			else
				cout << '*' << " ";

			if (j == cols - 1)
				cout << "| " << static_cast<char>('A' + i);
		}
		cout << endl;
	}
	cout << "   --------------- " << endl;
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << endl;

}

void LoadGame(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO])
{
	ifstream inFile;
	string rivi;
	int row = 0;

	try
	{
		inFile.open("pelitilanne.txt");

		if (!inFile.is_open())
		{
			throw "Tiedostoa ei voitu avata";
		}
	}
	catch (const char* error)
	{
		cout << endl << error << endl;
		return;
	}

	while (inFile.peek() != EOF)
	{
		getline(inFile, rivi);

		if (row < 7)
		{
			for (int i = 0; i < LAUDAN_KOKO; i++)
			{
				peliLauta[row][i] = rivi[i];
			}
		}
		else
		{
			for (int i = 0; i < LAUDAN_KOKO; i++)
			{
				ampumaLauta[row - 7][i] = rivi[i];
			}
		}
		row++;
	}
	
	cout << "Pelitilanne ladattu!" << endl;
	inFile.close();
}

bool FileExists() 
{
	ifstream inFile;

	inFile.open("pelitilanne.txt");

	if (inFile.is_open())
	{
		inFile.close();
		return true;
	}
	else 
	{
		return false;
	}
}


void SaveGame(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], int rows, int cols)
{
	string overWrite = "";

	if (FileExists())
	{
		cout << "Tiedosto on jo olemassa, haluatko ylikirjoittaa? (k/e): ";
		
		while (overWrite != "k" && overWrite != "e")
		{
			getline(cin, overWrite);

			if (overWrite != "k" && overWrite != "e")
			{
				cout << "Virheellinen valinta, yrita uudelleen: ";
			}
		}

		if (overWrite == "e")
		{
			cout << "Tallentaminen keskeytetty" << endl;
			return;
		}
	}

	ofstream outFile;

	outFile.open("pelitilanne.txt");

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (peliLauta[i][j] == NULL || peliLauta[i][j] == '0')
			{
				outFile << "0";
			}
			else
			{
				outFile << peliLauta[i][j];
			}
		}
		outFile << endl;
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (ampumaLauta[i][j] == NULL || ampumaLauta[i][j] == '0')
			{
				outFile << "0";
			}
			else
			{
				outFile << ampumaLauta[i][j];
			}
		}
		if (i < rows - 1)
		{
			outFile << endl;
		}
	}
	cout << "Pelitilanne tallennettu!" << endl;

	outFile.close();
}

string PrintMenu()
{
	vector<string> sallitut{ "1", "2", "3", "4", "5", "L", "l" };
	string valinta;
	bool valid = false;

	do
	{
		cout << endl << "Laivanupotuspeli" << endl;
		cout << "================" << endl << endl;
		cout << "Valinnat: " << endl;
		cout << "1) Syota laivat" << endl;
		cout << "2) Pelaa" << endl;
		cout << "3) Arvo laivojen sijainnit" << endl;
		cout << "4) Tallenna pelitilanne" << endl;
		cout << "5) Lataa pelitilanne" << endl;
		cout << "L) Lopeta" << endl << endl;
		cout << "Valintasi: ";
		getline(cin, valinta);

		if (valinta.length() > 1 || find(sallitut.begin(), sallitut.end(), valinta) == sallitut.end())
		{
			cout << "Virheellinen valinta, yrita uudelleen!" << endl << endl;
		}
		else if (find(sallitut.begin(), sallitut.end(), valinta) != sallitut.end())
		{
			cout << endl;
			valid = true;
		}

	} while (!valid);


	return valinta;
}

int MuunnaKoordinaatti(string koords, int* x, int* y)
{
	// Poista whitespace
	koords.erase(remove_if(koords.begin(), koords.end(), isspace), koords.end());

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

void Alusta(char lauta[][LAUDAN_KOKO])
{
	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			lauta[i][j] = '0';
		}
	}
}

bool LaillinenValinta(string sallitut, char valinta)
{
	if (sallitut.find(valinta) != string::npos)
	{
		return true;
	}

	return false;
}

void DebugPrint(char peliLauta[][LAUDAN_KOKO])
{
	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			cout << peliLauta[i][j];
		}
		cout << endl;
	}
}