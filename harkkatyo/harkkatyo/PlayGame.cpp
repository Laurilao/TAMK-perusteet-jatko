#include "PlayGame.h"
#include "Helpers.h"


// Aja valikon valinnan mukainen aliohjelma
void SelectedMode(string valinta, char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	if (valinta == "1")
	{
		EnterShips(peliLauta, ampumaLauta, boardIsEmpty);
	}
	else if (valinta == "2")
	{
		if (*boardIsEmpty == true)
		{
			cout << "Valitse ensin laivojen sijainnit!" << endl;
		}
		else
		{
			ShootingMode(ampumaLauta, peliLauta, boardIsEmpty);
		}
	}
	else if (valinta == "3")
	{
		RandomPlacement(peliLauta, ampumaLauta, boardIsEmpty);
		
	}
	else if (valinta == "4")
	{
		if (*boardIsEmpty == false)
		{
			SaveGame(peliLauta, ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);
		}
		else
			cout << "Ei voi tallentaa tyhjaa pelitilannetta!" << endl << endl;
	}
	else if (valinta == "5")
	{
		LoadGame(peliLauta, ampumaLauta);
		*boardIsEmpty = false;
	}
}

// Ajetaan ampumismoodia kunnes peli ohi tai valitaan paluu (p)
void ShootingMode(char ampumaLauta[][LAUDAN_KOKO], char peliLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	string koords;
	int x, y;
	bool debugPrint = false;
	bool gameOver = false;

	do
	{
		// Jos käytetty laivojen vakoilua, ei tulosteta uudestaan pelitilannetta
		if (!debugPrint)
		{
			PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);
		}
		debugPrint = false;

		cout << endl << "Anna ampumiskoordinaatti: ";
		getline(cin, koords);
		cout << endl;

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
				CheckForSink(peliLauta, ampumaLauta, x, y, koords);
			}
		}
		// Jos syötetään p, palataan valikkoon
		else if (koords == "p" || koords == "P")
		{
			break;
		}
		// Laivojen sijainnin vakoilu
		else if (koords == "\\@")
		{
			cout << "Laivat sijaitsevat seuraavissa paikoissa:" << endl << endl;
			TulostaLauta(peliLauta, LAUDAN_KOKO, LAUDAN_KOKO);
			debugPrint = true;
		}
		else
		{
			cout << "Virheellinen koordinaatti..." << endl << endl;
		}

		gameOver = IsGameOver(peliLauta, ampumaLauta);

		if (gameOver)
		{
			*boardIsEmpty = true;
			PrintShots(ampumaLauta, LAUDAN_KOKO, LAUDAN_KOKO);
			cout << endl << "Onneksi olkoon, voitit!" << endl << endl;
		}

	} while (!gameOver);
}

// Tarkista onko peli ohi
bool IsGameOver(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO])
{
	bool shipsLeft = false;

	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			if (peliLauta[i][j] != '0')
			{
				// Jos sijoittelutaulukon laivaa vastaava ampumataulukon ruutu ei ole uponnut laiva, peli on vielä kesken
				if (ampumaLauta[i][j] != '#')
				{
					return false;
				}
			}
		}
	}
	
	return true;
}

// Tarkista upposiko osuman saanut laiva
int CheckForSink(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], int x, int y, string koords)
{
	int hitCount = 0;
	char shipMarker = peliLauta[x][y];
	ampumaLauta[x][y] = shipMarker;
	bool finalBlow = false;

	for (int i = 0; i < LAUDAN_KOKO; i++)
	{
		for (int j = 0; j < LAUDAN_KOKO; j++)
		{
			if (ampumaLauta[i][j] == shipMarker)
			{
				hitCount++;
			}
		}
	}

	switch (shipMarker)
	{
	case '5':
		finalBlow = hitCount == 5 ? true : false;
		break;
	case '4':
		finalBlow = hitCount == 4 ? true : false;
		break;
	case '3':
		finalBlow = hitCount == 3 ? true : false;
		break;
	case '2':
		finalBlow = hitCount == 2 ? true : false;
		break;
	default:
		break;
	}

	// Jos laivan viimeinen osa, vaihda * -merkit #-merkeiksi 
	if (finalBlow)
	{
		cout << "Laukaus kohtaan " << koords << " upotti laivan." << endl << endl;
		for (int i = 0; i < LAUDAN_KOKO; i++)
		{
			for (int j = 0; j < LAUDAN_KOKO; j++)
			{
				if (ampumaLauta[i][j] == shipMarker)
				{
					ampumaLauta[i][j] = '#';
				}
			}
		}
		return 1;
	}
	else
	{
		cout << "Laukaus kohtaan " << koords << " osui laivaan." << endl << endl;
		return 0;
	}
}

// Sijoita laivat käsin pelilaudalle
void EnterShips(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	string koords;
	char suunta;
	int x, y, koko;
	bool validPlacement;

	Alusta(peliLauta);
	Alusta(ampumaLauta);

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

		validPlacement = CheckValidPlacement(peliLauta, x, y, suunta, koko);

	} while (!validPlacement);

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

		validPlacement = CheckValidPlacement(peliLauta, x, y, suunta, koko);

	} while (!validPlacement);

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

		validPlacement = CheckValidPlacement(peliLauta, x, y, suunta, koko);

	} while (!validPlacement);

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

		validPlacement = CheckValidPlacement(peliLauta, x, y, suunta, koko);

	} while (!validPlacement);
	
	PlaceShip(peliLauta, x, y, koko, suunta);

	*boardIsEmpty = false;
}

// Aseta laiva pelilaudalle
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

// Tarkista onko käsin yritetty sijoitus laillinen
bool CheckValidPlacement(char peliLauta[][LAUDAN_KOKO], int x, int y, char suunta, int koko)
{
	bool withinBoundaries = CheckBoundaries(x, y, suunta, koko);

	if (withinBoundaries)
	{
		bool noOverlap = CheckOverlap(peliLauta, x, y, suunta, koko);

		if (noOverlap)
		{
			return true;
		}
		else
		{
			cout << "Alla on jo laiva!" << endl << endl;
			return false;
		}
	}
	else
	{
		cout << "Valinta ei ole pelilaudan sisalla!" << endl << endl;
		return false;
	}
}

// Tarkista yritetäänkö sijoittaa olemassa olevan laivan päälle
bool CheckOverlap(char peliLauta[][LAUDAN_KOKO], int x, int y, char suunta, int koko)
{
	if (suunta == 'i')
	{
		for (int i = 0; i < koko; i++)
		{
			if (peliLauta[x][y + i] != '0')
			{
				return false;
			}
		}
	}
	else if (suunta == 'e')
	{
		for (int i = 0; i < koko; i++)
		{
			if (peliLauta[x + i][y] != '0')
			{
				return false;
			}
		}
	}
	else if (suunta == 'l')
	{
		for (int i = 0; i < koko; i++)
		{
			if (peliLauta[x][y - i] != '0')
			{
				return false;
			}
		}
	}
	else if (suunta == 'p')
	{
		for (int i = 0; i < koko; i++)
		{
			if (peliLauta[x - i][y] != '0')
			{
				return false;
			}
		}
	}

	return true;
}

// Tarkista yritetäänkö sijoittaa pelilaudan ulkopuolelle
bool CheckBoundaries(int x, int y, char suunta, int koko)
{
	if (suunta == 'p')
	{
		if (x - koko < -1)
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
		if (y - koko < -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

// Sijoittele laivat satunnaisesti pelilaudalle
void RandomPlacement(char peliLauta[][LAUDAN_KOKO], char ampumaLauta[][LAUDAN_KOKO], bool* boardIsEmpty)
{
	map<int, char> directions;
	directions[0] = 'p';
	directions[1] = 'i';
	directions[2] = 'e';
	directions[3] = 'l';

	Alusta(peliLauta);
	Alusta(ampumaLauta);

	PlaceRandomly(peliLauta, 5, directions);
	PlaceRandomly(peliLauta, 4, directions);
	PlaceRandomly(peliLauta, 3, directions);
	PlaceRandomly(peliLauta, 2, directions);

	*boardIsEmpty = false;
}

// Sijoita parametrina saadun kokoinen laiva pelilaudalle
void PlaceRandomly(char peliLauta[][LAUDAN_KOKO], int koko, map<int, char> directions)
{
	int x, y;
	int debugTryCount = 0;
	char suunta;
	bool wasValid = false;

	// Random number generaattori
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> koord(0, 6);
	uniform_int_distribution<> direction(0, 3);

	// Luo satunnaissijoituksia kunnes validi yhdistelmä saatu
	do
	{
		x = koord(gen);
		y = direction(gen);
		suunta = directions[rand() % 4];

		if (CheckBoundaries(x, y, suunta, koko))
		{
			if (CheckOverlap(peliLauta, x, y, suunta, koko))
			{
				wasValid = true;
			}
		}
		debugTryCount++;

	} while (!wasValid);

	PlaceShip(peliLauta, x, y, koko, suunta);

	cout << koko << ":n pituinen laiva lisatty!" << endl;
	//cout << "Yrityksia meni: " << debugTryCount << endl;

}
