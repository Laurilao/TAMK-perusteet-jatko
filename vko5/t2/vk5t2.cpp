#include <iostream>

using namespace std;

int main()
{
	long int value1, value2;
	value1 = 200000;

	// a
	long int* iPtr;

	// b
	iPtr = &value1;

	//c
	cout << "iPtr arvo: " << *iPtr << endl;

	//d
	value2 = *iPtr;

	//e, onnistuu jos iPtr laitetaan osoittamaan value2 (iPtr = &value2), muutoin saadaan value1 arvo kuten tässä
	cout << "value2 arvo: " << value2 << ", iPtr arvo: " << *iPtr << endl;

	//f
	cout << "value1 muistiosoite: " << &value1 << endl;

	//g, iPtr osoittaa edelleen value1, muistiosoite ja sisältö on jo tulostettu aiemmin
	cout << "iPtr sisalto: " << *iPtr << " ja osoite: " << iPtr << endl;



	system("pause");
	return 0;
}