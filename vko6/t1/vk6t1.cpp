#include <iostream>

using namespace std;

const int LAUDAN_KOKO = 7;

void tulostaLauta(int shipsArray[][LAUDAN_KOKO], int rows, int cols);

int main()
{

	int lauta[LAUDAN_KOKO][LAUDAN_KOKO] = { 0 };

	lauta[1][0] = 2;
	lauta[2][0] = 2;

	lauta[4][1] = 3;
	lauta[4][2] = 3;
	lauta[4][3] = 3;

	lauta[0][6] = 4;
	lauta[1][6] = 4;
	lauta[2][6] = 4;
	lauta[3][6] = 4;

	lauta[5][0] = 5;
	lauta[5][1] = 5;
	lauta[5][2] = 5;
	lauta[5][3] = 5;
	lauta[5][4] = 5;

	tulostaLauta(lauta, LAUDAN_KOKO, LAUDAN_KOKO);

	system("pause");
	return 0;
}

void tulostaLauta(int lauta[][LAUDAN_KOKO], int rows, int cols)
{
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << "   --------------- " << endl;

	for (int i = 0; i < rows; i++) {

		cout << static_cast<char>('A' + i) << " | ";

		for (int j = 0; j < cols; j++) 
		{
			if (lauta[i][j] == 0)
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