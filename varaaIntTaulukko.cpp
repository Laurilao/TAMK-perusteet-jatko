#include <iostream>
using namespace std;

int main()
{
	int length;
	int index;
	int value;
	int *table_p = NULL;
	int a[1000000];

	cout << "Give length: ";
	cin >> length;
	/*cout << "Give index: ";
	cin >> index;
	cout << "Give value: ";
	cin >> value;*/

	table_p = new int[length];
	if (NULL == table_p) {
		cerr << "Memory allocation failed!\n";
		return 1;
	}

/*	for (int i = 0; i < length; i++)
		table_p[i] = 0;

	table_p[index] = value;

	for (int i = 0; i < length; i++)
		cout << table_p[i] << " ";
	cout << endl;*/
	
	system("pause");

	delete table_p;
	table_p = NULL;

	return 0;
}