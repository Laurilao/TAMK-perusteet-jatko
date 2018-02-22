#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int TAULUKON_KOKO = 7;

void PrintShots(char[][TAULUKON_KOKO], int, int);
void LoadGame(char[][TAULUKON_KOKO]);

int main()
{
	char lauta[TAULUKON_KOKO][TAULUKON_KOKO] = { 0 };

	LoadGame(lauta);

	PrintShots(lauta, TAULUKON_KOKO, TAULUKON_KOKO);

	system("pause");
	return 0;
}

void PrintShots(char lauta[][TAULUKON_KOKO], int rows, int cols)
{

	cout << "Pelitilanne on seuraava:" << endl << endl;
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << "   --------------- " << endl;

	for (int i = 0; i < rows; i++) {

		cout << static_cast<char>('A' + i) << " | ";

		for (int j = 0; j < cols; j++)
		{
			if (lauta[i][j] == '0' || lauta[i][j] == NULL)
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

void LoadGame(char lauta[][TAULUKON_KOKO])
{
	ifstream inFile;
	string rivi;
	int row = 0;

	try
	{
		inFile.open("Save.txt");

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

		for (int i = 0; i < TAULUKON_KOKO; i++)
		{
			lauta[row][i] = rivi[i];
		}
		row++;
	}
	cout << "Pelitilanne ladattu!" << endl;
	inFile.close();
}