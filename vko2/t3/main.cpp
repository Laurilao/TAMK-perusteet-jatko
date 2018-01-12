#include <iostream>
#include <string>

using namespace std;

void kysyTiedot(string*, string*);

int main()
{
	string nimi, ika;

	kysyTiedot(&nimi, &ika);

	cout << "Nimesi: " << nimi << endl;
	cout << "Ikasi: " << ika << endl;

	system("pause");
	return 0;
}

void kysyTiedot(string* nimi, string* ika)
{
	cout << "Anna etunimesi: ";
	getline(cin, *nimi);
	cout << "Anna ikasi: ";
	getline(cin, *ika);

	return;
}