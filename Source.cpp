#include <iostream>
#include <iomanip>
using namespace std;

const int TAULUKON_RIVEJA = 3;
const int TAULUKON_SARAKKEITA = 4;

void tuplaa(int[][TAULUKON_SARAKKEITA], int, int);
void tulosta(int[][TAULUKON_SARAKKEITA], int, int);

int main()
{
	
	int taulukko[TAULUKON_RIVEJA][TAULUKON_SARAKKEITA] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	tulosta(taulukko, TAULUKON_RIVEJA, TAULUKON_SARAKKEITA);

	tuplaa(taulukko, TAULUKON_RIVEJA, TAULUKON_SARAKKEITA);

	tulosta(taulukko, TAULUKON_RIVEJA, TAULUKON_SARAKKEITA);

	return 0;
}

void tuplaa(int pTaulukko[][TAULUKON_SARAKKEITA], int riveja, int sarakkeita)
{
	for (int i = 0; i < riveja; i++)
		for (int j = 0; j < sarakkeita; j++)
			pTaulukko[i][j] *= 2;
}

void tulosta(int pTaulukko[][TAULUKON_SARAKKEITA], int riveja, int sarakkeita)
{
	for (int i = 0; i < riveja; i++) {
		for (int j = 0; j < sarakkeita; j++)
			cout << setw(3) << pTaulukko[i][j] << " ";

		cout << endl;
	}
	cout << endl;
}
