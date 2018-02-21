#include <iostream>

using namespace std;

const int TAULUKON_KOKO = 7;

void PrintShots(char[][TAULUKON_KOKO], int, int);

int main()
{
	char lauta[TAULUKON_KOKO][TAULUKON_KOKO] = { '0' };

	lauta[1][0] = 'x';
	lauta[2][0] = 'x';

	lauta[4][1] = 'x';
	lauta[4][2] = 'x';
	lauta[4][3] = 'x';

	lauta[0][6] = '#';
	lauta[1][6] = '#';
	lauta[2][6] = '#';
	lauta[3][6] = '#';

	lauta[5][0] = '*';
	lauta[5][1] = '*';
	lauta[5][2] = '*';
	lauta[5][3] = '*';
	lauta[5][4] = '*';

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
