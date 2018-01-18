#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double luku;

	cout << "Anna luku: ";
	cin >> luku;

	cout << endl << "Luku sisaltyy valille [ " << floor(luku) << ", " << ceil(luku) << " ]." << endl;


	system("pause");
	return 0;
}