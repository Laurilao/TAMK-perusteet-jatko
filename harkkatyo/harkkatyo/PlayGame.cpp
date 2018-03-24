#include "PlayGame.h"
#include "Helpers.h"


struct Ship
{
	int xalku = 0;
	int xloppu = 0;
	int yalku = 0;
	int yloppu = 0;
};

void SelectedMode(string valinta, char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO])
{
	if (valinta == "1")
	{
		EnterShips(peliLauta);
	}
	else if (valinta == "2")
	{
		ShootingMode(ampumaLauta, peliLauta);
	}
	else if (valinta == "3")
	{

	}
}

void ShootingMode(char ampumaLauta[][LAUDAN_KOKO], char peliLauta[][LAUDAN_KOKO])
{
	bool gameOver = true;
	string koords;
	int x, y;

	do
	{
		gameOver = true;

		PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);

		cout << endl << "Anna ampumiskoordinaatti: ";
		getline(cin, koords);

		if (koords == "p" || koords == "P")
		{
			break;
		}

		if (MuunnaKoordinaatti(koords, &x, &y) == 0)
		{
			if (ampumaLauta[x][y] != '0')
			{
				cout << "Kohtaan on jo ammuttu..." << endl << endl;
			}
			else if (peliLauta[x][y] == '0')
			{
				cout << "Laukaus kohtaan " << koords << " ei osunut." << endl << endl;
				ampumaLauta[x][y] = 'x';
			}
			else if (peliLauta[x][y] != '0')
			{
				// TODO risuaidat
				CheckForSink(peliLauta, ampumaLauta, x, y, koords);
				ampumaLauta[x][y] = peliLauta[x][y];
			}
		}
		else
		{
			cout << "Virheellinen koordinaatti..." << endl << endl;
		}

			
		for (int i = 0; i < LAUDAN_KOKO; i++)
		{
			for (int j = 0; j < LAUDAN_KOKO; j++)
			{
				if (peliLauta[i][j] != '*' && peliLauta[i][j] != '0')
				{
					gameOver = false;
				}
			}
		}

		if (gameOver)
		{
			PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);
			cout << endl << "Onneksi olkoon, voitit!" << endl << endl;
		}

	} while (!gameOver);


}

void CheckForSink(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], int x, int y, string koords)
{
	char marker = peliLauta[x][y];
	bool found = false;

	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			if (peliLauta[i][j] == marker)
			{
				found = true;
			}
		}
	}

	if (!found)
	{
		cout << "Laukaus kohtaan " << koords << " upotti laivan." << endl << endl;
		for (int i = 0; i < LAUDAN_KOKO; i++)
		{
			for (int j = 0; j < LAUDAN_KOKO; j++)
			{
				if (peliLauta[i][j] == marker)
				{
					ampumaLauta[i][j] == '#';
				}
			}
		}
	}
	else
	{
		cout << "Laukaus kohtaan " << koords << " osui laivaan." << endl << endl;
	}
}

void EnterShips(char peliLauta[][LAUDAN_KOKO])
{
	string koords;
	char suunta;
	int x, y, koko;
	bool sisalla;

	do
	{
		do
		{
			cout << "Anna viiden pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 5;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna neljan pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 4;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna kolmen pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 3;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);

	PlaceShip(peliLauta, x, y, koko, suunta);

	do
	{
		do
		{
			cout << "Anna kahden pituisen laivan alkupiste: ";
			getline(cin, koords);
			koko = 2;

		} while (MuunnaKoordinaatti(koords, &x, &y) != 0);

		do
		{
			cout << "Anna suunta (p(ohjoinen)/i(ta)/e(tela)/l(ansi)): ";
			cin >> suunta;
			cin.ignore();
			suunta = tolower(suunta);

		} while (suunta != 'p' && suunta != 'i' && suunta != 'e' && suunta != 'l');

		sisalla = CheckBoundaries(x, y, suunta, koko);

		if (!sisalla)
		{
			cout << "Laiva ei ollut pelilaudan sisalla! Yrita uudelleen..." << endl;
		}

	} while (!sisalla);
	
	PlaceShip(peliLauta, x, y, koko, suunta);
}

void PlaceShip(char peliLauta[][LAUDAN_KOKO], int x, int y, int koko, char suunta)
{
	char marker;
	switch (koko)
	{
	case 5:
		marker = '5';
		break;
	case 4:
		marker = '4';
		break;
	case 3:
		marker = '3';
		break;
	case 2:
		marker = '2';
		break;
	}
	if (suunta == 'p')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x - i][y] = marker;
		}
	}
	else if (suunta == 'i')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x][y + i] = marker;
		}
	}
	else if (suunta == 'e')
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x + i][y] = marker;
		}
	}
	else
	{
		for (int i = 0; i < koko; i++)
		{
			peliLauta[x][y - i] = marker;
		}
	}
}

bool CheckBoundaries(int x, int y, char suunta, int koko)
{
	if (suunta == 'p')
	{
		if (x - koko < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'i')
	{
		if (y + koko > 7)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'e')
	{
		if (x + koko > 7)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else if (suunta == 'l')
	{
		if (y - koko < 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
		return false;
}
