/*
harjoitus 1.	Tee pääohjelma, jossa:
•	teet kaksiulotteisen 7 x 7 int-taulukon. Tämä taulukko on ehdotukseni laivanupotuspelin laivojen sijainnin hallintaa varten.
Solun sisältö on 0, jos ko. kohdassa pelialueella ei ole laivaa ja vastaavasti 2, 3, 4 tai 5 jos ko. pituisen laivan osa
sijaitsee ko. solussa.
•	alustat kyseisen taulukon nollilla
•	tulostat tyhjän pelialueen sisällön näytölle
•	sijoitat taulukkoon laivanupotuspelin laivat haluamiisi kohtiin ihan vain indeksoimalla taulukon sopivia soluja ja
sijoittamalla niihin int-arvoja 2, 3, 4 ja 5
•	tulostat pelialueen sisällön näytölle
*/

#include <iostream>
#include "Laivat.h"
using namespace std;

int main()
{
	int playArea[ROWS][COLS] = {};

	printShips(playArea, ROWS, COLS);

	playArea[2][6] = 5;
	playArea[3][6] = 5;
	playArea[4][6] = 5;
	playArea[5][6] = 5;
	playArea[6][6] = 5;

	playArea[1][0] = 4;
	playArea[1][1] = 4;
	playArea[1][2] = 4;
	playArea[1][3] = 4;

	playArea[2][0] = 3;
	playArea[2][1] = 3;
	playArea[2][2] = 3;

	playArea[3][0] = 2;
	playArea[3][1] = 2;

	printShips(playArea, ROWS, COLS);

	return 0;
}

/*
    1 2 3 4 5 6 7
  -----------------
A | 5 5 5 5 5   3 | A
B |             3 | B
C |             3 | C
D |         4     | D
E |   2 2   4     | E
F |         4     | F
G |         4     | G
  -----------------
    1 2 3 4 5 6 7
*/

void printShips(int shipsArray[][COLS], int rows, int cols)
{
	cout << "    1 2 3 4 5 6 7  " << endl;
	cout << "  -----------------" << endl;

	for (int i = 0; i < rows; i++) {
		cout << static_cast<char>('A' + i ) << " | ";
		for (int j = 0; j < cols; j++) {
			if (0 == shipsArray[i][j])
				cout << ' ' << " ";
			else
				cout << shipsArray[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "  -----------------" << endl;
	cout << "    1 2 3 4 5 6 7  " << endl;	
}
