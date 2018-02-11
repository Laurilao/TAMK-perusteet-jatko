

/*
harjoitus 1.	Suunnittele kurssin harjoitusty�st� seuraavat toiminnot pseudokoodina:
a)	Ohjelman k�ynnistymisen yhteydess� huolehdittavat asiat
b)	Ohjelman p��valikon k�sittely
c)	Yhden ammunnan k�sittely ohjelmassa.
Tee pseudokoodi hyvin karkealla tasolla. Voit kirjoittaa sit� suoraan valitsemallasi tekstieditorilla
(tulos = .txt-loppuliitteinen tiedosto). Mallia pseudokoodin tuottamiseen l�yd�t kurssin teoriakalvosarjan 
Luentokalvot - Osa 2 sivuilta 31 - 37 (k�sitelty syksyll� kurssilla Ohjelmointikielet, perusteet).

a)
	Alusta pelilauta
	Alusta pelin muut muuttujat: upotukset, osumat jne.
	N�yt� valikko
	Lue valinta

b)
	Toista
		Tulosta p��valikko n�yt�lle
		Lue valinta
		Jos valinta = 1
			Tee 1:n mukaiset toimenpiteet
		Muutoin
		Jos valinta = 2
			Tee 1:n mukaiset toimenpiteet
		...
		Jos valinta = lopeta
			Aseta lopetuslippu p��lle
		Muutoin
			Tulosta ilmoitus "v��r� valinta!"
	Kunnes k�ytt�j� haluaa lopettaa pelin

c)
	Lue rivi- & saraketieto
	Jos alla ei laivaa
		Merkitse huti
	Muutoin
	Jos osui
		Merkitse osuma
		Jos viimeinen lokero
			Merkitse koko laiva uponneeksi

	P�ivit� tilastot
*/

/*
harjoitus 2.	Kirjoita kuhunkin seuraavaan kohtaan yksitt�inen C++ -lause, joka toteuttaa kohdassa mainitun toimenpiteen. 
Oletetaan, ett� ohjelmatekstiss� on aiemmin m��ritelty long int �tyyppiset muuttujat value1 ja value2. Oletetaan lis�ksi, 
ett� value1 �muuttuja on alustettu arvoon 200000. Oletetaan my�s, ett� tietyss� kohdassa (esim. c) ) on jo suoritettu 
aiempien kohtien C++ -lauseet ( c)-kohtaa ennen on suoritettu a)- ja b)-kohtien lauseet; j�lkimm�iseth�n oletkin itse laatinut).

a)	M��rittele muuttuja iPtr siten, ett� se on osoitinmuuttuja long int �tyyppiseen tietoon.
b)	Sijoita muuttujan value1 osoite osoitinmuuttujan iPtr arvoksi.
c)	Tulosta iPtr:n osoittaman tiedon arvo p��tteelle k�ytt�m�ll� ainoastaan hyv�ksi iPtr:ia tulostuslauseessa.
d)	Sijoita muuttujaan value2 iPtr-muuttujan osoittaman tiedon arvo j�lleen k�ytt�en ainoastaan iPtr:ia sijoitettavan 
    tiedon hakemiseen.
e)	Tulosta muuttujan value2 arvo suoraan sek� osoitinmuuttujan iPtr avulla. Onnistuuko t�m� ?
f)	Tulosta value1 �muuttujan muistiosoite.
g)	Tulosta iPtr-muutujan sis�lt� sek� osoite. Onko jompikumpi n�ist� arvoista tulostettu jo aiemmin ? Perustele kannanottosi.
    Voit esitt�� ratkaisusi my�s toimivana p��ohjelmana, jossa on per�kk�in edellisten kohtien C++ -lauseet. Ohjelman 
    ajotuloksista pit�� pysty� osoittamaan tehtyjen C++ -lauseiden oikea toiminta. Lauseiden toimivuuden voit osoittaa 
    my�s debugger:in avulla.
*/

#include <iostream>
using namespace std;

int main()
{
	long int value1 = 200000, value2;

	// a)	M��rittele muuttuja iPtr siten, ett� se on osoitinmuuttuja long int 
	//      -tyyppiseen tietoon.
	long int *iPtr;

	// b)	Sijoita muuttujan value1 osoite osoitinmuuttujan iPtr arvoksi.
	iPtr = &value1;

	// c)	Tulosta iPtr:n osoittaman tiedon arvo p��tteelle k�ytt�m�ll� 
	//      ainoastaan hyv�ksi iPtr:ia tulostuslauseessa.
	cout << *iPtr << endl;

	// d)	Sijoita muuttujaan value2 iPtr-muuttujan osoittaman tiedon 
	//      arvo j�lleen k�ytt�en ainoastaan iPtr:ia sijoitettavan tiedon hakemiseen.
	value2 = *iPtr;

	// e)	Tulosta muuttujan value2 arvo suoraan sek� osoitinmuuttujan iPtr 
	//      avulla. Onnistuuko t�m� ?
	cout << value2 << " " << *iPtr << endl;

	// f)	Tulosta value1 -muuttujan muistiosoite.
	cout << &value1 << endl;

	// g)	Tulosta iPtr-muutujan sis�lt� sek� osoite. Onko jompikumpi 
	//      n�ist� arvoista tulostettu jo aiemmin ? Perustele kannanottosi. 
	cout << iPtr << " " << &iPtr << endl;

	// Voit esitt�� ratkaisusi my�s toimivana p��ohjelmana, jossa on per�kk�in 
	// edellisten kohtien C++ -lauseet. Ohjelman ajotuloksista pit�� pysty� 
	// osoittamaan tehtyjen C++ -lauseiden oikea toiminta. Lauseiden toimivuuden 
	// voit osoittaa my�s debugger:in avulla.

	return 0;
}
