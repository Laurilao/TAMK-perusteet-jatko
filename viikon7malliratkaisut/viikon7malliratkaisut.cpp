

/*
harjoitus 1.	Suunnittele kurssin harjoitustyöstä seuraavat toiminnot pseudokoodina:
a)	Ohjelman käynnistymisen yhteydessä huolehdittavat asiat
b)	Ohjelman päävalikon käsittely
c)	Yhden ammunnan käsittely ohjelmassa.
Tee pseudokoodi hyvin karkealla tasolla. Voit kirjoittaa sitä suoraan valitsemallasi tekstieditorilla
(tulos = .txt-loppuliitteinen tiedosto). Mallia pseudokoodin tuottamiseen löydät kurssin teoriakalvosarjan 
Luentokalvot - Osa 2 sivuilta 31 - 37 (käsitelty syksyllä kurssilla Ohjelmointikielet, perusteet).

a)
	Alusta pelilauta
	Alusta pelin muut muuttujat: upotukset, osumat jne.
	Näytä valikko
	Lue valinta

b)
	Toista
		Tulosta päävalikko näytölle
		Lue valinta
		Jos valinta = 1
			Tee 1:n mukaiset toimenpiteet
		Muutoin
		Jos valinta = 2
			Tee 1:n mukaiset toimenpiteet
		...
		Jos valinta = lopeta
			Aseta lopetuslippu päälle
		Muutoin
			Tulosta ilmoitus "väärä valinta!"
	Kunnes käyttäjä haluaa lopettaa pelin

c)
	Lue rivi- & saraketieto
	Jos alla ei laivaa
		Merkitse huti
	Muutoin
	Jos osui
		Merkitse osuma
		Jos viimeinen lokero
			Merkitse koko laiva uponneeksi

	Päivitä tilastot
*/

/*
harjoitus 2.	Kirjoita kuhunkin seuraavaan kohtaan yksittäinen C++ -lause, joka toteuttaa kohdassa mainitun toimenpiteen. 
Oletetaan, että ohjelmatekstissä on aiemmin määritelty long int –tyyppiset muuttujat value1 ja value2. Oletetaan lisäksi, 
että value1 –muuttuja on alustettu arvoon 200000. Oletetaan myös, että tietyssä kohdassa (esim. c) ) on jo suoritettu 
aiempien kohtien C++ -lauseet ( c)-kohtaa ennen on suoritettu a)- ja b)-kohtien lauseet; jälkimmäisethän oletkin itse laatinut).

a)	Määrittele muuttuja iPtr siten, että se on osoitinmuuttuja long int –tyyppiseen tietoon.
b)	Sijoita muuttujan value1 osoite osoitinmuuttujan iPtr arvoksi.
c)	Tulosta iPtr:n osoittaman tiedon arvo päätteelle käyttämällä ainoastaan hyväksi iPtr:ia tulostuslauseessa.
d)	Sijoita muuttujaan value2 iPtr-muuttujan osoittaman tiedon arvo jälleen käyttäen ainoastaan iPtr:ia sijoitettavan 
    tiedon hakemiseen.
e)	Tulosta muuttujan value2 arvo suoraan sekä osoitinmuuttujan iPtr avulla. Onnistuuko tämä ?
f)	Tulosta value1 –muuttujan muistiosoite.
g)	Tulosta iPtr-muutujan sisältö sekä osoite. Onko jompikumpi näistä arvoista tulostettu jo aiemmin ? Perustele kannanottosi.
    Voit esittää ratkaisusi myös toimivana pääohjelmana, jossa on peräkkäin edellisten kohtien C++ -lauseet. Ohjelman 
    ajotuloksista pitää pystyä osoittamaan tehtyjen C++ -lauseiden oikea toiminta. Lauseiden toimivuuden voit osoittaa 
    myös debugger:in avulla.
*/

#include <iostream>
using namespace std;

int main()
{
	long int value1 = 200000, value2;

	// a)	Määrittele muuttuja iPtr siten, että se on osoitinmuuttuja long int 
	//      -tyyppiseen tietoon.
	long int *iPtr;

	// b)	Sijoita muuttujan value1 osoite osoitinmuuttujan iPtr arvoksi.
	iPtr = &value1;

	// c)	Tulosta iPtr:n osoittaman tiedon arvo päätteelle käyttämällä 
	//      ainoastaan hyväksi iPtr:ia tulostuslauseessa.
	cout << *iPtr << endl;

	// d)	Sijoita muuttujaan value2 iPtr-muuttujan osoittaman tiedon 
	//      arvo jälleen käyttäen ainoastaan iPtr:ia sijoitettavan tiedon hakemiseen.
	value2 = *iPtr;

	// e)	Tulosta muuttujan value2 arvo suoraan sekä osoitinmuuttujan iPtr 
	//      avulla. Onnistuuko tämä ?
	cout << value2 << " " << *iPtr << endl;

	// f)	Tulosta value1 -muuttujan muistiosoite.
	cout << &value1 << endl;

	// g)	Tulosta iPtr-muutujan sisältö sekä osoite. Onko jompikumpi 
	//      näistä arvoista tulostettu jo aiemmin ? Perustele kannanottosi. 
	cout << iPtr << " " << &iPtr << endl;

	// Voit esittää ratkaisusi myös toimivana pääohjelmana, jossa on peräkkäin 
	// edellisten kohtien C++ -lauseet. Ohjelman ajotuloksista pitää pystyä 
	// osoittamaan tehtyjen C++ -lauseiden oikea toiminta. Lauseiden toimivuuden 
	// voit osoittaa myös debugger:in avulla.

	return 0;
}
